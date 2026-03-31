#include<iostream>
#include<stack>
#include<vector>
using namespace std;


 void recursive_Print(stack<int>&st){
        if(st.size() == 0) return;
        int x = st.top();
        st.pop();
        recursive_Print(st);
        cout<<x<<" ";
        st.push(x);
};

 void recursive_Print_reverse(stack<int>&st){
        if(st.size() == 0) return;
        cout<<st.top()<<" ";
        st.pop();
        recursive_Print_reverse(st);
};

void insert_ele_atIdx(stack<int>&st , int val , int idx){
    stack<int>temp;
    while(st.size()>idx){
        temp.push(st.top());
        st.pop();
    };
    st.push(val);
    while(temp.size() != 0){
        st.push(temp.top());
        temp.pop();
    };

};

void insert_At_End(stack<int>&st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    };
    int x = st.top();
    st.pop();
    insert_At_End(st,val);
    st.push(x);
};

void Push_array(int arr,int val){
    idx++;
    arr[idx] = val;

}

int main(){

    // stack<int>st;
    // stack<int>temp1;
    // stack<int>temp2;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.push(60);
    // cout<<st.size()<<endl;

    //print element of stack

    // while(st.size()!=0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // };

    // print element recursive

    // recursive_Print(st);

    // cout<<endl;

    // print element recursive in reverse order

    // recursive_Print_reverse(st);

    //USING TWO EXTRA STACK TO REVERSE THE STACK

    // while(st.size() != 0){
    //     cout<<st.top()<<" ";
    //     int x = st.top();
    //     st.pop();
    //     temp1.push(x);
    // };
    // cout<<endl;

    // while(temp1.size() != 0){
    //     cout<<temp1.top()<<" ";
    //     int x = temp1.top();
    //     temp1.pop();
    //     temp2.push(x);
    // };
    // cout<<endl;

    // while(temp2.size() != 0){
    //     cout<<temp2.top()<<" ";
    //     int x = temp2.top();
    //     temp2.pop();
    //     st.push(x);
    // };
    // cout<<endl;
    // while(st.size() != 0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // };
    // cout<<endl;

    //Push stacka at any index

    // insert_ele_atIdx(st,80,3);

    // insert_At_End(st , 90);


    // recursive_Print(st);
    // cout<<endl;
    // recursive_Print_reverse(st);

    // Stack Implementation using array/vector





    return 0;
}