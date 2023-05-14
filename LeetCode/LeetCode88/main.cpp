#include <iostream>
using namespace std;

/*
* LeetCode88:合并两个有序数组
给你两个有序整数数组nums1和nums2,请你将nums2合并到nums1中，使nums1成为一个有序数组
初始化nums1和nums2的元素数量分别为m和n,你可以假设nums1的空间大小等于m+n,这样它就有足够的空间
保存来自nums2的元素
*/
void merge(int *nums1, int m, int len1, int* nums2, int n) {
	//索引从有序数组nums1有效元素的末端开始
	//数组的下标索引从零开始计数
	//索引 0  1  2
	//数组[1, 2, 3]
	int i = m - 1;

	//索引从有序数组nums2的末端开始
	int j = n - 1;

	//从有序数组nums1最末端的位置开始保存元素
	int cur = len1 - 1;

	//通过循环把nums2的元素都移动到num1中
	while (j >= 0) {
		//比较num1和num2中的当前的元素大小
		//如果num1中的索引位置为i的元素大于num2中的索引位置为j的元素
		//为了防止越界i必须是大于等于0
		if ((i >= 0) && (nums1[i] > nums2[j])) {
			//把num1中的索引位置为i的元素复制到索引为cur的位置
			//此时cur的元素已经确定下来
			nums1[cur] = nums1[i];

			//接下来去确定cur前面一个元素应该放什么数字
			cur--;
			//此时，索引i需要向前移动
			i--;
			//否则，如果num1中的索引位置为i的元素小于或者等于num2中索引位置为j的元素
		} else {
			//把nums2中的索引位置为j的元素复制到索引为cur的位置
			nums1[cur] = nums2[j];
			//接下来去确定cur前面一个元素应该放什么数字
			cur--;
			//此时，索引j需要向前移动
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