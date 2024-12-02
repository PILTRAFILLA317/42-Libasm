section .text
global ft_strcmp

ft_strcmp:
	xor rax, rax                    ; Limpiar RAX
	.loop:
		mov al, byte [rdi]
		mov bl, byte [rsi]
		cmp al, bl
		jne .diff
		cmp al, 0
		je .done
		inc rdi
		inc rsi
		jmp .loop
	.done:
		xor rax, rax
    	ret                             ; Retornar
	.diff:
		sub rax, rbx
		ret
		
