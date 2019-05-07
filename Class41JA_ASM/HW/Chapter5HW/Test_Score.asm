TITLE Test_Score    (Test_Score.asm)

INCLUDE Irvine32.inc

.data

.code

;; CalcGrade
;;   eax: integer grade from 0 to 100
;; returns
;;   eax: letter grade 'A' to 'F'
CalcGrade PROC
	cmp eax, 59
	jle Grade_F
	cmp eax, 69
	jle Grade_D
	cmp eax, 79
	jle Grade_C
	cmp eax, 89
	jle Grade_B
	jmp Grade_A
	Grade_F:
		mov eax, 'F'
		jmp Return_Grade
	Grade_D:
		mov eax, 'D'
		jmp Return_Grade
	Grade_C:
		mov eax, 'C'
		jmp Return_Grade
	Grade_B:
		mov eax, 'B'
		jmp Return_Grade
	Grade_A:
		mov eax, 'A'
		jmp Return_Grade
	Return_Grade:
	ret
CalcGrade ENDP



main PROC
	call Clrscr
	call Randomize

	mov ecx, 10 ; counter for my loop
	L1:
		mov eax, 51
		call RandomRange  ; returns a number between 0 and eax - 1, between 0 and 50
		add eax, 50       ; convert eax to between 50 to 100
		pusha
		call WriteDec ; print one number, eax
		call Crlf
		call CalcGrade
		call WriteChar ;print one letter
		call Crlf
		popa
	loop L1   ; always dec ecx; cmp ecx, 0; jne <label> 

	call Crlf
	exit
main ENDP
END main

