#include<bits/stdc++.h>
using namespace std;

int dp[1005];    
int solve(vector<pair<int,int>>&v , int cap){

    if(cap == 0) return 0;
    if(dp[cap]!=-1)return dp[cap];

    int res = 0;
    for(int i=0 ; i<v.size() ; i++){
        if(cap >= v[i].second)res = max(res , v[i].first+solve(v , cap-v[i].second));
    }

    return dp[cap] = res;

}

int main(){
//     Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
// Output: 110
// Explanation: The optimal choice is to pick the 2nd element and the 4th element
    vector<int> wt = {1, 3, 4 , 5};
    vector<int> val = {10, 40, 50, 70};
    int capacity = 8;
    int n = val.size();
    vector<pair<int,int>>v(n , {0,0});
    for(int i=0 ; i<n ; i++){
        v[i] = {val[i] , wt[i]};
    }
    memset(dp , -1 , sizeof(dp));
    int ans = solve(v , capacity);
    cout<< ans;
    return 0;
}