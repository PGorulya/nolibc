    .text
    .global main
    .syntax unified

main:
    mov r7, 4		/* sys_write() has syscall number 4 */
    mov r0, 1		/* first param fd = stdout */
    ldr r1, =msg	/* second param buf -> load address of 'msg' */
    mov r2, (endmsg-msg)	/* lenght of 'msg' */
    svc 0			/* system call */

end:
    mov r7, 1		/* sys_exit() has syscall number 1 */
    svc 0

    .data
msg:
    .ascii  "Hello, World!\n"
endmsg:
