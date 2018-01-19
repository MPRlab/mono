/*
 * Whamola Motor Controller
 *  This program interfaces with the whamola motor controllers to control the 
 *  motor speed.
 * 
 * Author: Christopher Bove cpbove@wpi.edu
*/

#include "mbed.h"
#include "DualMC33926MotorShield/DualMC33926MotorShield.h"
#include "DualMC33926MotorShield/test_shield.h"

// main() runs in its own thread in the OS
int main() {
    while (true) {
        test_shield_loop();
    }
}

