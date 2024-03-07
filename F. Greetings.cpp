#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD 998244353
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
class Solution 
{
public:
class SegmentTree {
private:
    vector<ll> tree;
    ll n;
    void Build(const vector<ll>& arr, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            ll tm = (tl + tr) / 2;
            Build(arr, v*2, tl, tm);
            Build(arr, v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1] ; 
        }
    }
    ll Query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) 
            return tree[v];
        ll tm = (tl + tr) / 2;
        ll Choice1 = Query(v*2, tl, tm, l, min(r, tm));
        ll Choice2 = Query(v*2+1, tm+1, tr, max(l, tm+1), r);
        return Choice1+Choice2;
    }
    void Update(ll v, ll tl, ll tr, ll pos, ll val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                Update(v*2, tl, tm, pos, val);
            else
                Update(v*2+1, tm+1, tr, pos, val);
            tree[v] = tree[v*2] + tree[v*2+1] ;
        }
    }
public:
    SegmentTree(const vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        Build(arr, 1, 0, n - 1); 
    }
    ll Query(int l, int r) {
        return Query(1, 0, n - 1, l, r);
    }
    void Update(ll pos, ll val) {
        Update(1, 0, n - 1, pos, val);
    }
};
void solve()
{
    ll n , Count = 0 ; cin >> n ; 
    vector<ll> B , A , Prefix(n);
    SegmentTree Know(Prefix);
    map<int,int> Which ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        ll a , b ; cin >> a >> b ; 
        B.push_back(b);
        A.push_back(a);
        Which[a] = b ; 
    }
    Sort(A); Sort(B); 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        auto It = lower_bound(B.begin(),B.end(),Which[A[i]]) ; 
        ll Where = n - (It - B.begin()) - 1 , Minus = Know.Query(Where,n-1) ; 
        Count += Where - Minus; 
        Know.Update(Where,1) ; 
    }
    cout << Count << endl ; 
}
};
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    IWillWinTCPC ;   
    cout<<fixed<<setprecision(14);
    int t = 1 ; 
    cin >> t ; 
    while ( t-- ){ Solution Sol ; Sol.solve(); } 
    return 0;
}
