#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int>vec ={5, 2, 9, 1, 5, 6};


int main(){


    for(int i=0;i<vec.size()-1;i++){
        int min_idx = -1;
        int min_val = INT_MAX;
        for(int j=i ; j<vec.size();j++){
            if(vec[j]<min_val){
                min_val=vec[j];
                min_idx =j;
            }      
        }
         swap(vec[i],vec[min_idx]);
    }

    for(int ele : vec){
        cout<<ele<<" ";
    }

    return 0;
}