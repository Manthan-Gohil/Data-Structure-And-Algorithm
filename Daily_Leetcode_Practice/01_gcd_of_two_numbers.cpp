// leetcode no - 3658
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sumOdd = 0;
    int sumEven = 0;

    int countOdd = 0;
    int countEven = 0;
    int i=1;
    while(countOdd <= n || countEven <= n){
        if(i%2 == 0){
            sumEven += i;
            i++;
            countEven++;
        }else{
            sumOdd += i;
            i++;
            countOdd++;
        }
        
    }
    cout<<"sumodd = "<<sumOdd<<endl;
    cout<<"sumeven = "<<sumEven<<endl;
}