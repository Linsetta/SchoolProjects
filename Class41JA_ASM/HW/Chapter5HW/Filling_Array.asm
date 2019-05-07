TITLE Filling_Array       (Filling_Array.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc

.data
buffer DWORD(64) DUP(0)
.code

;; Fill_Array
;;   edx: result, pointer to the array
;;   ecx: N
;;   edi: j
;;   esi: k
Fill_Array PROC
	shl ecx, 2  ; ecx = ecx << 2,  ecx = ecx * 4  
	L1:
		sub ecx, 4  ; ecx = ecx - 4	
		mov eax, esi  ; eax = esi,        eax = k = highest random number
		sub eax, edi  ; eax = eax - edi,  eax = k - j   = gives me a range of random numbers
		inc eax       ; eax ++,           eax = k - j + 1 = to include my top number
		call RandomRange ; always eax = random number from 0 to eax - 1
		add eax, edi  ; eax = eax + edi,  eax = eax + j,  eax = random number from j to k
		mov [edx + ecx], eax ; moves random number into results array
		cmp ecx, 0
	jne L1
	ret
Fill_Array ENDP

;; Write_Array
;;   edx: result
;;   ecx: N
Write_Array PROC
	shl ecx, 2  ; ecx = ecx << 2,  ecx = ecx * 4
	L1:
		sub ecx, 4  ; ecx = ecx - 4	
		mov eax, [edx + ecx]
		call writedec
		call crlf
		cmp ecx, 0
	jne L1
	call crlf
	ret
Write_Array ENDP

main PROC
	call Clrscr
	call Randomize

	pusha
	mov edx, OFFSET buffer ; result
	mov ecx, 10            ; N
	mov edi, 5             ; j
	mov esi, 10            ; k
	call Fill_Array
	popa

	pusha
	mov edx, OFFSET buffer ; result
	mov ecx, 10            ; N
	call Write_Array
	popa
	
	pusha
	mov edx, OFFSET buffer ; result
	mov ecx, 16            ; N
	mov edi, 500000        ; j
	mov esi, 1000000       ; k
	call Fill_Array
	popa

	pusha
	mov edx, OFFSET buffer ; result
	mov ecx, 16            ; N
	call Write_Array
	popa

	call Crlf
	exit
main ENDP
END main

