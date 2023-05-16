#include <iostream>
using namespace std;

/*
InsertionSort: 插入排序
1.多次遍历待排序的数组
2.首先，将数组的第1个元素看做是包含1个元素的已排序数组
3.接着，按顺序把待排序数组中的元素插入到已排序数组的正确位置
*/
void insertionSort(int* nums, int len) {
	//外层循环从nums[1]开始遍历，即i从1循环至len-1
	for (int i = 1; i < len; i++) {
		//将nums[i]保存至key中
		int key = nums[i];

		//a[j]是a[i]的前一个元素
		int j = i - 1;

		//只要j大于等于0并且nums[j]大于key
		while (j >= 0 && nums[j] > key) {
			//只要j
			nums[j + 1] = nums[j];
			j--;
		}

		//最初的nums[i]找到了一个插入位置
		nums[j + 1] = key;
	}
}

int main() {
	int nums[5] = { 5, 1, 3, 4, 2 };
	int len = sizeof(nums) / sizeof(nums[0]);
	insertionSort(nums, len);

	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}