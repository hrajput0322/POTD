//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* find(Node* root,int n){
            if(root == NULL){
                return NULL;
            }
            
            if(n==root->data){
                return root;
            }
            
            if(n < root->data){
                find(root -> left,n);
            }else{
                find(root -> right,n);
            }
        }
        void find_ancestor(Node* root, Node* node,vector<Node*> &ans)   {
            if(root == NULL){
                return ;
            }
            ans.push_back(root);
            if(root -> data == node -> data){
                return ;
            }
            
            if(node->data < root->data){
                find_ancestor(root -> left,node,ans);
            }else{
                find_ancestor(root -> right,node,ans);
            }
            return ;
        }
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            Node* p = find(root,n1);
            Node* q = find(root,n2);
            vector<Node*> node_p;
            vector<Node*> node_q;
        
            find_ancestor(root,p,node_p);
            find_ancestor(root,q,node_q);
    
            int i = node_p.size() - 1,j = node_q.size() - 1;
        
            int it = min(i,j);

            while(it>=0){
                if(node_p[it] == node_q[it]){
                    return node_p[it];
                }
                it--;
            }
        
            return p;
        }

};


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends
