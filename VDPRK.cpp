#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>

void vdpRK(double x0, double y0, double h, double mu, double T, std::string s) {        // x'' + mu(1-x^2)x' + x = 0, y = x'
    double steps = T/h;
    double x = x0;
    double y = y0;
    double k1,k2,l1,l2;
    double z;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i != steps; ++i) {
        k1 = h*y;
        l1 = h*(mu*(1-pow(x,2))*y - x);
        k2 = h*(y+l1);
        z = x + (k1 + k2)/2;
        l2 = h*(mu*(1-pow(x+k1,2))*(y + l1*h/2) - (x+k1));
        y = y + (l1 + l2)/2;
        x = z;

        outfile << x << '\t' << y << '\n';
    }
    outfile.close();
}

void xRK(double x0, double y0, double h, double mu, double T, std::string s) {
    double steps = T/h;
    double x = x0;
    double y = y0;
    double k1,k2,l1,l2;
    double z;
    std::ofstream outfile;
    outfile.open(s);
    outfile << 0 << '\t' << x0 << '\n';

    for(int i = 0; i != steps; ++i) {
        k1 = h*y;
        l1 = h*(mu*(1-pow(x,2))*y - x);
        k2 = h*(y+l1);
        z = x + (k1 + k2)/2;
        l2 = h*(mu*(1-pow(x+k1,2))*(y + l1*h/2) - (x+k1));
        y = y + (l1 + l2)/2;
        x = z;

        outfile << (i+1)*h << '\t' << x << '\n';
    }
    outfile.close();
}

void pRK(double x0, double y0, double h, double mu, double T, std::string s) {
    double steps = T/h;
    double x = x0;
    double y = y0;
    double k1,k2,l1,l2;
    double z;
    std::ofstream outfile;
    outfile.open(s);
    outfile << 0 << '\t' << y0 << '\n';

    for(int i = 0; i != steps; ++i) {
        k1 = h*y;
        l1 = h*(mu*(1-pow(x,2))*y - x);
        k2 = h*(y+l1);
        z = x + (k1 + k2)/2;
        l2 = h*(mu*(1-pow(x+k1,2))*(y + l1*h/2) - (x+k1));
        y = y + (l1 + l2)/2;
        x = z;

        outfile << (i+1)*h << '\t' << y << '\n';
    }
    outfile.close();
}

int main() {
    vdpRK(1,1,0.0001,1,50,"RKmu1.dat");
    //xRK(1,1,0.001,1,50,"xRKmu1.dat");
    //pRK(1,1,0.001,1,50,"pRKmu1.dat");
}