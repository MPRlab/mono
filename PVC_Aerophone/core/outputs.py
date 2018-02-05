"""
outputs.py
Provides an abstract output class and various implementations

#author  Tanuj Sane
#since   11/20/2017
#version 2.0

Changelog:
2.0 Renamed GPIOOutput --> DriverBoardOutput
1.0 Initial commit
"""

from abc import ABC, abstractmethod
from time import sleep as wait

# Map notes to driver board array positions


# ---------------------------------------------------------------------------- #
# The abstract Output class providing an interface to handle notes and cleanup
class Output(ABC):
    @abstractmethod
    def play(self, notes): pass

    @abstractmethod
    def close(self): pass
# ---------------------------------------------------------------------------- #

# Output implementation that prints notes out to console
class DebugOutput(Output):
    def __init__(self):
        wait(2)                 # Simulate the setup delay for the DriverBoardOutput

    def play(self, notes):
        for msg in notes: print(msg, end="\t")
        print("")

    def close(self):
        pass

MIN_STRIKE_DELAY = 5e-3
MAX_STRIKE_DELAY = 35e-3

# Output implementation that serializes notes out over GPIO for the DriverBoard in the v3.0 configuration
class DriverBoardOutput(Output):
    def __init__(self):
        self._gpio = GPIOConnector()

        # Control pins for each of the two boards
        self._clk_1 = 4; self._ser_1 = 17; self._en_1 = 27; self._rst_1 = 22
        self._clk_2 = 5; self._ser_2 = 6; self._en_2 = 13; self._rst_2 = 19

    def play(self, notes):
        out_1 = 0x000; out_2 = 0x000
        for note in notes:
            pitch = note.note % 24
            if pitch < 12: out_1 |= 1 << (pitch)
            else: out_2 |= 1 << (note.note % 24)

        mask = 0x800
        while mask != 0:
            # Write to the serial input on the correct driver
            self._gpio.set(self._ser_1, 1 if out_1 and mask else 0); self._gpio.set(self._ser_2, 1 if out_2 and mask else 0)

            # Bit-bang the clock to shift the set value into the register
            self._gpio.pulse(self._clk_1); self._gpio.pulse(self._clk_2)

            # Shift the mask
            mask >>= 1

        # Spit the buffer out to the H-bridges, then clear them (strike)
        # Use the note velocity to choose a strike delay
        self._gpio.pulse(self._en_1); self._gpio.pulse(self._en_2)
        wait(MAX_STRIKE_DELAY * (notes[0].velocity / 127) + MIN_STRIKE_DELAY)
        self._gpio.pulse(self._rst_1, active_low=True); self._gpio.pulse(self._rst_2, active_low=True)
        self._gpio.pulse(self._en_1); self._gpio.pulse(self._en_2)

    def close(self):
        self._gpio.close()

class GPIOConnector:
    def __init__(self):
        self._active_pins = []

    def activate(self, pin):
        # Export the pin to create the
        with open("/sys/class/gpio/{}".format('export'), 'w') as export:
            export.write(pin)

        # Wait for the directory to load in
        wait(0.5)

        with open("/sys/class/gpio/gpio{0}/{1}".format(pin, 'direction'), 'w') as direction:
            direction.write('out')

        self._active_pins.append(pin)

    def set(self, pin, value):
        if pin in self._active_pins:
            with open("/sys/class/gpio/gpio{0}/{1}".format(pin, 'value'), 'w') as value:
                value.write(str(value))

    def pulse(self, pin, active_low=False):
        self.set(pin, 0 if active_low else 1)
        self.set(pin, 1 if active_low else 0)
        pass

    def close(self):
        # Close lines for business
        for pin in self._active_pins:
            with open("/sys/class/gpio/{}".format('unexport'), 'w') as unexport:
                unexport.write(pin)