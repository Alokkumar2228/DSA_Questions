#include<iostream>
using namespace std;

class Student{
    public:
       string name;
       int age;
       int rollNo;

       Student(string name , int age , int rollNo){
           this->name = name;
           this->age = age;
           this->rollNo = rollNo;
       };

};

 void changeName(Student *s){
    s->name = "Simran";
 }

int main(){

    Student *s = new Student("John", 20, 101);   // Dynamically allocating memory for Student object
    // cout<<(*s).name << " " <<(*s).age << " " << (*s).rollNo << endl;
    // cout << s->name << " " << s->age << " " << s->rollNo << endl;

    Student s1 = *s; // Dereferencing the pointer to get the object
    cout<<"Before:" << s1.name << " " << s1.age << " " << s1.rollNo << endl;

    changeName(s); // Passing pointer to the function

    cout<<"After:" << s->name << " " << s->age << " " << s->rollNo << endl;

    // Comparison of nodes

}


    return 0;


}