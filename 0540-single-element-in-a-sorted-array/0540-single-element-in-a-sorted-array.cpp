class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xox = nums[0];
        for(int i = 1; i < n; i++) {
             xox = xox ^ nums[i];
        }
        return xox;
    }
};