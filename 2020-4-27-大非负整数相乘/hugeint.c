/*************************************************************************
    > File Name: hugeint.c
    > Author: wangzhijie
    > Mail: juneburning@163.com 
    > Created Time: 2020年04月27日 星期一 11时06分14秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ARRSIZE	100

unsigned char num1[ARRSIZE] = {
	0
};
unsigned char num2[ARRSIZE] = {
	0
};


int *hugesum(unsigned char *an1, unsigned char *an2)
{
	if(NULL == an1 || NULL == an2)
		return NULL;

	int *sum = malloc(sizeof(int) * 2 * ARRSIZE);
	if(NULL == sum)
		return NULL;
	memset(sum, 0 , 2 * ARRSIZE * sizeof(int));

	//计算出大整数的有效位
	int validnum1 = 0, validnum2 = 0, i, j, power;
	for(i = 0; i < ARRSIZE; i++){
		if(an1[i] != 0xff){
			validnum1++;	
		}
		if(an2[i] != 0xff){
			validnum2++;
		}
		if(an1[i] == 0xff && an2[i] == 0xff)
			break;
	}
	printf("validnum1=%d, validnum2=%d\n",validnum1,validnum2);
	
	//用乘数和被乘数每一位进行乘法运算
	for(i = 0; i < validnum1; i++){
		for(j = 0; j < validnum2; j++){
			power = (int)pow(10, i+j);
			sum[i+j] += an1[i] * an2[j];
		}
	}

	//开始对sum进行进位
	for(i = 0; i < (2 * ARRSIZE); i++){
		if(sum[i] > 9){
			sum[i + 1] += sum[i] / 10;
			sum[i] = sum[i] % 10;
		}
	}

	for(i = 2 * ARRSIZE - 1; i >= 0; i--){
		if(sum[i] != 0)
			break;
	}
	for(j = i; j >= 0; j--){
		printf("%d",sum[j]);
	}

	printf("\n");
	return sum;
}

int main()
{
	char buf[101] = {
		0
	};
	memset(num1, 0xff, ARRSIZE);
	memset(num2, 0xff, ARRSIZE);
	int i, j;

	while(scanf("%s", buf)){
		if(num1[0] == 0xff){
			int size = strlen(buf);
			for(i = size - 1, j = 0; i >= 0; i--,j++){
				num1[i] = buf[j] - 48;
			}
		}else if(num2[0] == 0xff){
			int size = strlen(buf);
			for(i = size - 1, j = 0; i >= 0; i--, j++){
				num2[i] = buf[j] - 48;
			}
		}
		memset(buf, 0, sizeof(buf));

		if(num1[0] != 0xff && num2[0] != 0xff){
			int *sum = hugesum(num1, num2);
		}
	}
	
	return 0;
}
