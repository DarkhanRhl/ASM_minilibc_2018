SECTION .text
GLOBAL strlen
strlen:              ; label de debut de la fonction
                       ; rdi contient le premier argument:char const *str;convention de debut de fonction
    push rbp            ; convention de debut de fonction
    mov rbp, rsp        ; convention de debut de fonction
    mov rax, 0         ; rax = 0
start_strlen:    ; label de debut de boucle (utilise par jmp)

    cmp byte[rdi], 0  ; compare le byte (char) a l’adresse de rdi avec 0 (\0) ; soit *str == 0
    je end_strlen    ; jump seulement si les valeurs comparees sont egales (Jump Equal)
    add rax, 1          ; rax = rax + 1
    add rdi, 1          ; rdi = rdi + 1 (decalage de pointeur)
    jmp start_strlen ; retourne au debut de la boucle
end_strlen:          ; label de fin de boucle (utilise par jmp)
    leave            ; convention de debut de fonction
    ret              ; quitte la fonction (la valeur de retour est toujours dans rax)
