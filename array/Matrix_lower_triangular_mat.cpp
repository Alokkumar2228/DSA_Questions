#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>>v = {{2,1,3,5} , {1,0,0,0} , {1,1,3,6} , {0 , 0 , 4 , 6}};

    int row = v.size();
    int col = v[0].size();

    for(int i=0 ; i<col ; i++){
        v[2][i] = v[2][i] - v[1][i];
    }

    for(int i=0 ; i<col ; i++){
        v[1][i] = 2*v[1][i] - v[0][i];
    }

    for(int i=0 ; i<col ; i++){
        v[2][i] = v[2][i] + v[1][i];
    }

    for(int i=0 ; i<col ; i++){
        v[2][i] = v[2][i] + v[1][i];
    }

    for(int i=0 ; i<row ; i++){
        v[i][2] = 3*v[i][2] - 2*v[i][3];
    }

    for(int i=0 ; i<col ; i++){
        v[2][i] = v[2][i] - v[1][i];
    }

    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[0].size() ; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }


    




    return 0;
}