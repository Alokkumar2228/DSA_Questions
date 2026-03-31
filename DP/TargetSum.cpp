#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp;
    int offset;
    int helper(vector<int>&nums , int target , int idx , int exp){

        if(exp == target && idx == nums.size())return 1;
        if(idx>=nums.size())return 0;
        if(dp[idx][exp + offset]!=-1)return dp[idx][exp+offset];

        int take_pos = helper(nums , target , idx+1 , exp+nums[idx]);
        int take_neg = helper(nums , target , idx+1 , exp-nums[idx]);

        return dp[idx][exp + offset] = take_pos + take_neg;

    }
    // here totalSum can be from [-totalSum , +totalSum]
    // so for eliminating the negatie idx we use offset
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int n:nums)totalSum += n;
        offset = totalSum ;
        dp.resize(nums.size() , vector<int>(2*totalSum + 1 , -1));
        return helper(nums , target , 0 , 0);

        
    }
};

int main(){

    Solution s;
    vector<int>nums = {1,1,1,1,1};
    int target = 3 ;
    int ans = s.findTargetSumWays(nums ,target);
    cout<<ans;


}