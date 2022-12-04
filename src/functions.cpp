#include "vex.h"
#include<cmath>
#include "robot-config.h"

using namespace vex;

// 前进
void Run(double l, double r) {
  FrontLeft.spin(fwd, l, pct);
  BackLeft.spin(fwd, l, pct);
  FrontRight.spin(fwd, r, pct);
  BackRight.spin(fwd, r, pct);
}

//前进函数2
void VRUN(double l,double r)
{
  vexMotorVoltageSet(1,l*120);
  vexMotorVoltageSet(2,l*120);
  vexMotorVoltageSet(4,l*120);
  vexMotorVoltageSet(3,l*120);
  vexMotorVoltageSet(6,r*120);
  vexMotorVoltageSet(8,r*120);
  vexMotorVoltageSet(9,r*120);
  vexMotorVoltageSet(7,r*120);
}

//打表转筒
void Roll()
{
  spin_roll.spin(forward,80,pct);
  task::sleep(1500);
  spin_roll.spin(forward,0,pct);
}

//跑对应的长度
void run_line_distance(double cell_num,double speed,move_direction direct)
{
  const double K = RUN_LINE_K;//对应常数，可以进行调试得到最终的长度
  double run_time=cell_num/speed*K;
  speed *= (direct==move_direction::fwd?1:-1);
  printf("into auto");
  Run(speed,speed);
  task::sleep(run_time);
  Run(0,0);
}

//转向，对应单位为角度
void rotate_angle(const double rotate_angle, const double speed,rotate_direction direct)
{
  // 旋转180度,速度为20
  const double K=ROTATE_K;
  const int rdirect = (direct == rotate_direction::left?1:-1);
  double runtime;
  runtime=rotate_angle/speed*K;
  Run(rdirect*speed, -rdirect*speed);
  task::sleep(runtime);
  Run(0, 0);
}

//投掷飞盘，假设调用函数前已经对准
void auto_throw(int times,bool High)
{
  double V=High?100:80;
  for(int i=0;i<times;i++){
    ThrowLeft.spin(reverse,V,pct);
    ThrowRight.spin(reverse,V-10,pct);
    task::sleep(1000);
    pushPan.spinFor(reverse,360,degrees,100,(velocityUnits)pct,false);
    if(i==0){
      task::sleep(1000);
    }
  }
  ThrowLeft.spin(reverse,0,pct);
  ThrowRight.spin(reverse,0,pct);
}