#include <iostream>
using namespace std;

/*
LeetCode21:合并两个有序链表
将两个升序链表合并为一个新的升序链表并返回，新链表是通过拼接给定的两个链表的所有节点组成的
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }

    ListNode(int x, ListNode* next) {
        this->val = x;
        this->next = next;
    }
};

ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
    //一开始设置一个虚拟节点，它的值为-1，它的值可以设置为任何的数，因为我们根本不需要使用它的值
    ListNode* dummy = new ListNode(-1);

    //设置一个指针，指向虚拟节点
    ListNode* pre = dummy;

    //通过一个循环，不断地比较L1和L2中当前节点值地大小，直到L1或L2遍历完毕为止
    while ((L1 != NULL) && (L2 != NULL)) {
        //如果L1当前节点的值小于等于L2当前节点的值
        if (L1->val <= L2->val) {
            //让pre指向节点的next指针指向这个更小值的节点
            //即指向L1
            pre->next = L1;
            //让L1向后移动
            L1 = L1->next;
        } else {
            //让pre指向节点的next指针指向这个更小值的节点
            //即指向L2
            pre->next = L2;
            //让L2向后移动
            L2 = L2->next;
        }
        //让pre向后移动
        pre = pre->next;
    }

    //跳出循环后，L1或者L2中间可能有剩余的节点没有被观察过
    //直接把剩下的节点加入到pre的next指针位置

    //如果L1中还有节点
    if (L1 != NULL) {
        //把L1中剩下的节点全部加入到pre的next指针位置
        pre->next = L1;
    }

    //如果L2中还有节点
    if (L2 != NULL) {
        //把L2中剩下的节点全部加入到pre的next指针位置
        pre->next = L2;
    }

    //最后返回虚拟节点的next指针
    return dummy->next;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode* retNode = mergeTwoLists(head1, head2);
    while (retNode != NULL) {
        cout << retNode->val << " ";
        retNode = retNode->next;
    }
    cout << endl;
	return 0;
}