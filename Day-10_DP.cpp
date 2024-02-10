/*
647. Palindromic Substrings
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
*/
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            ans++;
            if(i+1<n and s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                ans++;
            }
        }
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len<n;i++)
            {
                if(dp[i+1][i+len-1] and s[i]==s[i+len])
                {
                    dp[i][i+len]=1;
                    ans++;
                }
            }
        }        
        return ans;
        

    }
};

