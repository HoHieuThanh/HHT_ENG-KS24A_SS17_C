#include <stdio.h>
#include <string.h>

void addStr(char *str);
void displayStr(char *str);
void displayApb(char *str, int size, int *n, char *apb);
void displayNum(char *str, int size, int*n, char *num);
void displaySpc(char *str, int size, int*n, char *spc);

int main(){	
	
	int choice, n, size;
	char str[100], apb[100], num[100], spc[100];
	do{
		printf("\nMENU\n");
		printf("1.Nhap vao chuoi\n");
		printf("2.Hien thi chuoi\n");
		printf("3.Hien thi so luong chu cai va in ra\n");
		printf("4.Hien thi so luong chu so va in ra\n");
		printf("5.Hien thi so luong ky tu dac biet va in ra\n");
		printf("6.Thoat\n");
		printf("Lua chon: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				fflush(stdin);
				addStr(str);
				size=strlen(str);
				break;
			case 2:
				displayStr(str);
				break;
			case 3:
				n=0;
				displayApb(str,size,&n,apb);
				break;
			case 4:
				n=0;
				displayNum(str,size,&n,num);
				break;
			case 5:
				n=0;
				displaySpc(str,size,&n,spc);
				break;
			case 6:
				break;
			default:
				printf("Khong hop le\n");
		}
	}while(choice!=6);
	
	return 0;
}

void addStr(char *str){
	fgets(str,100,stdin);
}
void displayStr(char *str){
	printf("%s\n", str);
}
void displayApb(char *str, int size, int *n, char *apb){
	for(int i=0; i<size; i++){
		if(*(str+i)>='a' && *(str+i)<='z'||*(str+i)>='A' && *(str+i)<='Z'){
			*(apb+*n)=*(str+i);
			(*n)++;
		}
	}
	if(*n==0){
		printf("Khong co chu cai trong chuoi\n");
	}else{
		printf("Co %d chu cai trong chuoi: ", *n);
		for(int i=0; i<*n; i++){
			printf("%c ", *(apb+i));
		}
	}
}
void displayNum(char *str, int size, int *n, char *num){
	for(int i=0; i<size; i++){
		if(*(str+i)>='0' && *(str+i)<='9'){
			*(num+*n)=*(str+i);
			(*n)++;
		}
	}
	if(*n==0){
		printf("Khong co chu so trong chuoi\n");
	}else{
		printf("Co %d chu so trong chuoi: ", *n);
		for(int i=0; i<*n; i++){
			printf("%c ", *(num+i));
		}
	}
}
void displaySpc(char *str, int size, int *n, char *spc){
	for(int i=0; i<size; i++){
		if(!((*(str+i) >= 'a' && *(str+i) <= 'z') || (*(str+i) >= 'A' && *(str+i) <= 'Z') || (*(str+i) >= '0' && *(str+i) <= '9'))){
			*(spc+*n)=*(str+i);
			(*n)++;
		}
	}
	if(*n==0){
		printf("Khong co ky tu dac biet trong chuoi\n");
	}else{
		printf("Co %d ky tu dac biet trong chuoi: ", *n);
		for(int i=0; i<*n; i++){
			printf("%c ", *(spc+i));
		}
	}
}