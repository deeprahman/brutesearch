#include <stdio.h>
#include <string.h>

#define LEN 20
#define PAT_LEN 20

void printString(char *ch);
int bruteSearch(char *p, char *a);

int main()
{
	char string[LEN] = {'b','a','b','d','b','a','b','c','\0'};
	char pat[PAT_LEN] = {'b','a','b','x','\0'};
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
	/*
	The program keep one pointer (i) into the text and another pointer(j) into the pattern.
	As long as they point to matching characters both pointers are incremented. If i and j point to mismatching characters, then j is reset to point to the begining of the pattern and i is reset to correspond to moving the pattern to the right one position formatching against the text.
	In particulat, whenever the first interation of the while loop sets j = 0, then subsequent interation increment i until a test character matching the first character is encountered.
	If the end of the pattern is reached i.e j is equal to M(the length of the pattern), then there is a match starting at a[i-M]; otherwise, if the end of the text is reached before the end of the pattern is ever reached i.e. i is equal to N(the length of the string), there is no match and -1 is returned.
	
	*/
	int i = 0, j = 0,k=1;
	int M = strlen(p);
	int N = strlen(a);
	for(i=0,j=0,k=1; j<M && i<N;j++,i++,k++){
		printf("\n============ Iteration %d begins (outer loop)  =========\n",k);
		printf("  value of i: %d   and  value of j: %d\n",i,j);
		printf("  a[%d] = %c  and p[%d] = %c\n",i,a[i],j,p[j]);
		printf("============ Inner Loop Begins =========\n");
		while(a[i] != p[j] && i < N){
			
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
		printf("value of i: %d   and  value of j: %d\n value of M: %d   value of  N: %d\n",i,j,M,N);
	if(j == M){
		printf("returning i - M\n");
		return i-M;
	}else{
		printf("Pattern did not match\n");
		return -1;
	}
}