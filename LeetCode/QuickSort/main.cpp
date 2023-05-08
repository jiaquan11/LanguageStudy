#include <iostream>
using namespace std;

/*
快速排序算法
1.首先设定一个分界值pivot,通过该分界值将数组分成左右两部分
2.将大于或等于分界值的数据集中到数组右边，小于或等于分界值的数据集中到数组的左边
3.接着，左边和右边的数据可以独立排序，对于左侧的数组数据，又可以取一个分界值，将该部分数据分成左右
两部分，同样在左边放置较小值，右边放置较大值。右侧的数组数据也可以做类似处理。
4.重复上述过程
*/
int partition(int* nums, int left, int right) {
	//经典快速排序的写法
	//设置当前区间的第一个元素为基准元素
	int pivot = nums[left];
	
	//left向右移动，right向左移动，直到left和right指向同一元素为止
	while (left < right) {
		//只有当遇到小于pivot的元素时，right才停止移动
		//此时,right指向了一个小于pivot的元素，这个元素不在它该在的位置上
		while ((left < right) && (nums[right] >= pivot)) {
			///如果right指向的元素时大于pivot的，那么right不断地向左移动
			right--;
		}

		//将此时的nums[left]赋值为nums[right]
		//执行完这个操作，比pivot小的这个元素被移动到了左侧
		nums[left] = nums[right];

		//只有当遇到大于pivot left才停止移动
		//此时left指向了一个大于pivot的元素，这个元素不在它该在的位置上
		while (left < right && nums[left] <= pivot) {
			//如果left指向的元素是小于pivot的，那么left不断地向右移动
			left++;
		}

		//将此时的nums[right]赋值为nums[left]
		//执行完这个操作，比pivot大的这个元素被移动到了右侧
		nums[right] = nums[left];
	}

	//此时，left和right相遇，那么需要将此时的元素设置为pivot
	//这个时候，pivot的左侧元素都小于它，右侧元素都大于它
	nums[left] = pivot;

	//返回left
	return left;
}

//函数传入待排序数组nums
//排序区间的左端点left
//排序区间的右端点right
void quickSort(int* nums, int left, int right) {
	//如果left大于等于right,说明该区间只有1个或者没有元素
	if (left >= right) {
		//无需再递归划分后再排序，直接返回
		return;
	}

	//调用函数partion,将left和right之间的元素划分为左右两部分
	int mid = partition(nums, left, right);

	//划分之后，再对mid左侧的元素进行快速排序
	quickSort(nums, left, mid - 1);

	//划分之后，再对mid右侧的元素进行快速排序
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