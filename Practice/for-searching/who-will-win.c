// link: http://practice.geeksforgeeks.org/problems/who-will-win/0
// Input:
// 3
// 10 8 10 25
// 10 8 10 30
// 10 8 10 12
// Output:
// 2
// 2
// 2

#include <stdio.h>
#include <math.h>

int array[1001];
int times = 0;

int binary_search(int low, int high, int target){

	while (low <= high) {
		int mid =	(low + high) / 2;

		if (array[mid] == target) {
			//printf("times = %d\n", times);
			return times;
		}else if (array[mid] < target) {
			times++;
			low = mid + 1;
		}else{
			times++;
			high = mid - 1;
		}
	}

}

int main() {
	int testcase;
  int total;
  int target;
  int tg;
  int ts;
  int cost_G;
  int cost_S;

	int i;
	for (i = 0; i < 1000; i++) {
		array[i] = i;
	}

  scanf("%d", &testcase);

  while (testcase--) {
    scanf("%d %d %d %d", &total, &target, &tg, &ts);

    cost_G = target * tg;
    cost_S = binary_search(0, total-1, target) * ts;

		//printf("cost_G = %d cost_S = %d\n", cost_G, cost_S);
    if (cost_G > cost_S) {
      printf("2\n");
    }else if (cost_G < cost_S) {
      printf("1\n");
    }else{
      printf("0\n");
    }
  }
	return 0;
}
