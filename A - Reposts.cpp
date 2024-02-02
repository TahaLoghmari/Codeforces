#include <bits/stdc++.h>
using namespace std;
#define TCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "no" << endl  
#define Yes cout << "yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD 998244353
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
 
vector<int> Dist(204,1);
string toUpperCase(const std::string& str) 
{
    string result = str;
    for (char& c : result) {
        c = toupper(c);
    }
    return result;
}
void dfs ( int root , vector<vector<int>> Graph , vector<bool>& Vis ) {
    Vis[root] = true ; 
    for ( auto u : Graph[root] ) {
        if ( !Vis[u] ) {
            Dist[u] = Dist[root] + 1 ;dfs( u , Graph , Vis ) ; 
        }
    }
}
void solve(){
    int n ; cin >> n ; 
    vector<vector<int>> Graph( n + 2 ) ;
    vector<bool> Vis(n + 2 );
    string Name1 , Waste , Name2 ;
    map<string,int> Track ; 
    for ( int i = 0 ; i < n ; ++i ) {
        cin >> Name1 >> Waste >> Name2 ; 
        Name1 = toUpperCase(Name1); Name2 = toUpperCase(Name2);
        if ( Track[Name1] == 0 ) Track[Name1] = i + 2; 
        if ( Track[Name2] == 0 ) Track[Name2] = i + 1; 
        Graph[Track[Name2]].push_back(Track[Name1]);
    }
    dfs(1 , Graph , Vis ) ; 
    int Max = *max_element(Dist.begin(),Dist.end()); 
    cout << Max << endl ; 
}        
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    TCPC ;   
    cout<<fixed<<setprecision(14);
    int t = 1 ; 
    // cin >> t ; 
    while ( t-- ) solve();
    return 0;
}
