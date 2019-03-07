SECTION .text
GLOBAL strstr

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

strncmp:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rcx, 0
my_for:
    cmp rdx, 0
    je end_strcmp
    sub rdx, 1
	mov r8b, [rsi + rcx]
	mov rax, [rdi + rcx]
	cmp r8b, 0
    je end_strcmp
	cmp rax, 0
	je end_strcmp
	cmp al, r8b
	jne end_strcmp
	add rcx, 1
	jmp my_for
end_strcmp:
	sub al, r8b
	movsx rax, al
	leave
	ret


;char *strstr(const char *meuledefoin, const char *aiguille);
;
;   int j = 0;
;   char *tmp = null
;
;   while (*meuledefoin != '\0') {
;       if (*meuledefoins == aiguille[j])
;           tmp = *meuledefoins;
;       while (meuledefoins[i] == aiguille[j]) {
;           *meuledefoins++
;           j++;
;           if (aiguille[j + 1] == 0)
;               return tmp
;           if (meuledefoins[i] == 0 || aiguille[j] == 0)
;               return tmp
;       }
;       j = 0
;       *meuledefoins++;
;}


strstr:
    push rbp
    mov rbp, rsp

    mov rax, 0
    mov rcx, 0
    ; rdi s1
    ; rsi s2
    mov rdx, 0 ;n
    jmp my_call_strlen

my_call_strlen:
    push rdi
    mov rdi, rsi
    call strlen
    mov rdx, rax
    pop rdi

my_for_strstr:
    cmp byte[rdi], 0
    je end_strstr_lose
    push rdi
    push rsi
    push rdx
    call strncmp
    pop rdx
    pop rsi
    pop rdi
    cmp rax, 0
    je end_strstr_win
    inc rdi
    jmp my_for_strstr

end_strstr_win:
    mov rax, rdi
	leave
	ret

end_strstr_lose:
    mov rax, 0
    leave
    ret
