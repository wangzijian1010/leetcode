//
// Created by wangzijian on 2023/10/7.
//

#include "string"
#include "vector"
#include <cstring>
#include "stack"
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        // 将字符串格式快速转化为字符数组
        const char* charArray = s.c_str();

        size_t len = std::strlen(charArray);

        // 如果是奇数的话那么肯定无法配对
        if (len%2)
            return false;
        // 初始化栈
        std::stack<char> parenthesesStack;
        // 其实也不用转化为字符数组使用while循环 使用for循环也是可以的
        for(char c : s){
            // 左括号入栈
            if (c == '(' || c == '{' || c=='[')
                parenthesesStack.push(c);
            else{
                // 如果是右括号 那么则要匹配 但是如果栈为空的话 那么只能为false
                if (parenthesesStack.empty())
                    return false;
                char top = parenthesesStack.top();
                // 栈顶指针往下移
                parenthesesStack.pop();

                // 判断右括号是否与栈顶的左括号匹配
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        // 栈为空代表所有的均已出栈 则代表匹配成功
        return parenthesesStack.empty();

    }
};

int main(){
    string test = "()";
    Solution solution;
    bool result= solution.isValid(test);
    int a = 0;
    return 0;
}