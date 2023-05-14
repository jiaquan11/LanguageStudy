#include <stdio.h>

/*
给定一个头节点为head的非空单链表，返回链表的中间节点
如果有两个中间节点，则返回第二个中间节点
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    //设置两个指针，一开始都指向链表的头节点
    ListNode* slow = head;
    ListNode* fast = head;
    //接下来，让这两个指针向前移动
    //如果可以移动，那么就会让快指针每次移动两步，慢指针每次移动一步
    //而快指针可以移动两步的前提就是当前节点不为空，同时下一节点也不为空
    //这样才能保证fast->next有值，fast->next->next有值
    while (fast != NULL && fast->next != NULL) {
        //慢指针每次移动一步
        slow = slow->next;
        //快指针每次移动两步
        fast = fast->next->next;
    }

    //最后slow指向的就是中间节点
    return slow;
}

// 实现主函数调用
int main() {
    // 创建链表
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);

    // 调用函数
    ListNode* middle = middleNode(head);
    printf("middle->val: %d\n", middle->val);
    return 0;
}