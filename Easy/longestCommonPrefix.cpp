//
// Created by wangzijian on 2023/9/28.
//

#include "string"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 如果传入的字符串为空则直接返回空字符串
        if (strs.empty())
            return "";
        // 获取字符数组长度
        int length = strs.size();
        // 定义初始的公共字符串
        string prefix = strs[0];
        for (int i = 1; i < length; i++) {
            string& current = strs[i];
            size_t j = 0;
            while (j < current.length() && j < prefix.length() && current[j] == prefix[j]){
                j++;
            }
            // 更新前缀
            prefix = prefix.substr(0,j);

            if (prefix.empty())
                break;
        }
        return prefix;
    }
};

int main(){
    vector<string> test={"flowers","flow","flight"};
    Solution solution;

    string result = solution.longestCommonPrefix(test);
    std::cout << "Longest common prefix: " << result << std::endl;

}