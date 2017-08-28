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
