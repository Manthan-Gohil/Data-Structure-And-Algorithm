// calculate power of number
#include<bits/stdc++.h>
using namespace std;

double pow(double x, int n){
    long binForm = n;
    double ans = 1;

    // if -ve power
    if(n < 0){
        x = 1/x;
        binForm = -binForm;
    }

    while(binForm > 0){
        if(binForm % 2 == 1){
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }
    return ans;
}

int main(){

    double result = pow(3,5);
    cout<<result;

}