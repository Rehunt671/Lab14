#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double x[],int n,double y[]){
  const double e = 2.71828;
  double sum = 0,sumsq = 0,sumlog = 0 , sumhar = 0 , max = x[0] , min = x[0];
  double arhM,sd,gm,hm;
  for(int i = 0 ; i < n ; i++){
    if(x[i] > max ) max = x[i];
    if(x[i] < min ) min = x[i];
    sum += x[i]; 
    sumsq += pow(x[i],2);
    sumlog += log(x[i]);
    sumhar += 1/x[i];
  }
  y[0] = arhM = sum/n;
  y[1] = sd = sqrt(sumsq/n-pow(arhM,2));
  y[2] = gm = pow(e,sumlog/n);
  y[3] = hm = n/sumhar;
  y[4] = max;
  y[5] = min;
}