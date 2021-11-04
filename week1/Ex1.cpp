#include<stdio.h>
#include<string.h>
#define max 100
int main(){
	int A[26]={0},i;
	char str[max];
	gets(str);
	for(i=0;i<strlen(str);i++){
		if(str[i]>=65&&str[i]<=122)A[str[i]-'a']++;
	}
	for(i=0;i<26;i++){
		if(A[i]!=0)printf("So lan xuat hien cua %c la %d\n",i+'a',A[i]);
	}
	return 0;
}
