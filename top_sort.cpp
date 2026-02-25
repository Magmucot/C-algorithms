#include <bits/stdc++.h>
using namespace std;

// Топ сорт

using ll = long long;
const ll MAXN = 1000005;
vector<ll> order;
vector<ll> g[MAXN];
ll color[MAXN];
bool cycle = false;
void dfs(ll v, ll parent = -1)
{
    color[v] = 1;
    for (ll to : g[v])
    {
        if (color[to] == 1)
        {
            cycle = true;
            return;
        }
        if (color[to] == 0)
        {
            dfs(to, v);
            if (cycle)
                return;
        }
    }
    color[v] = 2;
    order.push_back(v);
}

int main()
{
    cycle = false;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 0; i <= n; ++i)
    {
        if (color[i] == 0)
        {
            dfs(i);
            if (cycle)
                return;
        }
    }
    reverse(order.begin(), order.end());
    copy(order.begin(), order.end(), ostream_iterator<ll>(cout, " "));
    cout << "\n";
    return 0;
}
