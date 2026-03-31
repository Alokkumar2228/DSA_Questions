#include<bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

void solve(vector<int>&arr , int target , int sum , int idx){

    if(idx>=arr.size()){
        if(abs(target-sum) < abs(target-ans) )ans = sum;
        return;
    } ;
    if(target == sum){
        ans = target;
        return;
    }


    if(abs(target-sum) < abs(target-ans) )ans = sum;
    if(abs(target-sum) == abs(target-ans))ans = min(sum ,ans);

    //take_first
    solve(arr , target , sum+2*arr[idx] , idx+1);
    solve(arr , target , sum+arr[idx] , idx+1);
    solve(arr , target , sum , idx+1);

}

int main(){
    vector<int>arr1;
    vector<int>arr2;
    string s1;
    getline(cin , s1);
    int n;
    stringstream ss(s1);
    while(ss >> n){
        arr1.push_back(n);
    }

    string s2;
    getline(cin , s2);
    int m;
    stringstream pp(s2);
    while(pp >> m){
        arr2.push_back(m);
    }

    int target;
    cin>>target;

    // BreadCost = [5,7]
    // FillingCost = [2,3]
    // Target = 10
    for(int i=0 ; i<arr1.size() ; i++){
        solve(arr2 , target , arr1[i] , 0);
    }

    cout<<ans<<endl;
    
    //5 7
    //2 3
    //10


}