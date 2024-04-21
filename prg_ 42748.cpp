#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

int arraySize = 0;
int commandsSize = 0;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    commandsSize = commands.size();
    for(int commandsIdx = 0 ; commandsIdx < commandsSize; commandsIdx++){
        vector<int>tmp(array.begin() + commands[commandsIdx][0]-1,array.begin() + commands[commandsIdx][1]);
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[commands[commandsIdx][2]-1]);
    }
    
    
    return answer;
}
