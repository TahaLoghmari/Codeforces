#include <bits/stdc++.h>
using namespace std;
#define TCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
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
 
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
 
void solve()
{
    int n ; cin >> n ; 
    string s ; cin >> s ; 
    vector<char> Output(n);
    DisjointSet PhaseShift(26) ; 
    vector<bool> Used(26);
    map<char,char> Track ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        for ( int j = 0 ; j < 26 ; ++j ) 
        {
            if ( Track[s[i]] != '\0' )
            {
                Output[i] = Track[s[i]] ; break; 
            }  
            bool IsIt = PhaseShift.findUPar( j ) == PhaseShift.findUPar( s[i] - 'a' );
            if ( IsIt || (s[i] - 'a' ) ==  j  || Used[j] ) continue;
            PhaseShift.unionBySize( j , s[i] - 'a' ) ; 
            Track[s[i]] = 'a' + j ; 
            Used[j] = true ;  
            Output[i] = 'a' + j ; 
            break;
        }
    }
    for ( int i = 0 ; i < n ; ++i ) 
    {
        for ( int j = 0 ; j < 26 ; ++j ) 
        {
            if ( Used[j] || Output[i] != '\0' ) continue;
            Output[i] = 'a' + j ; 
        }
    }
    for ( int i = 0 ; i < n ; ++i ) 
    {
        cout << Output[i] ; 
    }
    cout << endl ; 
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
    cin >> t ; 
    while ( t-- ) solve();
    return 0;
}
