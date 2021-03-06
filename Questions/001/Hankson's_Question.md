# 题目: Hankson趣味问题

Time Limit: 1000ms Memory Limit: 65536KB
（出自：SmartOJ1012）

# 描述Descript

Hanks博士是BT（Bio-Tech，生物技术）领域的知名专家，他的儿子名叫Hankson。现在，刚刚放学回家的Hankson正在思考一个有趣的问题。

今天在课堂上，老师讲解了如何求两个正整数c1和c2的最大公约数和最小公倍数。现在Hankson认为自己已经熟练地掌握了这些知识，他开始思考一个“求公约数”和“求公倍数”之类问题的“逆问题”，这个问题是这样的：已知正整数a0,a1,b0,b1，设某未知正整数x满足：1、 x和a0的最大公约数是a1；2、 x和b0的最小公倍数是b1。

Hankson的“逆问题”就是求出满足条件的正整数x。但稍加思索之后，他发现这样的x并不唯一，甚至可能不存在。因此他转而开始考虑如何求解满足条件的x的个数。请你帮助他编程求解这个问题。 

# 输入Input

第一行为一个正整数n，表示有n组输入数据。接下来的n行每行一组输入数据，为四个正整数a0，a1，b0，b1，每两个整数之间用一个空格隔开。输入数据保证a0能被a1整除，b1能被b0整除。

# 输出Output

共n行。每组输入数据的输出结果占一行，为一个整数。
对于每组数据：若不存在这样的x，请输出0；
若存在这样的x，请输出满足条件的x的个数；

# 样例Sample

输入数据
2
41 1 96 288
95 1 37 1776
输出数据
6
2

# 备注Hint

【说明】 第一组输入数据，x可以是9、18、36、72、144、288，共有6个。 第二组输入数据，x可以是48、1776，共有2个。 【数据范围】 对于50%的数据，保证有1≤a0，b1，b0，b1≤10000且n≤100。 对于100%的数据，保证有1≤a0，b1，b0，b1≤2,000,000,000且n≤2000。

# 解答Solution

``` bash
#数论
lcm(x, b0) = x*b0/gcd(x, b0) = b1
=>b1*gcd(x, b0) = x*b0
=>gcd(x, b0) = x*b0/b1
=>gcd(b1/b0, b1/x) = 1
```
证明了x是b1的因数, 因此我们只需要枚举b1的因数到sqrt(b1)即可

``` c++
#include <stdio.h>

int n;
int a0, a1, b0, b1;

int gcd(int a, int b){//求最大公约数
	return b==0? a: gcd(b, a%b);
}


bool judge(int a){
	if(a%a1)
		return 0;

	return gcd(a/a1, a0/a1)==1 && gcd(b1/b0, b1/a)==1;
}


int main(){
	int i, j;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d %d %d %d", &a0, &a1, &b0, &b1);
		long long ans = 0;

		for(j=1; j*j<=b1; j++){
			if(!(b1%j)){//j为b1的因数
				ans += judge(j);

				if(b1/j != j)//可以减少枚举次数
					ans += judge(b1/j);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
```

