section	.text
global	ft_strdup

ft_strdup:
    xor rax, rax
	mov rsi, rdi
	push rsi
	extern ft_strlen
	call ft_strlen
	inc rax
	mov rdi, rax
	extern malloc	; rax ahora apunta a la memoria alojada
	call malloc WRT ..plt
	test rax, rax
	jz .malloc_error
	xor rbx, rbx
	xor rcx, rcx
	pop rsi
	.loop:
		mov cl, byte [rsi + rbx]
		mov byte [rax + rbx], cl
		cmp byte [rsi + rbx], 0
		je .done
		inc rbx
		jmp .loop
	.done:
    	ret
	.malloc_error:
		mov rax, -1
    	ret