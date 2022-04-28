#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodetype{
int coef;
int power;
struct nodetype *next;
}node;
void readPolynomial(node **p);
void addPolynomial(node *ptr1,node *ptr2,node **ptr3);
void addNode(node **ptr,int coef,int powe);
void printPolynomial(node *);

 void main(){
 node *poly1,*poly2, *poly3;
 int choice, element,after,before;
 poly1=poly2=poly3=NULL;
 clrscr();
 printf("\nProgram to add two polynomial");
 printf("\nenter first polynomial");
 readPolynomial(&poly1);
 printf("\nenter secod polynomial");
 readPolynomial(&poly2);
 addPolynomial(poly1,poly2,&poly3);
 printf("\nsum of polynomials");
 printPolynomial(poly1);
 printf("\nand\n");
 printPolynomial(poly2);
 printf("\nis\n");
 printPolynomial(poly3);
 getch();
 }

 void addNode(node **ptr,int coef,int power)
 {
 node *tempPtr;
 tempPtr=(node *)malloc(sizeof(node));
 tempPtr-> coef= coef;
 tempPtr -> power = power;
 if(*ptr == NULL){
 tempPtr -> next =NULL;
 *ptr = tempPtr;
 }
 else {
 tempPtr -> next =*ptr;
 *ptr = tempPtr;
 }
}

void readPolynomial(node **p)
{
 int coeficient,power;
 printf("\enter the terms in ascending order of power");
 while(1){
  printf("\n enter the degree of x: ");
  scanf("%d",&power);
  printf("enter its coefficient:");
  scanf("%d",&coeficient);
  addNode(p,coeficient,power);
  printf("\n Any More Tearm(y/n)? :");

  if(toUpper(getch())=='Y')
    break;
  }
}

void printPolynomial(node *ptr)
{
 if(ptr!= NULL)
    printf("%dx^%d",ptr->coef,ptr->power);
 for(ptr = ptr->next;ptr!=NULL;ptr=ptr->next)
 {
  if(ptr->coef>0)
    printf(" + ");
  if(ptr->power == 0)
    printf("%d",ptr->coef);
  else if(ptr->power == 1)
    printf("%dx", ptr->coef);
  else
    printf("%dx^%d",ptr->coef,ptr->power);

  }
}

void addPolynomial(node *ptr1,node *ptr2,node **ptr3)
{
  int powe;
  float coef;
  while((ptr1!=NULL) && (ptr2!=NULL))
  {
    if(ptr1->power > ptr2->power)
    {
     coef = ptr1->coef;
     powe = ptr1->power;
     ptr1=ptr1->next;
    }
    else if(ptr1->power < ptr2->power)
    {
     coef= ptr2->coef;
     powe = ptr2->power;
     ptr2=ptr2->next;
    }
    else{
     coef=ptr1->coef+ ptr2->coef;
     powe=ptr1->power;
     ptr1=ptr1->next;
     ptr2=ptr2->next;
    }
  if(coef!=0)
    addNode(ptr3,coef,powe);
    }
  if(ptr1==NULL)
  {
  for( ;ptr2!=NULL;ptr2=ptr2->next)
    addNode(ptr3,ptr2->coef,ptr2->power);
  }
  else if(ptr2==NULL)
  {
    for( ;ptr1!=NULL;ptr1=ptr1->next)
      addNode(ptr3,ptr1->coef,ptr1->power);
    }
}