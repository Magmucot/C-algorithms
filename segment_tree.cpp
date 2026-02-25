#include <bits/stdc++.h>

// Дерево отрезков, с ленивыми опирациями

using namespace std;
using ll = long long;
constexpr ll INF = 0x7FFFFFFFFFFFFFFF;
constexpr ll MOD = 1e9 + 7;

struct Node
{
    ll sum, max, min;
    Node(ll sum = 0, ll min = INF, ll max = -INF) : sum(sum), min(min), max(max) {}

    static Node comp(const Node &a, const Node &b)
    {
        Node res;
        res.sum = a.sum + b.sum;
        res.max = std::max(a.max, b.max);
        res.min = std::min(a.min, b.min);
        return res;
    }
    Node operator+(const Node &b) { return comp(*this, b); }
};
static Node Base = Node{};


struct SegTree
{
    vector<Node> tree;
    ll ln;
    vector<ll> arr;
    MySegTree(vector<ll> lst){
        arr = lst;
        ln = lst.size();
        build(1, 0, ln - 1);}

    void build(ll v, ll tl, ll tr){
        if (tl == tr){
            tree[v] = {arr[tl], arr[tl], arr[tl]};
            return;
        }
        ll tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    Node get(ll v,  ll l, ll r, ll tl, ll tr){
        if (r < tl or l > tr){
            return Base;
        }
        if (l <= tl and tr <= r) // !!!!!!!!!!!!
            return tree[v];
        ll tm = (tl + tr) / 2;
        Node L = get(2 * v, l, r, tl, tm);
        Node R = get(2 * v + 1, l, r, tm + 1, tr);
        return L + R;
    }
    void update(ll v, ll pos, ll val, ll tl, ll tr){
        if (pos < tl or pos > tr){
            return;
        }
        if (tl == tr){
            tree[v] = {val, val, val};
            return;}
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, pos, val, tl, tm);
        else
            update(2 * v + 1, pos, val, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
};










struct MySegmentTree
{
    vector<Node> tree;
    ll n;
    vector<ll> arr;

    MySegmentTree(vector<ll> &a)
    {
        arr = a;
        n = a.size();
        tree.assign(4 * n, Base);
        build(1, 0, n - 1);
    }
    MySegmentTree(ll ln)
    {
        n = ln;
        arr.assign(n, 0);
        tree.assign(4 * n, Base);
    }

    void build(ll v, ll tl, ll tr)
    {
        if (tl == tr)
        {
            tree[v] = {arr[tr], arr[tr], arr[tr]};
            return;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }
    Node get(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (r < tl or l > tr)
            return Base;
        if (l <= tl and tr <= r)
            return tree[v];
        ll tm = (tl + tr) / 2;
        Node L = get(2 * v, tl, tm, l, r), R = get(2 * v + 1, tm + 1, tr, l, r);
        return L + R;
    }
    void update(ll v, ll pos, ll val, ll tl, ll tr)
    {
        if (pos < tl or tr < pos)
            return;

        if (tl == tr)
        {
            tree[v] = Node(val, val, val);
            return;
        }

        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, pos, val, tl, tm);
        else
            update(2 * v + 1, pos, val, tm + 1, tr);

        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    void add(ll pos, ll delta)
    {
        arr[pos] += delta;
        update(1, pos, arr[pos], 0, n - 1);
    }
    void set(ll pos, ll val)
    {
        arr[pos] = val;
        update(1, pos, val, 0, n - 1);
    }
    ll getsum(ll l, ll r)
    {
        return get(1, 0, n - 1, l, r).sum;
    }
    ll getmax(ll l, ll r)
    {
        return get(1, 0, n - 1, l, r).max;
    }
    ll getmin(ll l, ll r)
    {
        return get(1, 0, n - 1, l, r).min;
    }
    ll size()
    {
        return n;
    }
    ll get_val(ll pos)
    {
        return arr[pos];
    }
};

// ===== ТЕСТЫ =====
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //

    // Тест 1
    vector<ll> a = {3, 1, 4, 1, 5, 9};
    SegTree st(a);

    cout << "=== Тест 1: vector ===" << "\n";
    cout << "Sum [0, 5] = " << st.getsum(0, 5) << "\n"; // 23
    cout << "Sum [1, 4] = " << st.getsum(1, 4) << "\n"; // 11

    cout << "\nSet arr[2] = 10" << "\n";
    st.set(2, 10);                                      // pos=2, val=10
    cout << "Sum [0, 5] = " << st.getsum(0, 5) << "\n"; // 29

    cout << "\nAdd arr[0] += 7" << "\n";
    st.add(0, 7);
    // Используем get_val или getsum(0,0)
    cout << "arr[0] = " << st.get_val(0) << "\n";
    cout << "Sum [0, 5] = " << st.getsum(0, 5) << "\n"; // 36

    // Тест 2
    cout << "\n=== Тест 2: empty tree ===" << "\n";
    MySegmentTree st2(5);
    cout << "Sum [0, 4] = " << st2.getsum(0, 4) << "\n"; // 0

    st2.set(2, 100);                                                        // pos=2, val=100
    cout << "After set(2, 100): Sum [0, 4] = " << st2.getsum(0, 4) << "\n"; // 100

    // Тест 3
    cout << "\n=== Тест 3: input ===" << "\n";
    // Пример ввода:
    // 5 3
    // 1 2 3 4 5
    // s 0 4
    // u 2 10
    // s 0 4

    ll n, m;
    if (cin >> n >> m)
    {
        vector<ll> arr(n);
        for (ll i = 0; i < n; ++i)
            cin >> arr[i];

        MySegmentTree tree(arr);

        for (ll i = 0; i < m; ++i)
        {
            char type;
            cin >> type;
            if (type == 's')
            {
                ll l, r;
                cin >> l >> r;
                cout << tree.getsum(l, r) << "\n";
            }
            else if (type == 'u')
            {
                ll pos, val;
                cin >> pos >> val;
                tree.set(pos, val);
            }
        }
    }

    return 0;
}

