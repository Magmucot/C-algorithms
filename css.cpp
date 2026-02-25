#include <bits/stdc++.h>
using namespace std;

// Ксс

using ll = long long;
const ll MAXN = 1000005;
vector<ll> order;
vector<ll> g[MAXN], gr[MAXN], g_cond[MAXN];
ll cid[MAXN], sz[MAXN];

void dfs(ll v)
{
    cid[v] = -1;
    for (ll to : g[v])
    {
        if (cid[to] == 0)
            dfs(to);
    }
    order.push_back(v);
}
void dfsr(ll v, ll cur_id)
{
    cid[v] = cur_id;
    sz[cur_id]++;
    for (ll to : gr[v])
    {
        if (cid[to] == -1)
            dfsr(to, cur_id);
        else if (cid[to] != cid[v] and cid[to] > 0)
            g_cond[cid[to]].push_back(cid[v]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, comp_cnt = 0;
    cin >> n >> m;
    order.reserve(n);

    for (int i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (cid[i] == 0)
            dfs(i);
    }

    reverse(order.begin(), order.end());
    for (int v : order)
    {
        if (cid[v] == -1)
            dfsr(v, ++comp_cnt);
    }
    // конденсация
    for (int i = 1; i <= comp_cnt; ++i)
    {
        sort(g_cond[i].begin(), g_cond[i].end());
        g_cond[i].erase(unique(g_cond[i].begin(), g_cond[i].end()), g_cond[i].end());
    }

    cout << "Nodes in condensation: " << comp_cnt << "\n";
    for (int i = 1; i <= comp_cnt; ++i)
    {
        cout << "Comp " << i << " (size " << sz[i] << ") leads to: ";
        for (ll to : g_cond[i])
            cout << to << " ";
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
