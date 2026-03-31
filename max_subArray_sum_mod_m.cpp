// User function Template for C++
class Solution {
  public:
    int maxSub(vector<int>& arr, int m) {
        
        // Set to store prefix sums in sorted order
        set<int> st;
        st.insert(0);   // To handle subarrays starting from index 0
        
        int pre = 0;                // Current prefix sum modulo m
        int mx_subarray_sum = 0;    // Maximum subarray sum modulo m
        
        for(int i = 0; i < arr.size(); i++) {  //O(n)
            
            // Compute prefix sum modulo m
            pre = (pre + arr[i]) % m;
            
            // Case 1: subarray starting from index 0
            mx_subarray_sum = max(mx_subarray_sum, pre);
            
            /*
             Subarray sum modulo m between indices (l+1 ... i) is:
             (pre[i] - pre[l] + m) % m
             
             To maximize this value:
             - pre[l] should be the smallest prefix strictly greater than pre[i]
             - This makes the subtraction wrap around close to m
             
             lower_bound(pre + 1) gives the smallest prefix > pre
            */
            
            auto it = st.lower_bound(pre + 1); //O(logn)
            
            if(it != st.end()) {
                mx_subarray_sum = max(
                    mx_subarray_sum,
                    (pre - *it + m) % m
                );
            }
            
            // Store current prefix for future subarrays
            st.insert(pre);
        }
        
        return mx_subarray_sum;
    }
};

//Time complexity
//O(n) * O(logn) = O(nlogn);
