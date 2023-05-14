#include <iostream>
#include <string>
using namespace std;

template <typename E>
class LinkedList {
public:
    LinkedList() {
        dummyHead = new Node();
        size = 0;
    }

    ~LinkedList() {
        clear();
        delete dummyHead;
    }

public:
    // 1、获取链表中的元素个数
    int getSize() {
        return size;
    }

    // 2、判断链表是否为空
    bool isEmpty() {
        return size == 0;
    }

    // 3、在链表头添加元素
    void addFirst(E element) {
        add(0, element);
    }

    // 4、在链表中间添加元素
    void add(int index, E element) {
        Node* prev = dummyHead;
        // 需要遍历 index - 1 次，找到 prev 所在的位置
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* newNode = new Node(element);
        newNode->next = prev->next;
        prev->next = newNode;

        size++;
    }

    // 5、在链表尾部添加元素
    void addLast(E element) {
        add(size, element);
    }

    // 6、获取链表的第 index 个位置的元素
    E get(int index) {
        Node* cur = dummyHead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->e;
    }

    // 获得链表的第一个元素
    E getFirst() {
        return get(0);
    }

    // 获得链表的最后一个元素
    E getLast() {
        return get(size - 1);
    }

    // 8、修改链表的第 index 个位置的元素
    void set(int index, E element) {
        Node* cur = dummyHead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->e = element;
    }

    // 9、查找链表中是否有该元素
    bool contains(E element) {
        Node* cur = dummyHead->next;
        // 从头到尾遍历所有元素，直到找到那个元素，或者遍历结束后找不到
        while (cur != NULL) {
            if (cur->e == element) {
                return  true;
            }
            cur = cur->next;
        }
        return  false;
    }

    // 10、删除链表的第 index 个位置的元素
    E remove(int index) {
        Node* prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* retNode = prev->next;
        prev->next = retNode->next;
        E retValue = retNode->e;
        delete retNode;

        size--;
        return  retValue;
    }

    // 11、清空所有元素
    void clear() {
        Node* cur = dummyHead->next;
        while (cur != NULL) {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
        dummyHead->next = NULL;
        size = 0;
    }

    //类的内部定义友元函数，会隐式地声明为内联函数
    /*
    friend ostream& operator<<(ostream& os, LinkedList* list) {
        Node* cur = list->dummyHead->next;
        while (cur != NULL) {
            os << cur->e << "->";
            cur = cur->next;
        }
        os << "NULL";
        return os;
   }*/

   template <typename E>
   friend ostream& operator<<(ostream& os, const LinkedList<E>& list);

private:
    struct Node {
        // 1、当前节点存储的值
        E e;
        // 2、当前节点存储的执行下一个节点的地址
        Node* next = NULL;

        Node() {
            this->e = -1;
            this->next = NULL;
        }

        Node(const E element) {
            this->e = element;
            this->next = NULL;
        }

        Node(const E element, Node* nextNode) {
            this->e = element;
            this->next = nextNode;
        }
    };

    // 元素的数量
    int size = 0;
    Node* dummyHead = NULL;
};

//类外部定义友元函数
template <typename E>
ostream& operator<<(ostream& os, const LinkedList<E>& list) {
    typename LinkedList<E>::Node* cur = list.dummyHead->next;
    while (cur != NULL) {
        os << cur->e << "->";
        cur = cur->next;
    }
    os << "NULL";
    return os;
}

int main() {
    LinkedList<int> *linkedList = new LinkedList<int>();
    for (int i = 0; i < 5; i++) {
        linkedList->addFirst(i);
        cout << *linkedList << endl;
    }
    
    linkedList->add(2, 666);
    cout << *linkedList << endl;

    linkedList->remove(2);
    cout << *linkedList << endl;
	return 0;
}