import sys

def print_list(stack):
	for i, v in enumerate(stack):
		print v

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
		insert_bool = False
		while i < len(buf):
			if (buf[i] == ' '):
				space_bool = True
			else:
				user_input = user_input + buf[i]
			if space_bool or  i == len(buf)-1:
				if user_input == 'quit':
					sys.exit(0)
				try:
					temp = None
					if user_input[0] == '-':
						t = 1
						temp = ''
						while t < len(user_input):
							temp = temp + user_input[t]
							t = t+1
						if temp.isdigit():
							negative_bool = True
					if user_input.isdigit() or negative_bool:
						insert_bool = True
						negative_bool = False
					elif user_input == ':true:' or user_input == ':false:':
						insert_bool = True
					elif user_input == 'add':
						temp = int(stack[1]) + int(stack[0])
						primitive_bool = True
					elif user_input == 'sub':
						temp = int(stack[1]) - int(stack[0])
						primitive_bool = True
					elif user_input == 'div':
						if int(stack[1]) < 0 and int(stack[0]) < 0:
							temp = int(stack[1]) / int(stack[0])
							temp = temp + 1
						else:
							temp = int(stack[1]) / int(stack[0])
						primitive_bool = True
					elif user_input == 'rem':
						if int(stack[1]) < 0 and int(stack[0]) < 0:
							temp2 = int(stack[1]) / int(stack[0])
							temp2 = temp2 + 1
							temp = int(stack[1]) - (temp2*int(stack[0]))
						else:
							temp = int(stack[1]) % int(stack[0])
						primitive_bool = True
					elif user_input == 'mul':
						temp = int(stack[1]) * int(stack[0])
						primitive_bool = True
					elif user_input == 'neg':
						temp = int(stack[0]) * int(-1)
						stack.pop(0)
						temp = str(temp)
						stack.insert(0, temp)
						user_input = ''
					elif user_input == 'pop':
						stack.pop(0)
						user_input = ''
					elif user_input == 'exn':
						temp = stack[1]
						stack.pop(1)
						stack.insert(0 , temp)
						user_input = ''
					else:
						error_bool = True
				except:
					error_bool = True
				if primitive_bool:
					stack.pop(0)
					stack.pop(0)
					temp = str(temp)
					stack.insert(0, temp)
					user_input = ''
					primitive_bool = False
				if insert_bool:
					stack.insert(0, user_input)
					user_input = ''
					insert_bool = False
				if error_bool:
					stack.insert(0, ':error:')
					print_list(stack)
					break;
				if not space_bool:
					print_list(stack)
				space_bool = False
			i=i+1

hw2()
