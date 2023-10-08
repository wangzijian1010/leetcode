//
// Created by wangzijian on 2023/10/8.
//

# include "vector"
using namespace std;

class Solution {
public:
    // 方法1
    // 首先我的想法是使用遍历的方法来进行操作
    // 利用数组头指针和遍历指针
    // 如果遍历指针和头指针的值一样那么删除遍历指针的值 后面的直接往前面移动 并且数组长度减1
    // 先不能直接移动 直接移动之后数字会有变化

    // 方法1的做法有点复杂
    // 居然他说了是非严格递增那么肯定有用处
    // 这里默认第一个元素为单独的元素
    // 后面的元素与第一个相比较
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int k = 1; // 记录唯一元素的个数

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main()
{
    // 初始化数组
    int nums[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // 数组转为vector
    vector<int> vec(nums,nums+sizeof(nums) / sizeof(nums[0]));
    // 或者直接初始化vector
    vector<int> vec1 = {1,1,2};
    Solution solution;
    solution.removeDuplicates(vec);
}