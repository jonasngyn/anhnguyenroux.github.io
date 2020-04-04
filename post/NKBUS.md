# Cách 1:

## Hướng dẫn:
  Ta để ý thấy rằng, thay vì xe phải đi tới nhà rồi đợi nhân viên, thì xe có thể đợi ở bến luôn rồi mới xuất phát, ví dụ như trong test đề, ta thấy thay vì dừng đợi ở trạm 2 thì cho ông tài xế ngồi ở nhà chơi 1 đơn vị thời gian, sau đó mới chạy đi rước thì kết quả cũng i chang :)) nên ta thử dùng tìm kiếm nhị phân. Với mỗi thời gian mình đang chặt kiểm tra xem có đón đủ m khách hay không, nếu đủ thì thử kiểm tra với thời gian nhỏ hơn xem.

## Code mẫu:
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
#define MAX 200005
using namespace std;

int n,m,s,res;
int d[MAX];
vector<int> a[MAX];

bool Check(int day)
{
    int now=day-s;
    int nNguoi=0;
    FOR(i,1,n)
    {
        nNguoi+=upper_bound(a[i].begin(),a[i].end(),now)-a[i].begin();
        now+=d[i];
    }
    if (nNguoi>=m) return true;
    return false;
}

void Solve()
{
    int l=s,r=INT_MAX;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (Check(mid))
        {
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        READFILE;
    #endif
    FAST;
    int tmp,tmp2;
    cin >> n >> m;
    FOR(i,1,n)
    {
        cin >>d[i] >> tmp;
        s+=d[i];
        FOR(j,1,tmp) cin >> tmp2, a[i].pb(tmp2);
    }

    FOR(i,1,n)
    {
        sort(a[i].begin(),a[i].end());
    }
    Solve();
    cout<<res;
    return 0;
}
```


---

# Cách 2:

## Hướng dẫn: 
ta tính thời gian ngồi đợi xe của từng người (thời gian đợi xe của 1 thằng=thời gian xe tới bến - thời gian đến bến),
sau đó sắp xếp thời gian đợi của mỗi người lại, ta tìm được kết quả.

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
#define MAX ???
using namespace std;

int n,m,kc,k,tmp,s;
vector <int> a;

int main()
{
    cin >> n >> m;
    FOR(i,1,n)
    {
        cin >> kc >> k;
        FOR(i,1,k)
        {
            cin >> tmp; 
            tmp=max(0,tmp-s);
            a.pb(tmp);
        }
        s+=kc;
    }
    sort(a.begin(),a.end());
    cout<<s+a.at(m-1);
    return 0;
}

```
