TITLE College_Reg    (College_Reg.asm)

INCLUDE Irvine32.inc

.data
prompt_grade_average       BYTE "Please enter your grade average, student: ", 0
confirm_grade_average      BYTE "Your grade average is ", 0
prompt_credits             BYTE "Please enter the number of credits that you have received, student: ", 0
confirm_credits            BYTE "The credits you have received is ", 0
explain_credits_too_low    BYTE "Your credits are too low, student.  The registrar says, 'The student cannot register.'", 0
explain_credits_too_high   BYTE "Your credits are too high, student.  The registrar says, 'The student cannot register.'", 0
explain_credits_just_right BYTE "Your credits are just right, student.  The registrar says, 'The student can register.'", 0

.code

main PROC
	call Clrscr
	call Randomize

	L1:
		mov edx, OFFSET prompt_grade_average
		call WriteString
		call ReadInt
		jno goodGradeAverageInput
	jmp L1
	
	goodGradeAverageInput:
		
		mov edx, OFFSET confirm_grade_average
		call WriteString
		call WriteInt
		call Crlf

	L2:
		mov edx, OFFSET prompt_credits
		call WriteString
		call ReadInt
		jno goodCreditsRead
	jmp L2
	goodCreditsRead:
		cmp eax, 0
	jle tooLowCredits
		cmp eax, 31
	jge tooHighCredits
	jmp justRightCredits

	tooLowCredits:
		mov edx, OFFSET explain_credits_too_low
		call WriteString
		call Crlf
	jmp L2
	tooHighCredits:
		mov edx, OFFSET explain_credits_too_high
		call WriteString
		call Crlf
	jmp L2
	justRightCredits:
		mov edx, OFFSET explain_credits_just_right
		call WriteString
		call Crlf
		
		mov edx, OFFSET confirm_credits
		call WriteString
		call WriteInt
		call Crlf

	call Crlf
	exit
main ENDP
END main

