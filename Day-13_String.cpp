/*
2108. Find First Palindromic String in the Array
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/
class Solution
{
public:
    string firstPalindrome(vector<string>& words)
    {
        for(auto it:words)
        {
            
            int i=0, j=it.size()-1;
            while(i<j)
            {
                if(it[i]==it[j])
                {
                    i++, j--;
                }
                else
                {
                    break;
                }
            }
            if(i>=j)
            {
                return it;
            }
        }
        return "";

    }
};


