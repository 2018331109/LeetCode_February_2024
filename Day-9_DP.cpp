/*
368. Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.
*/
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int>dp(n, 1);
        vector<int>v;
        int ans=1;
        int en=0;
        for(int i=0;i<n;i++)
        {
            int cur=nums[i];
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0)
                {
                    dp[i]=max(dp[j]+1, dp[i]);
                    if(ans<dp[i])
                    {
                        //cout<<ans<<endl;
                        ans=dp[i];
                        en=i;
                    }
                }
            }
        }
        int last=-1;
        //v.push_back(nums[en]);
        cout<<ans<<endl;
        
        for(int i=n-1;i>=0;i--)
        {
            if(ans==dp[i] and (last==-1 || !(last%nums[i])))
            {
                v.push_back(nums[i]);
                last=nums[i];
                ans--;
            }
        }
        return v;
        

    }
};

