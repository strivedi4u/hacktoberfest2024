#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int sum)
{
    int start = 0, curr_sum = 0;
    int n = arr.size();

    for (int end = 0; end < n; end++)
    {
        curr_sum += arr[end];

        while (curr_sum > sum && start < end)
        {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == sum)
        {
            return {start + 1, end + 1};
        }
    }

    return {-1};
}

int main()
{
    int N;
    cin >> N;
    vector<int> A;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int target_sum;
    cin >> target_sum;

    vector<int> ans = subarraySum(A, target_sum);

    if (ans[0] != -1)
    {
        cout << ans[0] << " to " << ans[1] << endl;
    }

    return 0;
}
