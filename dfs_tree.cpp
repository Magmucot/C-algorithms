#include <bits/stdc++.h>

// Дфс дерево

using namespace std;
using ll = long long;
const int MAXN = 100005;
vector<int> g[MAXN];
int tin[MAXN], tout[MAXN];
bool visited[MAXN];
int timer = 0;
void dfs(int v, int parent = -1)
{
    visited[v] = true;
    tin[v] = timer++;

    for (auto to : g[v])
    {
        if (to == parent)
            continue;
        if (!visited[to])
            dfs(to, v);
    }
    tout[v] = timer++;
}

bool isAncestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for (int v = 1; v <= n; v++)
    {
        cout << "Вершина " << v << ": tin=" << tin[v] << ", tout=" << tout[v] << "\n";
    }

    return 0;
}
