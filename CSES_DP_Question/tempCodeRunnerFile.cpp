#include<bits/stdc++.h>
using namespace std;

vector<int>dp(1000006 , -1);
const MOD = 100000007
int helper(vector<int>&dice , int tar , int sum ){
    if(sum == tar)return 1;
    if(sum>tar)return 0;
    long long count = 0;
    if(dp[sum]!=-1)return dp[sum]%MOD;
    for(int i=0 ; i<dice.size();i++){
        if(sum>tar)continue;
        count +=(( helper(dice,tar,sum+dice[i]))%MOD);
    }
    return dp[sum]=count%MOD;
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