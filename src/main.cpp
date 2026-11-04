#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
controller Controller1 = controller(primary);
inertial IMU = inertial(PORT5);

motor Right1 = motor(PORT2, ratio6_1, true);

motor Right2 = motor(PORT3, ratio18_1, true);

motor Right3 = motor(PORT4, ratio6_1, true);

motor Left1 = motor(PORT7, ratio6_1, false);

motor Left2 = motor(PORT8, ratio18_1, false);

motor Left3 = motor(PORT9, ratio6_1, false);

motor_group RightDriveSmart = motor_group(Right1, Right2, Right3);
motor_group LeftDriveSmart = motor_group(Left1, Left2, Left3);

distance ClawDist = distance(PORT6);
digital_out Claw = digital_out(Brain.ThreeWirePort.A);
motor CascadeMotorA = motor(PORT1, ratio36_1, true);
motor CascadeMotorB = motor(PORT10, ratio36_1, false);
motor_group Cascade = motor_group(CascadeMotorA, CascadeMotorB);



// generating and setting random seed
void initializeRandomSeed(){
  int systemTime = Brain.Timer.systemHighResolution();
  double batteryCurrent = Brain.Battery.current();
  double batteryVoltage = Brain.Battery.voltage(voltageUnits::mV);

  // Combine these values into a single integer
  int seed = int(batteryVoltage + batteryCurrent * 100) + systemTime;

  // Set the seed
  srand(seed);
}



void vexcodeInit() {

  //Initializing random seed.
  initializeRandomSeed(); 
}


// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

competition Competition;

// User defined function
void myblockfunction_Wrap_180_value(double myblockfunction_Wrap_180_value__value);
// User defined function
void myblockfunction_Turn__7C_Heading__heading_Wait__wait(double myblockfunction_Turn__7C_Heading__heading_Wait__wait__heading, double myblockfunction_Turn__7C_Heading__heading_Wait__wait__wait);
// User defined function
void myblockfunction_Drive__7C_inches__in_wait__wait(double myblockfunction_Drive__7C_inches__in_wait__wait__in, double myblockfunction_Drive__7C_inches__in_wait__wait__wait);
// User defined function
void myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError(double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kP, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kI, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kD, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__error, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__lastError, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__cumulativeError);

void calculatePosition(double distanceTraveled, double heading);

void setPos(double newXPos, double newYPos);

void odomTracking(double xPos, double yPos, double timeout);

int auto2();

double xPos = 0.0, yPos = 0.0, heading = 0.0, turnTime = .5;

int Screen_precision = 0, Console_precision = 0, Controller1_precision = 0, autoNum = 0, Auto = 0;

float PIDOutput, kPLateral, kDLateral, kPAngular, kDAngular, LastErrorLateral, LastErrorAngular, LateralPos, ErrorLateral, ErrorAngular, turnSpeed, driveSpeed, leftDriveSpeed, rightDriveSpeed, ReturnMath, startHeading, MaxSpeed, AutoNum, ControllerTurnSpeed;

bool ClawOpen;

// User defined function
void myblockfunction_Wrap_180_value(double myblockfunction_Wrap_180_value__value) {
  ReturnMath = myblockfunction_Wrap_180_value__value;
  while ((ReturnMath > 180.0)) {
    ReturnMath = ReturnMath + -360.0;
  wait(5, msec);
  }
  while ((ReturnMath < -180.0)) {
    ReturnMath = ReturnMath + 360.0;
  wait(5, msec);
  }
}

// User defined function
void myblockfunction_Turn__7C_Heading__heading_Wait__wait(double myblockfunction_Turn__7C_Heading__heading_Wait__wait__heading, double myblockfunction_Turn__7C_Heading__heading_Wait__wait__wait) {
  Brain.Timer.clear();
  while (true) {
    // Turn PID
    myblockfunction_Wrap_180_value(myblockfunction_Turn__7C_Heading__heading_Wait__wait__heading - IMU.rotation(degrees));
    ErrorAngular = ReturnMath;
    myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError(kPAngular, 0.0, kDAngular, ErrorAngular, LastErrorAngular, 0.0);
    LastErrorAngular = ErrorAngular;
    turnSpeed = PIDOutput;
    if (fabs(static_cast<float>(turnSpeed)) > MaxSpeed) {
      turnSpeed = (fabs(static_cast<float>(turnSpeed)) / turnSpeed) * MaxSpeed;
    }
    leftDriveSpeed = 0.0 - turnSpeed;
    rightDriveSpeed = 0.0 + turnSpeed;
    // Move Motors
    RightDriveSmart.spin(forward, rightDriveSpeed, volt);
    LeftDriveSmart.spin(forward, leftDriveSpeed, volt);
    // Wait
    if (Brain.Timer.time(seconds) > myblockfunction_Turn__7C_Heading__heading_Wait__wait__wait) {
      break;
    }
  wait(5, msec);
  }
  RightDriveSmart.stop();
  LeftDriveSmart.stop();
  MaxSpeed = 10.0;
}

// User defined function
void myblockfunction_Drive__7C_inches__in_wait__wait(double myblockfunction_Drive__7C_inches__in_wait__wait__in, double myblockfunction_Drive__7C_inches__in_wait__wait__wait) {
  Brain.Timer.clear();
  LastErrorLateral = myblockfunction_Drive__7C_inches__in_wait__wait__in;
  startHeading = IMU.rotation(degrees);
  RightDriveSmart.setPosition(0.0, turns);
  LeftDriveSmart.setPosition(0.0, turns);
  while (true) {
    // Drive PID
    ErrorLateral = myblockfunction_Drive__7C_inches__in_wait__wait__in - LateralPos;
    myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError(kPLateral, 0.0, kDLateral, ErrorLateral, LastErrorLateral, 0.0);
    LastErrorLateral = ErrorLateral;
    driveSpeed = PIDOutput;
    if (fabs(static_cast<float>(driveSpeed)) > MaxSpeed) {
      driveSpeed = (fabs(static_cast<float>(driveSpeed)) / driveSpeed) * MaxSpeed;
    }
    // Turn PID
    myblockfunction_Wrap_180_value(startHeading - IMU.rotation(degrees));
    ErrorAngular = ReturnMath;
    myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError(kPAngular, 0.0, kDAngular, ErrorAngular, LastErrorAngular, 0.0);
    LastErrorAngular = ErrorAngular;
    turnSpeed = PIDOutput;
    leftDriveSpeed = driveSpeed - turnSpeed;
    rightDriveSpeed = driveSpeed + turnSpeed;
    // Move Motors
    RightDriveSmart.spin(forward, rightDriveSpeed, volt);
    LeftDriveSmart.spin(forward, leftDriveSpeed, volt);
    // Wait
    if (Brain.Timer.time(seconds) > myblockfunction_Drive__7C_inches__in_wait__wait__wait) {
      break;
    }
  wait(5, msec);
  }
  RightDriveSmart.stop();
  LeftDriveSmart.stop();
  MaxSpeed = 10.0;

}

// User defined function
void myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError(double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kP, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kI, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kD, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__error, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__lastError, double myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__cumulativeError) {
  PIDOutput = myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kP * myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__error + (myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kI * myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__cumulativeError + myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__kD * (myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__error - myblockfunction_PID__kP__kP_kI__kI_kD__kD_error__error_lastError__lastError_cumulativeError__cumulativeError__lastError));
}

/*
void calculatePosition(double distanceTraveled, double heading) {
  // Convert heading from degrees to radians
  double headingRadians = heading * (M_PI / 180.0);
  
  // Calculate the change in position
  double deltaX = distanceTraveled * cos(headingRadians);
  double deltaY = distanceTraveled * sin(headingRadians);
  
  // Update the global position
  xPos += deltaX;
  yPos += deltaY;
  
}
  */

void setPos(double newXPos, double newYPos) {
 xPos = newXPos;
 yPos = newYPos;
}


struct Waypoint {
    double x;
    double y;
};

// Adjust these values to match your robot.
const double PATH_LOOKAHEAD = 8.0;  // inches
const double PATH_SPEED = 6.0;      // base voltage
const double PATH_TRACK_WIDTH = 12.0; // wheel-to-wheel width, inches

double clampValue(double value, double low, double high) {
    if (value < low) return low;
    if (value > high) return high;
    return value;
}
double Distance(double x, double y){
    return sqrt(x * x + y * y);
}
double pointDistance(double x1, double y1,
                     double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return Distance(dx, dy);
}

// Find a point on the path approximately one lookahead
// radius ahead of the robot.
bool getLookaheadPoint(
    const Waypoint path[],
    int count,
    int startSegment,
    double robotX,
    double robotY,
    double lookahead,
    double &targetX,
    double &targetY,
    int &targetSegment
) {
    double radiusSquared = lookahead * lookahead;

    for (int i = startSegment; i < count - 1; i++) {
        double ax = path[i].x;
        double ay = path[i].y;
        double dx = path[i + 1].x - ax;
        double dy = path[i + 1].y - ay;

        double fx = ax - robotX;
        double fy = ay - robotY;

        double a = dx * dx + dy * dy;
        if (a < 0.0001) continue;

        double b = 2.0 * (fx * dx + fy * dy);
        double c = fx * fx + fy * fy - radiusSquared;

        double discriminant = b * b - 4.0 * a * c;
        if (discriminant < 0.0) continue;

        double root = sqrt(discriminant);
        double t1 = (-b - root) / (2.0 * a);
        double t2 = (-b + root) / (2.0 * a);

        // Choose the furthest valid intersection on this
        // segment, in the direction of travel.
        double t = -1.0;

        if (t2 >= 0.0 && t2 <= 1.0) {
            t = t2;
        } else if (t1 >= 0.0 && t1 <= 1.0) {
            t = t1;
        }

        if (t >= 0.0) {
            targetX = ax + t * dx;
            targetY = ay + t * dy;
            targetSegment = i;
            return true;
        }
    }

    // No circle intersection found: aim for the final point.
    targetX = path[count - 1].x;
    targetY = path[count - 1].y;
    targetSegment = count - 2;
    return false;
}
bool withinRange(double checkedValue, double constantValue, double range) {
    return checkedValue<= constantValue + range/2 && checkedValue >= constantValue - range/2;
}
void followPath(const Waypoint path[], int count, double timeout) {
    if (count < 2) return;
    double lastX = path[count - 1].x;
    double lastY = path[count - 1].y;
    int segment = 0;

    // Allow up to 15 seconds for the path.
    Brain.Timer.clear();

    while (Brain.Timer.time(seconds) < timeout) {
        double finalDistance = pointDistance(
            xPos, yPos,
            path[count - 1].x,
            path[count - 1].y
        );

        // Stop when the final waypoint is reached.
        if (finalDistance < 1.5) break;
        if (withinRange(xPos, lastX, 1.5) && withinRange(yPos, lastY, 1.5)) break;
        // Advance through waypoints as we approach them.
        while (segment < count - 2 &&
               pointDistance(
                   xPos, yPos,
                   path[segment + 1].x,
                   path[segment + 1].y
               ) < PATH_LOOKAHEAD * 0.5) {
            segment++;
        }

        double targetX, targetY;
        int targetSegment = segment;

        getLookaheadPoint(
            path, count, segment,
            xPos, yPos,
            PATH_LOOKAHEAD,
            targetX, targetY,
            targetSegment
        );

        if (targetSegment > segment) {
            segment = targetSegment;
        }

        // Convert the target direction into a heading.
        // Zero degrees points forward (+Y).
        double dx = targetX - xPos;
        double dy = targetY - yPos;

        double targetHeading = atan2(dx, dy) * 180.0 / M_PI;
        double alpha = targetHeading - heading;

        // Normalize angle to -180 through +180.
        while (alpha > 180.0) alpha -= 360.0;
        while (alpha < -180.0) alpha += 360.0;

        double alphaRadians = alpha * M_PI / 180.0;

        // Pure Pursuit curvature, in inverse inches.
        double curvature =
            2.0 * sin(alphaRadians) / PATH_LOOKAHEAD;

        // Differential-drive steering.
        // Positive curvature makes the robot turn right.
        double correction =
            PATH_SPEED * curvature * PATH_TRACK_WIDTH / 2.0;

        double leftVolts = PATH_SPEED + correction;
        double rightVolts = PATH_SPEED - correction;

        leftVolts = clampValue(leftVolts, -12.0, 12.0);
        rightVolts = clampValue(rightVolts, -12.0, 12.0);

        LeftDriveSmart.spin(forward, leftVolts, volt);
        RightDriveSmart.spin(forward, rightVolts, volt);

        wait(10, msec);
    }

    LeftDriveSmart.stop(hold);
    RightDriveSmart.stop(hold);
}


void turnTo(double newHeading, double timeout) {
    double disHead = newHeading - heading;

    // Shortest turn direction
    while (disHead > 180) disHead -= 360;
    while (disHead < -180) disHead += 360;

    myblockfunction_Turn__7C_Heading__heading_Wait__wait(disHead, timeout);
}


void driveTo(double x, double y, double Time) {
    double disX = x - xPos;
    double disY = y - yPos;
    double TurnTime = turnTime;
    double DriveTime = Time - turnTime;
    // Angle to the target
    double targetAngle = atan2(disX, disY) * 180.0 / M_PI;

    // Degrees to turn relative to current heading
    double disHead = targetAngle - heading;

    // Shortest turn direction
    while (disHead > 180) disHead -= 360;
    while (disHead < -180) disHead += 360;

    // Distance to target
    double distance = sqrt(pow(disX, 2) + pow(disY, 2));

    myblockfunction_Turn__7C_Heading__heading_Wait__wait(disHead, TurnTime);
    myblockfunction_Drive__7C_inches__in_wait__wait(distance, DriveTime);
    setPos(x, y);
}

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToScreen_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Screen_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everything else
  }
}

// "when started" hat block
int whenStarted1() {
  Brain.Screen.setFillColor(purple);
  Brain.Screen.drawRectangle(0, 0, 479, 239);
  Brain.Screen.print("Heatron Template v0.1");
  Brain.Screen.newLine();
  while (true) {
    Brain.Screen.clearLine(3);
    Brain.Screen.setCursor(Brain.Screen.row(), 1);
    Brain.Screen.setCursor(2, 2);
    Brain.Screen.print("Heading: ");
    Brain.Screen.print(printToScreen_numberFormat(), static_cast<float>(IMU.rotation(degrees)));
    Brain.Screen.newLine();
    Brain.Screen.setCursor(3, 2);
    Brain.Screen.print(printToScreen_numberFormat(), static_cast<float>(LateralPos));
    Brain.Screen.newLine();
    if (Auto == 1) {
      Brain.Screen.clearLine(4);
      Brain.Screen.setCursor(Brain.Screen.row(), 1);
      Brain.Screen.setCursor(4, 2);
      Brain.Screen.print("Auto: Match Close");
    } else if (Auto == 2) {
      Brain.Screen.clearLine(4);
      Brain.Screen.setCursor(Brain.Screen.row(), 1);
      Brain.Screen.setCursor(4, 2);
      Brain.Screen.print("Auto: Skills");
    } else if (Auto == 3) {
      Brain.Screen.clearLine(4);
      Brain.Screen.setCursor(Brain.Screen.row(), 1);
      Brain.Screen.setCursor(4, 2);
      Brain.Screen.print("Auto: Match Right");
    } else {
      Brain.Screen.clearLine(4);
      Brain.Screen.setCursor(Brain.Screen.row(), 1);
      Brain.Screen.setCursor(4, 2);
      Brain.Screen.print("Auto: ERROR");
    }
  wait(5, msec);
  }
  return 0;
}

int whenStarted2() {
    // PID constants
    kDAngular = 4.0;
    kDLateral = 2.0;
    kPAngular = 0.4;
    kPLateral = 1.0;

    IMU.startCalibration();
    while (IMU.isCalibrating()) {
        wait(50, msec);
    }

    AutoNum = 3.0;

    double previousLateralPos = 0.0;
    bool firstUpdate = true;

    while (true) {
        // Average the four 6:1 drive motor encoders.
        LateralPos =
            ((Right1.position(turns) +
              Right3.position(turns) +
              Left1.position(turns) +
              Left3.position(turns)) / 4.0)
            * ((2.75 * M_PI) * (4.0 / 3.0)) / 1.85;

        // Read current heading.
        heading = IMU.rotation(degrees);

        if (firstUpdate) {
            previousLateralPos = LateralPos;
            firstUpdate = false;
        } else {
            // Distance traveled since the previous update.
            double deltaDistance =
                LateralPos - previousLateralPos;

            double headingRadians = heading * M_PI / 180.0;

            // 0 degrees = forward (+Y).
            // Positive heading = right (+X).
            xPos += deltaDistance * sin(headingRadians);
            yPos += deltaDistance * cos(headingRadians);

            previousLateralPos = LateralPos;
        }

        wait(10, msec);
    }

    return 0;
}

// "when Brain screen pressed" hat block
void onevent_Brain_screen_pressed_0() {
 Auto += 1;
  if (Auto > 3) {
    Auto = 0;
  }
}


// "when driver control" hat block
int ondriver_drivercontrol_0() {
  RightDriveSmart.setVelocity(100.0, percent);
  LeftDriveSmart.setVelocity(100.0, percent);
  Cascade.setVelocity(100.0, percent);
  ClawOpen = true;
  ControllerTurnSpeed = .75;
  while (true) {
    leftDriveSpeed = (Controller1.Axis3.position() - Controller1.Axis1.position() * ControllerTurnSpeed) / 10.0;
    rightDriveSpeed = (Controller1.Axis3.position() + Controller1.Axis1.position() * ControllerTurnSpeed) / 10.0;
    RightDriveSmart.spin(forward, rightDriveSpeed, volt);
    LeftDriveSmart.spin(forward, leftDriveSpeed, volt);
    if (Controller1.ButtonR2.pressing()) {
      Cascade.spin(forward);
    } else if (Controller1.ButtonR1.pressing() && Cascade.position(degrees) >= 0.0) {
      Cascade.spin(reverse);
    } else {
      Cascade.stop();
    }
    if (Controller1.ButtonL2.pressing() && ClawDist.objectDistance(mm) <= 40.0) {
      Claw.set(false);
    }
    else {
      if (Controller1.ButtonL1.pressing()) {
        Claw.set(false);
      }
      else {
        if (!ClawOpen) {
          Claw.set(true);
        }
      }
    }
    if (Controller1.ButtonL2.pressing()) {
      ClawOpen = false;
    }
    if (Controller1.ButtonDown.pressing()) {
      ControllerTurnSpeed = .3;
    }
    else {
      ControllerTurnSpeed = .75;
    }
  wait(5, msec);
  }
  return 0;
}
void initAuto(double maxSpeed){
  MaxSpeed = maxSpeed; //was initially 10.0
  RightDriveSmart.setStopping(hold);
  LeftDriveSmart.setStopping(hold);
  IMU.setRotation(0.0, degrees);
  Cascade.setVelocity(100.0, percent);
}
int auto1(){
    initAuto(8.0);
  // Skills
  Claw.set(false);
  Cascade.spinFor(forward, 270.0, degrees, true);
  myblockfunction_Drive__7C_inches__in_wait__wait(17.0, 1.0);
  myblockfunction_Turn__7C_Heading__heading_Wait__wait(90.0, 1.0);
  MaxSpeed = 4.0;
  myblockfunction_Drive__7C_inches__in_wait__wait(17.0, 1.0);
  Cascade.spinFor(reverse, 270.0, degrees, true);
  Claw.set(true);
  wait(1.0, seconds);
  MaxSpeed = 8.0;
  myblockfunction_Drive__7C_inches__in_wait__wait(-10.0, 1.0);
  myblockfunction_Turn__7C_Heading__heading_Wait__wait(0.0, 1.0);
  myblockfunction_Drive__7C_inches__in_wait__wait(10.0, 1.0);
  myblockfunction_Turn__7C_Heading__heading_Wait__wait(91.0, 1.0);
  myblockfunction_Drive__7C_inches__in_wait__wait(51.0, 1.5);
  myblockfunction_Turn__7C_Heading__heading_Wait__wait(180.0, 1.0);
  MaxSpeed = 6.0;
  myblockfunction_Drive__7C_inches__in_wait__wait(28.0, 1.5);
  Claw.set(false);
  Cascade.spinFor(forward, 15.0, degrees, true);
  wait(1.0, seconds);
  MaxSpeed = 8.0;
  Cascade.spinFor(forward, 350.0, degrees, false);
  myblockfunction_Drive__7C_inches__in_wait__wait(-14.0, 1.0);
  myblockfunction_Turn__7C_Heading__heading_Wait__wait(-90.0, 1.0);
  MaxSpeed = 8.0;
  myblockfunction_Drive__7C_inches__in_wait__wait(29.0, 1.0);
  Cascade.spinFor(reverse, 90.0, degrees, true);
  Claw.set(true);
  wait(1.0, seconds);
  myblockfunction_Drive__7C_inches__in_wait__wait(-15.0, 1.0);
  myblockfunction_Turn__7C_Heading__heading_Wait__wait(-45.0, 1.0);
  myblockfunction_Drive__7C_inches__in_wait__wait(50.0, 1.0);
  return 0;
}
// "when autonomous" hat block
int onauton_autonomous_0() {
  auto2();
  /*
if (autoNum == 1) {
    auto1();
  } else if (autoNum == 2) {
    auto2();
  } else if (autoNum == 3) {
    testAuto();
  }
    */
  return 0;
}

/*
functions to use:

initAuto - initializes the robot for autonomous. Takes in a max speed as a double and 
an autonomous number as an integer - the autonomous number is used to determine which autonomous routine is printed on brain.

setPos - sets the robot's position on the field. Takes in x and y coordinates as doubles.

turnTo - turns the robot to a specific heading. Takes in the desired heading as a double, and 
a timeout as a double - timeout is the amount of time to spend turning to the desired heading.

driveTo - drives the robot to a specific position on the field. Takes in x and y coordinates as doubles,
a Time as a double - Time is the amount of time to spend driving to the desired position.
Template: driveTo(x, y, Time);

Follow Path - follows a path defined by waypoints. Takes in the path as an array of waypoints, and the count as an integer -
Waypoint system - used to define waypoints for the robot to follow. 
A waypoint is defined by an x and y coordinate as doubles.

template: 
Waypoint path[] = {
    {x1, y1},
    {x2, y2},
    {x3, y3},
    {x4, y4}
    etc...
  };

  int count = sizeof(path) / sizeof(path[0]);
  follow path(path, count);
*/
int auto2(){
  initAuto(8.0);
  setPos(0.0, 0.0);
  Waypoint path[] = {
    {0.0, 0.0},
    {0.0, 12.0},
    {-10.0, 10.0},
  };
  int count = sizeof(path) / sizeof(path[0]);

  followPath(path, count, 5.0);
  driveTo(0.0, 12.0, 1.0);
  return 0; //ends it - don't be a muffin and mess with this
}
int testAuto(){
  initAuto(8.0);
  setPos(0.0, 0.0);
  driveTo(24.0, 24.0, 1.0);
  return 0;
}

void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}



void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auto0(onauton_autonomous_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}



int main() {
  vex::competition::bStopTasksBetweenModes = false;
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // register event handlers
  Brain.Screen.pressed(onevent_Brain_screen_pressed_0);

  wait(15, msec);
  vex::task ws1(whenStarted2);
  whenStarted1();
}