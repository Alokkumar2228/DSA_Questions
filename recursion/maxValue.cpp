#include<bits/stdc++.h>
using namespace std;
// 
// void print(vector<int> &arr , int idx){
    // if(idx == arr.size()) return;
    // cout<<arr[idx];
    // idx++;
    // print(arr,idx);
// };

int printMax(int arr[] , int idx ,int len){
    // if(idx == len){
        // cout<<maxi;
        // return;
    // };
    // if(maxi<arr[idx]) maxi = arr[idx];
    // printMax(arr,maxi,idx+1,len);

    // MEthod2
    if(idx == len) return INT_MIN;
    return max(arr[idx] , printMax(arr,idx+1,len));
};



int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<printMax(arr,0 ,n);

    // print(arr,0);



    return 0;
}