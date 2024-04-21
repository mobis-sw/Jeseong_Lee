#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[101][101];
int board[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct pos{
    int x,y;
};

void init_board(void){
    
    for(int i = 0 ; i < 101; i++){
        for(int j = 0 ; j <101; j++){
            board[j][i] = -1;
        }
    } 
    
}
int bfs(vector<vector<int>> maps){
    queue<pos> q;
    q.push({0,0});
    visit[0][0] = true;
    board[0][0] = 1;
    
    int maxX = maps[0].size();
    int maxY = maps.size();
    
    while(!q.empty()){
        pos cur = q.front();
        q.pop();
        if(cur.x == maxX && cur.y == maxY){
            return board[maxY-1][maxX-1];
        }
        for(int i = 0 ; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx>= maxX || ny >= maxY) continue;
            if(visit[ny][nx] == true || board[ny][nx] != -1 || maps[ny][nx] ==0 ) continue;
            q.push({nx,ny});
            visit[ny][nx] = true;
            board[ny][nx] = board[cur.y][cur.x] +1;
            
        }
    }
    return board[maxY-1][maxX-1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    init_board();
    answer = bfs(maps);
    
    return answer;
}
