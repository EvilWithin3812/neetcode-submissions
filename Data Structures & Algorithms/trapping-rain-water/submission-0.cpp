class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        vector<int> greaterRight(N, -1);
        vector<int> greaterLeft(N, -1);
        //calculating greaterRight
        int maxi = height[N-1];
        for(int i = N-2; i >= 0; i--){
            if(height[i] <= maxi){
                greaterRight[i] = maxi;
            }
            maxi = max(maxi, height[i]);
        }

        //calculating greaterLeft
        maxi = height[0];
        for(int i = 1; i < N; i++){
            if(height[i] < maxi){
                greaterLeft[i] = maxi;
            }
            maxi = max(maxi, height[i]);
        }

        int ans = 0;
        for(int i = 0; i < N; i++){
            if(greaterLeft[i] == -1 || greaterRight[i] == -1)
                continue;

            int maxH = min(greaterLeft[i], greaterRight[i]);
            ans += (maxH - height[i]);
        }

        return ans;


    }
};
