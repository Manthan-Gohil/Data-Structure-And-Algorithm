#include<bits/stdc++.h>
using namespace std;

// brute force approach
int maxProduct(int n){
    vector<int> digits;

    while(n > 0){
        digits.push_back(n%10);
        n /= 10;
    }

    int ans = 0;

    for(int i=0;i<digits.size();i++){
        for(int j=i+1;j<digits.size();j++){
            ans = max(ans, digits[i]*digits[j]);
        }
    }
    return ans;
}

int maxProduct2(int n){
    int largest = -1;
    int secondLargest = -1;

    while(n > 0){
        int digit = n % 10;

        if(digit > largest){
            secondLargest = largest;
            largest = digit;
        }
        else if(digit > secondLargest){
            secondLargest = digit;
        }
        n /= 10;
    }
    return largest*secondLargest;
}

int main(){
    int n = 124;
    cout<<"max product of two digits = "<<maxProduct(n)<<endl;
    cout<<"max product of two digits (method 2) = "<<maxProduct2(n)<<endl;

}