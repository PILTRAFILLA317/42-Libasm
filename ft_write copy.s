section .text
extern __errno_location
global ft_write

ft_write:
	mov rax, 1
	syscall
	test rax, rax
	jz .null_error
	ret
	.null_error:
		neg		rax
		mov		rdx, rax
		call	__errno_location	WRT ..plt
		mov		[rax], rdx
		mov		rax, -1
		ret                 ; Retorna con error
