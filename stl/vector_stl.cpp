// // 1. Erase element at a specific index

// vector<int> v = {10, 20, 30, 40, 50};

// int index = 2; // remove 30
// v.erase(v.begin()+index); // O(n) time complexity

// //2. Erase a range of elements
// vector<int> v2 = {10, 20, 30, 40, 50, 60, 70};
// v2.erase(v.begin()+2 , v.begin()+5); // removes 30,40,50 -> not 5th index is excluded


// // 3. Erase by value (remove all occurrences)

// vector<int> v3 = {10, 20, 30, 20, 40, 20, 50};
// // v.erase(remove(v.begin(), v.end(), value), v.end()); ->syntax

// v3.erase(remove(v.begin() , v.end() , 20), v.end()); // removes all 20s

// =========================================
//             C++ VECTOR NOTES
// =========================================

// -----------------------------------------
// 1. CONSTRUCTORS & CAPACITY
// -----------------------------------------

// // Create empty vector - O(1)
// vector<int> v;

// // Create vector of size n (default initialized) - O(n)
// vector<int> v1(5);    // {0,0,0,0,0}

// // Create vector with n copies of a value - O(n)
// vector<int> v2(5, 10); // {10,10,10,10,10}

// // Copy constructor - O(n)
// vector<int> v3 = v2;

// // Move constructor - O(1)
// vector<int> v4 = move(v3);

// // size() - O(1)
// int s = v2.size();     // 5

// // capacity() - O(1)
// int c = v2.capacity();

// // empty() - O(1)
// bool e = v2.empty();

// // reserve() - amortized O(n)
// v.reserve(100);

// // resize() - O(n)
// v.resize(10); // If expanding, fills new slots with 0

// // shrink_to_fit() - O(n)
// v.shrink_to_fit();

// -----------------------------------------
// 2. ELEMENT ACCESS (ALL O(1))
// -----------------------------------------

// vector<int> v = {10, 20, 30};

// // O(1)
// int x = v[1]; // 20

// // O(1) + bounds check
// int y = v.at(2); // 30

// // O(1)
// int f = v.front(); // 10
// int b = v.back();  // 30

// // O(1) - raw pointer to array
// int* p = v.data();

// -----------------------------------------
// 3. MODIFIERS
// -----------------------------------------

// vector<int> v = {1,2,3};

// // push_back() - Amortized O(1)
// v.push_back(4);  // {1,2,3,4}

// // pop_back() - O(1)
// v.pop_back();    // {1,2,3}

// // insert() - O(n)
// v.insert(v.begin() + 1, 10); // {1,10,2,3}

// // insert multiple - O(n)
// v.insert(v.begin(), 3, 7);   // {7,7,7,1,10,2,3}

// // erase() single element - O(n)
// v.erase(v.begin() + 2);

// // erase range - O(n)
// v.erase(v.begin(), v.begin() + 3);

// // clear() - O(n)
// v.clear();

// // assign() - O(n)
// v.assign(5, 100);  // {100,100,100,100,100}

// // swap() - O(1)
// swap(v, v2);

// -----------------------------------------
// 4. ITERATORS (ALL O(1))
// -----------------------------------------

// vector<int> v = {1,2,3};

// auto it  = v.begin();  // points to 1
// auto it2 = v.end();    // points past last

// auto rit = v.rbegin(); // reverse iterator

// for (auto &x : v) {}   // range loop

// -----------------------------------------
// 5. STL ALGORITHMS USED WITH VECTOR
// -----------------------------------------

// vector<int> v = {5,3,7,1,9};

// // sort() - O(n log n)
// sort(v.begin(), v.end());

// // binary_search() - O(log n)
// bool ok = binary_search(v.begin(), v.end(), 7);

// // lower_bound() / upper_bound() - O(log n)
// auto lb = lower_bound(v.begin(), v.end(), 5);
// auto ub = upper_bound(v.begin(), v.end(), 5);

// // reverse() - O(n)
// reverse(v.begin(), v.end());

// // find() - O(n)
// auto it = find(v.begin(), v.end(), 7);

// // count() - O(n)
// int c = count(v.begin(), v.end(), 3);

// -----------------------------------------
// 6. MEMORY GROWTH (IMPORTANT FOR INTERVIEW)
// -----------------------------------------

// - When vector is full and push_back() happens:
//     * New memory allocated (usually 2x capacity)
//     * Old elements copied → O(n)
//     * push_back becomes expensive that time

// - But average cost = O(1) → Amortized O(1)

// -----------------------------------------
// 7. TIME COMPLEXITY SUMMARY
// -----------------------------------------

// Access:
//     v[i], v.at(i), front(), back()       --> O(1)

// Insert/Delete at end:
//     push_back(), pop_back()              --> Amortized O(1)

// Insert/Delete at middle:
//     insert(), erase()                    --> O(n)

// Search (unsorted):
//     find(), count()                      --> O(n)

// Search (sorted):
//     binary_search(), lower_bound()       --> O(log n)

// Sort:
//     sort()                               --> O(n log n)

// -----------------------------------------
// 8. QUICK CHEAT NOTES
// -----------------------------------------

// - vector = dynamic array
// - Random access = O(1)
// - insert/erase at middle = O(n)
// - push_back = amortized O(1)
// - erase() automatically shifts elements
// - erase(begin()+i) removes element at index i

// =========================================
//              END OF NOTES
// =========================================

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> v = {10, 20, 30, 40, 50};
//     v.insert(v.begin(), 3, 7);   // {7,7,7,1,10,2,3}

//     auto lb = lower_bound(v.begin(), v.end(), 30);
//     auto ub = upper_bound(v.begin(), v.end(), 30);

//     for (size_t i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";    
//     }
//     bool ok = binary_search(v.begin(), v.end(), 7);
//     cout << endl << ok << endl;
    

//     cout << *lb << " " << *ub;
// }

// Rotate the array/vector/string


// In C++, when people say “rotation method”, they usually mean rotating elements in a container (array / vector / string).
// There are two big ways to do this:

// ✅ STL rotation (std::rotate) → recommended

// ⚙️ Manual rotation techniques → interview classics

// I’ll go basic → advanced, clean and crisp.

// 1️⃣ STL Rotation (Best & Cleanest)
// 🔹 std::rotate

// Header

// #include <algorithm>

// 🔹 Syntax
// rotate(start, middle, end);


// [start, middle) → moves to the end

// [middle, end) → comes to the front

// 🔁 Left Rotation by k
// vector<int> v = {1,2,3,4,5};
// int k = 2;

// rotate(v.begin(), v.begin() + k, v.end());


// ✅ Result:

// 3 4 5 1 2

// 🔁 Right Rotation by k
// int n = v.size();
// rotate(v.begin(), v.end() - k, v.end());


// ✅ Result:

// 4 5 1 2 3

// ⏱ Time & Space

// Time: O(n)

// Space: O(1)

// 2️⃣ Rotation Using Reverse Method (INTERVIEW FAVORITE 🔥)
// 🔁 Left Rotate by k

// Steps:

// Reverse first k

// Reverse remaining n-k

// Reverse whole array

// reverse(v.begin(), v.begin() + k);
// reverse(v.begin() + k, v.end());
// reverse(v.begin(), v.end());

// 🔁 Right Rotate by k
// k %= n;
// reverse(v.begin(), v.end());
// reverse(v.begin(), v.begin() + k);
// reverse(v.begin() + k, v.end());

// 3️⃣ Rotation Using Temporary Array (Easy but Extra Space)
// vector<int> temp(n);

// for(int i = 0; i < n; i++)
//     temp[(i + k) % n] = v[i];

// v = temp;


// Time: O(n)

// Space: O(n)

// 4️⃣ Rotation One-by-One (Worst Method ❌)
// for(int i = 0; i < k; i++) {
//     int first = v[0];
//     for(int j = 0; j < n-1; j++)
//         v[j] = v[j+1];
//     v[n-1] = first;
// }


// Time: O(n × k)

// ❌ Avoid unless forced

// 5️⃣ Rotation for Strings
// string s = "abcdef";
// rotate(s.begin(), s.begin() + 2, s.end());


// Result:

// cdefab

// 6️⃣ Rotation for Arrays
// int arr[] = {1,2,3,4,5};
// rotate(arr, arr + 2, arr + 5);

// 7️⃣ Which Method Should You Use?
// Scenario	Best Choice
// Clean code	std::rotate
// Interview	Reverse method
// Extra space allowed	Temp array
// Small k only	Any
// 🧠 Interview Insight

// If the interviewer asks:

// “Rotate array in-place with O(1) space”

// They want:
// 👉 Reverse method

// If they allow STL:
// 👉 std::rotate

// TL;DR
// rotate(v.begin(), v.begin() + k, v.end());   // left
// rotate(v.begin(), v.end() - k, v.end());     // right