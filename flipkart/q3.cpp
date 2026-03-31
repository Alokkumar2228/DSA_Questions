#include <bits/stdc++.h>
using namespace std;




int main(){

    int n;
    cin>>n;
    string str[n];
    vector<int>v;
    string ans ="";
    string ans2 = "";

    for(int i=0 ; i<n ;i++){
        cin>>str[i];
    };

    for(int i=0 ;i<n ;i++){
        string s = str[i];
        string ans ="";
        for(int j=0 ; j<s.length() ; j++){
            if(isdigit(s[j])){
                ans += s[j];
            }else{
                if(!ans.empty()){
                    ans2 = to_string(stoi(ans));
                    v.push_back(stoi(ans2));
                    ans = "";
                }
            }
        }
        if(!ans.empty()){
             ans2 = to_string(stoi(ans));
                    v.push_back(stoi(ans2));
                    ans = "";
        }
    };


    sort(v.begin() , v.end());

    for(int i=0 ; i<v.size() ; i++){
        cout << v[i]<<endl;
    }












    return 0;
}