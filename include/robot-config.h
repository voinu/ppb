using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature roll_vision__R_RED;
extern signature roll_vision__R_BLUE;
extern signature roll_vision__SIG_3;
extern signature roll_vision__SIG_4;
extern signature roll_vision__SIG_5;
extern signature roll_vision__SIG_6;
extern signature roll_vision__SIG_7;
extern vision roll_vision;
extern motor spin_roll;
extern motor_group FrontLeft;
extern motor_group BackLeft;
extern motor_group BackRight;
extern motor_group FrontRight;
extern controller Controller1;
extern motor PickPan;
extern motor pushPan;
extern motor ThrowLeft;
extern motor ThrowRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );