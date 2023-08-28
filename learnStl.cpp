#include <bits/stdc++.h>
using namespace std;

void explainVectors()
{
    vector<int> v;
    vector<int> v2(4, 6);
    vector<int> v3(v2);

    v.emplace_back(1);
    v.push_back(2);
    v.emplace_back(3);
    v.emplace_back(4);
    v.emplace_back(5);
    v.emplace_back(6);

    cout << v[0] << endl;

    // iterators
    vector<int>::iterator it = v.begin();
    cout << *(it) << endl;
    it = it + 3;
    cout << *(it) << endl;

    // use of auto
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    v.erase(v.begin() + 3, v.begin() + 5);
    v.insert(v.begin() + 2, 3, 9);
    v.insert(v.begin(), v2.begin(), v2.end());

    // use of for each here it is NOT AN ITERATOR: not pointing to the add
    // here the auto datatype is int: AS ITS FOR EACH LOOP
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // explainPair();
    explainVectors();
    return 0;
}
/*void explainPair()
{
    pair<int, int> p = {2, 3};
    cout << p.first << " " << p.second << endl;
    pair<int, pair<int, int>> p2 = {1, {3, 5}};
    cout << p2.second.first << endl;
}*/
