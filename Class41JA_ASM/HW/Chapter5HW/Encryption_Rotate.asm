TITLE (Encryption           (Encryption.asm)
; This program adds and subtracts 16-bit integers.
INCLUDE Irvine32.inc

DECIMAL_OFFSET = 5
.data

key BYTE -2, 4, 1, 0, -3, 5, 2, -4, -4, 6
;key BYTE 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
message BYTE "Hello Bob, I'll see you at the docks at sunset with the cash."
buffer BYTE(64) DUP(0)
buffer2 BYTE(64) DUP(0)
.code

;; encrypt
;;   edx: message string
;;   ecx: message string length
;;   ebx: encrypted message output
;;   eax: encryption key
encrypt PROC
	mov esi, 0  ; (index into message)
	L1:
	
	; compute: edi = esi % 10  (index into key from index into message)
	push eax
	push edx
	push ebx
	mov edx, 0
	mov eax, esi
	mov ebx, LENGTHOF key
	div ebx      ;; eax / ebx => eax (result of division), edx <= remainder of division
	mov edi, edx ;; all we want is the remainder (edx)
	pop ebx
	pop edx
	pop eax
	
	; compute: result[esi] = message[esi] >> key[edi]  (encrypt single byte)
	push eax
	push ecx
	mov ecx, 0
	mov cl, [eax + edi]  ; cl = key[edi]     (one byte, amount to shift to right)
	mov al, [edx + esi]  ; al = message[esi] (one byte, original character)
	ror al, cl           ; al = al >> cl
	mov [ebx + esi], al  ; result[esi] = al  (one byte, encrypted message)
	pop ecx
	pop eax

	; check loop condition
	inc esi         ; esi ++
	cmp esi, ecx    ; zf = (esi == ecx), zero flag = (counter == length of message)
	jne L1          ; jump if (! zf)
	
	; set null at end of encrypted message
	mov al, 0            ; al = 0
	mov [ebx + esi], al  ; result[esi] = al

	; print encrypted output
	mov edx, ebx
	call WriteString
	call Crlf

	ret
encrypt ENDP

;; decrypt
;;   edx: message string
;;   ecx: message string length
;;   ebx: encrypted message output
;;   eax: encryption key
decrypt PROC
	mov esi, 0
	L1:
	
	; compute: edi = esi % 10
	push eax
	push edx
	push ebx
	mov edx, 0
	mov eax, esi
	mov ebx, LENGTHOF key
	div ebx
	mov edi, edx
	pop ebx
	pop edx
	pop eax
	
	; compute: al = message[esi] >> key[edi]
	push eax
	push ecx
	mov ecx, 0
	mov cl, [eax + edi]
	mov al, [edx + esi]
	rol al, cl
	mov [ebx + esi], al
	pop ecx
	pop eax

	inc esi
	cmp esi, ecx
	jne L1
	mov al, 0
	mov [ebx + esi], al

	; print encrypted output
	mov edx, ebx
	call WriteString
	call Crlf

	ret
decrypt ENDP

main PROC
	call Clrscr
	
	mov edx, OFFSET message
	mov ecx, LENGTHOF message
	mov ebx, OFFSET buffer
	mov eax, OFFSET key
	call encrypt

	mov edx, OFFSET buffer
	mov ecx, LENGTHOF message
	mov ebx, OFFSET buffer2
	mov eax, OFFSET key
	call decrypt

	call Crlf
	exit
main ENDP
END main

