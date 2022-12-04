/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

//定义相应参数
#define ROTATE_K      256//原先 265
#define RUN_LINE_K    44000

//前后方向
enum class move_direction{
  fwd,bk
};

//转的方向
enum class rotate_direction{
  left,right
};

//走对应直线的长度，cell_num为走的格子的个数，speed为速度，direct为前进和后退的选择
void run_line_distance(double cell_num,const double speed,move_direction direct);//走直线的函数速度为对应，距离为格子
//行走的函数
void Run(double l, double r);
//转向函数，rotate_angle代表转的角度，speed控制转向方向，direct控制转向方向。
void rotate_angle(const double rotate_angle, const double speed, rotate_direction direct);//转向函数,left1,right0
//转筒的函数
void Roll();
//投掷函数，High为真表示高投掷
void auto_throw(int times,bool High);