#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <cmath>

void linear(double x0, double dt, double t, double k) {         // y' = k
    double steps = t/dt;
    double x = x0;

    std::cout << x << '\n';
    for(int i = 0; i < steps; ++i) {
        x = x + k*dt;
        std::cout << x << '\n';
    }
}

void exp_1(double x0, double dt, double t) {                    // y' = y
    double steps = t/dt;
    double x = x0;

    std::cout << x << '\n';
    for(int i = 0; i < steps; ++i) {
        x = x*(1 + dt);
        std::cout << x << '\n';
    }
}

void quad(double x0, double dt, double t) {                     // y' = y^2
    double steps = t/dt;
    double x = x0;

    std::cout << x << '\n';
    for(int i = 0; i < steps; ++i) {
        x = x*(1 + x*dt);
        std::cout << x << '\n';
    }
}

void t_(double x0, double dt, double T) {                       // y' = t
    double steps = T/dt;
    double x = x0;
    double t = 0;
    std::ofstream outfile;
    outfile.open("safklasdhfjkdahfjkas");

    //std::cout << x << '\n';
    for(int i = 0; i <= steps; ++i) {
        x = x + t*dt;
        t = t + dt;
        //std::cout << x << '\n';
        //outfile << t << '\t' << x << '\n';
    }
    outfile.close();
}

void strut(double x0, double dt, double T) {                     // y'^2 = y + t
    double steps = T/dt;
    double x = x0;
    double t = 0;
    std::ofstream outfile;
    outfile.open("strut");

    //std::cout << x << '\n';
    for(int i = 0; i <= steps; ++i) {
        x = x + sqrt(t + x)*dt;
        t = t + dt;
        //std::cout << x << '\n';
        outfile << t << '\t' << x << '\n';
    }
    outfile.close();
}

void osc_arm(double x0, double y0, double dt, double T) {        // x'' + x = 0, y = x'
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open("osc_arm");

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = y - x*dt;
        x = z;

        outfile << x << '\n';
    }
    outfile.close();
}

void osc_damp(double x0, double y0, double dt, double T) {        // x'' + x' + x = 0, y = x'
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open("osc_damp");

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = y - (x+y)*dt;
        x = z;

        outfile << x << '\n';
    }
    outfile.close();
}

int main() {
    osc_damp(1,0,0.01,15);
}