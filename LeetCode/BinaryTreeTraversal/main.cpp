#include <iostream>
#include <list>
#include <stack>

using namespace std;
/*
定义一个二叉树的节点
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

//二叉树前序遍历
list<int> *preorderTraversal(TreeNode* root) {
	cout << "preorderTraversal is start" << endl;
	//设置一个数组用来保存二叉树前序遍历的结果
	list<int> *preorderResult = new list<int>();

	//设置一个栈，用来保存路径
	stack <TreeNode*> *stackSave = new stack<TreeNode*>();

	//设置一个节点，一开始指向根节点
	TreeNode* node = root;

	//设置三种状态，方便表示当前遍历当前节点的时候进行到哪一步了
	//每个节点都有左 右 上 这三种状态
	//按照左-->右-->上的顺序观察每个节点

	//左代表该节点的左右孩子节点都没有遍历
	int nodeLeft = 1000;

	//右代表该节点的左孩子节点已经遍历，右孩子节点还没有遍历
	int nodeRight = 2000;

	//上代表左右孩子节点已经遍历，需要返回到它的父节点
	int nodeUp = 3000;

	//每个节点的初始化状态都是从左开始
	int nodeState = nodeLeft;

	//对二叉树进行遍历
	while (node != NULL) {
		//位置1

		//如果当前节点的状态是左，说明该节点的左右孩子节点都没有遍历
		if (nodeState == nodeLeft) {
			//把当前节点加入到二叉树前序遍历的结果数组中
			//根 左 右
			preorderResult->push_back(node->val);

			//如果当前节点有左子树
			if (node->left != NULL) {
				//先把当前节点加入到栈中，用来记录节点移动的路径
				stackSave->push(node);
				//开始观察当前节点的左孩子节点，代码来到了位置1
				node = node->left;
			} else {
				//如果当前节点没有左子树，切换当前节点的状态为:右  代码来到了位置1
				nodeState = nodeRight;
			}
		} else if (nodeState == nodeRight) {//如果当前节点的状态是右，说明该节点的左孩子节点已经遍历，右孩子节点还没有遍历
			//把当前节点加入到二叉树中序遍历的结果数组中
			//inorderResult->push_back(node.val);

			//如果当前节点有右子树
			if (node->right != NULL) {
				//先把当前节点加入到栈中，用来记录节点移动的路径
				stackSave->push(node);

				//开始观察当前节点的右孩子节点
				node = node->right;

				//每个节点开始的状态都是左开始，所以需要重新设置一下节点的状态
				nodeState = nodeLeft;

				//执行完上面三行代码，代码来到了位置1
			} else {
				//如果当前节点没有右子树，切换当前节点的状态为: 上  代码来到了位置1
				nodeState = nodeUp;
			}
		} else if (nodeState ==  nodeUp) {//如果当前节点的状态是上，说明左右孩子节点都已经遍历，需要返回到它的父节点
			//把当前节点加入到二叉树后序遍历的结果数组中
			//postorderRelust->push_back(node.val);

			//需要返回到当前节点的父节点位置，通过栈顶元素来获取当前节点的父节点
			//首先构建一个空的节点
			TreeNode* parent = NULL;

			//如果栈中有元素
			if (!stackSave->empty()) {
				//那么，栈顶元素就是当前节点的父节点
				parent = stackSave->top();

				//判断一下父节点的左节点是否为当前节点
				//比如这颗二叉树
				//               1
				//              / \
				//             2   3
				//            / \   \
				//           4   5   6
				//如果当前节点是4，那么4的父节点是2，2的左孩子节点是4，此时需要切换状态为: 右
				//如果当前节点是5，那么5的父节点是2，2的左孩子节点是4，此时不需要切换状态

				//如果父节点的左节点为当前节点
				if (parent->left == node) {
					//切换当前节点的状态为: 右
					nodeState = nodeRight;
				}
			}

			//开始观察当前节点的父节点
			//如果上述代码中栈中有元素，那么parent有值，代码来到了位置1
			//如果上述代码中栈中没有元素，那么parent没有值，会跳出循环
			node = parent;
		}
	}

	cout << "preorderTraversal is end" << endl;
	//根据题目要求，返回二叉树前序，中序，后序遍历的结果
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