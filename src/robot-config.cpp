#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor motorLF = motor(PORT6, ratio18_1, false);
motor motorLM = motor(PORT13, ratio18_1, false);
motor motorLB = motor(PORT11, ratio18_1, true);
motor motorRF = motor(PORT5, ratio18_1, true);
motor motorRM = motor(PORT2, ratio18_1, true);
motor motorRB = motor(PORT1, ratio18_1, false);
motor motorArmF = motor(PORT19, ratio18_1, false);
digital_out clawF = digital_out(Brain.ThreeWirePort.D);
digital_out chaB = digital_out(Brain.ThreeWirePort.B);
inertial Inertial21 = inertial(PORT21);
distance distanceF = distance(PORT3);
motor motorIn = motor(PORT4, ratio18_1, true);
limit limitSwitchF = limit(Brain.ThreeWirePort.C);

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