#include<iostream>
#include<string>
using namespace std;

int C;
char input;

string dc() {
	char t;
	string tree[4];
	
	for (int i = 0; i < 4; i++) {
		cin >> t;
		if (t == 'x') 
			tree[i] = t + dc();
		else 
			tree[i] = t;
	}
	return tree[2] + tree[3] + tree[0] + tree[1];
}

int main() {

	cin >> C;
	while (C-- > 0) {
		cin >> input;
		cout << input << (input == 'x' ? dq() : "") << endl;
	}
}
