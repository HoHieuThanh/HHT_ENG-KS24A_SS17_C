#include <stdio.h>
#include <string.h>
#include <ctype.h>

void addStr(char *str);
void reverseStr(char *str1, int size, char *reverse);
int countWord(char *str1, int size);
void compareStr(char *str1, int size, char *str2);
void toUpper(char *str1);
void appendStr(char *str1, char *str2);

int main() {
	
	char str1[100], str2[100], reverse[100];
	int choice, size;
	do{
		printf("\nMENU\n");
        printf("1. Nhap vao chuoi (Moi tu cach nhau boi 1 dau cach)\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch(choice){
        	case 1:
        		addStr(str1);
        		size=strlen(str1);
        		break;
        	case 2:
        		reverseStr(str1, size, reverse);
        		printf("%s\n", reverse);
        		break;
        	case 3:
        		printf("Chuoi co %d tu\n", countWord(str1, size));
        		break;
        	case 4:
        		printf("Nhap chuoi khac: ");
                addStr(str2);
                compareStr(str1, size, str2);
        		break;
        	case 5:
        		toUpper(str1);
                printf("%s\n", str1);
        		break;
        	case 6:
        		printf("Nhap chuoi khac: ");
                addStr(str2);
                appendStr(str1, str2);
                printf("Chuoi sau khi noi: %s\n", str1);
        		break;
        	case 7:
        		printf("Ket thuc chuong trinh");
        		break;
        	default:
        		printf("Khong hop le\n");
		}
	}while(choice!=7);
	
	return 0;
}

void addStr(char *str){
	fgets(str,100,stdin);
	str[strcspn(str, "\n")] = '\0';
}

void reverseStr(char *str1, int size, char *reversed) {
    for (int i = 0; i < size; i++) {
        reversed[i] = str1[size - i - 1];
    }
}

 int countWord(char *str1, int size){
	int count=1;
	for(int i=0; i<size; i++){
		if(str1[i]==' '){
			count++;
		}
	}
	if(str1[0]==' '){
		count--;
	}
	if(str1[size-1]==' '){
		count--;
	}
	if(count==1){
		return count;
	}
	return count;
}

void compareStr(char *str1, int size, char *str2) {
    int size2 = strlen(str2);
    if (size > size2) {
        printf("Chuoi ban dau dai hon chuoi moi\n");
    } else if (size < size2) {
        printf("Chuoi ban dau ngan hon chuoi moi\n");
    } else {
        printf("Hai chuoi co do dai bang nhau\n");
    }
}

void toUpper(char *str1) {
    while (*str1) {
        *str1 = toupper(*str1);
        str1++;
    }
}

void appendStr(char *str1, char *str2) {
    strcat(str1,str2);
}