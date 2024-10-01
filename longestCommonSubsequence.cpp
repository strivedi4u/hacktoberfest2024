#include <iostream>
#include <math.h>
using namespace std;

void print(string s1, int **dp, int **s, int m, int n)
{
    if (n >= 1 && m >= 1)
    {
        if (s[m][n] == 1)
        {
            print(s1, dp, s, m - 1, n - 1);
            cout << s1[m - 1];
        }
        else if (s[m][n] == 2)
        {
            print(s1, dp, s, m, n - 1);
        }
        else
        {
            print(s1, dp, s, m - 1, n);
        }
        return;
    }
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int m = s1.length();
    int n = s2.length();

    // int dp[m + 1][n + 1];
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        dp[0][j] = 0;
    }
    // int s[m + 1][n + 1];
    int **s = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i < m + 1; i++)
    {
        s[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                s[i][j] = 1;
            }
            else
            {
                if (dp[i - 1][j] < dp[i][j - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                    s[i][j] = 2;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    s[i][j] = 3;
                }
            }
        }
    }
    cout << dp[m][n] << "\n";
    print(s1, dp, s, m, n);
    return 0;
}
