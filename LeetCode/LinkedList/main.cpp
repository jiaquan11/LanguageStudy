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
    // 1����ȡ�����е�Ԫ�ظ���
    int getSize() {
        return size;
    }

    // 2���ж������Ƿ�Ϊ��
    bool isEmpty() {
        return size == 0;
    }

    // 3��������ͷ���Ԫ��
    void addFirst(E element) {
        add(0, element);
    }

    // 4���������м����Ԫ��
    void add(int index, E element) {
        Node* prev = dummyHead;
        // ��Ҫ���� index - 1 �Σ��ҵ� prev ���ڵ�λ��
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* newNode = new Node(element);
        newNode->next = prev->next;
        prev->next = newNode;

        size++;
    }

    // 5��������β�����Ԫ��
    void addLast(E element) {
        add(size, element);
    }

    // 6����ȡ����ĵ� index ��λ�õ�Ԫ��
    E get(int index) {
        Node* cur = dummyHead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->e;
    }

    // �������ĵ�һ��Ԫ��
    E getFirst() {
        return get(0);
    }

    // �����������һ��Ԫ��
    E getLast() {
        return get(size - 1);
    }

    // 8���޸�����ĵ� index ��λ�õ�Ԫ��
    void set(int index, E element) {
        Node* cur = dummyHead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->e = element;
    }

    // 9�������������Ƿ��и�Ԫ��
    bool contains(E element) {
        Node* cur = dummyHead->next;
        // ��ͷ��β��������Ԫ�أ�ֱ���ҵ��Ǹ�Ԫ�أ����߱����������Ҳ���
        while (cur != NULL) {
            if (cur->e == element) {
                return  true;
            }
            cur = cur->next;
        }
        return  false;
    }

    // 10��ɾ������ĵ� index ��λ�õ�Ԫ��
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

    // 11���������Ԫ��
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

    //����ڲ�������Ԫ����������ʽ������Ϊ��������
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
        // 1����ǰ�ڵ�洢��ֵ
        E e;
        // 2����ǰ�ڵ�洢��ִ����һ���ڵ�ĵ�ַ
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

    // Ԫ�ص�����
    int size = 0;
    Node* dummyHead = NULL;
};

//���ⲿ������Ԫ����
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