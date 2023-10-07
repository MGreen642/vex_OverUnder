#include <iostream>     // std::cout
#include <complex>      // std::complex
#include <math.h>


int main () {
    double Axis3 = -10;
    double Axis4 = 50;

    double steering = pow((Axis4),1.2)/10;
    if (Axis4 < 0) {
        steering = steering*-1;
    }
    double speed = Axis3;
    double left = speed-steering;
    double right = speed+steering;
    if (left > 100) {
        right = right - (left-100);
        left = 100;
    } else if (left < -100) {
        right = right - (left+100);
        left = -100;
    }
    if (right > 100) {
        left = left - (right-100);
        right = 100;
    } else if (right < -100) {
        left = left - (right+100);
        right = -100;
    }

    std::cout << right << left << '\n';
}

