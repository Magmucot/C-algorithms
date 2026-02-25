#include <bits/stdc++.h>
using namespace std;

// Z и Pi функция для строк

using ll = long long;
vector<ll> z_func(string s){
    ll n = s.size();
    ll l = 0, r = 0;
    vector<ll> z(n, 0);

    for(ll i=1; i < n;++i){
        if(i < r)
            z[i] = min(z[i - l], r - i);
        while(i + z[i] < n and s[z[i]] != s[z[i] + i])
            ++z[i];
        
        if(i + z[i] > r)
            l = i;
            r = i + z[i];
    }
    return z;
}
vector<ll> pi_func(string s){
    ll n = s.size();
    vector<ll> pi(n, 0);
    for(ll i = 1; i < n; ++i){
        ll j = pi[i - 1];

        while(j > 0 and s[i] != s[j])
            j = pi[j - 1];

        if(s[i] == s[j])
            j += 1;

        pi[i] = j;}
    return pi;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "\n";
    return 0;
}
