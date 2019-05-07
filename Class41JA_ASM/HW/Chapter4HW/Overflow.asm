TITLE Overflow           (Overflow.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc
.code
main PROC
	mov   eax, 7FFFFFFFh     ; EAX = 07FFFFFFFh, OV = 0, CY = 0
	add   eax, 1h            ; EAX = 080000000h, OV = 1, CY = 0
	call  DumpRegs           ; display registers
	add   eax, 0FFFFFFFFh    ; EAX = 0FFFFFFFFh, OV = 1. CY = 1
	call  DumpRegs  ; display registers
	exit
main ENDP
END main

