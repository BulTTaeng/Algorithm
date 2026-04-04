class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> m;

        for (int i = 0; i<nums.size(); i++) {
            m.insert({nums[i], i});
        }

        for (int i = 0; i<nums.size(); i++) {
            int curr = nums[i];
            int diff = target - curr;

            auto it = m.find(diff);
            if (it != m.end()) {
                int foundedValue = it -> second;
                if (foundedValue != i) {
                    ans.push_back(i);
                    ans.push_back(foundedValue);
                    break;
                }
            }
        }

        return ans;
    }
};
