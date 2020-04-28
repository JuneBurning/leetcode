/*************************************************************************
    > File Name: numappeartimes.c
    > Author: wangzhijie
    > Mail: juneburning@163.com 
    > Created Time: 2020年04月28日 星期二 15时27分28秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>





int arr[10] = {
	0
};


int main()
{
	char buf[100];

	while(scanf("%s", buf) != EOF){
		int size = strlen(buf);
		int i;
		for(i = 0;i < size; i++){
			switch(buf[i]){
				case 48:
					arr[0]++;
					break;
				case 49:
					arr[1]++;
					break;
				case 50:
					arr[2]++;
					break;
				case 51:
					arr[3]++;
					break;
				case 52:
					arr[4]++;
					break;
				case 53:
					arr[5]++;
					break;
				case 54:
					arr[6]++;
					break;
				case 55:
					arr[7]++;
					break;
				case 56:
					arr[8]++;
					break;
				case 57:
					arr[9]++;
					break;
				default:
					printf("it's not number!\n");
					break;
			}
		}
		for(i = 0; i < 10; i++){
			printf("数字%d出现的次数:%d\n",i,arr[i]);
		}

	}

	return 0;
}
