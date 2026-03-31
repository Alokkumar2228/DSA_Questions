#include<iostream>
using namespace std;

int main(){

    int arr[] = { 1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);

    for(int i=0 ; i<len ;i++ ){
        for(int j=i ; j<len ;j++){
            int k = i;
            cout<<"[";
            while(k<=j){
                cout<<arr[k];
                k++;
            }
            cout<<"]"<<endl;
        }
    }
}