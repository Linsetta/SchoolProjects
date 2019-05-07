TITLE Add and Subtract           (AddSub.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc
.data
	myByte  BYTE  3h    ; myByte = 3h
	mySByte SBYTE 5h    ; mySByte = 5h
	myWord  WORD  65000         ; myWord
	mySword SWORD 30000         ; mySword 
	myDword DWORD 10000000h     ; myDword 
	mySDword SDWORD -1300000000 ; mySDword 
	myFword FWORD 15h           ; myDword
	myQword QWORD 1000000000000000h     ; myDword 
	myTByte TBYTE 1900000000000000000h  ; myTByte
	myReal4 REAL4 -1.0   ; myReal4 
	myReal8 REAL8 2.0E   ; myReal8 
	myReal10 REAL10 4.0E ; myReal10 
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

