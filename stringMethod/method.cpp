// In C++ std::string does not have a method called .toLowercase(). That’s Java-style.
// 
// ✅ Correct C++ way:
// 
// You can use transform from <algorithm> with ::tolower:

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "Alok";
    string ans = str;  // copy original string
    
    // this will convery full string to lowercase
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

    char ch = 'A';
    // this will change char to lower case
    cout<<(char)tolower(ch);
    
    cout << ans;  // output: alok
    return 0;
}

// to check the string exist in vector or not

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> words = {"Alok", "Aman", "Gupta"};
    string target = "Aman";

    auto it = find(words.begin(), words.end(), target);

    if (it != words.end()) {
        cout << "Found at index " << (it - words.begin()) << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
// ✅ Output:
// 
// pgsql
// Copy code
// Found at index 1

//IF YOU ONLY WANT TO CHEK THE EXISTANCE YES OR NOT THEN USE THIS->
2. Using std::count

If you only need to check existence (not position):

if (count(words.begin(), words.end(), target)) {
    cout << "Exists\n";
} else {
    cout << "Not exists\n";
}

// to string string or char in front of string

strigng s = "Alok";
s.insert(0, "Mr. "); // Insert "Mr. " at the beginning
cout << s; // Output: "Mr. Alok"

// Syntax:
// s.insert(position, count, character);

//if string s = abc -> make it to -> dddddabc(push 5 d in front of s)
s.insert(0,5,'d');
cout<<s<<end;  //output-> dddddabc 

// T.C. => insert() at front = O(n) time (shifts all characters

//how to sort a string in a range
let string s = "helloworld";
//let we have to short from  idx 1to 8

sort(s.begin()+1 , s.begin()+9);
cout<<s<<endl; //output-> hdehllloorw
// to find the substring in the string

string s = "hello world";
string sub = "world";

// to check the substring is present or not
if(s.find(sub)!=string::npos){
    cout<<"Substring found at index: "<<s.find(sub)<<endl;
}
