#include <stdio.h>
#include <string.h>

void XoaDauXuongDong(char *xau){
	if(xau[strlen(xau)-1] == '\n')
		xau[strlen(xau)-1] = '\0';
}
void chuyenDoi(char *s1, char s2[][200], int soluong){
    int i, j, t;
    printf("\t");
    for(i=0; i<strlen(s1); i++){
    	int d = 0;
    	for(j=0; j<soluong; j++)
    		if(s1[i] == s2[j][0] || s1[i] == s2[j][0] + 32 || s1[i] == s2[j][0] - 32){ // kiem tra chu cai dau tien
    			d = 1;
    			for(t=1; t<strlen(s2[j]); t++)
    				if(!(s1[i + t] == s2[j][t] || s1[i] == s2[j][t] + 32 || s1[i] == s2[j][t] - 32)){
    					d = 0;
    					break;
					}
				if(d == 1){
					if(s1[i] <= 'z' && s1[i] >= 'a')
						printf("%c", s1[i] - 32);
					for(t = 1 ; t<strlen(s2[j]); t++){
						printf("*");
						i++;
					}
				}
			}
        if(d == 0)
        	printf("%c", s1[i]);
    }
}
void DocDuLieu(char string2[][200], int *soluong){
	FILE *in;
	in = fopen("./line.txt", "r");
	fscanf(in, "%d", soluong);
	int i;
	char Tam[100];
	fgets(Tam, sizeof(Tam), in);
	for(i=0; i<*soluong; i++){
		fgets(string2[i], sizeof(string2[i]), in);
		XoaDauXuongDong(string2[i]);
	}
}
void InDuLieu(char string2[][200], int soluong){
	FILE *out;
	out = fopen("./line.txt", "w");
	fprintf(out, "%d\n", soluong);
	int i;
	for(i=0; i<soluong; i++)
		fprintf(out, "%s\n", string2[i]);
}
void Menu(){
	printf("\n\t\tMENU");
	printf("\n\t1. Them tu nhay cam.");
	printf("\n\t2. Hien thi danh sach tu nhay cam.");
	printf("\n\t3. Che tu nhay cam.");
	printf("\n\t0. Thoat.");
	printf("\n\tChuc nang: ");
}
int main(){
    int i, j, n, chucNang;
    int line = 0;
	char string1[200];
	char string2[50][200];
	DocDuLieu(string2, &n); 

	do{
		Menu();
		scanf("%d", &chucNang);
		switch(chucNang){
			case 0:
				InDuLieu(string2, n);
				printf("\n\t\tKET THUC!");
				break;
			case 1:{
				int n2;
				printf("\tNhap so tu ban muon them: ");
				scanf("%d", &n2);
				fflush(stdin);
				for(i = 0; i < n2; i++){
					printf("\tNhap tu nhay cam ban muon them: ");
					fgets(string2[n], sizeof(string2[n]), stdin);
					XoaDauXuongDong(string2[n]);
					n++;
				}	
				break;
			}
		case 2:
			printf("\n\tCac tu nhay cam:\n");
			for(i = 0; i < n; i++){
				printf("\t%s\n", string2[i]);	
			}	
			break;	
		case 3:{
			fflush(stdin);
			printf("\tCau cua ban: ");
			fgets(string1, sizeof(string1), stdin);
			chuyenDoi(string1, string2, n);
			break;
		}	
		default:{
			printf("Sai cu phap. Vui long kiem tra lai\n");
			break;
		}
	}
	}while(chucNang != 0);	
    return 0;
}

