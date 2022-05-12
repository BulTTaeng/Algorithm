#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, string>m;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

	cin >> N >> M;
	
	string str1, str2;

	while(N--) {
		cin >> str1 >> str2;
		m.insert({str1, str2});
	}

	while(M--) {
		cin >> str1;
		cout << m[str1] << "\n";
	}
	
	return 0;
}
