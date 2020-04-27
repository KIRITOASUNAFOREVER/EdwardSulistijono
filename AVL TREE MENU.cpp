#include<stdio.h>
#include<stdlib.h>

struct Tree{
	int key;
	int height;
	Tree *left, *right;
}*root=NULL;

int getMax (int height1, int height2){
	if (height1 > height2){
		return height1;
	}else{
		return height2;
	}
}

int getHeight(Tree *curr){
	if (curr==NULL){
		return 0;
	}else{
		return curr->height;
	}
}

int getBalanceFactor(Tree *curr){
	if (curr==NULL){
		return 0;
	}else{
		return getHeight(curr->left)-getHeight(curr->right);
	}
}

struct Tree *leftRotation(Tree *curr){
	Tree *child = curr->right;
	Tree *grandChild = child->left;
	
	child->left = curr;
	curr->right = grandChild;
	
	curr->height = getMax(getHeight(curr->left), getHeight(curr->right))+1;
	child->height = getMax(getHeight(child->left), getHeight(child->right))+1;
	
	return child;
}

struct Tree *rightRotation(Tree *curr){
	Tree *child = curr->left;
	Tree *grandChild = child->right;
	
	child->right = curr;
	curr->left = grandChild;
	
	curr->height = getMax(getHeight(curr->left), getHeight(curr->right))+1;
	child->height = getMax(getHeight(child->left), getHeight(child->right))+1;
	
	return child;
}
struct Tree *insertNode(Tree *curr, int value){
	if (curr==NULL){
		curr = (Tree *)malloc(sizeof(struct Tree));
		curr->key =  value;
		curr->height = 1;
		curr->left = curr->right = NULL;
		return curr;
	}
	else if (value < curr->key){
		curr->left = insertNode(curr->left, value);
	}
	else if (value > curr->key){
		curr->right = insertNode(curr->right, value);
	}
	curr->height = getMax(getHeight(curr->left), getHeight(curr->right))+1;
	int balanceFactor = getBalanceFactor(curr);
	
	if (balanceFactor < -1 && value > curr->right->key){// RR case
		return leftRotation(curr);
	}
	
	if (balanceFactor < -1 && value < curr->right->key){//RL Case
		curr->right = rightRotation(curr->right);
		return leftRotation(curr);
	}
	
	if (balanceFactor > 1 && value < curr->left->key){// LL Case
		return rightRotation(curr);
	}
	
	if (balanceFactor > 1 && value > curr->left->key){ // LR Case
		curr->left = leftRotation(curr->left);
		return rightRotation(curr);
	}
	return curr;
}

struct Tree *preDecessor(Tree *curr){
	curr= curr->left;
	while(curr->right){
		curr=curr->right;
	}
	
	return curr;
}
struct Tree *deleteNode(Tree *curr, int value){
	if (curr==NULL){
		return curr;
	}
	else if (value < curr->key){
		curr->left = deleteNode(curr->left, value);
	}
	else if (value > curr->key){
		curr->right = deleteNode(curr->right, value);
	}
	else{
		Tree *temp = NULL;
		if (curr->left ==NULL || curr->right==NULL){ // 1 CHILD OR NO CHILD
			if (curr->left==NULL){
				temp = curr->right;
			}
			else{
				temp = curr->left;
			}
			
			if (temp==NULL){ // NO CHILD
				temp=curr;
				curr=NULL;
			}else{ // HAVE 1 CHILD
				*curr = *temp;
			}
			free(temp);
		}
		else{ // HAVE 2 CHILD
			temp = preDecessor(curr);
			curr->key = temp->key;
			curr->left = deleteNode(curr->left, temp->key);
		}
	}
	
	if (curr==NULL){
		return curr;
	}
	
	curr->height = getMax(getHeight(curr->left), getHeight(curr->right))+1;
	int balanceFactor = getBalanceFactor(curr);
	
	if (balanceFactor >1 && getBalanceFactor(curr->left)<0){//LR Case
		curr->left = leftRotation(curr->left);
		return rightRotation(curr);
	}
	
	if (balanceFactor > 1 && getBalanceFactor(curr->left)>=0){//LL Case
		return rightRotation(curr);
	}
	
	if (balanceFactor < -1 && getBalanceFactor(curr->right)<=0){// RR Case
		return leftRotation(curr);
	}
	
	if (balanceFactor < -1 && getBalanceFactor(curr->right)>0){//RL Case
		curr->right = rightRotation(curr->right);
		return leftRotation(curr);
	}
	
	return curr;
}
void preOrder(Tree *curr){
	if(curr!=NULL){
		printf("%d ", curr->key);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(Tree *curr) 
{
    if(curr!=NULL)
    {
        inOrder(curr->left);
        printf("%d ", curr->key);
        inOrder(curr->right);
    }
}

void postOrder(Tree *curr) 
{
    if(curr!=NULL)
    {
        postOrder(curr->left);
        postOrder(curr->right);
        printf("%d ",curr->key);
    }
}

struct Tree *search(Tree **node, int value){
	//jika pointer current memiliki data
	if((*node)!=NULL){
		//cek, apakah datanya lebih kecil. Jika iya, belok ke kiri
		if(value<(*node)->key){
			search(&(*node)->left,value);
		//jika lebih besar, maka belok ke kanan
		}else if(value>(*node)->key){
			search(&(*node)->right,value);
		//jika sama dengan, maka angka ketemu
		}else{
			printf("Angka %d ditemukan dalam Data", (*node)->key);
		}
	//jika tidak ada data lagi (not found)
	}else{
		printf("Tidak Ditemukan.");
	}
}
void menu(){
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
	printf("\nMenu\n");
	printf("===========\n");
	puts("1. Insert");
	puts("2. Delete");
	puts("3. Exit");
	printf("Choose >> ");
}

int main(){
	int choose=0;
	int inputNumber;
	
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
    	printf("\nMenu\n");
    	printf("===========\n");
    	puts("1. Insert");
    	puts("2. Delete");
    	puts("3. Search");
    	puts("4. Exit");
    	printf("Choose >> ");
        scanf("%d",&choose);
        
        switch(choose)
        {
            case 1:
                printf("Menu Insert\n");
				printf("Input number: ");
				scanf("%d", &inputNumber); fflush(stdin);
				root = insertNode(root, inputNumber);
                break;
            case 2:
                printf("Menu Delete\n");
    			printf("Input Number to be Delete : ");
    			scanf("%d" , &inputNumber);fflush(stdin);
    			root = deleteNode(root , inputNumber);
                break;
            case 3:
                printf("Menu Searching\n");
                printf("Input Number to be Searched : ");
                scanf("%d",&inputNumber);fflush(stdin);
                search(&root,inputNumber);getchar();
                break;
        }
    }while(choose != 4);
	return 0;
}
