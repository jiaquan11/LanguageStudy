#include <iostream>
using namespace std;

/*
ð������
1.��α��������������
2.ÿһ�ֱ��������αȽ�ÿ�����ڵ�Ԫ�أ����˳����󣬽�������Ԫ�ؽ�����ʹ�ý�С��Ԫ�ط��ڽϴ��Ԫ��
ǰ�棬������һ�ֱ���֮������Ԫ�ر�������������β��
*/
void bubbleSort(int* nums, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}


int main() {
	int nums[5] = { 5, 1, 3, 4, 2 };
	int len = sizeof(nums) / sizeof(nums[0]);
	bubbleSort(nums, len);

	cout << "BubbleSort nums is: ";
	for (int i = 0; i < len; i++) {
		cout << " " << nums[i];
	}
	return 0;
}
