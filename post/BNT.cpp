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
#define MAX 555
using namespace std;

const int MX = 1000006;

int m,n, a[MAX][MAX], Prime[MX];

vector<int> sPrime;

void Eratos()
{
    memset(Prime,1,sizeof Prime);
    Prime[1]=false;
    for(int i=2; i*i < MX; i++)
        if (Prime[i])
        {
            int j=i+i;
            while (j<MX)
            {
                Prime[j]=false; j+=i;
            }
        }

    FOR(i,1,MX) if (Prime[i]) sPrime.pb(i);

}

int main()
{
    #ifndef ONLINE_JUDGE
      READFILE;
    #endif
    FAST;


    cin >> n >> m;

    FOR(i,1,n)
        FOR(j,1,m)
            cin >> a[i][j];

    Eratos();

    int ans=INT_MAX;

    FOR(i,1,n)
    {
        int kq=0;
        FOR(j,1,m)
        {
            kq+=sPrime[lower_bound(sPrime.begin(),sPrime.end(),a[i][j])-sPrime.begin()]-a[i][j];
        }
        ans=min(ans,kq);
    }

        FOR(i,1,m)
    {
        int kq=0;
        FOR(j,1,n)
        {
            kq+=sPrime[lower_bound(sPrime.begin(),sPrime.end(),a[j][i])-sPrime.begin()]-a[j][i];
        }
        ans=min(ans,kq);
    }
    cout<<ans;

    return 0;
}
