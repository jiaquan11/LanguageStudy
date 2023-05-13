#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
N�ʺ�����
�о�������ν�n���ʺ������n*n�������ϣ�����ʹ�ʺ�˴�֮�䲻���໥����
����һ������n,�������в�ͬ��n�ʺ�����Ľ������
ÿһ�ֽⷨ����һ����ͬ��n�ʺ���������ӷ��÷������÷�����'Q'��'.'�ֱ�����˻ʺ�Ϳ�λ
*/

//�������з���Ҫ��Ľ�
list<list<string>*>* res = new list<list<string>*>();

//����(x, y)Ϊ�ʺ�������λ��
//����attack
void checkQueenAttack(int x, int y, int **attack, int n) {
	//����ÿһ������(x, y)��˵�������ϣ��£����ң����ϣ����£����ϣ����°˸�����
	//[����]������Ϊ(x-1, y-1)
	//[��]������Ϊ(x-1, y)
	//[����]������Ϊ(x-1, y+1)
	//[��]������Ϊ(x, y-1)
	//[��]������Ϊ(x, y+1)
	//[����]������Ϊ(x+1, y-1)
	//[��]������Ϊ(x+1, y)
	//[����]������Ϊ(x+1, y+1)
	//ͨ������һά������Ա�ʾ��˸�����
	//dx��ʾ x �ķ���
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	//dy��ʾ y �ķ���
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	//�ʺ�����������϶��ǻʺ��ܹ�����λ�ã�����Ϊ1
	attack[x][y] = 1;

	//������(x, y)Ϊ���ģ�ȥ�������˸����������
	for (int j = 0; j < 8; j++) {
		//��������Ľ��и���
		for (int i = 1; i < n; i++) {//�Ե�ǰ������Χѭ����Ȧ��ÿһȦ��8������
			//�µ�λ�õ�������Ϊx + i * dx[j]
			int nx = x + i * dx[j];
			//�µ�λ�õ�������Ϊy + i * dy[j]
			int ny = y + i * dy[j];

			//�����λ�õ�������n*n�����̷�Χ��
			if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n)) {
				//��ô��Щλ�þ���������Ϊ(x, y)�Ļʺ�Ĺ�����Χ�ڣ�����Ϊ1
				attack[nx][ny] = 1;
			}
		}
	}
}

//����Ȼ��ÿһ��ֻ�ܷ���һ���ʺ���������ÿһ��ÿһ�е������ûʺ�
//k ��ʾ��ǰ��������
//n ��ʾ��Ҫ���ö��ٸ��ʺ�ͬʱҲ�������̵Ĵ�СΪn*n
//queen������¼�ʺ��λ��
//attack������ʾ�ʺ�Ĺ�����Χ
void backTrack(int k, int n, char** queen, int** attack) {
	if (k == n) {//������������̵����һ�з��ú��˻ʺ���ô��˵���ҵ���һ�����Ҫ��Ľ�
		//���� queenΪ��ά�ַ����飬������Ҫת��Ϊ�ַ�������
		list<string>* listStr = new list<string>();

		//������ά����queen
		//ȡ��queen��ÿһ���ַ�����c
		for (int i = 0; i < n; i++) {
			//���ַ�����c�е������ַ�ת��Ϊ�ַ�������ʽ����ƴ��
			//����{'.', 'Q', '.', '.',}
			//ת��Ϊ'.Q..'
			//������ַ������뵽list��
			char* c = queen[i];
			listStr->push_back(string(c));
		}

		//list��Ϊһ�����Ҫ��Ľ⣬�������뵽���������
		res->push_back(listStr);
		//���ڱ����������е��У������ٱ�����ȥ�����Է���
		return;
	}

	//ÿһ��ֻ�ܷ���һ���ʺ�
	//����ÿһ��Ҳֻ�ܷ���һ���ʺ�
	//������k���У���0�е�n-1�У��жϻʺ�Ӧ�÷��õ��ĸ�λ��
	for (int i = 0; i < n; i++) {
		//�������attack[k][i] == 0
		//˵�����λ�ò����κ�һ���ʺ�Ĺ�����Χ��
		//���Կ��Կ��Ƿ��ûʺ�
		if (attack[k][i] == 0) {
			//�����(k, i)λ�÷����˻ʺ���ô����Ҫ������k+1��Ӧ����ô���������Ļʺ���
			//�����п�����(k, i)λ�÷����˻ʺ�֮���ں����������л��޷��ٷ��������Ļʺ�
			//��ô����Ҫ�ص�(k, i)��״̬�������ܲ�����(k, i+1)��λ�÷���
			//Ϊ���ܹ��ص�(k, i)��״̬��������Ҫ�ȼ�¼��ʱ��attack��ʹ��һ����ʱ�Ķ�ά���飬��ȿ���attack
			//�����ʹ����ȿ���������ֱ��ʹ��int[][] temp = c �ᵼ��attack�����ı�ʹtempҲ�ᷢ���ı� ����Ҳ���޷�����֮ǰ��״̬��
			int** temp = new int* [n];
			for (int i = 0; i < n; i++) {
				temp[i] = new int[n];
			}
			//ͨ������for ѭ������attack�е�����Ԫ����ȿ�����temp
			for (int l = 0; l < n; l++) {
				for (int m = 0; m < n; m++) {
					temp[l][m] = attack[l][m];
				}
			}

			//queen������¼�ʺ��λ��
			//��ô(k, i)��λ��queen[k][i] = 'Q'
			queen[k][i] = 'Q';

			//�����·�����һ���ʺ����Թ�����Χ�ָ����ˣ� ������Ҫ����attack����
			//�·��ûʺ������Ϊ(k, i),ͬ������Ҫ�������İ˸�����
			checkQueenAttack(k, i, attack, n);

			//�����(k, i)λ�÷����˻ʺ���ô����Ҫ������k+1��Ӧ����ô���������Ļʺ�
			//�ݹ�ĵ���backtrack��k+1�з��ûʺ�
			backTrack(k + 1, n, queen, attack);

			//�ݹ���������߻ʺ󣬻ָ�attack��״̬�������ܲ�����(k, i+1)��λ�÷���
			attack = temp;

			//�ָ�queen��״̬��˵����ʱ�ʺ󲻷�����(k, i)λ��
			queen[k][i] = '.';
		}
	}
}

list<list<string>*>* solveNQueens(int n) {
	//attack������ʾ�ʺ�Ĺ�����Χ
	int** attack = new int* [n];//��ά��int����n*n��ÿ��Ԫ�ش��intֵ
	for (int i = 0; i < n; i++) {
		attack[i] = new int[n];
	}

	//queen������¼�ʺ��λ��
	char** queen = new char* [n];//��ά��char����n*n,ÿ��Ԫ�ش��charֵ
	for (int i = 0; i < n; i++) {
		queen[i] = new char[n];
	}

	//��ʼ����ά����queen�����е�Ԫ��Ϊ'.'
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			queen[i][j] = '.';
		}
	}

	//��ʼ����ά����attack�����е�Ԫ��Ϊ0
	//0 ����û�лʺ��ܹ����ĵ�
	//1 ������������һ���ʺ�Ĺ�����Χ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			attack[i][j] = 0;
		}
	}

	//�����̵ĵ�0�е�0�д���n�ʺ�����
	backTrack(0, n, queen, attack);

	//��󣬷������з���Ҫ��Ľ�
	return res;
}

int main() {
	int n = 4;//n*n����ʾn���ʺ�n*n������
	list<list<string>*>* result = solveNQueens(n);//�����д���˶��������ÿ���������������stringԪ��
	for (auto it = result->begin(); it != result->end(); it++) {
		list<string>* solution = *it;
		for (auto jt = solution->begin(); jt != solution->end(); jt++) {
			cout << *jt << endl;
		}
		cout << endl;
	}
	return 0;
}