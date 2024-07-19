#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    queue<tuple<int,int,int>> q;
    q.push({n,k,0});
    while(!q.empty()){
        int now = get<0>(q.front());
        int mu = get<1>(q.front());
        int level = get<2>(q.front());
        q.pop();

        if(level<enemy.size()){
            //무적권 사용
            if (mu>=0){
                now-= enemy[level];
                if(now<0){
                     if(answer<now) answer = now;
                }
                else q.push({now,--k,++level});
            }

            //안사용
            now-= enemy[level];
            if(now<0) if(answer<now) answer = now;
            else q.push({now,k,++level});
        }
        else{ 
            answer = enemy.size();
            break;
        }
    }
    return answer;
}