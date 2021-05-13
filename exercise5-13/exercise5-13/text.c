#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
//void* mem_cpy(void* dest, const void* src, size_t count)
//{
//	assert(dest);
//	assert(src);
//	void* ret = dest;
//	while (count--)
//	{
//		*((char*)dest)++ = *((char*)src)++;
//		
//	}
//	return ret;
//}

//int main()
//{
//	int arr1[10] = { 1,2,3,4,5 };
//	int arr2[20];
//	mem_cpy(arr2,arr1,12);
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
//struct human
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct human h1 = { "xiaozuo",21 };
//	struct human h2;
//	memcpy(&h2, &h1, sizeof(h1));
//	printf("name:%s age:%d \n", h2.name, h2.age);
//	return 0;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5 };
//	memmove(arr1, arr1 + 2, 12);
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
void* mem_move(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (dest < src)    //从前向后拷贝
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else    //从后向前拷贝
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main()
{
	char str[30] = "abcdefg hijkiloveyou";
	mem_move(str, str + 12, 9);
	puts(str);
	return 0;
}
