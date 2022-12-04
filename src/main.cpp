/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\ljx                                              */
/*    Created:      Tue Nov 22 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// roll_vision          vision        19              
// spin_roll            motor         20              
// FrontLeft            motor_group   1, 2            
// BackLeft             motor_group   3, 4            
// BackRight            motor_group   7, 9            
// FrontRight           motor_group   6, 8            
// Controller1          controller                    
// PickPan              motor         18              
// pushPan              motor         16              
// ThrowLeft            motor         11              
// ThrowRight           motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
int v11=90,Time=0,Stop=0;
bool Left=true;//初始推盘必须在左边

/****对应自动的行走距离****/
const double auto_distance[]{
  1
};

/****对应的速度*********/
const double auto_speed[]{
  50
};

//对应的旋转角度
const double rotate_angle_val[]{
  360
};

//对应的旋转速度
const double rotate_speed_val[]{
  20
};

int main() {
  
 // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //第一步：转滚筒
  Roll();
  ThrowLeft.spin(forward,100,pct);
  ThrowRight.spin(forward,90,pct);//先转着
  //第1.5步：走一点（留出余位）
  //Run(-30,-30);
  //task::sleep(300);
  //Run(0,0);
  //第二步：给爷投！（场地角落处）
  rotate_angle(30,80,rotate_direction::right);
  pushPan.spinFor(reverse,360,degrees,100,(velocityUnits)pct,false);
  task::sleep(1000);
  pushPan.spinFor(reverse,360,degrees,100,(velocityUnits)pct,false);
  task::sleep(400);
  ThrowLeft.spin(forward,0,pct);
  ThrowRight.spin(forward,0,pct);//歇一会防止过热
  //第三步：右转准备移动至场地中央
  //rotate_angle(132,40,rotate_direction::right);
  rotate_angle(150,40,rotate_direction::right);
  //第四步：边走边捡
  Run(20,20);
  PickPan.spin(forward,100,pct);
  task::sleep(3000);
  ThrowLeft.spin(forward,100,pct);
  ThrowRight.spin(forward,90,pct);//先转着准备下一次投掷
  task::sleep(3000);
  PickPan.spin(forward,0,pct);
  Run(0,0);
  //第五步：转向高筐投
  rotate_angle(90,80,rotate_direction::left);
  pushPan.spinFor(reverse,360,degrees,100,(velocityUnits)pct,false);
  task::sleep(1500);
  pushPan.spinFor(reverse,360,degrees,100,(velocityUnits)pct,false);
  task::sleep(400);
  

  while(1)
  {
    /***操纵***/
    int fb,lf;
    fb=Controller1.Axis3.value();
    lf=Controller1.Axis4.value();
    int FB=fb<0?-fb:fb,LF=lf<0?-lf:lf;
    fb=FB>15?fb:0;
    lf=LF>15?lf:0;
    if(fb!=0||lf!=0)Run((fb+lf)*100.0/127.0,(fb-lf)*100.0/127.0);
    else Run(0,0);

    /****************按键操纵***************/

    //改变电压高低
    if(Controller1.ButtonUp.pressing())v11=100;
    if(Controller1.ButtonDown.pressing())v11=60;


    //飞盘投掷
    if(Controller1.ButtonR1.pressing()){
      ThrowLeft.spin(forward,v11,pct);
      ThrowRight.spin(forward,v11-10,pct);
    }
    else if(Controller1.ButtonR2.pressing()){
      ThrowLeft.spin(reverse,v11,pct);
      ThrowRight.spin(reverse,v11-10,pct);
      /*Time+=8;
      if(Time>1200){
        Time=0;
        ThrowPan.spin(reverse,v11,pct);
        pushPan.spinFor(reverse,361,degrees,100,(velocityUnits)pct,false);
        task::sleep(400);
      }*/
    }
    else{
      /*Stop+=8;
      if(Stop>500)Time=Stop=0;*/
      ThrowLeft.spin(reverse,0,pct);
      ThrowRight.spin(reverse,0,pct);
    }

    //飞盘拾取
    if(Controller1.ButtonX.pressing())PickPan.spin(forward,100,pct);
    else if(Controller1.ButtonB.pressing())PickPan.spin(reverse,100,pct);
    else PickPan.spin(forward,0,pct);

    //转滚筒
    if(Controller1.ButtonL1.pressing())spin_roll.spin(forward,100,pct);
    else if(Controller1.ButtonL2.pressing())spin_roll.spin(reverse,100,pct);
    else spin_roll.spin(reverse,0,pct);

    //转推盘
    if(Controller1.ButtonA.pressing()){
      pushPan.spinFor(reverse,360,degrees,100,(velocityUnits)pct,false);
      task::sleep(400);
      /*if(Left){
        Left=false;
        pushPan.spinFor(reverse,175,degrees,100,(velocityUnits)pct,false);
        task::sleep(500);
      }
      else{
        Left=true;
        pushPan.spinFor(forward,175,degrees,60,(velocityUnits)pct,false);
        task::sleep(500);
      }*/
    }

    task::sleep(8);//防过载
  }
  
}
