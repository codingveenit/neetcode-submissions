class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;

        for(int i = 0 ; i < n ; i++) {
            pq.push(stones[i]);
        }


        while(true) {
            if(pq.size() <= 1) break;
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            if(a == b) {
                continue;
            } else pq.push(a-b);
        }

        if(pq.empty()) {
            return 0;
        } else return pq.top();
        
    }
};
