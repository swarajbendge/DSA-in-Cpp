// ** all three traversal in one iteration ** //


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

tuple<vector<int>, vector<int>, vector<int>> preInPostTraversal(TreeNode* root) {
    vector<int> preorder, inorder, postorder;
    stack<pair<TreeNode*, int>> st;
    if(root == NULL) return {preorder, inorder, postorder};
    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            preorder.push_back(it.first -> data);
            it.second++;
            st.push(it);
            if(it.first -> left != NULL){
                st.push({it.first -> left, 1});
            }
        }
        else if(it.second == 2){
            inorder.push_back(it.first -> data);
            it.second++;
            st.push(it);
            if(it.first -> right != NULL) {
                st.push({it.first -> right, 1});
            }
        }
        else{
            postorder.push_back(it.first -> data);
        }
    }
    return {preorder, inorder, postorder};
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> preorder, inorder, postorder;
    tie(preorder, inorder, postorder) = preInPostTraversal(root);


    cout << "Preorder: ";
    for(int x : preorder) cout << x << " ";
    cout << endl;

    cout << "Inorder: ";
    for(int x : inorder) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for(int x : postorder) cout << x << " ";
    cout << endl;

    return 0;
}
