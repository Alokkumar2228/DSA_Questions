#include<bits/stdc++.h>
using namespace std;

vector<int>dp(10000006,-2);

class MinimizeCoin{
    public:

    int getMinimumCoin(vector<int>&coin , int target , int sum ){
        if(sum == target)return 0;
        if(sum>target)return INT_MAX;
        if(dp[sum]!=-2)return dp[sum];
        int result = INT_MAX;
        for(int i=0 ; i<coin.size();i++){
            int sub = getMinimumCoin(coin , target , sum+coin[i]);
            if(sub != INT_MAX){
                result =  min(result , 1+sub);
            }
        }

        return dp[sum] = result;

    }




};




int main(){

    int n,target;
    cin>>n>>target;
    vector<int>coin(n,0);
    for(int i=0 ; i<n ; i++){
        cin>>coin[i];
    }

    MinimizeCoin testMinCoin;
    int res = testMinCoin.getMinimumCoin(coin, target, 0);
    int finalans = (res == INT_MAX ? -1 : res);
    cout << finalans;



    return 0;

}