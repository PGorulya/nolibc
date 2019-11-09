/* Writes "Hello, World" to the console using only system calls. 
*  Runs on 64-bit Linux (i86-64 System V ABI).
*  To assemble:
*
*   gcc -nostdlib -nostdinc -O2 inasm64hello.c -o inasm64hello
*/

char *hello = "Hello world\n";

void _start()
{
/* write(1, hello, sizeof(hello)) */
    asm volatile(
	"mov $1, %rax;"		// system call 1 is write
	"mov $1, %rdi;"		// file handle 1 is stdout
	"mov hello, %rsi;"	// address of string to stdout
	"mov $12, %rdx;"	// number of bytes in "hello"
	"syscall;"		// invoke OS (syscall)
	);

/* exit(0) */
    asm volatile(
	"mov $60, %rax;"		// system call 60 is  exit
	"mov $0, %rdi;"		// return code 0
	"syscall;"		// syscall
	);
}
