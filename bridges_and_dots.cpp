#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 100005;
vector<int> g[MAXN];
int tin[MAXN], tout[MAXN], low[MAXN];
bool visited[MAXN], dots[MAXN];
int timer = 0;
vector<pair<int, int>> bridges;
void dfs(int v, int parent = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (auto to : g[v])
    {
        if (to == parent)
            continue;
        if (!visited[to])
        {
            children++;
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if (low[to] > tin[v])
                bridges.push_back({v, to});

            if (parent != -1 and low[to] >= tin[v])
                dots[v] = true;
        }
        else
            low[v] = min(low[v], tin[to]);
    }
    if (parent == -1 and children > 1)
    {
        dots[v] = true;
    }
    tout[v] = timer++;
}
void find_bridges_dots(int n)
{
    timer = 0;
    bridges.clear();
    fill(visited, visited + n + 1, false);

    for (int v = 1; v <= n; ++v)
    {
        if (!visited[v])
            dfs(v);
    }
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

    find_bridges_dots(n);

    for (int v = 1; v <= n; v++)
    {
        cout << "Вершина " << v << ": tin=" << tin[v] << ", tout=" << tout[v] << "\n";
    }

    cout << "Количество мостов: " << bridges.size() << "\n";
    for (auto &[u, v] : bridges)
    {
        cout << u << " — " << v << "\n";
    }

    cout << "Точки сочленения" << "\n";
    for (int v = 1; v <= n; ++v)
    {
        if (dots[v])
            cout << v << " ";
    }

    cout << "\n";
    return 0;
}
