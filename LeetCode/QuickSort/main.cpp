#include <iostream>
using namespace std;

/*
���������㷨
1.�����趨һ���ֽ�ֵpivot,ͨ���÷ֽ�ֵ������ֳ�����������
2.�����ڻ���ڷֽ�ֵ�����ݼ��е������ұߣ�С�ڻ���ڷֽ�ֵ�����ݼ��е���������
3.���ţ���ߺ��ұߵ����ݿ��Զ������򣬶��������������ݣ��ֿ���ȡһ���ֽ�ֵ�����ò������ݷֳ�����
�����֣�ͬ������߷��ý�Сֵ���ұ߷��ýϴ�ֵ���Ҳ����������Ҳ���������ƴ���
4.�ظ���������
*/
int partition(int* nums, int left, int right) {
	//������������д��
	//���õ�ǰ����ĵ�һ��Ԫ��Ϊ��׼Ԫ��
	int pivot = nums[left];
	
	//left�����ƶ���right�����ƶ���ֱ��left��rightָ��ͬһԪ��Ϊֹ
	while (left < right) {
		//ֻ�е�����С��pivot��Ԫ��ʱ��right��ֹͣ�ƶ�
		//��ʱ,rightָ����һ��С��pivot��Ԫ�أ����Ԫ�ز��������ڵ�λ����
		while ((left < right) && (nums[right] >= pivot)) {
			///���rightָ���Ԫ��ʱ����pivot�ģ���ôright���ϵ������ƶ�
			right--;
		}

		//����ʱ��nums[left]��ֵΪnums[right]
		//ִ���������������pivotС�����Ԫ�ر��ƶ��������
		nums[left] = nums[right];

		//ֻ�е���������pivot left��ֹͣ�ƶ�
		//��ʱleftָ����һ������pivot��Ԫ�أ����Ԫ�ز��������ڵ�λ����
		while (left < right && nums[left] <= pivot) {
			//���leftָ���Ԫ����С��pivot�ģ���ôleft���ϵ������ƶ�
			left++;
		}

		//����ʱ��nums[right]��ֵΪnums[left]
		//ִ���������������pivot������Ԫ�ر��ƶ������Ҳ�
		nums[right] = nums[left];
	}

	//��ʱ��left��right��������ô��Ҫ����ʱ��Ԫ������Ϊpivot
	//���ʱ��pivot�����Ԫ�ض�С�������Ҳ�Ԫ�ض�������
	nums[left] = pivot;

	//����left
	return left;
}

//�����������������nums
//�����������˵�left
//����������Ҷ˵�right
void quickSort(int* nums, int left, int right) {
	//���left���ڵ���right,˵��������ֻ��1������û��Ԫ��
	if (left >= right) {
		//�����ٵݹ黮�ֺ�������ֱ�ӷ���
		return;
	}

	//���ú���partion,��left��right֮���Ԫ�ػ���Ϊ����������
	int mid = partition(nums, left, right);

	//����֮���ٶ�mid����Ԫ�ؽ��п�������
	quickSort(nums, left, mid - 1);

	//����֮���ٶ�mid�Ҳ��Ԫ�ؽ��п�������
	quickSort(nums, mid + 1, right);
}

void topKFrequent(int* nums, int len, int k) {
	cout << "before quickSort is: ";
	for (int i = 0; i < len; i++) {
		cout << " " << nums[i];
	}

	cout << endl;

	quickSort(nums, 0, len - 1);

	cout << "after quickSort is: ";
	for (int i = 0; i < len; i++) {
		cout << " " << nums[i];
	}
}

int main() {
	int nums[8] = {4, 3, 5, 7, 6, 1, 2, 4};
	int len = sizeof(nums) / sizeof(nums[0]);

	topKFrequent(nums, len, 1);
	return 0;
}