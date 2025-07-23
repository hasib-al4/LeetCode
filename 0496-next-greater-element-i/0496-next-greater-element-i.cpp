class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;
        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> ans;
        for(int num : nums1) {
            ans.push_back(mpp.count(num) ? mpp[num] : -1);
        } 
        return ans;
    }
};