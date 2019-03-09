SECTION .text
GLOBAL memmove

;void *memmove(void *dest, const void *src, size_t n);

;debut boucle:
; push [src]
; inc src
; jmp debut boucle

; debut reset:
; pull [dest]
; inc dest
; jmp debut reset


memmove:
   push rbp
   mov rbp, rsp
   mov rax, 0

   push r12
   push r13
   push r14
   push r15

   mov r12, 0 ;tmp rsi
   mov r13, 0 ;tmp rdi
   mov r14, 0 ;conteur n
   mov r15, 0 ; incrementeur

   cmp rdx, 0
   je end_memmove
   ;rdi = dest = “”
   ;rsi = src = “hello world!”
   ;rdx = n

push_rsi:
   cmp r14, rdx
   je reset_compteur
   mov r12b, byte[rsi + r15]
   push r12
   inc r14
   inc r15
   jmp push_rsi

reset_compteur:
    dec r15

pull_rdi:
   cmp r14, 0
   je end_memmove
   pop r13
   mov byte[rdi + r15], r13b
   dec r15
   dec r14
   jmp pull_rdi


end_memmove:
   pop r15
   pop r14
   pop r13
   pop r12
   mov rax, rdi
   leave
   ret
