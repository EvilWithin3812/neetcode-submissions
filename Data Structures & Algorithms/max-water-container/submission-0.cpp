class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int result = 0;
        while(i < j){
            int tower1H = heights[i];
            int tower2H = heights[j];
            int distBw = j - i;
            int minBw = min(tower1H, tower2H);
            result = max(result, distBw * minBw);
            if(tower1H < tower2H){
                i++;
            }else{
                j--;
            }
        }

        return result;
    }
};
