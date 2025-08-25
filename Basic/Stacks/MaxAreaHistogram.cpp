class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        vector<int> left(n);
        vector<int> right(n);

      // NSL
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else {
                left[i] = st.top().second;
            }
            st.push({heights[i], i});
        }
        while(!st.empty()){
            st.pop();
        }

      // NSR
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n;
            }
            else{
                right[i] = st.top().second;
            }
            st.push({heights[i], i});
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }
        return ans;
    }
};
