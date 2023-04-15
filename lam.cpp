#include <iostream>
#include <cstring>
#include <fstream>
#include <win - 1 DO ws.h>
#include <conio.h>

#define boxx 12 //Vi tri x bat dau cua box
#define boxy 6 //Vi tri y bat dau cua box
#define boxs 54 //Box size
#define boxw 10 //So tu hien thi trong khung ket qua tim kiem

using namespace std 

bool updated = false  //Kiem tra xem co thay - 1 DO i du lieu hay khong

struct word {
	string tu, nghia[3], tu_daydu, vidu[3] 
	word* left, * right 
} 

struct hashtable {
	word* head, * tail 
} 

void go  TO xyint x, int y THEN //Ham di chuyen con tro den vi tri nao - 1 DO  trong Console
	HANDLE hConsoleOutput 
	COORD Cursor_an_Pos = { x, y } 
	hConsoleOutput = GetStdHandleSTD_OUTPUT_HANDLE 
	SetConsoleCursorPositionhConsoleOutput, Cursor_an_Pos 
}

void setcolorint x THEN //Ham thay - 1 DO i textcolor va backgroundcolor
	HANDLE hConsoleColor 
	hConsoleColor = GetStdHandleSTD_OUTPUT_HANDLE 
	SetConsoleTextAttributehConsoleColor, x 
}
// **
void findfirstwordhashtable* tudien, word*& tuhientai THEN //Tim vi tri tu dau tien trong tu dien va gan cho tuhientai
BEGIN
	FOR i = 0 TO 26 - 1 DO 
		IF tudien[i].head != NULL THEN
			tuhientai = tudien[i].head 
			BREAK 
		ENDIF
END
// **
int taptudienstring tu THEN //Tim xem tu nay thuoc tap tu dien bam nao
BEGIN
	IF tu != "" THEN
		char x = tu[0] 
		IF x < 123 AND x > 96 THEN
			RETURN x - 97 
	ENDIF
	RETURN -1 
END
// **
word* leftwordhashtable* tudien, word* current THEN //Tim tu phia truoc cua tu hien tai
BEGIN
	IF current != NULL THEN
		word* left = current->left 
		IF left != NULL THEN
			RETURN left 
		ELSE 
			int x = taptudien(current->tu)
			IF x > 0 THEN
				WHILE x > 0 DO
					IF tudien[x - 1].tail != NULL THEN
						RETURN tudien[x - 1].tail 
					x-- 
				RETURN NULL 
			ELSE 
				RETURN NULL 
			ENDIF
		ENDIF
	ELSE 
		RETURN NULL 
END
// **
word* rightwordhashtable* tudien, word* current THEN //Tim tu phia sau cua tu hien tai
BEGIN
	INPUT *tudien, *current
	IF current != NULL THEN
		*right = current->right 
		IF right != NULL THEN
			RETURN right 
		ELSE 
			x = taptudien(current->tu)
			IF x < 25 THEN
				WHILE x != 26 DO
					IF tudien[x + 1].head != NULL THEN
						RETURN tudien[x + 1].head 
					x++ 
				RETURN NULL 
			ELSE 
				RETURN NULL 
			ENDIF
		ENDIF
	ELSE 
		RETURN NULL
	ENDIF
END 

void addword*& head, word*& tail, word*& newword THEN
BEGIN
	INPUT *&head, *&tail, *&newword
	*run = head 
	IF head == NULL THEN
		head = tail = newword 
	ELSE 
		WHILE run != NULL DO
			IF run->tu < newword->tu THEN
				IF run->right == NULL THEN
					run->right = newword 
					newword->left = run 
					tail = newword 
					BREAK 
				ELSE 
					run = run->right 
				ENDIF
			ELSE 
				IF run == head THEN
					head = newword 
					head->right = run 
					run->left = head 
					BREAK 
				ELSE 
					*tmp = run->left 
					tmp->right = newword 
					newword->left = tmp 
					newword->right = run 
					run->left = newword 
					BREAK 
				ENDIF
			ENDIF
	ENDIF
END

void deletewordhashtable*& tudien, word*& xoa THEN
BEGIN
	IF xoa != NULL THEN
		x = taptudienxoa->tu 
		*head = tudien[x].head
		*tail = tudien[x].tail 
		IF head->tu == xoa->tu THEN
			IF head->right == NULL THEN
				head = tail = NULL 
			ELSE 
				head = head->right 
				head->left = NULL 
			ENDIF
		ELSE 
			IF xoa->tu == tail->tu THEN
				tail = tail->left 
				tail->right = NULL 
			ELSE 
				* left = xoa->left
				* right = xoa->right 
				left->right = right 
				right->left = left 
				xoa->left = xoa->right = NULL 
			ENDIF
		ENDIF
		delete xoa 
		xoa = NULL 
		tudien[x].head = head 
		tudien[x].tail = tail 
	ENDIF
END

void deletewordcurrenthashtable*& tudien, word*& tuhientai THEN//xoa tu hien tai
BEGIN
	INPUT *& tudien, *& tuhientai
	IF tuhientai != NULL THEN
		* left = leftword(tudien, tuhientai)
		* right = rightword(tudien, tuhientai)
		* tmp = tuhientai 
		IF left == NULL AND right == NULL THEN
			tuhientai = NULL 
		ELSE 
			IF left == NULL THEN
				tuhientai = right 
			ELSE 
				tuhientai = left 
			ENDIF
		ENDIF
		deleteword(tudien, tmp)
	ENDIF
END

void printscreenword* tmp THEN //In 1 tu ra man hinh tim kiem
BEGIN
	IF tmp != NULL THEN
		WRITE  tmp->tu 
END


void displaycurrentword* tmp THEN //Hien thi tu dau tren trong khung ket qua tim kiem
BEGIN
	INPUT *tmp	
	IF tmp != NULL THEN
		WRITE  " "  +  tmp->tu 
		FOR i = tmp->tu.length TO boxs - 1  
			WRITE  " " 
	ENDIF
END

void displaywordhashtable* tudien, word* hientai THEN //Hien thi danh sach tu trong ket qua tim kiem
BEGIN
	INPUT *tudien, *hienta
	IF hientai == NULL THEN
		FOR i = 0 TO boxw - 1 DO  //Xoa sach khung hien thi ket qua tim kiem
			gotoxy(boxx + 1, boxy + 3 + i)
			FOR j = 0  TO boxs - 1  
				WRITE  " " 
	ENDIF
	IF hientai != NULL THEN
		FOR i = 1 TO boxw - 1 DO  //Xoa sach khung hien thi ket qua tim kiem
			gotoxy(boxx + 2, boxy + 3 + i)
			FOR j = 1  TO boxs - 1  
				WRITE  " " 
		FOR i = 0 TO boxw - 1 DO 
			IF i == 0 THEN
				goTOxy(boxx + 1, boxy + 3 + i)
				setcolor(115)
				displaycurrent(hientai)
				setcolor(63) 
			ELSE 
				gotoxy(boxx + 2, boxy + 3 + i)
				printscreen(hientai)
			ENDIF
			hientai = rightword(tudien, hientai)
	ENDIF
END

bool comparestring cantim, word* dang - 1 DO  THEN
BEGIN
	INPUT	cantim, *dangdo
	x = cantim
	y = dangdo ->tu 
	IF x.length > y.length THEN
		RETURN false 
	ELSE 
		FOR i = 0 TO x.length - 1 DO 
			IF x[i] != y[i] THEN
				RETURN false 
		RETURN true 
	ENDIF
END
}

word* searchhashtable* tudien, string searchword THEN //Tim kiem tu va tra ve vi tri cua tu tim duoc
BEGIN
	INPUT * tudien, searchword
	x = taptudiensearchword 
	IF x < 0 THEN
		RETURN NULL 
	ELSE 
		* head = tudien[x].head 
		WHILE head != NULL DO
			IF compare(searchword, head) THEN
				RETURN head 
			head = head->right 
		RETURN NULL 
	ENDIF
END

void menu1 THEN
BEGIN
	gotoy(18, 2)
	setcolor(63) 
	WRITE  "Tab: Them tu moi" 
	gotoxy(18, 3)
	WRITE  "Esc: Ket thuc chuong trinh" 
	setcolor(63)
END

void menu2 THEN
BEGIN
	gotoXY(18, 2)
	setcolor(63) 
	WRITE  "Backspace: Chinh sua tu nay" 
	gotoXY(18, 3)
	WRITE  "Delete: Xoa tu nay" 
	gotoXY(18, 4) 
	WRITE  "Esc: Quay lai khung tim kiem" 
	setcolor(63) 
END

void menu4 THEN
BEGIN
	gotoXY(18, 2) 
	setcolor(63) 
	WRITE  "Esc: Quay lai khung tim kiem" 
	setcolor(63) 
END

void menu5 THEN
BEGIN
	gotoXY(18, 2) 
	setcolor(63)
	WRITE  "Esc: Quay lai tu dang xem" 
	setcolor(63)
END

bool confirmdelword*& tu THEN
BEGIN
	INPUT *&tu
	system("cls")
	gotoy(boxx, boxy)
	WRITE  "Ban co chac muon xoa tu " + tu->tu + " khong?" 
	gotoy(boxx, boxy + 1)
	WRITE  "Nhan phim Enter de xoa!" 
	gotoy(boxx, boxy + 1)
	WRITE  "Nhan phim Esc de quay tro lai!" 
	key = 0 
	WHILE key != 13 AND key != 27 DO
		key = getch 
	system("cls") 
	IF key == 13 THEN
		RETURN true 
	ELSE 
		IF key == 27 THEN
			RETURN false 
	ENDIF
END
}

void delerror THEN//xoa - 1 DO ng ERROR
BEGIN
	gotoxy(18, boxy + boxw + 2 )
	FOR i = 0 TO 39 
		WRITE  " " 
END

void printerrorint k THEN
BEGIN
	INPUT k
	delerror() 
	IF k == 1 THEN e = "Bat buoc nhap tu!" 
	ELSE IF k == 2  THEN e = "Tu nay da TO n tai!" 
	ELSE IF k == 3  THEN e = "Vui long nhap nghia cua tu!" 
	ELSE IF k == 4  THEN e = "Vui long nhap dang day du cua tu!" 
	setcolor(62)
	gotoxy(18, boxy + boxw + 2)
		WRITE  "ERROR: " +  e 
	setcolor(63) 
END

string fixtextstring t THEN
BEGIN
	INPUT t
	IF t != "" THEN
		WHILE t[0] == ' ' DO
			t.erase(0, 1)  //Xoa khoang trang o dau
		WHILE t[t.length - 1] == ' ' DO
			t.erase(t.length - 1, 1)  //Xoa khoang trang o cuoi
		IF t.length > 3 //Xoa khoang trang thua o giua
			FOR i = 1 TO t.length - 3  
				IF t[i] == ' ' AND t[i + 1] == ' ' THEN
					t.erase(i, 1) 
					i-- 
				ENDIF
		FOR i = 0 TO t.length DO
		    IF t[i] >= 'A' AND t[i] <= 'Z' 
				t[i] += 32  //Chuyen chu hoa thanh chu thuong
		RETURN t 
	ELSE 
		RETURN t 
	ENDIF
END

int checktexthashtable* tudien, string t, int k THEN
BEGIN
	INPUT *tudien, t, k
	t = fixtext(t) 
	IF k == 1 THEN
		IF t == "" 
			RETURN 1 
		ELSE 
			IF search(tudien, t) != NULL THEN
				IF search(tudien, t)->tu.length == t.length 
					RETURN 2 
		ENDIF
	ELSE 
		IF k == 2 THEN
			IF t == "" 
				RETURN 3 
		ELSE 
			IF k == 5 THEN
				IF t == "" 
					RETURN 4 
		ENDIF
	ENDIF
	RETURN 0 
END

void addwordbox THEN//tao khung them tu moi
BEGIN
	setcolor55 
	gotoxy(boxx, boxy)
		WRITE  char (201)
	FOR i = 1 TO boxs
	 	WRITE  char (205) 
	WRITE  char (187) 
	gotoxy(boxx, boxy + 1)
		 WRITE  char (186) + " Tu viet tat:" 
	gotoxy(boxx + 1, boxy + 1)  WRITE  char(186) 
	gotoxy(boxx, boxy + 2); WRITE char(186) + "   Nghia 1    :"
	gotoxy(boxx + boxs + 1, boxy + 2); WRITE char(186)
	gotoxy(boxx, boxy + 3); WRITE char(186) + "   Nghia 2    :"
	gotoxy(boxx + boxs + 1, boxy + 3); WRITE char(186)
	gotoxy(boxx, boxy + 4); WRITE char(186) + "   Nghia 3    :"
	gotoxy(boxx + boxs + 1, boxy + 4); WRITE char(186)
	gotoxy(boxx, boxy + 5); WRITE char(186) + "   Dang day du:"
	gotoxy(boxx + boxs + 1, boxy + 5); WRITE char(186)
	gotoxy(boxx, boxy + 6); WRITE char(186) + "   Vi du 1    :"
	gotoxy(boxx + boxs + 1, boxy + 6); WRITE char(186)
	gotoxy(boxx, boxy + 7); WRITE char(186) + "   Vi du 2    :"
	gotoxy(boxx + boxs + 1, boxy + 7); WRITE char(186)
	gotoxy(boxx, boxy + 8); WRITE char(186) + "   Vi du 3    :"
	gotoxy(boxx + boxs + 1, boxy + 8); WRITE char(186)
	gotoxy(boxx, boxy + 9); WRITE char(200)
	FOR i = 1 TO boxs   
		WRITE  char(205) 
	WRITE  char(188) 
	setcolor(63)
END
}

void printtextfieldstring t, int k THEN
BEGIN
	INPUT t, k
	gotoxy(boxx + 17, boxy + k)
	IF t.length >= boxs - 17 THEN
		FOR i = 0 TO boxs - 18
			WRITE  t[i] 
	ELSE 
		IF t.length < boxs - 17 THEN
			WRITE  t 
			FOR i = 0 TO boxs - 18 - t.length   
				WRITE  " " 
	ENDIF
END

void addword(hashtable*& tudien THEN
BEGIN
	INPUT *&tudien
	system("cls") 
	field[0] = "" 
	field[1] = "" 
	field[2] = "" 
	field[3] = "" 
	field[4] = "" 
	field[5] = "" 
	field[6] = "" 
	field[7] = "" 
	addwordbox()
	menu4()
	FOR k = 1 TO 8 DO
		keyhit = 0 
		dem = field[k - 1].length 
		text = field[k - 1] 
		WHILE keyhit != 13 DO
			gotoxy(boxx + 17, boxy + k) 
			IF dem < boxs - 17 THEN
				WRITE  text 
				FOR i = 1 TO boxs - 16 - dem - 1 DO
					WRITE  " " 
			ELSE 
				FOR i = dem - boxs + 17 TO dem - 1 DO
					WRITE  text[i] 
			ENDIF
			IF dem < boxs - 17
				gotoxy(boxx + 17 + dem, boxy + k)  //Xuat ra vi tri con tro khi khung nhap chua bi tran
			ELSE 
				gotoxy(boxx + boxs, boxy + k)  //Xuat ra vi tri con tro khi khung nhap bi tran
			keyhit = getch()
			IF keyhit == 224 THEN
				keyhit = getch() 
				IF keyhit == 72 THEN
					IF checktext(tudien, text, k) != 0 THEN
						keyhit = 0 
						printerrorchecktext(tudien, text, k )
					ELSE 
						text = fixtext(text)
						printtextfield(text, k) 
						field[k - 1] = text 
						delerror() 
						IF k > 1 THEN
							k-- 
						dem = field[k - 1].length 
						text = field[k - 1] 
					ENDIF
				ELSE 
					IF keyhit == 80 THEN
						IF checktext(tudien, text, k) != 0 THEN
							keyhit = 0 
							printerrorchecktext(tudien, text, k) 
					ELSE 
						text = fixtext(text) 
						printtextfield(text, k) 
						field[k - 1] = text 
						delerror() 
						IF k < 8 THEN
							k++ 
						dem = field[k - 1].length 
						text = field[k - 1] 
					ENDIF
				ENDIF
			ELSE 
				IF keyhit == 8 THEN
					IF dem > 0 AND dem < boxs - 16 THEN
						dem-- 
						text = text.substr0, text.size - 1 
					ELSE 
						IF dem > 0 THEN
							dem-- 
							text = text.substr(0, text.size - 1) 
					ENDIF
				ELSE 
					IF (dem < boxs - 17 AND ((keyhit > 96 AND keyhit < 123) OR (keyhit > 64 AND keyhit < 91) OR keyhit == 32 OR keyhit == 39 OR keyhit == 45 OR keyhit == 63 OR keyhit == 33 ))THEN
						IF keyhit == 63 OR keyhit == 33 THEN
							IF k == 7 OR k == 8 OR k == 9 THEN
								dem++ 
								text += char(keyhit) 
							ENDIF
						ELSE 
							dem++ 
							text += char(keyhit) 
					ELSE 
						IF (keyhit > 96 AND keyhit < 123) OR (keyhit > 64 AND keyhit < 91) OR keyhit == 32 OR keyhit == 39 OR keyhit == 45 OR keyhit == 63 OR keyhit == 33 THEN
							IF keyhit == 63 OR keyhit == 33 THEN
								IF k == 7 OR k == 8 OR k == 9 THEN
									dem++ 
									text += char(keyhit) 
							ELSE 
								dem++ 
								text += char(keyhit)
						ELSE 
							IF keyhit == 27 
								BREAK 
							ELSE 
								IF keyhit == 13 
									IF checktext(tudien, text, k) != 0 THEN
										keyhit = 0 
										printerrorcheck(texttudien, text, k) 
									ENDIF
							ENDIF
						ENDIF
			IF keyhit == 27 THEN
				BREAK 
			text = fixtext(text) 
			printtextfield(text, k) 
			field[k - 1] = text 
			delerror() 
	
	IF keyhit != 27 THEN
		* tu = new word 
		tu->tu = field[0] 
		tu->nghia[0] = field[1] 
		tu->nghia[1] = field[2] 
		tu->nghia[2] = field[3] 
		tu->tu_daydu = field[4] 
		tu->vidu[0] = field[5] 
		tu->vidu[1] = field[6] 
		tu->vidu[2] = field[7] 
		add(tudien[taptudientu->tu].head, tudien[taptudientu->tu].tail, tu )
		updated = true 
	ENDIF
	system("cls") 
END

void editwordhashtable* tudien, word*& hientai THEN
BEGIN
	INPUT *tudien, *&hientai
	system("cls") 
	field[0] = hientai->tu 
	field[1] = hientai->nghia[0] 
	field[2] = hientai->nghia[1] 
	field[3] = hientai->nghia[2] 
	field[4] = hientai->tu_daydu 
	field[5] = hientai->vidu[0] 
	field[6] = hientai->vidu[1] 
	field[7] = hientai->vidu[2] 
	addwordbox()
	menu5() 
	FOR k = 1  TO 8  DO //In gia tri cua cac field ra man hinh
		text = field[k - 1] 
		dem = field[k - 1].length 
		gotoxy(boxx + 17, boxy + k)
		IF dem < boxs - 17 THEN
			WRITE  text 
			FOR i = 1 TO boxs - 16 - dem -1 DO
			   	WRITE  " " 
		ELSE 
			FOR i = 0 TO boxs - 17   DO
				WRITE  text[i] 
		ENDIF
	
	FOR k = 1  TO 8  DO
		keyhit = 0 
		dem = field[k - 1].length 
		text = field[k - 1] 
		WHILE keyhit != 13 DO
			gotoxy(boxx + 17, boxy + k) 
			IF dem < boxs - 17 THEN
				WRITE  text 
				FOR i = 1 TO boxs - 16 - dem -1  
					WRITE  " " 
			ELSE 
				FOR i = dem - boxs + 17 TO dem -1 
					WRITE  text[i] 
			ENDIF
			
			IF dem < boxs - 17
				gotoxy(boxx + 17 + dem, boxy + k)  //Xuat ra vi tri con tro khi khung nhap chua bi tran
			ELSE 
				gotoxy(boxx + boxs, boxy + k)  //Xuat ra vi tri con tro khi khung nhap bi tran
			keyhit = getch()
			IF keyhit == 224 THEN
				keyhit = getch() 
				IF keyhit == 72 THEN
					IF k != 1 THEN
						IF checktext(tudien, text, k) != 0 THEN
							keyhit = 0 
							printerrorchecktext(tudien, text, k) 
						ELSE 
							text = fixtext(text) 
							printtextfield(text, k) 
							field[k - 1] = text 
							delerror() 
							IF k > 1 THEN
								k-- 
							dem = field[k - 1].length 
							text = field[k - 1] 
						ENDIF
					ELSE 
						IF fixtext(text) != field[0] THEN
							IF checktext(tudien, text, k) != 0 THEN
								keyhit = 0 
								printerrorchecktexttudien, text, k 
							ELSE 
								text = fixtext(text)
								printtextfield(text, k) 
								field[k - 1] = text 
								delerror() 
								IF k > 1 THEN
									k-- 
								dem = field[k - 1].length 
								text = field[k - 1] 
							ENDIF
						ELSE 
							text = fixtext(text) 
							printtextfield(text, k) 
							field[k - 1] = text 
							delerror() 
							IF k > 1 THEN
								k-- 
							dem = field[k - 1].length 
							text = field[k - 1] 
						ENDIF
					ENDIF
				ELSE 
					IF keyhit == 80 THEN
						IF k != 1 THEN
							IF checktext(tudien, text, k) != 0 THEN
								keyhit = 0 
								printerrorchecktext(tudien, text, k) 
							ELSE 
								text = fixtext(text) 
								printtextfield(text, k) 
								field[k - 1] = text 
								delerror() 
								IF k < 8 THEN
									k++ 
								dem = field[k - 1].length 
								text = field[k - 1] 
							ENDIF
						ELSE 
							IF fixtext(text) != field[0] THEN
								IF checktext(tudien, text, k) != 0 THEN
									keyhit = 0 
									printerrorchecktext(tudien, text, k) 	
								ELSE 
									text = fixtext(text) 
									printtextfield(text, k) 
									field[k - 1] = text 
									delerror() 
									IF k < 8 THEN
										k++ 
									dem = field[k - 1].length 
									text = field[k - 1] 
								ENDIF
							ELSE 
								text = fixtext(text) 
								printtextfield(text, k) 
								field[k - 1] = text 
								delerror() 
								IF k < 8 THEN
									k++ 
								dem = field[k - 1].length 
								text = field[k - 1] 
							ENDIF
						ENDIF
				ENDIF
			ELSE 
				IF keyhit == 8 THEN
					IF dem > 0 AND dem < boxs - 16 THEN
						dem-- 
						text = text.substr(0, text.size - 1) 
					ELSE 
						IF dem > 0 THEN
							dem-- 
							text = text.substr(0, text.size - 1) 
					ENDIF
				ELSE 
					IF dem < boxs - 17 AND ((keyhit > 96 AND keyhit < 123) OR (keyhit > 64 AND keyhit < 91) OR keyhit == 32 OR keyhit == 39 OR keyhit == 45 OR keyhit == 63 OR keyhit == 33)THEN
						IF keyhit == 63 OR keyhit == 33 THEN
							IF k == 7 OR k == 8 OR k == 9 THEN
								dem++ 
								text += char(keyhit) 
						ELSE 
							dem++ 
							text += char(keyhit) 
						ENDIF
					ELSE 
						IF (keyhit > 96 AND keyhit < 123) OR (keyhit > 64 AND keyhit < 91) OR keyhit == 32 OR keyhit == 39 OR keyhit == 45 OR keyhit == 63 OR keyhit == 33 THEN
							IF keyhit == 63 OR keyhit == 33 THEN
								IF k == 7 OR k == 8 OR k == 9 THEN
									dem++ 
									text += char(keyhit) 
							ELSE 
								dem++ 
								text += char(keyhit) 
							ENDIF
						ELSE 
							IF keyhit == 27 THEN
								BREAK 
							ELSE 
								IF keyhit == 13 THEN
									IF k != 1 THEN
										IF checktext(tudien, text, k) != 0 THEN
											keyhit = 0 
											printerrorchecktext(tudien, text, k) 
										ENDIF
									ELSE 
										IF fixtext(text) != field[0] THEN //Neu k = 1, text khong thay - 1 DO i thi khong can check...
											IF checktext(tudien, text, k) != 0 THEN
												keyhit = 0 
												printerrorchecktext(tudien, text, k) 
											ENDIF
									ENDIF
							ENDIF
						ENDIF
		IF keyhit == 27 THEN
			BREAK 
		text = fixtext(text) 
		printtextfield(text, k) 
		field[k - 1] = text 
		delerror() 
	
	IF keyhit != 27 THEN
		hientai->tu = field[0] 
		hientai->nghia[0] = field[1] 
		hientai->nghia[1] = field[2] 
		hientai->nghia[2] = field[3] 
		hientai->tu_daydu = field[4] 
		hientai->vidu[0] = field[5] 
		hientai->vidu[1] = field[6] 
		hientai->vidu[2] = field[7] 
		updated = true 
	ENDIF
	system("cls") 
END

void dicbox THEN //Ham tao khung nhap va khung ket qua tim kiem
BEGIN
	setcolor(55) 
	gotoxy(boxx, boxy) 
		WRITE  char(201) 
	FOR i = 1 TO boxs + 1 DO
		WRITE  char(205) 
	WRITE  char(187) 
	gotoxy(boxx, boxy + 1)  
		WRITE  char(186) + " Tim kiem:" 
	gotoxy(boxx + boxs + 1, boxy + 1)  
		WRITE  char(186) 
	gotoxy(boxx, boxy + 2)  
		WRITE  char(204) 
	FOR i = 1 TO boxs + 1 - 1 DO 
		WRITE  char(205) 
	
	WRITE  char(185) 
	FOR i = boxy + 3 TO boxy + 3 + boxw - 1 DO 
		gotoxy(boxx, i) 
		WRITE  char(186)
		gotoxy(boxx + boxs + 1, i)
		WRITE  char(186) 
	
	gotoxy(boxx, boxy + boxw + 3)
		WRITE  char(200)
	FOR i = 1 TO boxs DO
		WRITE  char(205) 
	WRITE  char(188) 
	setcolor(63) 
END

void stringoutstring n, int d THEN //Ham xuat ra chuoi string va tu - 1 DO ng xuong - 1 DO ng trong khung xem tu chi tiet
BEGIN
	INPUT n, d
	int dem = 0 
	FOR i = 0 TO n.length - 1 DO 
		WRITE  n[i] 
		IF i + 1 % boxs - 2 == 0 THEN
			dem++ 
			go  TO xyboxx + 2, boxy + d + dem 
		ENDIF
END

int linecountstring n THEN //Ham dem xem de xuat ra tu nay can bao nhieu - 1 DO ng
BEGIN
	INPUT n
	IF n == "" 
		RETURN 0 
	ELSE 
		int d = n.length / boxs - 2 
		int e = n.length % boxs - 2 
		IF e != 0 d++ 
		RETURN d 
	ENDIF
END

void detailboxword* hientai THEN //Ham tao khung hien thi thong tin tu can tra
BEGIN
	INPUT *hientai
	setcolor(55)
	nghia = "nghia: " 
	nghia += hientai->nghia[0] 
	IF hientai->nghia[1] != "" 
		nghia = nghia + "  " + hientai->nghia[1] 
	IF hientai->nghia[2] != "" 
		nghia = nghia + "  " + hientai->nghia[2] 
	d = 2 
	d += linecount(nghia) 
	IF hientai->vidu[0] != "" 
		d += linecount("Vi du 1: " + hientai->vidu[0]) 
	IF hientai->vidu[1] != "" 
		d += linecount("Vi du 2: " + hientai->vidu[1]) 
	IF hientai->vidu[2] != "" 
		d += linecount("Vi du 3: " + hientai->vidu[2]) 
	gotoxy(boxx, boxy)
		WRITE  char(201) 
	FOR i = 1 TO boxs DO
		WRITE  char(205) 
	WRITE  char(187) 
	FOR i = boxy + 1 TO boxy + 1 + d - 1 DO 
		gotoxy(boxx, i) 
		WRITE  char(186) 
		gotoxy(boxx + boxs + 1, i) 
		WRITE  char(186) 
	gotoxy(boxx, boxy + d + 1)  
		WRITE  char(200) 
	FOR i = 1 TO boxs DO  
		WRITE  char(205) 
	WRITE  char(188) 
	setcolor(63) 
END

void detailwordhashtable* tudien, word*& hientai THEN //Ham xuat ra man hinh thong tin chi tiet cua tu can tra
BEGIN
	INPUT *tudien, *&hientai
	system("cls") 
	int keyhit = 0 
	WHILE keyhit != 27 DO
		IF hientai != NULL THEN
			d = 3 
			menu2() 
			detailbox(hientai) 
			gotoxy(boxx + 2, boxy + 1)  //In tu dang xem
			WRITE  hientai->tu 
			gotoxy(boxx + 2, boxy + 2)  //In dang viet day du 
			WRITE  "Dang day du: " + hientai->tu_daydu 
			gotoxy(boxx + 2, boxy + d)  //In ra cac nghia
			nghia = "Nghia: " 
			nghia += hientai->nghia[0] 
			IF hientai->nghia[1] != "" THEN
				nghia = nghia + "  " + hientai->nghia[1] 
			IF hientai->nghia[2] != "" THEN
				nghia = nghia + "  " + hientai->nghia[2] 
			stringout(nghia, d) 
			d += linecount(nghia) 
			IF hientai->vidu[0] != "" THEN //In ra vi du 1
				gotoxy(boxx + 2, boxy + d) 
				stringout("Vi du 1: " + hientai->vidu[0], d) 
				d += linecount("Vi du 1: " + hientai->vidu[0]) 
			ENDIF
			IF hientai->vidu[1] != "" THEN //In ra vi du 2
				gotoxy(boxx + 2, boxy + d) 
				stringout("Vi du 2: " + hientai->vidu[1], d) 
				d += linecount("Vi du 2: " + hientai->vidu[1]) 
			ENDIF
			IF hientai->vidu[2] != "" THEN //In ra vi du 3
				gotoxy(boxx + 2, boxy + d) 
				stringout("Vi du 2: " + hientai->vidu[2], d) 
			ENDIF
			keyhit = getch()
			IF keyhit == 8 THEN
				editword(tudien, hientai) //an backspace
			ELSE 
				IF keyhit == 83 THEN//an delete
					IF confirmdel(hientai) THEN
						deletewordcurrent(tudien, hientai) 
						keyhit = 27 
						updated = true 
					ENDIF
			ENDIF
		ELSE 
			keyhit = 27 
		ENDIF
	system("cls") 
END

void searchboxhashtable*& tudien, word*& tuhientai THEN //Ham khung nhap tu khoa va ket qua tim kiem
BEGIN
	INPUT *&tudien, *&tuhientai
	setcolor(63) 
	changed = false 
	intext = "" 
	dem = 0 
	keyhit = 0 
	WHILE keyhit != 27 DO //chua nhan Esc
		menu1()
		dicbox() 

		gotoxy(boxx + 12, boxy + 1)  //Viet lai nhung chu cai da nhap trong khung tim kiem
		IF dem < boxs - 12 THEN
			WRITE  intext 
		ELSE 
			FOR i = dem - boxs + 12 TO dem -1
			   WRITE  intext[i] 
		ENDIF
		WHILE keyhit != 13 OR tuhientai == NULL DO//Chua nhan Enter
			IF changed THEN
				IF fixtext(intext) != "" THEN
					tuhientai = search(tudien, fixtext(intext)) 
				ELSE 
					findfirstword(tudien, tuhientai) 
				ENDIF
			displayword(tudien, tuhientai)  //Hien thi ket qua tim kiem

			IF dem < boxs - 12 THEN
				gotoxy(boxx + 12 + dem, boxy + 1)  //Xuat ra vi tri con tro khi khung nhap chua bi tran
			ELSE 
				gotoxy(boxx + boxs, boxy + 1)  //Xuat ra vi tri con tro khi khung nhap bi tran

			keyhit = getch()
			IF keyhit == 224 THEN
				keyhit = getch() 
				IF keyhit == 72 THEN //UP
					IF leftword(tudien, tuhientai) != NULL THEN
						tuhientai = leftword(tudien, tuhientai) 
				ELSE 
					IF keyhit == 80 THEN // - 1 DO WN
					IF rightword(tudien, tuhientai) != NULL THEN
						tuhientai = rightword(tudien, tuhientai) 
				ENDIF
				changed = false 
			ELSE 
				IF keyhit == 8 THEN //Kiem tra phim backspace de xoa...
					IF dem > 0 AND dem < boxs - 11 THEN
						dem-- 
						intext = intext.substr(0, intext.size - 1)  //Xoa ky tu cuoi trong string
						gotoxy(boxx + 12, boxy + 1) 
						WRITE  intext 
						FOR i = 1 TO boxs - 11 - dem -1 DO
							WRITE  " " 
					ELSE 
						IF dem > 0 THEN
							dem-- 
							intext = intext.substr(0, intext.size - 1) 
							gotoxy(boxx + 12, boxy + 1) 
							FOR i = dem - boxs + 12 TO dem -1 DO
								WRITE  intext[i] 
					ENDIF
					changed = true 
				ELSE 
					IF dem < boxs - 12 AND ((keyhit > 96 AND keyhit < 123) OR keyhit > 64 AND keyhit < 91 OR keyhit == 32 OR keyhit == 39 OR keyhit == 45)THEN
						dem++ 
						intext += char(keyhit) 
						gotoxy(boxx + 12, boxy + 1) 
						WRITE  intext 
						FOR i = 1 TO boxs - 11 - dem -1 DO
							WRITE  " " 
						changed = true 
					ELSE IF (keyhit > 96 AND keyhit < 123)/*a -z*/ OR (keyhit > 64 AND keyhit < 91)/*A- Z*/ OR keyhit == 32/*space*/ OR keyhit == 39/* ' */ OR keyhit == 45/* - */ THEN
						dem++ 
						intext += char(keyhit) 
						gotoxy(boxx + 12, boxy + 1 )
						FOR i = dem - boxs + 12 TO dem -1 DO
						   WRITE  intext[i] 
						changed = true 
					ENDIF
			ELSE 
				IF keyhit == 27 
					BREAK //Esc
				ELSE 
					IF keyhit == 9 
						BREAK //Tab
				ENDIF
		IF keyhit == 13 THEN
			detailword(tudien, tuhientai)
			keyhit = 0 
		ELSE 
			IF keyhit == 9 THEN
				addword(tudien) 
			ELSE 
				system("cls") 
				gotoxy(boxx, boxy)  
					WRITE  "Nhan Esc mot lan nua de thoat chuong trinh" 
				gotoxy(boxx, boxy + 1) 
					WRITE  "Nhan bat ky phim nao khac de quay lai chuong trinh" 
				keyhit = getch() 
				IF keyhit != 27 THEN
					IF keyhit == 224 THEN
						keyhit = getch()
					keyhit = 0 
				}
				system("cls") 
			ENDIF
		ENDIF
END
/* END Layout */

void addlastword*& head, word*& tail, word*& newword THEN
BEGIN
	INPUT *&head, *&tail, *&newword
	IF head == NULL THEN
		head = tail = newword 
	ELSE 
		tail->right = newword 
		newword->left = tail 
		tail = newword 
	ENDIF
END

void tachchuoistring line, word*& tmp THEN //Ham tach chuoi ra thanh va gan vao nhung vi tri phu hop
BEGIN
	INPUT line, *&tmp
	d = 0
	i = 0 
	tach = "" 
	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->tu = tach 
	tach = "" 
	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->tu_daydu = tach 
	tach = "" 

	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->nghia[0] = tach 
	tach = "" 

	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->nghia[1] = tach 
	tach = "" 
	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->nghia[2] = tach 
	tach = "" 
	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->vidu[0] = tach 
	tach = "" 
	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->vidu[1] = tach 
	tach = "" 
	WHILE line[i] != '/' DO
		tach += line[i] 
		i++
	i++
	tmp->vidu[2] = tach 
END

void importwordhashtable*& tudien, string line THEN//ham luu thong tin cac tu viet tat vao danh sach
BEGIN
	INPUT *&tudien, line
	FOR i = 97 TO 124 - 1 DO 
		IF line[0] == i THEN
			* newword = new word 
			tachchuoi(line, newword) 
			newword->left = NULL 
			newword->right = NULL 
			addlast(tudien[i - 97].head, tudien[i - 97].tail, newword) 
			BREAK 
		ENDIF
END

void readfhashtable*& tudien, word*& tuhientai THEN // - 1 DO c file
BEGIN
	INPUT *&tudien, *& tuhientai
	IFstream fi("data.txt")  
	IF fi.is_open THEN
		WHILE getline(fi, line) THEN
			importword(tudien, line) 
		fi.close()
	findfirstword(tudien, tuhientai) 
END

void writefhashtable* tudien THEN //Ghi file
BEGIN
	ofstream fo"./data.txt" 
	IF fo.is_open THEN
		FOR i = 0 TO 26 - 1 DO 
			word* head = tudien[i].head 
			WHILE head != NULL THEN
				fo  head->tu
					 "/"  head->tu_daydu
					 "/"  head->nghia[0]
					 "/"  head->nghia[1]
					 "/"  head->nghia[2]
					 "/"  head->vidu[0]
					 "/"  head->vidu[1]
					 "/"  head->vidu[2]  "/\n" 
				head = head->right 
			}
		}
		fo.close 
	}
END

int main THEN
BEGIN
	system("color 3f") 
	SetConsoleTitle("TU DIEN VIET TAT") 
	* tuhientai = NULL 
	* tudien = new hashtable[26] 
	FOR i = 0 TO 26 - 1 DO 
		tudien[i].tail = NULL 
		tudien[i].head = NULL 
	readf(tudien, tuhientai) 
	searchbox(tudien, tuhientai) 
	IF (updated) 
		writef(tudien) 
	gotoxy(0, boxw + 10) 
	RETURN 0 
END

