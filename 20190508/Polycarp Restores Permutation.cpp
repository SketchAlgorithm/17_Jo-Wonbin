//https://codeforces.com/contest/1141/problem/C
#include<iostream>
#include<algorithm>
#define BUFF 200000

using namespace std;

int n, q[BUFF + 1], m[2 * BUFF + 1];
bool isPermut(int idx) {
	for (int i = 0; i < n; i++) {
		if (m[idx + i] != 1)
			return false;
	}
	return true;
}

int main() {
	int temp = BUFF, idx = BUFF;
	scanf_s("%d", &n);
	for (int i = 1; i < n; i++)
		scanf_s("%d", &q[i]);
	for (int i = 0; i < n; i++) {
		temp += q[i];
		if (temp > BUFF * 2 || temp < 0) break;
		m[temp] = 1;
		idx = min(idx, temp);
	}
	if (isPermut(idx)) {
		int temp = BUFF - idx + 1;
		for (int i = 0; i < n; i++) {
			temp += q[i];
			printf("%d ", temp);
		}
	}
	else cout << -1;
	


}