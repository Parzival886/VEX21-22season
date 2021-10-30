/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#ifndef VEX_H
#define VEX_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string.h>
#include <iostream>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

enum competitionSide{
  LEFTLEFT,
  LEFTRIGHT,
  RIGHTLEFT,
  RIGHTRIGHT,
  DUIYOUGUAJI,
  TEST
};

void myRemoteControl();
void myAuto();

  /**
  * @brief 使用左右速度直接控制底盘
  * @param vl：指定左侧的电机速度
  * @param vr：指定右侧的电机速度
  */
void diPan(int vl,int vr);

  /**
  * @brief 将底盘电机角度重置为0
  */
void diPanRestPosition();

  /**
  * @brief 读取左侧底盘电机角度的平均值
  */
double getDipanLeftPosition();

  /**
  * @brief 读取右侧底盘电机角度的平均值
  */
double getDipanRightPosition();


  /**
  * @brief 读取底盘电机角度的平均值
  */
double getDipanPosition();

  /**
  * @brief 惯性传感器校准，使用之前调用
  * @param InertialDefault：惯性传感器（例如 Inertial21）
  */
void inertialInit(inertial InertialDefault=Inertial21);

  /**
  * @brief 设置底盘电机的刹车模式
  * @param mode：hold自锁，coast滑行
  */
void setDiPanBrake(brakeType mode);


  /**
  * @brief 前进指定度数
  * @param speed：速度
  * @param degree: 度数
  * @param ifHold: 结束之后底盘电机是否自锁，不填默认不自锁，填true自锁
  */
void forwardDegree(float speed,float degree,bool ifHold=false);

  /**
  * @brief 前进指定毫秒数
  * @param speed：速度
  * @param tMsec: 毫秒数
  * @param ifHold: 结束之后底盘电机是否自锁，不填默认不自锁，填true自锁
  */
void forwardMilliSecond(float speed,float tMsec,bool ifHold=false);

  /**
  * @brief 转到指定的度数，以初始为基准0度,
  * @param degree: 需要转到的度数值
  * @param ifHold: 结束之后底盘电机是否自锁，默认自锁
  */
void turnTo(float degree,bool ifHold=true,float kp=4,float kd=20);

  /**
  * @brief 按照指定的朝向前进指定的度数
  * @param degree: 度数
  * @param heading: 朝向的角度
  * @param ifAutoClaw: 是否检测到环塔之后自动夹住
  * @param ifHold: 结束之后底盘电机是否自锁,填true自锁，填false不自锁
  */
void pForward(float degree,float heading,bool ifAutoClaw,bool ifHold,float kp=1.2);


  /**
  * @brief 按照指定的朝向前进指定时间
  * @param speed: 速度
  * @param tMsec: 时间，毫秒数
  * @param heading: 朝向的角度
  * @param ifHold: 结束之后底盘电机是否自锁
  */
void pForwardMilliSecond(float speed,float tMsec,float heading,bool ifHold);


  /**
  * @brief 前进或后退到后面的距离传感器到指定距离（单位毫米）
  * @param distanceMM: 距离-毫米
  * @param heading: 朝向的角度
  * @param ifHold: 结束之后底盘电机是否自锁,不填默认自锁，填false不自锁
  */
void pForwardMM(float distanceMM,float heading,bool ifHold=true,float kp=0.7);

  /**
  * @brief 设置底盘电机的刹车模式
  * @param mode：hold自锁，coast滑行
  */
void setDiPanBrake(brakeType mode);

  /**
  * @brief 前进或后退到后面的距离传感器到指定距离（单位毫米）同时收起或放下前臂
  * @param distanceMM: 距离-毫米
  * @param heading: 朝向的角度
  * @param isUp: 前臂是否抬起，抬起true，放下false
  * @param ifAutoClaw: 是否检测到环塔之后自动夹住
  * @param ifHold: 结束之后底盘电机是否自锁,不填默认自锁，填false不自锁
  */
void pForwardMMArmF(float distanceMM,float heading,bool ifUp,bool ifAutoClaw,bool ifHold,float kp=0.7);


  /**
  * @brief 前进指定度数,同时收起或放下前臂
  * @param degree: 度数
  * @param heading: 朝向的角度
  * @param ifUp: 前臂是否抬起，抬起true，放下false
  * @param ifAutoClaw: 是否检测到环塔之后自动夹住
  * @param ifHold: 结束之后底盘电机是否自锁,填true自锁，填false不自锁
  */
void pForwardArmF(float degree,float heading,bool ifUp,bool ifAutoClaw,bool ifHold,float kp=1.2);


  /**
  * @brief 前臂放到底
  */
void armFDown();

  /**
  * @brief 前臂抬起100度
  */
void armFUp();

#define ARMFUPDEGREE 100

#define FORWARDINERTIALKP 3
#define FORWARDINERTIALKI 0
#define FORWARDINERTIALKD 12

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

#endif