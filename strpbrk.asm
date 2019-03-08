SECTION .text
GLOBAL strpbrk

strchr:

    push rbp
    mov rbp, rsp

    mov rax, 0
start_strchr:
    cmp byte[rdi], 0
    je not_found_strchr
    cmp byte[rdi], sil
    je found_strchr
    add rdi, 1
    jmp start_strchr
not_found_strchr:
    cmp byte[rdi], sil
    je found_strchr
    leave
    ret 0
found_strchr:
    mov rax, rdi
    leave
    ret

;char *strpbrk(register const char *s, register const char *accept)
;{
;  while (*s != '\0')
;    if (strchr(accept, *s) == NULL)
;      s++;
;    else
;      return (char *)s;

;  return NULL;
;}

strpbrk:
    push rbp
    mov rbp, rsp

    mov rax, 0
    mov rdx, 0
    cmp rdi, 0
    je end_null
    cmp rsi, 0
    je end_null

invert_rdi_rsi:
    mov rdx, rsi
    mov rsi, rdi
    mov rdi, rdx
    jmp my_for_strpbrk

my_for_strpbrk:

    cmp byte[rsi], 0
    je end_null

    push rdi
    push rsi
    mov rsi, [rsi]

    call strchr

    pop rsi
    pop rdi

    cmp rax, 0
    jne end

    inc rsi
    jmp my_for_strpbrk

end_null:
    mov rax, 0
    leave
    ret

end:
    mov rax, rsi
    leave
    ret
