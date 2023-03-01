%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data

msg db "Counting +ve and -ve elements of an array",10
msglen equ $-msg
msg1 db "Positive nos. are: "
msglen1 equ $-msg1
msg2 db "Negative nos. are: "
msglen2 equ $-msg2

array db 12h,90h,87h,88h,8ah,0ah,02h
pcnt db 0
ncnt db 0
newline db 10

section .bss

dispbuff resb 2

section .txt
global _start
_start:
print msg,msglen

mov rsi,array ;source index
mov rcx,07 ;counter register

again:
		bt byte[rsi],7 ;bit test
		jnc pnxt ;jump not carry
		inc byte[ncnt] ;increment ncnt
		jmp pskip 
	pnxt: inc byte[pcnt]
	pskip: inc rsi
loop again
print msg1,msglen1
mov bl,[pcnt] ;moved to bl to convert to ascii
call disp_result ;procedure to convert to ascii
print newline,1





disp_result:

https://github.com/andipro123/Blockchain-based-E-Voting/tree/master/poll
https://www.tutorialspoint.com/compile_assembly_online.php





