using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor motorLF;
extern motor motorLM;
extern motor motorLB;
extern motor motorRF;
extern motor motorRM;
extern motor motorRB;
extern motor motorArmF;
extern digital_out clawF;
extern digital_out chaB;
extern inertial Inertial21;
extern distance distanceF;
extern motor motorIn;
extern limit limitSwitchF;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );