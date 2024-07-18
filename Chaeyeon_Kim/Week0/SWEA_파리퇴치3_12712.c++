#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, m = 0;
        int center = 0;
        cin >> n >> m; // n은 배열 m은 파워
        int max = 0;
        vector<vector<int> > arr(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int a = 0;
                cin >> a;
                arr[i][j] = a;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum1 = 0;
                int sum2 = 0;
                int sum = 0;
                for (int k = 1; k < m; k++)
                {
                    if (i - k >= 0)
                    {
                        sum1 += arr[i - k][j];
                    }
                    if (i + k <= n - 1)
                    {
                        sum1 += arr[i + k][j];
                    }
                    if (j - k >= 0)
                    {
                        sum1 += arr[i][j - k];
                    }
                    if (j + k <= n - 1)
                    {
                        sum1 += arr[i][j + k];
                    }
                    if (i + k <= n - 1 and j - k >= 0) 
                    {
                        sum2 += arr[i + k][j - k];
                    }
                    if (i - k >= 0 and j + k <= n - 1)
                    {
                        sum2 += arr[i - k][j + k];
                    }
                    if (i - k >= 0 and j - k >= 0)
                    {
                        sum2 += arr[i - k][j - k];
                    }
                    if (i + k <= n-1 and j + k <= n-1)
                    {
                        sum2 += arr[i + k][j + k];
                    }
                }
                sum1 += arr[i][j];
                sum2 += arr[i][j];

                if (sum1 > sum2)
                {
                    sum = sum1;
                }
                else
                {
                    sum = sum2;
                }
                if (sum > max)
                {
                    max = sum;
                }
            }
        }
        std::cout << "#" << test_case << " " << max << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}