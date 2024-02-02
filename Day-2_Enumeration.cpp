/*

1291. Sequential Digits
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

SUBMISSION IN C++
*/

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int>ans;
        //starting digit;
        for(int i=1; i<=9; i++)
        {
            int num=i;
            int next=i+1;
            while(num<=high and next<=9)
            {
                num=num*10+next;
                if(num>=low and num<=high)
                {
                    ans.push_back(num);
                }
                next++;
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};

