#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int ALPHABETS = 26;
//char to int function
int toInt(char ch) { return ch - 'A'; }

struct TrieNode {

	//���ڿ��� �����Ǵ� �� �˹ٺ� ����
	TrieNode* children[ALPHABETS];
	//���� ��������� Ȯ��.
	bool terminal;
	//�ڵ��ϼ��� ������ �ܾ�
	string word;
	//�� ��
	int freq;

	//������
	TrieNode(string word = "", int freq = 0) :terminal(false), freq(freq), word(word) {
		memset(children, 0, sizeof(children));
	}
	//�Ҹ���
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}
	//���ڿ� ����
	void insert(const char* key) {
		if (*key == 0) terminal = true;
		else {
			int next = toInt(*key);
			if (children[next] == nullptr) {
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}
	//���ϴ� ���ڿ� �ּ� Ÿ�� �� ��ȯ
	//Ư�� ��带 Ž���ϴ� �Լ� 
	int find(const char* key, string word) {
		if (*key == 0) return 10;
		if (this->word == word) return 1;
		int next = toInt(*key);

		if (children[next] == nullptr) return 10;
		return children[next]->find(key + 1, word) + 1;
	}

	//�ڵ��ϼ� ������ �ܾ �� ��帶�� Ž���Ͽ� �����ϴ� �Լ�
	void update(const char* key, string word, int freq) {
		if (*key == 0) return;

		if (this->freq < freq) {
			this->freq = freq;
			this->word = word;
		}
		if (this->freq == freq) {
			this->word = min(this->word, word);
		}

		int next = toInt(*key);
		children[next]->update(key + 1, word, freq);
	}
};

int C, N, M, ans;
char word[21];
string words[10000];
int freq[10000];

int main() {


	scanf("%d", &C);
	for (int i = 0; i < C; i++) {

		//init
		TrieNode root = TrieNode("1", 1000000);
		ans = 0;

		//input 
		scanf("%d %d", &N, &M);

		for (int j = 0; j < N; j++) {
			scanf("%s %d", &word, &freq[j]);
			words[j] = word;
			//generate Trie
			root.insert(word);
			root.update(word, words[j], freq[j]);
		}

		for (int j = 0; j < M; j++) {
			scanf("%s", &word);
			int size = ((string)word).size();
			//�ּҰ� �Ǵ� Ÿ�� �� ���ϱ�.
			ans += min(root.find(word, word), size);
		}

		//output
		cout << ans + M - 1 << endl;
	}
}