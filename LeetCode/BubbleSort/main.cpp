#include <iostream>
using namespace std;

/*
冒泡排序
1.多次遍历待排序的数组
2.每一轮遍历，依次比较每个相邻的元素，如果顺序错误，将这两个元素交换，使得较小的元素放在较大的元素
前面，这样，一轮遍历之后，最大的元素被交换到了序列尾部
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
