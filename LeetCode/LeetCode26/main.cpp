#include <iostream>
using namespace std;

/*
LeetCode26:ɾ�����������е��ظ���
����һ���������е�����nums, ����ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Σ�����ɾ����������³��ȡ�
Ԫ�ص����˳��Ӧ�ñ���һ��
*/
int removeDuplicates(int *nums, int len) {
	//ָ��i�����������
	int n = len;
	//ָ��jָ�򼴽�����ֵ��λ��
	int j = 0;
	//��ʼ��������б���
	for (int i = 0; i < n; i++) {
		//����ɸѡ
		if (i == 0 || (nums[i] != nums[i - 1])) {
			//��ֵ
			nums[j] = nums[i];
			//j�ƶ�
			j++;
		}
	}
	//��ȡ���
	return j;
}

int main() {
	int nums[10] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int len = sizeof(nums) / sizeof(nums[0]);
	int ret = removeDuplicates(nums, len);
	cout << "The ret is " << ret << endl;
	cout << " new nums is ";
	for (int i = 0; i < ret; i++) {
		cout << " " << nums[i];
	}
	return 0;
}