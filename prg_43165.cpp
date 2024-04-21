#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &numbers, int &answer, int target, int cnt, int sum){
    
    if(cnt == numbers.size()-1){    
        if(target == sum + numbers[cnt] || target == sum - numbers[cnt]){
            answer++;
        }
           return;
    }
    dfs(numbers, answer, target, cnt+1, sum+numbers[cnt]);
    dfs(numbers, answer, target, cnt+1, sum-numbers[cnt]);
 
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers,answer,target,0,0);
    
    return answer;
}
