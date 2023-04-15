#include <stdio.h>
#include <string.h>

void NhapFile(char *s){
	FILE *input;
	input = fopen("./Cau3.inp", "r");
	fgets(s, 201, input);
}
void XuLy(char *s){
	int count = 0;
	int i;
	for(i=0; i<strlen(s); i++){
		if(!(s[i] == 32 || (s[i]>='a' && s[i] <= 'z') || (s[i]>='A' && s[i] <= 'A'))){
			strcpy(s + i, s + i + 1);
			i--;
		}
		if( (i == 0 || s[i-1] == 32) && s[i] == 'C')
			count++;
	}
	FILE *out;
	out = fopen("./Cau3.out", "w");
	fprintf(out, "C = %d", count);
}
int main(){
	char s[201];
	NhapFile(s);
	XuLy(s);
}
