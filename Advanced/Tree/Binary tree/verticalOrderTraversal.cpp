class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            mp[x][y].push_back(node->val);
            
            if(node->left)  q.push({node->left, {x - 1, y + 1}});
            if(node->right) q.push({node->right, {x + 1, y + 1}});
        }
        
        vector<vector<int>> ans;
        for(auto &x : mp){
            vector<int> level;
            for(auto &y : x.second){
                auto &v = y.second;
                sort(v.begin(), v.end());
                level.insert(level.end(), v.begin(), v.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};
