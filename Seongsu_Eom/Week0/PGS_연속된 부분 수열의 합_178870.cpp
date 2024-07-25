#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    sequence.push_back(0);
    int sum = 0;
    int s = 0, e = 0, cnt = 0;
    int a[3] = {10000000,0,0};
    for(int i=0;i<sequence.size();i++) {
        if(sum == k) {
            i--;
            if(a[0] > cnt) {
                a[0] = cnt;
                a[1] = s;
                a[2] = i;
            }
            cnt--;
            sum -= sequence[s];
            s++;
        }
        else if(sum > k) {
            cnt--;
            sum -= sequence[s];
            s++;
            i--;
        }
        else if(sum < k) {
            cnt++;
            sum += sequence[i];
        }
    }
    answer.push_back(a[1]);
    answer.push_back(a[2]);

    return answer;
}