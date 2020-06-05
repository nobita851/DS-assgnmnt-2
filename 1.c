#include<stdio.h>
#include<stdlib.h>
typedef struct node
{int data;
struct node*left,*right;
};
struct node* creation(struct node* temp,int a)
{
if(temp==NULL)
{
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=a;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
  else
  {if((temp->data)>a)
    {
    temp->left=creation(temp->left,a);
    }
    else
    {temp->right=creation(temp->right,a); }
  }
}
int height(struct node *temp,int a)
{ int b,c;
    if(temp==NULL)
        {return 0;}
    else
    {a++;
        b=height(temp->left,0);
        c=height(temp->right,0);
        if(b>c)
            {return a+b;}
        else
            {return a+c;}
    }
}
    int main()
{ struct node *root=NULL;
int array[6]={1,2,3,4,5,6};
int l=0;
    while(l!=6)
    {
  int i=array[l];
    root=creation(root,i);
    l++;
    }
      printf(" height of tree is %d\n",height(root,-1));
      post(root);
}
void post(struct node *temp)
{
    if(temp!=NULL)
   {post(temp->left);
    post(temp->right);
        if(((height(temp->left,0))-(height(temp->right,0)))>1)
    {    printf(" Balance Factor:%d\n",((height(temp->left,0))-(height(temp->right,0))));
        printf("%d node is imbalance, so RR rotation is done\n",temp->data);
    }
    if(((height(temp->left,0))-(height(temp->right,0)))<-1)
    {    printf("Balance Factor:%d\n",((height(temp->left,0))-(height(temp->right,0))));
        printf("%d node is imbalance, so LL rotation is done\n",temp->data);
    }
    }
}
