section	.text
global	ft_strlen

ft_strlen:
    xor rax, rax ; RAX a 0
    .loop:
        cmp byte [rdi + rax], 0 ; Comparar RDI (inicio de la cadena) + RAX (posicion del byte) con 0
        je .done ; Saltar a done si se cumple lo de arriba
        inc rax ; Hacer un ++ a RAX si lo de arriba no se cumple
        jmp .loop ; Volver al principio del loop
    .done:
    ret