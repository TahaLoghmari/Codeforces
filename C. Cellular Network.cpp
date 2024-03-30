#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "NO" << endl  
#define Yes cout << "YES" << endl  
#define CB(x) 64 - __builtin_clzll(x) 
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD (ll)(1e9+7)
#define BS(A,x) binary_search(A.begin(),A.end(),x)
#define INF LONG_LONG_MAX 
#define Sum(A) accumulate( A.begin() , A.end() , (ll)0 ) 
#define Max(A) (ll)(*max_element(A.begin(),A.end()))
#define Min(A) (ll)(*min_element(A.begin(),A.end()))
#define endl '\n' 
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
#define Inverse(x) (((1ll<<CB(x))-1)^x)
#define CountOnes(x) __builtin_popcountll(x)
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution 
{
public:
class SegmentTree {
private:
    ll n;
    vector<ll> a, Tree, Lazy;
    void Check(ll p, ll s, ll e) {
        if (Lazy[p] != 0) {
            Tree[p] += Lazy[p];
            if (s != e) {
                Lazy[2 * p] += Lazy[p];
                Lazy[2 * p + 1] += Lazy[p];
            }
            Lazy[p] = 0;
        }
    }
    void Build(ll p, ll s, ll e) {
        Check(p, s, e);

        if (s == e) {
            Tree[p] = a[s];
            return;
        }

        Build(2 * p, s, (s + e) / 2);
        Build(2 * p + 1, (s + e) / 2 + 1, e);

        Tree[p] = min(Tree[2 * p], Tree[2 * p + 1]);
    }
    void Update(ll p, ll s, ll e, ll i, ll v) {
        Check(p, s, e);
        if (s == e) {
            Tree[p] = v;
            return;
        }
        if (i <= (s + e) / 2)
            Update(2 * p, s, (s + e) / 2, i, v);
        else
            Update(2 * p + 1, (s + e) / 2 + 1, e, i, v);

        Tree[p] = min(Tree[2 * p], Tree[2 * p + 1]);
    }
    void Update(ll p, ll s, ll e, ll a, ll b, ll v) {
        Check(p, s, e);
        if (s >= a && e <= b) {
            Tree[p] += v;
            if (s != e) {
                Lazy[2 * p] += v;
                Lazy[2 * p + 1] += v;
            }
            return;
        }
        if (s > b || e < a)
            return;
        Update(2 * p, s, (s + e) / 2, a, b, v);
        Update(2 * p + 1, (s + e) / 2 + 1, e, a, b, v);
        Tree[p] = min(Tree[2 * p], Tree[2 * p + 1]);
    }
    ll Get(ll p, ll s, ll e, ll a, ll b) {
        Check(p, s, e);
        if (s >= a && e <= b)
            return Tree[p];
        if (s > b || e < a)
            return INT_MAX;
        return min(Get(2 * p, s, (s + e) / 2, a, b), Get(2 * p + 1, (s + e) / 2 + 1, e, a, b));
    }
public:
    SegmentTree(const vector<ll>& arr) {
        n = arr.size();
        a = arr;
        Tree.resize(4 * n);
        Lazy.resize(4 * n);
        Build(1, 0, n - 1);
    }
    void Update(ll index, ll value) {
        Update(1, 0, n - 1, index, value);
    }
    void UpdateRange(ll start, ll end, ll value) {
        Update(1, 0, n - 1, start, end, value);
    }
    ll Gett(ll start, ll end) {
        return Get(1, 0, n - 1, start, end);
    }
};
void solve()
{
    int n , m ; cin >> n >> m ; 
    vector<int> Cities(n) , Towers(m); Take(Cities) ; Take(Towers);
    ll l = 0 , r = 1e10 , Ans = 0 ; 
    while ( l <= r )
    {
        vector<ll> Seg(n) ; 
        SegmentTree Check(Seg);
        ll middle = ( l + r ) / 2 ;
        bool Can = true ; 
        for ( int i = 0 ; i < m ; ++i ) 
        {
            ll First = lower_bound(Cities.begin(),Cities.end(),Towers[i]-middle) - Cities.begin();
            ll Second = upper_bound(Cities.begin(),Cities.end(),Towers[i]+middle) - Cities.begin() ;
            Second--;
            Check.UpdateRange(First,Second,1);
        } 
        for ( int i = 0 ; i < n ; ++i ) 
        {
            if ( Check.Gett(i,i) == 0 ) Can = false ; 
        }
        if ( Can )
        {
            r = middle - 1 ;
            Ans = middle ; 
        }  
        else l = middle + 1 ; 
    }  
    cout << Ans << endl ; 
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
    // cin >> t ; 
    while ( t-- ){ Solution Sol ; Sol.solve(); } 
    return 0;
}
