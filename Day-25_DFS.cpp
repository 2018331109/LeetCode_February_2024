/*
2709. Greatest Common Divisor Traversal
You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

Return true if it is possible to traverse between all such pairs of indices, or false otherwise.
*/
#define pb push_back
const int N=100005;
class Solution
{
public:
    static const int N=100005;
    vector<int>p2i[N], i2p[N], check;
    unordered_map<int, bool>mp;
     
    int n;
    void p_fact(int x, int ind)
    {
        int vl=x;
        for(int i=2; i*i<=x; i++)
        {
            if(x%i==0)
            {
                i2p[ind].pb(i);
                p2i[i].pb(ind);
                while(x%i==0)
                {
                    x/=i;
                }
            }
        }
        if(x>1)
        {
            i2p[ind].pb(x);
            p2i[x].pb(ind);
        }
    }

    void dfs(int now)
    {
        if(check[now])
        {
            return;
        }
        check[now]=1;
        for(auto prime:i2p[now])
        {
            if(mp[prime])
            {
                continue;
            }
            mp[prime]=true;

            for(auto it:p2i[prime])
            {
                if(check[it])
                {
                    continue;
                }
                dfs(it);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums)
    {

        n=nums.size();
        check.assign(n, 0);
        for(int i=0; i<n; i++)
        {
            int it=nums[i];
            p_fact(it, i);
        }

        dfs(0);

        for(int i=0; i<n; i++)
        {
            if(!check[i])
            {
                return false;
            }
        }

        return true;

    }
};

