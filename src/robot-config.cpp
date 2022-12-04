#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature roll_vision__R_RED = signature (1, 8687, 10753, 9720, -1697, -855, -1276, 0.9, 0);
signature roll_vision__R_BLUE = signature (2, -3981, -3007, -3494, 11141, 13137, 12139, 1.5, 0);
vision roll_vision = vision (PORT19, 50, roll_vision__R_RED, roll_vision__R_BLUE);
/*vex-vision-config:end*/
motor spin_roll = motor(PORT20, ratio18_1, false);
motor FrontLeftMotorA = motor(PORT1, ratio18_1, true);
motor FrontLeftMotorB = motor(PORT2, ratio18_1, false);
motor_group FrontLeft = motor_group(FrontLeftMotorA, FrontLeftMotorB);
motor BackLeftMotorA = motor(PORT3, ratio18_1, false);
motor BackLeftMotorB = motor(PORT4, ratio18_1, true);
motor_group BackLeft = motor_group(BackLeftMotorA, BackLeftMotorB);
motor BackRightMotorA = motor(PORT7, ratio18_1, false);
motor BackRightMotorB = motor(PORT9, ratio18_1, true);
motor_group BackRight = motor_group(BackRightMotorA, BackRightMotorB);
motor FrontRightMotorA = motor(PORT6, ratio18_1, false);
motor FrontRightMotorB = motor(PORT8, ratio18_1, true);
motor_group FrontRight = motor_group(FrontRightMotorA, FrontRightMotorB);
controller Controller1 = controller(primary);
motor PickPan = motor(PORT18, ratio18_1, false);
motor pushPan = motor(PORT16, ratio18_1, false);
motor ThrowLeft = motor(PORT11, ratio18_1, false);
motor ThrowRight = motor(PORT12, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}