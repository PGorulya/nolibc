/* Writes "Hello, World" to the console using only system calls. 
*  Runs on 32-bit Linux (i386 System V ABI).
*  To assemble:
*
*   gcc -nostdlib -nostdinc -O2 inasm32hello.c -o inasm32hello
*/

char *hello = "Hello world\n";

void _start()
{
/* write(1, hello, sizeof(hello)) */
    asm volatile(
	"mov $4, %eax;"		// system call 4 is write
	"mov $1, %ebx;"		// file handle 1 is stdout
	"mov hello, %ecx;"	// address of string to stdout
	"mov $12, %edx;"	// number of bytes in "hello"
	"int $0x80;"		// invoke OS (syscall)
	);

/* exit(0) */
    asm volatile(
	"mov $1, %eax;"		// system call 1 is  exit
	"mov $0, %ebx;"		// return code 0
	"int $0x80;"		// syscall
	);
}
