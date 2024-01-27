void augmentedBFS ( int src , int dest , vector<vector<int>>& Graph , vector<int>& dist , vector<bool>& Visited )  
{
    queue<int> q ; 
    q.push(src) ; 
    Visited[src] = true ; 
    dist[src] = 0 ; 
    while ( !q.empty() ) 
    {
        int parent = q.front() ; 
        q.pop() ; 
        for ( auto child : Graph[parent] ) 
        {
            if ( !Visited[child] ) 
            {
                Visited[child] = true ; 
                q.push(child) ; 
                dist[child] = 1 + dist[parent];
            }
        }
    }
}
void solve()    
{
    
    int n , m ; cin >> n >> m ; 
    const int N = 1e5 + 7 ; 
    vector<bool> Visited(N); 
    vector<vector<int>> Graph(N) ;
    vector<int> dist(N,1e18) ;
    if ( n == m )
    {
        cout << 0 << endl ; return ; 
    }
    if ( n > m ) 
    {
        cout << n - m << endl ; return ; 
    }
    int mMax = ( m - 1 ) * 2 ;
    for ( int i = 1 ; i <= mMax ; ++i ) 
    {
        if ( (2 * i) <= mMax ) Graph[i].push_back( i*2 );
        if ( i - 1 > 0 ) Graph[i].push_back(i-1);  
    }
    augmentedBFS( n , m  , Graph , dist , Visited ) ; 
    cout << dist[m] << endl; 
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
