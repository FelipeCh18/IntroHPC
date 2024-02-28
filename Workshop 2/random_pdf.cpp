#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 
#include <fstream>

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

  for(int h = 0; h<50; h++){
    pdf.push_back(0);
  }

  double gap = (xmax-xmin)/nbins;
  for(int k=0;k<nbins;k++){
    for(int i=0;i<muestra.size();i++){
      if(xmin+(k*gap)<=muestra[i] && muestra[i]<=xmin+((k+1)*gap)){
        pdf[k]+=1;
      }
    }
  }

  double mayor = 0;
  for(int l=0;l<pdf.size();l++){
    if(pdf[l]>mayor){
      mayor=pdf[l];
    }
  }

  std::ofstream txt_dist("dist.txt");
  double prob = 0;
  for(int j=0;j<pdf.size();j++){
    txt_dist << xmin+((2*j+1)*(gap/2)) << "\t" << pdf[j]/mayor << "\n";
    prob+=pdf[j]/muestra.size();
  }
  std::cout << prob;
  txt_dist.close();
  
  // TODO: compute and print the pdf

}
