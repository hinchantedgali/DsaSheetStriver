#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int e)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == e)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    int e;
    cin >> e;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << firstOccurence(arr, n, e);

    return 0;
}