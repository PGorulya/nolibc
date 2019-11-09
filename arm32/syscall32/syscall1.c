/* vi: set sw=4 ts=4: */


#include <features.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/syscall.h>


static inline long syscall1(long sysnum, long a)
{

	register long _r7 __asm__("r7")=(long)(sysnum);
	register long _r0 __asm__("r0")=(long)(a);
	__asm__ __volatile__(
			"svc 0"
			: "=r"(_r0)
			: "r"(_r0), "r"(_r7)
			: "memory");

	if(_r0 >=(unsigned long) -4095) {
		long err = _r0;
		(*__errno_location())=(-err);
		_r0=(unsigned long) -1;
	}
	return (long) _r0;
}

static inline long syscall3(long sysnum, long a, long b, long c)
{
	register long _r7 __asm__("r7")=(long)(sysnum);
	register long _r2 __asm__("r2")=(long)(c);
	register long _r1 __asm__("r1")=(long)(b);
	register long _r0 __asm__("r0")=(long)(a);
	__asm__ __volatile__(
			"svc 0"
			: "=r"(_r0)
			: "r"(_r0), "r"(_r1), "r"(_r2), "r"(_r7)
			: "memory");

	if(_r0 >=(unsigned long) -4095) {
		long err = _r0;
		(*__errno_location())=(-err);
		_r0=(unsigned long) -1;
	}
	return (long) _r0;
}

int write(int fd, const void *buf, int count)
{
    return syscall3(4, fd, (long)buf, count);
}

int main(void)
{
    int val;

    val = write(1, "Hello Syscall\n", 14);

    syscall1(1, 0);
    return 0;
}