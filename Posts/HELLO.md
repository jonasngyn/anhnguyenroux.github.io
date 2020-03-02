# QBRECT - Hình chữ nhật 0 1

##  Link đề: [Link](https://vn.spoj.com/problems/QBRECT/)

##  Hướng dẫn:
      Với mỗi vị trí j ta sử dụng thuật toán L,R hoặc deque để tìm ra chỉ số bên trái mà tạo nên cột toàn số 1 nhỏ hơn j và gần j nhất,
    tương tự cho bên phải từ mảng trên ta có diện tích hình chữ nhật dài nhất tạo bởi phần tử j là cột thấp nhất: s=(chiều cao cột j)*(số
    cột kề j mà lớn hơn j).
      Ta duyệt từ đầu xuống theo i để tìm ra kết quả.
      
## Code:
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
#define MAX 1003 
using namespace std;
 

int n,m, a[MAX][MAX], h[MAX],r[MAX],l[MAX],res;

void Solve()
{
	FOR(i,1,n)
	{
		h[0]=-1; h[m+1]=-1;
		FOR(j,1,m)
			h[j]=a[i][j]*(h[j]+1);
		FOR(j,1,m)
		{
			l[j]=j;
			while (h[j]<=(h[l[j]-1])) l[j]=l[l[j]-1];
		}
		FORD(j,m,1)
		{
			r[j]=j;
			while (h[j]<=h[r[j]+1]) r[j]=r[r[j]+1];
		}
		FOR(j,1,m)
		{
			res=max(res,(r[j]-l[j]+1)*h[j]);
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
        READFILE;
    #endif
    FAST;
    
 	cin >> n >> m;
 	FOR(i,1,n) FOR(j,1,m) cin >> a[i][j];
	Solve(); 
	cout<<res;
    return 0;
}

```
