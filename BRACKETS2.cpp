///algospot BRACKETS2

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int c;
vector<char> v; //LIFO(last in, first out) 구조 이므로 벡터를 사용
string br;

bool isMatch() {

	for (int i = 0; i < br.size(); i++) {
		if (br[i] == '(' || br[i] == '{' || br[i] == '[')
			v.push_back(br[i]); 	//open brackets일 경우 벡터에 저장
		else if (!v.empty() && (v.back() - br[i] == -1 || v.back() - br[i] == -2))
			v.pop_back();		//close일 경우 맨뒤 값과 ASCII 값이 차이가 1 ,2 일 경우 값을 지우고 for문 진행
		else	
			return false;		//mismatch일 경우 return false;
	}

	return true;
}


int main() {
	cin >> c;	
	
	while (c-- > 0)
	{
		cin >> br;
		printf(isMatch() && v.empty() ? "YES\n" : "NO\n");
		v.clear();
	}
	
}
