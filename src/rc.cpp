#include "vex.h"
using namespace vex;

bool directionForward = true;

void rcArmF()
{
  int a2;
  a2 = Controller1.Axis2.position(pct);
  if(abs(a2)<10)
    a2=0;
  if(a2>0)
  {
    if(motorArmF.position(degrees)>1690)
        motorArmF.spin(fwd,0,pct);
      else
        motorArmF.spin(fwd,a2,pct);
  }
  else
  {
    if(motorArmF.position(degrees)<10)
          motorArmF.spin(fwd,0,pct);
    else
          motorArmF.spin(fwd,a2,pct);
  }
}

void rcIn()
{
  if(Controller1.ButtonL2.pressing())
    motorIn.spin(fwd,-100,pct);
  else if(Controller1.ButtonL1.pressing())
    motorIn.spin(fwd,100,pct);
  else 
    motorIn.spin(fwd,0,pct);
}

void rcArmB()
{

}


void directionChange()
{
  if(Controller1.ButtonRight.pressing())
  {
    Controller1.rumble("...-");
    directionForward = !directionForward;
    waitUntil(!Controller1.ButtonRight.pressing());
  }
}

void yijianzisuo()
{
  if(Controller1.ButtonUp.pressing())
  {
    Controller1.rumble("...-");
    setDiPanBrake(hold);
    waitUntil(!Controller1.ButtonUp.pressing());
  }
  if(Controller1.ButtonDown.pressing())
  {
    Controller1.rumble("...-");
    setDiPanBrake(coast);
    waitUntil(!Controller1.ButtonDown.pressing());
  }
}

void rcClawF()
{
  if(Controller1.ButtonR1.pressing())
  {
    clawF.set(false);
  }else if (Controller1.ButtonR2.pressing()) {
    clawF.set(true);
  }
}

void rcChaB()
{
  if(Controller1.ButtonA.pressing())
  {
    chaB.set(false);
  }else if (Controller1.ButtonB.pressing()) {
    chaB.set(true);
  }
}

void rcDipan()
{
  static int a3,a4;
  a3 = Controller1.Axis3.position(pct);
  a4 = Controller1.Axis4.position(pct);
  if(abs(a3)<15)
    a3=0;
  if(abs(a4)<15)
    a4=0;
  if(directionForward)
    diPan(a3+a4, a3-a4);
  else
    diPan(-a3+a4, -a4-a3);
}

void myRemoteControl()
{
  rcDipan();
  rcArmF();
  rcIn();
  rcChaB();
  rcClawF();
  rcArmF();
  yijianzisuo();
  directionChange();
}