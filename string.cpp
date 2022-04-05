#include <stdio.h>
#include <string.h>

#define LEN 20
#define PAT_LEN 20

void printString(char *ch);
int bruteSearch(char *p, char *a);

int main()
{
	char string[LEN] = {'b','a','b','d','b','a','b','c','\0'};
	char pat[PAT_LEN] = {'b','a','b','c','\0'};
	printf("The String: \n");
	printString(string);
	printf("\n");
	
	printf("The pattern: \n");
	printString(pat);
	printf("\n");
	
	
	printf("Match Pattern: \n");
	int is_found = bruteSearch(pat, string);	
	printf("The value of the 'is_found': %d\n",is_found);
}


void printString(char *ch){
	for(int i=0;i < LEN;i++){
		printf("%c",ch[i]);
	}
}

int bruteSearch(char *p, char *a){
	int i = 0, j = 0,k=1;
	int M = strlen(p);
	int N = strlen(a);
	for(i=0,j=0,k=1; j<M && i<N;j++,i++,k++){
		printf("\n============ Iteration %d begins (outer loop)  =========\n",k);
		printf("  value of i: %d   and  value of j: %d\n",i,j);
		printf("  a[%d] = %c  and p[%d] = %c\n",i,a[i],j,p[j]);
		printf("============ Inner Loop Begins =========\n");
		while(a[i] != p[j]){
			
		printf("  ============ Inner Loop body Begins =========\n");
		printf("    a[%d] = %c  and p[%d] = %c\n",i,a[i],j,p[j]);
			i -= j- 1;
			j = 0;
		printf("    Inner Loop value of i(i-j+1): %d   and  value of j: %d\n",i,j);
		printf("  ============ Inner Loop body End =========\n");
		}
		printf("============ Inner Loop Ends =========\n");
		printf("  value of i: %d   and  value of j: %d\n",i,j);
		printf("  a[%d] = %c  and p[%d] = %c\n",i,a[i],j,p[j]);
		
		printf("============ Iteration %d Ends=========\n\n",k);
	}
		printf("value of i: %d   and  value of j: %d\n value of M: %d   value of  N: %d",i,j,M,N);
	if(j == M){
		printf("returning i - M\n");
		return i-M;
	}else{
		printf("returning i\n");
		return i;
	}
}