/* Writes "Hello, World" to the console using only system calls.
*  Runs on 64-bit Linux only (x86-64 ABI).
*  To assemble and run:
*    gcc -nostdlib -nostdinc -static -O2 sys64hello.c -o sys64hello
*/

//#include <stdint.h>
//#include <unistd.h>

static inline long long syscall3(long long syscallnum, long long arg0, long long arg1, long long arg2)
{
  register long long syscallnum_ __asm__("eax");
  register long long arg0_ __asm__("edi");
  register long long arg1_ __asm__("rsi");
  register long long arg2_ __asm__("edx");
  syscallnum_ = syscallnum;
  arg0_ = arg0;
  arg1_ = arg1;
  arg2_ = arg2;
  asm volatile
    (
        "syscall"
        : "+r"(syscallnum_)
        : "r"(arg0_), "r"(arg1_), "r"(arg2_)
        : "%rcx", "%r11", "memory"
    );
  return syscallnum_;
}

static inline long long syscall1(long long syscallnum, long long arg0)
{
  register long long syscallnum_ __asm__("eax");
  register long long arg0_ __asm__("edi");
  syscallnum_ = syscallnum;
  arg0_ = arg0;
  asm volatile
    (
        "syscall"
        : "+r"(syscallnum_)
        : "r"(arg0_)
        : "%rcx", "%r11", "memory"
    );
  return syscallnum_;
}


int write(int fd, const void *buf, int count) {
    return syscall3(1, fd, (long long)buf, count);
}

int exit0(int status) {
    return syscall1(60, status);
}



void _start()
{
    const char hello[] = "Hello World!\n";

    write(1, hello, sizeof(hello));
    exit0(0);
}
