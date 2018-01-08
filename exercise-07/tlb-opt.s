	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.section	__TEXT,__literal16,16byte_literals
	.p2align	4
LCPI0_0:
	.long	1127219200              ## 0x43300000
	.long	1160773632              ## 0x45300000
	.long	0                       ## 0x0
	.long	0                       ## 0x0
LCPI0_1:
	.quad	4841369599423283200     ## double 4503599627370496
	.quad	4985484787499139072     ## double 1.9342813113834067E+25
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI0_2:
	.quad	4696837146684686336     ## double 1.0E+6
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
Lcfi3:
	.cfi_offset %rbx, -48
Lcfi4:
	.cfi_offset %r12, -40
Lcfi5:
	.cfi_offset %r14, -32
Lcfi6:
	.cfi_offset %r15, -24
	leaq	L_str(%rip), %rdi
	callq	_puts
	movl	$1, %r15d
	leaq	L_.str.1(%rip), %r14
	.p2align	4, 0x90
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	$1048576, %eax          ## imm = 0x100000
	xorl	%edx, %edx
	idivl	%r15d
	movl	%eax, %ebx
	callq	_clock
	movq	%rax, %r12
	testl	%ebx, %ebx
	jle	LBB0_2
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	decl	%ebx
	incq	%rbx
	imulq	%r15, %rbx
	jmp	LBB0_4
	.p2align	4, 0x90
LBB0_2:                                 ##   in Loop: Header=BB0_1 Depth=1
	xorl	%ebx, %ebx
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	callq	_clock
	subq	%r12, %rax
	movd	%rax, %xmm0
	punpckldq	LCPI0_0(%rip), %xmm0 ## xmm0 = xmm0[0],mem[0],xmm0[1],mem[1]
	subpd	LCPI0_1(%rip), %xmm0
	haddpd	%xmm0, %xmm0
	divsd	LCPI0_2(%rip), %xmm0
	movb	$1, %al
	movq	%r14, %rdi
	movl	%r15d, %esi
	movq	%rbx, %rdx
	callq	_printf
	incq	%r15
	cmpq	$17, %r15
	jne	LBB0_1
## BB#5:
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"%d\t %.8f\t %ld\n"

	.p2align	4               ## @str
L_str:
	.asciz	"#pages\t proc\t sum"


.subsections_via_symbols
