# 题目描述

如图所示的数字三角形，从顶部出发，在每一结点可以选择向左走或得向右走，
一直走到底层，要求找出一条路径，使路径上的值最大。
       7
     3   8
   8   1   0
 2   7   4   4

# 输入描述 Input Description 

第一行是数塔层数N(1<=N<=100)。
第二行起，按数塔图形，有一个或多个的整数，表示该层节点的值，共有N行。

# 输出描述 Output Description 

输出最大值。

# 样例输入 Sample Input 

5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11

# 样例输出 Sample Output 

86

# 解答 Solution

动态规划解法, 从第n层开始往上计算, 对于第n-1层a[n-1][j], 它只能选择a[n][j]或是a[n][j+1], 每次取最大. 以此递推. 推到a[1][1]就得到了最优解.

``` c
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
```
