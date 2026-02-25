#include <bits/stdc++.h>
using namespace std;

/*
Базовый dfs и bfs на графах, также небольшие улушения для поиска циклов и тд, а также считывание графов
*/

const int MAXN = 100005; 
vector<int> g[MAXN];
bool visited[MAXN];

void dfs(int u)
{
    visited[u] = true;
    cout << "Зашли в вершину: " << u << "\n";
    for (int v : g[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
        else
            cout << "Есть цикл";
    }
}
void start_dfs(int n)
{
    int cnt = 0;
    cout << "Старт обхода:" << "\n";
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}

vector<int> bfs(int start_node, int n, vector<int> g[])
{
    vector<int> dist(n + 1, -1);
    deque<int> q;

    dist[start_node] = 0;
    q.push_back(start_node);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();

        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push_back(v);
            }
        }
    }
    return dist;
}
vector<int> my_bfs(int start, int n, vector<int> g[])
{
    vector<int> dist(n + 1, -1), p(n + 1, -1);
    deque<int> q;
    q.push_back(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push_back(v);
                p[v] = u;
            }
        }
    }
    return dist;
}
void start_bfs(int n, vector<int> g[])
{
    vector<int> res = my_bfs(2, n, g);
    cout << "------расстояния от вершины 2----" << "\n";
    for (auto f : res)
    {
        cout << f << "\n";
    }
}

bool has_cycle(int u, int p)
{
    visited[u] = 1;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        if (visited[v] == 1)
            return true;
        if (visited[v] == 0 && has_cycle(v, u))
            return true;
    }
    visited[u] = 2;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    return 0;
}
