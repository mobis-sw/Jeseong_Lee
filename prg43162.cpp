#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visit[201];
queue<int> q;
vector<int> board[201];

void bfs(int x, int n){
    visit[x] = 1;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0 ; i< board[cur].size() ; i++){
            int nx = board[cur][i];
            if(!visit[nx]){
                visit[nx] = true;
                q.push(nx);
            }
            
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0 ; i<computers.size(); i++){
        for(int j = 0 ; j<computers[i].size(); j++){
            if(computers[i][j]){
                board[i].push_back(j);
                board[j].push_back(i);
            }
        }    
    }
    
    for(int i = 0 ; i<computers.size(); i++){
        for(int j = 0 ; j<computers[i].size(); j++){
            if(!visit[i] && computers[i][j]){
                bfs(i,n);
                answer++;
            }
        }
    }
    
    
    return answer;
}
