//
// Created by wangzijian on 2023/9/26.
//

#include "vector"
#include "algorithm"

class Solution {
public:
    bool isPalindrome(int x) {
        // 负数直接返回0
        if (x<0) return false;
        int temp = 0;
        int bakup = x;
        // 实现数字逆序操作
        while (x){
            temp = x % 10 + temp * 10;
            x = x / 10;
        }
        if (bakup == temp){
            return true;
        } else{
            return false;
        }

    }
};

int main(){
    Solution solution;
    bool test = solution.isPalindrome(101);


}
