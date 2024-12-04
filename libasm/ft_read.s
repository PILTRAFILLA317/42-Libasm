section .text
extern __errno_location
global ft_read

ft_read:
	mov rax, 0				; 0 es read
	syscall					; llama read
	test rax, rax			; da negativo si hay algun error
	js ._error				; si es negativo, salta a _error
	ret
	._error:
		neg		rax			; poner en positivo rax
		mov		rdx, rax	; pasar el valor de rax a un aux
		call	__errno_location WRT ..plt	; guardar en rax el puntero de la variable gobal errno
		mov		[rax], rdx	; escribir en la variable global el valor de rdx
		mov		rax, -1		; devolver -1 (error)
		ret