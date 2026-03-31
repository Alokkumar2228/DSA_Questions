#include<iostream>
using namespace std;
 // Player-> user define data type

class Book{

    public:
    string name;
    int price ;
    int pagelen;

    Book(string name , int price , int pagelen){
        this->name = name;
        this->price = price;
        this->pagelen = pagelen;
    }

    int countBooks(int price){
        if(this->price < price){
            return 1;   
        }else return 0;
    }

    bool isBookPresent (string title){
        if(title == this->name ){
            return true;
        }else return false;
    }
};

int main(){

    Book b1("Math" , 300 , 20);
    cout<<b1.countBooks(400);
    cout<<b1.isBookPresent("Physic");


    return 0;
}