#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int vit1[1000001] = {0,};
    int vit2[1000001] = {0,};
    int t1[10002] = {0,};
    int t2[10002] = {0,};
    int cnt1 = 0, cnt2 = 0;
    for(int i =0;i<topping_len - 1;i++) {
        if(t1[topping[i]] == 0) {
            t1[topping[i]] = 1;
            cnt1++;
        }
        vit1[i] = cnt1;
        if(t2[topping[topping_len - i - 1]] == 0) {
            t2[topping[topping_len - i - 1]] = 1;
            cnt2++;
        }
        vit2[topping_len - i - 1] = cnt2;
    }
    for(int i =0;i<topping_len - 1;i++) {
        if(vit1[i] == vit2[i + 1])
            answer++;
    }
    
    
    return answer;
}