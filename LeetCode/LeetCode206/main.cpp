#include <iostream>
using namespace std;

/*
LeetCode206:反转链表
给你单链表的头节点head,请你反转链表，并返回反转后的链表
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    //寻找递归终止条件
    //1 head指向的结点为NULL
    //2 head指向的结点的下一个结点为NULL
    //在这两种情况下，反转之后的结果还是它自己本身
    if (head == NULL || head->next == NULL) {
        return head;
    }

    //不断的通过递归调用，直到无法递归下去，递归的最小粒度是在最后一个结点
    //因为到最后一个结点的时候，由于当前结点head的next结点为空，所以会直接返回head
    ListNode* cur = reverseList(head->next);

    //比如原链表为1->2->3->4->5->NULL
    //5->4
    //第一次执行下面代码的时候，head为4,那么head.next=5
    //那么head.next.next就是5.next,意思就是去设置5的下一个结点
    //符号右侧为head,意思就是设置5的下一个结点是4
    head->next->next = head;

    //head原来的下一个结点指向自己，所以head自己本身就不能再指向原来的下一个结点
    //否则会发生无线循环
    head->next = NULL;

    //我们把每次反转后的结果传递给上一层
    return cur;
}

int main() {
    // 创建链表
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
   
    ListNode* retNode = reverseList(head);

    while (retNode != NULL) {
        cout << retNode->val << " ";
        retNode = retNode->next;
    }
    cout << endl;
	return 0;
}