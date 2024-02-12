/*
169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        int cnt=0, ans=0;
        unordered_map<int, int>mp;
        for(auto it:nums)
        {
            mp[it]++;
            if(mp[it]>cnt)
            {
                cnt=mp[it];
                ans=it;
            }
        }
        
        return ans;

    }
};

