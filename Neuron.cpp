#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>

double solution(int time) {
    if(time == 0.002) { return 2; }
    else { return 0; }
}

void neuron(double h=0.01, double e=0.1, double T=2., double x0=1.2, double b0=0.6, int steps = 50000, std::string s = "File.dat") {
    double x=x0,b=b0;
    double z;
    double t = 0.;
    std::ofstream outfile;
    std::ofstream outfile1;
    outfile.open(s);
    outfile1.open("testosone.dat");

    for(int i = 0; i < steps; ++i) {
        z = -(h/e)*(pow(x,3) - T*x + b) + x;
        b = (x-1)*h + b;
        x = z;
        //w = -(h/e)*(pow(y,3) - T*y + b_) + y;
        //b_ = (y-x)*h + b_;
        //y = w;
        //std::cout << solution(i*h);

        t = (i+1)*h;
        outfile << x << '\t' << b << '\n';
        outfile1 << t << '\t' << x << '\n';
    }
    outfile.close();
    outfile1.close();
}

int main() {
    double x=0.65,y=-0.65,b=-0.15,d=0.15,z=0.,w=0.;
    float h = 0.01;
    int steps = 10000;
    double T1 = 4.;
    double T2 = 1;
    double e = 0.1;

    std::ofstream outfile;
    std::ofstream outfile1;
    outfile.open("Accop.dat");
    outfile1.open("Accop1.dat");
    for(int i = 0; i < steps; ++i) {
        z = -(h/e)*(pow(x,3) - T1*x + b) + x;
        b = (x-y)*h + b;
        x = z;
        w = -(h/e)*(pow(y,3) - T2*y + d) + y;
        d = (y-x)*h + d;
        y = w;

        outfile << x << '\t' << b << '\n';
        outfile1 << y << '\t' << d << '\n';
    }
    outfile.close();
    outfile1.close();
}