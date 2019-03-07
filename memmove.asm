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
   jge reset_compteur
   mov r12b, [rsi + r15]
   push r12
   inc r14
   inc r15
   jmp push_rsi

reset_compteur:
   mov r14, 0
   mov r15, 0

pull_rdi:
   cmp r14, rdx
   jge reset_2
   pop r13
   mov [rdi + r15], r13b
   inc r15
   inc r14
   jmp pull_rdi

reset_2:
   mov r14, 0
   mov r15, 0

revert_push:
   cmp r14, rdx
   jge reset_3
   mov r13b, [rdi + r15]
   inc r15
   push r13
   inc r14
   jmp revert_push

reset_3:
   mov r14, 0
   mov r15, 0

revert_pull:
   pop r13
   mov [rdi + r15], r13b
   inc r14
   cmp r14, rdx
   jge end_memmove
   inc r15
   jmp revert_pull

end_memmove:
   mov rax, rdi
   leave
   ret
