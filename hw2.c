/****************************************************************************
 * +++hw2.c+++|
 * ___________|
 *
 * Author: Sean Frischmann
 * Class: Cse 305
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

enum Types{
	NUMBER,
	BOOLEAN,
	ERROR,
	STRING,
	NAME,
	PRIMITIVE
}Type;

typedef struct node{
	Type type;
	union{
		int number;
		int boolean;
		int error;
		char* string;
		char* name;
		int primitive;
	}value;
};

typedef struct stack{
	struct node data_node;
	struct stack *next;
};

struct stack* push(struct stack *head, struct node *input){
	struct stack *temp;
	temp->data_node->type = input->type;
	temp->data_node->value = input->value;
	temp->next = head;
	head = temp;
	return head;
}

void hw2(){
	char buf[LINE_MAX];
	bool state = true;
	while(state){
		printf("repl> ");
		fgets(buf, sizeof buf, stdin);
		if(buf != NULL){
			size_t last = strlen(buf) - 1;
			if(buf[last] == '\n'){
				buf[last] = '\0';
			}
		}
		char *newline = "\n";
		printf(buf);
		printf(newline);
		if(strcmp(buf, "quit") == 0){
			exit(1);
		}
/*		if(a == "add"){
			printf("hoorah");
		}
		if(a == "div"){
			return true;
		}
		if(a == "mul"){
			return true;
		}
		if(a == "sub"){
			return true;
		}
		if(a == "rem"){
			return true;
		}
		if(a == "neg"){
			return true;
		}
*/	}
}
int main(){
	hw2();
	return 0;
}
