#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

double comparation(std::string s1, std::string s2) {
  std::ifstream is1{s1}; // Più rado
  std::ifstream is2{s2}; // Più fitto
  double t1 = 0.;
  double t2 = 0.;
  double x1 = 0.;
  double x2 = 0.;
  double diff = 0.;
  std::vector<double> results;

  while(is1 >> t1) {
    is1 >> x2;
    while (t2 != t1) {
      is2 >> t2;
      is2 >> x2; //std::cout << t2 << ' ' << x2 << '\n';
    }
    diff += std::pow((x2 - x1), 2);
    //results.push_back(diff);
  }
  is1.close();
  is2.close();
  //double max = *std::max_element(results.begin(), results.end());
  return std::sqrt(diff);
}

int main() {
  std::string s1 = "Data/VDP1.dat";
  std::string s2 = "Data/VDP1p.dat";
  std::cout << "Norm = " << comparation(s1, s2) << '\n';
}
