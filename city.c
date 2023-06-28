#include <stdio.h>
# include <stdlib.h> 
#include <string.h>
typedef struct tree 
{ 
 struct tree* lchild;
 char data[20]; 
 struct tree* rchild; 
}node; 
node *tree[100];
char arr[20][100];
int m=0;
node* newnode(char *data) 
{ 
   node *temp ; 
   temp = (node*) malloc(sizeof(node));
   strcpy(temp->data, data);
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
} 

int traverse(node* root,char corp[20]){ 
   if (root==NULL)
        return 0;
   if (strcmp(root->data,corp)==0)
        return 1;

    int left= traverse(root->lchild, corp);
    int right = traverse(root->rchild, corp);
    
    if (left || right) {
        strcpy(arr[m], root->data);
        m=m+1;
        return 1;
    }

    return left||right ;
}


void create_fbinarytree() 
{ 
 int j, i=0;
j = 15; 
 j--; 
 do 
 { 
 if( j > 0 )
 {
tree[i]->lchild = tree[i * 2 + 1]; 
 j--;
 }
 if( j > 0 ) 
 {
 j--;
tree[i]->rchild = tree[i * 2 + 2]; 
 }
 i++; 
} while( j > 0); 
}

void printPostorder(node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left subtree
    printPostorder(node->lchild);
 
    // Then recur on right subtree
    printPostorder(node->rchild);
 
    // Now deal with the node
    printf("%s ", node->data);
}


void levelorder()
{ 
 int j;
for(j = 0; j < 15; j++) 
 { 
 if(tree[j] != NULL) 
 printf("%3s",tree[j]->data); 
 } 
} 



void main(){
    // Write C code here
    char city[100],suburbs1[100],suburbs2[100],t1[4][1],t2[4][1],str[100],c1[100],c2[100],arr1[20][100],arr2[20][100];
    int pincode[10],corp1,corp2,t=0,corp[10];
    printf("enter the city name\n");
    scanf("%s",&city);
    node *root;
    root=tree[t]=newnode(city);
    t++;
    printf("enter the first suburbs name\n");
    scanf("%s",&suburbs1);
    tree[t]=newnode(suburbs1);
    t++;
    printf("enter the second suburbs name\n");
    scanf("%s",&suburbs2);
    tree[t]=newnode(suburbs2);
    t++;
    printf("enter the towns in %s \n",suburbs1);
    for(int i=0;i<2;i++){
        scanf("%s",&t1[i]);
        tree[t]=newnode(t1[i]);
        t++;
        }
    printf("enter the town in %s \n",suburbs2);
    for(int i=0;i<2;i++){
        scanf("%s",&t2[i]);
        tree[t]=newnode(t2[i]);
        t++;
    }
    int k=0;
        printf("enter corporation a");
        for(int j=0;j<2;j++){
            scanf("%d",&corp[k]);
            sprintf(str, "%d", corp[k]);
            tree[t]=newnode(str);
            t++;
            k++;
        }
        printf("enter corporation in b");
        for(int j=0;j<2;j++){
            scanf("%d",&corp[k]);
            sprintf(str, "%d", corp[k]);
            tree[t]=newnode(str);
            t++;
            k++;
        }
        printf("enter corporation c");
        for(int j=0;j<2;j++){
            scanf("%d",&corp[k]);
            sprintf(str, "%d", corp[k]);
            tree[t]=newnode(str);
            t++;
            k++;
        }
        printf("enter corporation in d");
        for(int j=0;j<2;j++){
            scanf("%d",&corp[k]);
            sprintf(str, "%d", corp[k]);
            tree[t]=newnode(str);
            t++;
            k++;
        }
    create_fbinarytree();
    
    printf("give  first corporations");
    scanf("%d",&corp1);
    sprintf(c1, "%d", corp1);
    printf("give  second corporations");
    scanf("%d",&corp2);
    sprintf(c2, "%d", corp2);
    
    
    traverse(root,c1);
    for(int i=0;i<m;i++){
        strcpy(arr1[i],arr[i]);
        //printf("%s",arr1[i]);
    }
    m=0;
    traverse(root,c2);
    for(int i=0;i<m;i++){
        strcpy(arr2[i],arr[i]);
        //printf("%s",arr2[i]);
    }
    for(int i=0;i<m;i++){
        if(strcmp(arr1[i],arr2[i])==0){
            printf("%s\t",arr1[i]);
        }
    }
    
    
}


