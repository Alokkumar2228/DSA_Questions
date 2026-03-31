Header
#include <iostream>
#include <set>
using namespace std;

//🔹 Important Methods of std::set
//1. insert() – Insert an element
set<int> s;
s.insert(10);
s.insert(5);
s.insert(20);
// s = {5, 10, 20}

//2. erase() – Remove an element (by value or iterator)
s.erase(10);    // removes element 10
s.erase(s.begin()); // removes first element (smallest)
// s = {20}

//3. find() – Search element, returns iterator
auto it = s.find(20);
if(it != s.end()) cout << "Found: " << *it;  // Found: 20

//4. count() – Check if element exists (0 or 1)
cout << s.count(20); // 1 (present)
cout << s.count(50); // 0 (not present)

//5. size() – Number of elements
cout << "Size: " << s.size();

//6. empty() – Check if set is empty
if(s.empty()) cout << "Set is empty";

//7. clear() – Remove all elements
s.clear();   // s = {}

//8. begin() / end() – Iterators (first, last+1)
set<int> s = {1, 2, 3, 4};
cout << *s.begin();        // 1
cout << *prev(s.end());    // 4 (last element)

//9. rbegin() / rend() – Reverse iterators
set<int> s = {1, 2, 3, 4};
cout << *s.rbegin();    // 4 (largest)

//10. lower_bound() – First element ≥ given value
set<int> s = {10, 20, 30, 40};
auto it = s.lower_bound(25);
if(it != s.end()) cout << *it; // 30

//11. upper_bound() – First element > given value
auto it2 = s.upper_bound(30);
if(it2 != s.end()) cout << *it2; // 40

//12. swap() – Swap contents of two sets
set<int> a = {1, 2, 3};
set<int> b = {10, 20};
a.swap(b);
// a = {10, 20}, b = {1, 2, 3}

//13. emplace() – Insert (faster than insert, constructs in place)
set<int> s;
s.emplace(50);
s.emplace(10);
// s = {10, 50}

//✅ Full Example
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // insert
    s.insert(10);
    s.insert(20);
    s.insert(5);

    // print all elements
    for(int x : s) cout << x << " ";  // 5 10 20
    cout << endl;

    // find
    auto it = s.find(10);
    if(it != s.end()) cout << "Found " << *it << endl;

    // erase
    s.erase(10);

    // lower_bound & upper_bound
    cout << "Lower bound of 15: " << *s.lower_bound(15) << endl; // 20
    cout << "Upper bound of 5: " << *s.upper_bound(5) << endl;   // 20

    // size
    cout << "Size: " << s.size() << endl;

    return 0;
}