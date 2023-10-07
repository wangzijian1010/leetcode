//
// Created by wangzijian on 2023/10/7.
//

#include "string"
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    // 链表的无参构造函数
    ListNode() : val(0), next(nullptr) {}
    // 链表的整数参数的构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    // 链表的两个有参的构造函数
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 初始化merge链表
        ListNode* head = nullptr;
        ListNode* tail = nullptr;


        // 访问list1的第一个节点
        ListNode* currentNode1 = list1;
        // 访问list2的第一个节点
        ListNode* currentNode2 = list2;

        // 先将长度相同的合并 更长的那一截直接拼上去就好了
        // 因为是递增链表
        while(currentNode1 != nullptr && currentNode2 != nullptr){
            // 将更小的设置为更前面
            int val;
            if (currentNode1->val > currentNode2->val)
            {
                val = currentNode2->val;
                currentNode2 = currentNode2->next;
            }
            else
            {
                // 不能用currentNode2++ 这个是很傻逼的写法 for循环用多了的表现
                // 要用next
                val = currentNode1->val;
                currentNode1 = currentNode1->next;
            }
            ListNode* newNode = new ListNode(val);
            if (head == nullptr){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = tail->next;
            }
        }

        // 处理l1剩余节点
        if (currentNode1 != nullptr){
            if (head == nullptr)
            {
                head = currentNode1;
            }else{
                tail->next = currentNode1;
            }
        }

        // 处理l2剩余节点
        if (currentNode2 != nullptr){
            if (head == nullptr)
            {
                head = currentNode2;
            }else{
                tail->next = currentNode2;
            }
        }

        return head;

    }
};

int main()
{
    // 初始化链表l1
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    // 初始化链表l2
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution solution;
    solution.mergeTwoLists(l1,l2);


    // 使用玩链表后要记得释放
}