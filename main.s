section .data
    str db 'hola hola hola', 0   ; La cadena terminada en null
    format_string db "%d", 0      ; Formato para printf

section .text
    global _start                 ; Definir la entrada para el enlazador
    extern _ft_strlen, printf     ; Declarar las funciones externas

_start:
    ; Prologue
    push rbp

    ; Llamar a _ft_strlen("hola hola hola")
    lea rdi, [str]               ; Cargar la dirección de la cadena en rdi (primer argumento de la función)
    call _ft_strlen              ; Llamar a la función _ft_strlen

    ; El valor retornado por _ft_strlen está en rax, que es el valor de la longitud de la cadena
    ; Llamar a printf("%d", rax)
    mov rsi, rax                 ; Copiar la longitud de la cadena en rsi (segundo argumento de printf)
    mov rdi, format_string       ; Copiar la dirección de la cadena de formato en rdi (primer argumento de printf)
    xor rax, rax                 ; Limpiar rax (no hay valores de argumentos para printf en rdx, r8, r9)
    call printf                  ; Llamar a printf

    ; Epílogo
    pop rbp
    ret
