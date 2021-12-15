#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>

double I(int time) {
    if (time = 0.5) { return 0.5; }
    else { return 0; }
}

void FHN(double v0, double w0, double I_, float eps, double a, double b, float h, int steps,std::string s) {
    double v=v0,w=w0,z=0.;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i < steps; ++i) {
        z = h*(v - pow(v,3)/3 - w + I(i*h)) + v;
        w = h*eps*(v - b*w + a) + w;
        v = z;
        //I = 0;

        outfile << v << '\t' << w << '\n';
    }
    outfile.close();
}

void FHNtime(double v0, double w0, double I_, float eps, double a, double b, float h, int steps,std::string s) {
    double v=v0,w=w0,z=0.;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i < steps; ++i) {
        z = h*(v - pow(v,3)/3 - w + I(i*h)) + v;
        w = h*eps*(v - b*w + a) + w;
        v = z;
        //I = 0;

        outfile << v << '\t' << (i+1)*h << '\n';
    }
    outfile.close();
}

int main() {
    //double v=-1,w=1;
    //double z;
    //double I=0.1;
    //double eps = 0.33;
    //double b=0.2,a=0.2;
    //float h = 0.01;
    //int steps = 10000;
    
    FHN(-1,1,0.1,0.33,0.2,0.2,0.01,10000,"FHNtest.dat");
    FHNtime(-1,1,0.1,0.33,0.2,0.2,0.01,10000,"FHNtimetest.dat");
}