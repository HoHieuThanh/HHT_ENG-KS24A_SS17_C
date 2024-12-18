#include <stdio.h>
#include <stdbool.h>

void inputArray(int *arr, int *n);
void displayEvenNumbers(int *arr, int n);
void displayPrimeNumbers(int *arr, int n);
void reverseArray(int *arr, int n);
void sortArray(int *arr, int n, bool ascending);
int searchElement(int *arr, int n, int target);
bool isPrime(int num);

int main() {
    int arr[100], n = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                displayEvenNumbers(arr, n);
                break;
            case 3:
                displayPrimeNumbers(arr, n);
                break;
            case 4:
                reverseArray(arr, n);
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 5: {
                int sortChoice;
                printf("\n1. Tang dan\n2. Giam dan\nLua chon: ");
                scanf("%d", &sortChoice);
                sortArray(arr, n, sortChoice == 1);
                printf("Mang sau khi sap xep: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 6: {
                int target;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &target);
                int index = searchElement(arr, n, target);
                if (index != -1) {
                    printf("Phan tu %d nam o vi tri %d\n", target, index+1);
                } else {
                    printf("Khong tim thay phan tu %d trong mang\n", target);
                }
                break;
            }
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 7);

    return 0;
}

void inputArray(int *arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    printf("Nhap tung phan tu:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayEvenNumbers(int *arr, int n) {
    printf("Cac so chan trong mang: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void displayPrimeNumbers(int *arr, int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void reverseArray(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void sortArray(int *arr, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int searchElement(int *arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
