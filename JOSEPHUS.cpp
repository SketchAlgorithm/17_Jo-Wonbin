#include<iostream>
#include<vector>
using namespace std;

int c, n, k, i;
vector<int> check;

void solve(int idx) {

	if (check.size() == 3) return; 
	// 마지막 두명이 남을 떄 까지 벡터를 erase
	check.erase(check.begin() + idx);
	idx += k;
	idx = idx > check.size() ? (idx - check.size()) % (check.size() - 1) : idx - 1; 
	//인덱스가 전체 배열의 크기보다 크면 mod연산.
     	idx = !idx ? check.size() - 1 : idx;
	//인덱스가 0이라면 배열의 마지막 값으로 변경
	solve(idx);
	
	
}

int main() {
	cin >> c;
	while (c-- > 0) {
		cin >> n >> k;
		check.resize(n + 1); 
		for (i = 1; i <= n; i++)
			check[i] = i;
		
		solve(1);
		for (i = 1; i <= 2; i++)
			cout << check[i] << " ";
		cout << endl;
	}
}
