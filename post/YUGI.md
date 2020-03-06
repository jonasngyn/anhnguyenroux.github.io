## Hướng dẫn:

- Ta chặt nhị phân với mỗi giá trị v là độ giảm sức mạnh lớn nhất. Với mỗi v, ta duyệt BFS hoặc DFS để 
gộp nhóm tất cả các phần tử mà a[i,j]<v (Theo cách duyệt này, với 2 nhóm bất kì thì ta luôn có a[i][j]>=k) 
và số nhóm là tối đa. nếu số nhóm>=k thì ta lưu giá trị và duyệt tiếp đoạn (mid+1,r) (nếu số nhóm>k thì ta
có thể gộp 2 nhóm thành 1 tới khi nào được k, trong 2 nhóm a[i][j] >=k) ngược lại thì ta tìm đoạn (l,mid-1).

## Code

```cpp
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
#define MAX 222
using namespace std;
 
int a[MAX][MAX], vs[MAX], n,k,res;

void DFS(int u,int val)
{
	vs[u]=true;
	FOR(v,1,n)
	{
		if (a[u][v]<val && !vs[v])
			DFS(v,val);
	}
}

int cntGroup(int val)
{
	int cnt=0;
	memset(vs,0,sizeof vs);
	FOR(i,1,n) if (!vs[i]) 
	{
		DFS(i,val); cnt++;
	}
	return cnt;
}

int main()
{
    #ifndef ONLINE_JUDGE
        READFILE;
    #endif
    FAST;
    
 	cin >> n >> k;
 	FOR(i,1,n) FOR(j,1,n) cin >> a[i][j];


 	int l=1,r=32767;

 	while (l<=r)
 	{
 		int mid=(l+r)>>1;
 		if (cntGroup(mid)>=k) 
 		{
 			res=mid; l=mid+1;
 		} else r=mid-1;
 	}

 	cout<<res;
    return 0;
}
```
