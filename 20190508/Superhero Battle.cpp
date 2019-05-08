//https://codeforces.com/contest/1141/problem/E
#include<iostream>
#include<algorithm>
using namespace std;
int H, n, d[200001];

int main() {
	cin >> H >> n;
	int sum = 0;
	int mn = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &d[i]);
		sum += d[i];
		mn = min(mn, sum);
	}
	int h = H;
	if (sum > 0 && -mn < H) cout << -1;
	else {
		h = h % -sum + mn / sum * sum;
 		for (int i = 0; i < n; i++) {
			if (h <= 0) {
				cout << H / -sum * n + i + 1;
				return 0;
			}
			h += d[i];
		}
	}
}