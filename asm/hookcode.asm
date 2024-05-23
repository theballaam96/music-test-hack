START_HOOK:
initCode:
    jal 0x80609140
    sw $zero, 0x14 ($sp)
    jal quickInit
    nop
    j 0x805FBDF4
    nop

displayListCode:
    jal displayListModifiers
    or $a0, $s0, $zero
    or $s0, v0, $zero
    lui $a0, 0x8075
    addiu $a0, $a0, 0x531C
    lhu v1, 0x0 ($a0)
    lui v0, 0x8075
    j 0x80714184
    lbu v0, 0x5314 (v0)

.align 0x10
END_HOOK: