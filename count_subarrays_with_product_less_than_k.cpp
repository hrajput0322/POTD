//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i=0,j=0,ans=0;
        long long prod=1;
        while(j<n && i<n)
        {
            long long p = 1;
            int res = 0;
            for (int start = 0, end = 0; end < n; end++) {
    
                // Move right bound by 1 step. Update the product.
                p *= a[end];
    
                // Move left bound so guarantee that p is again
                // less than k.
                while (start < end && p >= k) p /= a[start++];
    
                // If p is less than k, update the counter.
                // Note that this is working even for (start == end):
                // it means that the previous window cannot grow
                // anymore and a single array element is the only
                // addendum.
                if (p < k) {
                    int len = end - start + 1;
                    res += len;
                }
            }
    
            return res;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
