#include<bits/stdc++.h>
using namespace std;

vector<int>dp;


//use this method

int helper(vector<int>&coin , int target){

    if(target == 0)return 0;
    if(target < 0 )return INT_MAX;
    if(dp[target]!=-1])return dp[target];
    int res = INT_MAX;
    for(int i=0 ; i<coin.size() ; i++){

        // mini coin = 1 + min(f-coint[i])
        int sub = helper(coin , target-coin[i]);
        if(sub!=INT_MAX){
            res = min(res , 1 + sub);
        }
    }

    return dp[target] = res;



}




int main(){

    int n,target;
    cin>>n>>target;
    vector<int>coin(n,0);
    for(int i=0 ; i<n ; i++){
        cin>>coin[i];
    }

    // MinimizeCoin testMinCoin;
    // int res = testMinCoin.getMinimumCoin(coin, target, 0);