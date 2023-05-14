#include <iostream>
using namespace std;

/*
LeetCode283 
移动零
给定一个数组nums,编写一个函数将所有0移动到数组的末尾，同时保持非零元素的相对顺序
请注意，必须在不复制数组的情况下原地对数组进行操作
*/
void moveZeroes(int* nums, int length) {
	//设置一个变量，用来指向经过一系列操作后数组中所有为0元素的第一个位置上
	//一开始默认在索引为0的位置
	int slow = 0;

	//从头到尾遍历数组
	//遍历完毕之后，slow指向了一个为0的元素，或者如果数组中不存在0，就和fast一样，超过了数组的范围
	for (int fast = 0; fast < length; fast++) {
		//在遍历过程中，如果发现访问的元素是非0元素
		//说明slow不在正确的位置上，需要向后移动，寻找合适的位置
		if (nums[fast] != 0) {
			//这个时候，原先slow的值需要被fast的值覆盖
			nums[slow] = nums[fast];
			
			//slow需要向后移动，寻找合适的位置
			slow++;
		}
	}

	//接下来，只需要把slow极其后面所有的元素都设置为0就行
	for (int i = slow; i < length; i++) {
		//都设置为0
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