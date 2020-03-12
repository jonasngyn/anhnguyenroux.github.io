#include <bits/stdc++.h>
#define VA AnhNguyenProV2
#define pb push_back
#define FOR(i, a, b) for(int i = int(a); i <= int(b); i++)
#define FORD(i, a, b) for(int i = int(a); i >= int(b); i--)
#define REP(i, r) for(int i = 0; i < r; i++)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define READFILE freopen("input.txt", "r", stdin)
#define WRITEFILE freopen("output.txt", "w", stdout);
#define ii pair<int, int>
#define ll long long
#define fi first
#define se second
#define MAX 10004
#define MAXK 222
using namespace std;

struct node{
    int v,h,w;
    node(int _v,int _h,int _w) {v=_v; h=_h; w=_w;};
};

bool operator <(node a, node b)
{
    return (a.h > b.h);
}

int n,m,k,st,en;

const int Max= 10000007;
vector<node> a[MAX];

int d[MAX][MAXK];

void Djikstra()
{
    FOR(i,0,n)
        FOR(j,0,k)
        {
            d[i][j]=Max;
        }

    d[st][0]=0;

    priority_queue<node> pq;
    pq.push(node(st,0,0));

    while (!pq.empty())
    {
        int u=pq.top().v, du=pq.top().h, wu=pq.top().w;
        pq.pop();
        if (d[u][wu]!=du) continue;

        for(node t: a[u])
        {
            int v=t.v, uv=t.h, wuv=t.w;
            if (wu+wuv<k)
            {
                if (d[v][wu+wuv]>d[u][wu]+uv)
                {
                    d[v][wu+wuv]=d[u][wu]+uv;
                    pq.push(node(v, d[v][wu+wuv],wu+wuv));
                }
            }
        }
    }

    int ans=Max;
    FOR(i,0,k-1)
    {
        ans=min(ans,d[en][i]);
    }
    cout<<ans<<endl;
}

int main()
{

    #ifndef ONLINE_JUDGE
      READFILE;
    #endif

    cin >> k >> n>> m;
    FOR(i,1,m)
    {
        int u,v,h,w;
        cin >> u >> v >> h >> w;
        a[u].pb(node(v,h,w));
        a[v].pb(node(u,h,w));
    }

    cin >> st >>en;
    Djikstra();
    return 0;
}
