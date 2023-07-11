//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int arr[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int j=1;
 		int top=0;
 		int left=0;
 		int right=m-1;
 		int bottom=n-1;
 		while (top<=bottom && left<=right){
 		    for (int i=left;i<=right;i++){
 		        if (j==k){
 		            return arr[top][i];
 		        }
 		        j++;
 		    }
 		    top++;
 		    for (int i=top;i<=bottom;i++){
 		        if (j==k){
 		            return arr[i][right];
 		        }
 		        j++;
 		    }
 		    right--;
 		    if (top<=bottom){
 		        for (int i=right;i>=left;i--){
 		            if (j==k){
 		                return arr[bottom][i];
 		            }
 		            j++;
 		        }
 		        bottom--;
 		    }
 		    if (left<=right){
 		        for (int i=bottom;i>=top;i--){
 		            if (j==k){
 		                return arr[i][left];
 		            }
 		            j++;
 		        }
 		        left++;
 		    }
 		}
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
