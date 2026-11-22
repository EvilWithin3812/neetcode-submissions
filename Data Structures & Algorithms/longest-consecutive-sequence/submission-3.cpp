class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        set<int> st;
        for(auto xd : nums){
            st.insert(xd);
        }

        int prev = *st.begin();
        st.erase(st.begin());
        int count = 1;
        int ans = 1;
        while(!st.empty()){
            int temp = *st.begin();
            st.erase(st.begin());
            if(prev+1 == temp){
                count++;
                ans = max(ans, count);
                prev = temp;
            }
            else{
                count = 1;
                prev = temp;
            }
        }

        return ans;
    }
};
