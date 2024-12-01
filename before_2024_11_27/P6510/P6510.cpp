#include <bits/stdc++.h>
using namespace std;
int stn[100000+7];
int stx[100000+7];

vector <int> arr(1);
int ans=0;
int tn=0,tx=0;
signed main ()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int temp;scanf("%d",&temp);
        arr.push_back(temp);
    }
    for(int i=1;i<=n;++i)
    {
        while(tn&&arr[stn[tn]]>=arr[i])tn--;
        while(tx&&arr[stx[tx]]<arr[i])tx--;
        int k=lower_bound(stn+1,stn+1+tn,stx[tx])-stn;
        if(k!=tn+1)
            ans=max(ans,i-stn[k]+1);
        stn[++tn]=i;
        stx[++tx]=i;
    }
    printf("%d",ans);

}
