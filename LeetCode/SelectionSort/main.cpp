#include <iostream>
using namespace std;

/*
SelectionSort:选择排序
1.多次遍历待排序的数组
2.每一轮遍历，从待排序序列中选出最小的元素，存放到已排序序列的末尾，即和待排序序列中的开始元素进行交换
*/
void selectionSort(int *nums, int len) {
	//外层循环寻找最小元素的次数，len个元素的排序，需要进行len-1次选择
	for (int i = 0; i < len - 1; i++) {
		int index = i;

		//内层循环len - i - 1次，代表第i次循环中比较的次数
		for (int j = i + 1; j < len; j++) {//找出i+1和len之间的最小数
			if (nums[j] < nums[index]) {
				index = j;
			}
		}

		//将nums[index]和待排序部分的第1个元素nums[i]交换
		int temp = nums[i];
		nums[i] = nums[index];
		nums[index] = temp;
	}
}

int main() {
	int nums[5] = { 5, 1, 3, 4, 2 };
	int len = sizeof(nums) / sizeof(nums[0]);
	selectionSort(nums, len);

	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}