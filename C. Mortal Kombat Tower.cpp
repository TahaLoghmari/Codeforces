#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_pbds;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
// bool sortinc(pair<int,int> &a,pair<int,int> &b){ if ( a.second == b.second ) return a.first < b.first ;  else  (a.second < b.second);}
// bool sortdec(pair<int,int> &a,pair<int,int> &b){ if ( a.second == b.second ) return a.first > b.first ;  else  (a.second > b.second);}
#define SortPI(x) sort(x.begin(),x.end(),sortinc);
#define SortPD(x) sort(x.begin(),x.end(),sortdec);
#define MOD 998244353
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution 
{
public:
int n ; 
vector<ll> A ;
vector<vector<ll>> DP ;  
ll Work ( int i , int Turn ) 
{
    if ( i >= n ) return 0 ;
    if ( DP[i][Turn] != - 1 ) return DP[i][Turn] ;   
    ll First = ( Turn == 0 ? ( (A[i] == 1) ? 1 : 0) : 0 ) + Work( i + 1 , (Turn^1));
    ll Second = ( Turn == 0 ? ( (A[i] == 1) ? 1 : 0) : 0 ) + ( Turn == 0 ? ( (A[i+1] == 1) ? 1 : 0) : 0 ) + Work( i + 2 , (Turn^1) );
    return DP[i][Turn] = min( First , Second ) ;
}
void solve()
{
    cin >> n ; A.resize(n); Take(A) ; 
    DP.resize(n,vector<ll>(2,-1));
    ll Result = Work( 0 , 0 ) ;  
    cout << Result << endl ;  
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
