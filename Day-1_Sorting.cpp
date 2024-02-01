/*
2966. Divide Array Into Arrays With Max Difference

You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:

    Each element of nums should be in exactly one array.
    The difference between any two elements in one array is less than or equal to k.

Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

SUBMISSION IN C++
*/

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
         vector<vector<int>>ans;
        int n=nums.size();
        if(n%3 || n==0)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        
        int l=0, r=2;
        while(r<n)
        {
            vector<int>v;
            if(nums[r]-nums[l]>k)
            {
                return {};
            }
            while(l<=r)
            {
                v.push_back(nums[l++]);
            }
            ans.push_back(v);
            r+=3;
            
        }
        
        return ans;

    }
};

