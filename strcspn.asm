SECTION .text
GLOBAL strcspn

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

;size_t strcspn(const char *s, const char *reject);
; while (s[i])
;{
;   if (strchr(reject, s[i])
;        return (i)
;   i++;
;}

strcspn:
    push rbp
    mov rbp, rsp
    mov rax, 0
    mov rcx, 0

invert_rdi_rsi:
    mov rdx, rsi
    mov rsi, rdi
    mov rdi, rdx
    mov rdx, 0
    jmp my_for_strpbrk

my_for_strpbrk:

    cmp rsi, 0
    je end

    push rdi
    push rsi
    mov rsi, [rsi]

    call strchr

    pop rsi
    pop rdi

    cmp rax, 0
    jne end

    inc rsi
    inc rdx
    jmp my_for_strpbrk

end:
    mov rax, rdx
    leave
    ret

