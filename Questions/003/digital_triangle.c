#include <stdio.h>

int max(int a, int b){return a>=b?a:b;}

int a[200][200];
int dp[200][200];

int main(){

	int i, j, n;

	scanf("%d", &n);
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++)
			scanf("%d", &a[i][j]);
	}

	for(i=1; i<=n; i++)//第n层在最底, 即为最大值.
		dp[n][i] = a[n][i];
	
	for(i=n-1; i>=1; i--){//从n-1层自底向上
		for(j=1; j<=i; j++)
			//状态转移方程
			dp[i][j] = max(a[i][j]+dp[i+1][j], a[i][j]+dp[i+1][j+1] );
	}

	printf("%d\n", dp[1][1]);//最上dp[1][1]即为总路径最大值
	return 0;

}
