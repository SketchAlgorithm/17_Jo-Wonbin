#include<iostream>
#include<vector>
using namespace std;

int c;
int n;
int k;
vector<int> check;
int solve(int i) {
	if(i) return 1;
	int idx = solve(i - 1) % check.size();
	check.erase(check.begin() + idx);

	
}
	

int  main() {
	cin >> c;

	

	while (c-- > 0)
	{
		
		cin >> n >> k;
		check.assign(n + 1, 1);
		
		cout << ans << endl;
	}
}