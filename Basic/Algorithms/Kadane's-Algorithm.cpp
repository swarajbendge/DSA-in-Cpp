// To find mximum sum of a contigous sub-array.



int maxSum(vector<int> &arr){
  long long maxSum = LONG_MIN;
  long long sum = 0;

  for(int i = 0; i < arr.size(); i++){
      sum += arr[i];
      maxSum = max(maxSum, sum);
      if(sum < 0) sum = 0;
  }
  return maxSum;
}
