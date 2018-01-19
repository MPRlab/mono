/*
 * This file has been modified from https://github.com/pololu/dual-mc33926-motor-shield/blob/master/DualMC33926MotorShield.h
 * 
 * Modifying Author: Christopher Bove cpbove@wpi.edu
*/

#ifndef DualMC33926MotorShield_h
#define DualMC33926MotorShield_h

#include "mbed.h"

class DualMC33926MotorShield
{
  public:
    // CONSTRUCTOR - with default overrides for plugging shield directly into nucleo
    DualMC33926MotorShield(PinName M1DIR = PF_13, PinName M1PWM = PD_15,
                           PinName M1FB = A0, PinName M2DIR = PF_12, 
                           PinName M2PWM = PD_14, PinName M2FB = A1,
                           PinName nD2 = PF_14, PinName nSF = PA_6);
    // DESTRUCTOR
    ~DualMC33926MotorShield();
    
    // PUBLIC METHODS
    void enable(); // enable motor controller
    void disable(); // disable motor controller
    void setM1Speed(float speed); // Set speed for M1.
    void setM2Speed(float speed); // Set speed for M2.
    void setSpeeds(float m1Speed, float m2Speed); // Set speed for both M1 and M2.
    float getM1CurrentAmps(); // Get current reading for M1. 
    float getM2CurrentAmps(); // Get current reading for M2.
    bool hasFault(); // Get fault reading. Will return true if fault.
    
  private:
    void setMSpeed(PwmOut * motor, DigitalOut * dir, float speed);
    float getMCurrentAmps(AnalogIn * analogIn);
    PinName _M1DIR;
    PinName _M1PWM;
    PinName _M1FB;
    
    PinName _M2DIR;
    PinName _M2PWM;
    PinName _M2FB;
    
    PinName _nD2; // enable line
    PinName _nSF; // fault input line. 
    
    DigitalOut * _M1DirOut;
    DigitalOut * _M2DirOut;
    DigitalOut * _nD2Out;
    PwmOut * _M1PwmOut;
    PwmOut * _M2PwmOut;
    AnalogIn * _M1FbAnalogIn;
    AnalogIn * _M2FbAnalogIn;
    DigitalIn * _nSfDigitalIn; // TODO make this InterruptIn
};

#endif