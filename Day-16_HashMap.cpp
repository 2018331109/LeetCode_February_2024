/*
1481. Least Number of Unique Integers after K Removals
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>&nums, int k) {
         unordered_map<int, int>mp;
    int kk=0,cnt=0;
    priority_queue<int, vector<int>, greater<int>>pq;

    for(auto it:nums)
    {
        mp[it]++;
    }
    for(auto it:mp)
    {
        pq.push(it.second);
        cnt++;
    }
    while(kk<k)
    {
        kk+=pq.top();
        pq.pop();
        cnt--;
    }

    if(kk>k)
    {
        cnt++;
    }

    cout<<cnt<<endl;
    return cnt;
        
    }
};
