//algospot WILDCARD
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string W, N;
vector<string> ans;
int cache[101][101];
int c, n;
bool match(int ,int );

int main() {
	
	cin >> c;
	while (c-- > 0) {
		cin >> W;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 101; j++)
				for (int k = 0; k < 101; k++)
					cache[j][k] = -1;
			cin >> N;
			if (match(0, 0))
				ans.push_back(N);
		}
		sort(ans.begin(), ans.end());
		for (auto iter = ans.begin(); iter != ans.end(); iter++)
			cout << *iter << endl;
		ans.clear();
	}

	
}

bool match(int w, int n) {


	int& ret = cache[w][n];
	if (ret != -1)
		return ret;

	/*
	if (n < N.size() && w < W.size() && (W[w] == N[n] || W[w] == '?'))
		return ret = match(w + 1, n + 1);
	
	if (w == W.size()) return ret = (n == N.size());

	if (W[w] == '*')
		return ret = (n != N.size() && match(w, n + 1)) || match(w + 1, n);
	
	return ret = false;
	*/
	

	if (w == W.size()) 
		return n == N.size();
	
	if (n == N.size())
		return false;

	if (W[w] == '*')
		return match(w + 1, n) || match(w, n + 1);
	
	if (W[w] == N[n] || W[w] == '?')
		return match(w + 1, n + 1);
	
	return false;
	
	
	
	/*if (w < W.size() && n < N.size() &&
		(W[w] == N[n] || W[w] == '?')) {
		return ret = match(w + 1, n + 1);
	}
	
	if (w == W.size())
		return ret = (n == N.size());
	
	if (W[w] == '*') {
		if (match(w + 1, n) || (n < N.size() && match(w, n + 1)))
			return ret = 1;
	}
	return ret = false;
	*/

	

}
