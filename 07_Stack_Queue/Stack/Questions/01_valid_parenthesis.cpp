#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string &str){
    stack<char> s;

    for(int i=0;i<str.size();i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){ // opening
            s.push(str[i]);
        }
        else{ // closing
            if(s.size() == 0){
                return false;
            }

            if((s.top() == '{' && str[i] == '}') ||
                (s.top() == '[' && str[i] == ']') ||
                (s.top() == '(' && str[i] == ')')){
                    s.pop();
                }
            else{
                return false;
            }

        }
    }
    return s.size() == 0;
}

int main(){
    string str = "{([]])}";
    bool ans = validParenthesis(str);
    cout<<"is valid parenthesis = "<<ans<<endl;
}