/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       z52c                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  *#*#*#*#*#*#*#*#*#*#                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// motorLF              motor         6               
// motorLM              motor         13              
// motorLB              motor         11              
// motorRF              motor         5               
// motorRM              motor         2               
// motorRB              motor         1               
// motorArmF            motor         19              
// clawF                digital_out   D               
// chaB                 digital_out   B               
// Inertial21           inertial      21              
// distanceF            distance      3               
// motorIn              motor         4               
// limitSwitchF         limit         C               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "ui.h"

using namespace vex;
competitionSide sideFlag;

competition Competition;
ui _ui;
task taskScreenPress = task(_tPressDetect);


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  wait(1, sec);
  //惯性传感器校准
  inertialInit(Inertial21);
  //惯性传感器校准完成，遥控器上输出提示信息
  Controller1.Screen.setCursor(1, 0);
  Controller1.Screen.print("inertial init sucess");
  //创建界面
  _ui = ui();
  //开启屏幕触点检测任务
  taskScreenPress.resume();
}


//使用场控的自动部分程序
void autonomous(void) {
  //计时器重置
  timer t;
  t.reset();
  //自动程序内容，在auto.cpp文件中
  motorArmF.setBrake(hold);
  myAuto();
  //在遥控器上输出自动消耗的时间
  Controller1.Screen.setCursor(1, 0);
  Controller1.Screen.print("%f",t.time(sec));
}

//手动部分
void usercontrol(void) 
{
  motorArmF.setBrake(hold);
  while (1) {
    //遥控程序内容，在rc.cpp文件中
    myRemoteControl();
    wait(20, msec); 
  }
}


int main() {
  //设置自动阶段调用的函数
  Competition.autonomous(autonomous);
  //设置手动阶段调用的函数
  Competition.drivercontrol(usercontrol);
  //执行pre_auton()中的预执行内容
  pre_auton();
  //无限循环，防止程序结束
  while (true) {
    wait(100, msec);
  }
}
