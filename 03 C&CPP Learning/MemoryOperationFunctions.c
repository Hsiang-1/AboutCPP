#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    int a[10];

	// void *memset(void *s, int c, size_t n);
	memset(a, 97, sizeof(a));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%c\n", a[i]);
	}
	printf("\n");


	int b[10];

	// void *memcpy(void *dest, const void *src, size_t n);
	memcpy(b, a, sizeof(a));
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", b[i]);
	}
	printf("\n");

	// void *memmove(void *dest, const void *src, size_t n);

	// int memcmp(const void *s1, const void *s2, size_t n);
	int flag = memcmp(a, b, sizeof(a));
	printf("flag = %d\n", flag);
	printf("\n");


	// heap memory
	// void *malloc(size_t size);
	// void free(void *ptr);


    return 0; 
}