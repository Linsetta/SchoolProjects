TITLE Summing_array     (Summing_array.asm)

INCLUDE Irvine32.inc

.data
array SDWORD 3, 4, 5, -7, 8, 2, 6, 3, 6, 7, 37
.code

;; Sum_Array
;;   edx: array
;;   edi: lowest element index to sum
;;   esi: highest element index to sum
Sum_Array PROC
	mov eax, 0
	shl edi, 2 ; edi = edi << 2, edi = edi * 4  (convert dword indices to byte indices)
	shl esi, 2 ; esi = esi << 2, esi = esi * 4  (convert dword indices to byte indices)
	add esi, 4
	mov ecx, edi
	L1:
		add eax, [edx + ecx]
		add ecx, 4           ; ecx = ecx + 4
		cmp ecx, esi
	jne L1
	ret
Sum_Array ENDP

;; Write_Array
;;   edx: array
;;   ecx: N
Write_Array PROC
	shl ecx, 2  ; ecx = ecx << 2,  ecx = ecx * 4
	mov edi, 0
	L1:
		mov eax, [edx + edi]
		call WriteInt
		call Crlf
		add edi, 4  ; edi = edi + 4	
		cmp edi, ecx
	jne L1
	call crlf
	ret
Write_Array ENDP

main PROC
	call Clrscr
	call Randomize

	pusha
	mov edx, OFFSET array   ; array
	mov ecx, LENGTHOF array ; N
	call Write_Array
	popa
	
	pusha
	mov edx, OFFSET array ; array
	mov edi, 3            ; lowest element index to sum
	mov esi, 5            ; highest element index to sum
	call Sum_Array
	call WriteInt
	call Crlf
	popa

	pusha
	mov edx, OFFSET array ; array
	mov edi, 5            ; lowest element index to sum
	mov esi, 10            ; highest element index to sum
	call Sum_Array
	call WriteInt
	call Crlf
	popa

	call Crlf
	exit
main ENDP
END main

