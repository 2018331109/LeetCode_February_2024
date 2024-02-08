/*
279. Perfect Squares
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

*/
class Solution
{
public:
    int numSquares(int total)
    {
        vector<int>dp(total+1, total+1);
        int n=sqrt(total)+1;

        dp[0]=0;
        for(int i=1; i<=n; i++)
        {
            int coin=i*i;
            for(int now=coin; now<=total; now++)
            {
                dp[now]=min(dp[now], dp[now-coin]+1);
            }
            //cout<<dp[total]<<endl;
        }

        cout<<dp[total]<<endl;
        if(dp[total]==total+1)
        {
            return -1;
        }
        return dp[total];

    }
};

