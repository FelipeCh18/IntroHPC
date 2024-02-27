#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

float suma1(float num);
float suma2(float num);

int main(int argc, char **argv){
    ofstream txt_error("error_numerico.txt");
    cout.precision(7);
    cout.setf(ios::scientific);
    int N = 10000000; //atoi(argv[1]);
    float s1 = 0.0;
    float s2 = 0.0;
    float dif = 0.0;
    for(int i=1;i<=N;i++){
        s1 = suma1(i);
        s2 = suma2(i);
        dif = abs(1-(s1/s2));
        txt_error << i << "\t"
        << s1 << "\t"
        << s2 << "\t"
        << dif << "\n";
    }
    return 0;
}

float suma1(float num){
    float sum = 0.0;
    for(float i=1.0; i<=num; i++){
        sum+=(1/i);
    }
    return sum;
}

float suma2(float num){
    float sum = 0.0;
    for(float i=num; i>=1; i--){
        sum+=(1/i);
    }
    return sum;
}