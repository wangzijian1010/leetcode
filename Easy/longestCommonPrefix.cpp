//
// Created by wangzijian on 2023/10/6.
//

#include "string"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string> longestStr={};
        // 如果字符串为空 那么直接返回无最长字符串
        if (strs.empty())
            return "";

        // 将字符串第一个设置为最长字串
        std::string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            // 如果当前为空 则也返回空的最长字符串
            if (strs[i].empty())
                return "";

            int j=0;
            // 判断条件
            while (j<prefix.length() && j<strs[i].length() && prefix[j]==strs[i][j]){
                j++;
            }

            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};

int main(){
    vector<string> test = {"flower","flow","flight"};
}