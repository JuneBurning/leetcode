/*************************************************************************
    > File Name: charappearstimes.c
    > Author: wangzhijie
    > Mail: juneburning@163.com 
    > Created Time: 2020年04月28日 星期二 16时46分46秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


void hashchar(char *buf)
{
	int *arr = (int *)malloc(sizeof(int) * 256);
	memset(arr, 0, sizeof(int) * 256);

	int i, size;
	size = strlen(buf);
	for(i = 0; i < size; i++){
		arr[buf[i]]++;
	}
	for(i = 0; i < 256; i++){
		if(arr[i] != 0){
			printf("char:%c, appeartimes:%d\n", i, arr[i]);
		}
	}
}




int main()
{

	char buf[256] = {
		0
	};

	while(scanf("%s", buf) != EOF){
		hashchar(buf);
	}

	return 0;
}
