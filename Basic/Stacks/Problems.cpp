
///////////////////////////////
// Popular problems on Stack //
///////////////////////////////

// Nearest Greater to Right 

vector<int> NGR(vector<int>& nums){
int n = nums.size();    vector<int> ans(n, -1);
stack<int> st;

for(int i = n - 1; i >= 0; i--){
    while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(ans[i]);
    }
    return ans;
}
