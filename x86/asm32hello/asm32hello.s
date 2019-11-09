/* Writes "Hello, World" to the console using only system calls. 
*  Runs on 32/64-bit Linux (i386 ABI).
*  To assemble:
*
*  as asm32hello.s -o asm32hello.o
*  ld  asm32hello.o -o asm32hello
*/

	.text
	.global _start

_start:

# write(1, hello, sizeof(hello)) 

	mov $4, %eax		# system call 4 is write
	mov $1, %ebx		# file handle 1 is stdout
	mov $hello, %ecx		# address of string to stdout
	mov $(endhello-hello), %edx	# number of bytes
	int $0x80		# invoke OS (syscall)


# exit(0) 

	mov $1, %eax		# system call 1 is  exit
	mov $0, %ebx		# return code 0
	int $0x80		# syscall

	.data	# data section contains variables and constants
hello:	.ascii "Hello world\n"
endhello:
