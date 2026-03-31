#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int>stock_price = {100,80,60,81,70,60,75,85};
    vector<int>ans(8,0);
    stack<int>st;
    st.push(0);
    ans[0]=1;
    for(int i=1 ; i<stock_price.size() ; i++){
        if(stock_price[st.top()]>stock_price[i]){
            ans[i] = i - st.top();
            st.push(i);
        }else {
            while(stock_price[i]>stock_price[st.top()]){
                st.pop();
            };
            ans[i] = i -  st.top();
            st.push(i);
        }
    };

    for(auto &it : ans){
        cout<<it<<endl;
    };






    return 0;
}
