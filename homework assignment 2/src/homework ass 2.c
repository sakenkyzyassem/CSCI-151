#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for encrypting/decrypting
typedef struct{
	char read_f[255];
	int sum;
	char file_ch;
}crypt_f;

void p(char *text){
	printf("%s\n", text);
}

void closingFile(FILE *fin, FILE *fout){
	fclose(fin);
	fclose(fout);
}

//checks the file which name is entered by a user
_Bool checkingOpenedFile(FILE *f, crypt_f scan_ch){
	if(f == NULL){
		printf("CANNOT open %s\n", scan_ch.read_f);
		return 0;}
	else
		return 1;
}

void encrypt( FILE *fin, FILE *fout, char key_ch[], char pass_ar[] ){
	int i, pass_index, pass_len;
	char ch;
	crypt_f enc;
	pass_len = strlen(pass_ar);

	for(i=0; !feof(fin); i++){
		ch = getc(fin);
		if((unsigned char) ch != 255){  //at the end of file sometimes there is EOF char which is not needed to be encrypted
		pass_index = i % pass_len;
		enc.sum = (pass_ar[pass_index] + (unsigned char) ch) % 255;
		putc(key_ch[enc.sum], fout);}
	}

	closingFile(fin, fout);
}

void decrypt( FILE *fin, FILE *fout, char key_ch[], char pass_ar[] ){
	int i, j, pass_index, pass_len;
	char ch;
	crypt_f dec;
	pass_len = strlen(pass_ar);

	for(i=0; !feof(fin); i++){
		ch = getc(fin);
		if((unsigned char) ch != 255){
		for(j=0; j<255; j++){			//finds that read character from keyfile(array of key)
			if(key_ch[j] == ch)		//and takes its number in an array
				break;}
		pass_index = i % pass_len;
		dec.sum = (j - pass_ar[pass_index]) % 255;
		dec.file_ch =dec.sum;//converts an ASCII number to character
		putc(dec.file_ch, fout);}
	}

	closingFile(fin, fout);
}

char keyFileReading(FILE *keyfile, char key_char[]){
	int i;

	keyfile = fopen("key.254","r");
//in case there is an error opening a key file it quits the program	by returning 'q'
	if(keyfile == NULL){
		p("CANNOT open key.254");
		return 'q';}
//if file is opened successfully it continues working by returning any character
//(in my case I made it is 'c')
	else {
	for(i=0; !feof(keyfile); i++)
	key_char[i] = fgetc(keyfile);

	fclose(keyfile);
	return 'c';
	}
}

int main(){
	setvbuf (stdout, NULL, _IONBF, 0);

	FILE *readFile, *writtenFile;
	crypt_f encrypting;
	crypt_f decrypting;
	char ch, starter[255], key[255], p_arr[255];
	int i=0;

	p("WELCOME to the encryption service.");
	p("ENTER your password:");
	scanf("%s", p_arr);

	do{
//opens and reads key file and declares it to one array
//character k is for continuing/ending the program due to the status of key file
//if opened successfully, continues; if not, provides a message and quits
		FILE *keyFile;
		keyFile = fopen("key.254", "r");
		ch = keyFileReading(keyFile, key);

	if (ch == 'c'){
		p("MENU: <e>ncode, <d>ecode, or <q>uit");
		scanf("%s", starter);
		ch = starter[0];

		switch (ch){

			case 'e':
				//I used a loop so that I can break and and go back to menu in case file cannot be read,
				//or continue if everything is fine
				//Note that when it continues, i = 1 (reading function is BOOL type), and
				//this loop will not run infinitely in case that file is read successfully,
				//so it just exits the loop
				for(i=0; i!=1; ){
					p("ENTER a file to encrypt:");
					scanf("%s", encrypting.read_f);
					readFile = fopen(encrypting.read_f, "r");
					i = checkingOpenedFile(readFile, encrypting);
					if(i == 0)
						break;

					p("ENTER a filename for the encrypted file.");
					scanf("%s", encrypting.read_f);
					writtenFile = fopen(encrypting.read_f, "w");
					i = checkingOpenedFile(writtenFile, encrypting);
					if(i == 0)
						break;
				}
				//If everything is fine with files, i=1, it can continue encrypting
				//if not, i = 0, it breaks and goes back to menu
				if(i==1)
					encrypt (readFile, writtenFile, key, p_arr);
				break;

			case 'd':
				//The same is with decrypting:
				//If there is an error with reading a file it breaks, i = 0
				//but if everything is fine, it continues
				for(i=0; i!=1;){
					p("ENTER a file to decrypt");
					scanf("%s", decrypting.read_f);
					readFile = fopen(decrypting.read_f, "r");
					i = checkingOpenedFile(readFile, decrypting);
					if(i == 0)
						break;

					p("ENTER a filename for the decrypted file.");
					scanf("%s", decrypting.read_f);
					writtenFile = fopen(decrypting.read_f, "w");
					i = checkingOpenedFile(writtenFile, decrypting);
					if(i == 0)
						break;
				}

				if(i==1)
					decrypt(readFile, writtenFile, key, p_arr);
				break;

			case 'q':
				break;

			default:
				printf("UNRECOGNIZED %c\n", ch);
		}
	}
	else
		starter[0] = ch;

	}while(starter[0] != 'q');

	p("BYE!");

	return 0;
}
