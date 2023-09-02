#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOfTwoArraysBrute(int a[], int b[], int p, int q)
{
    vector<int> inter;
    int visited[q];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (a[i] == b[j] && visited[j] == 0)
            {
                inter.push_back(a[i]);
                visited[j] = 1;
                break;
            }
            if (b[j] > a[i])
            {
                break;
            }
        }
    }

    return inter;
}

vector<int> intersectionOfTwoArraysOptimal(int a[], int b[], int p, int q)
{
    int i = 0;
    int j = 0;
    vector<int> inter;

    while (i < p && j < q)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            inter.push_back(a[i]);
        }
    }
    return inter;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int p, q;
    cin >> p >> q;

    int a[p];
    int b[q];

    for (int i = 0; i < p; i++)
    {
        cin >> a[p];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> b[q];
    }
    intersectionOfTwoArraysOptimal(a, b, p, q);

    return 0;
}