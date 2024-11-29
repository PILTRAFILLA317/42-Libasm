section .data
    string db "Hola vaca", 0         ; Cadena a procesar

section	.text
global	ft_strcpy

ft_strcpy:
	xor rax, rax
    lea rax, [string]
    ret