// *** breadth first search traversal in graph *** //

vector<int> bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> vis(n);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bf;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bf.push_back(node);
        for(auto x : adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    return bf;
}


// *** Depth First Traversal *** //

  private:
    void check(vector<vector<int>>& adj, vector<int>& vis, int node, vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto x : adj[node]){
            if(!vis[x]){
                check(adj, vis, x, ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        check(adj, vis, 0, ans);
        return ans;
    }
