#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), zero(n + 1);
    // zero 是当前开始往后遇到的连续 0 的数量

    for (auto &x : a)
        cin >> x;
        
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == 0)
            zero[i] = zero[i + 1] + 1;
        else
            zero[i] = 0;
    }

    ll ans = 0;
    for (int l = 0; l < n; ++l)
    {
        int r = l;
        int sum_xor = 0;
        while (r < n)
        {
            if (!a[r])
            {
                r += zero[r];
            }
            else
            {
                if (sum_xor & a[r])
                    break;
                sum_xor ^= a[r];
                r++;
            }
        }
        ans += r - l;
    }

    cout << ans << '\n';

    return 0;
}