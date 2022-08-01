#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        int h1 = 0, h2 = 0;
        if (root->left != NULL)
            h1 = height(root->left) + 1;
        if (root->right != NULL)
            h2 = height(root->right) + 1;
        return h1 >= h2 ? h1 : h2;
    }

}; //End of Solution


int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
  	std::cout << height << endl;

    return 0;
}


int getHeight(vector<vector<int>> indexes, int node) {
    int l = indexes[node-1][0]; int r = indexes[node-1][1]; 
    int h1 = 0, h2 = 0;
    if (l != -1)
        h1 = getHeight(indexes, l) + 1;
    if (r != -1)
        h2 = getHeight(indexes, r) + 1;
    return h1 >= h2 ? h1 : h2;
}