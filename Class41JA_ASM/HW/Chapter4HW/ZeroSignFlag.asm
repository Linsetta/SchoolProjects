TITLE ZeroSignFlag       (ZeroSignFlag .asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc
.code
main PROC
	mov   eax, 1h            ; EAX = 000000001h, ZR = 0
	sub   eax, 1h            ; EAX = 000000000h, ZR = 1, PL = 0
	call  DumpRegs  ; display registers
	sub   eax, 1h            ; EAX = 0FFFFFFFFh, ZR = 0, PL = 1
	call  DumpRegs  ; display registers
	exit
main ENDP
END main

