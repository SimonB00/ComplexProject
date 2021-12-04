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

is2 >> t2;
is2 >> x2;

  while(is1 >> t1) {
    is1 >> x1;
    while (t2 != t1) {
      is2 >> t2;
      is2 >> x2; //std::cout << t2 << ' ' << x2 << '\n';
    }
    //diff += std::pow((x2 - x1), 2);
    diff = std::abs(x2-x1);
    results.push_back(diff);
  }
  is1.close();
  is2.close();
  double max = *std::max_element(results.begin(), results.end());
  //return std::sqrt(diff);
  return max;
}
