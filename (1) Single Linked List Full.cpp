#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human{
	//menampung integer umur
	int age;
	//menampung nama manusia
	char name[30];
	//menampung alamat dari data selanjutnya
	human *next;
}*head, *tail, *current;
//head adalah pointer yang menyimpan alamat data pertama
//tail adalah pointer yang menyimpan alamat data terakhir
//current adalah pointer yang digunakan sebagai temporary variabel

void pushHead(int age, char name[]){
	//alokasi memory untuk data baru
	current = (human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//kondisi tidak kosong
	else{
		current->next = head;
		head = current;
	}	
}

void pushTail(int age, char name[]){
	//alokasi memory untuk data baru
	current = (human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//kondisi tidak kosong
	else{
		tail->next = current;
		tail = current;
	}
	tail->next = NULL;
}

void pushMid(int age, char name[]){
	//alokasi memory untuk data baru
	current = (human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//jika umur data yang barusan dimasukkan lebih kecil dari umur data pertama (head)
	else if(current->age < head->age){
		pushHead(age, name);
	}
	//jika umur data yang barusan dimasukkan lebih besar dari umur data terakhir (tail)
	else if(current->age > tail->age){
		pushTail(age, name);
	}
	//push ditengah-tengah
	else{
		human *temp = head;
		//mencari posisi data yang sesuai untuk diselipkan
		while(temp->next->age < current->age){
			temp = temp->next;
		}
		current->next = temp->next;
		//mengarahkan penunjuk ke alamat data baru
		temp->next = current;
	}
}

void popHead(){
	//inisialisasi current sebagai head
	current=head;
	//jika head kosong (tidak ada data)
	if(head==NULL){
		//cetak tidak ada data
		printf("No data");
	//jika head dan tail itu sama (hanya 1 data)
	}else if(head==tail){
		//head dan tail dikosongkan
		head=tail=NULL;
		//hapus data current (head)
		free(current);
	}else{
		//set head menjadi data selanjutnya dari head
		head=head->next;
		//hapus data current (head)
		free(current);
	}
}

void popTail(){
	//jika head kosong (tidak ada data)
	if(head==NULL){
		//cetak tidak ada data
		printf("No data");
	//jika head dan tail itu sama (hanya 1 data)
	}else if(head==tail){
		//head dan tail dikosongkan
		head=tail=NULL;
		//hapus data current (head)
		free(current);
	}else{
		//buat variabel penampung baru dan assign nilai mulai dari head
		human *temp=head;
		//looping untuk mencari posisi 1 data sebelum tail
		while(temp->next!=tail){
			//temp diubah menjadi 1 data selanjutnya
			temp=temp->next;
		}
		//set data current menjadi tail
		current=tail;
		//set tail menjadi 1 data sebelum tail (hasil looping)
		tail=temp;
		//hapus data current (tail)
		free(current);
		//data setelah next dikosongkan/pointer next punya tail diberi NULL
		tail->next=NULL;
	}
}

//kita akan menghapus data sesuai dengan umurnya.
void popMid(int age){
	//jika head kosong (tidak ada data)
	if(head==NULL){
		printf("No data");
	//jika umur si head(data pertama) sama dengan data umur yang mau dihapus
	}else if(head->age==age){
		//pop head
		popHead();
	//jika umur si tail(data terakhir) sama dengan data umur yang mau dihapus
	}else if(tail->age==age){
		//pop tail
		popTail();
	}else{
		//buat variabel penampung baru dan assign nilai mulai dari head
		human *temp=head;
		//looping untuk mencari posisi 1 data sebelum tail
		while(temp->next->age!=age && temp!=tail){
			//temp diubah menjadi 1 data selanjutnya
			temp=temp->next;
		}
		//set data current menjadi data selanjutnya dari temp
		current=temp->next;
		//data selanjutnya dari temp diubah menjadi 2 data setelah temp
		temp->next=temp->next->next;
		//hapus data current
		free(current);
	}
}

//kita akan menghapus data sesuai dengan namanya.
void popMid(char name[]){
	//jika head kosong (tidak ada data)
	if(head==NULL){
		printf("No data");
	//jika nama si head(data pertama) sama dengan data nama yang mau dihapus
	}else if(strcmp(head->name,name)==0){
		//pop head
		popHead();
	//jika nama si tail(data terakhir) sama dengan data nama yang mau dihapus
	}else if(strcmp(tail->name,name)==0){
		//pop tail
		popTail();
	}else{
		//buat variabel penampung baru dan assign nilai mulai dari head
		human *temp=head;
		//looping untuk mencari posisi 1 data sebelum tail
		while(strcmp(temp->next->name,name)!=0 && temp!=tail){
			//temp diubah menjadi 1 data selanjutnya
			temp=temp->next;
		}
		//set data current menjadi data selanjutnya dari temp
		current=temp->next;
		//data selanjutnya dari temp diubah menjadi 2 data setelah temp
		temp->next=temp->next->next;
		//hapus data current
		free(current);
	}
}

void popAll(){
	while(head!=NULL){
		popHead();
	}
}

void print(){
	current = head;
	if(current==NULL)
	{
	    printf("No Data!!!");
    }else{
        while(current != NULL){
		printf("%s(%d) -> ",current->name,current->age);
		current = current->next;
	   }
    }
	
}

int main(){
	int pilihan;
	int umur;
	char nama[100];
	do{
		system("cls");
		print();
		printf("\n\nMenu\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Exit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d",&pilihan);
		
		switch(pilihan)
		{
			case 1:
			printf("Masukkan Umur: ");
			scanf("%d",&umur);fflush(stdin);
			printf("Masukkan Nama: ");
			scanf("%s",&nama);fflush(stdin);
			pushMid(umur,nama);
				break;
			case 2:
//					printf("Masukkan Nilai yang ingin di hapus: ");
//					scanf("%d",&umur);fflush(stdin);
//					popMid(umur);
					//KALAU MAU HAPUS berdasarkan INPUT nama, Di UNCOMMENT AJA, YANG DIATAS DICOMMENT
					printf("Masukkan Nama yang ingin di hapus: "); 
					scanf("%s",&nama);fflush(stdin);
					popMid(nama);					
				break;
		}
	}while(pilihan !=3);
	return 0;
}
