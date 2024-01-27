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
 
 
void solve()
{
    int n , SubstringCount = 0 ; cin >> n ; string s ; cin >> s; 
    for ( int i = 0 ; i < n ; ++i )
    {
        int Count = 0 , Distinct = 0 , MaxOcc = 0  ; 
        vector<int> CountD(10,0);
        for ( int j = i ; j < min ( i + 100 , n ) ; ++j ) 
        {
            if ( CountD[s[j]-'0'] == 0 ) Distinct++; 
            CountD[ s[j] - '0' ]++; 
            MaxOcc = max ( MaxOcc , CountD[ s[j] - '0' ] ) ; 
            if ( MaxOcc <= Distinct ) SubstringCount++;
        }
    }
    cout << SubstringCount << endl ; 
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
