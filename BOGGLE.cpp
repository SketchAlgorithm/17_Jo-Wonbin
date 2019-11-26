#include<iostream>
#include<string>
#include<string.h>
using namespace std;


int T, N;
char map[7][7];
string term;

int cache[7][7][11];
//memoization
int dx[8] = { -1, -1, 0, 1, 1 ,1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
//Ž�� �迭

int search(int y, int x, int idx) {
	if (term.size() == idx) return true;
	if (map[y][x] != term[idx]) return false;
	//basis case

	int& ret = cache[y][x][idx];
	if (ret != -1) return ret;//Ž���� ���
	
	ret = 0;
	for (int i = 0; i < 8; i++) {//Ž��
		ret |= search(y + dy[i], x + dx[i], idx + 1);
	}
	return ret;	
}

int main() {
	cin >> T;
	while (T-- > 0) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				cin >> map[i][j];
			}
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> term;
			int flag = false;
			for (int i = 1; i <= 5; i++) {
				for (int j = 1; j <= 5; j++) {
					flag |= search(i, j, 0);
				}
			}
			cout << term << " " << (flag ? "YES" : "NO") << "\n";
			
		}
	}
}