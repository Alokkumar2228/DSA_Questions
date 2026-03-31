// Here is a complete Bitwise Operator Guide in C++ (Interview + DSA Important) 🔥

// 🔥 1️⃣ AND Operator (&)
// 📌 Rule:
// 1 & 1 = 1
// Otherwise = 0
// Example:
// int a = 5;   // 101
// int b = 3;   // 011
// cout << (a & b);   // 001 = 1
// ✅ Uses:

// Check even/odd → n & 1

// Turn OFF a bit

// 🔥 2️⃣ OR Operator (|)
// 📌 Rule:
// If any bit is 1 → result is 1
// int a = 5;  // 101
// int b = 3;  // 011
// cout << (a | b);  // 111 = 7
// ✅ Uses:

// Turn ON a bit

// 🔥 3️⃣ XOR Operator (^)
// 📌 Rule:
// Same bits → 0
// Different bits → 1
// int a = 5;  // 101
// int b = 3;  // 011
// cout << (a ^ b);  // 110 = 6
// ✅ Uses:

// Swap without temp

// Find unique element

// Toggle a bit

// 🔥 4️⃣ NOT Operator (~)

// Flips all bits.

// int a = 5;  
// cout << (~a);

// ⚠ Produces negative number (2’s complement)

// 🔥 5️⃣ Left Shift (<<)

// Moves bits left.

// int a = 5;  // 101
// cout << (a << 1);  // 1010 = 10
// ✅ Formula:
// n << k  = n × (2^k)
// 🔥 6️⃣ Right Shift (>>)

// Moves bits right.

// int a = 8;  // 1000
// cout << (a >> 1);  // 100 = 4
// ✅ Formula:
// n >> k = n / (2^k)
// 🚀 IMPORTANT BITWISE TRICKS (Very Important for Interviews)
// ✅ 1. Check Even or Odd
// if (n & 1) cout << "Odd";
// else cout << "Even";
// ✅ 2. Check ith Bit is Set or Not
// if (n & (1 << i))
// ✅ 3. Set ith Bit
// n = n | (1 << i);
// ✅ 4. Clear ith Bit
// n = n & ~(1 << i);
// ✅ 5. Toggle ith Bit
// n = n ^ (1 << i);
// ✅ 6. Remove Last Set Bit
// n = n & (n - 1);
// ✅ 7. Check Power of 2
// if (n > 0 && (n & (n - 1)) == 0)
// ✅ 8. Count Set Bits
// __builtin_popcount(n);       // for int
// __builtin_popcountll(n);     // for long long
// ✅ 9. Get Lowest Set Bit
// int lowest = n & (-n);
// 🎯 Time Complexity

// All bitwise operations → O(1)

// 🔥 Most Asked Bitwise Interview Questions

// Single number problem

// Power of 2

// Count set bits

// Subsets using bitmask

// Find two non-repeating numbers

// If you want, I can give:

// 🔥 Bitmasking full guide

// 🔥 XOR interview problems

// 🔥 Advanced bit manipulation tricks

// 🔥 20 Most Asked Bitwise Questions with solution

// Tell me what level you want (Beginner / Intermediate / Advanced)?

// give the method to count number of one , how to convert binary string t number(stl) , number to binary string

// Here is a complete interview-focused guide for all three things you asked 🔥

// ✅ 1️⃣ Count Number of 1’s (Set Bits)
// 🔹 Method 1: Built-in Function (Best & Fastest)
// int n = 10;   // 1010
// int count = __builtin_popcount(n);
// cout << count;   // 2

// For long long:

// __builtin_popcountll(n);

// ⏱ Time: O(1)
// 👉 Best answer in interview

// 🔹 Method 2: Using bitset
// #include <bitset>

// int n = 10;
// int count = bitset<32>(n).count();
// 🔹 Method 3: Brian Kernighan’s Algorithm (Important)
// int count = 0;
// while(n > 0){
//     n = n & (n - 1);
//     count++;
// }

// ⏱ Time: O(number of set bits)

// Very important trick 🔥

// ✅ 2️⃣ Convert Binary String → Number (Using STL)
// 🔹 Method 1: stoi() (Easiest)
// string s = "1010";
// int num = stoi(s, nullptr, 2);

// cout << num;   // 10

// 👉 2 means base 2

// For long long:

// long long num = stoll(s, nullptr, 2);
// 🔹 Method 2: Using bitset
// #include <bitset>

// string s = "1010";
// int num = bitset<32>(s).to_ulong();

// cout << num;   // 10
// ✅ 3️⃣ Convert Number → Binary String
// 🔹 Method 1: Using bitset (Best)
// #include <bitset>

// int n = 10;
// string binary = bitset<32>(n).to_string();

// cout << binary;

// Output:

// 00000000000000000000000000001010
// 🔹 Remove Leading Zeros
// binary.erase(0, binary.find_first_not_of('0'));
// cout << binary;   // 1010
// 🔹 Method 2: Using Loop
// int n = 10;
// string result = "";

// while(n > 0){
//     result = char('0' + (n % 2)) + result;
//     n /= 2;
// }

// 🎯 Interview Summary Table
// Task	Best Method
// Count set bits	__builtin_popcount()
// Binary string → number	stoi(s, nullptr, 2)
// Number → binary string	bitset<32>(n).to_string()