#include<iostream>
#include <queue>

using namespace std;

int R, C;
char road[51][51];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<pair<int,int>> rain;
queue<pair<int,int>> tempq;


queue<pair<int,int>> car;
queue<pair<int,int>> tempcar;

void show();
void simulate();
void moveRain();
bool moveCar();

int ans = 0;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> R >> C;

	for(int i =0; i<R ; i++){
		for(int j =0; j<C; j++){
			cin >> road[i][j];

			if(road[i][j] == 'W'){
				car.push({i,j});
			}
			if(road[i][j] == '*'){
				rain.push({i,j});
			}
		}
	}

	simulate();

	if(ans < 0){
		cout << "FAIL";
	}
	else{
		cout << ans;
	}

	return 0;
}


void show(){
	for(int i =0; i<R; i++){
		for(int j =0; j<C ;j++){
			cout << road[i][j];
		}
		cout << "\n";
	}
}

void simulate(){

	bool suc= false;

	while(true){
		ans++;
		moveRain();
		suc = moveCar();

		if(suc) break;
		if(car.empty()){
			ans = -1;
			break;
		}

	}

}

void moveRain(){

	int r,c , nx, ny;

	while(!rain.empty()){
		r = rain.front().first;
		c = rain.front().second;
		rain.pop();

		for(int i =0; i<4; i++){
			nx = r+dx[i];
			ny = c + dy[i];

			if(nx>=0 && nx<R && ny >= 0 && ny<C){
				if(road[nx][ny] == '.' || road[nx][ny] == 'W'){
					tempq.push({nx, ny});
					road[nx][ny] = '*';
				}
			}
		}
	}

	while(!tempq.empty()){
		rain.push({tempq.front().first , tempq.front().second});
		tempq.pop();
	}

}


bool moveCar(){
	int r,c, nx, ny;

	while(!car.empty()){
		r = car.front().first;
		c = car.front().second;
		car.pop();

		for(int i =0; i<4; i++){
			nx = r + dx[i];
			ny = c + dy[i];

			if(nx >=0 && nx<R && ny>=0 && ny<C){
				if(road[nx][ny] == '.'){
					road[nx][ny] = 'W';
					tempcar.push({nx , ny});
				}
				else if(road[nx][ny] == 'H'){
					return true;
				}
			}
		}
	}

	while(!tempcar.empty()){
		car.push({tempcar.front().first , tempcar.front().second });
		tempcar.pop();
	}

	return false;
}
