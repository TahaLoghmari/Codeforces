#include <bits/stdc++.h>
#define TCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
using namespace std;
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define Show(x) for ( auto & d : x ) cout << d << " " ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
 
void Recursion ( map<int,int>& Occ , int I , int Final ) 
{
    if ( I == 0 ) {
        Occ[Final]++;
        return;
    }
    Recursion( Occ , I - 1 , Final + 1 ) ;
    Recursion( Occ , I - 1 , Final - 1 ) ;
} 
void solve()
{
    string s1 , s2 ; 
    cin >> s1 >> s2 ; 
    int PS1 = 0 , PS2 = 0 , I = 0 ; 
    for ( int i = 0 ; i < s1.size() ; ++i ) {
        PS1 += s1[i] == '+' ? 1 : -1 ; 
        PS2 += s2[i] == '+' ? 1 : s2[i] == '-' ? -1 : 0 ;
        I += s2[i] == '?' ;  
    }
    map<int,int> Occ ; 
    Recursion ( Occ , I , PS2 ) ; 
    cout << setprecision(9) << fixed << (double)Occ[PS1]/pow(2,I) << endl ; 
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
