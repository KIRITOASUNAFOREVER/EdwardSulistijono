#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct pasien{
    char nama[100];
    char penyakit[30];
    char gender[15];
    int umur;
    char jenis_penyakit[15];
    int prioritas;
    pasien *next;
}*head,*tail,*current;

void tambah_pasien(char nama[],char penyakit[],char gender[],int umur,char jenis_penyakit[],int prioritas)
{
    current = (pasien*)malloc(sizeof(struct pasien));
    
    strcpy(current->nama,nama);
    current->umur = umur;
    strcpy(current->gender,gender);
    current->prioritas = prioritas;
    strcpy(current->jenis_penyakit,jenis_penyakit);
    strcpy(current->penyakit,penyakit);
    current->next = NULL;
    
    if(head==NULL)
    {
        head = tail = current;
    }
    else if(current->prioritas > head->prioritas)
    {
        current->next = head;
        head= current;
    }
    else{
        pasien *temp = head;
        while(temp->next != NULL && current->prioritas <= temp->next->prioritas){
			temp = temp->next;
		}
		current->next = temp->next;
		temp->next = current;
		current->next = temp->next->next;
    }
}

void panggil_pasien()
{
	current=head;
	if(strcmp(current->gender,"pria")==0)
	{
	    printf("Bapak %s Silahkan Masuk Ke Ruangan\n",current->nama);
    }
    else
    {
        printf("Ibu %s Silahkan Masuk Ke Ruangan\n",current->nama);
    }
	head = head ->next;
	free(current);
}

int cek_penyakit(char penyakit[30]){
	 int flag = 0;
	 if((strcmpi(penyakit , "batuk") == 0 ||strcmpi(penyakit , "demam") == 0 ||strcmpi(penyakit , "flu") == 0) 
		 ||strcmpi(penyakit , "cacar") == 0 ||strcmpi(penyakit , "campak") == 0 ||strcmpi(penyakit , "diare") == 0
		 ||strcmpi(penyakit , "hepatitis") == 0 ||strcmpi(penyakit , "kanker") == 0 ||strcmpi(penyakit , "usus buntu") == 0){
			 flag = 1;
	 }else{
		 flag = 0;
	 }

	 return flag;
 }
 
void display(){
	 int i=1;
	 current =head;
	 printf("==============================================================================\n");
	 printf("| No. | Nama                 | Gender | Umur |   Penyakit   | Jenis Penyakit |\n");
	 printf("==============================================================================\n");
	 while(current!=NULL)
	 {
		 printf("| %3d | %20s | %6s | %4d | %12s | %14s |\n",  i, current->nama, current->gender, current->umur, current->penyakit, current->jenis_penyakit);
		 i=i+1;
		 current=current->next;

	 }
	 printf("==============================================================================\n");
 }
 
int main()
{
    int choice, umur, prioritas;
    char nama[30], penyakit[30], jenis_penyakit[15], gender[15];
    
    do
	{
		system("cls");
		printf("Klinik Dr. Jonni\n");
		printf("================\n\n");
		//display
		display();
		printf("\n\n1. Registrasi pasien\n");
		printf("2. Panggil pasien\n");
		printf("3. Exit\n");
		printf(">> Masukkan pilihan: "); scanf("%d", &choice); fflush(stdin);
		switch(choice)
		{
		case 1:
			system("cls");
			do{
			printf("1. Masukkan nama [5..20]: "); 
			scanf("%[^\n]", nama); 
			fflush(stdin);
			}while((strlen(nama) < 5 || strlen(nama) > 20));
            
            do{
                printf("2. Masukkan umur [5..100]: "); 
			     scanf("%d", &umur); 
			     fflush(stdin);
            }while(umur<5 || umur >100);
            
            do{
                printf("3. Masukkan gender [pria | wanita]: "); 
			     scanf("%s", gender);
                 fflush(stdin); 
            }while(strcmpi(gender,"pria")!=0 && strcmpi(gender,"wanita")!=0);
			
			do{
			     printf("4. Masukkan penyakit: "); 
			     scanf("%[^\n]", penyakit); 
			     fflush(stdin);
			}while(cek_penyakit(penyakit) == 0);

			if(strcmpi(penyakit , "batuk") == 0 ||strcmpi(penyakit , "demam") == 0 ||strcmpi(penyakit , "flu") == 0){
				strcpy(jenis_penyakit,"ringan");
				prioritas =1;
			}else if(strcmpi(penyakit , "cacar") == 0 ||strcmpi(penyakit , "campak") == 0 ||strcmpi(penyakit , "diare") == 0){
				strcpy(jenis_penyakit,"sedang");
				prioritas = 2;
			}else{
				strcpy(jenis_penyakit,"parah");
				prioritas = 3;
			}
			tambah_pasien(nama,penyakit,gender,umur,jenis_penyakit,prioritas);
			printf("\nPasien telah teregistrasi.. ");
			getchar();
			break;
		case 2:
			system("cls");
			panggil_pasien();
			getchar();
			break;
		}
	}while(choice!=3);
	return 0;
}

