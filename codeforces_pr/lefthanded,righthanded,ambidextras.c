// https://codeforces.com/contest/950/problem/A

#include <stdio.h>

int main(){

	setvbuf(stdout, NULL, _IONBF, 0);

	int l, r, a;

	scanf("%i", &l);
	scanf("%i", &r);
	scanf("%i", &a);
//l<r
	if (l<r) {
		if ((l+a)==r){
			printf("%i", a+r+l);	}
		else if ((l+a)<r){
				printf("%i", 2*(l+a));}
		else if ((l+a)>r){
			if((l+a-r)>1){
				if((l+a-r)%2 ==0){
					printf("%i", 2*r+l+a-r);}
				else {
					printf("%i", 2*r+l+a-r-1);}
			}
			else {
			printf("%i", 2*r);		}
		}
	}
//l>r
	else if (l>r){
		if ((r+a)==l){
				printf("%i", a+r+l);	}
		else if ((r+a)<l){
				printf("%i", 2*(r+a));	}
		else if ((r+a)>l){
			if(r+a-l>1){
				if((r+a-l)%2 ==0){
				printf("%i", 2*l+r+a-l);}
				else{
				printf("%i", 2*l+r+a-l-1);}
			}
			else{
				printf("%i", 2*l);	}	}
	}
//l=r
	else {
		if((l+r+a)%2 == 0){
			printf("%i", l+r+a);}
		else {
			printf("%i", l+r+a-1);}
	}
	return 0;
}
