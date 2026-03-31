#include <bits/stdc++.h>
using namespace std;

void substring(string ans, string org) {
    if(org.length() == 0){
        cout<<ans<<endl;
        return;
    };
    char ch = org[0];
    substring(ans+ch , org.substr(1));
    substring(ans , org.substr(1));     
};

int main() {
    string org = "alok";
     substring("", org); // output: loklnffd
    return 0;
}
