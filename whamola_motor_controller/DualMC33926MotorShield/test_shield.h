/*
 * This file has been modified from https://github.com/pololu/dual-mc33926-motor-shield/blob/master/examples/Demo/Demo.ino
 * 
 * Modifying Author: Christopher Bove cpbove@wpi.edu
*/

#include <math.h>

DualMC33926MotorShield ms;

const float current_step = 0.2f;
const float speed_step = 0.05f;
const unsigned int wait_ms_delay = 120;

void stopIfFault()
{
  if (ms.hasFault())
  {
    printf("fault\n");
    while(1);
  }
}

void test_shield_loop()
{
  printf("M1 Forward.\n\r");
  for (float i = 0; i <= 1 + speed_step; i += speed_step)
  {
    ms.setM1Speed(i);
    stopIfFault();
    printf("M1 speed: %f current: %f\n\r", i, ms.getM1CurrentAmps());
    wait_ms(wait_ms_delay);
  }
  
  wait(2);
  
  printf("M1 Backward\n\r");
  for (float i = 1; i >= -1 - speed_step; i -= speed_step)
  {
    ms.setM1Speed(i);
    stopIfFault();
    printf("M1 speed: %f current: %f\n\r", i, ms.getM1CurrentAmps());
    wait_ms(wait_ms_delay);
  }
  
  wait(2);
  
  printf("M1 Forward to stop\n\r");
  for (float i = -1; i <= 0 + speed_step; i += speed_step)
  {
    ms.setM1Speed(i);
    stopIfFault();
    printf("M1 speed: %f current: %f\n\r", i, ms.getM1CurrentAmps());
    wait_ms(wait_ms_delay);
  }
  
  printf("M1 stopped. Pausing.\n\r");
  wait(3);

  printf("M2 Forward.\n\r");
  for (float i = 0; i <= 1 + speed_step; i += speed_step)
  {
    ms.setM2Speed(i);
    stopIfFault();
    printf("M2 speed: %f current: %f\n\r", i, ms.getM2CurrentAmps());
    wait_ms(wait_ms_delay);
  }
  
  wait(2);
  
  printf("M2 Backward\n\r");
  for (float i = 1; i >= -1 - speed_step; i -= speed_step)
  {
    ms.setM2Speed(i);
    stopIfFault();
    printf("M2 speed: %f current: %f\n\r", i, ms.getM2CurrentAmps());
    wait_ms(wait_ms_delay);
  }
  
  wait(2);
  
  printf("M2 Forward to stop\n\r");
  for (float i = -1; i <= 0 + speed_step; i += speed_step)
  {
    ms.setM2Speed(i);
    stopIfFault();
    printf("M2 speed: %f current: %f\n\r", i, ms.getM2CurrentAmps());
    wait_ms(wait_ms_delay);
  }
  
  printf("M2 stopped. Pausing.\n\r");
  wait(3);
}