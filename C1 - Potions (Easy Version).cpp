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
vector<ll> A ; 
vector<vector<ll>> DP ; 
void solve()
{
    int n ; cin >> n ; 
    A.resize(n+1);
    DP.resize(n+1,vector<ll>(n+1));
    for ( int i = 1 ; i <= n ; ++i ) cin >> A[i] ; 
    for (int i = 1; i <= n; i++) cin >> A[i];
    for(int i=1;i<=n;i++) DP[0][i]=-1e18;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        DP[i][j]=DP[i-1][j];
        if(DP[i-1][j-1] >= 0) DP[i][j]=max(DP[i][j],A[i]+DP[i-1][j-1]);
    }
    ll ans = 0 ;
    for(int i=0;i<=n;i++) if(DP[n][i]>=0) ans=i;
    cout << ans;
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
