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
        wait(2)     # Simulate the setup delay for the DriverBoardOutput

    def play(self, notes):
        for msg in notes: print(msg, end="\t")
        print("")

    def close(self):
        pass

# Output implementation that serializes notes out over GPIO for the DriverBoard
class DriverBoardOutput(Output):
    def __init__(self, clk, _rst, en, ser):
        # The device directories for each pin
        self._gpio = "/sys/class/gpio/{}"
        self._pin = self._gpio.format("gpio{0}/{1}")

        # The necessary data lines
        self.lines = {
            'CLK': str(clk),      # Rising edge moves to the next input
            '_RST': str(_rst),    # Active low slave select, drive high to enable reading
            'EN': str(en),        # Drive high to latch input data, output it to H-bridges
            'SER': str(ser),      # Serial output, 'out' is serialized over this line
        }

        # Set up for I/O
        for (_, line) in self.lines.items():
            with open(self._gpio.format('export'), 'w') as export:
                export.write(line)

            # Wait for the directory to load in
            wait(0.5)

            with open(self._pin.format(line, 'direction'), 'w') as direction:
                direction.write('out')

        # Startup settings
        self._set('_RST', 1)        # Enable driver
        self._set('EN', 0)          # Latch data - no output to board

    def play(self, notes):
        # Generate the output and serialize
        out = 0x000
        for msg in notes: out |= 1 << (msg.note % 12)

        mask = 0x800
        while mask != 0:
            self._set('SER', 1 if out & mask else 0)
            self._pulse('CLK')
            mask >>= 1

        # Spit the buffer out to the H-bridges, then clear them (strike)
        self._pulse('EN')
        wait(25e-3)     # TODO: No magic numbers - that's the strike delay
        self._pulse('_RST')
        self._pulse('EN')

    def _set(self, name, setting):
        with open(self._pin.format(self.lines[name], 'value'), 'w') as value:
            value.write(str(setting))

    def _pulse(self, name):
        active_low = (name[0] == '_')
        self._set(name, 0 if active_low else 1)
        self._set(name, 1 if active_low else 0)

    def close(self):
        # Close lines for business
        for (_, line) in self.lines.items():
            with open(self._gpio.format('unexport'), 'w') as unexport:
                unexport.write(line)