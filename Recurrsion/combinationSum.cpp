#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>v,int arr[],int target,int n,int idx){

    if(target==0){
        for(int el:v){
            cout<<el<<"";
        }
        cout<<endl;
        return;
    }

    if(target<0)return;



    for(int i=idx;i<n;i++){
        v.push_back(arr[i]);
        solve(v,arr,target-arr[i],n,i);
        v.pop_back();
    }
}

int main(){
    int arr[]={2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    solve(v,arr,8,n,0);


    return 0;
}