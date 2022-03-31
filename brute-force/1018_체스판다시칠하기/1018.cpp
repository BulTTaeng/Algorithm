#include <iostream>

using namespace std;

char inp[51][51];
char w[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};

char b[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};

int N , M , ans =987654321;

int first_w(int x, int y);
int first_b(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> inp[i][j];
        }
    }

	int white, black;

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			white = first_w(i, j);
			black = first_b(i, j);
			
            ans = min(ans , white);
            ans = min(ans , black);
		}
	}
	cout << ans;
    return 0;
}

int first_w(int x, int y) {
	int temp = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (inp[x + i][y + j] != w[i][j])
				temp++;
		}
	}
	return temp;
}

int first_b(int x, int y) {
	int temp = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (inp[x + i][y + j] != b[i][j])
				temp++;
		}
	}

	return temp;
}
