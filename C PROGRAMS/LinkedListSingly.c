// https://www.thedshandbook.com/linked-lists/

#include <stdlib.h> // malloc, free, realloc // "alloc.h" 
#include <stdio.h>

struct Node
{
	int data; // info
	struct Node *next;
} *head = NULL;

//struct Node * head = NULL;
//typedef struct Node node;
//typedef struct Node * pnode;

void insertAtEnd(int value)
{
	struct Node *newNode;
	newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	
	if(head == NULL)
	{	head = newNode;
	}
	else
	{	struct Node *tempNode = head;
		while(tempNode->next) // while(tempNode->next != NULL)
		{	tempNode = tempNode->next;
		}
		
		tempNode->next = newNode;
	}
	printf("\n Node successfully inserted at the end.\n");	
}

void insertAtBeginning(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	
	if(head == NULL)
	{	newNode->next = NULL;
		head = newNode;
	}
	else
	{	newNode->next = head;
		head = newNode;
	}
	
	printf("\n Node successfully inserted at the beginning.\n");
}

void insertAtPosition(int value, int pos)
{	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	
	if(head==NULL)
	{	newNode->next = NULL;
		head = newNode;
	}	
	else
	{	int count = 0;
		struct Node *tempNode = head;
		while(count++ < pos-1)
		{	tempNode = tempNode->next;
			//count++;
		}	
		newNode->next = tempNode->next;
		tempNode->next = newNode;
	}	
		
	printf("\n Node successfully inserted at position %d", pos);
}


void deleteAtBeginning()
{	if(head == NULL )
	{	printf("\n List is Empty");
	}
	else
	{	struct Node *tempNode = head;
		printf("\n Deleting value %d from beginning .. ", head->data);
		if(head->next == NULL)
		{	head = NULL;
		}
		else
		{	head = head->next;
		}
					
		free(tempNode);
	}

}

void deleteAtEnd()
{	if(head == NULL)
	{	printf("\n List is Empty");
	}	
	else
	{	struct Node *tempNode1 = head; // NO DATA VALUE ASSIGNED, SO NO NEED TO ALLOCATE MEMORY
		struct Node *tempNode2; // NO DATA VALUE ASSIGNED, SO NO NEED TO ALLOCATE MEMORY  
		//tempNode1 = head;
		
		while(tempNode1->next != NULL)	
		{	tempNode2 = tempNode1;
			tempNode1 = tempNode1->next;
		}
		tempNode2->next = NULL;
		//printf("\n Deleting node from end ..");
		printf("\n Deleting %d from end ..", tempNode1->data);
		free(tempNode1);
	}
}

void deleteAtPosition(int pos) // HAS BUGS !!! NEED TO DEBUG !!!!
{	if(head == NULL)
	{	printf("\n List is Empty ..");
	}
	else
	{	int count = 0;
		struct Node *tempNode1 = head;
		struct Node *tempNode2;
		while(count < pos-1)
		{	tempNode1 = tempNode1->next;
		}
		tempNode2 = tempNode1->next;
		tempNode1->next = tempNode2->next;
		
		free(tempNode1);
		free(tempNode2);
	}
}

void printLinkedList()
{	struct Node *tempNode = head; // NO DATA VALUE ASSIGNED, SO NO NEED TO ALLOCATE MEMORY
	if(head == NULL)
	{	printf("\n List is empty! \n");
	}
	else
	{	printf("\n start -> ");
		while(tempNode != NULL)
		{	printf(" %d -> ", tempNode->data);
			tempNode = tempNode->next;
		}
		printf(" end\n");
	}

}

void recurPrintLinkedList(struct Node *tempNode)
{
	if(tempNode == NULL)
		return;
	else
	{	printf(" %d -> ", tempNode->data);
		recurPrintLinkedList(tempNode->next);
	}	
			
}

int main()
{	printLinkedList();

 	insertAtBeginning(5);
 	printLinkedList();
 	insertAtEnd(7);
 	printLinkedList();
 	insertAtPosition(6, 1);
 	printLinkedList();
 	
 	insertAtBeginning(4);
 	printLinkedList();
 	insertAtEnd(8);
 	printLinkedList();
 	insertAtPosition(9, 4);
 	printLinkedList();
 	
 	insertAtBeginning(3);
 	printLinkedList();
 	insertAtEnd(10);
 	printLinkedList();
 	insertAtPosition(-1, 6);
 	printLinkedList();
	
	deleteAtBeginning();
	printLinkedList();
	
	deleteAtEnd();
	printLinkedList();
	
	//deleteAtPosition(5);
	
	printf("\n start -> ");
	recurPrintLinkedList(head);
	printf(" end \n");
}


