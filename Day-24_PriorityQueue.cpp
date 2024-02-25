/*
2092. Find All People With Secret
You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.
*/
class Solution
{
public:
#define pii pair<int, int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        vector<pair<int, int>>graph[n];
        
        for(auto it:meetings)
        {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>>pq;
         
        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<int>visited(n, 0);
        vector<int>ans;
        while(!pq.empty())
        {
            auto [time, person]=pq.top();
            pq.pop();
            if(visited[person])
            {
                continue;
            }
            visited[person]=1;
             
                for(auto it:graph[person])
                {
                    if(!visited[it.first] and it.second>=time)
                    {
                        pq.push({it.second, it.first});
                    }
                    
                }
 
        }

       for(int i=0;i<n;i++)
       {
           if(visited[i])
           {
               ans.push_back(i);
           }
       }
        return ans;

    }
};

