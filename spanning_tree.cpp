#include <bits/stdc++.h>
using namespace std;

// Алгоритмы поиска минимального остовного дерева

using ll = long long;
const ll INF = 1e18;
pair<vector<ll>, vector<ll>> dijkstra(ll start, ll n, vector<vector<pair<ll, ll>>> &g)
{

    priority_queue<pair<ll, ll>,
                   vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>>
        pq;
    vector<ll> d(n + 1, INF), parent(n + 1, -1);
    d[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [dist_v, v] = pq.top();
        pq.pop();
        if (dist_v > d[v])
            continue;
        for (auto [to, w] : g[v])
        {
            if (d[to] > w + d[v] and d[v] < INF)
            {
                d[to] = w + d[v];
                pq.push({d[to], to});
                parent[to] = v;
            }
        }
    }
    return {d, parent};
}

struct Edge
{
    ll from, to, w;
};

pair<vector<ll>, bool> ford(ll start, ll n, vector<Edge> &edges)
{
    vector<ll> d(n + 1, INF);
    d[start] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        bool changes = false;
        for (auto &e : edges)
        {
            if (d[e.from] < INF and d[e.to] > d[e.from] + e.w)
            {
                d[e.to] = d[e.from] + e.w;
                changes = true;
            }
        }
        if (!changes)
            break;
    }
    bool hasneg = false;
    for (auto &e : edges)
    {
        if (d[e.from] < INF and d[e.to] > d[e.from] + e.w)
        {
            d[e.to] = d[e.from] + e.w;
            hasneg = true;
            break;
        }
    }
    return {d, hasneg};
}

vector<vector<ll>> floid(ll n, vector<vector<ll>> &d)
{
    for (int k = 1; k < n + 1; ++k)
    {
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (d[i][k] < INF and d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}

pair<ll, vector<pair<ll, ll>>> prim(ll start, ll n, vector<vector<pair<ll, ll>>> &g)
{
    vector<bool> inMST(n + 1, false);
    vector<ll> parent(n + 1, -1);
    vector<ll> minEdge(n + 1, INF);

    priority_queue<pair<ll, ll>,
                   vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>>
        pq;

    pq.push({0, start});
    ll cnt = 0;
    vector<pair<ll, ll>> mstEdges;

    while (!pq.empty())
    {
        auto [w, v] = pq.top();
        pq.pop();

        if (inMST[v])
            continue;
        inMST[v] = true;
        cnt += w;

        if (parent[v] != -1)
            mstEdges.push_back({v, parent[v]});

        for (auto [to, w1] : g[v])
        {
            if (!inMST[to] and w1 < minEdge[to])
            {
                minEdge[to] = w1;
                parent[to] = v;
                pq.push({w1, to});
            }
        }
    }
    return {cnt, mstEdges};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        ll from, to, w;
        cin >> from >> to >> w;
        g[from].push_back({to, w});
        // g[to].push_back({from, w});
        edges[i].w = w;
        edges[i].to = to;
        edges[i].from = from;
    }
    auto [df, hasneg] = ford(1, n, edges);
    /*auto [d, parent] = dijkstra(1, n, g);
    cout << "deikstra\n";
    for (auto v : d)
        cout << (v == INF ? -1 : v) << " ";*/
    cout << "\nford\n";
    cout << (hasneg ? "есть отриц. цикл\n" : "нормальный граф\n");
    for (auto v : df)
        cout << (v == INF ? -1 : v) << " ";
    cout << "\n";
    return 0;
}
