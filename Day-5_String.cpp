/*
387. First Unique Character in a String
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n=s.size();
        vector<int>v(26, 0);
        for(int i=n-1;i>=0;i--)
        {
            v[s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            if(v[s[i]-'a']==1)
            {
                return i;
            }
        }
        
        return -1;

    }
};

