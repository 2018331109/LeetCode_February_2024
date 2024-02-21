/*
268. Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto it:nums)
        {
            sum+=it;
        }
        int total=(n*(n+1))/2;
        return total-sum;
        
    }
};
