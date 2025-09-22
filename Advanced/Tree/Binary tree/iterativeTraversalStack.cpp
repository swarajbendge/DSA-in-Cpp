//  ** preorder iterative traversal using stack  ** //

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }   
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            ans.push_back(root -> val);
            if(root -> right != NULL){
                st.push(root -> right);
            }
            if(root -> left != NULL){
                st.push(root -> left);
            }
        }
      return ans;
  }

// ** inorder iterative traversal using stack ** //

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(true){
            if(node != NULL) {
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                ans.push_back(node -> val);
                node = node -> right;
            }
        }
        return ans;
    }


// ** postorder iterative traversal using stack ** //
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root -> left != NULL){
                st1.push(root -> left);
            }
            if(root -> right != NULL){
                st1.push(root -> right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top() -> val);
            st2.pop();
        }
        return ans;
    }
