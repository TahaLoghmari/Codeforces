#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define CB(x) 64 - __builtin_clzll(x) 
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD (ll)(1e9+7)
#define Sum(A) accumulate( A.begin() , A.end() , (ll)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
#define Inverse(x) (((1ll<<CB(x))-1)^x)
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution 
{
public:
vector<vector<int>> Graph ; 
vector<set<int>> Groups ;  
vector<bool> Vis ; 
void dfs( int Pos , int Parent ) 
{
    Vis[Pos] = true ; 
    for ( auto & d : Graph[Pos] ) 
    {
        if ( d != Parent ) Groups[Parent].insert(d);
        if ( !Vis[d] ) dfs( d , Parent ) ; 
    } 
}
void solve()
{
    int n , m ; cin >> n >> m ; 
    if ( m == 0 ) 
    {
        int j = 1 ; 
        for ( int i = 0 ; i < n/3 ; ++i ) 
        {
            cout << j << " " << j+1 << " " << j+2 << endl ; 
            j += 3 ; 
        }
        return;
    }
    Graph.resize(n+1);
    Groups.resize(n+1);
    Vis.resize(n+1);
    for ( int i = 0 ; i < m ; ++i ) 
    {
        int a , b ; cin >> a >> b ;
        a--;
        b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a); 
    }
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( !Vis[i] ) 
        {
            dfs(i,i);
        }
    }
    vector<bool> Done(n) ; 
    vector<int> Usefull ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( Groups[i].size() > 2 ) 
        {
            cout << -1 << endl ; return ; 
        }
    }
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( Groups[i].size() != 0 ) 
        {
            Done[i] = true ; 
            for ( auto & d : Groups[i] ) 
            {
                if ( i != d ) Done[d] = true ; 
            }
        }
    }
    ll S = Sum(Done);
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( !Done[i] ) Usefull.push_back(i);
    }
    ll Count = 0 ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( Groups[i].size() != 0 && Groups[i].size() < 2 && S == n ) 
        {
            cout << -1 << endl ; return ; 
        }
    }
    ll T = 0 ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( Groups[i].size() != 0 ) 
        {
            int Left = Groups[i].size() ;
            if ( Left < 2 && Usefull.size() != 0 && T >= Usefull.size() ) 
            {
                cout << -1 << endl ; return ; 
            }
            while ( Left < 2 )  
            {
                T++;
                Left++;
            }
        } 
    }
    T = 0;
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( Groups[i].size() != 0 ) 
        {
            cout << i + 1 << " " ;  
            for ( auto & d : Groups[i] ) 
            {
                if ( i != d ) cout << d + 1 << " " ; 
            }
            int Left = Groups[i].size() ;
            while ( Left < 2 )  
            {
                cout << Usefull[T++]+1 << " " ; 
                Left++;
            }
            cout << endl ;
        } 
    }
    while ( T < Usefull.size() ) 
    {
        for ( int i = 0 ; i <= 2 ; ++i ) cout << Usefull[T+i]+1 << " " ;
        T += 3 ; 
    }
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
