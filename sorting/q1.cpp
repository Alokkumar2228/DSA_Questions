#include<iostream>
#include<string>
#include<algorithm> // Needed for sort
using namespace std;

int main() {
    
    //Q1
    // string str;
    // cin >> str;

    // string ans = "";

    // for (int i = 0; i < str.size(); i++) {
    //     if (str[i] >= 'X') {
    //         ans += str[i]; //
    //     }
    // }

    // sort(ans.begin(), ans.end());

    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }

    // return 0;

    //Q2

     int arr[] = {5,0,1,2,0,0,0,3};

     int n = sizeof(arr)/sizeof(arr[0]);
     int count=0;
     for(int i=0;i<n;i++){
         if(arr[i]==0){
             count++;
         }
     }
     
     for( int i=0;i<count;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]==0 && arr[j+1]!=0){
                swap(arr[j],arr[j+1]);
            }else continue;
        }
     }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }

}
