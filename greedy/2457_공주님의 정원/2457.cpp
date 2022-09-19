#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N ;

struct flower{
  int sm;
  int sd;
  int em;
  int ed;
}typedef flower;

struct compare_asc{
    bool operator()(flower &p1 , flower &p2){
        if(p1.sm == p2.sm){
            return p1.sd > p2.sd;
        }
        return p1.sm > p2.sm;
    }
};

struct compare_des{
    bool operator()(flower &p1 , flower &p2){
        if(p1.em == p2.em){
            return p1.ed < p2.ed;
        }
        return p1.em < p2.em;
    }
};

priority_queue<flower, vector<flower>, compare_asc> pq;
priority_queue<flower, vector<flower>, compare_des> okFlower;
int ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> N;
  flower temp;
  for(int i =0; i<N; i++){
    cin >> temp.sm;
    cin >> temp.sd;
    cin >> temp.em;
    cin >> temp.ed;
    pq.push(temp);
  }

  int currMonth = 3;
  int currDay = 1;

  while(true){

    if(currMonth >= 12){
      break;
    }

    //cout << currMonth << " " << currDay << "\n";
    
    while(!pq.empty()){
      temp = pq.top();
      if(temp.sm < currMonth){
        okFlower.push(temp);
        pq.pop();
      }
      else if(temp.sm == currMonth && temp.sd <= currDay){
        okFlower.push(temp);
        pq.pop();
      }
      else{
        break;
      }
    }

    if(okFlower.empty()){ //현재 피울 수 있는 꽃이 없다
      ans = 0;
      break;
    }

    currMonth = okFlower.top().em;
    currDay = okFlower.top().ed;

    while(!okFlower.empty()){
      okFlower.pop();
    }
    ans++;
    
  }

  cout << ans;
  return 0;

  
}
