/*
2402. Meeting Rooms III
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

    Each meeting will take place in the unused room with the lowest number.
    If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
    When a room becomes unused, meetings that have an earlier original start time should be given the room.

Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.
*/
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>>available;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>>busy;

        vector<int>ans(n, 0);

        sort(meetings.begin(), meetings.end());
        for(int i=0;i<n;i++)
        {
            available.push(i);
        }
        for(auto it:meetings)
        {
            int st=it[0], en=it[1];
            while(busy.size()>0 and busy.top().first<=st)
            {
                available.push(busy.top().second);
                busy.pop();
            }
            if(available.size()>0)
            {
                int tp=available.top();
                ans[tp]++;
                available.pop();
                busy.push({en, tp});
                continue;
            }
            auto tp=busy.top();
            int next_time=tp.first;
            int ind=tp.second;
            busy.pop();
            ans[ind]++;
            busy.push({tp.first+en-st, ind});
        }
        int mx=max_element(ans.begin(), ans.end())-ans.begin();
        return mx;
    }
};
