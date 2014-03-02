import sys

def hw2():
	print('\nInterpreter\n'
			'Author: Sean Frischmann\n'
			'Class: Cse 305\n')
	while True:
		buf = raw_input('repl> ')
		str(buf)
		user_input = ''
		i=0
		while i < len(buf):
			if (buf[i] == ' '):
				if( user_input == 'quit'):
						sys.exit(0)
			user_input = user_input + buf[i]
			i=i+1


