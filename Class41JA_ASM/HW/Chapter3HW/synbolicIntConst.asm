TITLE Add and Subtract           (AddSub.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc
	Monday = 1
	Tuesday = 2
	Wednesday = 3
	Thursday = 4
	Friday = 5
	Saturday = 6 
	Sunday = 7
.data
	daysOfWeek WORD Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
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

