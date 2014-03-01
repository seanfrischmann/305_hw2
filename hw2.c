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

node* pop(node *head, int *number){
	node *temp = head;
	*number = head->data.value.number;
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

bool numberCheck(node *head){
	node *current = head;
	if((current == NULL) || (current->next == NULL)){
		return false;
	}
	if(current->data.type == 1){
		if(current->next->data.type == 1){
			return true;
		}else{
			return false;
		}
	}
	return false;
}

void hw2(){
	int number = 1;
	int boolean = 2;
	int error = 3;
	int primitive = 6;
	char buf[LINE_MAX];
	bool state = true;
	node *head;
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
		input[0] = 0;
		int position = 0;
		int pos_ck = 0;
		bool digit_bool = false;
		bool error_bool = false;
		size_t buf_len = strlen(buf);
		for(i=0; i< buf_len; i++){
			if((buf[i] == ' ') || (buf[i] == '@')){
				Data data_input;
				Data *current_data;
				current_data = &data_input;
				int current_number;
				int previous_number;
				if(input[0] == 0){
					error_bool = true;
				}
				if(error_bool){
					current_data->type = error;
					current_data->value.error = 1;
					head = push(head, current_data);
					display(head);
					break;
				}
				if(digit_bool){
					int temp;
					temp = strtol(input, NULL, 0);
					current_data->type = number;
					current_data->value.number = temp;
					head = push(head, current_data);
					digit_bool = false;
					pos_ck = i+1;
					position = 0;
					memset(&input[0], 0, sizeof(input));
				}else if(strncmp(input, ":true:", position) == 0){
					current_data->type = boolean;
					current_data->value.boolean = true;
					head = push(head, current_data);
					position = 0;
				}else if(strncmp(input, ":false:", position) == 0){
					current_data->type = boolean;
					current_data->value.boolean = false;
					head = push(head, current_data);
					position = 0;
				}else if(strncmp(input, "add", position) == 0){
					if(numberCheck(head)){
						head = pop(head, &current_number);
						head = pop(head, &previous_number);
						current_number = current_number + previous_number;
						current_data->type = number;
						current_data->value.number = current_number;
						head = push(head, current_data);
						position = 0;
					}else{
						error_bool = true;
					}
				}else if(strncmp(input, "sub", position) == 0){
					if(numberCheck(head)){
						head = pop(head, &current_number);
						head = pop(head, &previous_number);
						current_number = previous_number - current_number;
						current_data->type = number;
						current_data->value.number = current_number;
						head = push(head, current_data);
						position = 0;
					}else{
						error_bool = true;
					}
				}else if(strncmp(input, "mul", position) == 0){
					if(numberCheck(head)){
						head = pop(head, &current_number);
						head = pop(head, &previous_number);
						current_number = previous_number * current_number;
						current_data->type = number;
						current_data->value.number = current_number;
						head = push(head, current_data);
						position = 0;
					}else{
						error_bool = true;
					}
				}else if(strncmp(input, "div", position) == 0){
					if(numberCheck(head)){
						head = pop(head, &current_number);
						head = pop(head, &previous_number);
						if((current_number > 0) && (previous_number < 0)){
							current_number = previous_number / current_number;
							current_number--;
						}else if((current_number < 0) && (previous_number < 0)){
							current_number = previous_number / current_number;
							current_number++;
						}else{
							current_number = previous_number / current_number;
						}
						current_data->type = number;
						current_data->value.number = current_number;
						head = push(head, current_data);
						position = 0;
					}else{
						error_bool = true;
					}
				}else if(strncmp(input, "rem", position) == 0){
					if(numberCheck(head)){
						head = pop(head, &current_number);
						head = pop(head, &previous_number);
						if((current_number > 0) && (previous_number < 0)){
							int divisor = previous_number / current_number;
							divisor--;
							current_number = previous_number - (divisor*current_number);
						}else if((current_number < 0) && (previous_number < 0)){
							int divisor = previous_number / current_number;
							divisor++;
							current_number = previous_number - (divisor*current_number);
						}else{
							current_number = previous_number % current_number;
						}
						current_data->type = number;
						current_data->value.number = current_number;
						head = push(head, current_data);
						position = 0;
					}else{
						error_bool = true;
					}
				}else if(strncmp(input, "neg", position) == 0){
					if(head->data.type == 1){
						head = pop(head, &current_number);
						current_number = current_number*(-1);
						current_data->type = number;
						current_data->value.number = current_number;
						head = push(head, current_data);
						position = 0;
					}else{
						error_bool = true;
					}
				}else if(strncmp(input, "pop", position) == 0){
					if(head == NULL){
						error_bool = true;
					}else{
						int junk;
						head = pop(head, &junk);
						position = 0;
					}
				}else if(strncmp(input, "exn", position) == 0){
					if((head != NULL) && (head->next != NULL)){
						int junk;
						node *store_previous = malloc(sizeof(node));
						node *store_current = malloc(sizeof(node));
						memcpy(store_current, head, sizeof(node));
						memcpy(store_previous, head->next, sizeof(node));
						head = pop(head, &junk);
						head = pop(head, &junk);
						head = push(head, &store_current->data);
						head = push(head, &store_previous->data);
						position = 0;
					}else{
						error_bool = true;
					}
				}else{
					error_bool = true;
				}
				if (error_bool){
					current_data->type = error;
					current_data->value.error = 1;
					head = push(head, current_data);
					display(head);
					break;
				}
				if(buf[i] == '@'){
					display(head);
				}
				i++;
			}
			if(isdigit(buf[pos_ck])){
				if(isdigit(buf[i])){
					digit_bool = true;
				}else{
					error_bool = true;
				}
			}
			if(buf[pos_ck] == '-'){
				pos_ck = pos_ck + 1;
				
			}
			input[position++] = buf[i];
		}
	}
}
int main(){
	hw2();
	return 0;
}
