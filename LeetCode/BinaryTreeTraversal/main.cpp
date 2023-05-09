#include <iostream>
#include <list>
#include <stack>

using namespace std;
/*
����һ���������Ľڵ�
*/
class TreeNode {
public:
	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

	TreeNode(int val, TreeNode* left, TreeNode* right) {
		this->val = val;
		this->left = left;
		this->right = right;
	}

public:
	int val = -1;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

//������ǰ�����
list<int> *preorderTraversal(TreeNode* root) {
	cout << "preorderTraversal is start" << endl;
	//����һ�������������������ǰ������Ľ��
	list<int> *preorderResult = new list<int>();

	//����һ��ջ����������·��
	stack <TreeNode*> *stackSave = new stack<TreeNode*>();

	//����һ���ڵ㣬һ��ʼָ����ڵ�
	TreeNode* node = root;

	//��������״̬�������ʾ��ǰ������ǰ�ڵ��ʱ����е���һ����
	//ÿ���ڵ㶼���� �� �� ������״̬
	//������-->��-->�ϵ�˳��۲�ÿ���ڵ�

	//�����ýڵ�����Һ��ӽڵ㶼û�б���
	int nodeLeft = 1000;

	//�Ҵ���ýڵ�����ӽڵ��Ѿ��������Һ��ӽڵ㻹û�б���
	int nodeRight = 2000;

	//�ϴ������Һ��ӽڵ��Ѿ���������Ҫ���ص����ĸ��ڵ�
	int nodeUp = 3000;

	//ÿ���ڵ�ĳ�ʼ��״̬���Ǵ���ʼ
	int nodeState = nodeLeft;

	//�Զ��������б���
	while (node != NULL) {
		//λ��1

		//�����ǰ�ڵ��״̬����˵���ýڵ�����Һ��ӽڵ㶼û�б���
		if (nodeState == nodeLeft) {
			//�ѵ�ǰ�ڵ���뵽������ǰ������Ľ��������
			//�� �� ��
			preorderResult->push_back(node->val);

			//�����ǰ�ڵ���������
			if (node->left != NULL) {
				//�Ȱѵ�ǰ�ڵ���뵽ջ�У�������¼�ڵ��ƶ���·��
				stackSave->push(node);
				//��ʼ�۲쵱ǰ�ڵ�����ӽڵ㣬����������λ��1
				node = node->left;
			} else {
				//�����ǰ�ڵ�û�����������л���ǰ�ڵ��״̬Ϊ:��  ����������λ��1
				nodeState = nodeRight;
			}
		} else if (nodeState == nodeRight) {//�����ǰ�ڵ��״̬���ң�˵���ýڵ�����ӽڵ��Ѿ��������Һ��ӽڵ㻹û�б���
			//�ѵ�ǰ�ڵ���뵽��������������Ľ��������
			//inorderResult->push_back(node.val);

			//�����ǰ�ڵ���������
			if (node->right != NULL) {
				//�Ȱѵ�ǰ�ڵ���뵽ջ�У�������¼�ڵ��ƶ���·��
				stackSave->push(node);

				//��ʼ�۲쵱ǰ�ڵ���Һ��ӽڵ�
				node = node->right;

				//ÿ���ڵ㿪ʼ��״̬������ʼ��������Ҫ��������һ�½ڵ��״̬
				nodeState = nodeLeft;

				//ִ�����������д��룬����������λ��1
			} else {
				//�����ǰ�ڵ�û�����������л���ǰ�ڵ��״̬Ϊ: ��  ����������λ��1
				nodeState = nodeUp;
			}
		} else if (nodeState ==  nodeUp) {//�����ǰ�ڵ��״̬���ϣ�˵�����Һ��ӽڵ㶼�Ѿ���������Ҫ���ص����ĸ��ڵ�
			//�ѵ�ǰ�ڵ���뵽��������������Ľ��������
			//postorderRelust->push_back(node.val);

			//��Ҫ���ص���ǰ�ڵ�ĸ��ڵ�λ�ã�ͨ��ջ��Ԫ������ȡ��ǰ�ڵ�ĸ��ڵ�
			//���ȹ���һ���յĽڵ�
			TreeNode* parent = NULL;

			//���ջ����Ԫ��
			if (!stackSave->empty()) {
				//��ô��ջ��Ԫ�ؾ��ǵ�ǰ�ڵ�ĸ��ڵ�
				parent = stackSave->top();

				//�ж�һ�¸��ڵ����ڵ��Ƿ�Ϊ��ǰ�ڵ�
				//������Ŷ�����
				//               1
				//              / \
				//             2   3
				//            / \   \
				//           4   5   6
				//�����ǰ�ڵ���4����ô4�ĸ��ڵ���2��2�����ӽڵ���4����ʱ��Ҫ�л�״̬Ϊ: ��
				//�����ǰ�ڵ���5����ô5�ĸ��ڵ���2��2�����ӽڵ���4����ʱ����Ҫ�л�״̬

				//������ڵ����ڵ�Ϊ��ǰ�ڵ�
				if (parent->left == node) {
					//�л���ǰ�ڵ��״̬Ϊ: ��
					nodeState = nodeRight;
				}
			}

			//��ʼ�۲쵱ǰ�ڵ�ĸ��ڵ�
			//�������������ջ����Ԫ�أ���ôparent��ֵ������������λ��1
			//�������������ջ��û��Ԫ�أ���ôparentû��ֵ��������ѭ��
			node = parent;
		}
	}

	cout << "preorderTraversal is end" << endl;
	//������ĿҪ�󣬷��ض�����ǰ�����򣬺�������Ľ��
	return preorderResult;
}

int main() {
	TreeNode* treeNode1 = new TreeNode(1);
	TreeNode* treeNode2 = new TreeNode(2);
	TreeNode* treeNode3 = new TreeNode(3);
	TreeNode* treeNode4 = new TreeNode(4);
	TreeNode* treeNode5 = new TreeNode(5);
	TreeNode* treeNode6 = new TreeNode(6);
	treeNode1->left = treeNode2;
	treeNode1->right = treeNode4;
	treeNode2->left = treeNode3;
	treeNode4->left = treeNode5;
	treeNode4->right = treeNode6;

	cout << "preorderTraversal is : " << endl;
	list <int> *listResult = preorderTraversal(treeNode1);
	int listsize = listResult->size();
	cout << "preorderTraversal listsize : " << listsize << endl;;
	for (int i = 0; i < listsize; i++) {
		cout << listResult->front();
	}
	return 0;
}