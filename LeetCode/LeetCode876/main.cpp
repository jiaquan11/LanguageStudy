#include <stdio.h>

/*
����һ��ͷ�ڵ�Ϊhead�ķǿյ���������������м�ڵ�
����������м�ڵ㣬�򷵻صڶ����м�ڵ�
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    //��������ָ�룬һ��ʼ��ָ�������ͷ�ڵ�
    ListNode* slow = head;
    ListNode* fast = head;
    //����������������ָ����ǰ�ƶ�
    //��������ƶ�����ô�ͻ��ÿ�ָ��ÿ���ƶ���������ָ��ÿ���ƶ�һ��
    //����ָ������ƶ�������ǰ����ǵ�ǰ�ڵ㲻Ϊ�գ�ͬʱ��һ�ڵ�Ҳ��Ϊ��
    //�������ܱ�֤fast->next��ֵ��fast->next->next��ֵ
    while (fast != NULL && fast->next != NULL) {
        //��ָ��ÿ���ƶ�һ��
        slow = slow->next;
        //��ָ��ÿ���ƶ�����
        fast = fast->next->next;
    }

    //���slowָ��ľ����м�ڵ�
    return slow;
}

// ʵ������������
int main() {
    // ��������
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

    // ���ú���
    ListNode* middle = middleNode(head);
    printf("middle->val: %d\n", middle->val);
    return 0;
}