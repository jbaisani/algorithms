#include <stdio.h>
#define MAX_PEOPLE 10001
#define MAX_RELATIONSHIP 100001 

int father[MAX_PEOPLE];//存储每个元素的father
int relat[MAX_RELATIONSHIP][2];//存储朋友关系

//初始化集合
void Make_Set(int x){
	father[x] = x;
}

//查找x所在集合并压缩路径
int Find_Set(int x){

	int root;
	int i, next;
	root = x;
	while(father[root] != root)//寻找x所在集合的代表元
		root = father[root];
	
	i = x;
	while(i != root){//将r集合中的所有结点直接指向r, 路径压缩
		next = father[i];
		father[i] = root;
		i = next;
	}
	return root;

}


void Union(int x, int y){
	int x_set;
	int y_set;

	x_set = Find_Set(x);
	y_set = Find_Set(y);

	if(x_set == y_set)
		return ;
	else 
		father[y_set] = x_set;

}

int main(){

	int n;//n个朋友圈用户
	int	m;//m对朋友关系
	
	int i;
	int count=0;
	scanf("%d %d", &n, &m);

	for(i=0; i<n; i++)//初始化
		Make_Set(i);

	for(i=0; i<m; i++)//合并关系
		Union(relat[i][0], relat[i][1]);

	for(i=0; i<n; i++)//代表元即一个朋友圈
		if(father[i] == i)
			count++;
	
	printf("%d\n", count);
	return 0;
}
