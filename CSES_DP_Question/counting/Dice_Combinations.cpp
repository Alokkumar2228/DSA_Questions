#include<bits/stdc++.h>
using namespace std;


const int MOD = 1000000007;
vector<int>dp(1000006 , -1);
int helper(vector<int>&dice , int tar , int sum ){
    if(sum == tar)return 1;
    if(sum>tar)return 0;
    int count = 0;
    if(dp[sum]!=-1)return dp[sum];
    for(int i=0 ; i<dice.size();i++){
        if(sum>tar)continue;
        count = (count + (helper(dice,tar,sum+dice[i])))%MOD;
    }
    return dp[sum]=count % MOD;
}

int main(){
    vector<int>dice(6,0);
    for(int i=0 ; i<6 ; i++){
        dice[i] = i+1;
    }
    int target;
    cin>>target;
    cout<<helper(dice,target,0);

}