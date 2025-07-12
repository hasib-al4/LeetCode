class Solution {
public:
    void powerSet(int ind, vector<int> nums, vector <vector<int>> &ans, vector<int> temp, int n) {
        
            ans.push_back(temp);
        
        for(int i = ind; i < n; i++) {
            if(i != ind && nums[i]==nums[i - 1]) continue;
            temp.push_back(nums[i]);
        powerSet(i + 1, nums, ans, temp, n);
        temp.pop_back();
        


        }
        


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector <vector<int>> ans;
        vector<int> temp;
        
        powerSet(0,nums,ans,temp, n);
        
        return ans;
    }
};