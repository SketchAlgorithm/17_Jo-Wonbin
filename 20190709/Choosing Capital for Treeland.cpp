#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int cache[200001];
vector<int> node[200001];
vector<int> child[200001];
vector<int> ans;
int n, s, t;

int search(int s, int t) {
	
	int ret = 0;

	for (int i = 0; i < node[t].size(); i++) {
		if (node[t][i] != s) {
			ret += 1 + search(t, node[t][i]);
		}
	}
	for (int i = 0; i < child[t].size(); i++) {
		if (child[t][i] != s) {
			ret += search(t, child[t][i]);
		}
	}
	
	return ret;
	
}

void dp(int s, int t)
{
	for (int i = 0; i < node[t].size(); i++) {
		if (node[t][i] != s) {
			cache[node[t][i]] = cache[t] - 1;
			dp(t, node[t][i]);
		}
	}
	for (int i = 0; i < child[t].size(); i++) {
		if (child[t][i] != s) {
			cache[child[t][i]] = cache[t] + 1;
			dp(t, child[t][i]);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &s, &t);
		child[s].push_back(t);
		node[t].push_back(s);
	}
	cache[1] = search(0, 1);
	dp(0, 1);
	int m = 1000000;
	for (int i = 1; i < n + 1; i++) {
		if (cache[i] < m) {
			ans.clear();
			ans.push_back(i);
			m = cache[i];
		}
		else if (cache[i] == m)
			ans.push_back(i);
	}
	cout << m << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;

}