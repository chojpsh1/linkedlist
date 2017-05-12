#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	struct _node *next;
	char name[50];
}node;

typedef struct _linkedlist{
	struct _node *head;
}linkedlist;

void create_node(linkedlist *list, char *p_name, int length);
void delete_node(linkedlist *list);
void print_out_name(linkedlist* list, int n);

int main(){
	linkedlist *list = (linkedlist *)malloc(sizeof(linkedlist));
	list->head = NULL;
	int n;
	scanf("%d", &n);
	for( int i = 0 ; i < n ; i++ ){
		char name[50] = {'\0',};
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
	}
	newNODE->next = NULL;
	if( list->head == NULL ){
		list->head = newNODE;
		list->head->next = newNODE;
	}
	else{
		newNODE->next = list->head->next;
		list->head->next = newNODE;
		list->head = newNODE;
	}
}

void print_out_name(linkedlist* list, int n){
	node *current = list->head->next;
	for( int i = 0 ; i < n ; i++){
		printf("Hello, %s!\n", current->name);
		current = current->next;
	}
}

void delete_node(linkedlist* list){
	free(list->head);
}
