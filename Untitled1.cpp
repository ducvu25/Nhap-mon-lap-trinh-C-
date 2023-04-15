#include <stdio.h>
#include <string.h>

void XoaEnter(char s[100]){
	if(s[strlen(s)-1] == '\n')
		s[strlen(s)-1] = '\0';
}
void chuyenDoi(char *s1, char s2[][100], int n){
    int i, j;
    for(i=0; i<n; i++){
        char *p = strstr(s1, s2[i]);
        if(p != 0){
        	if(*p <= 'z' && *p >= 'a')
        		*p -= 32;
        	for(j=1; j<strlen(s2[i]); j++)
           	 *(p+j) = '*';
		}
    }
}
void DocFile(char s2[][100], char *s, int *n){
	FILE *fp;
	fp = fopen(s, "r");
	fscanf(fp, "%d", n);
	int i;
	fflush(fp);
	for(i=0; i<*n; i++){
		fgets(s2[i], sizeof(s[i]), fp);
		XoaEnter(s2[i]);
	}
}
void InFile(char string2[][100], char *s, int n){
	FILE *fp;
	fp = fopen(s, "w");
	fprintf(fp, "%d\n", n);
	int i;
	for(i=0; i<n; i++)
		fprintf(fp, "%s\n", string2[i]);
}
int main(){
    int i, j, n, k;
    int line = 0;
    char str[50];
	char string1[50];
	char string2[50][100];
	DocFile(string2, "line.txt", &n); //  doc du lieu
//	char *error = "Lua chon khong hop le. Vui long nhap lai\n";
	do{
		printf("\n\t\tMENU\n");
		printf("\t1. Them tu nhay cam vao tu dien\n");
		printf("\t2. Hien thi danh sach tu nhay cam hien tai\n");
		printf("\t3. Nhap chuoi va hien thi sau khi da che tu nhay cam\n");
		printf("\t0. Exit\n");
		printf("\tChuc nang: ");
		scanf("%d", &k);
		switch(k){
			case 0:
				InFile(string2, "line.txt", n);
				break;
			case 1:
				int n2;
				printf("Nhap so tu ban muon them: ");
				scanf("%d", &n2);
				fflush(stdin);
				for(i = 0; i < n2; i++){
					printf("Nhap tu nhay cam ban muon them: ");
					gets(string2[n++]);
					XoaEnter(string2[n - 1]);
				}	
				break;
		case 2:
			for(i = 0; i < n; i++){
				printf("%s\n", string2[i]);	
			}	
			break;	
		case 3:
			printf("Nhap cau: ");
			fflush(stdin);
			fgets(string1, sizeof(string1), stdin);
			chuyenDoi(string1, string2, n);
			printf("%s", string1);
			break;
			
	}		
	}while(k != 0);	
    return 0;
}

