#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int T, N, M, ans;
int temp;

struct st{
    int value;
    int idx;
    int maxNumAfter;
}typedef st;

deque<st> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    st inputT;

    while(T--) {
        cin >> N >> M;

        dq.clear();
        ans = 0;
        
        for (int i =0; i< N; i++) {
            cin >> temp;
            inputT.value = temp;
            inputT.idx = i;
            inputT.maxNumAfter = temp;
            dq.push_back(inputT);
        }

        int currentBigNum = dq.back().maxNumAfter;

        for (int i = N-1; i>=0; i--) {
            currentBigNum = max(dq[i].maxNumAfter, currentBigNum);
            dq[i].maxNumAfter = currentBigNum;
        }

        int seq = 0;

        while(!dq.empty()) {
            int curr = dq.front().value;
            int idx = dq.front().idx;
            int bigNum = dq.front().maxNumAfter;
            
            if(curr >= bigNum){
                seq++;
                dq.pop_front();
                if(idx == M) {
                    ans = seq;
                    break;
                }
            } else {
                dq.pop_front();
                for (int j = dq.size()-1; j >=0; j--) {
                    if (dq[j].maxNumAfter < curr) {
                        dq[j].maxNumAfter = curr;
                    } else {
                        break;
                    }
                }
                dq.push_back(st{curr, idx, curr});
            }
        }

        cout << ans << "\n";
    }

    return 0;
}