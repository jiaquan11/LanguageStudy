#include <iostream>
using namespace std;

/*
* LeetCode88:�ϲ�������������
��������������������nums1��nums2,���㽫nums2�ϲ���nums1�У�ʹnums1��Ϊһ����������
��ʼ��nums1��nums2��Ԫ�������ֱ�Ϊm��n,����Լ���nums1�Ŀռ��С����m+n,�����������㹻�Ŀռ�
��������nums2��Ԫ��
*/
void merge(int *nums1, int m, int len1, int* nums2, int n) {
	//��������������nums1��ЧԪ�ص�ĩ�˿�ʼ
	//������±��������㿪ʼ����
	//���� 0  1  2
	//����[1, 2, 3]
	int i = m - 1;

	//��������������nums2��ĩ�˿�ʼ
	int j = n - 1;

	//����������nums1��ĩ�˵�λ�ÿ�ʼ����Ԫ��
	int cur = len1 - 1;

	//ͨ��ѭ����nums2��Ԫ�ض��ƶ���num1��
	while (j >= 0) {
		//�Ƚ�num1��num2�еĵ�ǰ��Ԫ�ش�С
		//���num1�е�����λ��Ϊi��Ԫ�ش���num2�е�����λ��Ϊj��Ԫ��
		//Ϊ�˷�ֹԽ��i�����Ǵ��ڵ���0
		if ((i >= 0) && (nums1[i] > nums2[j])) {
			//��num1�е�����λ��Ϊi��Ԫ�ظ��Ƶ�����Ϊcur��λ��
			//��ʱcur��Ԫ���Ѿ�ȷ������
			nums1[cur] = nums1[i];

			//������ȥȷ��curǰ��һ��Ԫ��Ӧ�÷�ʲô����
			cur--;
			//��ʱ������i��Ҫ��ǰ�ƶ�
			i--;
			//�������num1�е�����λ��Ϊi��Ԫ��С�ڻ��ߵ���num2������λ��Ϊj��Ԫ��
		} else {
			//��nums2�е�����λ��Ϊj��Ԫ�ظ��Ƶ�����Ϊcur��λ��
			nums1[cur] = nums2[j];
			//������ȥȷ��curǰ��һ��Ԫ��Ӧ�÷�ʲô����
			cur--;
			//��ʱ������j��Ҫ��ǰ�ƶ�
			j--;
		}
	}
}

int main() {
	int nums1[6] = { 1, 2, 3, 0, 0, 0 };
	int m = 3;
	int len1 = sizeof(nums1) / sizeof(nums1[0]);
	int nums2[3] = { 2, 5, 6 };
	int n = 3;

	merge(nums1, m, len1, nums2, n);

	for (int i = 0; i < len1; i++) {
		cout << nums1[i] << " ";
	}
	cout << endl;

	return 0;
}