; Wrote by Ayush Yadav(clawbhaiya) on 01/07/2021
; This file is a part of Maize Kernel

; Stivale header
section .stivale2hdr
stivale2hdr:
  .entry_point: dq 0
  .stack: dq stack.top
  .flags: dq 0
  .tags: dq fb_tag

; reserve 8kb for stack
section .bss
stack:
  resb 8192
.top:

; tag definitions
section .data
fb_tag:
  .id: dq 0x3ecc1bc43d0f7971
  .next: dq fb_mtrr
  .fb_width: dw 0
  .fb_height: dw 0
  .fb_bpp: dw 0

fb_mtrr:
  .id: dq 0x4c7bb07731282e00
  .next: dq 0

section .text
; start of kernel
global _start

; main kernel function
extern kmain
_start:
  cli           ; stop interrupts
  call kmain    ; call the main kernel function
  hlt           ; halt if we somehow exit main kernel function
  jmp loop      ; jump to loop

loop:
  cli           ; block interrupts
  hlt           ; halt the system
  jmp $         ; loop infinitely

