
///////////////////////////////
// Popular problems on Stack //
///////////////////////////////


// Nearest Greater to Right 
vector<int> NGR(vector<int>& nums){
    int n = nums.size();    
    vector<int> ans(n, -1);
    stack<int> st;

for(int i = n - 1; i >= 0; i--){
    while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}


// Nearest greater to left
vector<int> NGL(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}



//Nearest smaller to left
vector<int> NSL(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}



//Nearest smaller to right
vector<int> NSR(vector<int>& nums){
int n = nums.size();    
vector<int> ans(n, -1);
stack<int> st;

for(int i = n - 1; i >= 0; i--){
    while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }   
        st.push(nums[i]);
    }
    return ans;
}
