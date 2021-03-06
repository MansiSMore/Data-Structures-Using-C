//Singly Cicular Linked List

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int bool;

//Structure of linkedlist
struct node
{
	int data;
	struct node *next;
};

//Creating NewNode
struct node* createNewnode(int data)
{
	struct node* newN = (struct node*)malloc(sizeof(struct node*));
	newN -> data = data;
	newN -> next = NULL;
	
	return newN;
}

//Counting elements from LinkedList
int count(struct node *first)
{
	int cnt = 0;
	struct node* temp = first;
	while(first -> next != temp)
	{
		cnt++;
		first = first -> next;
	}
	cnt++;
	return cnt;
}

//Display LinkedList
void display(struct node *first)
{
	struct node* temp = first;
	/*if(first == NULL)
	{
		printf("LinkedList is Empty...!!\n\n");
		return;
	}*/
	while(first -> next != temp)
	{
		printf("%d\t",first -> data);
		first = first -> next;
	}
	printf("%d\t",first -> data);
	printf("\n");
}

//Search element from linked list
bool Search(struct node* first, int val)
{
	struct node* temp = first;
	do
	{
		if(first-> data == val)
		{
			return TRUE;
		}
		first = first -> next;
		
	}
	while(first != temp);
	return FALSE;
}


//Inserting element in the linkedlist at first position
void insertAtFirst(struct node** first , int val)
{
	struct node* newN = createNewnode(val), *temp = (*first);
	
	//If the linked list is empty 
	if(*first == NULL)
	{
		*first = newN;
		newN -> next = (*first);
	}
	else
	{
		while(temp -> next != (*first))
			temp = temp -> next;
		
		temp -> next = newN;
		newN -> next = (*first);
		(*first) = newN;
	}
	printf("Element inserted successfully...!!\n");
}

//Inserting element in the linkedlist at Last position
void insertAtLast(struct node** first , int val)
{
	struct node* newN = createNewnode(val) , *temp = (*first);
	
	//If the linked list is empty 
	if(*first == NULL)
	{
		*first = newN;
	}
	else
	{
		while(temp -> next != (*first))
		{
			temp = temp -> next;
		}
		temp -> next = newN;
	}
	newN -> next = (*first);
	printf("Element inserted successfully...!!\n");
}

//Inserting element in the linkedlist at any position
void insertAtPos(struct node** first , int val, int pos)
{
	struct node* temp = (*first) , *newN = createNewnode(val);
	int cnt = count(*first), i = 1;
	
	//Inserting element at first position
	if(pos == 1)
	{
		insertAtFirst(first,val);
	}
	else if(pos == cnt + 1)
	{
		insertAtLast(first,val);
	}
	else if(pos > 1 && pos < cnt+1)
	{
		while(i != (pos-1))
		{
			temp = temp -> next;
			i++;
		}
		
		newN -> next = temp -> next;
		temp -> next = newN;
		printf("Element inserted successfully...!!\n");
	}
	else
	{
		printf("Wrong position...!\n\n");
	}
}


//Delete element position wise
void deleteByPosition(struct node** first, int pos)
{
	struct node* temp = (*first) , *t2 = NULL;
	int cnt = count(*first), i = 1;
	//If the linked list is empty
	if(*first == NULL)
	{
		printf("LinkedList is Empty...!\n");
	}
	else
	{
		//Delete the first element
		if(pos == 1)
		{
			while(temp -> next != (*first))
				temp = temp -> next;
			
			temp -> next = (*first) -> next;
			temp = (*first);
			(*first) = temp -> next;
			free(temp);
			printf("Node Deleted Successfully..!!\n");
		}
		//delete the last element
		else if(pos == cnt)
		{
			while(i != (pos-1))
			{
				i++;
				temp = temp -> next;
			}
			t2 = temp -> next;
			temp -> next = temp -> next -> next;
			free(t2);
			printf("Node Deleted Successfully..!!\n");
		}
		//delete the particular element
		else if(pos > 1 && pos < cnt)
		{
			while(i != (pos-1))
			{
				i++;
				temp = temp -> next;
			}
			t2 = temp -> next;
			temp -> next = t2 -> next;
			free(t2);
			printf("Node Deleted Successfully..!!\n");
		}
		else
		{
			printf("Wrong POSITION....!!\n");
		}
	}
}

/*Delete elements by their value
bool deleteByValue(struct node** first , int val)
{
	struct node* temp = (*first) ,* t2 = NULL;
	if(Search((*first),val))
	{
		if(temp -> data == val)
		{
			t2 = (*first);
			(*first) = temp -> next;
			free(t2);
		}
		else
		{
			while(temp -> next != NULL && ((temp -> next) -> data != val))
			{
				temp = temp -> next;
			}
			if(temp -> next -> data == val)
			{
				t2 = temp -> next;
				temp -> next = temp -> next -> next;
				free(t2);
			}
		}
		return TRUE;
	}
	else
		return FALSE;
}
*/

//Delete elements by their value without using Search Function - TWO POINTER APPROACH 
bool deleteByValue(struct node** first , int val)
{
	struct node* temp1 = (*first) ,*temp2 = (*first)-> next ,*t2 = NULL;
	if(temp1 -> data == val)
	{
		t2 = (*first);
		printf("%p",(*first));
		(*first) = temp1 -> next;
		free(t2);
		printf("%p",(*first));
		return TRUE;	
	}
	else
	{
		while(temp2 != (*first))
		{
			if(temp2 -> data != val)
			{
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
			else
				break;
		}
		if(temp2 != (*first))
		{
			t2 = temp1 -> next;
			temp1 -> next = temp1 -> next -> next;
			free(t2);
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}	
}


int main()
{
	int i = 0 , cnt = 0 , ele = 0 , pos = 0 , no = 0 ;
	
	struct node* head = NULL;
	
	printf("**************Singly Circular LinkedList**************\n\n");
	while(1)
	{
		printf("1.Inserting the element at FIRST position \n\n2.Inserting the element at ANY position \n\n3.Inserting the element at LAST position \n\n4.Count the elements\n\n5.Display the elements\n\n6.Delete the element POSITION wise\n\n7.Search\n\n8.Delete the element that you want to delete VALUE wise\n\n0.Exit\n");
		printf("\nEnter your choice :\n");
		scanf("%d",&no);
		
		switch(no)
		{
			case 1:
					printf("Enter the data :\n");
					scanf("%d",&ele);
					insertAtFirst(&head,ele);
					break;
					
			case 2:
					printf("Enter the data and position\n");
					scanf("%d %d",&ele,&pos);
					insertAtPos(&head,ele,pos);
					break;
					
			case 3:
					printf("Enter the data :\n");
					scanf("%d",&ele);
					insertAtLast(&head,ele);
					break;
			
			case 4:
					cnt = count(head);
					printf("Elements from the given linkedlist : %d\n",cnt);
					break;
			
			case 5:
					if(head == NULL)
						printf("LinkedList is empty..!!\n");
					else
					{
						printf("Elements from the given list are :\n");
						display(head);
					}
					break;
				
			case 6:
					printf("Enter the pos :\n");
					scanf("%d",&pos);
					deleteByPosition(&head,pos);
					break;
					
			case 7:
					printf("Enter the no that you want to search :\n");
					scanf("%d",&pos);
					if(Search(head,pos))
						printf("%d is found in the linked list...!!\n",pos);
					else
						printf("%d is not present in the linked list..!!\n",pos);
					break;
			
			case 8:
					printf("Enter the no that you want to delete :\n");
					scanf("%d",&pos);
					if(deleteByValue(&head,pos))
						printf("%d is deleted...!!\n",pos);
					else
						printf("%d is not present in the linked list..!!\n",pos);
					
					break;
					
			case 0:
					exit(0);
					
			default:
					printf("Wrong choice...!\n\n");
		}
	}
	return 0;
}
