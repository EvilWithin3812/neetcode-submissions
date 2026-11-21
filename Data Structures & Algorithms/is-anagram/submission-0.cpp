class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        int N = s.size();
        unordered_map<char, int> um;
        for(int i = 0; i < N; i++){
            um[s[i]]++;
        }

        for(int i = 0; i < N; i++){
            if(um.count(t[i])){
                um[t[i]]--;
                if(um[t[i]] == 0){
                    um.erase(t[i]);
                }
            }
            else{
                return false;
            }
        }

        if(um.size() == 0)
            return true;
        return false;
    }
};
