#include<iostream>
#include<queue>
using namespace std;

int main(){
    // for kth largest use ->min heap
    // gor kth smallest use -> max heap
    priority_queue<int ,vector<int> , greater<int>>pq;
    int arr[] = {5 ,100 ,-5 ,34 ,65 ,9 ,-100};
    int k =3;
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i<len ; i++){ //log(n)
        pq.push(arr[i]); //log(k)
        if(pq.size() > k)pq.pop(); //log(k)
    }
    cout<<pq.top();

    //complexity -> nlog(k)
}