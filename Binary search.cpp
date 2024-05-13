#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int lo = 0;
    int hi = n - 1;
    int mid;

    int to_find;
    cin >> to_find;

    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;

        if (a[mid] < to_find)
        {
            lo = mid + 1;
        }
        else if (a[mid] >= to_find)
        {
            hi = mid;
        }
    }
    if (a[lo] == to_find)
    {
        cout << "Found at : " << lo << endl;
        // break;
    }
    else if (a[hi] == to_find)
    {
        cout << "found at :" << hi << endl;
        // break;
    }
    else
    {
        cout << "Not found" << endl;
    }

}

