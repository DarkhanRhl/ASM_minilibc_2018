SECTION .text
GLOBAL memset

memset:
    push rbp
    mov rbp, rsp

    mov rax, 0
start_memset:
    cmp rdi, 0
    je empty_string
    mov rcx, 0
    jmp my_for
my_for:
    cmp rcx, rdx
    je end_memset
    mov [rdi], sil
    inc rdi
    inc rcx
    jmp my_for
empty_string:
    leave
    ret 0
end_memset:
    mov rax, rdi
    leave
    ret
