class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> um;

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0]; 
            int v = times[i][1];
            int wt = times[i][2];

            um[u].push_back({v, wt});
            
            
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k]= 0;

        while(!pq.empty()){
            auto pa = pq.top();
            pq.pop();
            int node = pa.second;
            int time = pa.first;

            if(dist[node] < time)
                continue;

            for(const auto& xd : um[node]){
                int neighbour = xd.first;
                int wt = xd.second;

                if(time + wt < dist[neighbour]){
                    dist[neighbour] = time + wt;
                    pq.push({dist[neighbour], neighbour});
                }
            }

        } 
        int ans= 0;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;

    }
};
