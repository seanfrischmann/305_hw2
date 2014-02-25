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

typedef struct Data_storage{
	int type;
	union{
		int number;
		bool boolean;
		int error;
		int primitive;
	}value;
}Data;

char *primitives[] = {"add", "sub", "mul", "div", "rem", "neg"};

typedef struct Node{
	Data data;
	struct Node *next;
}node;

node* push(node *head, Data *input){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = *input;
	temp->next = head;
	return temp;
}

node* pop(node *head, Data *data){
	node *temp = head;
	*data = head->data;
	head = head->next;
	free(temp);
	return head;
}

void display(node *head){
	node *current;
	current = head;
	while(current != NULL){
		if(current->data.type == 1){
			printf("%d\n", current->data.value.number);
		}else if(current->data.type == 2){
			fputs(current->data.value.boolean ? ":true:" : ":false:", stdout);
			printf("\n");
		}else if(current->data.type == 3){
			printf(":error:\n");
		}else if(current->data.type == 6){
			printf("%s\n", primitives[current->data.value.primitive]);
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
	//node stack;
	node *head;
	//head = &stack;
	head = NULL;
	while(state){
		printf("repl> ");
		fgets(buf, sizeof buf, stdin);
		if(buf != NULL){
			size_t last = strlen(buf) - 1;
			if(buf[last] == '\n'){
				buf[last] = '@';
			}
		}
		if(strcmp(buf, "quit@") == 0){
			exit(0);
		}
		size_t i;
		char input[LINE_MAX];
		int position = 0;
		bool digit_bool = false;
		bool error_bool = false;
		size_t buf_len = strlen(buf);
		for(i=0; i< buf_len; i++){
			if((buf[i] == ' ') || (buf[i] == '@')){
				Data data_input;
				Data *input_data;
				input_data = &data_input;
				if(error_bool){
					input_data->type = error;
					input_data->value.error = 1;
					head = push(head, input_data);
					display(head);
					break;
				}
				if(digit_bool){
					int temp;
					temp = atoi(input);
					input_data->type = number;
					input_data->value.number = temp;
					head = push(head, input_data);
					digit_bool = false;
					position = 0;
				}else if(strncmp(input, ":true:", position) == 0){
					input_data->type = boolean;
					input_data->value.boolean = true;
					head = push(head, input_data);
					position = 0;
				}else if(strncmp(input, ":false:", position) == 0){
					input_data->type = boolean;
					input_data->value.boolean = false;
					head = push(head, input_data);
					position = 0;
				}else if(strncmp(input, "add", position) == 0){
					input_data->type = primitive;
					input_data->value.primitive = 0;
					head = push(head, input_data);
					position = 0;
				}else if(strncmp(input, "sub", position) == 0){
					input_data->type = primitive;
					input_data->value.primitive = 1;
					head = push(head, input_data);
					position = 0;
				}else if(strncmp(input, "mul", position) == 0){
					input_data->type = primitive;
					input_data->value.primitive = 2;
					head = push(head, input_data);
					position = 0;
				}else if(strncmp(input, "div", position) == 0){
					input_data->type = primitive;
					input_data->value.primitive = 3;
					head = push(head, input_data);
					position = 0;
				}else if(strncmp(input, "rem", position) == 0){
					input_data->type = primitive;
					input_data->value.primitive = 4;
					head = push(head, input_data);
					position = 0;
				}else if(strncmp(input, "neg", position) == 0){
					input_data->type = primitive;
					input_data->value.primitive = 5;
					head = push(head, input_data);
					position = 0;
				}else{
					input_data->type = error;
					input_data->value.error = 1;
					head = push(head, input_data);
					display(head);
					break;
				}
				i++;
				display(head);
			}
			if(isdigit(buf[0])){
				if(isdigit(buf[i])){
					digit_bool = true;
				}else{
					error_bool = true;
				}
			}
			input[position++] = buf[i];
		}
	}
}
int main(){
	hw2();
	return 0;
}
