// #include "pid.h"
// #include <stdio.h>

// //一个用法示例
// void pid_main() {

//     PID pid = PID(0.1, 100, -100, 0.1, 0.01, 0.5);

//     double val = 20;
//     double target = 3;//根据对应程序改
//     for (int i = 0; i < 100; i++) {
//         //val是当前值 inc为改变量
//         double inc = pid.calculate(target, val);
//         printf("val:% 7.3f inc:% 7.3f\n", val, inc);
//         val += inc;
//     }

//     return 0;
// }