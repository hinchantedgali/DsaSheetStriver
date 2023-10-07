#include <iostream>
#include <climits>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    int k;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    int maxx = INT_MIN;

    for (int i = 0; i < n - k; i++)
    {
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] > maxx)
            {
                maxx = arr[j];
            }
        }

        cout << maxx << " ";
    }
    maxx = arr[n - k];
    for (int i = n - k; i < n; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    cout << maxx;

    return 0;
}