TITLE Overflow           (Overflow.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc

DECIMAL_OFFSET = 5
.data
;binary_one BYTE 0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
;binary_two BYTE 12h,11h,10h,09h,08h,07h,06h,05h,04h,03h,02h,01h
binary_one BYTE 10h,10h,10h,10h,10h,10h,10h,10h,10h,10h,10h,10h
binary_two BYTE 00h,01h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
;binary_two BYTE 01h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h,00h
buffer     BYTE(64) DUP(0)
.code

;; edx: pointer to display
;; ecx: length to display
DisplayExtended PROC
	push esi
	push eax
	mov esi, ecx
	Label1:
	sub esi, 4
	mov eax, [edx + esi];
	call WriteHex
	cmp esi, 0
	jne Label1
	pop eax
	pop esi
	ret
DisplayExtended ENDP

;; Extended_Sub
;; ebx: pointer to first binary number array
;; edx: pointer to second binary number array
;; ecx: length of binary number arrays (same for each)
Extended_Sub PROC
	; print first number (ebx)
	push edx
	push ecx
	mov edx, ebx
	mov ecx, ecx
	call DisplayExtended
	call Crlf
	pop ecx
	pop edx
	
	; print second number (edx)
	push edx
	push ecx
	mov edx, edx
	mov ecx, ecx
	call DisplayExtended
	call Crlf
	pop ecx
	pop edx
	
	push edx
	push ecx; lenght of my number . 
	
	; begin calculate buffer
	mov esi, ebx
	mov edi, edx
	mov edx, OFFSET buffer ; pointer of the result into memory
	clc ; clear the carry bit set to 0.
	Label1:
	mov al, [esi]; taking  the number ( 1 byte)  which esi point to
	sbb al, [edi]; // sub with  borrow. Al become smaller.
	mov [edx], al ; put number al into edx memory location 
	inc esi
	inc edi
	inc edx
	loop Label1 ; decrement ecx nd junp to label if ecx !=0.
	; end calculate buffer
	
	pop ecx
	pop edx

	; print result (buffer)
	push edx
	push ecx
	mov edx, OFFSET buffer
	mov ecx, ecx
	call DisplayExtended
	call Crlf
	pop ecx
	pop edx
	
	ret
Extended_Sub ENDP

main PROC
	call Clrscr
	
	mov ebx, OFFSET binary_one
	mov edx, OFFSET binary_two
	mov ecx, LENGTHOF binary_one
	call Extended_Sub
	
	call Crlf
	exit
main ENDP
END main

