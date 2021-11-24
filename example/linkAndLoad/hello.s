	.arch armv8-a
	.text
	.zerofill __DATA,__bss,__ZStL8__ioinit,1,3
	.cstring
	.align	3
lC0:
	.ascii "hello link and load\12\0"
	.text
	.align	2
	.globl _main
_main:
LFB1778:
	stp	x29, x30, [sp, -16]!
LCFI0:
	mov	x29, sp
	adrp	x0, lC0@GOTPAGE
	ldr	x1, [x0, lC0@GOTPAGEOFF];momd
	adrp	x0, __ZSt4cout@GOTPAGE
	ldr	x0, [x0, __ZSt4cout@GOTPAGEOFF];momd
	bl	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	w0, 0
	ldp	x29, x30, [sp], 16
LCFI1:
	ret
LFE1778:
	.align	2
__Z41__static_initialization_and_destruction_0ii:
LFB2276:
	stp	x29, x30, [sp, -32]!
LCFI2:
	mov	x29, sp
	str	w0, [sp, 28]
	str	w1, [sp, 24]
	ldr	w0, [sp, 28]
	cmp	w0, 1
	bne	L5
	ldr	w1, [sp, 24]
	mov	w0, 65535
	cmp	w1, w0
	bne	L5
	adrp	x0, __ZStL8__ioinit@PAGE
	add	x0, x0, __ZStL8__ioinit@PAGEOFF;momd
	bl	__ZNSt8ios_base4InitC1Ev
	adrp	x0, ___dso_handle@GOTPAGE
	ldr	x2, [x0, ___dso_handle@GOTPAGEOFF];momd
	adrp	x0, __ZStL8__ioinit@PAGE
	add	x1, x0, __ZStL8__ioinit@PAGEOFF;momd
	adrp	x0, __ZNSt8ios_base4InitD1Ev@GOTPAGE
	ldr	x0, [x0, __ZNSt8ios_base4InitD1Ev@GOTPAGEOFF];momd
	bl	___cxa_atexit
L5:
	nop
	ldp	x29, x30, [sp], 32
LCFI3:
	ret
LFE2276:
	.align	2
__GLOBAL__sub_I_main.cpp:
LFB2277:
	stp	x29, x30, [sp, -16]!
LCFI4:
	mov	x29, sp
	mov	w1, 65535
	mov	w0, 1
	bl	__Z41__static_initialization_and_destruction_0ii
	ldp	x29, x30, [sp], 16
LCFI5:
	ret
LFE2277:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB1778-.
	.set L$set$2,LFE1778-LFB1778
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB1778
	.long L$set$3
	.byte	0xe
	.uleb128 0x10
	.byte	0x9d
	.uleb128 0x2
	.byte	0x9e
	.uleb128 0x1
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE1:
LSFDE3:
	.set L$set$5,LEFDE3-LASFDE3
	.long L$set$5
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB2276-.
	.set L$set$6,LFE2276-LFB2276
	.quad L$set$6
	.uleb128 0
	.byte	0x4
	.set L$set$7,LCFI2-LFB2276
	.long L$set$7
	.byte	0xe
	.uleb128 0x20
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$8,LCFI3-LCFI2
	.long L$set$8
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE3:
LSFDE5:
	.set L$set$9,LEFDE5-LASFDE5
	.long L$set$9
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB2277-.
	.set L$set$10,LFE2277-LFB2277
	.quad L$set$10
	.uleb128 0
	.byte	0x4
	.set L$set$11,LCFI4-LFB2277
	.long L$set$11
	.byte	0xe
	.uleb128 0x10
	.byte	0x9d
	.uleb128 0x2
	.byte	0x9e
	.uleb128 0x1
	.byte	0x4
	.set L$set$12,LCFI5-LCFI4
	.long L$set$12
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE5:
	.private_extern ___dso_handle
	.ident	"GCC: (Homebrew GCC 11.1.0_1) 11.1.0"
	.mod_init_func
_Mod.init:
	.align	3
	.xword	__GLOBAL__sub_I_main.cpp
	.subsections_via_symbols
