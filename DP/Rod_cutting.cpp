#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    
    vector<int>dp;
    int solve(vector<int>&price , int idx . int len){
        
        if(len == 0)return 0;
        if(dp[len]!= -1)return dp[len];
        
        // int ans = INT_MIN;
        // for(int i=0 ; i<price.size() ; i++){
        //     if(len >= (i+1))ans = max(ans , price[i]+solve(price , len-(i+1)));
        // }
        // return dp[len] = ans;
        
        //or use method take or not take
        int n_take = solve(price , idx-1 , len );
        int take = INT_MIN;
        if(len>=(idx+1))take = price[idx] + solve(price , idx , len - price[idx]);

        return  max(take , n_take);
        
    }
    
    
    int cutRod(vector<int> &price) {
        // code here
        dp.assign(price.size()+5 , -1);
        int len = price.size();
        return solve(price , len);
        
    }
};

int main(){


    vector<int>height = {1, 5, 8, 9, 10, 17, 17, 20};
    int len = height.size();




    Solution ob;
    int ans = ob.cutRod(height);
    cout<< ans;

    returna 0;
}

//BUTTON UP

// for tabulation do right shift in recurrsion and then write buttom up

class Solution {
  public:
    
     vector<vector<int>>dp;
    int solve(vector<int>&price , int idx , int len){
        
        if(idx == 0)return 0;
        if(dp[idx][len]!= -1)return dp[idx][len];
        
        int n_take = solve(price , idx-1 , len );
        int take = INT_MIN;
        if(len>=(idx))take = price[idx-1] + solve(price , idx , len - (idx));

        return dp[idx][len] = max(take , n_take);
        
    }
    
    
    int cutRod(vector<int> &price) {
        // code here
        int len = price.size();
        dp.assign(len+1 , vector<int>(len+1 , 0));
        //dp[i][j] -> maximum price till i indexa of j length
        
        for(int l = 0 ; l <= len ; l++){
            dp[0][l] = 0;
        }
        
        for(int idx = 1 ; idx<= len ; idx++){
            for(int le = 1 ; le<=len ; le++ ){
                
                int n_take = dp[idx-1][le];
                int take = INT_MIN;
                if(le>=(idx))take = price[idx-1] + dp[idx][le - idx];
        
                dp[idx][le] = max(take , n_take);
                
            }
        }
        
        return dp[len][len];
        
    }
};