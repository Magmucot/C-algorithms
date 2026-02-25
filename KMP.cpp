#include <bits/stdc++.h>
using namespace std;

// KMP и KMP автомат

using ll = long long;

vector<vector<int>> KMP_automoton(const vector<int> &pi, const string &p, const string &alpha)
{
    vector<vector<int>> next(p.size() + 1, vector<int>(alpha.size(), 0));
    if (p.size() == 0)
        return next;

    for (int i = 0; i < alpha.size(); i++)
    {
        if (alpha[i] == p[0])
            next[0][i] = 1;
    }
    for (int i = 1; i <= p.size(); i++)
    {
        for (int c = 0; c < alpha.size(); c++)
        {
            if (i < p.size() && alpha[c] == p[i])
                next[i][c] = i + 1;
            else
                next[i][c] = next[pi[i - 1]][c];
        }
    }
    return next;
}
vector<ll> pi_func(const string &s)
{
    ll n = s.size();
    vector<ll> pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        ll j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }
    return pi;
}
vector<ll> KMP(const string &s, const string &patrn)
{
    ll n = s.size(), m = patrn.size();
    vector<ll> pi = pi_func(patrn), res;
    ll j = 0;
    for (ll i = 0; i < n; ++i)
    {
        while (j > 0 and s[i] != patrn[j])
            j = pi[j - 1];
        if (s[i] == patrn[j])
            j++;
        if (j == m)
        {
            res.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> search = KMP("nap[iosnvspeionv[iozdjv[ismtbner=0hb]", "[io");
    for (auto v : search)
        cout << v << " ";
    cout << "\n";
    return 0;
}
