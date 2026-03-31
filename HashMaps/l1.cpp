#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int>v = {1,3,3,4,5};
    unordered_map<int,int>map;

    for(int i=0 ; i<5 ;i++){
        map[i] = v[i];
    };

    // if(map.find(3) != map.end()){
    //     cout<<map[3]<<endl;
    // }else cout<<"not found";

    for(auto m : map){
        cout<<m.first << ":"<< m.second<<endl;
    };

    // for(auto m : map){
    //     if(m[0] == 2){
    //         cout<<"2 is present"<<endl;
    //     }
    //     if(m.second == 2){
    //         cout<<"2 is available"<<endl;
    //     }
    // }

    return 0;

}