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
void solve()
{
    ll n ; cin >> n ;
    map<string,ll> Track ; 
    map<string,ll> Final ; 
    vector<pair<string,ll>> Store(n) ;  
    for ( int i = 0 ; i < n ; ++i ) 
    {
        string s ; ll x ; cin >> s >> x ; 
        Track[s] += x ; 
        Store[i].first = s ;
        Store[i].second = Track[s] ; 
    }
    ll Maxi = 0 ; 
    for ( auto & d : Track ) Maxi = max( Maxi , (ll)d.second ) ;
    for ( auto & d : Track ) if ( d.second == Maxi ) Final[d.first] = 1 ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( Store[i].second >= Maxi && Final[Store[i].first] == 1 )
        {
            cout << Store[i].first << endl ; 
            return ; 
        }
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
