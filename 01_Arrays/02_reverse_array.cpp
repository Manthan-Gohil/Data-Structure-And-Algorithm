#include<bits/stdc++.h>
using namespace std;
// two pointer approach
int main(){
    int arr[] = {4,2,7,6,1,9,2};
    int size = sizeof(arr)/sizeof(int);
    int i = 0;
    int j = size - 1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}