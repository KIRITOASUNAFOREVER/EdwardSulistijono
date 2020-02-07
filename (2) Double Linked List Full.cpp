#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int nilai;
	char nama[30];
	data *next,*prev;
}*head,*tail,*current;

void pushMid(int nilai,char nama[])
{
	current=(data*)malloc(sizeof(struct data));
	current->nilai=nilai;
	strcpy(current->nama,nama);
	
	current->next=current->prev=NULL;
	
	if(!head)
	{
		head=tail=current;
	}
	else
	{
		if(nilai<head->nilai) //PUSH HEAD
		{
			current->next=head;
			head->prev=current;
			head=current;
		}
		else if(nilai>tail->nilai) //PUSH TAIL
		{
			current->prev=tail;
			tail->next=current;
			tail=current;
		}
		else //PUSH MID
		{
			data *temp=head;
			
			while(temp->nilai<nilai)
			{
				temp=temp->next;
			}
			current->prev=temp->prev;
			current->next=temp;
			temp->prev->next=current;
			temp->prev=current;
		}
	}
	
}

void view()
{
	current=head;
	
	if(head==NULL)
	{
		printf("No Data\n\n");
	}
	else
	{
		while(current!=NULL)
	{
		printf("%s(%d) -> ",current->nama,current->nilai);
		current=current->next;
	}
	}
}

void popMid(int nilai)
{
	current=head;
	if(head==tail)
	{
		head=tail=NULL;
		free(current);
	}
	else{
		if(nilai==head->nilai) //POP HEAD
		{
			head=head->next;
			head->prev=NULL;
			free(current);
		}
		else if(nilai==tail->nilai) //POP TAIL
		{
			current=tail;
			tail=tail->prev;
			tail->next=NULL;
			free(current);
		}
		else //POP MID
		{
			while(current->nilai!=nilai)
			{
				current=current->next;
			}
			current->prev->next=current->next;
			current->next->prev=current->prev;
			free(current);
		}
	}
}

void popMid(char nama[])
{
	current=head;
	if(head==tail)
	{
		head=tail=NULL;
		free(current);
	}
	else{
		if(strcmp(nama,head->nama)==0) //POP HEAD
		{
			head=head->next;
			head->prev=NULL;
			free(current);
		}
		else if(strcmp(nama,tail->nama)==0) //POP TAIL
		{
			current=tail;
			tail=tail->prev;
			tail->next=NULL;
			free(current);
		}
		else //POP MID
		{
			while(strcmp(current->nama,nama)!=0)
			{
				current=current->next;
			}
			current->prev->next=current->next;
			current->next->prev=current->prev;
			free(current);
		}
	}
}

int main()
{
	int pilihan;
	int nilai;
	char nama[30];
	do{
		system("cls");
		view();
		printf("\n\nMenu\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Exit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d",&pilihan);
		
		switch(pilihan)
		{
			case 1:
			printf("Masukkan Nilai: ");
			scanf("%d",&nilai);fflush(stdin);
			printf("Masukkan Nama: ");
			scanf("%s",&nama);fflush(stdin);
			pushMid(nilai,nama);
				break;
			case 2:
//					printf("Masukkan Nilai yang ingin di hapus: ");
//					scanf("%d",&nilai);fflush(stdin);
//					popMid(nilai);
					
					printf("Masukkan Nama yang ingin di hapus: ");
					scanf("%s",&nama);fflush(stdin);
					popMid(nama);					
				break;
		}
	}while(pilihan !=3);
}
