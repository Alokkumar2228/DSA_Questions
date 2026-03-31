#include<bits/stdc++.h>
using namespace std;

vector<int> calDig(int n ){
    vector<int>ans;
    if(n<10 && n!= 0){
        ans.push_back(n);
        return ans;
    }
    while(n>0){
        int temp = n%10;
        if(temp != 0)ans.push_back(temp);
        n /= 10;
    }

    return ans;
}
vector<int>dp;
int helper(int n){
    if(n == 0)return 0;
    if(n < 10)return 1;

    vector<int>d = calDig(n);
    int res = INT_MAX;
    if(dp[n] != -1)return dp[n];
    for(int i=0 ; i<d.size()  ; i++){
        res = min(res , helper(n-d[i]));
    }

    return dp[n] = 1 + res;

};
//button up approach 

int bua(int num){
    dp[0] = 0;
    for(int i=1 ; i<=9 ; i++){
        dp[i] = 1;
    }
    for(int n=10 ; n<= num ; n++){
        vector<int>d = calDig(n);
        int res = INT_MAX;
        for(int i=0 ; i<d.size()  ; i++){
        res = min(res , dp[n-d[i]]);
     }
     dp[n] = 1 + res;   
    }

    return dp[num];
}

int main(){

    int n; cin >> n;
    dp.clear();
    dp.resize(1e6+1 , -1);
   cout<<bua(n);


    return 0;
}