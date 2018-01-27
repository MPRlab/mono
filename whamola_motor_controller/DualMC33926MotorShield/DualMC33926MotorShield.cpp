/*
 * This file has been modified from https://github.com/pololu/dual-mc33926-motor-shield/blob/master/DualMC33926MotorShield.cpp
 * 
 * Modifying Author: Christopher Bove cpbove@wpi.edu
*/

#include "DualMC33926MotorShield.h"

#include "mbed.h"

// Constructor ////////////////////////////////////////////////////////////////
DualMC33926MotorShield::DualMC33926MotorShield(PinName M1DIR, PinName M1PWM, PinName M1FB,
                                               PinName M2DIR, PinName M2PWM, PinName M2FB,
                                               PinName nD2, PinName nSF)
{
  _M1DIR = M1DIR;
  _M1PWM = M1PWM;
  _M1FB = M1FB;
  _M2DIR = M2DIR;
  _M2PWM = M2PWM;
  _M2FB = M2FB;
  _nD2 = nD2;
  _nSF = nSF;
  
  // initialize the mbed objects from pins
  _M1DirOut = new DigitalOut(_M1DIR);
  _M2DirOut = new DigitalOut(_M2DIR);
  _M1PwmOut = new PwmOut(_M1PWM);
  _M2PwmOut = new PwmOut(_M2PWM);
  _M1FbAnalogIn = new AnalogIn(_M1FB);
  _M2FbAnalogIn = new AnalogIn(_M2FB);
  _nD2Out = new DigitalOut(_nD2);
  _nSfDigitalIn = new DigitalIn(_nSF);
  
  // default to enable
  enable();
}

// Destructor ////////////////////////////////////////////////////////////////
DualMC33926MotorShield::~DualMC33926MotorShield(){
    delete _M1DirOut;
    delete _M2DirOut;
    delete _M1PwmOut;
    delete _M2PwmOut;
    delete _M1FbAnalogIn;
    delete _M2FbAnalogIn;
    delete _nD2Out;
    delete _nSfDigitalIn;
}

// Public Methods //////////////////////////////////////////////////////////////
void DualMC33926MotorShield::enable() {
    _nD2Out->write(1);
}

void DualMC33926MotorShield::disable() {
    _nD2Out->write(0);
}

// Set speed for motor 1, speed is a number betwenn -400 and 400
void DualMC33926MotorShield::setM1Speed(float speed)
{
  setMSpeed(_M1PwmOut, _M1DirOut, speed);
}

// Set speed for motor 2, speed is a number betwenn -400 and 400
void DualMC33926MotorShield::setM2Speed(float speed)
{
  setMSpeed(_M2PwmOut, _M2DirOut, speed);
}

// Set speed for motor 1 and 2
void DualMC33926MotorShield::setSpeeds(float m1Speed, float m2Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}

// Return motor 1 current value in amps.
float DualMC33926MotorShield::getM1CurrentAmps()
{
  return getMCurrentAmps(_M1FbAnalogIn);
}

// Return motor 2 current value in amps.
float DualMC33926MotorShield::getM2CurrentAmps()
{
  return getMCurrentAmps(_M2FbAnalogIn);
}

// Return error status
bool DualMC33926MotorShield::hasFault()
{
  int result = _nSfDigitalIn->read();
  if(result)
    return false;
  else
    return true;
}

void DualMC33926MotorShield::setMSpeed(PwmOut* motor, DigitalOut* dir, float speed) {
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 1)  // Max PWM dutycycle
    speed = 1;

  motor->write(speed);
  dir->write(reverse);

}

float DualMC33926MotorShield::getMCurrentAmps(AnalogIn* analogIn) {
  //float volts = analogIn->read() * 3.3;
  // 3.3V / 0.525 V per A = 6.2857 A per 1.0 V
  return analogIn->read() * 6.2857f;
}