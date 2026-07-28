/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> meets;
        for(int i = 0 ; i < intervals.size() ; i++) {
            meets.push_back({intervals[i].start, +1});
            meets.push_back({intervals[i].end, -1});
        }

        sort(meets.begin(), meets.end());

        int ans = 0;
        int curr = 0;

        for(int i = 0 ; i < meets.size(); i++) {
            curr += meets[i].second;
            ans = max(ans, curr);
        }

        return ans;
        
    }
};
