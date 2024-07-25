#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int minsz = sequence.size();
    int sum =0;
    int start =0;
    int end = 0;
    pair<int,int>target = {0,sequence.size()-1};
    
    while(start<sequence.size() )
    {
        if(sum == k && minsz > (end-start))
        {
            minsz = end-start;
            target.first = start;
            target.second = end-1;
        }
        else if(sum<k && end<sequence.size())
        {
            sum += sequence[end];
            end++;
        }
        else
        {
            sum -= sequence[start];
            start++;
        }
        
    }
    
    answer.push_back(target.first);
    answer.push_back(target.second);
    
    return answer;
}