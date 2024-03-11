#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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
vector<ll> Players ;
const int N = 2000 ; 
vector<pair<char,ll>> Throws ;
vector<vector<bool>> DP ;  
ll Count = 0 ; 
void Work ( ll x , ll m , ll n , ll index ) 
{
    if ( DP[index][x] ) return ; 
    DP[index][x] = true ;
    if ( index == m ) 
    {
        Players.push_back(x);
        Count++;
        return;
    }  
    char First = Throws[index].first ; 
    ll Second = Throws[index].second ; 
    if ( First == '0' ) Work( (x+Second>n?(x + Second)%(n+1)+1:x+Second) , m , n , index + 1 );
    else if ( First == '1' ) Work( (x-Second<=0? (x - Second)+n:x-Second) , m , n , index + 1 ) ;
    else
    {
        Work( (x+Second>n?(x + Second)%(n+1)+1:x+Second) , m , n , index + 1 ) ;
        Work( (x-Second<=0? (x - Second)+n:x-Second) , m , n , index + 1 ) ;
    }
}
void solve()
{
    ll n , m , x ; cin >> n >> m >> x ; 
    DP.resize(n+1000,vector<bool>(n+1000,false));
    for ( int i = 0 ; i < m ; ++i ) 
    {
        ll r ; char c ; cin >> r >> c ; 
        Throws.push_back({c,r});
    } 
    for ( int i = 0 ; i < 10 ; ++i ) Throws.push_back({' ',0});
    Work(x , m , n , 0 ) ; 
    Sort(Players);
    cout << Count << endl ; 
    for ( int i = 0 ; i < Players.size() ; ++i ) 
    {
        cout << Players[i] << " " ; 
    }
    cout << endl ; 
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
