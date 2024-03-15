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
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
vector<vector<char>> M;
vector<vector<bool>> Vis ; 
bool x = false ; 
int n ; 
bool Work ( int Row , int i , bool Needed ) 
{
    if ( i == n || i < 0 || Row < 0 || Row > 1 ) return false ;  
    if ( Vis[Row][i] == true ) return false ; 
    Vis[Row][i] = true ; 
    if ( Row == 1 && i == n - 1 ) return true ;
    if ( Needed ) 
    {
        if ( M[Row][i] == '>' ) return Work( Row , i + 1 , false  ) ;
        else return Work( Row , i - 1 , false ) ; 
    }
    for ( int k = 0 ; k < 4 ; ++k ) x |= Work( Row + di[k] , i + dj[k] , true ) ; 
    return x ; 
}
void solve()
{
    cin >> n ; 
    string s1 , s2 ; cin >> s1 >> s2 ; 
    M.resize(2,vector<char>(n));
    Vis.resize(2,vector<bool>(n));
    for ( int i = 0 ; i < n ; ++i ) 
    {
        M[0][i] = s1[i] ; 
        M[1][i] = s2[i] ; 
    }
    cout << (Work(0,0,false) ? "Yes" : "No") << endl ; 
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
