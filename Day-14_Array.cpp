/*
2149. Rearrange Array Elements by Sign
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

    Every consecutive pair of integers have opposite signs.
    For all integers with the same sign, the order in which they were present in nums is preserved.
    The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=0;
        int cnt=0;
        vector<int>ans;
        while(cnt<(n/2))
        {
            while(nums[l]<0)
            {
                l++;
            }
            ans.push_back(nums[l]);
            l++;
            while(nums[r]>0)
            {
                r++;
            }
            ans.push_back(nums[r]);
            r++;

            cnt++;
        }

        return ans;
        
    }
};
