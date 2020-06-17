vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
      if (groupSizes.empty()) {
          return vector<vector<int> >();
      }
      vector<vector<int> > res;
      int len = groupSizes.size();
      vector<vector<int> > group(len+1, vector<int>()); // +1 为了适应{1}, 否则会报错
      for (int i = 0; i < len; ++i) {
          group[groupSizes[i]].push_back(i);
          if (group[groupSizes[i]].size() == groupSizes[i]) {
              res.push_back(group[groupSizes[i]]);
              group[groupSizes[i]] = {};
          }
      }

      return res;
  }
