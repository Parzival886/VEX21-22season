#include "vex.h"
using namespace vex;
extern competitionSide sideFlag;


void leftLeft();
void leftRight();
void rightLeft();
void rightRight();
void duiyouguaji();
void test();

void armFUp(int degree)
{
  motorArmF.spin(fwd,100,pct);
  waitUntil(motorArmF.position(degrees)>degree);
  motorArmF.spin(fwd,0,pct);
}

void myAuto()
{
  switch(sideFlag){
    case LEFTLEFT:
      leftLeft();
      break;
    case LEFTRIGHT:
      leftRight();
      break;
    case RIGHTLEFT:
      rightLeft();
      break;
    case RIGHTRIGHT:
      rightRight();
      break;
    case DUIYOUGUAJI:
      duiyouguaji();
      break;
    case TEST:
      test();
  }
}

void leftLeft()//默认的，不用管
{
  pForward(1500, Inertial21.rotation(), true, false);
  pForwardArmF(-600, 45, true, false, true);
  turnTo(0);
  pForwardMM(400, 0);
  armFUp(1500);
  turnTo(-60);
  pForward(200, -60, false, true);
  chaB.set(true);
  wait(2000, msec);
  pForward(-400, -60, false, false);
  pForwardMilliSecond(-30, 1000, -60, false);
  chaB.set(false);
  wait(2000, msec);
  pForward(200, -60, false, false);
  motorIn.spin(fwd,70,pct);
}

void leftRight()//默认的，不用管
{

}

void rightLeft()//蓝右
{
  int flag = 2;   //flag == 1 ->直线冲      flag == 2 -> 抢中塔
  
  if (flag == 1)
  {//直线冲
  pForward(1800, 0, true, false);   //前进并且检测到环塔后自动夹取，如果没有检测到最大行进距离1800度，检测到则夹取立即执行下一条语句
  pForwardArmF(-400, 0, true, false, false);  //后退并且抬起前臂，第四个参数设为false，关闭自动夹取
  pForwardMM(800, 0);   //离墙800毫米   （此处位置根据自己机器人调整）
  turnTo(-90);      //转到-90度方向
  chaB.set(true);   //放下后叉
  pForward(200, -90, false, true);   //前进200度，关闭自动夹取
  wait(1000, msec);    //等待后叉完全放下
  pForward(-500, -90, false, false);   //后退200度，关闭自动夹取，不自锁
  pForwardMilliSecond(-30, 1000, -90, false);    //以30的功率后退1000毫秒，不自锁
  chaB.set(false);    //抬起后叉
  wait(2000, msec);   //等待完全抬起
  pForward(1100, -90, false, true);    //前进800度，关闭自动夹取
  clawF.set(false);  //松开夹子
  pForwardMM(1000, -90);    //后退到离墙1000毫米的位置        （此处根据自己机器人调整）
  turnTo(-45);     //转到-4度方向
  pForwardArmF(1400, -45, false, true, false);  //前进并且放下前臂，检测到环塔后自动夹取，如果没有检测到最大行进距离1100度，检测到则夹取立即执行下一条语句
  motorIn.spin(fwd,70 ,pct);  //开启吸环电机
  pForwardArmF(-1400, -46, true, false, false);}  //后退并且抬起前臂，第四个参数设为false，关闭自动夹取

  if (flag == 2)
  {//抢中塔
  pForward(1700, Inertial21.rotation(), true, false);   //沿摆放方向前进并且检测到环塔后自动夹取，如果没有检测到最大行进距离1700度，检测到则夹取立即执行下一条语句
  pForwardArmF(-1100, -40, true, false, true);   //后退1100度并且抬起前臂，第四个参数设为false，关闭自动夹取
  turnTo(-90);  //转向-90度方向
  chaB.set(true);  //放下后叉
  pForwardArmF(600, -90, false, false, true);  //前进同时放下前臂，关闭自动夹取
  wait(50, msec);
  clawF.set(false);    //松开夹子
  wait(50, msec);      //等环塔离开夹子
  pForward(-200, -90, false, true);  //后退200度，关闭自动夹取
  turnTo(0);   //转向0度方向
  pForwardMM(750, 0);   //离墙760毫米
  turnTo(-90);    //转向-90度方向
  pForward(-300, -90, false, false);   //后退300度，关闭自动夹取
  pForwardMilliSecond(-30, 1000, -90, false);  //30的功率后退1000毫秒
  chaB.set(false);   //抬起后叉
  wait(2000, msec);  //等待后叉完全抬起
  pForwardMM(700, -90);  //前进到离墙720毫米
  turnTo(0);  //转向0度方向
  motorIn.spin(fwd,70,pct);   //开启吸环电机
  pForward(600, 0, true, false);    //前进并且检测到环塔后自动夹取，如果没有检测到最大行进距离600度，检测到则夹取立即执行下一条语句
  pForwardArmF(-600, 0, true, false, false);}  //后退并且抬起前臂，第四个参数设为false，关闭自动夹取
}

void rightRight()//红右
{ 
  int flag = 2;   //flag == 1 -> 直线冲      flag == 2 -> 抢中塔
  
  
  if (flag == 1)
  {//直线冲
  pForward(1800, 0, true, false);   //前进并且检测到环塔后自动夹取，如果没有检测到最大行进距离1800度，检测到则夹取立即执行下一条语句
  pForwardArmF(-400, 0, true, false, false);  //后退并且抬起前臂，第四个参数设为false，关闭自动夹取
  pForwardMM(800, 0);   //离墙800毫米   （此处位置根据自己机器人调整）
  turnTo(-90);      //转到-90度方向
  chaB.set(true);   //放下后叉
  pForward(200, -90, false, true);   //前进200度，关闭自动夹取
  wait(1000, msec);    //等待后叉完全放下
  pForward(-500, -90, false, false);   //后退200度，关闭自动夹取，不自锁
  pForwardMilliSecond(-30, 1000, -90, false);    //以30的功率后退1000毫秒，不自锁
  chaB.set(false);    //抬起后叉
  wait(2000, msec);   //等待完全抬起
  pForward(1100, -90, false, true);    //前进800度，关闭自动夹取
  clawF.set(false);  //松开夹子
  pForwardMM(1000, -90);    //后退到离墙1000毫米的位置        （此处根据自己机器人调整）
  turnTo(-45);     //转到-4度方向
  pForwardArmF(1400, -45, false, true, false);  //前进并且放下前臂，检测到环塔后自动夹取，如果没有检测到最大行进距离1100度，检测到则夹取立即执行下一条语句
  motorIn.spin(fwd,70 ,pct);  //开启吸环电机
  pForwardArmF(-1400, -46, true, false, false);}  //后退并且抬起前臂，第四个参数设为false，关闭自动夹取


  if (flag == 2)
  {//抢中塔
  
  pForward(1700, Inertial21.rotation(), true, false);   //沿摆放方向前进并且检测到环塔后自动夹取，如果没有检测到最大行进距离1700度，检测到则夹取立即执行下一条语句
  pForwardArmF(-1100, -40, true, false, true);   //后退1100度并且抬起前臂，第四个参数设为false，关闭自动夹取
  turnTo(-90);  //转向-90度方向
  chaB.set(true);  //放下后叉
  pForwardArmF(600, -90, false, false, true);  //前进同时放下前臂，关闭自动夹取
  wait(50, msec);
  clawF.set(false);    //松开夹子
  wait(50, msec);      //等环塔离开夹子
  pForward(-200, -90, false, true);  //后退200度，关闭自动夹取
  turnTo(0);   //转向0度方向
  pForwardMM(750, 0);   //离墙760毫米
  turnTo(-90);    //转向-90度方向
  pForward(-300, -90, false, false);   //后退300度，关闭自动夹取
  pForwardMilliSecond(-30, 1000, -90, false);  //30的功率后退1000毫秒
  chaB.set(false);   //抬起后叉
  wait(2000, msec);  //等待后叉完全抬起
  pForwardMM(700, -90);  //前进到离墙720毫米
  turnTo(0);  //转向0度方向
  motorIn.spin(fwd,70,pct);   //开启吸环电机
  pForward(600, 0, true, false);    //前进并且检测到环塔后自动夹取，如果没有检测到最大行进距离600度，检测到则夹取立即执行下一条语句
  pForwardArmF(-600, 0, true, false, false);}  //后退并且抬起前臂，第四个参数设为f

}

void duiyouguaji()
{
  pForward(100, 0, true, true);
  wait(100, msec);
  clawF.set(false);
  wait(50, msec);
  pForward(-250, 30, false,true);
  turnTo(-90);
  pForwardMM(540, -90);
  turnTo(-180);
  chaB.set(true);
  pForward(-2500, -180, false, true);
  pForwardMilliSecond(-30, 1000, -180, false);
  chaB.set(false);
  wait(2000, msec);
  pForward(300, -180, false, false);
  motorIn.spin(fwd,70,pct);
}

void test()
{

}