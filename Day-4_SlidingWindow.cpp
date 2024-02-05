/*
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window
substring
of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/
class Solution
{
public:
    string minWindow(string s, string t)
    {
    vector<int> vs(60, 0), vt(60, 0);
    for (auto it : t)
    {
        vt[it - 'A']++;
    }

    int ans = INT_MAX, l = 0, r = 0, st = -1, n = s.size();
    while (r < n)
    {
        vs[s[r] - 'A']++;
        int f = 1;
        while (f)
        {
            for (int i = 0; i < 60; i++)
            {
                //cout<<vs[i]<<" "<<vt[i]<<endl;
                if (vs[i] < vt[i])
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                if (r - l + 1 < ans)
                {
                    st = l;
                    ans = r - l + 1;
                }
                
                    vs[(s[l++] - 'A')]--;
                
            }
            //cout<<l<<" "<<r<<endl;
        }
        r++;
    }

    if (st != -1)
    {
        return s.substr(st, ans);
    }
    else
    {
        return "";
    }

    }
};

