class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>, vector<string>> um;
        for(string str : strs){
            vector<int> count(26, 0);
            
            for(char xd : str){
                count[xd - 'a']++;
            }

            um[count].push_back(str);
        }

        for(auto& [key, value] : um){
            result.push_back(value);
        }
        return result;
        



    }
};
