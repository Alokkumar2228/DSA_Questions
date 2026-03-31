#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int idx = 1;
    public:
    vector<int>vec;
    int len;
    MinHeap(int len){
        this->len = len;
        vec.resize(len+1,0);
    }
    void front(){
        cout<<vec[1]<<endl;
    }
    void push(int val){
        vec[idx] = val;
        int i = idx ;
        while(i!=1){
            int parent = i/2;
            if(vec[parent]>vec[i]){
                swap(vec[parent],vec[i]);
                i = i/2;
            }else break;
        }
        idx++;
    }

    void pop(){
        vec[1] = vec[idx-1];
        idx--;
        int i = 1;
        while(2*i<idx){
            int l = 2*i;
            int r = 2*i + 1;
            int s = l;
            if(r<idx && vec[r]<vec[l])s = r;
            if(vec[s]>vec[i])break;
            else{
                swap(vec[s],vec[i]);
                i = s;
            }
            
        }
    }

    void display(){
        for(int i=1 ; i<idx;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    MinHeap mh(10);
    mh.push(8);
    mh.push(9);
    mh.push(10);
    mh.push(13);
    mh.push(14);
    mh.push(11);
    mh.push(12);
    mh.push(4);
    mh.push(1);
    mh.push(100);
    mh.display();
    mh.front();
    mh.pop();
    mh.display();




    return 0;
}