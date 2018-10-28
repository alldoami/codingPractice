class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indeces;
        vector<int> result;
        for(int i = 0; i < nums.size(); i ++){
            int diff = target - nums[i];
            if(indeces.find(nums[i]) != indeces.end()){
                result.push_back(indeces.at(nums[i]));
                result.push_back(i);
                return result;
            }
            indeces.insert({diff, i});
        }
        return result;
    }
};