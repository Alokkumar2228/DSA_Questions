#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr , int idx){
    if(idx == arr.size()) return;
    cout<<arr[idx];
    idx++;
    print(arr,idx);
};

int main(){

    vector<int>arr = {1,2,3,4,5};

    print(arr,0);



    return 0;
}