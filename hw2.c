/****************************************************************************
 * +++hw2.c+++|
 * ___________|
 *
 * Author: Sean Frischmann
 * Class: Cse 305
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Type{
	int type;
	union{
		int number;
		int boolean;
		int error;
		char* string;
		char* name;
		int primitive;
	}value;
};

bool IsPrimitive(char **a){
	int start = 1;
	switch (start){
		case 1:
			if(a == "add"){
				return true;
			}
		case 2:
			if(a == "div"){
				return true;
			}
		case 3:
			if(a == "mul"){
				return true;
			}
		case 4:
			if(a == "sub"){
				return true;
			}
		case 5:
			if(a == "rem"){
				return true;
			}
		case 6:
			if(a == "neg"){
				return true;
			}
		default:
			{
				return false;
			}
	}
}

