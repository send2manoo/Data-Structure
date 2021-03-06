#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solve (int* B, int N, int half) {

// 15478 8452 8232 874 985 4512
	char cstr[5], tempCstr[N], tempArr[N];
	int length, i, j = 0, temp;

	for (i = 0; i < half; i++)
	{
		sprintf(cstr, "%d", B[i]); // convert int to string using sprintf()
		length = strlen(cstr);
		if(length == 5)
		{
			temp = atoi(cstr);
			tempCstr[i] = (char)(temp / 10000);
		}
		else if(length == 4)
		{
		    temp = atoi(cstr);
			tempCstr[i] = (char)(temp / 1000);
		}
		else if(length == 3)
		{
			temp = atoi(cstr);
			tempCstr[i] = (char)(temp / 100);
		}
		else if(length == 2)
		{
			temp = atoi(cstr);
			tempCstr[i] = (char)(temp / 10);
		}
		else
		{
			temp = atoi(cstr);
			tempCstr[i] = (char)temp;
		}
	}
	
	for (i = half; i < N; i++)
	{
		temp = B[i] % 10;
		sprintf(cstr, "%d", temp);
		tempCstr[i] = atoi(cstr);
	}
	for(i = 0; i < N; i++){
    	j = j + sprintf(&tempArr[j], "%d", tempCstr[i]);
	}

	temp = atoi(tempArr); // string to int
	((temp % 11) == 0) ? printf("OUI") : printf("NON"); 
}

int main() {
    long int N, i;
    int *A;
    scanf("%ld", &N);
    // long int A[N];
    A = (int*) malloc (N * sizeof(int)); // base address with N bytes

    for(i = 0; i < N; i++){
    	scanf("%d", &A[i]);
	}
   
    solve(A, N, N/2);    	
}