SECTION .text
GLOBAL rindex

;char *rindex(const char *s, int c);
;   while(str[i] != '\0') {
;       if (str[i] == c)
;           tmp = str[i]
;   return tmp
;}
rindex:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rdx, 0

my_for:
    cmp byte[rdi], 0
    je end_rindex
    cmp byte[rdi], sil
    je same_char
    add rdi, 1
    jmp my_for

same_char:
    mov rdx, rdi
    inc rdi
    jmp my_for

end_rindex:
    mov rax, rdx
	leave
	ret
