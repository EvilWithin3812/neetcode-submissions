class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            um[nums[i]]++;
        }
        vector<int> result;

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto& [key, val] : um){
            pq.push({val, key});
        }

        while(k--){
            auto xd = pq.top();
            pq.pop();
            result.push_back(xd.second);
        }

        return result;



    }
};
