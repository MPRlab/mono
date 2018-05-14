/**
 * driver_board.h
 * Definition of a class for controlling the DriverBoard
 * 
 * @author  Tanuj Sane
 * @since   4/20/2018
 * @version 1.0
 * 
 * Changelog:
 * - 1.0 Initial commit
 */

#ifndef DRIVER_BOARD_H_
#define DRIVER_BOARD_H_

#define STRIKE_DELAY    	35	/* ms */
#define OUTPUT_PIN_IDLE		-2
#define OUTPUT_PIN_UPDATE	-1

typedef char byte;

typedef struct {
	byte state;			// The current state of the pin (ON or OFF)
	int ms_elapsed;		// The number of elapsed milliseconds since last update
} OutputPin;

class DriverBoard {
private:
	DigitalOut p_clk, p_en, p_rst, p_ser;    // The input lines from the uC
	OutputPin outputs[12];    				 // The output lines on the DriverBoard

public:
	/**
	 * Constructor
	 *
	 * @param clk The pin for bit-banging SCK
	 * @param en  The pin for the RCK input
	 * @param rst The pin for the RST input
	 * @param ser The pin for the input line to the shift register
	 */
	DriverBoard(PinName clk, PinName en, PinName rst, PinName ser):
		p_clk(DigitalOut(clk)), p_en(DigitalOut(en)), p_rst(DigitalOut(rst)), p_ser(DigitalOut(ser))
{/* Empty */}

	/** Initialize the object and enable connected DriverBoard */
	void init() {
		// Initialize all output pins to the OFF state
		for(int i = 0; i < 12; i++) {
			OutputPin pin;
			pin.state = 0;
			pin.ms_elapsed = OUTPUT_PIN_IDLE;

			this->outputs[i] = pin;
		}

		// Drive reset high to enable board
		this->p_rst = 1;
	}

	/** Queue up the note to be set out to the output pins */
	void play(uint32_t pitch, uint32_t velocity) {
		int i = (int) pitch % 12;
		this->outputs[i].state = 1;
		this->outputs[i].ms_elapsed = OUTPUT_PIN_UPDATE;
	}

	/**
	 * Synchronize the DriverBoard with the internal state
	 * The sync time is provided externally to ensure synchronization with main()
	 *
	 * @param ms_since_last The number of milliseconds since the previous sync call
	 */
	void sync(int ms_since_last) {
		for(int i = 0; i < 12; i++) {
			OutputPin pin = this->outputs[i];

			// Enter a state machine on the overloaded timer value
			int ms_elapsed = pin.ms_elapsed;
			switch(ms_elapsed) {
			case OUTPUT_PIN_IDLE: break;

			// If update requested, start its timer
			case OUTPUT_PIN_UPDATE:
				pin.ms_elapsed = 0;
				break;

			default:
				// If time's up, turn off the pin
				if(pin.ms_elapsed >= STRIKE_DELAY) {
					pin.state = 0;
					pin.ms_elapsed = OUTPUT_PIN_IDLE;
				}
				// Otherwise update the pin timer
				else pin.ms_elapsed += ms_since_last;
				break;
			}

			// Set the value to the shift register and advance
			this->p_ser = pin.state;
			this->p_clk = 1; this->p_clk = 0;

			// Apply updates to the internal state
			this->outputs[i] = pin;
		}

		// Enable the shift register output on the pins
		this->p_en = 1; this->p_en = 0;
	}
};

#endif /* DRIVER_BOARD_H_ */
