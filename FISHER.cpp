//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 105 ;
const int INF  = 1 << 29 ;

int T[NX][NX] , cost[NX][NX] , dis[NX][10*NX] , Jabe[NX] , n , ttm , vis[NX] ;
void solve()
{
    set < pii > pq ;
    pq.insert( mp( 0 , 1 ) ) ;
    int i , j ;
    dis[1][0] = 0 ;
    while( !pq.empty() )
    {
        pii now ;
        now.ff = pq.begin()->ff ;
        now.ss = pq.begin()->ss ;
        pq.erase(pq.begin());
        int t =  now.ff ;
        int x = now.ss ;
        for ( i= 1 ; i <= n ; i++ )
        {
            if( i == x ) continue ;
            int tt = t + T[x][i];
          //  printf(" tt :: %d x :: %d i :: %d\n" , tt , x , i);
           // printf(" dis[i][tt] :: %d dis[x][t] + cost[x][i] :: %d\n",dis[i][tt],dis[x][t],cost[x][i]);
            if( tt > ttm ) continue ;
            if(  dis[i][tt] > dis[x][t] + cost[x][i] )
            {
                dis[i][tt] = dis[x][t] + cost[x][i];
                pq.insert( mp( tt , i ) ) ;
            }
        }
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   while( scanf("%d %d",&n,&ttm) == 2 )
   {
       if( n == 0 && ttm == 0 ) break ;
       int i , j ;
       for ( i = 1 ; i <= n ; i++ )
       {
           for ( j = 1 ; j <= n ; j++ )
           {
               T[i][j] = II ;

           }

       }
       for ( i = 1 ; i <= n ; i++ )
       {
           for ( j = 0 ; j <= ttm ; j++ ) dis[i][j] = INF ;
       }
     //  getchar();
       for ( i = 1 ; i <= n ; i++ )
       {
           for ( j = 1 ; j <= n ; j++ )
           {
               cost[i][j] = II ;

           }
           //dis[i] = INF  ;
           vis[i] = 0 ;
       }
     //  getchar();
       solve();
       int ans = INF , laglo ;
       for ( i = 0 ; i <= ttm ; i++ )
       {
           // cout << dis[n][i] << " " ;
            if( ans > dis[n][i] )
            {
                ans = dis[n][i];
                laglo = i ;
            }
       }
      // cout << " \n , ans " ;
       cout << ans << " " << laglo << endl ;
   }

    return 0;
}
