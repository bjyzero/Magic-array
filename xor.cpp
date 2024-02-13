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
                r += zero[r];    // 这里 a[r] 的值为 0 时，可以异或，但 & 运算为 0 ，要特殊考虑
            }                    // 当数为 0 时直接跳过对应 0 出现的次数
            else
            {
                if (sum_xor & a[r])    // 当 & 运算结果为 0 说明 数字之间二进制刚好错开
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
