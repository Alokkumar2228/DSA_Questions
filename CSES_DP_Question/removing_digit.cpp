// Online C compiler to run C program online
#include<bits/stdc++.h>
#include <climits>
using namespace std;

int helper(int n , int res , vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int temp = n;
    while(temp>0){
        int lst = temp%10;
        temp=temp/10;
        if(lst!=0){
            res = min(res , 1+ helper(n-lst , res ,dp));
            dp[n] = res;
        }
    }
    return res;
}

int buttomUp(int num ,vector<int>&dp){
    dp[0] = 0;
    for(int i= 1 ; i<=9 ;i++)dp[i] = 1;
    for (int i = 10; i <= num; i++) {
        int temp = i;
        int result = INT_MAX;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            if (digit != 0) {
                result = min(result, 1 + dp[i - digit]);
            }
            dp[i] = result;
        }
    }
    return dp[num];
}



int main() {
    
    int num ;
    cin>>num;
    int res = INT_MAX;
    vector<int>dp(1000005 , -1);
    cout<<helper(num ,res ,dp)<<endl;
    cout<<buttomUp(num ,dp);


    return 0;
}