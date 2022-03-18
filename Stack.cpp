#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
	//Bir tane diziyi isaret etmesi için bir pointer tanimliyoruz.
	int* arr;

	//Dizinin baslangictaki boyutunu belirlemek için bir degisken tanýmliyoruz.
	int arr_size;

	//Dizinin ilk elemanini belirlemek için bir degisken tanýmliyoruz.
	int head;
};


//Yiginin en üstteki siler ve döndürür.	
int pop(node* stack)
{
	if(stack->arr == NULL || stack->head <= 0)
	{
		printf("Array is empty!");
		return -1;
	}
		
	//Eger dizinin en üstündeki elemaninin indexi, dizinin boyutunun 1/4'üne esitse dizimizin boyutunu yariya düsürecegiz.
	//Örnegin 8 elemanli bir dizimin olsun. Biz bu dizideki elemanlari çikararak 2 eleman kalacak sekilde ayarladik. head degerimiz 2 oldu ve arr_size degerimiz 8 olarak kaldi. Dizimizin içerisinde 2 eleman var fakat dizimiz hala 8 eleman yer alacak sekilde yer kapliyor. Bu dizimizin boyutunu 4'e dusurmek icin bu islemi yapicaz.
	if(stack->head <= stack->arr_size/4)
	{
		
		//Yeni bir dizi olusturuyoruz ve bu olusturdugumuz dizinin boyutu mevcut dizinin boyutunun yarisi kadar olacak.
		int* new_arr = (int*)malloc(sizeof(int) * stack->arr_size / 2);
		
		//Mevcut dizideki elemanlar kaybolmansin diye mevcut dizideki elemanlari tek tek yeni diziye atiyoruz.
		for(int i = 0; i < stack->head; i++)
		{
			new_arr[i] = stack->arr[i];
		}
		
		//Eski dizideki verileri siliyoruz ki ramda bosu bosuna yer kaplamasin.
		free(stack->arr);
		
		//Artik mevcut dizimiz boyutunu yariya düsürdügümüz yeni dizimiz oluyor.
		stack->arr = new_arr;
		
		//Dizinin boyutunu yariya dusuruyoruz
		stack->arr_size /= 2;
	}
	
	return stack->arr[--stack->head];
}

//Yiginin en üstüne a degerini ekler.
void push(node* stack, int a)
{
	if(stack->arr == NULL)
	{
		stack->arr = (int*)malloc(sizeof(int) * 2);
	}
	
	//Eger dizimizin kapasitesi dolduysa dizi boyutunu 2 katina cikarmamizi saglayacak kodlar.
	if(stack->head >= stack->arr_size)
	{
		
		//Yeni bir dizi olusturuyoruz fakat bu olusturdugumuz dizinin boyutu mevcut dizinin boyutunun iki kati olacak.
		int* new_arr = (int*)malloc(sizeof(int) * stack->arr_size * 2);
		
		//Mevcut dizideki elemanlar kaybolmansin diye mevcut dizideki elemanlari tek tek yeni diziye atiyoruz.
		for(int i = 0; i < stack->head; i++)
		{
			new_arr[i] = stack->arr[i];
		}
		
		//Eski dizideki verileri siliyoruz ki ramda bosu bosuna yer kaplamasin.
		free(stack->arr);
		
		//Artik mevcut dizimiz boyutunu iki katina cikardigimiz yeni dizimiz oluyor.
		stack->arr = new_arr;
		
		//Dizinin boyutunu iki katina cikariyoruz.
		stack->arr_size *= 2;
	}
	
	stack->arr[stack->head++] = a;
}

//Yiginin icindekileri ilk koyulandan son koyulana kadar ekrana yazdirir.
void StackList(node* stack)
{
	printf("\nSize: %d", stack->arr_size);
	for(int i = 0; i < stack->head; i++)
	{
		printf("\nDeger: %d", stack->arr[i]);
	}
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	node* list = new node;
	list->arr = NULL;
	list->arr_size = 2;
	list->head = 0;
	
	StackList(list);
	
	printf("\n\n-----------------------------------------\n\n");
	
	push(list, 10);
	push(list, 20);
	push(list, 30);
	push(list, 40);
	push(list, 50);
	//push(60);
	//push(70);
	//push(80);
	StackList(list);
	
	printf("\n\n-----------------------------------------\n\n");
	
	printf("Popped: %d", pop(list));
	printf("\nPopped: %d", pop(list));
	printf("\nPopped: %d", pop(list));
	printf("\nPopped: %d", pop(list));
	StackList(list);
	
	printf("\n\n-----------------------------------------\n\n");
	
	push(list, 10);
	push(list, 20);
	push(list, 30);
	push(list, 40);
	push(list, 50);
	push(list, 60);
	push(list, 70);
	push(list, 80);
	push(list, 90);
	StackList(list);
}







