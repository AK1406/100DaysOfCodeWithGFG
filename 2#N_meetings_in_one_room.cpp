/*
N meetings in one room

There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] 
is finish time of meeting i.What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held 
in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4

Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)

*/



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int count =1;
        vector<pair<int,int>>meet;
        for(int i=0;i<n;i++){
            meet.push_back(make_pair(end[i],start[i]));
        }
        sort(meet.begin(),meet.end());
        int time_limit = meet[0].first;
        for(int i =1;i<n;i++){
            if(meet[i].second > time_limit){
                count++;
                time_limit = meet[i].first;
            }
        }
        return count;
    }
};
