#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combination(candidates, target, tmp, 0, 0);
        return result;
    }
    void combination(std::vector<int>& candidates, int& target, std::vector<int>& tmp, int sum, int index) {
        if (sum == target) {
            result.push_back(tmp);
            return;
        }
        else if (sum > target) {
            return;
        }
        for (int i = index;i < candidates.size();i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            tmp.push_back(candidates[i]);
            combination(candidates, target, tmp, sum + candidates[i], i + 1);
            tmp.pop_back();
        }
    }
};