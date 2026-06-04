#include<bits/stdc++.h>
using namespace std;

void largest_smallest_element_array(int arr[], int n){
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    int smallIdx = 0;
    int largeIdx = 0;
    for(int i=0;i<n;i++){
        if(maxNum < arr[i]){
            maxNum = arr[i];
            largeIdx = i;
        }
        // maxNum = max(maxNum, arr[i])
        if(minNum > arr[i]){
            minNum = arr[i];
            smallIdx = i;
        }
        // minNum = min(minNum, arr[i])
    }
    cout<<"Max num = "<<maxNum<<" idx = "<<largeIdx<<endl<<"Min num = "<<minNum<<" idx = "<<smallIdx<<endl;
}

int main(){

    int arr[] = {5,15,22,1,-15,24};
    largest_smallest_element_array(arr,6);

}