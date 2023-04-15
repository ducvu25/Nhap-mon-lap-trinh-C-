	void findfirstword(hashtable* tudien, word*& tuhientai)
BEGIN
	INPUT *tudien, *&hientai
	FOR i = 0 TO 26 - 1 DO
		IF tudien[i].head THEN
			tuhientai = tudien[i].head
			BREAK
		ENDIF
END

	
	int taptudien(string tu)
BEGIN
	INPUT tu
	IF tu THEN
		x = tu[0]
		IF x < 123 AND x > 96 THEN
			RETURN 	x - 97
	ENDIF
	RETURN -1
END

	word* leftword(hashtable* tudien, word* current)
BEGIN
	INPUT *tudien, *current
	IF current THEN
		*left = current->left
		IF left THEN
			RETURN left
		ELSE
			x = taptudien(current->tu);
			IF x > 0 THEN 
				WHILE x > 0 DO
					IF tudien[x - 1].tail THEN
						RETURN tudien[x - 1].tail
					x--
				RETURN NULL
			ELSE
				RETURN NULL
			ENDIF
		ENDIF
	ELSE
		RETURN NULL
	ENDIF
END

	word* rightword(hashtable* tudien, word* current) //Tim tu phia sau cua tu hien tai
BEGIN	
	IF current THEN
		*right = current->right
		IF right THEN
			RETURN right
		ELSE
			x = taptudien(current->tu)
			IF x < 25 THEN
				WHILE x != 26 DO
					IF tudien[x + 1].head THEN
						RETURN tudien[x + 1].head;
					x++
				RETURN NULL;
			ELSE
				RETURN NULL;
			ENDIF
		ENDIF
	ELSE
		RETURN NULL;
	ENDIF
END


		void editword(hashtable* tudien, word*& hientai) 
BEGIN
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
	FOR k = 1 TO 9 - 1 DO 
		text = field[k - 1];
		dem = field[k - 1].length()
		gotoxy(boxx + 17, boxy + k)
		IF dem < boxs - 17 THEN
			WRITE text;
			FOR i = 1 TO boxs - 16 - dem -1 DO
				WRITE " "
		ELSE
			FOR i = 0 TO boxs - 17 - 1 DO
				WRITE text[i];
		ENDIF
	
	FOR k = 1 TO 9 - 1 DO
		keyhit = 0
		dem = field[k - 1].length()
		text = field[k - 1]
		 WHILE keyhit != 13 DO
			gotoxy(boxx + 17, boxy + k)
			IF dem < boxs - 17 THEN
				WRITE text
				FOR i = 1 TO boxs - 16 - dem -1 DO
					WRITE " "
			ELSE
				FOR i = dem - boxs + 17 TO i < dem DO
				WRITE text[i]
			ENDIF
			
			IF dem < boxs - 17 THEN
				gotoxy(boxx + 17 + dem, boxy + k) //Xuat ra vi tri con tro khi khung nhap chua bi tran
			ELSE
				gotoxy(boxx + boxs, boxy + k) //Xuat ra vi tri con tro khi khung nhap bi tran
			keyhit = getch()
			ENDIF
			IF keyhit == 224 THEN
				keyhit = getch()
				IF keyhit == 72 THEN
					IF k != 1 THEN
						IF checktext(tudien, text, k) != 0 THEN
							keyhit = 0
							printerror(checktext(tudien, text, k))
						ELSE
							text = fixtext(text)
							printtextfield(text, k)
							field[k - 1] = text
							delerror()
							IF k > 1 THEN
								k--;
							dem = field[k - 1].length();
							text = field[k - 1];
						ENDIF
					ELSE
						IF fixtext(text) != field[0] THEN
							IF checktext(tudien, text, k) != 0 THEN
								keyhit = 0;
								printerror(checktext(tudien, text, k));
							ELSE
								text = fixtext(text)
								printtextfield(text, k)
								field[k - 1] = text;
								delerror()
								IF k > 1 THEN
									k--;
								dem = field[k - 1].length()
								text = field[k - 1]
							ENDIF
						ENDIF
					ELSE
						text = fixtext(text)
						printtextfield(text, k)
						field[k - 1] = text
						delerror()
						IF k > 1 THEN
							k--
						dem = field[k - 1].length()
						text = field[k - 1]
					ENDIF	
				ELSE
					IF keyhit == 80 THEN
						IF k != 1 THEN
							IF checktext(tudien, text, k) != 0 THEN
								keyhit = 0
								printerror(checktext(tudien, text, k))
							ELSE
								text = fixtext(text)
								printtextfield(text, k)
								field[k - 1] = text
								delerror()
								IF k < 8 THEN
									k++
								dem = field[k - 1].length()
								text = field[k - 1]
						ENDIF
					ELSE
						IF	fixtext(text) != field[0] 	THEN
							IF	checktext(tudien, text, k) != 0	THEN
								keyhit = 0
								printerror(checktext(tudien, text, k))
						ELSE
							text = fixtext(text)
							printtextfield(text, k)
							field[k - 1] = text
							delerror()
							IF	k < 8	THEN
								k++
							dem = field[k - 1].length()
							text = field[k - 1]
						ENDIF
					ELSE
						text = fixtext(text)
						printtextfield(text, k)
						field[k - 1] = text
						delerror()
						IF	k < 8	THEN
							k++
						dem = field[k - 1].length()
						text = field[k - 1]
					ENDIF
			ELSE
				IF keyhit == 8	THEN
					IF	dem > 0 AND dem < boxs - 16	THEN
						dem--
						text = text.substr(0, text.size() - 1)
				ELSE
					IF dem > 0 THEN
						dem--
						text = text.substr(0, text.size() - 1)
				ENDIF
			ELSE
				IF dem < boxs - 17 AND ((keyhit > 96 AND keyhit < 123) OR (keyhit > 64 AND keyhit < 91) OR (keyhit == 32) OR (keyhit == 39) OR (keyhit == 45) OR (keyhit == 63) OR (keyhit == 33)) THEN
					IF	keyhit == 63 OR keyhit == 33 THEN
						IF (k == 7 OR k == 8 OR k == 9 THEN
							dem++
							text += char(keyhit)
				ELSE 
					dem++
					text += char(keyhit)
				ENDIF
			ELSE
				IF ((keyhit > 96 AND keyhit < 123) OR (keyhit > 64 AND keyhit < 91) OR (keyhit == 32) OR (keyhit == 39) OR (keyhit == 45) OR (keyhit == 63) OR (keyhit == 33)) THEN
					IF 	keyhit == 63 OR keyhit == 33 	THEN
					 	IF k == 7 OR k == 8 OR k == 9 	THEN
						dem++;
						text += char(keyhit);
					}
				}
				else {
					dem++;
					text += char(keyhit);
				}
			}
			else if (keyhit == 27) break;
			else if (keyhit == 13) {
				if (k != 1) {
					if (checktext(tudien, text, k) != 0) {
						keyhit = 0;
						printerror(checktext(tudien, text, k));
					}
				}
				else if (fixtext(text) != field[0]) { //Neu k = 1, text khong thay doi thi khong can check...
					if (checktext(tudien, text, k) != 0) {
						keyhit = 0;
						printerror(checktext(tudien, text, k));
					}
				}
			}
		}
		if (keyhit == 27) break;
		text = fixtext(text);
		printtextfield(text, k);
		field[k - 1] = text;
		delerror();
	}
	if (keyhit != 27) {
		hientai->tu = field[0];
		hientai->nghia[0] = field[1];
		hientai->nghia[1] = field[2];
		hientai->nghia[2] = field[3];
		hientai->tu_daydu = field[4];
		hientai->vidu[0] = field[5];
		hientai->vidu[1] = field[6];
		hientai->vidu[2] = field[7];
		updated = true;
	}
	system("cls");
}
