#include <iostream>
#include <string>

using namespace std;

int N;
string S;
int ans = 0;

bool canTake(string str);
void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> S;

    solve();

    cout << ans;
    
    return 0;
}

bool canTake(string str)
{
    int num = 0;
    for (int i =0; i<str.length(); i++) {
        num *= 10;
        num += str[i] - '0';
    }
    if (num <= 641) return true;
    return false;
}

void solve() {
    for (int i = 0; i < N; i++) {
        if ((i + 3 == N || (i + 3 < N && S[i + 3] != '0')) && canTake(S.substr(i, 3))) {
            i += 2;
        }
        else if ((i + 2 == N || (i + 2 < N && S[i + 2] != '0')) && canTake(S.substr(i, 2))) {
            i += 1;
        }
        ans++;
    }
}
