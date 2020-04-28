/*************************************************************************
    > File Name: lowmanacher.c
    > Author: wangzhijie
    > Mail: juneburning@163.com 
    > Created Time: 2020年04月28日 星期二 10时24分09秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>


#define MALLOC_ERROR(ptr)\
	if(NULL == ptr) { \
		printf("%s,%d malloc error!\n", __FUNCTION__,__LINE__);\
}

void lowmanacher(int *arr, char *buf)
{
	int i, j, size, max = 0;
	size = strlen(buf);
	for(i = 0; i < strlen(buf); i++){
		j = 1;
		while((i - j) >= 0 && (i + j) < size){
			if(buf[i - j] == buf[i+j]){
				arr[i]++;
				j++;
			}else
				break;
		}
		if(arr[max] < arr[i])
			max = i;
	}
	if(arr[max] == 0){
		printf("没有回文串\n");
		return;
	}

	char *tmp = malloc(sizeof(char) * arr[max] * 2 + 1);
	memcpy(tmp, (buf + max) - arr[max], 2 * arr[max] + 1);
	printf("max palindrome position is %d, max palindrome segment is %s\n", max, tmp);


}


int main()
{

	char buf[100] = {
		0
	};

	while(scanf("%s", buf) != EOF){
		//把每个字符代表的回文长度存储到数组中	
		int *arr = malloc(sizeof(int) * strlen(buf));
		MALLOC_ERROR(arr);
		memset(arr, 0, sizeof(int) * strlen(buf));
		lowmanacher(arr, buf);
	}



	return 0;
}
