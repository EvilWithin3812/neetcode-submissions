class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int N = nums.size();

        for(int i = 0; i < N; i++){
            um[nums[i]] = i;
        }
        vector<int> result;
        for(int i = 0; i < N; i++){
            int temp = target - nums[i];
            if(um.count(temp)){
                if(i != um[temp]){
                    result.push_back(i);
                    result.push_back(um[temp]);
                    break;
                }
                
            }
        }
        return result;

    }
};
