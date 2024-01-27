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
 
int Count = 0 ; 
 
bool canMove(int i, int j , int n , int m ) 
{
    return i > -1 && i < n && j >- 1 && j < m ;
}
string WhichWay ( string s1 , string s2 , int i , int j ) 
{
    if ( s1[i] == '<' && s2[j] == '^') return "LU";
    if ( s1[i] == '>' && s2[j] == 'v') return "RD";
    if ( s1[i] == '<' && s2[j] == 'v') return "LD";
    if ( s1[i] == '>' && s2[j] == '^') return "RU";
}
 
void bfs ( vector<vector<string>>& M , int i , int j , int n , int m , vector<vector<bool>>& Vis ) 
{
    Vis[i][j] = true ;
    queue<int> First ; 
    queue<int> Second ; 
    First.push(i);
    Second.push(j);
    while ( ! First.empty() ) 
    {
        int x = First.front() ; 
        int y = Second.front() ; 
        First.pop(); Second.pop() ; 
        if ( M[x][y][0] == 'L' && canMove( x , y - 1 , n , m ) && !Vis[x][y-1] )
        {
            Count++;
            First.push( x ) ; Second.push( y - 1 ) ;
            Vis[x][y-1] = true ;  
        }
        if ( M[x][y][1] == 'U' && canMove( x - 1 , y , n , m ) && !Vis[x-1][y])
        {
            Count++;
            First.push( x - 1 ) ; Second.push( y ) ;
            Vis[x-1][y] = true ; 
        }
        if ( M[x][y][0] == 'R' && canMove( x  , y + 1 , n , m ) && !Vis[x][y+1])
        {
            Count++;
            First.push( x ) ; Second.push( y + 1 ) ;
            Vis[x][y+1] = true ; 
        }
        if ( M[x][y][1] == 'D' && canMove( x + 1  , y , n , m ) && !Vis[x+1][y])
        {
            Count++;
            First.push( x + 1) ; Second.push( y ) ;
            Vis[x+1][y] = true ; 
        }
    } 
}
void solve()    
{
    int n , m ; cin >> n >> m ; 
    vector<vector<string>> M(n,vector<string>(m," "))  ; 
    string s1 , s2 ; cin >> s1 >> s2 ; 
    int k = 0 ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        for ( int j = 0 ; j < m ; ++j ) 
        {
            M[i][j] = WhichWay( s1 , s2 , i , j ) ; 
        }
    }
    vector<vector<bool>> Vis(n,vector<bool>(m,false));
    for ( int i = 0 ; i < n ; ++i ) 
    {
        for ( int j = 0 ; j < m ; ++j ) 
        {
            vector<vector<bool>>Vis(n,vector<bool>(m,false));
            Count = 0 ; 
            bfs( M , i , j , n , m , Vis ) ; 
            int tryy = Count ; 
            if ( Count != ( ( m * n ) - 1 ) ) 
            {
                No ; return ; 
            }
        }
    }
    Yes ; 
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
