#include<bits/stdc++.h>
using namespace std;

// brute force approach
int container_max_water(vector<int> &height){
    int n = height.size();
    int maxWater = 0;
    // left boundry
    for(int  i=0;i<n;i++){
        // right boundry
        for(int j=i+1;j<n;j++){
            int width = j-i;
            int length = min(height[i],height[j]);
            int area = length*width;
            maxWater = max(maxWater,area);
        }
    }
    return maxWater;
}

// two pointer approach

int container_max_water2(vector<int> &height){
    int n = height.size();
    int lp = 0;
    int rp = n-1;
    int maxWater = 0;
    while(lp<rp){
        int w = rp-lp;
        int ht = min(height[lp], height[rp]);
        int area = w*ht;
        maxWater = max(maxWater, area);

        if(height[lp]<height[rp]){
            lp++;
        }else{
            rp--;
        }
    }
    return maxWater;
}

int main(){

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<"Brute "<<container_max_water(height)<<endl;
    cout<<"Two pointer approach "<<container_max_water2(height)<<endl;

}