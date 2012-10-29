	SECTION .data
shell:	db "/bin/sh",0

	SECTION .text
	global _start

_start:

	push	0
	push	shell

	mov	edx,0
	mov	ecx,esp
	mov	ebx,shell
	mov	eax,0xb
	int	0x80

	mov	ebx,0
	mov	eax,1
	int	0x80
