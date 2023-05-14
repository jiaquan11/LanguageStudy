#include <iostream>
using namespace std;

/*
LeetCode75:��ɫ����
����һ��������ɫ����ɫ����ɫ��һ��n��Ԫ�ص����飬ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ�
�����պ�ɫ����ɫ����ɫ˳������
�����У�����ʹ������0��1��2�ֱ��ʾ��ɫ����ɫ����ɫ
*/

//����ֵ
/*
ͨ���м��������������Ԫ�ص�ֵ
nums[i]��ֵ��Ϊ��nums[j]��ֵ
nums[j]��ֵ��Ϊ��nums[i]��ֵ
*/
void swap(int* nums, int i, int j) {
	//ʹ����ʱ����temp,����nums[i]��ֵ
	int temp = nums[i];

	//nums[i]��ֵ�޸�Ϊnums[j]��ֵ
	nums[i] = nums[j];

	//nums[i]��ֵ�޸�Ϊtemp��ֵ
	nums[j] = temp;
}

void sortColors(int* nums, int length) {
	//left ָ������Ŀ�ʼλ�ã���ָ���λ����඼��0
	int left = 0;
	//right ָ������Ľ�����λ�ã���ָ���λ���Ҳ඼��2
	int right = length - 1;
	//index ָ������Ŀ�ʼλ��
	int index = 0;

	//index ����ƶ�������Խ��rightʱ����ѭ��������Ҫ���ж���
	//��Ϊ��ʱ˵��index�Ҳ�Ķ��Ѿ���2
	while (index <= right) {
		//��ȡ��ǰ��Ԫ��ֵ
		int cur = nums[index];
		if (cur == 0) {//���index λ���ϵ�Ԫ��ֵΪ0
			//˵���Ǻ�ɫ��Ҫ������ǰ��ȥ
			//��ǰ����Ǹ�Ԫ�ر�left ָ�ţ�������indexָ���Ԫ�غ�leftָ��λ���ϵ�Ԫ�ؽ��н���
			swap(nums, left, index);

			//index��������ƶ�
			index++;
			//left ��������ƶ����������������0
			left++;
		} else if (cur == 1) {//���indexλ���ϵ�Ԫ��ֵΪ1
			//˵���ǰ�ɫ����Ӧ�÷����м䣬���ù����������ƶ�index
			index++;
		} else if (cur == 2) {//���indexλ���ϵ�Ԫ��ֵΪ2
			//˵������ɫ��Ҫ���������
			//������indexָ���Ԫ�غ�rightָ��λ���ϵ�Ԫ�ؽ��н���
			swap(nums, right, index);

			//����ԭ��rightָ���Ԫ�ؿ���Ϊ0��1��2�����ֵ��κ�һ��
			//��������index�󣬻���Ҫ�����۲�һ�֣�����index�Ȳ��ƶ�
			right--;
		}
	}
}

int main() {
	int nums[6] = { 2, 0, 2, 1, 1, 0};
	int length = sizeof(nums) / sizeof(nums[0]);

	sortColors(nums, length);

	for (int i = 0; i < length; i++) {
		cout << nums[i] << " ";
	}

	cout << endl;
	return 0;
}