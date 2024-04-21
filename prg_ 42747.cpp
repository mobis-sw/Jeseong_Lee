#include <string>
#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;

bool cmp(int x, int y){
    return x>y;
}

int solution(vector<int> citations) {
    int answer = 0;
    int nums = citations.size();
    sort(citations.begin(),citations.end(),cmp);
    
    for(int i = 0 ; i < nums; i++){
        
        if(citations[i] >= (i+1)){
            answer = max(i+1,answer);
        }
    }
    
    return answer;
}
