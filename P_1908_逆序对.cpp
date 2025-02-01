#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n = re();
        std::vector<int>A(n + 1);
        std::vector<int>B(n + 1);
        for (int i = 1;i <= n;++i)
        {
            std::cin >> A[i];
        }
        int ans = 0;
        auto merge = [&](auto work, const int l, const int r)->void
            {
                if (l == r)return;
                const int mid = l + r >> 1;
                work(work,l, mid);
                work(work,mid + 1, r);
                int i = l, j = mid+1;
                int k=l;
                
                while (i <= mid && j <= r)
                    if (A[i] <= A[j])
                        B[k++] = A[i++];
                    else
                        B[k++] = A[j++],ans += mid - i + 1;
                while (i <= mid)
                    B[k++] = A[i++];
                while (j <= r)
                    B[k++] = A[j++];
                for(int i=l;i<=r;++i)
                    A[i]=B[i];
            };
        merge(merge,1,n);
        std::cout<<ans<<endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}