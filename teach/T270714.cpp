#include<bits/stdc++.h>
using namespace std;
long long a[55][55];
int juli;
int  main() {
	long long x,y;
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			cin>>a[i][j];
		}
	}
	
			for(int i=1;i<=x;i++){
				for(int j=1;j<=y;j++){ //a[i][j]
					int max=0;
					for(int n=1;n<=x;n++){
						for(int m=1;m<=y;m++){
							if(a[i][j]==a[n][m]){
								int x1=abs(n-i);
								int y1=abs(m-j);
								
									juli=x1*x1+y1*y1;
							
							
								if(juli>max){
									max=juli;
								}
							}
					}
			} cout<<max<<" ";
		}cout<<endl;
	}
	
	
}
 