class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int N = nums.size();
        bool zeroPresent = false;
        bool multipleZeroPresent = false;
        bool flag = false;

        for(int i = 0; i < N; i++){
            if(nums[i] == 0 && flag == false){
                zeroPresent = true;
                flag = true;
                continue;
            }
            else if(nums[i] == 0 && flag == true){
                multipleZeroPresent = true;
                continue;
            }
            else{
                totalProduct *= nums[i];
            }
        }

        vector<int> ans;
        if(multipleZeroPresent == true){
            ans.assign(N, 0);
            return ans;
        }

        if(zeroPresent == true){
            ans.assign(N, 0);
            for(int i = 0; i < N; i++){
                if(nums[i] == 0){
                    ans[i] = totalProduct;
                }
            }

            return ans;
        }

        for(int i = 0; i < N; i++){
            int temp = totalProduct;
            int temp2 = temp / nums[i];
            ans.push_back(temp2);
        }

        return ans;
    }
};
