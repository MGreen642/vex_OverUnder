/* ---------------------------------------------------------------------------- */
/*                                                                              */                 
/*    Project:        Clawbot Controller with Events                            */
/*    Module:         main.cpp                                                  */
/*    Author:         VEX                                                       */
/*    Created:        Fri Aug 05 2022                                           */
/*    Description:    This example will use Controller button events to         */
/*                    control the V5 Clawbot arm and claw                       */
/*                                                                              */                 
/*    Configuration:  V5 Clawbot (Individual Motors)                            */
/*                    Controller                                                */
/*                    Claw Motor in Port 3                                      */
/*                    Arm Motor in Port 8                                       */
/*                    Left Motor in Port 1                                      */
/*                    Right Motor in Port 10                                    */
/*                                                                              */                 
/* ---------------------------------------------------------------------------- */

#include "vex.h"
// to use complex numbers
#include <complex>

using namespace vex;

// config code

// define brain - lol no brain, much pain
brain Brain;

// define drivetrain motors, their: ports, gear cartridge, and 
motor DT_BL = motor(PORT1, ratio6_1, true);
motor DT_FL = motor(PORT2, ratio6_1, true);
motor DT_BR = motor(PORT9, ratio6_1, true);
motor DT_FR = motor(PORT10, ratio6_1, true);

controller Controller1 = controller(primary);

// test function
void controller_L1_Pressed(){
  Brain.Screen.clearScreen();
  Brain.Screen.print("code running");
}


int main() {

  // call simple callback event
  Controller1.ButtonA.pressed(controller_L1_Pressed);
  wait(15,msec); // Delay to make sure the event gets registered

  DT_BL.spin(forward);
  DT_FL.spin(forward);
  DT_BR.spin(reverse);
  DT_FR.spin(reverse);

  // Main loop
  while(true){
    float steering = pow((Controller1.Axis4.position()),1.2)/10;
    if (Controller1.Axis4.position() < 0) {
      steering = steering*-1;
    }
    float speed = Controller1.Axis3.position();
    float left = speed-steering;
    float right = speed+steering;
    if (left > 100) {
      right = right - (left-100);
      left = 100;
    } else if (left < -100) {
      right = right - (left+100);
      left = -100;
    }
    if (right > 100) {
      left = left - (right-100);
      right = 100;
    } else if (right < -100) {
      left = left - (right+100);
      right = -100;
    }
    DT_BL.setVelocity((left), percent);
    DT_FL.setVelocity((left), percent);
    DT_BR.setVelocity((right), percent);
    DT_FR.setVelocity((right), percent);
    wait(5, msec);
  }
}
