// 🔁 Circular Array — Full Concept Notes
// 1️⃣ What is a Circular Array?

// In a circular array, the end connects back to the start.

// Example:

// nums = [1, 2, 3]


// Traversal order (circular):

// 1 → 2 → 3 → 1 → 2 → 3 → ...


// So for the last element, “right side” includes the start of the array.

// 2️⃣ Why Circular Arrays Are Tricky

// Normal array:

// Right side = elements after index i

// Circular array:

// Right side = elements after i

// PLUS elements from beginning up to i-1

// Naive approach:

// For each element, scan entire array → ❌ O(n²)

// 3️⃣ The Core Trick (🔥 MOST IMPORTANT)

// Pretend the array is repeated twice

// Instead of:

// [1, 2, 1]


// Think of:

// [1, 2, 1, 1, 2, 1]


// But we never actually create this array.

// 4️⃣ How We Simulate Circularity (Key Formula)

// Let:

// n = nums.size()


// Loop like this:

// for (int i = 2*n - 1; i >= 0; i--) {
//     int idx = i % n;
// }

// Why this works:

// i % n maps indices back into [0 … n-1]

// Every element gets to “see” all elements to its right including wrap-around

// 5️⃣ Where Monotonic Stack Fits In

// Circular array problems usually ask:

// Next Greater

// Next Smaller

// Previous Greater

// Previous Smaller

// Pattern:

// “Find first better element in some direction”

// This screams:
// 👉 Monotonic Stack

// 6️⃣ Monotonic Stack Rule (For Next Greater)

// We maintain:

// Stack: decreasing order (top = smallest)


// Why?

// If current element is bigger → it becomes the next greater for all smaller ones before it

// 7️⃣ Circular Next Greater Element — Strategy
// Step-by-step Plan

// Initialize:

// stack<int> st;
// vector<int> ans(n, -1);


// Traverse from 2n-1 → 0

// For each index:

// idx = i % n


// While stack top ≤ current:

// st.pop();


// If i < n and stack not empty:

// ans[idx] = st.top();


// Push current element:

// st.push(nums[idx]);

// 8️⃣ Full Example (Dry Run)
// Input:
// nums = [1, 2, 1]
// n = 3

// Traverse indices:
// i = 5 → 0

// i	idx	nums[idx]	Stack before	Action	Stack after	ans
// 5	2	1	[]	push	[1]	-
// 4	1	2	[1]	pop, push	[2]	-
// 3	0	1	[2]	push	[2,1]	-
// 2	2	1	[2,1]	pop	[2]	ans[2]=2
// 1	1	2	[2]	pop	[]	ans[1]=-1
// 0	0	1	[2]	ans[0]=2	[2,1]	✔
// Final Output:
// [2, -1, 2]

// 9️⃣ Why This Is O(n)
// Critical Guarantee:

// Each element:

// Is pushed at most twice

// Is popped at most twice

// Total operations:

// push ≤ 2n
// pop ≤ 2n

// 👉 Overall Time Complexity:
// O(n)

// 🔟 Template Code (MEMORIZE THIS)
// vector<int> nextGreaterElements(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> ans(n, -1);
//     stack<int> st;

//     for (int i = 2*n - 1; i >= 0; i--) {
//         int idx = i % n;

//         while (!st.empty() && st.top() <= nums[idx]) {
//             st.pop();
//         }

//         if (i < n && !st.empty()) {
//             ans[idx] = st.top();
//         }

//         st.push(nums[idx]);
//     }

//     return ans;
// }

// 1️⃣1️⃣ Common Circular Variations
// Problem	Stack Type
// Next Greater	Decreasing
// Next Smaller	Increasing
// Previous Greater	Decreasing
// Previous Smaller	Increasing

// 1️⃣3️⃣ When to Recognize This Pattern

// If you see:

// “next greater”

// “wrap around”

// “circular”

// “first element on the right/left”

// 👉 Think: 2n traversal + monotonic stack

// Example Problems:

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        /*
        =========================================
        PROBLEM: Next Greater Element in CIRCULAR array
        =========================================

        Circular means:
        - After the last element, we can continue from the first element.
        - So each element can look "right" across the array boundary.

        Example:
        nums = [1, 2, 1]
        Result = [2, -1, 2]
        */

        int n = nums.size();

        // Answer array:
        // Initialize with -1 because if no greater element exists,
        // the answer should be -1.
        vector<int> ans(n, -1);

        /*
        Stack will store ELEMENT VALUES (not indices).

        We maintain a MONOTONIC DECREASING STACK:
        - Top of stack is the smallest among stored elements.
        - Stack contains only "useful candidates" for next greater.
        */
        stack<int> st;

        /*
        =========================================
        KEY CIRCULAR ARRAY TRICK
        =========================================

        We traverse from (2*n - 1) down to 0.

        Why 2*n?
        - First pass: prepares stack (simulates circular wrap)
        - Second pass: fills answers

        We DO NOT duplicate the array.
        Instead, we use modulo (%) to wrap indices.
        */

        for (int i = 2*n - 1; i >= 0; i--) {

            // Map index back into [0 ... n-1]
            int idx = i % n;

            /*
            =========================================
            MONOTONIC STACK RULE
            =========================================

            While stack is not empty AND
            stack top is <= current element:

            Why pop?
            - Smaller or equal elements can NEVER be the next greater
              for current element or for any element before it.
            - So they are useless → remove them.
            */
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            /*
            =========================================
            FILL ANSWER (ONLY IN SECOND PASS)
            =========================================

            We only write answers when i < n.
            Why?
            - i >= n → first pass (stack preparation)
            - i < n  → real positions of original array
            */
            if (i < n && !st.empty()) {
                ans[idx] = st.top();
            }

            /*
            Push current element into stack.

            This element can act as "next greater"
            for elements that appear before it.
            */
            st.push(nums[idx]);
        }

        /*
        =========================================
        TIME & SPACE COMPLEXITY
        =========================================

        Time Complexity: O(n)
        - Each element is pushed at most twice
        - Each element is popped at most twice
        - Total operations ≤ 4n

        Space Complexity: O(n)
        - Stack + answer array
        */

        return ans;
    }
};
