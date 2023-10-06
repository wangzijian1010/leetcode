//
// Created by wangzijian on 2023/9/25.
//

#include "vector"
#include <unordered_map>
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.count(complement)) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector nums = {2,7,11,15};
    Solution solution;
    int target = 13;
    solution.twoSum(nums,target);
    std::cout<<"hello sum"<<std::endl;

}