// Q1 WAF to calculate sum & product of all numbers in an array
// Q2 WAF to swap max & min number of an array
// Q3 WAF to print all the unique values in an array
// q4 WAF to print intersection of 2 array
// Q5 WAF to merge two sorted array

#include<bits/stdc++.h>
using namespace std;

void Q1(int arr[], int size){
    int sum = 0;
    int pro = 1;
    for(int i=0;i<size;i++){
        sum = sum + arr[i];
        pro = pro * arr[i];
    }
    cout<<"Sum = "<<sum<<" "<<"Product = "<<pro<<endl;
}

void Q2(int arr[], int size){
    // let both smallidx and largeidx at index 0
    int smallIdx = 0;
    int largeIdx = 0;

    for(int i=1;i<size;i++){
        if(arr[i]<arr[smallIdx]){
            smallIdx = arr[i];
        }
        if(arr[i]>arr[largeIdx]){
            largeIdx = arr[i];
        }
    }
    swap(arr[smallIdx], arr[largeIdx]);
    cout<<"largenum = "<<arr[smallIdx]<<" smallnum = "<<arr[largeIdx]<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void Q3(int arr[], int size){
    unordered_map<int,int> freq;
    for(int i=0;i<size;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        if(freq[arr[i]] == 1){
            cout<<arr[i]<<" ";
        }
    }
}


void Q4(int arr1[], int arr2[], int size1, int size2){
    unordered_set<int> s;

    for(int i=0;i<size1;i++){
        s.insert(arr1[i]);
    }
    for(int j=0;j<size2;j++){
        if(s.find(arr2[j]) != s.end()){
            cout<<arr2[j]<<" ";
        }
    }
}

void Q5(int arr1[], int arr2[], int size1, int size2){
    int i=0, j=0;
    while(i<size1 && j<size2){

        if(arr1[i]<arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
        }else{
            cout<<arr2[j]<<" ";
            j++;
        }
    }

    // remaining element of arr1
    while(i<size1){
        cout<<arr1[i]<<" ";
        i++;
    }
    //remaining element of arr2
    while(j<size2){
        cout<<arr2[j]<<" ";
        j++;
    }
}

vector<int> Q6(vector<int> &nums1, vector<int> nums2){
    int size1 = nums1.size();
    int size2 = nums2.size();

    vector<int> result;
    // making two pointer
    int i = 0;
    int j = 0;
    while(i< size1 && j < size2){
        if(nums1[i]<nums2[j]){
            result.push_back(nums1[i]);
            i++;
        }else{
            result.push_back(nums2[j]);
            j++;
        }
    }
    // put remaining elements to this result array
    while(i < size1){
        result.push_back(nums1[i]);
        i++;
    }
    while(j < size2){
        result.push_back(nums2[j]);
        j++;
    }
    return result;
}

int main(){
    int arr[5] = {1,2,3,3,5};
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {3,5};
    vector<int> nums1 = {2,4,6,8};
    vector<int> nums2 = {1,3,5,7};
    // Q1(arr, 5);
    // Q2(arr, 5);
    // Q3(arr, 5);
    // Q4(arr1, arr2, 5,2);
    // Q5(arr1,arr2,5,2);

    vector<int> result = Q6(nums1,nums2);
    for(int i : result){
        cout<<i<<" ";
    }
    
}