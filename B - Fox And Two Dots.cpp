#include <bits/stdc++.h>
using namespace std ;
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
 
const int N = 51 ;
int Parentx , Parenty ;  
int Count = 0 ;
vector<vector<char>> M( N , vector<char> ( N , ' ' ) ) ;
vector<int> dx = { 1 , 0 , -1 , 0 };
vector<int> dy = { 0 , 1 , 0 , -1 };
bool canMove( int i , int j , int n , int m , char Start )
{
    return i > - 1 && i < n && j > - 1 && j < m && M[i][j] == Start ; 
}
bool isCyclic ( int i , int j , vector<vector<bool>>& Vis , int n , int m , char Start )
{
    Vis[i][j] = true ; 
    Count++;
    for ( int x = 0 ; x < dx.size() ; ++x ) 
    {
        int IN = i + dx[x] , JN = j + dy[x] ; 
        if ( Count >= 4 && canMove( IN , JN , n , m , Start ) && Vis[IN][JN] && IN == Parentx && JN == Parenty ) 
            return true ; 
        else if ( canMove ( IN , JN , n , m , Start ) && !Vis[IN][JN] && isCyclic( IN , JN , Vis , n , m , Start ) ) 
        return true ; 
    }
    Count--;
    return false ; 
}
 
void solve()
{
    int n , m ; cin >> n >> m ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        for ( int j = 0 ; j < m ; ++j ) 
        {
            char a ; cin >> a ; 
            M[i][j] = a ;
        }
    }
    for ( int i = 0 ; i < n ; ++i ) 
    {
        for ( int j = 0 ; j < m ; ++j ) 
        {
            Count = 0 ; 
            Parentx = i ; Parenty = j ; 
            vector<vector<bool>> Vis(n,vector<bool>(m,false));
            if ( isCyclic( i , j , Vis , n , m , M[i][j] ) == true )
            {
                Yes ; return ; 
            }
        }
    }
    No ; 
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
