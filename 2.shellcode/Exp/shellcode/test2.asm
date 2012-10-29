	SECTION .text
	global _start

_start:
	jmp	callback
dowork:
	pop 	esi
	push	0
	push	esi

	mov	edx,0
	mov	ecx,esp
	mov	ebx,esi
	mov	eax,0xb
	int	0x80

	mov	ebx,0
	mov	eax,1
	int	0x80

callback:
	call	dowork
	db "/bin/sh",0


