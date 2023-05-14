#include <iostream>
using namespace std;

/*
LeetCode283 
�ƶ���
����һ������nums,��дһ������������0�ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
��ע�⣬�����ڲ���������������ԭ�ض�������в���
*/
void moveZeroes(int* nums, int length) {
	//����һ������������ָ�򾭹�һϵ�в���������������Ϊ0Ԫ�صĵ�һ��λ����
	//һ��ʼĬ��������Ϊ0��λ��
	int slow = 0;

	//��ͷ��β��������
	//�������֮��slowָ����һ��Ϊ0��Ԫ�أ�������������в�����0���ͺ�fastһ��������������ķ�Χ
	for (int fast = 0; fast < length; fast++) {
		//�ڱ��������У�������ַ��ʵ�Ԫ���Ƿ�0Ԫ��
		//˵��slow������ȷ��λ���ϣ���Ҫ����ƶ���Ѱ�Һ��ʵ�λ��
		if (nums[fast] != 0) {
			//���ʱ��ԭ��slow��ֵ��Ҫ��fast��ֵ����
			nums[slow] = nums[fast];
			
			//slow��Ҫ����ƶ���Ѱ�Һ��ʵ�λ��
			slow++;
		}
	}

	//��������ֻ��Ҫ��slow����������е�Ԫ�ض�����Ϊ0����
	for (int i = slow; i < length; i++) {
		//������Ϊ0
		nums[i] = 0;
	}
}

int main() {
	int nums[5] = { 0, 1, 0, 3, 12 };
	int length = sizeof(nums) / sizeof(nums[0]);

	moveZeroes(nums, length);

	for (int i = 0; i < length; i++) {
		cout << nums[i] <<" ";
	}

	cout << endl;
	return 0;
}