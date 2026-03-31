#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

// index shifting -> this we will use for button up approach
// int solve(string &s1 , string &s2 , int idx1 , int idx2){
    
//     if(idx1 == 0 || idx2 == 0)return idx1 + idx2;
    
//     if(s1[idx1-1] == s2[idx2-1]){
//         return dp[idx1][idx2] = 1 + solve(s1 , s2 , idx1-1 , idx2-1);
//     }else{
//         //take  first stirng
//         // int take_first = 1 + solve(s1 , s2 , idx1-1 , idx2);
//         // //take_second_string
//         // int take_second = 1+ solve(s1 , s2 , idx1 , idx2-1);

//         return dp[idx1][idx2] = 1 + min( solve(s1 , s2 , idx1-1 , idx2) , solve(s1 , s2 , idx1 , idx2-1));

//     }


// }


int main(){

    string str1;
    getline(cin , str1);
    string str2;
    getline(cin , str2);

    int n = str1.length();
    int m = str2.length();
    dp.resize(n+1 , vector<int>(m+1 ));

        //bottom up

        for(int i=0 ; i<=n ; i++){
            for(int j=0 ; j<=m ; j++){
                if( i == 0 || j==0)dp[i][j] = i+j;
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        string ans = "";
        int i = n;
        int j = m;

        while(i>0 && j>0){

           if(str1[i-1] == str2[j-1]) {
            ans.push_back(str1[i-1]);
            i--;
            j--;     
           }else{
                if(dp[i][j-1] < dp[i-1][j]){
                    ans.push_back(str2[j-1]);
                    j--;
                }else{
                    ans.push_back(str1[i-1]);
                    i--;
                }
           }
           

        }

        while(i==0 && j>0){
            ans.push_back(str2[j-1]);
            j--;
        }

        while(j==0 && i>0){
            ans.push_back(str1[i-1]);
            i--;
        }

        reverse(ans.begin() ,ans.end());
        cout<<ans<<endl;




























    // int n = str1.length();
    // int m = str2.length();
    
    // dp.resize(n+1 , vector<int>(m+1 , -1));
    // // cout<<solve(str1 , str2 , n , m);

    // //bottom UP

    // string s1 = str1;
    // string s2 = str2;

    // //buttom-up approach
    // for(int i= 0 ; i<=n ; i++){
    //     for(int j=0 ; j<=m ; j++){

    //         if(i==0 || j==0){
    //             dp[i][j] = i+j;
    //         }else if(s1[i-1] == s2[j-1]){
    //              dp[i][j] = 1 + dp[i-1][j-1] ; 
    //         }else{
    //             dp[i][j] = 1 + min( dp[i-1][j] ,  dp[i][j-1]);

    //         }
            

    //     }
    // }    
    // //dp[i][j] ->signify the scs of s1 of length1 and s2 of length j

    // cout<< dp[n][m]<<endl;

    // //to print the string

    // string ans = "";

    // cout<<"ans " <<ans<<endl;

    // int i = n;
    // int j = m;

    // while(i>0 && j>0){
    //     cout<<"i " << i << "j " <<j<<endl;
    //     if(dp[i-1][j]<dp[i][j-1]){
    //         ans.push_back(s1[i-1]);
    //         i--;
    //     }else if(dp[i][j-1] < dp[i-1][j] ){
    //         ans.push_back(s2[j-1]);
    //         j--;
    //     }else{
    //         ans.push_back(s1[i-1]);
    //         i--;
    //         j--;
    //     }
    // }

    // while(i==0 && j>0){
    //     ans.push_back(s2[j-1]);
    //     j--;
    // }

    // while(j==0 && i>0){
    //     ans.push_back(s1[i-1]);
    //     j--;
    // }

    // reverse(ans.begin() , ans.end());

    // cout<<ans<<endl;







    return 0;
}