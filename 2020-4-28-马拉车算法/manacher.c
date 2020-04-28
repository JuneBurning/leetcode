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

//将数组中填充#，2*i+1必然是奇数，所以肯定是奇对称
char* arrinsert(char *buf, int size)
{
	//需要在最后加一个\0用来输出打印
	char *tmp = malloc(size * 2 + 1 + 1);
	MALLOC_ERROR(tmp);
	memset(tmp, 0, size * 2 + 2);
	int i;
	for(i = 0; i < size * 2 + 1; i += 2){
		tmp[i] = '#';
		tmp[i + 1] = buf[i / 2];
	}
	printf("new buf=%s\n", tmp);
	return tmp;
}

void manacher(char *buf)
{
	int i, j, size, max = 0, mirror = -1;
	size = strlen(buf);
	char *tmp = arrinsert(buf, size);
	size = strlen(tmp);
	int *arr = malloc( sizeof(int) * size);
	MALLOC_ERROR(arr);
	memset(arr, 0, sizeof(int) * size);
	//三种情况，在回文长度，需要在最长回文长度外在判断，或者在最长回文长度外，朴素查找
	//所以前两种情况只要i在最长回文半径内，则可以减少mirror[i]的查找，这就是马拉车算法精髓

	for(i = 0; i < strlen(tmp); i++){
		//判断i是否在max内
		if(i < max + arr[max]){
			mirror = 2 * max - i;
			if(mirror < 0)
				j = 1;
			else
				j = arr[mirror];
		}else{
			j = 1;
		}
		while((i - j) >= 0 && (i + j) < size){
			if(tmp[i - j] == tmp[i+j]){
				arr[i]++;
				j++;
			}else
				break;
		}
		if(mirror != -1)
			arr[i] += arr[mirror];
		if(arr[max] < arr[i])
			max = i;
		mirror = -1;
	}

	if(arr[max] == 0 || (tmp[arr[max] + max] == '#' && arr[max] == 1 )){
		printf("没有回文串\n");
		return;
	}
	printf("max=%d\n",max);

	for(i = max - arr[max]; i <= arr[max] + max; i++){
		if(tmp[i] == '#')
			continue;
		else
			printf("%c",tmp[i]);
	}
	printf("\n");

	free(tmp);
}


int main()
{

	char buf[100] = {
		0
	};

	while(scanf("%s", buf) != EOF){
		//把每个字符代表的回文长度存储到数组中	
		manacher(buf);
	}

	return 0;
}
