SECTION .text
GLOBAL strncmp

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
