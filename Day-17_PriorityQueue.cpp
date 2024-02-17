/*
1642. Furthest Building You Can Reach
You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

    If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
    If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.

Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.
*/
class Solution
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        int n=heights.size();
        int sum=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        int i=0;
        for(i=1;i<n;i++)
        {
            int dif=heights[i]-heights[i-1];
            if(dif>0)
            {
                if(pq.size()<ladders)
                {
                    pq.push(dif);
                }
                else if (!pq.empty())
                {
                    int tp=pq.top();
                    if(tp<dif)
                    {
                        pq.pop();
                        sum+=tp;
                        pq.push(dif);
                    }
                    else
                    {
                        sum+=dif;
                    }
                }
                else
                {
                    sum+=dif;
                }
            }
            
            if(sum>bricks)
            {
                break;
            }

            
        }

        return i-1;

    }
};

