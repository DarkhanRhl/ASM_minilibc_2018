#Project tech2 EPITECH MONTPELLIER 2018
# -ASM_minilibc_2018
the goal of this project is to create some functions of library C in Asm.

Utilities :

- ax : registre utilisé pour transmettre le retour de fonction.

- rsp : stack pointer -> contient l’adresse de fin de la stack (et modifié par les opérateurs push/pop).
changer la valeur de rsp modifie l’allocation de la stack.

- rbp : base pointer -> contient une adresse dans la stack qui correspond au début de la fonction
(doit être modifié par l’utilisateur).

- rbp, rbx, r12, r13, r14 et r15 : ils doivent être inchangés par les fonctions
(s’ils sont modifiés, ils doivent être sauvegardés puis remis à leur place).

- Passage d’argument : rdi, rsi, rdx, rcx, r8, r9, stack. .


- mov : permet d’assigner une valeur à une entité
- call : permet d’appeller une fonction
- syscall : ne prend pas d’argument, appelle le syscall en fonction de rax (voir la liste des syscalls)
- push / pop : permet de mettre / enlever un registre dans la stack
- add / sub : ajoute ou soustrait deux entités et met le résultats dans la troisième entité
- cmp / test : compare deux entités
- jmp : saute à une adresse mémoire (utilisé pour faire des if / while)
- ret : quitte la fonction
- and / or / xor : opérateurs binaires
