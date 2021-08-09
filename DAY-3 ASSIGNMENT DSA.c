#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;
void insertion_begin();
void insertion_sl();
void insertion_end();
void deletion_begin();
void deletion_sl();
void deletion_end();
void display();
void search();

void main()
{
	int choice;
	char c;
	do
	{
		clrscr();
		printf("\t\t\t******************************\n");
		printf("\n\t\t\t\t------Menu-----\n");
		printf("\n\t\t\t******************************\n");
		printf("\n\t1.Insertion at beginning");
		printf("\n\t2.Insertion at specific location");
		printf("\n\t3.Insertion at ending");
		printf("\n\t4.Deletion at beginning");
		printf("\n\t5.Deletion at specific location");
		printf("\n\t6.Deletion at ending");
		printf("\n\t7.Display");
		printf("\n\t8.Searching");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		insertion_begin();
		break;
		case 2:
		insertion_sl();
		break;
		case 3:
		insertion_end();
		break;
		case 4:
		deletion_begin();
		break;
		case 5:
		deletion_sl();
		break;
		case 6:
		deletion_end();
		break;
		case 7:
		display();
		break;
		case 8:
		search();
		break;
		default:
			printf("\nEnter a valid choice!");
		}
		printf("\nDo you want to continue?(Y/N): ");
		scanf("%s", &c);
	} while (c == 'Y' || c == 'y');
	getch();
}

void insertion_begin()
{
	int item;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter an element:");
	scanf("%d", &item);
	ptr->data = item;
	if (head==NULL)
	{
		head=ptr;
		head->next = NULL;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

void insertion_sl()
{
	int item,loc,i;
	struct node *ptr,*temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter an element:");
	scanf("%d", &item);
	ptr->data = item;
	temp=head;
	if (head == NULL)
	{
		head=ptr;
		head->next = NULL;
	}
	else
	{
    	printf("\nEnter after which loc to be inserted:");
    	scanf("%d",&loc);
    	ptr->data=item;
    	for(i=1;i<=loc;i++)
    	{
    		temp=temp->next;
    		if(temp==NULL)
    		{
    			return;
    		}
    	}
    	ptr->next=temp->next;
    	temp->next=ptr;
	}
}

void insertion_end()
{
	int item;
	struct node *ptr,*temp;
	ptr = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter an element:");
	scanf("%d", &item);
	ptr->data = item;
	temp=head;
	if (head == NULL)
	{
        head=ptr;
		head->next = NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=NULL;
	}
}

void deletion_begin()
{
	struct node *ptr;
	if(head->next==NULL)
	{
		ptr=head;
		head=NULL;
		free(ptr);
	}
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
	}
}

void deletion_sl()
{
	struct node *ptr,*ptr1;
	int loc;
	printf("\nEnter the location at which to be deleted:");
	scanf("%d",&loc);
	if(head->next==NULL)
	{
		ptr=head;
		head=NULL;
		free(ptr);
	}
	else
	{
		ptr=head;
		for(int i=1;i<=loc;i++)
		{
			ptr1=ptr;
			ptr=ptr->next;
			if(ptr=NULL)
			return;
		}
		ptr1->next=ptr->next;
		free(ptr);
	}
}

void deletion_end()
{
	struct node *ptr,*ptr1;
	if(head->next==NULL)
	{
		ptr=head;
		head=NULL;
		free(ptr);
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=NULL;
		free(ptr);
	}
}

void display()
{
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nNothing to print");  
    }     
    else  
    {  
        printf("\nThe values in list are: \n");   
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr=ptr->next;  
        }  
    }              
}

void search()
{
	struct node *ptr;
	int item,i=1;
	printf("\nEnter an item to be searched:");
	scanf("%d",&item);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			printf("\n%d is found at position %d",item,i);
			break;
		}
		else
		printf("\n%d doesn't exist.",item);
		ptr=ptr->next;
		i++;
	}
}