    #include <iostream>
    #include <map>
    using namespace std;
    typedef long long LL;
    LL a[200001];
    map<LL,LL> m;
    int main() {
        int n;
        LL c;
        LL ans=0;
        cin >> n >> c;
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            m[a[i]]++;
            a[i]-=c;    
        } 
        for(int i=1;i<=n;i++) ans+=m[a[i]];
        cout << ans << endl;
        return 0;
}
