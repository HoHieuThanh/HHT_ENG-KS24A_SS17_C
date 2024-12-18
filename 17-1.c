#include <stdio.h>

void addArr(int *arr, int n);
void displayArr(int *arr, int n);
int lengthArr(int *arr);
int sumArr(int *arr, int *n, int *sum);
int maxArr(int *arr, int *n, int *maxValue);

int main(){
	int choice, arr[100], n, sum, size, maxValue;
	
	do{
		printf("\nMENU\n");
		printf("1.Nhap vao so phan tu va phan tu\n");
		printf("2.Hien thi mang\n");
		printf("3.Tinh do dai mang\n");
		printf("4.Tong cac phan tu trong mang\n");
		printf("5.Phan tu lon nhat\n");
		printf("6.Thoat\n");
		printf("Lua chon: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Nhap so phan tu muon nhap: ");
				scanf("%d", &n);
				printf("Nhap cac phan tu:\n");
				addArr(&arr[n], n);
				break;
			case 2:
				displayArr(&arr[n], n);
				break;
			case 3:
				printf("Do dai mang = %d\n", n);
				break;
			case 4:
				sum=0;
				sumArr(&arr[n], &n, &sum);
				printf("Tong = %d\n", sum);
				break;
			case 5:
				maxArr(&arr[n], &n, &maxValue);
				printf("Phan tu lon nhat trong mang : %d\n", maxValue);
				break;
			case 6:
				printf("Ket thuc chuong trinh\n");
				break;
			default:
				printf("Khong hop le\n");
		}

	}while(choice!=6);
	
	return 0;
}

void addArr(int *arr, int n){
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
}
void displayArr(int *arr, int n){
	for(int i=0; i<n; i++){
		printf("arr[%d]=%d\n", i, arr[i]);
	}
}
int sumArr(int *arr, int *n, int *sum){
	for(int i=0; i<*n; i++){
		*sum+=arr[i];
	}
	return *sum;
}

int maxArr(int *arr, int *n, int *maxValue){
	*maxValue = arr[0];
	for(int i=1; i<*n;  i++){
		if(arr[i]>*maxValue){
			*maxValue=arr[i];
		}
	}
	return *maxValue;
}         