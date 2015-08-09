#include "status.h"

// Constructor
init_status(Status * s) {

	// Set the default pulse hold time for the drivers
	for (uint8_t i = 0; i < 6; i++) {

		set(&(s->driver_pulse_hold_time) + i, PULSE_HOLD_TIME);
		set(&(s->hold_pwm) + i, HOLD_PWM);
		set(&(s->pulse_pwm) + i, PULSE_PWM);

	}

}
