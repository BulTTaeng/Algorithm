#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int r, c, m, s, d;
int board[52][52];

struct fireball {
  int r;
  int c;
  int m;
  int s;
  int d;
} typedef fireball;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

queue<fireball> q;

struct compare {
  bool operator()(fireball &f1, fireball &f2) {
    if (f1.r == f2.r) {
      return f1.c < f2.c;
    }
    return f1.r < f2.r;
  };
};

priority_queue<fireball, vector<fireball>, compare> pq;

void combineFireball() {

  fireball f;
  fireball f2;
  f2.m = 0;
  f2.s = 0;
  f2.d = 0;

  int countodd = 0;
  int counteven = 0;

  while (!pq.empty()) {
    f = pq.top();
    pq.pop();

    if (!pq.empty() && (f.c == pq.top().c && f.r == pq.top().r)) {
      f2.c = f.c;
      f2.r = f.r;
      f2.m += f.m;
      f2.s += f.s;
      if (f.d % 2 == 0) {
        counteven++;
      } else {
        countodd++;
      }
    } 
    else {
      if ((countodd + counteven) == 0) { //이전의 값은 모두 처리 되었음
        if (f.m != 0) q.push(f);
      } 
      else {
        if (f.c == f2.c && f.r == f2.r) { //같은 위치에 있다면
          f2.m += f.m;
          f2.s += f.s;
          if (f.d % 2 == 0) {
            counteven++;
          } else {
            countodd++;
          }

          f2.m = f2.m / 5;
          f2.s = f2.s / (countodd + counteven);

          if (f2.m != 0){
            if (countodd == 0 || counteven == 0) {
              for (int i = 0; i <= 6; i += 2) {
                f2.d = i;
                q.push(f2);
              }
            } else {
              for (int i = 1; i <= 7; i += 2) {
                f2.d = i;
                q.push(f2);
              }
            }
          }
          
          f2.m = 0;
          f2.s = 0;
          f2.d = 0;
          countodd = 0;
          counteven = 0;

        } else {                            //다른 위치라면
          
          if ((countodd + counteven) == 1) { //이전에 하나가 있음
            if (f2.m != 0)
              q.push(f2);
            if (f.m != 0)
              q.push(f);
          }
          else { //이전에 여러개가 있었음
            if(f.m != 0) q.push(f);
            f2.m = f2.m / 5;
            f2.s = f2.s / (countodd + counteven);

            if (f2.m != 0){ 
              if (countodd == 0 || counteven == 0) {
                for (int i = 0; i <= 6; i += 2) {
                  f2.d = i;
                  q.push(f2);
                }
              } else {
                for (int i = 1; i <= 7; i += 2) {
                  f2.d = i;
                  q.push(f2);
                }
              }
            }
            f2.m = 0;
            f2.s = 0;
            f2.d = 0;
            countodd = 0;
            counteven = 0;
          }
        }
      }
    }
  }
}

void moveFireball(fireball fire) {
  fireball newfireball;

  int rr = fire.r + (dx[fire.d] * fire.s) % N;
  int cc = fire.c + (dy[fire.d] * fire.s) % N;

  if(rr>N) rr -=N;
  if(cc>N) cc -= N;
  if(rr<1) rr+=N;
  if(cc<1) cc+=N;

  newfireball.r = rr;
  newfireball.c = cc;
  newfireball.m = fire.m;
  newfireball.s = fire.s;
  newfireball.d = fire.d;

  pq.push(newfireball);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M >> K;

  fireball temp;

  for (int i = 0; i < M; i++) {
    cin >> temp.r >> temp.c >> temp.m >> temp.s >> temp.d;
    q.push(temp);
  }

  int currtime = 0;

  while (!q.empty()) {
    temp = q.front();
    q.pop();

    moveFireball(temp);

    if (q.empty()) {
      currtime++;
      combineFireball();
      if (currtime >= K) break;
    }
  }

  int ans = 0;

  while (!q.empty()) {
    ans += q.front().m;
    q.pop();
  }

  cout << ans;

  return 0;
}
