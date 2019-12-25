
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    if(candidates.empty()){
        return result;
    }
    sort(candidates.begin(), candidates.end());
    vector<int> combination;
    helper(candidates, target, result, combination, 0);

    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return result;
}


    void helper(vector<int>& candididates, int target,
                           vector<vector<int> >& result, vector<int>& combination, int begin){
    if(target == 0){
        result.push_back(combination);
        return;
    }
    for (int i = begin; i < candididates.size() && target >= candididates[i]; ++i) {
        combination.push_back(candididates[i]);
        helper(candididates, target - candididates[i], result, combination, i);
        combination.pop_back();
    }
    return;
}
