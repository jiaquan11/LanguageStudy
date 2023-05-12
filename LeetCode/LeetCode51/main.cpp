#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
N皇后问题
研究的是如何将n个皇后放置在n*n的棋盘上，并且使皇后彼此之间不能相互攻击
给你一个整数n,返回所有不同的n皇后问题的解决方案
每一种解法包含一个不同的n皇后问题的棋子放置方案，该方案中'Q'和'.'分别代表了皇后和空位
*/

//保存所有符合要求的解
list<list<string>*>* res = new list<list<string>*>();

//坐标(x, y)为皇后所处的位置
//更新attack
void checkQueenAttack(int x, int y, int **attack, int n) {
	//对于每一个坐标(x, y)来说，都有上，下，左，右，左上，左下，右上，右下八个方向
	//[左上]的坐标为(x-1, y-1)
	//[上]的坐标为(x-1, y)
	//[右上]的坐标为(x-1, y+1)
	//[左]的坐标为(x, y-1)
	//[右]的坐标为(x, y+1)
	//[左下]的坐标为(x+1, y-1)
	//[下]的坐标为(x+1, y)
	//[右下]的坐标为(x+1, y+1)
	//通过两个一维数组可以表示这八个方向
	//dx表示 x 的方向
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	//dy表示 y 的方向
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	//皇后所处的坐标肯定是皇后能攻击的位置，设置为1
	attack[x][y] = 1;

	//以坐标(x, y)为中心，去更新它八个方向的坐标
	for (int j = 0; j < 8; j++) {
		//由内向外的进行更新
		for (int i = 1; i < n; i++) {//以当前坐标周围循环几圈，每一圈有8个方向
			//新的位置的坐标行为x + i * dx[j]
			int nx = x + i * dx[j];
			//新的位置的坐标列为y + i * dy[j]
			int ny = y + i * dy[j];

			//如果新位置的坐标在n*n的棋盘范围内
			if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n)) {
				//那么这些位置就是在坐标为(x, y)的皇后的攻击范围内，更新为1
				attack[nx][ny] = 1;
			}
		}
	}
}

//很显然，每一行只能放置一个皇后，所以我们每一行每一行的来放置皇后
//k 表示当前处理的行
//n 表示需要放置多少个皇后，同时也代表棋盘的大小为n*n
//queen用来记录皇后的位置
//attack用来表示皇后的攻击范围
void backTrack(int k, int n, char** queen, int** attack) {
	if (k == n) {//如果发现在棋盘的最后一行放置好了皇后，那么就说明找到了一组符合要求的解
		//由于 queen为二维字符数组，所以需要转换为字符串数组
		list<string>* listStr = new list<string>();

		//遍历二维数组queen
		//取出queen的每一行字符数组c
		for (int i = 0; i < n; i++) {
			//把字符数组c中的所有字符转换为字符串的形式进行拼凑
			//比如{'.', 'Q', '.', '.',}
			//转换为'.Q..'
			//把这个字符串加入到list中
			char* c = queen[i];
			listStr->push_back(string(c));
		}

		//list即为一组符合要求的解，把它加入到结果数组中
		res->push_back(listStr);
		//由于遍历完了所有的行，无需再遍历下去，所以返回
		return;
	}

	//每一行只能放置一个皇后
	//并且每一列也只能放置一个皇后
	//所以在k行中，从0列到n-1列，判断皇后应该放置到哪个位置
	for (int i = 0; i < n; i++) {
		//如果发现attack[k][i] == 0
		//说明这个位置不在任何一个皇后的攻击范围内
		//所以可以考虑放置皇后
		if (attack[k][i] == 0) {
			//如果在(k, i)位置放置了皇后，那么就需要考虑再k+1行应该怎么放置其它的皇后了
			//由于有可能在(k, i)位置放置了皇后之后，在后续的其它行会无法再放置其它的皇后
			//那么就需要回到(k, i)的状态，考虑能不能在(k, i+1)的位置放置
			//为了能够回到(k, i)的状态，所以需要先记录此时的attack，使用一个临时的二维数组，深度拷贝attack
			//如果不使用深度拷贝，而是直接使用int[][] temp = c 会导致attack发生改变使temp也会发生改变 这样也就无法保存之前的状态了
			int** temp = new int* [n];
			for (int i = 0; i < n; i++) {
				temp[i] = new int[n];
			}
			//通过两个for 循环，把attack中的所有元素深度拷贝到temp
			for (int l = 0; l < n; l++) {
				for (int m = 0; m < n; m++) {
					temp[l][m] = attack[l][m];
				}
			}

			//queen用来记录皇后的位置
			//那么(k, i)的位置queen[k][i] = 'Q'
			queen[k][i] = 'Q';

			//由于新放置了一个皇后，所以攻击范围又更多了， 所以需要更新attack数组
			//新放置皇后的坐标为(k, i),同样的需要更新它的八个方向
			checkQueenAttack(k, i, attack, n);

			//如果在(k, i)位置放置了皇后，那么就需要考虑在k+1行应该怎么放置其它的皇后
			//递归的调用backtrack在k+1行放置皇后
			backTrack(k + 1, n, queen, attack);

			//递归结束后，拿走皇后，恢复attack的状态，考虑能不能在(k, i+1)的位置放置
			attack = temp;

			//恢复queen的状态，说明此时皇后不放置在(k, i)位置
			queen[k][i] = '.';
		}
	}
}

list<list<string>*>* solveNQueens(int n) {
	//attack用来表示皇后的攻击范围
	int** attack = new int* [n];//二维的int数组n*n，每个元素存放int值
	for (int i = 0; i < n; i++) {
		attack[i] = new int[n];
	}

	//queen用来记录皇后的位置
	char** queen = new char* [n];//二维的char数组n*n,每个元素存放char值
	for (int i = 0; i < n; i++) {
		queen[i] = new char[n];
	}

	//初始化二维数组queen中所有的元素为'.'
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			queen[i][j] = '.';
		}
	}

	//初始化二维数组attack中所有的元素为0
	//0 代表没有皇后能攻击的到
	//1 代表出于任意一个皇后的攻击范围
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			attack[i][j] = 0;
		}
	}

	//从棋盘的第0行第0列处理n皇后的情况
	backTrack(0, n, queen, attack);

	//最后，返回所有符合要求的解
	return res;
}

int main() {
	int n = 4;//n*n，表示n个皇后，n*n个格子
	list<list<string>*>* result = solveNQueens(n);//链表中存放了多个链表，每个链表中用来存放string元素
	for (auto it = result->begin(); it != result->end(); it++) {
		list<string>* solution = *it;
		for (auto jt = solution->begin(); jt != solution->end(); jt++) {
			cout << *jt << endl;
		}
		cout << endl;
	}
	return 0;
}