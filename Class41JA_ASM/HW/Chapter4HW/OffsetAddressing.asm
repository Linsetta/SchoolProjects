TITLE Add and Subtract           (AddSub.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc
.data
	; myMessage1 BYTE myMessageDefinition
	Uarray WORD 1000h, 2000h, 3000h, 4000h
	Sarray SWORD -1,-2,-3,-4
.code
main PROC
	mov   eax, 0h
	mov   ebx, 0h
	mov   ecx, 0h
	mov   edx, 0h
	mov   esi, OFFSET Uarray + 0  ; 
	mov   ax, [esi]              ; EAX = 000001000h
	mov   esi, OFFSET Uarray + 2  ; 
	mov   bx, [esi]              ; EBX = 000002000h
	mov   esi, OFFSET Uarray + 4  ; 
	mov   cx, [esi]              ; ECX = 000003000h
	mov   esi, OFFSET Uarray + 6  ; 
	mov   dx, [esi]              ; EDX = 000004000h
	call  DumpRegs           ; display registers
	mov   eax, 0ffffffffh
	mov   ebx, 0ffffffffh
	mov   ecx, 0ffffffffh
	mov   edx, 0ffffffffh
	mov   esi, OFFSET Sarray + 0  ; 
	mov   ax, [esi]              ; EAX = 0h
	mov   esi, OFFSET Sarray + 2  ; 
	mov   bx, [esi]              ; EBX = 0h
	mov   esi, OFFSET Sarray + 4  ; 
	mov   cx, [esi]              ; ECX = 0h
	mov   esi, OFFSET Sarray + 6  ; 
	mov   dx, [esi]              ; EDX = 0h
	call  DumpRegs           ; display registers
	exit
main ENDP
END main

