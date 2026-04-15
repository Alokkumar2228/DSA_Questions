#include<iostream>
using namespace std;

class Solution {
public:

    unordered_set<int>storest;
    map<pair<long long,long long>, bool> mp;
    bool solve( int &end , int jmp , int st){

        if(jmp <= 0 || st < 0)return false;
        if(st ==  end)return true;
        if(storest.find(st)==storest.end())return false;
        if(mp.count({jmp , st})) return mp[{jmp, st}];

        return mp[{jmp,st}]= solve(end , jmp+1 , st+(jmp+1))||solve(end , jmp , st+jmp)||solve(end , jmp-1 , st+(jmp-1));

    }
    bool canCross(vector<int>& stones) {

        for(int i=0 ; i<stones.size() ; i++)storest.insert(stones[i]);

        if(storest.find(1) == storest.end())return false;

        return solve(stones.back() , 1 , 1);
        
    }
};

int main(){

    vector<int>height = {0,1,3,5,6,8,12,17};
    int len = height.size();
    Solution ob;
    bool ans = ob.canCross(height); 
    cout<< ans;


}