#include <iostream>
using namespace std;

/*
ð������
1.��α��������������
2.ÿһ�ֱ��������αȽ�ÿ�����ڵ�Ԫ�أ����˳����󣬽�������Ԫ�ؽ�����ʹ�ý�С��Ԫ�ط��ڽϴ��Ԫ��
ǰ�棬������һ�ֱ���֮������Ԫ�ر�������������β��
*/
void bubbleSort(int* nums, int len) {
	//���ѭ����Ҫ�����Ĵ�����n��Ԫ�ص�������Ҫn-1�α���
	//����0��n-2,�ܹ�Ϊn-1�α���
	for (int i = 0; i < len - 1; i++) {
		//�ڲ�ѭ��n-i-1�Σ������i��ѭ���бȽϵĴ���
		for (int j = 0; j < len - 1 - i; j++) {
			//����Ƚϵ�����Ԫ��a[j]����a[j+1],˵���ϴ���ڽ�С��ǰ��
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
