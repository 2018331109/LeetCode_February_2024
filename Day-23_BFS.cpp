/*
787. Cheapest Flights Within K Stops
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>>graph(n);
        for(auto it:flights)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int>dist(n, INT_MAX);
        queue<pair<int, int>>q;
        q.push({src, 0});
        int stops=0;

        while(stops<=k and !q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto [node, d]=q.front();
                q.pop();
                for(auto [adj, price]:graph[node])
                {
                    if(price+d>=dist[adj])
                    {
                        continue;
                    }
                    dist[adj]=price+d;
                    q.push({adj, dist[adj]});
                }
            }
            stops++;
        }

        return dist[dst]==INT_MAX? -1: dist[dst];

    }
};

