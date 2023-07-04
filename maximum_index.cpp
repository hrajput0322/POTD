//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        int left[n];
        int right[n];
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        for (int i=1;i<n;i++){
            left[i]=min(arr[i],left[i-1]);
        }
        for (int i=n-2;i>=0;i--){
            right[i]=max(arr[i],right[i+1]);
        }
        int i=0,j=0;
        int maxi=INT_MIN;
        while(i<n&&j<n){
            if(left[i]<=right[j]){
                maxi=max(maxi,j-i);
                j++;
            }
            else{
                i++;
            }
        }
    return maxi;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
