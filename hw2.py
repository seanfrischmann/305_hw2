import sys

def print_list(stack):
	for i, v in enumerate(stack):
		print v

def is_digit(stack, option):
	if not stack:
		return False
	if option == 1:
		if int(stack[0]):
			return True
	else:
		if len(stack) < 2:
			return False
		if stack[0].isdigit() and stack[1].isdigit:
			return True
	return False

def hw2():
	print('\nInterpreter\n'
			'Author: Sean Frischmann\n'
			'Class: Cse 305\n')
	stack = list()
	while True:
		buf = raw_input('repl> ')
		user_input = ''
		i=0
		space_bool = False
		error_bool = False
		primitive_bool = False
		negative_bool = False
		while i < len(buf):
			if (buf[i] == ' '):
				space_bool = True
			else:
				user_input = user_input + buf[i]
			if space_bool or  i == len(buf)-1:
				temp = None
				if( user_input == 'quit'):
					sys.exit(0)
				if user_input[0] == '-':
					t = 1
					temp = ''
					while t < len(user_input):
						temp = temp + user_input[t]
						t = t+1
					if temp.isdigit():
						negative_bool = True
						user_input = temp
				if user_input.isdigit() or negative_bool:
					if negative_bool:
						user_input = -1 * int(user_input)
						negative_bool = False
					else:
						user_input = int(user_input)
					stack.insert(0,user_input)
					user_input = ''
				elif user_input == 'add':
					if is_digit(stack, 2):
						temp = stack[0] + stack[1]
						primitive_bool = True
					else:
						error_bool = True
				elif user_input == 'sub':
					if is_digit(stack, 2):
						temp = stack[1] - stack[0]
						primitive_bool = True
					else:
						error_bool = True
				elif user_input == 'div':
					if is_digit(stack, 2):
						temp = int(stack[1]) / int(stack[0])
						primitive_bool = True
					else:
						error_bool = True
				elif user_input == 'rem':
					if is_digit(stack, 2):
						temp = int(stack[1]) % int(stack[0])
						primitive_bool = True
					else:
						error_bool = True
				elif user_input == 'mul':
					if is_digit(stack, 2):
						temp = int(stack[1]) * int(stack[0])
						primitive_bool = True
					else:
						error_bool = True
				elif user_input == 'neg':
					if is_digit(stack, 1):
						temp = int(stack[0]) * int(-1)
						stack.pop(0)
						temp = str(temp)
						stack.insert(0, temp)
						user_input = ''
					else:
						error_bool = True
				elif user_input == 'pop':
					if not stack:
						error_bool = True
					else:
						stack.pop(0)
						user_input = ''
				elif user_input == 'exn':
					if (not stack[0]) or (not stack[1]):
						error_bool = True
					else:
						temp = stack[1]
						stack.pop(1)
						stack.insert(0 , temp)
						user_input = ''
				if primitive_bool:
					stack.pop(0)
					stack.pop(0)
					temp = str(temp)
					stack.insert(0, temp)
					user_input = ''
				if error_bool:
					stack.insert(0, ':error:')
					print_list(stack)
					break;
				if not space_bool:
					print_list(stack)
				space_bool = False
			i=i+1
