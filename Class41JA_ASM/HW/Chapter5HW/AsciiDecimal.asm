TITLE Overflow           (Overflow.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc

DECIMAL_OFFSET = 5
.data
original      BYTE "Original String: ", 0
with_decimal  BYTE "With Decimal   : ", 0
decimal_one   BYTE "100123456789765", 0
decimal_two   BYTE "328762348762", 0
decimal_three BYTE "52487245", 0
buffer        BYTE(64) DUP(0)
.code
;; WriteScaled
;; edx: pointer to ASCII number string
;; ecx: length of ASCII number string
;; ebx: number of decimals to the right of decimal point
WriteScaled PROC
	push ecx
	push edx
	mov edx, OFFSET original
	call WriteString
	pop edx
	call WriteString
	call Crlf
	push edx
	mov edx, OFFSET with_decimal
	call WriteString
	pop edx
	pop ecx
	; fill buffer with decimal string
	push eax
	sub ecx, ebx
	sub ecx, 1
	mov esi, 0
	Label1:
	mov al, [edx + esi]
	mov buffer[esi], al
	inc esi
	cmp ecx, esi
	jne Label1
	mov buffer[esi], '.'
	inc esi
	
	add ecx, ebx
	add ecx, 1
	Label2:
	mov al, [edx + esi - 1]
	mov buffer[esi], al
	inc esi
	cmp ecx, esi
	jne Label2
	mov buffer[esi], 0
	
	pop eax
	; print buffer
	mov edx, OFFSET buffer
	call WriteString
	call Crlf
	call Crlf
	ret
WriteScaled ENDP
main PROC
	call Clrscr
	mov edx, OFFSET decimal_one
	mov ecx, LENGTHOF decimal_one
	mov ebx, DECIMAL_OFFSET
	call WriteScaled
	
	mov edx, OFFSET decimal_two
	mov ecx, LENGTHOF decimal_two
	mov ebx, DECIMAL_OFFSET
	call WriteScaled
	
	mov edx, OFFSET decimal_three
	mov ecx, LENGTHOF decimal_three
	mov ebx, DECIMAL_OFFSET
	call WriteScaled
	
	;call  DumpRegs  ; display registers
	exit
main ENDP
END main

