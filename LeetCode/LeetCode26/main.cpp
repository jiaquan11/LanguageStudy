#include <iostream>
using namespace std;

/*
LeetCode26:删除有序数组中的重复项
给你一个升序排列的数组nums, 请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度。
元素的相对顺序应该保持一致
*/
int removeDuplicates(int *nums, int len) {
	//指针i进行数组遍历
	int n = len;
	//指针j指向即将被赋值的位置
	int j = 0;
	//开始对数组进行遍历
	for (int i = 0; i < n; i++) {
		//进行筛选
		if (i == 0 || (nums[i] != nums[i - 1])) {
			//赋值
			nums[j] = nums[i];
			//j移动
			j++;
		}
	}
	//获取结果
	return j;
}

int main() {
	int nums[10] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int len = sizeof(nums) / sizeof(nums[0]);
	int ret = removeDuplicates(nums, len);
	cout << "The ret is " << ret << endl;
	cout << " new nums is ";
	for (int i = 0; i < ret; i++) {
		cout << " " << nums[i];
	}
	return 0;
}