#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
    double am,sd,gm,hm;
    double max = A[0];
    double min = A[0];
    double sum = 0;
    double sum_thing = 0;
    double sumx = 1;
    double har_sum = 0;
    for (int i = 0; i < N; i++){
        sum += A[i];
        sum_thing += pow(A[i],2);
        sumx *= A[i];
        har_sum += 1.00/A[i];
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    am = sum/N;
    sd = sqrt(sum_thing/N - pow(am,2));
    gm = pow(sumx,1.00/N);
    hm = N/har_sum;
    B[0] = am;
    B[1] = sd;
    B[2] = gm;
    B[3] = hm;
    B[4] = max;
    B[5] = min;
}