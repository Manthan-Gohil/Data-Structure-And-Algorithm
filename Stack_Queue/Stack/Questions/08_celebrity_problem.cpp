#include<bits/stdc++.h>
using namespace std;
// TC O(n) SC O(n) 
int getCelebrity(vector<vector<int>> &nums){
    int n = nums.size();
    stack<int> s;

    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size() > 1){
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if(nums[i][j] == 0){ // eliminate j because j could not be celebrity
            s.push(i);
        }else{ // eliminate i
            s.push(j);
        }
    }

    int celeb = s.top();
    for(int i=0;i<n;i++){
        if((i != celeb) && nums[i][celeb] == 0 || nums[celeb][i] == 1){
            return -1;
        }
    }
    return celeb;

}

int main(){
    vector<vector<int>> nums = {{0,1,0},
                                {-1,0,0},
                                {0,1,0}};

    int ans = getCelebrity(nums);
    cout<<"celebrity is = "<<ans<<endl;                            

}