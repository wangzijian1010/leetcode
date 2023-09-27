//
// Created by wangzijian on 2023/9/27.
//
#include "string"
#include "map"
#include "iostream"
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // 创建字典键值对
        map<char,int> myDict;
        myDict['I'] = 1;
        myDict['V'] = 5;
        myDict['X'] = 10;
        myDict['L'] = 50;
        myDict['C'] = 100;
        myDict['D'] = 500;
        myDict['M'] = 1000;

        // 首先要将输入的字符串转化为字符数组
        const char* charArray = s.c_str();
        const char*bakupArray = charArray;
        int finalNum = 0;
        while (*charArray){
            // 出现4种情况的处理
            if (myDict[*charArray] < myDict[*(charArray + 1)])
            {
                // myDict[*charArray] = 0 - myDict[*charArray];
                int currNum =  0 - myDict[*charArray];
                finalNum = finalNum + currNum;
                charArray++;
                continue;
            }
            // 未出现4种情况的处理

            finalNum = myDict[*charArray] + finalNum;

            charArray++;
        }
        return finalNum;

    }
};

int main()
{
    Solution solution;
    int num = solution.romanToInt("MCMXCIV");
    std::cout<<num<<endl;
}