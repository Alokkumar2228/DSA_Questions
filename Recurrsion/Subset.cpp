#include<bits/stdc++.h>
using namespace std;

void subArray(vector<int>ans,int arr[],int n,int idx){
    if(idx==n){
        for(int el:ans){
            cout<<el<<" ";
        }
        cout<<endl;
        return;

    }
    subArray(ans,arr,n,idx+1);
    ans.push_back(arr[idx]);
    subArray(ans,arr,n,idx+1);


}


int main(){

    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>vec;
    subArray(vec,arr,n,0);
   

    return 0;
}

