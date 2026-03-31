#include<iostream>
#include<vector>
using namespace std;

vector<int>v = {1,2,3,4,5};
int n =v.size();

int main(){
    
    for(int i=1 ; i<n;i++){
        if(v[i]<v[i-1]){
            for(int j=i ;j>0 ;j--){
                if(v[j]<v[j-1]){
                    swap(v[j], v[j-1]);
                } else{
                    break;
                }
            }
        }
    }

    for(int i=0 ; i<n  ; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}