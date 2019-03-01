#include <string>
#include<algorithm>
#include <vector>
#include<iostream>
using namespace std;

vector<string> b;
int check_row[2][4] = { 0,1,0,-1,1,0,-1,0 };
int check_col[2][4] = { 1,0,-1,0,0,-1,0,1 };

int cache[47][48][50];

bool isEmpty(int y, int x) {
	return !(y < 0 || y > b.size() - 1 || x < 0 || x > b[y].size() - 1)
		&& b[y][x] == '.';
}

bool findPos(int& y, int& x) {
	for(int i = 0; i < b.size(); i++)
		for (int j = i%2; j < b[i].size(); j += 2) {
			if (b[i][j] == '.') {
				y = i;
				x = j;
				return true;
			}
		}
	return false;
}

int solve() {
	for (auto i : b) {
		cout << endl;
		for (auto k : i)
			cout << k;
	}
	int ret = 0;
	int x = -1, y = -1;
	
	if (!findPos(y, x)) return 0;
	int count = 0;
	for (int k = 0; k < 4; k++) {
		if (isEmpty(y + check_row[0][k], x + check_col[0][k]) &&
			isEmpty(y + check_row[1][k], x + check_col[1][k]))
		{
			b[y][x] = 'X';
			b[y + check_row[0][k]][x + check_col[0][k]] = 'X';
			b[y + check_row[1][k]][x + check_col[1][k]] = 'X';

			ret = max(ret, 1 + solve());

			b[y][x] = '.';
			b[y + check_row[0][k]][x + check_col[0][k]] = '.';
			b[y + check_row[1][k]][x + check_col[1][k]] = '.';
		}
		else count++;
	}
	if (count == 4) {
		b[y][x] = 'X';
		ret = max(ret, solve());
	}

	return ret;
}
//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
	
	int solution(vector<string> board) {
		
		b = board;
		
		int ans = solve();
		return ans;

	}
};



int main() {
	Solution s;
	vector<string> a = { "......", "......","......"  };
	cout << s.solution(a);
}