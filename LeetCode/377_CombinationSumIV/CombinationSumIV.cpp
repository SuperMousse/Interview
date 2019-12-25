//combination[4] = combination[4-1] + combination[4-2] + combination[4-3] 
                 = combination[3] + combination[2] + combination[1].

int combinationSum4(vector<int>& nums, int target) {
    if(nums.empty()){
        return 0;
    }
    vector<unsigned int> combination(target + 1, 0);
    combination[0] = 1;
    for (int i = 1; i < combination.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if(nums[j] <= i) {
                combination[i] += combination[i - nums[j]];
            }
        }
    }
    return combination[target];
}
