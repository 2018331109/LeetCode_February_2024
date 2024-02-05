/*
1043. Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.
*/

class Solution
{
public:
    
    int call(int ind, vector<int>& nums, int k, vector<int>& dp)
    {
        int n=nums.size();
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int len=0;
        int mx=INT_MIN;
        int ans=INT_MIN;
        
        for(int j=ind;j<min(n, ind+k);j++)
        {
            len++;
            mx=max(mx, nums[j]);
            int sum=mx*len + call(j+1, nums, k, dp);
            ans=max(ans, sum);
            
        }
        
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>dp(n, -1);
        return call(0, nums, k, dp);
        
         

    }
};

