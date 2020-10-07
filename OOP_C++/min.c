#include<stdio.h>
#include<math.h>

int main()
{
	int a[100]; // khai bao mang a
	int n, i; // so phan tu cua mang a
	int min = 1000000; 
	
	printf("Nhap vao so phan tu cua mang: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	
	for (i = 0; i < n; i++) {
		if (a[i] % 2 == 0 && a[i] < min) {
			min = a[i];
		}
	}
	
	printf("MIN = %d", min);
}

