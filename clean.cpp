// #pragma region VEXcode Generated Robot Configuration
// // Make sure all required headers are included.
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <math.h>
// #include <string.h>


// #include "vex.h"

// using namespace vex;
// competition Competition;

// // User defined function
// void myblockfunction_Wrap_180_value(double myblockfunction_Wrap_180_value__value);
// // User defined function
// void myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError(double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kP, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kI, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kD, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__error, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__lastError, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__cumulativeError);
// // User defined function
// void myblockfunction_Turn__7C_Heading__heading_Wait__wait(double myblockfunction_Turn__7C_Heading__heading_Wait__wait__heading, double myblockfunction_Turn__7C_Heading__heading_Wait__wait__wait);
// // User defined function
// void myblockfunction_Drive__7C_inches__in_wait__wait(double myblockfunction_Drive__7C_inches__in_wait__wait__in, double myblockfunction_Drive__7C_inches__in_wait__wait__wait);

// int Screen_precision = 0, Console_precision = 0, Controller1_precision = 0;

// float PIDOutput, kPLateral, kDLateral, kPAngular, kDAngular, LastErrorLateral, LastErrorAngular, LateralPos, ErrorLateral, ErrorAngular, turnSpeed, driveSpeed, leftDriveSpeed, rightDriveSpeed, ReturnMath, startHeading, MaxSpeed, AutoNum, Auto, ControllerTurnSpeed, OldAuto, kI, cumulativeError;

// bool ClawOpen, StopProgram;

// event RUN = event();
// event STOP = event();
// event AutoSelect = event();
// event Auto1 = event();
// event Auto2 = event();
// event Auto3 = event();
// event Driver = event();



// // User defined function





// // "when started" hat block
// int whenStarted2() {
//   Brain.Screen.setFillColor(purple);
//   Brain.Screen.drawRectangle(0, 0, 480, 240);
//   Brain.Screen.print("Heatron Template v0.2");
//   Brain.Screen.newLine();
//   Brain.Screen.setFillColor(black);
//   Brain.Screen.drawRectangle(0, 80, 130, 55);
//   Brain.Screen.setPenColor(white);
//   Brain.Screen.setCursor(4, 2);
//   Brain.Screen.setFont(prop30);
//   Brain.Screen.print("RUN (B)");
//   Brain.Screen.drawRectangle(0, 140, 135, 55);
//   Brain.Screen.setPenColor(white);
//   Brain.Screen.setCursor(6, 2);
//   Brain.Screen.setFont(prop30);
//   Brain.Screen.print("STOP (A)");
//   while (true) {
//     Brain.Screen.setFillColor(purple);
//     Brain.Screen.setFont(mono20);
//     Brain.Screen.setPenColor(white);
//     Brain.Screen.clearLine(2);
//     Brain.Screen.setCursor(Brain.Screen.row(), 1);
//     Brain.Screen.setCursor(2, 2);
//     Brain.Screen.print("Heading: ");
//     Brain.Screen.print(printToScreen_numberFormat(), static_cast<float>(IMU.rotation(degrees)));
//     Brain.Screen.newLine();
//     AutoSelect.broadcast();
//   wait(5, msec);
//   }
//   return 0;
// }

// // "when Brain screen pressed" hat block
// void onevent_Brain_screen_pressed_0() {
//   if (Brain.Screen.pressing() && (0.0 < Brain.Screen.xPosition() < 130.0 && 80.0 < Brain.Screen.yPosition() < 135.0)) {
//     RUN.broadcast();
//   } else if (Brain.Screen.pressing() && (0.0 < Brain.Screen.xPosition() < 135.0 && 140.0 < Brain.Screen.yPosition() < 195.0)) {
//     STOP.broadcast();
//   } else {
//     if (Auto < AutoNum) {
//       Auto = Auto + 1.0;
//     }
//     else {
//       Auto = 0.0;
//     }
//   }
// }

// // "when I receive RUN" hat block


// // "when I receive Auto1" hat block
// void onevent_Auto1_0() {
//   // Skills
//   // Preload
//   MaxSpeed = 8.0;
//   IMU.setRotation(0.0, degrees);
//   Claw.set(false);
//   Cascade.spinFor(forward, 360.0, degrees, false);
//   myblockfunction_Drive__7C_inches__in_wait__wait(6.0, .5);
//   myblockfunction_Drive__7C_inches__in_wait__wait(-6.125, .5);
//   myblockfunction_Drive__7C_inches__in_wait__wait(6.0, .5);
//   myblockfunction_Drive__7C_inches__in_wait__wait(-6.125, .5);
//   myblockfunction_Drive__7C_inches__in_wait__wait(16.0, 1.0);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(90.0, 1.0);
//   MaxSpeed = 4.0;
//   myblockfunction_Drive__7C_inches__in_wait__wait(17.0, 1.0);
//   Cascade.spinFor(reverse, 290.0, degrees, true);
//   Claw.set(true);
//   wait(1.0, seconds);
//   Cascade.spinFor(reverse, 100.0, degrees, false);
//   // Field Obj 1
//   MaxSpeed = 8.0;
//   myblockfunction_Drive__7C_inches__in_wait__wait(-10.0, .75);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(180.0, .75);
//   myblockfunction_Drive__7C_inches__in_wait__wait(11.0, .75);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(90.0, .75);
//   myblockfunction_Drive__7C_inches__in_wait__wait(40.0, 1.5);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(-1.0, 1.0);
//   MaxSpeed = 2.0;
//   myblockfunction_Drive__7C_inches__in_wait__wait(8.0, 1.0);
//   Claw.set(false);
//   wait(0.75, seconds);
//   MaxSpeed = 6.0;
//   Cascade.spinFor(forward, 360.0, degrees, false);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(-80.0, 1.0);
//   myblockfunction_Drive__7C_inches__in_wait__wait(19.5, 1.0);
//   Cascade.spinFor(reverse, 270.0, degrees, true);
//   Claw.set(true);
//   // Match Load
//   MaxSpeed = 8.0;
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(-90.0, 1.0);
//   Cascade.spinFor(reverse, 80.0, degrees, false);
//   myblockfunction_Drive__7C_inches__in_wait__wait(-31.0, 1.5);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(180.0, 1.0);
//   myblockfunction_Drive__7C_inches__in_wait__wait(10.0, 1.0);
//   Claw.set(false);
//   wait(1.0, seconds);
//   Cascade.spinFor(forward, 80.0, degrees, false);
//   myblockfunction_Drive__7C_inches__in_wait__wait(-15.0, 1.0);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(-90.0, 1.0);
//   MaxSpeed = 4.0;
//   Cascade.spinFor(forward, 400.0, degrees, false);
//   myblockfunction_Drive__7C_inches__in_wait__wait(45.0, 2.0);
//   Cascade.spinFor(reverse, 220.0, degrees, true);
//   Claw.set(true);
//   wait(1.0, seconds);
// }

// // "when I receive Auto2" hat block
// void onevent_Auto2_0() {
//   // Match Right
//   MaxSpeed = 8.0;
//   IMU.setRotation(0.0, degrees);
//   Claw.set(false);
//   Cascade.spinFor(forward, 180.0, degrees, false);
//   myblockfunction_Drive__7C_inches__in_wait__wait(2.0, 1.0);
//   myblockfunction_Drive__7C_inches__in_wait__wait(-2.0, 1.0);
//   myblockfunction_Drive__7C_inches__in_wait__wait(2.0, 1.0);
//   myblockfunction_Drive__7C_inches__in_wait__wait(-2.0, 1.0);
//   myblockfunction_Drive__7C_inches__in_wait__wait(17.0, 1.0);
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(-90.0, 1.0);
//   MaxSpeed = 4.0;
//   myblockfunction_Drive__7C_inches__in_wait__wait(18.0, 1.0);
//   Cascade.spinFor(reverse, 180.0, degrees, true);
//   Claw.set(true);
//   MaxSpeed = 8.0;
//   myblockfunction_Drive__7C_inches__in_wait__wait(-10.0, 1.0);
// }

// // "when I receive Auto3" hat block
// void onevent_Auto3_0() {
//   MaxSpeed = 10.0;
//   myblockfunction_Turn__7C_Heading__heading_Wait__wait(90.0, 1.0);
// }





