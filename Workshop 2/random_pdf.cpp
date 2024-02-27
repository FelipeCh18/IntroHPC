#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 
#include <fstream>

double normal_dist(double num, double mu, double sigma);
void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  std::vector<double> muestra, pdf;

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    if(r>=xmin && r<=xmax){
      muestra.push_back(r);
    }
    // TODO: fill here the counting histogram stuff
  }

  std::sort(muestra.begin(), muestra.end());
  std::ofstream txt_dist("dist.txt");
  for(int h=0; h<muestra.size();h++){
    pdf.push_back(normal_dist(muestra[h], mu, sigma));
    txt_dist << muestra[h] << "\t" << pdf[h] << "\t" << "\n";
  }
  txt_dist.close();
  
  // TODO: compute and print the pdf

}

double normal_dist(double num, double mu, double sigma){
  double nd = (1/(sigma*sqrt(2*M_PI)))*exp(-0.5*pow((num-mu)/sigma, 2));
  return nd;
}
