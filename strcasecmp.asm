SECTION .text
GLOBAL strcasecmp
;
;
;
; while(s1 != s2 && s1[i] != '\0' && s2[i] !+ '\0') {
;   if (s1[i] != s2[i]) {
;       if (s1[i] >= 'A' && s1[i] <= 'Z')
;           s1[i] += 32
;   if (s1[i] != s2[i]) {
;       if (s2[i] >= 'A' && s2[i] <= 'Z')
;           s2[i] += 32
;      i++
;}

strcasecmp:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rcx, 0
    jmp transform_str

my_for:
    cmp r8b, al
    jne end_strcasecmp
	cmp r8b, 0
    je end_strcasecmp
	cmp al, 0
	je end_strcasecmp
	add rcx, 1
	jmp transform_str

transform_str:
	mov r8b, [rsi + rcx]
    cmp r8b, 65
    jl transform_al
    cmp r8b, 90
    jle r8b_is_maj
    jmp transform_al

transform_al:
	mov al, [rdi + rcx]
    cmp al, 65
    jl my_for
    cmp al, 90
    jle al_is_maj
    jmp my_for

al_is_maj:
    add al, 32
    jmp my_for

r8b_is_maj:
    add r8b, 32
    jmp transform_al

end_strcasecmp:
	sub al, r8b
	movsx rax, al
	leave
	ret
