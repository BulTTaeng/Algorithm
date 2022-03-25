#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, p;

vector<int> makeTable(string p);
int kmp(string s, string p, vector<int> &table);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> p;

	vector<int> table = makeTable(p);
	cout << kmp(s, p, table);
	return 0;
}

vector<int> makeTable(string p) {
	vector<int> table(p.length());
	int j = 0;
	for (int i = 1; i < p.length(); i++) {
		while (p[i] != p[j] && j > 0) {
			j = table[j-1];
		}
		if (p[i] == p[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int kmp(string s, string p, vector<int> &table) {
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		while (s[i] != p[j] && j > 0) {
			j = table[j-1];
		}
		if (s[i] == p[j]) {
			if (j == p.length()-1) {
				return 1;
			}
            else{
                j++;
            }
		}
	}
	return 0;
}
