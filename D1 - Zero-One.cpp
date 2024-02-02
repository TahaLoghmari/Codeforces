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
 
 
void solve() {
	int n , k ; cin >> n >> k ; 
    vector<int> A(n) , Ok(n) ; Take(A) ; 
    for ( int i = 0 ; i < n - 1 ; ++i ) Ok[i] = A[i] < 2* A[i+1] ; 
    int NumberOf1s = 0 , Total = 0 , l = 0 ; 
    for ( int i = 0 ; i < k ; ++i ) NumberOf1s += Ok[i] == 1 ; 
    if ( NumberOf1s == k ) Total++;
    for ( int r = k ; r < n ; ++r ) 
    {
        NumberOf1s -= Ok[l] ; 
        NumberOf1s += Ok[r] ; 
        l++;
        Total += NumberOf1s == k ; 
    }
    cout << Total << endl ; 
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
