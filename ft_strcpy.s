section .text
global ft_strcpy

ft_strcpy:
	xor rbx, rbx					; i = 0
	xor rax, rax                    ; Limpiar RAX
	.loop:
		cmp byte [rsi + rbx], 0
		je .done
		mov al, byte [rsi + rbx]
		mov byte [rdi + rbx], al
		inc rbx
		jmp .loop
	.done:
		mov byte [rdi + rbx], 0
    	mov rax, rdi           			; Cargar la dirección relativa de 'string' en RAX
    	ret                             ; Retornar
