CarryFlag          (CarryFlag.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc

.code
main PROC
	mov   eax, 0FFFFFFFFh    ; EAX = 0FFFFFFFFh, CY = 0 its a largest number for 32 bit registers 
	add   eax, 2h            ; EAX = 000000001h, CY = 1 after adding positive number CY appear, b/c the circle overrunning again from -1.
	call  DumpRegs  ; display registers
	sub   eax, 1h            ; EAX = 000000000h, it is 0, so we do not have carry flag, but we have a zero flag for number 0. CY = 0. 
	call  DumpRegs  ; display registers
	exit
main ENDP
END main

