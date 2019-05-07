TITLE Add and Subtract           (AddSub.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc
.code
main PROC
	mov   ax, 5h    ; AX = 5h
	sub   ax, 1h    ; AX = 4h
	sub   ax, 2h    ; AX = 2h
	sub   ax, 3h    ; AX = -1h
	call  DumpRegs  ; display registers
	exit
main ENDP
END main

