#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(void)
{
	int n,studentNum,gender,locate;
	scanf("%d", &n);
	int* switchOnOff = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &switchOnOff[i]);
	}
	scanf("%d", &studentNum);
	for (int i = 0; i < studentNum; i++) {
		scanf("%d %d", &gender,&locate);
		if (gender==1) {
			for (int k = locate-1; k < n; k+=locate) {
				switchOnOff[k] = !switchOnOff[k];
			}
		}
		else{
			switchOnOff[locate - 1] = !switchOnOff[locate - 1];
			int l=locate-2;
			for (int k = locate; k < n; k++) {
				if (l < 0) {
					break;
				}
				else if (switchOnOff[l] == switchOnOff[k]) {
					switchOnOff[l] = !switchOnOff[l];
					switchOnOff[k] = !switchOnOff[k];
					l--;
					continue;
				}
				else {
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0 && i % 20 == 0) puts("");
		printf("%d ", switchOnOff[i]);
	}
	free(switchOnOff);

	return 0;
}