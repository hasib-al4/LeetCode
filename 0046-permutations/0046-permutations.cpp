class Solution {
public:
    void per(vector<int> nums, vector<int> &ds, vector<int> &mp, vector<vector<int>> &ans) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(mp[i] != 1) {
                ds.push_back(nums[i]);
                mp[i] = 1;
                per(nums, ds, mp, ans);
                mp[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<int> mp(nums.size(), 0);
        vector<vector<int>> ans;
        per(nums, ds, mp, ans);
        return ans;
    }
};