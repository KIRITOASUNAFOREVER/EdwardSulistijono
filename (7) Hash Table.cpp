#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char nama[100];
	struct Node *next,*prev;
}*head[10],*tail[10],*current;

int hash(char nama[]){
	int totalAscii = 0;
	for (int i=0; i<strlen(nama); i++){
		// code logic hash
		totalAscii = totalAscii + nama[i];
	}
	// return;
	return totalAscii%10;
}

void pushHash(char nama[]){
	// code push untuk hash
	current = (Node*)malloc(sizeof(struct Node));
	
	strcpy(current->nama,nama);
	current->next=current->prev=NULL;
	int hasilHash = hash(nama);
	
	if(head[hasilHash]==NULL)
	{
		head[hasilHash] = tail[hasilHash] = current;
	}
	else
	{
		tail[hasilHash]->next=current;
		current->prev=tail[hasilHash];
		tail[hasilHash] = current; 
	}
	
}

void viewAll(){
	for (int i=0; i<10; i++){
		printf("%d: ",i);
		if (head[i] == NULL){
			printf("NULL\n");
		}
		else{
			current = head[i];
			while (current!=NULL){
				printf("%s -> ",current->nama);
				current = current->next;
			}
			puts("");
		}
		
	}
}
int main(){
	int pilih;
	char nama[255];
	do{
		
		system("CLS");
		printf("=====List Data=====\n");
		viewAll();
		printf("===================\n\n");
		printf("1. Push Hash\n");
		printf("2. Exit\n");
		printf("Choose: ");
		scanf("%d" , &pilih);fflush(stdin);
		
		switch(pilih){
			case 1:
				printf("Masukkan Nama : ");
				scanf("%[^\n]" , nama);fflush(stdin);
				pushHash(nama);
				printf("Nama Berhasil di input");getchar();
				break;
		}
	}while(pilih != 2);
	return 0;
}

