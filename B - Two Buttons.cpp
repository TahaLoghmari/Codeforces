#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define int long long 
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
void augmentedBFS ( int src , int dest , vector<vector<int>>& Graph , vector<int>& dist , vector<bool>& Visited )  
{
    queue<int> q ; 
    q.push(src) ; 
    Visited[src] = true ; 
    dist[src] = 0 ; 
    while ( !q.empty() ) 
    {
        int parent = q.front() ; 
        q.pop() ; 
        for ( auto child : Graph[parent] ) 
        {
            if ( !Visited[child] ) 
            {
                Visited[child] = true ; 
                q.push(child) ; 
                dist[child] = 1 + dist[parent];
            }
        }
    }
}
void solve()    
{
    
    int n , m ; cin >> n >> m ; 
    const int N = 1e5 + 7 ; 
    vector<bool> Visited(N); 
    vector<vector<int>> Graph(N) ;
    vector<int> dist(N,1e18) ;
    if ( n == m )
    {
        cout << 0 << endl ; return ; 
    }
    if ( n > m ) 
    {
        cout << n - m << endl ; return ; 
    }
    int mMax = ( m - 1 ) * 2 ;
    for ( int i = 1 ; i <= mMax ; ++i ) 
    {
        if ( (2 * i) <= mMax ) Graph[i].push_back( i*2 );
        if ( i - 1 > 0 ) Graph[i].push_back(i-1);  
    }
    augmentedBFS( n , m  , Graph , dist , Visited ) ; 
    cout << dist[m] << endl; 
}        
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    TCPC ;   
    int t = 1 ; 
    // cin >> t ; 
    while ( t-- ) solve();
    return 0 ;
}
