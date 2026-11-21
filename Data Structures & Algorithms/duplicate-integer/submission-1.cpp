class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int N = nums.size();
        set<int> st;
        for(int i = 0; i < N; i++){
            if(st.count(nums[i]))
                return true;
            else
                st.insert(nums[i]);
        }
        return false;
    }
};