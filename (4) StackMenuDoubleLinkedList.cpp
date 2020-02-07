#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char nama[100];
	int nilai;
	data *next,*prev;
}*head,*tail,*current;

void pushHead(char nama[],int nilai)
{
	current = (data*)malloc(sizeof(struct data));
	
	strcpy(current->nama,nama);
	current->nilai = nilai;
	current->next=current->prev=NULL;
	
	if(head==NULL)
	{
		head = tail = current;
	}
	else
	{
		current->next=head;
		head->prev=current;
		head=current;
	}
}

void popHead()
{
	if(head ==NULL)
	{
		printf("No Data\n");
	}
	else if(head == tail)
	{
		current=head;
		head = tail = NULL;
		free(current);
	}
	else
	{
		current=head;
		head = head->next;
		head->prev=NULL;
		free(current);
	}
}

void view()
{
	current = head;
	
	if(current == NULL)
	{
		printf("No Data\n");
	}
	else
	{
		while(current != NULL)
		{
			printf("%s(%d)\n",current->nama,current->nilai);
			current = current->next;		
		}
	}
}

int main()
{
	int pilihan;
	int nilai;
	char nama[100];
	
	do{
		system("cls");
		printf("Stack Menu Single Linked List\n");
		view();printf("\n");
		printf("1. Push Data\n");
		printf("2. Pop Data\n");
		printf("3. Exit\n");
		printf("Masukkan Pilihan: ");
		scanf("%d",&pilihan);fflush(stdin);
		
		switch(pilihan)
		{
			case 1:
				printf("Masukkan Nama Anda : ");
				scanf("%[^\n]",nama);fflush(stdin);
				printf("Masukkan Nilai Anda : ");
				scanf("%d",&nilai);fflush(stdin);
				pushHead(nama,nilai);
				break;
			case 2:
					popHead();
				break;
		}
	}while(pilihan !=3);
}
