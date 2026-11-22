class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> um;
        for(string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            um[key].push_back(str);
        }

        for(auto& [key, value] : um){
            result.push_back(value);
        }
        return result;
        



    }
};
