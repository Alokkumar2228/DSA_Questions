#include<bits/stdc++.h>
using namespace std;

int diff = INT_MAX;
int ans = 0 ;
set<pair<long long , int> , int>visited;
void solve(vector<int>&fill , int target , int sum  ,int idx ){

    if(visited.count({sum , idx})>0)return;
    if(idx>=fill.size()){  
        if(abs(target - sum) < diff){
            diff = abs(target - sum);
            ans = sum;
        }
        visited.insert({sum, idx});
        return;
    }

    if(abs(target - sum)< diff){
        ans = sum;
        diff = abs(target - sum);
        visited.insert({sum, idx});
    }

    solve(fill , target , sum , idx+1 );
    solve(fill , target , sum+fill[idx] , idx+1);
    solve(fill , target , sum+2*fill[idx] , idx+1 );

}

int main(){

    vector<int>bread;
    vector<int>filling;
    string s1 ;
    getline(cin , s1);

    int n;
    stringstream ss(s1);
    while(ss >> n)bread.push_back(n);

    string s2;
    getline(cin , s2);
    
    int m;
    stringstream tt(s2);
    while(tt >> m)filling.push_back(m);

    int target;
    cin>>target;

    for(int i = 0 ; i<bread.size() ; i++){
        int sum = bread[i];
        if((target - sum) == 0 ){
            cout<<sum<<endl;
            break;
        }

        solve(filling , target , sum  , 0);

    }

    cout<<"Closest sum: "<<ans<<endl;


    

    




    return 0;
}