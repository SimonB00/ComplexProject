#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include "Norm.hpp"

void VDP1(double x0, double y0, double dt, double mu, double T, std::string s) {        // x'' - mu(1-x^2)x' + x = 0, y = x'
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = (mu*(1-pow(x,2))*y - x)*dt + y;
        x = z;

        outfile << x << '\t' << y << '\n';
    }
    outfile.close();
}

void AndTempX(double x0, double y0, double dt, double mu, double T, std::string s) {        // Andamento temporale x
    double t = 0;
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = (mu*(1-pow(x,2))*y - x)*dt + y;
        x = z;

        outfile << t << '\t' << x << '\n';
        t = t + dt;
    }
    outfile.close();
}

void AndTempP(double x0, double y0, double dt, double mu, double T, std::string s) {        // Andamento temporale p
    double t = 0;
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = (mu*(1-pow(x,2))*y - x)*dt + y;
        x = z;

        outfile << t << '\t' << y << '\n';
        t = t + dt;
    }
    outfile.close();
}


void VDP3(double x0, double y0, double dt, double mu, double T, std::string s) {        // Animazione        
    double t = 0;
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = (mu*(1-pow(x,2))*y - x)*dt + y;
        x = z;

        outfile << x << '\t' << t << '\n';
        t = t + dt;
    }
    outfile.close();
}


void VDP4(double x0, double y0, double dt, double mu, double T, std::string s) {        
    double t = 0;
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = (mu*(1-pow(x,2))*y - x)*dt + y;
        x = z;

        outfile << x << '\t' << y << "\n\n\n";
        t = t + dt;
    }
    outfile.close();
}

int main() {
    //VDP1(1,1,0.1,1,40,"Mu1-1.dat");
    //VDP1(1,1,0.01,1,40,"Mu1-01.dat");
    //VDP1(1,1,0.001,1,40,"Mu1-001.dat");
    //VDP1(1,1,0.0001,1,40,"Mu1-0001.dat");
    //VDP1(1,1,0.001,1.5,15,"VDP15.dat");
    
    //VDP1(1,1,0.01,10,40,"Test10.dat"); //Con 0.1 non funziona nemmeno
    //AndTempX(1,1,0.01,10,40,"ATMu10-01.dat");
    //AndTempX(1,1,0.001,10,40,"ATMu10-001.dat");
    //AndTempX(1,1,0.0001,10,40,"ATMu10-0001.dat");
    //AndTempX(1,1,0.00005,10,40,"ATMu10-00005.dat"); //0.00001 è troppo poco
    //AndTempX(1,1,0.000001,10,40,"ATMu10-000001.dat");
    //AndTempP(1,1,0.01,10,40,"ATPMu10-01.dat");
    //AndTempP(1,1,0.001,10,40,"ATPMu10-001.dat");
    //AndTempP(1,1,0.0001,10,40,"ATPMu10-0001.dat");
    //AndTempP(1,1,0.00005,10,40,"ATPMu10-00005.dat"); //0.00001 è troppo poco
    //AndTempX(1,1,0.000001,10,40,"ATMu10-000001.dat");
    
    AndTempX(2,1,0.0001,1,20,"ConfrMLXMu1.dat");
    /*
    std::string name = "Anim";
    int N_ = 350;
    double mu = 1;
    int T = 10;
    double x = 0;
    double y = 0;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis(-2.,2.);*/
    /*
    AndTempX(1,1,0.01,1,15,"Err1.dat");
    AndTempX(1,1,0.0001,1,15,"Err2.dat");
    std::cout << "Max1 = " << comparation("Err1.dat","Err2.dat") << '\n';
    AndTempX(1,1,0.001,1,15,"Err3.dat");
    std::cout << "Max2 = " << comparation("Err3.dat","Err2.dat") << '\n';
    AndTempX(1,1,0.1,1,15,"Err4.dat");
    std::cout << "Max3 = " << comparation("Err4.dat","Err2.dat") << '\n';
    AndTempX(1,1,1,1,15,"Err5.dat");
    std::cout << "Max4 = " << comparation("Err5.dat","Err2.dat") << '\n';
    */
    //AndTempX(1,1,0.1,1,15,"ATMu1-1.dat");
    //AndTempP(1,1,0.01,1,15,"ATPMu1-01.dat");
    //AndTempP(1,1,0.0001,1,15,"ATPMu1-0001.dat");
    //AndTempP(1,1,0.001,1,15,"ATPMu1-001.dat");
    //AndTempP(1,1,0.1,1,15,"ATPMu1-1.dat");

    /*
    for(int i = 0; i != N_; ++i) {
        std::string new_name = name + std::to_string(i) + ".dat";
        x = dis(gen);
        y = dis(gen);
        VDP1(x,y,0.01,mu,T,new_name);
    }
    */

    std::cout << "Max1 = " << comparation("Mu10-01.dat","Mu10-00005.dat") << '\n';
    //std::cout << "Max2 = " << comparation("Mu10-001.dat","Mu10-00005.dat") << '\n';
    //std::cout << "Max3 = " << comparation("Mu10-0001.dat","Mu10-00005.dat") << '\n';
}