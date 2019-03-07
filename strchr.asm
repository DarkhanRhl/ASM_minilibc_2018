SECTION .text
GLOBAL strchr

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
