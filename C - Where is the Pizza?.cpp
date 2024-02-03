#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD (int)( 1e9 + 7 ) 
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
#define isSorted(x) is_sorted(A.begin(),A.end())
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS  
*/
class DisjointSet {
public: 
    vector<int>size , parent ; 
    DisjointSet(int n) { 
        size.resize(n+3); 
        parent.resize(n+3);
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
    int findboss(int node) { // findultimateparent       /// log (n) 
        if(node == parent[node])
            return node; 
        return parent[node] = findboss(parent[node]); 
    }
    void unionset(int u, int v) {     /// log (n) 
        int x = findboss(u); 
        int y = findboss(v); 
        if(x == y) return; 
        if ( size[x] >= size[y] ) swap(x,y);
        parent[x] = y; 
        size[y] += size[x]; 
    }
};

void solve()
{
    int n , Res = 2 ; cin >> n ; 
    vector<int> A(n) , B(n) , C(n) ; Take(A) ; Take(B) ; Take(C) ; 
    DisjointSet Graph(n);
    for ( int i = 0 ; i < n ; ++i ) Graph.unionset(A[i],B[i]);
    set<int> DistinctParents ; 
    for ( int i = 0 ; i < n ; ++i ) DistinctParents.insert(Graph.findboss(B[i])) ; 
    for ( int i = 0 ; i < n ; ++i )
    if ( C[i] != 0 || A[i] == B[i] ) DistinctParents.erase(Graph.findboss(B[i]));
    for ( int i = 0 ; DistinctParents.size() != 0 && i < DistinctParents.size() - 1 ; i++ )
    {
        Res *= 2;
        Res %= MOD;
    }
    cout << (DistinctParents.size() == 0 ? 1 : Res % MOD) << endl ; 
}
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
    while ( t-- ) solve();
    return 0;
}
