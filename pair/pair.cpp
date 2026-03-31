// All about Pair

// What is pair?
// 
// A pair is a simple container in C++ STL that stores two values together (possibly of different types).
// 
// Defined in <utility> header.
// 
// Syntax:
// 
// pair<T1, T2> p;
// 
// 
// where T1 and T2 can be any data type.
// 
// 👉 Think of it as a tiny struct with only two members: .first and .second.

2. Creating and Initializing Pairs
(a) Default initialization
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> p;  // uninitialized
    p.first = 1;
    p.second = "Hello";
    cout << p.first << " " << p.second << "\n";
}

(b) Direct initialization
pair<int, string> p1(10, "C++");
pair<int, string> p2 = {20, "STL"};

(c) Using make_pair()
auto p3 = make_pair(30, "Pair");

3. Accessing Pair Elements

Each pair has only two members:

cout << p1.first;   // 10
cout << p1.second;  // "C++"

4. Common Methods and Functions
(a) make_pair(a, b)

Creates a pair without explicitly writing types.

auto p = make_pair(1, 2.5);  // pair<int, double>

(b) tie()

Unpacks pair values into variables.

pair<int, string> p = {101, "Code"};
int x; string y;
tie(x, y) = p;
cout << x << " " << y;  // 101 Code

(c) swap()

Swap contents of two pairs (if same type).

pair<int,int> p1(1,2), p2(3,4);
p1.swap(p2);  // now p1=(3,4), p2=(1,2)

(d) Comparison operators

Pairs are compared lexicographically:

First compares .first

If equal, compares .second

Example:

pair<int,int> p1(1,5), p2(1,7);
cout << (p1 < p2);  // true (5 < 7)

5. Pairs Inside Containers

Pairs are very useful in STL containers.

(a) Vector of pairs
vector<pair<int, string>> v;
v.push_back({1, "one"});
v.push_back({2, "two"});

for(auto &p : v) {
    cout << p.first << " " << p.second << "\n";
}

(b) Map

A map is internally implemented as a container of pairs (pair<const Key, Value>).

map<int, string> mp;
mp[1] = "apple";
mp[2] = "banana";

for(auto &p : mp) {
    cout << p.first << " => " << p.second << "\n";
}

(c) Set of pairs
set<pair<int,int>> s;
s.insert({1,2});
s.insert({2,3});

6. Real-Life Examples
Example 1: Storing coordinates
vector<pair<int,int>> points = {{1,2},{3,4},{5,6}};
for(auto &pt : points) {
    cout << "(" << pt.first << "," << pt.second << ")\n";
}

Example 2: Sorting by pair
vector<pair<int,int>> arr = {{2,100}, {1,200}, {2,50}};
sort(arr.begin(), arr.end()); // sorts by first, then by second

Example 3: Returning two values from a function
pair<int,int> getMinMax(vector<int> &a) {
    return { *min_element(a.begin(), a.end()), 
             *max_element(a.begin(), a.end()) };
}

int main() {
    vector<int> arr = {3,1,7,5};
    auto ans = getMinMax(arr);
    cout << "Min: " << ans.first << ", Max: " << ans.second;
}

🔑 Key Takeaways

pair groups two values (like a 2-element tuple).

Access with .first and .second.

Can be nested: pair<int, pair<int,string>>.

Works great inside containers (vector, map, set).

Supports make_pair, tie, swap, comparison operators.