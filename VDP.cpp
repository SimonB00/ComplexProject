#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>

void VDP1(double x0, double y0, double dt, double mu, double T, std::string s) {        // x'' + mu(1-x^2)x' + x = 0, y = x'
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

void VDP2(double x0, double y0, double dt, double mu, double T, std::string s) {        // Andamento temporale
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

/*
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
*/

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

void VDPF1(double x0, double y0, double dt, double mu, double T, double w, double A, std::string s) {        
    double t = 0;
    double steps = T/dt;
    double x = x0;
    double y = y0;
    double z;
    std::ofstream outfile;
    outfile.open(s);

    for(int i = 0; i != steps; ++i) {
        z = x + y*dt;
        y = (mu*(1-pow(x,2))*y - x + A*sin(w*t))*dt + y;
        x = z;

        outfile << t << '\t' << x << '\n';
        t = t + dt;
    }
    outfile.close();
}

double comparation(std::string s1, std::string s2, int N, int size1, int size2) {
    std::ifstream is1{s1};      // Più rado
    std::ifstream is2{s2};      // Più fitto
    double t1 = 0.;
    double t2 = 0.;
    double x1 = 0.;
    double x2 = 0.;
    double diff = 0.;
    std::vector<double> results;

    for(int i = 0; i != size1; ++i) {
        is1 >> t1;
        for(int j = 0; t2 != t1; ++j) {
            is2 >> t2;
            if(t2 == t1) { 
                is1 >> x1;
                is2 >> x2;
                diff = std::abs(x1-x2);
                results.push_back(diff);
            }
            else {
                is2 >> x2;
            }
        }
    }
    double max = *std::max_element(results.begin(),results.end());
    return max;
}

int main() {
    VDP1(1,1,0.1,1,20,"VDP1PP.dat");          // Traiettoria caratteristica dell'oscillatore
    /*VDP1(1,1,0.01,0,20,"VDP0.dat");          // Traiettorie per valori di mu: mu = 0
    VDP1(1,1,0.01,0.25,20,"VDP025.dat");       // mu = 0.25 
    VDP1(1,1,0.01,0.5,20,"VDP05.dat");        // mu = 0.5
    VDP1(1,1,0.01,0.75,20,"VDP075.dat");       // mu = 0.75
    VDP1(1,1,0.01,0.9,20,"VDP09.dat");        // mu = 0.9
    VDP1(1,1,0.01,0.95,20,"VDP095.dat");       // mu = 0.95
    //VDP1(1,1,0.01,1,20,"VDP1.dat");          // mu = 1 (Utilizzo quello della prima riga)
    VDP1(1,1,0.01,2,20,"VDP2.dat");          // mu = 2
    VDP1(1,1,0.01,3,20,"VDP3.dat");          // mu = 3
    VDP1(1,1,0.01,4,20,"VDP4.dat");          // mu = 4
    VDP1(1,1,0.01,5,20,"VDP5.dat");          // mu = 5
    VDP1(1,1,0.01,6,20,"VDP6.dat");          // mu = 6
    VDP1(1,1,0.01,7,20,"VDP7.dat");          // mu = 7
    VDP1(1,1,0.01,8,20,"VDP8.dat");          // mu = 8
    VDP2(1,1,0.01,2,35,"AndTemp.dat");       // mu = 2
    VDP4(1.5,1,0.01,1.5,15,"SingolaPar.dat");*/  // mu = 1.5
    VDP1(1,1,0.01,-0.5,20,"VDP-05.dat");
    VDPF1(1,1,0.01,8.5,200,0.6,1.2,"AndVDPF.dat");

    std::string name = "Anim";
    int N_ = 350;
    double mu = 1;
    int T = 10;
    double x = 0;
    double y = 0;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis(-2.,2.);

    VDP2(1,1,0.01,1,15,"Err1.dat");
    VDP2(1,1,0.0001,1,15,"Err2.dat");
    std::cout << "Max = " << comparation("Err1.dat","Err2.dat",100,1500,150000) << '\n';

    /*
    for(int i = 0; i != N_; ++i) {
        std::string new_name = name + std::to_string(i) + ".dat";
        x = dis(gen);
        y = dis(gen);
        VDP1(x,y,0.01,mu,T,new_name);
    }
    */
}