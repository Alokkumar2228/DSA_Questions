#include<bits/stdc++.h>
using namespace std;

vector<int>dp(1000006 ,-1);
const int MOD = 1000000007;
//coin = {1,2,3} target = 4
// 1 + 1 + 1 + 1
// 1 + 1 + 2    
//1+3

int helper(vector<int>&coin , int target , int sum){

    if(sum==target)return 1;
    if(sum > target)return 0;
    //base case

    if(dp[sum]!=-1)return dp[sum];
    int count = 0;
    
    for(int i=0 ; i<coin.size();i++){
        if(sum>target)continue;
        count = (count + helper(coin , target , sum+coin[i])%MOD)%MOD;
    }

    return dp[sum]=count%MOD;

};

int main(){

    int n,x;
    cin>>n>>x;
    vector<int>coin(n,0);
    for(int i=0 ; i<n ; i++)cin>>coin[i];
    cout<<helper(coin , x , 0);

    return 0;
}