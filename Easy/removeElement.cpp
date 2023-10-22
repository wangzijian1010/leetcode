//
// Created by wangzijian on 2023/10/22.
//

#include "string"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        // 利用双指针法将不等于val的值放到前方
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};


int main(){
    vector<int> test= {3,2,2,3};
    Solution solution;
    int result = solution.removeElement(test,3);
    cout<<"hello"<<endl;
    return 0;
}