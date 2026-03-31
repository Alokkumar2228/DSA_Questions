#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    vector<int> ans;
    ans.reserve(n);

    // Fill stack
    for (int i = 1; i <= n / 2; i++) {
        st.push(i);
    }

    // If even: pair all
    if (n % 2 == 0) {
        while (!st.empty()) {
            int x = st.top();
            ans.push_back(x);
            ans.push_back(-x);
            st.pop();
        }
    }
    // If odd: pair (n-1) numbers, then add a 0
    else {
        while (!st.empty()) {
            int x = st.top();
            ans.push_back(x);
            ans.push_back(-x);
            st.pop();
        }
        ans.push_back(0); // middle element
    }

    // Print result
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
