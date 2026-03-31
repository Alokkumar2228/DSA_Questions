#include<bits/stdc++.h>
using namespace std;

void Permutation(string ans , string s){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0 ; i<s.length();i++){
        char ch = s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        Permutation(ans+ch , ros);
    };
};

int main(){

    string s = "abcd";
    Permutation("",s);




    return 0;
}