#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char nama[100];
	int umur;
	data *next,*prev;
}*head,*tail,*current;

void pushHead(char nama[],int umur)
{
	current = (data*)malloc(sizeof(struct data));
	
	strcpy(current->nama,nama);
	current->umur=umur;
	current->next=current->prev=NULL;
	
	if(head==NULL)
	{
		head=tail=current;
	}
	else
	{
		head->prev=current;
		current->next=head;
		head=current;
	}
}

void popTail()
{
	if(head==NULL)
	{
		printf("No Data\n");
	}
	else if(head==tail)
	{
		head=tail=NULL;
		free(current);
	}
	else
	{
		current=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(current);
	}
}

void view()
{
	current=head;
	
	if(current==NULL)
	{
		printf("No Data\n");
	}
	else
	{
		while(current!=NULL)
		{
			printf("%s(%d)->",current->nama,current->umur);
			current=current->next;
		}
	}
}int main()
{
	int choose,umur;
	char nama[100];
	
	do{
		system("cls");
		printf("Queue Menu Double Linked List\n");
		view();printf("\n");
		printf("1. Push Data\n");
		printf("2. Pop Data\n");
		printf("3. Exit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d",&choose);fflush(stdin);
		
		switch(choose)
		{
			case 1:
				printf("Masukkan Nama Anda : ");
				scanf("%[^\n]",nama);fflush(stdin);
				printf("Masukkan umur anda : ");
				scanf("%d",&umur);fflush(stdin);
				pushHead(nama,umur);
				break;
			case 2:
					popTail();
				break;
		}
	}while(choose!=3);
}
