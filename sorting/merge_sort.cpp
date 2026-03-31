#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v , int st , int mid , int end){

    vector<int>temp;
    int left = st;
    int right =  mid+1;

    while(left<=mid && right<=end){

        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }else{
            temp.push_back(v[right]);
            right++;
        }

    }

    while(left <= mid){
        temp.push_back(v[left]);
        left++;
    }

    while(right <= end){
        temp.push_back(v[right]);
        right++;
    }

    for(int i=st ; i<=end ; i++){
        v[i] = temp[i-st];
    }

    for(int i : v)cout<<i<<"   ";
    cout<<endl;

}

void mergeSort( vector<int>&v , int st , int end ){

    if(st >= end) return;

    int mid = ( st + end ) / 2 ;
    mergeSort( v , st , mid );
    mergeSort(v , mid+1 , end);
    merge(v, st , mid , end);

}

int main(){
    
    string input;
    getline(cin , input);
    int n;
    stringstream ss(input);
    vector<int>temp;
    while(ss >> n) temp.push_back(n);

    mergeSort(temp , 0 , temp.size() - 1);

    for(int i : temp)cout<<i<<"   ";






    return 0;
}