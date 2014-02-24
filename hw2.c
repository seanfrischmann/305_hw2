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
#include <ctype.h>

enum Types{
	NUMBER,
	BOOLEAN,
	ERROR,
	STRING,
	NAME,
	PRIMITIVE
}Type;

typedef struct Data{
	int type;
	union{
		int number;
		bool boolean;
		char* error;
		char* string;
		char* name;
		char* primitive;
	}value;
};

typedef struct node{
	struct Data data;
	struct node *next;
};

struct node* push(struct node *head, struct Data *input){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = input;
	temp->next = head;
	return temp;
}

struct node* pop(struct node *head, struct Data *data){
	struct node *temp = head;
	*data = head->next;
	head = head->next;
	free(temp);
	return head;
}

void display(struct node *head){
	struct node *current;
	current = head;
	while(current != NULL){
		if(current->data->type == 1){
			printf("%d\n", current->data->value);
		}else if(current->data->type == 2){
			fputs(current->data->type ? "true" : "false", stdout);
			printf("\n");
		}else if(current->data->type == 3){
			printf(":error:\n");
		}else if(current->data->type == 6){
			printf("%s\n", current->data->value);
		}
		current = current->next;
	}
}

void hw2(){
	int number = 1;
	int boolean = 2;
	int error = 3;
	int primitive = 6;
	char buf[LINE_MAX];
	bool state = true;
	struct node *head;
	head = NULL;
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
			exit(0);
		}
		int i;
		char *input;
		bool digit = false;
		for(i=0; i< strlen(buf); i++){
			if((buf[i] == ' ') || (buf[i] == '\0')){
			}
			if(isdigit(buf[0])){
				if(isdigit(buf[i])){
					digit = true;
					input = input + buf[i];
				}else{
					struct Data *input;
					input.type = 3;
					input.value = ":error:";
					head = push(head,input);
					break;
				}
			}
		}


		if(strcmp(input,"add") == 0){
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
	}
}
int main(){
	hw2();
	return 0;
}
