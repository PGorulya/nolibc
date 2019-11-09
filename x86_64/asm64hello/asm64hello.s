# Writes "Hello, World" to the console using only system calls. 
#  Runs on 64-bit Linux (x86-64/amd64 ABI).
#  To assemble:
#
#  as asm64hello.s -o asm64hello.o
#  ld asm64hello.o -o asm64hello
#  or:
#  gcc -c asm64hello.s -o asm64hello.o
#  ld asm64hello.o -o asm64hello


	.text
	.global _start

_start:

# write(1, hello, sizeof(hello)) 

	mov $1, %rax		# system call 1 is write
	mov $1, %rdi		# file handle 1 is stdout
	mov $hello, %rsi	# address of string to stdout
	mov $(endhello-hello), %rdx	# number of bytes in "hello"
	syscall			# invoke OS (syscall)


# exit(0) 

	mov $60, %rax		# system call 60 is  exit
	mov $0, %rdi		# return code 0
	syscall			# syscall

	.data 	# data section contains variables and constants
hello:	.ascii "Hello world\n"
endhello:
