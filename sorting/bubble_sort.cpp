#include<iostream>
#include<vector>
using namespace std;

vector<int> arr = { 5, 1, 4, 2, 8 };
int n = arr.size();

bool flag;

int main() {
    for(int i=0 ; i<n-1 ;i++){
        flag= false;
        for(int j=0 ;j<n-1-i ;j++){
            if(arr[j]>arr[j+1] ){
                swap(arr[j],arr[j+1]);
            }
            flag= true;
        }
        if(!flag)break;
    }

    for(int i=0 ; i<n  ; i++){
        cout<<arr[i]<< "";
    }
}
