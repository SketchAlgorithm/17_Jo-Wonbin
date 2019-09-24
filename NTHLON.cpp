#include<iostream>
#include<set>
#include<algorithm>
#include<string.h>
using namespace std;

const int NORMAL = 100000;
set<pair<int, int>> s;
int cache[2 * NORMAL + 1], C, M, A, B, ans;

int dp(int w) {
	if (w == 0) return 0;
	if (w > 2000 || w < -2000) return 1000000400;
	int& ret = cache[w + NORMAL];
	if (ret != -1) return ret;

	ret = 1000000000;
	if (w > 0) {
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			int weight = (*iter).second;
			int diff = (*iter).first;
			if (diff == 0) continue;
			ret = min(ret, weight + dp(w + diff));
		}
	}
	else {
		for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
			int weight = (*iter).second;
			int diff = (*iter).first;
			if (diff == 0) continue;
			ret = min(ret, weight + dp(w + diff));
		}
	}
	
	return ret;
}


int main() {
	
	cin >> C;
	while (C-- > 0) {
		s.clear(); ans = 10000001;
		memset(cache, -1, sizeof(cache));
		//init
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			s.insert({ A - B, A });
		}
		if ((*s.begin()).first > 0 || (*s.rbegin()).first < 0)
			cout << "IMPOSSIBLE" << endl;
		else {
			for (auto iter = s.begin(); iter != s.end(); iter++) {
				int weight = (*iter).second;
				int diff = (*iter).first;
				ans = min(ans, weight + dp(diff));
			}
			cout << ans << endl;
		}
		
	}
}