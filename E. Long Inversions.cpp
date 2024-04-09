#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "NO" << endl  
#define Yes cout << "YES" << endl  
#define CB(x) 64 - __builtin_clzll(x) 
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD (ll)(1e9+7)
#define BS(A,x) binary_search(A.begin(),A.end(),x)
#define INF LONG_LONG_MAX 
#define Sum(A) accumulate( A.begin() , A.end() , (ll)0 ) 
#define Max(A) (ll)(*max_element(A.begin(),A.end()))
#define Min(A) (ll)(*min_element(A.begin(),A.end()))
#define endl '\n' 
#define All(x) x.begin(),x.end()
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
#define Inverse(x) (((1ll<<CB(x))-1)^x)
#define CountOnes(x) __builtin_popcountll(x)
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution 
{
public: 
class SegmentTree {
private:
    vector<ll> tree;
    int n;
    void Increment(int node , ll Start , ll End , ll RightUSER , ll LeftUSER) {
        
        if (LeftUSER > End || RightUSER < Start)
            return; 
        if (Start >= LeftUSER && End <= RightUSER){ 
            tree[node]+=1;
            return;
        }  
        ll mid = ( Start + End) / 2 ;
        Increment(node*2  , Start ,mid  ,  RightUSER, LeftUSER );
        Increment(node*2 +1 , mid + 1  , End , RightUSER ,  LeftUSER   );
 
    }
    int QueryDis ( int node , int left , int right , int pos )
    {
        if ( left == right) return tree[node];
 
        ll mid = ( left + right ) / 2 ;
        if ( mid >= pos )
        return   QueryDis( node * 2 , left , mid , pos  ) + tree[node]  ; 
 
        else  return  QueryDis( node * 2 +1 , mid + 1  , right , pos  )+ tree[node]   ;
    }
public:
    SegmentTree(int g ) {
        n = g ; 
        tree.resize(4 * n); 
    }
    void incRange ( ll start , ll end ){
        Increment(1, 0, n - 1, end, start ) ;
    }
    ll Pointquery( ll pos ) {
        return QueryDis( 1 , 0 , n-1 , pos ) ;
    }
 
};
void solve()
{
    ll n ; cin >> n ; 
    string s ; cin >> s ; 
    vector<ll> S ;
    ll Ans = 1 ; 
    for ( auto & c : s ) S.push_back(c-'0');
    for ( int k = 1 ; k <= n ; k++ ) 
    {
        SegmentTree Updated(n);
        for ( int i = 0 ; i < n ; ++i ) 
        {
            ll Value = (Updated.Pointquery(i)+S[i]) % 2 ; 
            if ( Value == 0 ) 
            {
                if ( i + k - 1 < n ) Updated.incRange(i,i+k-1);
                else break ;
            }
        }
        bool Found0 = true ; 
        for ( int i = 0 ; i < n ; ++i ) 
        {
            ll Value = (Updated.Pointquery(i)+S[i]) % 2 ;
            if ( Value == 0 ) Found0 = false ; 
        }
        if ( Found0 ) Ans = k ;
    }
    cout << Ans << endl ; 
}   
};
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
    while ( t-- ){ Solution Sol ; Sol.solve(); } 
    return 0;
}
