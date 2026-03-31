// To convert an alphabet (character) → index, use simple subtraction.

✅ 1. Lowercase (a → 0)
int index = ch - 'a';
🔍 Example:
char ch = 'e';
int index = ch - 'a';

cout << index;   // Output: 4

👉 Mapping:

a → 0  
b → 1  
c → 2  
...
z → 25
✅ 2. Uppercase (A → 0)
int index = ch - 'A';
🔍 Example:
char ch = 'E';
int index = ch - 'A';

cout << index;   // Output: 4
🔥 If you want (1-based index)
Lowercase:
int index = ch - 'a' + 1;
Uppercase:
int index = ch - 'A' + 1;

👉 Example:

e → 5
E → 5
⚠️ Important
Use 'a' for lowercase
Use 'A' for uppercase
Don’t mix them ❌

acii value 
a-> 97 to 122
A-> 65 to 90