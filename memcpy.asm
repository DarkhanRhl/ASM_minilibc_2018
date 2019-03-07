SECTION .text
GLOBAL memcpy

memcpy:
    push rbp
    mov rbp, rsp
    mov rax, 0

start_memcpy:
    cmp rdi, 0
    je empty
    cmp rsi, 0
    je empty
    cmp rdx, 0
    je empty
    mov rcx, 0
    mov r8, 0
    jmp my_for
my_for:
    cmp rcx, rdx
    je end_memcpy
    mov r8b, [rsi + rcx]
    mov [rdi + rcx], r8b
    inc rcx
    jmp my_for
empty:
    leave
    ret 0
end_memcpy:
    mov rax, rdi
    leave
    ret
