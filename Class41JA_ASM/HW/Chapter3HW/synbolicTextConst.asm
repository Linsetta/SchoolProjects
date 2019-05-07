TITLE Add and Subtract           (AddSub.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc
myMessageDefinition TEXTEQU <"Hi Everybody!", 0dh, 0ah,0>
myMessage1Definition TEXTEQU <"Happy Monday!",  0dh, 0ah,0>
myMessage2Definition TEXTEQU <"Happy Tusday!",  0dh, 0ah,0>
.data
	myMessage1 BYTE myMessageDefinition
	myMessage2 BYTE myMessage1Definition
	myMessage3 BYTE myMessage2Definition
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

