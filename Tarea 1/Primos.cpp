#include <iostream>
using namespace std;
int contador = 0;
int divisor = 1;
int main() {
    for(int i=10;i<31;i++){
        while(divisor<=i){
            if(i%divisor==0){
                contador+=1;
            }
            divisor+=1;
        }
        if(contador==2){
            cout << i << " ";
        }
        divisor = 1;
        contador = 0;
    }
    
}


