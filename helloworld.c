/* It is linked list code for C language.
   Also, it's explanation of ALGOSPOT's problem(HELLOWORLD).
   ALGOSTPOT's HELLOWORLD link : https://algospot.com/judge/problem/read/HELLOWORLD
   A more detailed description is on http://chojpsh1.tistory.com/87 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	struct _node *next;	//pointer for next node
	char name[50];	//data
}node;	//declare struct node

typedef struct _linkedlist{
	struct _node *head;	//in this code, head isn't first node. a flag-like role
}linkedlist;	//declare struct linkedlist

//declare functions.
void create_node(linkedlist *list, char *p_name, int length);
void delete_node(linkedlist *list);
void print_out_name(linkedlist* list, int n);

int main(){
	linkedlist *list = (linkedlist *)malloc(sizeof(linkedlist));
	//allocate linkedlist dynamically.
	list->head = NULL;	//declare initial value of head.
	int n;	//integer for how many times to enter name.
	scanf("%d", &n);
	for( int i = 0 ; i < n ; i++ ){
		char name[50] = {'\0',};	//declare initial value.
		scanf("%s", name);
		int length = strlen(name);
		create_node(list, name,length);
	}

	print_out_name(list,n);

	delete_node(list);

	return 0;
}

void create_node(linkedlist* list, char *p_name,int length){
	node *newNODE = (node *)malloc(sizeof(node));
	
	for( int i = 0 ; i < length ; i++ ){
		newNODE->name[i] = p_name[i];
	}	//string what I enter inserts into new node's name(data).
	newNODE->next = NULL;
	if( list->head == NULL ){	//if no node exists,
		list->head = newNODE;
		list->head->next = newNODE;
	}	//the head and head's next point new node.
	else{	//else if there exist nodes at least one,
		newNODE->next = list->head->next;	//new node's next is first node
		list->head->next = newNODE;
		//the preceding node's next poit new node.
		list->head = newNODE;	//the head points new node.
	}
}

void print_out_name(linkedlist* list, int n){
	node *current = list->head->next;
	for( int i = 0 ; i < n ; i++){
		printf("Hello, %s!\n", current->name);
		current = current->next;
	}
	/* when print node's data, use 'while' with condition that until next pointer isn't NULL in usual case*/
}

void delete_node(linkedlist* list){
	free(list->head);
	//if you use malloc, you should have to free it.
}
