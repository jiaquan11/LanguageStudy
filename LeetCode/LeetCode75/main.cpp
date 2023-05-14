#include <iostream>
using namespace std;

/*
LeetCode75:颜色分类
给定一个包含红色，白色和蓝色，一共n个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，
并按照红色，白色，蓝色顺序排列
此题中，我们使用整数0，1和2分别表示红色，白色和蓝色
*/

//交换值
/*
通过中间变量，交换两个元素的值
nums[i]的值变为了nums[j]的值
nums[j]的值变为了nums[i]的值
*/
void swap(int* nums, int i, int j) {
	//使用临时变量temp,保存nums[i]的值
	int temp = nums[i];

	//nums[i]的值修改为nums[j]的值
	nums[i] = nums[j];

	//nums[i]的值修改为temp的值
	nums[j] = temp;
}

void sortColors(int* nums, int length) {
	//left 指向数组的开始位置，它指向的位置左侧都是0
	int left = 0;
	//right 指向数组的结束的位置，它指向的位置右侧都是2
	int right = length - 1;
	//index 指向数组的开始位置
	int index = 0;

	//index 向后移动，当它越过right时跳出循环，不需要再判断了
	//因为此时说明index右侧的都已经是2
	while (index <= right) {
		//获取当前的元素值
		int cur = nums[index];
		if (cur == 0) {//如果index 位置上的元素值为0
			//说明是红色，要放在最前面去
			//最前面的那个元素被left 指着，所以让index指向的元素和left指向位置上的元素进行交换
			swap(nums, left, index);

			//index可以向后移动
			index++;
			//left 可以向后移动，它的左侧区域都是0
			left++;
		} else if (cur == 1) {//如果index位置上的元素值为1
			//说明是白色，就应该放在中间，不用管它，继续移动index
			index++;
		} else if (cur == 2) {//如果index位置上的元素值为2
			//说明是蓝色，要放在最后面
			//所以让index指向的元素和right指向位置上的元素进行交换
			swap(nums, right, index);

			//由于原先right指向的元素可能为0，1，2这三种的任何一种
			//交换到了index后，还需要继续观察一轮，所以index先不移动
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