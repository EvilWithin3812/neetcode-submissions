class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size();
        if(N == 0)
            return 0;
        int i = 0;
        int j = 0;
        int ans = 1;
        unordered_map<char, int> um;
        while(j < N){
            if(um.count(s[j])){
                while(!um.empty() && s[i] != s[j]){
                    um.erase(s[i]);
                    i++;
                }
                um.erase(s[i]);
                i++;
            }
            um[s[j]]++;
            ans = max(ans,(int) um.size());
            j++;
        }

        return ans;
    }
};
