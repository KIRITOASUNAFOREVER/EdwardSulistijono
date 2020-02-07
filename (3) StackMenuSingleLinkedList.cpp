#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char nama[100];
	int usia;
	data *next;
}*head,*tail,*current;

void pushHead(char nama[],int usia)
{
	current = (data*)malloc(sizeof(struct data));
	
	strcpy(current->nama,nama);
	current->usia=usia;
	current->next=NULL;
	
	if(head==NULL)
	{
		head = tail = current;
	}
	else
	{
		current->next=head;
		head=current;
	}
}

void popHead()
{
	if(head==NULL)
	{
		printf("No Data\n");
	}
	else if(head==tail)
	{
		current = head;
		head = tail = NULL;
		free(current);
	}
	else
	{
		current = head;
		head = head->next;
		current = NULL;
		free(current);
	}
}

void view()
{
	current = head;
	
	if(current==NULL)
	{
		printf("No Data");
	}
	else
	{
		while(current != NULL)
	 {
	 	printf("%s(%d)\n",current->nama,current->usia);
	 	current = current->next;
	 }	
	}
}

int main()
{
	int pilihan;
	int usia;
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
				printf("Masukkan Usia Anda : ");
				scanf("%d",&usia);fflush(stdin);
				pushHead(nama,usia);
				break;
			case 2:
					popHead();
				break;
		}
	}while(pilihan !=3);
}
