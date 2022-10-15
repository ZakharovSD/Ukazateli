#include <stdio.h>

#include <malloc.h>

void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int* createArray()
{
	int* a = calloc(4, 1000000);
	for (int i = 0; i < 1000000; i++)
	{
		*(a + i) = i;
	}
	return a;
}

int** crefntTriangleMatrix(int size)
{
	int** a = calloc(size, sizeof(int*));
	int chis = 0;
	for (size_t i = 1; i < size + 1; i++)
	{
		*(a + i - 1) = calloc(i, sizeof(int));
		for (size_t j = 0; j < i; j++)
		{
			*(*(a + i - 1) + j) = chis;
			chis++;
		}
	}
	return a;
}
void vivod(int size, int** a)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			printf("%d ", *(*(a + i) + j));

		}
		printf("\n");
	}
}

void freeDouble(int size, int** a)
{
	for (size_t i = 0; i < size; i++)
	{
		free(*(a + i));
	}
	free(a);
}

void freeSingle(int* a)
{
	free(a);
}

void piramid(int* array, int size)
{
	int jumpLine = 1;
	int elem = 0;
	for (int i = 0; i < size; i++)
	{
		if (jumpLine == elem) {
			printf("\n");
			jumpLine++;
			elem = 0;
		}
		printf("%d ", array[i]);
		elem++;
	}
}
void workWDouble(void(*f[])(int, int**), int size)
{
	int** a = crefntTriangleMatrix(size);
	f[0](size, a);
	f[1](size, a);
}

int main()
{
	void (*f[2])(int, int**);
	f[0] = vivod;
	f[1] = freeDouble;
	workWDouble(f, 10);

	return 0;

}