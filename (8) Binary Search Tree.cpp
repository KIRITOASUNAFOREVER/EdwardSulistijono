#include<stdio.h>
#include<stdlib.h>

struct data{
	int number;
	data *left,*right;
}*root=NULL;

data* push(data* node,int number)
{
	if(node==NULL)
	{
		data* current=(data*)malloc(sizeof(struct data));
		current->number=number;
		current->left=current->right=NULL;
		printf("Data Berhasil Diinput");getchar();
		return current;
	}
	else if(node->number==number)
	{
		printf("Insert gagal, data sudah ada");getchar();
		return node;
	}
	else if(number < node->number)
	{
		node->left=push(node->left,number);
	}
	else if(number > node->number)
	{
		node->right = push(node->right,number);
	}
	return node;
}

void search(data **node, int number){
	//jika pointer current memiliki data
	if((*node)!=NULL){
		//cek, apakah datanya lebih kecil. Jika iya, belok ke kiri
		if(number<(*node)->number){
			search(&(*node)->left,number);
		//jika lebih besar, maka belok ke kanan
		}else if(number>(*node)->number){
			search(&(*node)->right,number);
		//jika sama dengan, maka angka ketemu
		}else{
			printf("Angka %d ditemukan dalam Data", (*node)->number);
		}
	//jika tidak ada data lagi (not found)
	}else{
		printf("Tidak Ditemukan.");
	}
}

data * minValueNode(data* node) 
{ 
    data* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

data* deleteNode(data* node, int number) 
{ 
    if (node == NULL) return node; 
    if (number < node->number) 
        node->left = deleteNode(node->left, number); 
  
    else if (number > node->number) 
        node->right = deleteNode(node->right, number); 
  
    else
    { 
        if (node->left == NULL) 
        { 
            data *temp = node->right; 
            free(node); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            data *temp = node->left; 
            free(node); 
            return temp; 
        } 
        data* temp = minValueNode(node->right); 
        node->number = temp->number; 
        node->right = deleteNode(node->right, temp->number); 
    } 
    return node; 
} 

void preOrder(data *node) 
{
	if(node==NULL)
	{
		return;
	}
	printf("%d ",node->number); 
	preOrder(node->left); 
	preOrder(node->right); 
}

void inOrder(data *node) 
{
	if(node==NULL)
	{
		return;
	}
	
	inOrder(node->left); 
	printf("%d ",node->number); 
	inOrder(node->right); 
}

void postOrder(data *node)
{
	if(node==NULL)
	{
	return;
	}
	
	postOrder(node->left); 
	postOrder(node->right); 
	printf("%d ",node->number);
}

int main()
{
	int choose;
	int number;
	
	do{
		system("cls");
		printf("PreOrder : ");
    	preOrder(root);
    	printf("\n");
    	printf("InOrder : ");
    	inOrder(root);
    	printf("\n");
    	printf("PostOrder : ");
    	postOrder(root);
    	printf("\n\n");
		printf("Binary Tree\n");
		printf("1. Push Data\n");
		printf("2. View Preorder\n");
		printf("3. View Inorder\n");
		printf("4. View Postorder\n");
		printf("5. Cari Data\n");
		printf("6. Delete Data\n");
		printf("7. Exit\n");
		printf("choose : ");
		scanf("%d",&choose);fflush(stdin);
		
		switch(choose)
		{
			case 1:
				printf("Masukkan Angka : ");
				scanf("%d",&number);fflush(stdin);
				root = push(root,number);
				
				printf("\n\n");
				break;
			case 2:
				printf("Preorder   : ");preOrder(root);printf("\n\n");	
				printf("Press Enter to Continue...");
				getchar();
				break;
			case 3:
				printf("Inorder    : ");inOrder(root);printf("\n\n");		
				printf("Press Enter to Continue...");
				getchar();
				break;
			case 4:
				printf("Postorder  : ");postOrder(root);printf("\n\n");			
				printf("Press Enter to Continue...");
				getchar();
				break;
			case 5:
			    printf("Masukkan Angka yang ingin dicari : ");
			    scanf("%d",&number);fflush(stdin);
			    search(&root,number);getchar();
			    break;
			case 6:
			    printf("Masukkan Angka yang ingin dihapus : ");
			    scanf("%d",&number);fflush(stdin);
			    deleteNode(root,number);
			    break;
		}
	}while(choose!=7);
	
}
