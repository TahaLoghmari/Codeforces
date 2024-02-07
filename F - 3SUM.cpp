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
#define Sum( A , Start ) accumulate( A.begin() , A.end() , (int)Start ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
 
 
void solve()
{
    int n ; cin >> n ; 
    vector<int> A(n) ;
    for ( int i = 0 ; i < n ; ++i ) 
    {
        int x ; cin >> x ; 
        A[i] = x % 10 ; 
    }
    map<int,int> Exist ; 
    for ( int i = 0 ; i < n ; ++i ) Exist[A[i]]++; 
    for ( int i = 0 ; i <= 9 ; ++i ) 
    {
        for ( int j = 0 ; j <= 9 ; ++j ) 
        {
            for ( int k = 0 ; k <= 9 ; ++k ) 
            {
                map<int,int> Track; 
                if ( (i + j + k) == 23 || (i + j + k) == 3 || (i + j + k) == 13 )
                {
                    Track[i]++ ; Track[j]++; Track[k]++;
                    if ( Exist[i] >= Track[i] && Exist[j] >= Track[j] && Exist[k] >= Track[k])
                    {
                        Yes ; return;
                    }
                }
            }
        }
    }
    No;
}      
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    TCPC ;   
    int t = 1 ; 
    cin >> t ; 
    while ( t-- ) solve();
    return 0;
}
