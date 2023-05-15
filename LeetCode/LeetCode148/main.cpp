#include <iostream>
using namespace std;

/*
* LeetCode148:排序链表
给你链表的头节点head,请将其按升序排列并返回排序后的链表
进阶：你可以在O(n logn)时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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

//合并两个有序链表
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
        }
        else {
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

ListNode* sortList(ListNode* head) {
    //获取链表的总长度
    int length = 0;

    //从链表的头节点开始访问
    ListNode* node = head;

    //利用while循环，可以统计出链表的节点个数，即长度
    while (node != NULL) {
        length++;
        node = node->next;
    }

    //在源链表的头部设置一个虚拟头结点
    //因为可能会操作到原链表的头结点
    //设置了虚拟头结点，原链表的头结点和原链表的其它节点地位一样
    ListNode* dummyHead = new ListNode(0, head);

    //利用for循环，执行合并的操作
    //长度为1的链表和长度为1的链表合并后，形成一个长度为2的链表
    //长度为2的链表和长度为2的链表合并后，形成一个长度为4的链表
    //长度为4的链表和长度为4的链表合并后，形成一个长度为8的链表
    //长度为8的链表和长度为8的链表合并后，形成一个长度为16的链表
    //也有可能是，长度为8的链表和长度为5的链表合并后，形成一个长度为13的链表
    //但是，每次合并过程中，子链表都会想要扩充为原来的两倍
    //直到子链表想要扩充的长度超过了length
    for (int subLength = 1; subLength < length; subLength *= 2) {
        //整个归并过程分为三个步骤
        //1.不停的划分，直到无法划分为止
        //2.开始两两合并
        //3.每次合并之后的结果都需要连接起来

        //每次都把结果连接到dummyHead,因此先记录一下
        //prev表示已经排序好的链表的【尾结点】
        ListNode* prev = dummyHead;

        //dummyHead的后面节点才是原链表的节点，需要把它们进行划分
        //curr表示所有正在准备排序的那些节点的【尾结点】
        ListNode* curr = dummyHead->next;

        //利用while循环，寻找出每次划分后子链表的头结点
        while (curr != NULL) {
            //每次都是两个子链表开始合并
            //1.先寻找出【左子链表】，长度为subLength
            ListNode* head1 = curr;

            //通过for循环，找出subLength个节点来
            //curr的索引为0，需要再找subLength-1个节点来
            for (int i = 1; (i < subLength) && (curr->next != NULL); i++) {
                curr = curr->next;
            }

            //2.再寻找出【右子链表】，长度最多为subLength,甚至有可能长度为0
            ListNode* head2 = curr->next;

            //此时，需要将【左子链表】与【右子链表】的连接断开
            curr->next = NULL;

            //curr来到【右子链表】的头部
            curr = head2;

            //通过for循环，找出【右子链表】的那些节点来
            //【右子链表】的节点个数可能达不到subLength，甚至只有1个或者0个节点
            for (int i = 1; (i < subLength) && (curr != NULL) && (curr->next != NULL); i++) {
                curr = curr->next;
            }

            //获取到【右子链表】之后，需要把它和后续链表断开
            //next表示接下来需要排序的那些节点的【首节点】
            ListNode* next = NULL;

            //如果curr != NULL,那么说明【右子链表】的节点个数达到了subLength个，并且后续还有节点
            if (curr != NULL) {
                //记录一下后面节点
                next = curr->next;

                //再将【右子链表】和后续链表断开
                curr->next = NULL;
            }

            //将【左子链表】与【右子链表】合并 (两个子链表都是有序的，合并后再组成一个有序的链表)
            ListNode* mergeNode = mergeTwoLists(head1, head2);

            //合并之后的结果需要连接到前一个链表
            prev->next = mergeNode;

            //prev来到链表的尾部，是下一个即将合成链表之后的前一个链表的尾结点
            while (prev->next != NULL) {
                prev = prev->next;
            }

            //curr来到next,处理后面的节点
            curr = next;
        }
    }
    return dummyHead->next;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode* retNode = sortList(head);
    while (retNode != NULL) {
        cout << retNode->val << " ";
        retNode = retNode->next;
    }
    cout << endl;
	return 0;
}