#include <iostream>
using namespace std;

/*
LeetCode21:�ϲ�������������
��������������ϲ�Ϊһ���µ������������أ���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
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
    //һ��ʼ����һ������ڵ㣬����ֵΪ-1������ֵ��������Ϊ�κε�������Ϊ���Ǹ�������Ҫʹ������ֵ
    ListNode* dummy = new ListNode(-1);

    //����һ��ָ�룬ָ������ڵ�
    ListNode* pre = dummy;

    //ͨ��һ��ѭ�������ϵرȽ�L1��L2�е�ǰ�ڵ�ֵ�ش�С��ֱ��L1��L2�������Ϊֹ
    while ((L1 != NULL) && (L2 != NULL)) {
        //���L1��ǰ�ڵ��ֵС�ڵ���L2��ǰ�ڵ��ֵ
        if (L1->val <= L2->val) {
            //��preָ��ڵ��nextָ��ָ�������Сֵ�Ľڵ�
            //��ָ��L1
            pre->next = L1;
            //��L1����ƶ�
            L1 = L1->next;
        } else {
            //��preָ��ڵ��nextָ��ָ�������Сֵ�Ľڵ�
            //��ָ��L2
            pre->next = L2;
            //��L2����ƶ�
            L2 = L2->next;
        }
        //��pre����ƶ�
        pre = pre->next;
    }

    //����ѭ����L1����L2�м������ʣ��Ľڵ�û�б��۲��
    //ֱ�Ӱ�ʣ�µĽڵ���뵽pre��nextָ��λ��

    //���L1�л��нڵ�
    if (L1 != NULL) {
        //��L1��ʣ�µĽڵ�ȫ�����뵽pre��nextָ��λ��
        pre->next = L1;
    }

    //���L2�л��нڵ�
    if (L2 != NULL) {
        //��L2��ʣ�µĽڵ�ȫ�����뵽pre��nextָ��λ��
        pre->next = L2;
    }

    //��󷵻�����ڵ��nextָ��
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