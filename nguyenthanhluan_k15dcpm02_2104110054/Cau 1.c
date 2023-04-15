#include <stdio.h>

int kiemTra(long x){
	int i;
	long sum = 0;
	for(i=1; i<x; i++)
		if(x % i == 0)
			sum += i;
	return sum == x;
}
int main(){
	FILE *input;
	input = fopen("./Cau1.inp", "r");
	long n, count = 0, i;
	fscanf(input, "%ld", &n);
	for(i=6; i<=n; i++)
		if(kiemTra(i) == 1)
			count++;
	FILE *out;
	out = fopen("./Cau1.out", "w");
	fprintf(out, "%ld", count);
}
