/*
451. Sort Characters By Frequency
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        priority_queue<pair<int, char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second, it.first});
        }
        s="";
        while(!pq.empty())
        {
            s+=string(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        return s;

    }
};

