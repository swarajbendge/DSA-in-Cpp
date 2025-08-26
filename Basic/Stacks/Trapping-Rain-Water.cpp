// Trapping Rain Water
// 1. Two pointer approach (constant space)

int trap(vector<int>& height) {
    int n = height.size();
    int start = 0;
    int end = n - 1;
    int leftMax = 0, rightMax = 0, ans = 0;

    while (start < end) {
        if (height[start] <= height[end]) {
            if (height[start] > leftMax) {
                leftMax = height[start];
            } else {
                ans += leftMax - height[start];
            }
            start++;
        } else {
            if (height[end] > rightMax) {
                rightMax = height[end];
            } else {
                ans += rightMax - height[end];
            }
            end--;
        }
    }
    return ans;
}


// 2. prefix/suffix array

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> maxLeft(n);
    vector<int> maxRight(n);
    
    maxLeft[0] = height[0];
    for(int i = 1; i < n; i++){
        maxLeft[i] = max(maxLeft[i - 1], height[i]);
    }

    maxRight[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 0; i--){
        maxRight[i] = max(maxRight[i + 1], height[i]);
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        int water = min(maxLeft[i], maxRight[i]) - height[i];
        sum += water;
    }
    return sum;
}
