class Solution {
public:
void combinations(int ind, int target, vector<int> candidates, vector<int> &ds, vector<vector<int>> &ans, int n) {
    if(ind == n) {
        if(target == 0) ans.push_back(ds);
        return;
    }
    if(candidates[ind] <= target) {
        ds.push_back(candidates[ind]);
        combinations(ind, target - candidates[ind], candidates, ds, ans, n);
        ds.pop_back();
    }
    combinations(ind + 1, target, candidates, ds, ans, n);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        combinations(0, target, candidates, ds, ans, n);
        return ans;
    }
};