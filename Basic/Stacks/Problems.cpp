
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






// Stock span problem 
// idea is to find NGL, and stop as soon as you find it
// find the differences of the index b/w current index and NGL index
vector<int> spanProblem(vector<int>& nums){
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> idx(n);
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top().first <= nums[i]){
            st.pop();
        }
        if(st.empty()){
            idx[i] = -1;
        }
        else{
            idx[i] = st.top().second;
        }
        st.push({nums[i], i});
    }
    for(int i = 0; i < n; i++){
        ans[i] = i - idx[i];
    }
    return ans;
}
