align 16
SynthesizerActivate:
loc_10001000:
;sub esp, 0x8
sub r11d, 0x8
cmp dword [loc_1001B2C8], 0x0
;push esi
;push edi
PUSH32 esi, edi
jnz short loc_10001018
;call loc_10002830
CALL loc_10002830
mov [loc_1001B2C8], eax
loc_10001018:
cmp dword [loc_1001B2A4], 0x0
jz short loc_1000102B
xor eax, eax
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x8
add r11d, 0x8
;ret 0x18
RET 24
loc_1000102B:
;mov esi, [esp+0x24]
mov esi, [r11d+0x24]
test esi, esi
jnz short loc_10001042
;push loc_1001E8A0
PUSH32 loc_1001E8A0
;call loc_10001980
CALL loc_10001980
;add esp, 0x4
add r11d, 0x4
jmp short loc_1000104E
loc_10001042:
mov edi, loc_1001E8A0
mov ecx, 0x12c
;rep movsd
rep a32 movsd
loc_1000104E:
;mov eax, [esp+0x28]
mov eax, [r11d+0x28]
;lea ecx, [esp+0xc]
lea ecx, [r11d+0xc]
;lea edx, [esp+0x8]
lea edx, [r11d+0x8]
;push eax
PUSH32 eax
mov byte [loc_1001ED38], 0x1
;push ecx
;push edx
PUSH32 ecx, edx
;push loc_1001E8A0
PUSH32 loc_1001E8A0
;call loc_10001C20
CALL loc_10001C20
;add esp, 0x10
add r11d, 0x10
test eax, eax
jnz short loc_1000107F
xor eax, eax
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x8
add r11d, 0x8
;ret 0x18
RET 24
loc_1000107F:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;mov edx, [esp+0x20]
mov edx, [r11d+0x20]
mov [loc_1001B2B0], eax
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
mov [loc_1001B2A8], ecx
mov [loc_1001B2B4], eax
mov [loc_1001B2AC], edx
xor eax, eax
test ecx, ecx
mov [loc_1001B2B8], eax
mov [loc_1001B2BC], eax
jz short loc_100010C7
cmp ecx, 0x1
jz short loc_100010DC
cmp ecx, 0x2
jz near loc_100010F1
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x8
add r11d, 0x8
;ret 0x18
RET 24
loc_100010C7:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
PUSH32 eax
;call loc_10001DD0
CALL loc_10001DD0
;add esp, 0x4
add r11d, 0x4
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x8
add r11d, 0x8
;ret 0x18
RET 24
loc_100010DC:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
PUSH32 eax
;call loc_100021D0
CALL loc_100021D0
;add esp, 0x4
add r11d, 0x4
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x8
add r11d, 0x8
;ret 0x18
RET 24
loc_100010F1:
mov eax, 1 ; allow output type 2
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x8
add r11d, 0x8
;ret 0x18
RET 24
align 16
SynthesizerDeactivate:
loc_10001100:
cmp dword [loc_1001B2A4], 0x0
jnz short loc_1000110C
xor eax, eax
;ret
RET
loc_1000110C:
mov eax, [loc_1001B2A8]
test eax, eax
jz short loc_10001122
cmp eax, 0x1
jz short loc_10001129
cmp eax, 0x2
jz short loc_10001139
xor eax, eax
;ret
RET
loc_10001122:
;call loc_10002040
CALL loc_10002040
jmp short loc_1000112E
loc_10001129:
;call loc_10002520
CALL loc_10002520
loc_1000112E:
;call loc_10001D40
CALL loc_10001D40
mov eax, 0x1
;ret
RET
loc_10001139:
jmp short loc_1000112E ; allow output type 2
;ret
RET
align 16
SynthesizerPreload:
loc_10001140:
xor al, al
cmp dword [loc_1001B2A4], 0x0
jz short loc_1000115F
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov ecx, [loc_1001B2A4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10002EE0
CALL loc_10002EE0
;add esp, 0x8
add r11d, 0x8
loc_1000115F:
xor ecx, ecx
mov cl, al
mov eax, ecx
;ret 0x4
RET 4
align 16
SynthesizerMidi:
loc_10001170:
cmp dword [loc_1001B2A4], 0x0
jz short loc_10001192
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
PUSH32 eax
mov edx, [loc_1001B2A4]
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_100043B0
CALL loc_100043B0
;add esp, 0xc
add r11d, 0xc
loc_10001192:
;ret 0x8
RET 8
align 16
SynthesizerMidiLong:
loc_100011A0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
and eax, 0xf0
sub eax, 0x80
cmp eax, 0x60
ja short loc_100011C2
xor ecx, ecx
mov cl, [eax+loc_10001210]
;jmp dword [ecx*4+loc_100011F4]
mov r9d, [ecx*4+loc_100011F4]
jmp r9
loc_100011C2:
xor ax, ax
jmp short loc_100011D1
loc_100011C7:
mov ax, 0x3
jmp short loc_100011D1
loc_100011CD:
mov ax, 0x2
loc_100011D1:
cmp dword [loc_1001B2A4], 0x0
jz short loc_100011EF
;push eax
PUSH32 eax
mov ecx, [loc_1001B2A4]
;lea eax, [esp+0x8]
lea eax, [r11d+0x8]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_100043B0
CALL loc_100043B0
;add esp, 0xc
add r11d, 0xc
loc_100011EF:
;ret 0x4
RET 4
db 139
db 255
align 4
loc_100011F4:
dd loc_100011C7
dd loc_100011C7
dd loc_100011C7
dd loc_100011CD
dd loc_100011CD
dd loc_100011C7
dd loc_100011C2
loc_10001210:
db 0
times 15 db 6
db 1
times 31 db 6
db 2
times 15 db 6
db 3
times 15 db 6
db 4
times 15 db 6
db 5
times 15 db 204
align 4
SynthesizerPlayback:
loc_10001280:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
mov [loc_1001B2E0], eax
mov [loc_1001E898], ecx
mov eax, 0x1
;ret 0x8
RET 8
align 16
SynthesizerAllNotesOff:
loc_100012A0:
cmp dword [loc_1001B2A4], 0x0
jz short loc_100012B7
mov eax, [loc_1001B2A4]
;push eax
PUSH32 eax
;call loc_10003030
CALL loc_10003030
;add esp, 0x4
add r11d, 0x4
loc_100012B7:
;ret
RET
align 16
SynthesizerReset:
loc_100012C0:
cmp dword [loc_1001B2A4], 0x0
jz short loc_100012D7
mov eax, [loc_1001B2A4]
;push eax
PUSH32 eax
;call loc_10002FC0
CALL loc_10002FC0
;add esp, 0x4
add r11d, 0x4
loc_100012D7:
;ret
RET
align 16
SynthesizerControllersReset:
loc_100012E0:
cmp dword [loc_1001B2A4], 0x0
jz short loc_100012F7
mov eax, [loc_1001B2A4]
;push eax
PUSH32 eax
;call loc_10003100
CALL loc_10003100
;add esp, 0x4
add r11d, 0x4
loc_100012F7:
;ret
RET
align 16
SynthesizerStatus:
loc_10001300:
;sub esp, 0x1c
sub r11d, 0x1c
xor eax, eax
cmp [loc_1001B2A4], eax
jnz short loc_10001325
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
mov [ecx], eax
mov [ecx+0x4], eax
mov [ecx+0x8], eax
mov [ecx+0xc], eax
mov [ecx+0x10], eax
;add esp, 0x1c
add r11d, 0x1c
;ret 0x4
RET 4
loc_10001325:
;lea eax, [esp]
lea eax, [r11d]
mov ecx, [loc_1001B2A4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10005910
CALL loc_10005910
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;add esp, 0x8
add r11d, 0x8
shl eax, 0x2
lea ecx, [eax+eax*4]
lea eax, [ecx+ecx*4]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
cdq
;idiv dword [esp+0x4]
idiv dword [r11d+0x4]
mov [ecx], eax
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
shl eax, 0x2
lea edx, [eax+eax*4]
lea eax, [edx+edx*4]
cdq
;idiv dword [esp+0xc]
idiv dword [r11d+0xc]
mov [ecx+0x4], eax
;movsx eax, word [esp+0x10]
movsx eax, word [r11d+0x10]
mov [ecx+0x8], eax
mov eax, [loc_1001B2B8]
shl eax, 0x2
lea edx, [eax+eax*4]
lea eax, [edx+edx*4]
sar eax, 0x10
mov [ecx+0xc], eax
mov eax, [loc_1001B2BC]
shl eax, 0x2
lea edx, [eax+eax*4]
lea eax, [edx+edx*4]
sar eax, 0x10
mov [ecx+0x10], eax
;add esp, 0x1c
add r11d, 0x1c
;ret 0x4
RET 4
align 16
SynthesizerNumberOfBanks:
loc_100013A0:
cmp dword [loc_1001B2A4], 0x0
jnz short loc_100013AD
xor ax, ax
;ret
RET
loc_100013AD:
mov eax, [loc_1001B2A4]
mov ecx, [eax+0x18]
mov edx, [ecx]
mov ax, [edx+0x18]
;ret
RET
align 16
SynthesizerBankIndexToNumber:
loc_100013C0:
xor ax, ax
cmp dword [loc_1001B2A4], 0x0
jz short loc_10001400
mov ecx, [loc_1001B2A4]
mov ecx, [ecx+0x18]
mov edx, [ecx]
;mov cx, [esp+0x4]
mov cx, [r11d+0x4]
test cx, cx
jl short loc_10001400
cmp [edx+0x18], cx
jle short loc_10001400
movsx eax, cx
mov ecx, eax
shl eax, 0x3
sub eax, ecx
lea eax, [edx+eax*8]
add eax, 0x40
;push eax
PUSH32 eax
;call loc_10005F70
CALL loc_10005F70
;add esp, 0x4
add r11d, 0x4
loc_10001400:
;ret 0x4
RET 4
align 16
SynthesizerBankNumberToIndex:
loc_10001410:
cmp dword [loc_1001B2A4], 0x0
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
jnz short loc_10001426
mov ax, 0xffff
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret 0x4
RET 4
loc_10001426:
xor bx, bx
mov eax, [loc_1001B2A4]
mov ecx, [eax+0x18]
mov edi, [ecx]
cmp [edi+0x18], bx
jle short loc_10001464
;mov si, [esp+0x10]
mov si, [r11d+0x10]
loc_1000143E:
movsx eax, bx
mov ecx, eax
shl eax, 0x3
sub eax, ecx
lea eax, [edi+eax*8]
add eax, 0x40
;push eax
PUSH32 eax
;call loc_10005F70
CALL loc_10005F70
;add esp, 0x4
add r11d, 0x4
cmp ax, si
jz short loc_1000146E
inc bx
cmp [edi+0x18], bx
jg short loc_1000143E
loc_10001464:
mov ax, 0xffff
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret 0x4
RET 4
loc_1000146E:
mov ax, bx
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret 0x4
RET 4
align 16
SynthesizerBankName:
loc_10001480:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;push esi
;push edi
PUSH32 esi, edi
mov byte [edx], 0x0
cmp dword [loc_1001B2A4], 0x0
jz near loc_10001529
mov eax, [loc_1001B2A4]
mov ecx, [eax+0x18]
;mov ax, [esp+0xc]
mov ax, [r11d+0xc]
mov esi, [ecx]
test ax, ax
jl near loc_10001529
cmp [esi+0x18], ax
jle near loc_10001529
movsx eax, ax
xor edi, edi
mov ecx, eax
shl eax, 0x3
sub eax, ecx
lea ecx, [eax*8]
loc_100014C3:
lea eax, [esi+edi]
mov al, [eax+ecx+0x1e]
cmp al, 0x2e
jz short loc_100014D9
mov [edx+edi], al
inc edi
cmp edi, 0x20
jl short loc_100014C3
jmp short loc_100014DD
loc_100014D9:
mov byte [edx+edi], 0x0
loc_100014DD:
mov eax, [ecx+esi+0x40]
cmp eax, 0x6e6f726d
jnz short loc_100014F7
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;pop edi
;pop esi
POP32 esi, edi
mov dword [eax], 0x0
;ret 0xc
RET 12
loc_100014F7:
cmp eax, 0x676d2020
jnz short loc_1000150D
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;pop edi
;pop esi
POP32 esi, edi
mov dword [eax], 0x1
;ret 0xc
RET 12
loc_1000150D:
cmp eax, 0x67732020
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
jnz short loc_10001523
;pop edi
POP32 edi
mov dword [eax], 0x2
;pop esi
POP32 esi
;ret 0xc
RET 12
loc_10001523:
mov dword [eax], 0xffffffff
loc_10001529:
;pop edi
;pop esi
POP32 esi, edi
;ret 0xc
RET 12
align 16
SynthesizerNumberOfPrograms:
loc_10001530:
xor ax, ax
;push esi
PUSH32 esi
cmp dword [loc_1001B2A4], 0x0
jz near loc_1000159D
mov ecx, [loc_1001B2A4]
mov edx, [ecx+0x18]
;mov cx, [esp+0x8]
mov cx, [r11d+0x8]
mov esi, [edx]
test cx, cx
jl short loc_1000159A
cmp [esi+0x18], cx
jle short loc_1000159A
movsx ecx, cx
mov edx, ecx
shl ecx, 0x3
sub ecx, edx
mov edx, [esi+ecx*8+0x4e]
test edx, edx
jnz short loc_10001571
xor ax, ax
;pop esi
POP32 esi
;ret 0x4
RET 4
loc_10001571:
mov cx, [edx]
test cx, cx
jle short loc_1000158C
movsx ecx, cx
add edx, 0x22
loc_1000157F:
cmp dword [edx], 0x0
jz short loc_10001586
inc ax
loc_10001586:
add edx, 0x2c
dec ecx
jnz short loc_1000157F
loc_1000158C:
cmp ax, 0x80
jle short loc_1000159D
;pop esi
POP32 esi
mov ax, 0x80
;ret 0x4
RET 4
loc_1000159A:
xor ax, ax
loc_1000159D:
;pop esi
POP32 esi
;ret 0x4
RET 4
align 16
SynthesizerProgramName:
loc_100015B0:
xor dx, dx
;sub esp, 0xc
sub r11d, 0xc
mov ecx, 0xffffffff
;push ebx
PUSH32 ebx
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;push esi
PUSH32 esi
;mov ebx, [esp+0x28]
mov ebx, [r11d+0x28]
;push edi
;push ebp
PUSH32 edi, ebp
mov [eax], dl
mov [ebx], dl
cmp dword [loc_1001B2A4], 0x0
jz near loc_10001756
;cmp [esp+0x20], cx
cmp [r11d+0x20], cx
mov eax, [loc_1001B2A4]
mov ebp, [eax+0x18]
mov ebx, [ebp]
jl near loc_10001756
;mov ax, [esp+0x20]
mov ax, [r11d+0x20]
cmp [ebx+0x18], ax
jle near loc_10001756
cmp ax, cx
jnz short loc_10001617
movsx eax, word [ebx+0x16]
mov esi, eax
shl eax, 0x3
sub eax, esi
lea ebp, [ebx+eax*8+0x1a]
;mov [esp+0x18], ebp
mov [r11d+0x18], ebp
jmp short loc_1000162B
loc_10001617:
;movsx esi, word [esp+0x20]
movsx esi, word [r11d+0x20]
mov eax, esi
shl esi, 0x3
sub esi, eax
lea eax, [ebx+esi*8+0x1a]
;mov [esp+0x18], eax
mov [r11d+0x18], eax
loc_1000162B:
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
mov esi, [eax+0x34]
;mov [esp+0x10], esi
mov [r11d+0x10], esi
test esi, esi
jz near loc_10001756
;cmp word [esp+0x24], 0x0
cmp word [r11d+0x24], 0x0
jl near loc_10001756
mov ax, [esi]
;mov bp, [esp+0x24]
mov bp, [r11d+0x24]
;mov [esp+0x14], ax
mov [r11d+0x14], ax
cmp bp, ax
jge near loc_10001756
cmp bp, 0x80
jge near loc_10001756
xor edi, edi
cmp ax, di
jle short loc_1000169C
add esi, 0x22
loc_10001675:
cmp dword [esi], 0x0
jz short loc_1000168B
inc dx
;movsx ebp, word [esp+0x24]
movsx ebp, word [r11d+0x24]
movsx eax, dx
sub eax, ebp
cmp eax, 0x1
jz short loc_1000169A
loc_1000168B:
add esi, 0x2c
inc edi
;movsx eax, word [esp+0x14]
movsx eax, word [r11d+0x14]
cmp eax, edi
jg short loc_10001675
jmp short loc_1000169C
loc_1000169A:
mov ecx, edi
loc_1000169C:
;cmp word [esp+0x20], 0xffff
cmp word [r11d+0x20], 0xffff
jnz short loc_100016AA
add ecx, 0x80
loc_100016AA:
test ecx, ecx
jl near loc_10001756
lea eax, [ecx+ecx*4]
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
lea eax, [eax+eax*8]
sub eax, ecx
add edi, eax
mov eax, [edi+0x26]
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
lea ebp, [edi+0x22]
;call GlobalAlloc
CALL GlobalAlloc
;push eax
PUSH32 eax
mov esi, eax
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;push 0x0
PUSH32 0x0
;push ebp
PUSH32 ebp
mov ecx, [eax]
;push ecx
;push ebx
PUSH32 ecx, ebx
;call loc_10005EF0
CALL loc_10005EF0
;mov ebx, [esp+0x40]
mov ebx, [r11d+0x40]
;add esp, 0x14
add r11d, 0x14
movsx eax, byte [esi+0x31]
mov [ebx], eax
cmp eax, 0x19
jg short loc_100016F8
test eax, eax
jge short loc_100016FE
loc_100016F8:
mov dword [ebx], 0x0
loc_100016FE:
;push esi
PUSH32 esi
add edi, 0x2
;call GlobalFree
CALL GlobalFree
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov eax, ecx
shr ecx, 0x2
mov esi, edi
;mov edi, [esp+0x30]
mov edi, [r11d+0x30]
;rep movsd
rep a32 movsd
mov ecx, eax
and ecx, 0x3
;rep movsb
rep a32 movsb
mov ecx, [ebx]
lea eax, [ecx+ecx*4]
mov ecx, 0xffffffff
lea edi, [eax+eax*4+loc_1001B030]
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
shr ecx, 0x2
mov esi, edi
;mov edi, [esp+0x28]
mov edi, [r11d+0x28]
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
loc_10001756:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret 0x14
RET 20
SynthesizerProgramNumberToIndex:
loc_10001760:
xor ax, ax
;push ebx
PUSH32 ebx
cmp dword [loc_1001B2A4], 0x0
;push esi
;push edi
;push ebp
PUSH32 esi, edi, ebp
jnz short loc_1000177B
mov ax, 0xffff
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_1000177B:
mov ecx, [loc_1001B2A4]
mov edx, [ecx+0x18]
;mov cx, [esp+0x14]
mov cx, [r11d+0x14]
mov esi, [edx]
test cx, cx
jl near loc_10001800
cmp [esi+0x18], cx
jle near loc_10001800
movsx ecx, cx
mov edx, ecx
shl ecx, 0x3
sub ecx, edx
mov esi, [esi+ecx*8+0x4e]
test esi, esi
jnz short loc_100017B3
mov ax, 0xffff
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_100017B3:
;mov cx, [esp+0x18]
mov cx, [r11d+0x18]
xor edx, edx
test cx, cx
jl short loc_100017F5
cmp [esi], cx
jle short loc_100017F5
cmp cx, 0x80
jge short loc_100017F5
test cx, cx
jle short loc_10001804
xor edi, edi
loc_100017D2:
movsx ebx, dx
mov ebp, ebx
lea ebx, [ebx+ebx*4]
lea ebx, [ebx+ebx*8]
sub ebx, ebp
cmp [ebx+esi+0x22], edi
jz short loc_100017E7
inc ax
loc_100017E7:
inc dx
cmp dx, cx
jl short loc_100017D2
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_100017F5:
mov ax, 0xffff
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_10001800:
mov ax, 0xffff
loc_10001804:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
align 16
SynthesizerProgramIndexToNumber:
loc_10001810:
xor dx, dx
;push ebx
PUSH32 ebx
cmp dword [loc_1001B2A4], 0x0
;push esi
;push edi
;push ebp
PUSH32 esi, edi, ebp
jnz short loc_1000182B
mov ax, 0xffff
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_1000182B:
mov eax, [loc_1001B2A4]
mov ecx, [eax+0x18]
;mov ax, [esp+0x14]
mov ax, [r11d+0x14]
mov esi, [ecx]
test ax, ax
jl near loc_100018D9
cmp [esi+0x18], ax
jle near loc_100018D9
movsx eax, ax
mov ecx, eax
shl eax, 0x3
sub eax, ecx
mov esi, [esi+eax*8+0x4e]
test esi, esi
jnz short loc_1000186A
mov ax, 0xffff
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_1000186A:
;cmp word [esp+0x18], 0x0
cmp word [r11d+0x18], 0x0
jl near loc_100018CE
mov di, [esi]
;cmp [esp+0x18], di
cmp [r11d+0x18], di
jge near loc_100018CE
;cmp word [esp+0x18], 0x80
cmp word [r11d+0x18], 0x80
jge near loc_100018CE
mov ax, 0xffff
xor bx, bx
test di, di
jle near loc_100018DD
loc_10001891:
movsx ecx, bx
mov ebp, ecx
lea ecx, [ecx+ecx*4]
lea ecx, [ecx+ecx*8]
sub ecx, ebp
cmp dword [ecx+esi+0x22], 0x0
jz short loc_100018B6
inc dx
;movsx ebp, word [esp+0x18]
movsx ebp, word [r11d+0x18]
movsx ecx, dx
sub ecx, ebp
cmp ecx, 0x1
jz short loc_100018C4
loc_100018B6:
inc bx
cmp bx, di
jl short loc_10001891
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_100018C4:
mov ax, bx
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_100018CE:
mov ax, 0xffff
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
loc_100018D9:
mov ax, 0xffff
loc_100018DD:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret 0x8
RET 8
align 16
SynthesizerSetMode:
loc_100018F0:
cmp dword [loc_1001B2A4], 0x0
jnz short loc_10001900
mov ax, 0xffff
;ret 0x4
RET 4
loc_10001900:
;mov ax, [esp+0x4]
mov ax, [r11d+0x4]
cmp ax, 0x2
jnz short loc_10001923
mov eax, [loc_1001B2A4]
mov byte [eax+0x61], 0x1
mov eax, [loc_1001B2A4]
mov byte [eax+0x60], 0x0
xor ax, ax
;ret 0x4
RET 4
loc_10001923:
cmp ax, 0x1
jnz short loc_10001941
mov eax, [loc_1001B2A4]
mov byte [eax+0x61], 0x0
mov eax, [loc_1001B2A4]
mov byte [eax+0x60], 0x1
xor ax, ax
;ret 0x4
RET 4
loc_10001941:
xor ecx, ecx
test ax, ax
jnz short loc_1000195F
mov eax, [loc_1001B2A4]
mov [eax+0x61], cl
mov eax, [loc_1001B2A4]
mov [eax+0x60], cl
mov ax, 0xffff
;ret 0x4
RET 4
loc_1000195F:
mov ax, 0xffff
;ret 0x4
RET 4
align 16
SynthesizerPlayClick:
loc_10001970:
mov eax, 0x1
;ret 0x8
RET 8
align 16
loc_10001980:
;sub esp, 0x14
sub r11d, 0x14
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x20]
mov esi, [r11d+0x20]
;push edi
;push ebp
;push esi
PUSH32 edi, ebp, esi
;call loc_100060F0
CALL loc_100060F0
;lea eax, [esp+0x24]
lea eax, [r11d+0x24]
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;add esp, 0x4
add r11d, 0x4
;push eax
;push ecx
PUSH32 eax, ecx
;push 0x0
PUSH32 0x0
;push 0xf003f
PUSH32 0xf003f
;push 0x0
PUSH32 0x0
;push loc_1001B3A0
PUSH32 loc_1001B3A0
;push 0x0
PUSH32 0x0
;push loc_1001B37C
PUSH32 loc_1001B37C
;push 0x80000002
PUSH32 0x80000002
;call RegCreateKeyExA
CALL RegCreateKeyExA
test eax, eax
jnz near loc_10001C14
mov ebx, 0x3
mov ebp, 0x1
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
lea ecx, [esi+0x1]
;lea edx, [esp+0x14]
lea edx, [r11d+0x14]
;push eax
PUSH32 eax
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;push ecx
;push edx
PUSH32 ecx, edx
mov edi, RegQueryValueExA
;mov [esp+0x20], ebx
mov [r11d+0x20], ebx
;push 0x0
PUSH32 0x0
;mov [esp+0x20], ebp
mov [r11d+0x20], ebp
;push loc_1001B374
PUSH32 loc_1001B374
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
;lea ecx, [esp+0x10]
lea ecx, [r11d+0x10]
lea eax, [esi+0x482]
;lea edx, [esp+0x14]
lea edx, [r11d+0x14]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push eax
PUSH32 eax
;mov [esp+0x1c], ebx
mov [r11d+0x1c], ebx
;push edx
PUSH32 edx
;mov [esp+0x1c], ebp
mov [r11d+0x1c], ebp
;push 0x0
PUSH32 0x0
;push loc_1001B368
PUSH32 loc_1001B368
;push ecx
PUSH32 ecx
;call edi
mov r9d, edi
CALL r9
;lea ecx, [esp+0x10]
lea ecx, [r11d+0x10]
lea edx, [esi+0x48e]
;lea eax, [esp+0x14]
lea eax, [r11d+0x14]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push edx
PUSH32 edx
;mov [esp+0x1c], ebx
mov [r11d+0x1c], ebx
;push eax
PUSH32 eax
;mov [esp+0x1c], ebp
mov [r11d+0x1c], ebp
;push 0x0
PUSH32 0x0
;push loc_1001B35C
PUSH32 loc_1001B35C
;push ecx
PUSH32 ecx
;call edi
mov r9d, edi
CALL r9
;lea ecx, [esp+0x10]
lea ecx, [r11d+0x10]
lea edx, [esi+0x499]
;lea eax, [esp+0x14]
lea eax, [r11d+0x14]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push edx
PUSH32 edx
;mov [esp+0x1c], ebx
mov [r11d+0x1c], ebx
;push eax
PUSH32 eax
;mov [esp+0x1c], ebp
mov [r11d+0x1c], ebp
;push 0x0
PUSH32 0x0
;push loc_1001B358
PUSH32 loc_1001B358
;push ecx
PUSH32 ecx
;call edi
mov r9d, edi
CALL r9
;lea ecx, [esp+0x10]
lea ecx, [r11d+0x10]
lea edx, [esi+0x498]
;mov [esp+0x14], ebx
mov [r11d+0x14], ebx
;push ecx
PUSH32 ecx
;mov [esp+0x14], ebp
mov [r11d+0x14], ebp
;push edx
PUSH32 edx
;lea ebx, [esp+0x1c]
lea ebx, [r11d+0x1c]
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push ebx
PUSH32 ebx
;push 0x0
PUSH32 0x0
;push loc_1001B350
PUSH32 loc_1001B350
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
mov eax, 0x4
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;lea ebx, [esp+0x14]
lea ebx, [r11d+0x14]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x10], eax
mov [r11d+0x10], eax
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;push eax
;push ecx
PUSH32 eax, ecx
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push ebx
PUSH32 ebx
;push 0x0
PUSH32 0x0
;push loc_1001B33C
PUSH32 loc_1001B33C
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
test eax, eax
jnz short loc_10001ACF
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov [esi+0x49c], ax
loc_10001ACF:
mov eax, 0x4
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;lea edx, [esp+0x14]
lea edx, [r11d+0x14]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x10], eax
mov [r11d+0x10], eax
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;push eax
;push ecx
PUSH32 eax, ecx
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push edx
PUSH32 edx
;push 0x0
PUSH32 0x0
;push loc_1001B338
PUSH32 loc_1001B338
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
test eax, eax
jnz short loc_10001B08
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov [esi+0x4a0], ax
loc_10001B08:
mov eax, 0x4
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;lea edx, [esp+0x14]
lea edx, [r11d+0x14]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x10], eax
mov [r11d+0x10], eax
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;push eax
;push ecx
PUSH32 eax, ecx
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push edx
PUSH32 edx
;push 0x0
PUSH32 0x0
;push loc_1001B32C
PUSH32 loc_1001B32C
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
test eax, eax
jnz short loc_10001B40
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov [esi+0x4a2], eax
loc_10001B40:
mov eax, 0x4
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;lea edx, [esp+0x14]
lea edx, [r11d+0x14]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x10], eax
mov [r11d+0x10], eax
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;push eax
;push ecx
PUSH32 eax, ecx
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push edx
PUSH32 edx
;push 0x0
PUSH32 0x0
;push loc_1001B31C
PUSH32 loc_1001B31C
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
test eax, eax
jnz short loc_10001B79
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov [esi+0x48c], ax
loc_10001B79:
mov eax, 0x4
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;lea edx, [esp+0x14]
lea edx, [r11d+0x14]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x10], eax
mov [r11d+0x10], eax
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;push eax
;push ecx
PUSH32 eax, ecx
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push edx
PUSH32 edx
;push 0x0
PUSH32 0x0
;push loc_1001B30C
PUSH32 loc_1001B30C
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
test eax, eax
jnz short loc_10001BB2
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov [esi+0x496], ax
loc_10001BB2:
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;lea ecx, [esp+0x14]
lea ecx, [r11d+0x14]
;mov dword [esp+0x14], 0x3
mov dword [r11d+0x14], 0x3
;mov edx, [esp+0x18]
mov edx, [r11d+0x18]
;push eax
PUSH32 eax
;mov dword [esp+0x14], 0x1
mov dword [r11d+0x14], 0x1
;push loc_1001B2C0
PUSH32 loc_1001B2C0
;push ecx
PUSH32 ecx
;push 0x0
PUSH32 0x0
;push loc_1001B308
PUSH32 loc_1001B308
;push edx
PUSH32 edx
;call edi
mov r9d, edi
CALL r9
mov eax, 0x4
;lea ecx, [esp+0x14]
lea ecx, [r11d+0x14]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x10], eax
mov [r11d+0x10], eax
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;mov edx, [esp+0x18]
mov edx, [r11d+0x18]
;push eax
PUSH32 eax
;push loc_1001B2C4
PUSH32 loc_1001B2C4
;push ecx
PUSH32 ecx
;push 0x0
PUSH32 0x0
;push loc_1001B2F8
PUSH32 loc_1001B2F8
;push edx
PUSH32 edx
;call edi
mov r9d, edi
CALL r9
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;push ecx
PUSH32 ecx
;call RegCloseKey
CALL RegCloseKey
loc_10001C14:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14
add r11d, 0x14
;ret
RET
align 16
loc_10001C20:
;push esi
PUSH32 esi
xor eax, eax
;push edi
PUSH32 edi
mov ecx, 0x100
mov edi, loc_1001DC70
;rep stosd
rep a32 stosd
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
PUSH32 eax
;push loc_1001B2A4
PUSH32 loc_1001B2A4
;push 0x3c
PUSH32 0x3c
;push 0x40
PUSH32 0x40
;push 0x190
PUSH32 0x190
;push 0x190
PUSH32 0x190
;mov esi, [esp+0x24]
mov esi, [r11d+0x24]
;push 0x4
PUSH32 0x4
;push 0x190
PUSH32 0x190
;push 0x190
PUSH32 0x190
;push 0x190
PUSH32 0x190
;push 0x0
PUSH32 0x0
;push esi
PUSH32 esi
;call loc_10002910
CALL loc_10002910
;add esp, 0x30
add r11d, 0x30
test eax, eax
jz short loc_10001C71
xor eax, eax
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_10001C71:
mov eax, [loc_1001B2A4]
;push eax
PUSH32 eax
;call loc_10002B80
CALL loc_10002B80
;add esp, 0x4
add r11d, 0x4
xor ecx, ecx
mov cl, al
test ecx, ecx
jnz short loc_10001C8C
xor eax, eax
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_10001C8C:
mov eax, [loc_1001B2A4]
mov dword [eax+0x4], 0x0
mov eax, [loc_1001B2A4]
mov ecx, [eax+0x18]
mov edx, [ecx]
mov eax, [edx+0x10]
lea ecx, [eax+eax*4]
lea edx, [ecx+ecx*4]
mov ecx, 0x5622
lea eax, [edx+edx*4]
shl eax, 0x3
cdq
idiv ecx
mov edx, [loc_1001B2A4]
mov ecx, 0x64
mov [edx+0x8], eax
mov edx, [loc_1001B2A4]
movsx eax, word [esi+0x4a0]
imul eax, [edx+0x8]
sub edx, edx
div ecx
mov edx, [loc_1001B2A4]
mov [edx+0xc], eax
mov edx, [loc_1001B2A4]
mov eax, [edx+0xc]
sub edx, edx
div ecx
;push eax
PUSH32 eax
;call loc_100063B0
CALL loc_100063B0
inc ax
;add esp, 0x4
add r11d, 0x4
mov ecx, [loc_1001B2A4]
mov [ecx+0x12], ax
mov ecx, [loc_1001B2A4]
mov eax, [ecx+0x18]
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov edx, [eax]
mov eax, [edx+0x10]
mov [ecx], eax
cmp eax, 0x200
jbe short loc_10001D27
xor eax, eax
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_10001D27:
lea ecx, [eax*4]
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;pop edi
;pop esi
POP32 esi, edi
mov [eax], ecx
mov eax, 0x1
;ret
RET
align 16
loc_10001D40:
;sub esp, 0x64
sub r11d, 0x64
; remove useless call to sprintf
mov ecx, [loc_1001B2A4]
;push ecx
PUSH32 ecx
;call loc_10002B10
CALL loc_10002B10
mov dword [loc_1001B2A4], 0x0
;add esp, 0x4
add r11d, 0x4
;add esp, 0x64
add r11d, 0x64
;ret
RET
align 16
ProcessEventsAndGenerateAudio:
loc_10001D80:
;push esi
;push edi
PUSH32 esi, edi
mov edi, timeGetTime
;call edi
mov r9d, edi
CALL r9
mov esi, eax
mov eax, [loc_1001B2A4]
;push eax
PUSH32 eax
;call loc_100043F0
CALL loc_100043F0
;add esp, 0x4
add r11d, 0x4
mov eax, [loc_1001B2A4]
;push loc_1001DC70
PUSH32 loc_1001DC70
;push eax
PUSH32 eax
;call loc_10003BB0
CALL loc_10003BB0
;add esp, 0x8
add r11d, 0x8
;call loc_10002730
CALL loc_10002730
;call edi
mov r9d, edi
CALL r9
mov ecx, [loc_1001B2A4]
sub eax, esi
inc dword [ecx]
mov ecx, [loc_1001B2A4]
;pop edi
;pop esi
POP32 esi, edi
mov [ecx+0x4], eax
;ret
RET
align 16
loc_10001DD0:
;sub esp, 0x14c
sub r11d, 0x14c
cmp dword [loc_1001B2CC], 0x0
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
jz short loc_10001DF0
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
loc_10001DF0:
mov eax, loc_1001E090
xor ecx, ecx
loc_10001DF7:
mov [eax], ecx
add eax, 0x20
cmp eax, loc_1001E890
mov [eax-0x10], ecx
jb short loc_10001DF7
;call waveOutGetNumDevs
CALL waveOutGetNumDevs
cmp eax, 0x1
jae short loc_10001E1E
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
loc_10001E1E:
;lea eax, [esp+0x28]
lea eax, [r11d+0x28]
;push 0x34
PUSH32 0x34
;push eax
PUSH32 eax
;push 0xffffffff
PUSH32 0xffffffff
;call waveOutGetDevCapsA
CALL waveOutGetDevCapsA
test eax, eax
jz short loc_10001E3E
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
loc_10001E3E:
cmp byte [loc_1001ED38], 0x1
;mov word [esp+0x10], 0x1
mov word [r11d+0x10], 0x1
;mov dword [esp+0x14], 0x5622
mov dword [r11d+0x14], 0x5622
sbb eax, eax
xor ecx, ecx
add eax, 0x2
mov cx, ax
;mov [esp+0x12], ax
mov [r11d+0x12], ax
mov eax, ecx
shl ecx, 0x4
add ecx, eax
lea edx, [ecx+ecx*8]
lea ecx, [eax+edx*8]
;mov word [esp+0x1e], 0x10
mov word [r11d+0x1e], 0x10
;mov word [esp+0x20], 0x0
mov word [r11d+0x20], 0x0
;mov ax, [esp+0x12]
mov ax, [r11d+0x12]
;push 0x30000
PUSH32 0x30000
add ax, ax
;push 0x0
PUSH32 0x0
shl ecx, 0x2
;mov [esp+0x24], ax
mov [r11d+0x24], ax
;push loc_100021B0
PUSH32 loc_100021B0
lea edx, [ecx+ecx*8]
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;mov [esp+0x24], edx
mov [r11d+0x24], edx
;push ecx
PUSH32 ecx
;push 0xffffffff
PUSH32 0xffffffff
;push loc_1001B2CC
PUSH32 loc_1001B2CC
;call waveOutOpen
CALL waveOutOpen
mov ebx, eax
test ebx, ebx
jz near loc_10001F0D
;lea eax, [esp+0x5c]
lea eax, [r11d+0x5c]
;push 0x100
PUSH32 0x100
;push eax
PUSH32 eax
mov edi, loc_1001B3CC
;push ebx
PUSH32 ebx
;call waveOutGetErrorTextA
CALL waveOutGetErrorTextA
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
;lea edi, [esp+0x5c]
lea edi, [r11d+0x5c]
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
test ebx, ebx
jz short loc_10001F0D
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
loc_10001F0D:
;lea eax, [esp+0x24]
lea eax, [r11d+0x24]
mov ecx, [loc_1001B2CC]
;push eax
;push ecx
PUSH32 eax, ecx
;call waveOutGetVolume
CALL waveOutGetVolume
test eax, eax
jz short loc_10001F30
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
loc_10001F30:
mov ebx, loc_1001E090
loc_10001F35:
mov eax, [loc_1001B2B4]
;push eax
PUSH32 eax
;push 0x40
PUSH32 0x40
;call GlobalAlloc
CALL GlobalAlloc
mov ecx, [loc_1001B2B4]
test eax, eax
jz near loc_10002019
;push 0x20
PUSH32 0x20
mov [ebx], eax
;push ebx
PUSH32 ebx
mov eax, [loc_1001B2CC]
;push eax
PUSH32 eax
mov [ebx+0x4], ecx
mov dword [ebx+0x8], 0x0
mov dword [ebx+0xc], 0x0
mov dword [ebx+0x10], 0x0
mov dword [ebx+0x14], 0x0
mov dword [ebx+0x18], 0x0
mov dword [ebx+0x1c], 0x0
;call waveOutPrepareHeader
CALL waveOutPrepareHeader
mov ebp, eax
test ebp, ebp
jz short loc_10001FDC
;lea eax, [esp+0x5c]
lea eax, [r11d+0x5c]
;push 0x100
PUSH32 0x100
;push eax
PUSH32 eax
mov edi, loc_1001B3CC
;push ebp
PUSH32 ebp
;call waveOutGetErrorTextA
CALL waveOutGetErrorTextA
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
;lea edi, [esp+0x5c]
lea edi, [r11d+0x5c]
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
test ebp, ebp
jnz near loc_10002026
loc_10001FDC:
add ebx, 0x20
cmp ebx, loc_1001E890
jb near loc_10001F35
xor eax, eax
mov esi, 0x40
mov [loc_1001B2D0], eax
mov [loc_1001B2D4], eax
mov [loc_1001B2D8], eax
loc_10002001:
;call loc_100020D0
CALL loc_100020D0
dec esi
jnz short loc_10002001
mov eax, 0x1
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
loc_10002019:
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
loc_10002026:
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14c
add r11d, 0x14c
;ret
RET
align 16
loc_10002040:
cmp dword [loc_1001B2CC], 0x0
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
jz near loc_100020C5
mov dword [loc_1001B2D0], 0x1
mov eax, [loc_1001B2CC]
;push eax
PUSH32 eax
;call waveOutReset
CALL waveOutReset
test eax, eax
jnz near loc_100020C5
mov edi, loc_1001E090
mov esi, GlobalFree
mov ebx, waveOutUnprepareHeader
mov ebp, 0x2
loc_1000207D:
test [edi+0x10], ebp
jz short loc_10002091
;push 0x20
PUSH32 0x20
mov eax, [loc_1001B2CC]
;push edi
;push eax
PUSH32 edi, eax
;call ebx
mov r9d, ebx
CALL r9
test eax, eax
jnz short loc_100020C5
loc_10002091:
mov eax, [edi]
test eax, eax
jz short loc_100020A0
;push eax
PUSH32 eax
;call esi
mov r9d, esi
CALL r9
mov dword [edi], 0x0
loc_100020A0:
add edi, 0x20
cmp edi, loc_1001E890
jb short loc_1000207D
mov eax, [loc_1001B2CC]
;push eax
PUSH32 eax
;call waveOutClose
CALL waveOutClose
test eax, eax
jnz short loc_100020C5
mov dword [loc_1001B2CC], 0x0
loc_100020C5:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_100020D0:
cmp dword [loc_1001B2D0], 0x0
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
jnz near loc_1000219F
;call loc_10001D80
CALL loc_10001D80
mov eax, [loc_1001B2D4]
shl eax, 0x5
mov ecx, [eax+loc_1001E090]
xor eax, eax
cmp [loc_1001B2B4], eax
jle short loc_1000210F
loc_100020FD:
mov dl, [eax+loc_1001DC70]
mov [ecx+eax], dl
inc eax
cmp eax, [loc_1001B2B4]
jl short loc_100020FD
loc_1000210F:
;push 0x20
PUSH32 0x20
mov eax, [loc_1001B2D4]
shl eax, 0x5
mov ecx, [loc_1001B2CC]
add eax, loc_1001E090
;push eax
;push ecx
PUSH32 eax, ecx
;call waveOutWrite
CALL waveOutWrite
test eax, eax
jnz near loc_1000219F
inc dword [loc_1001B2D4]
cmp dword [loc_1001B2D4], 0x40
jnz short loc_10002149
mov dword [loc_1001B2D4], 0x0
loc_10002149:
cmp dword [loc_1001B2E0], 0x0
jz short loc_1000219F
mov ebx, 0x2d57
cmp [loc_1001B2DC], ebx
jg short loc_10002195
mov esi, 0x2d58
xor edi, edi
loc_10002166:
mov eax, [loc_1001E898]
;push eax
PUSH32 eax
;call dword [loc_1001B2E0]
mov r9d, [loc_1001B2E0]
CALL r9
;add esp, 0x4
add r11d, 0x4
test eax, eax
jle short loc_10002181
add [loc_1001B2DC], eax
jmp short loc_1000218D
loc_10002181:
mov [loc_1001B2DC], esi
mov [loc_1001B2E0], edi
loc_1000218D:
cmp [loc_1001B2DC], ebx
jle short loc_10002166
loc_10002195:
sub dword [loc_1001B2DC], 0x2d57
loc_1000219F:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_100021B0:
;cmp dword [esp+0x8], 0x3bd
cmp dword [r11d+0x8], 0x3bd
jnz short loc_100021C5
;call loc_100020D0
CALL loc_100020D0
inc dword [loc_1001B2D8]
loc_100021C5:
;ret 0x14
RET 20
align 16
loc_100021D0:
;sub esp, 0x98
sub r11d, 0x98
;push esi
PUSH32 esi
;push 0x0
PUSH32 0x0
;push loc_1001E890
PUSH32 loc_1001E890
;push 0x0
PUSH32 0x0
;call loc_10002900
CALL loc_10002900
test eax, eax
jz short loc_100021F3
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_100021F3:
;lea eax, [esp+0x3c]
lea eax, [r11d+0x3c]
mov ecx, [loc_1001E890]
;mov dword [esp+0x3c], 0x60
mov dword [r11d+0x3c], 0x60
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [ecx]
;call dword [eax+0x10]
mov r9d, [eax+0x10]
CALL r9
test eax, eax
jz short loc_1000221A
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_1000221A:
;lea eax, [esp+0x30]
lea eax, [r11d+0x30]
mov ecx, [loc_1001E890]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [ecx]
;call dword [eax+0x20]
mov r9d, [eax+0x20]
CALL r9
test eax, eax
jz short loc_10002239
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_10002239:
;mov eax, [esp+0xa0]
mov eax, [r11d+0xa0]
;push 0x2
PUSH32 0x2
;push eax
PUSH32 eax
mov ecx, [loc_1001E890]
;push ecx
PUSH32 ecx
mov eax, [ecx]
;call dword [eax+0x18]
mov r9d, [eax+0x18]
CALL r9
test eax, eax
jz short loc_1000225D
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_1000225D:
;lea ecx, [esp+0x8]
lea ecx, [r11d+0x8]
xor eax, eax
mov [ecx], eax
;push eax
PUSH32 eax
;push loc_1001DC3C
PUSH32 loc_1001DC3C
mov [ecx+0x4], eax
mov [ecx+0x8], eax
mov edx, [loc_1001E890]
mov [ecx+0xc], eax
mov [ecx+0x10], eax
;lea ecx, [esp+0x10]
lea ecx, [r11d+0x10]
;mov dword [esp+0x10], 0x14
mov dword [r11d+0x10], 0x14
;mov dword [esp+0x14], 0x1
mov dword [r11d+0x14], 0x1
;push ecx
PUSH32 ecx
mov eax, [edx]
;push edx
PUSH32 edx
;call dword [eax+0xc]
mov r9d, [eax+0xc]
CALL r9
test eax, eax
jz short loc_100022A6
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_100022A6:
;lea eax, [esp+0x4]
lea eax, [r11d+0x4]
mov ecx, [loc_1001DC3C]
mov word [loc_1001DC60], 0x0
;push eax
PUSH32 eax
;push 0x12
PUSH32 0x12
;push loc_1001DC50
PUSH32 loc_1001DC50
mov eax, [ecx]
;push ecx
PUSH32 ecx
;call dword [eax+0x14]
mov r9d, [eax+0x14]
CALL r9
test eax, eax
jz short loc_100022D5
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_100022D5:
mov dword [loc_1001DC54], 0x5622
mov dword [loc_1001DC58], 0x15888
xor esi, esi
;push loc_1001DC50
PUSH32 loc_1001DC50
mov [loc_1001DC60], si
mov eax, [loc_1001DC3C]
mov word [loc_1001DC52], 0x2
mov word [loc_1001DC5C], 0x4
mov word [loc_1001DC5E], 0x10
;push eax
PUSH32 eax
mov eax, [eax]
;call dword [eax+0x38]
mov r9d, [eax+0x38]
CALL r9
mov [loc_1001DC60], si
;lea ecx, [esp+0x4]
lea ecx, [r11d+0x4]
;push ecx
PUSH32 ecx
mov edx, [loc_1001DC3C]
;push 0x12
PUSH32 0x12
;push loc_1001DC50
PUSH32 loc_1001DC50
;push edx
PUSH32 edx
mov eax, [edx]
;call dword [eax+0x14]
mov r9d, [eax+0x14]
CALL r9
test eax, eax
jz short loc_1000234A
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_1000234A:
;mov dword [esp+0x20], 0x5622
mov dword [r11d+0x20], 0x5622
;mov dword [esp+0x24], 0x15888
mov dword [r11d+0x24], 0x15888
;mov word [esp+0x1c], 0x1
mov word [r11d+0x1c], 0x1
;mov dword [esp+0x8], 0x14
mov dword [r11d+0x8], 0x14
;mov dword [esp+0xc], 0x40e0
mov dword [r11d+0xc], 0x40e0
;mov dword [esp+0x10], 0x1000
mov dword [r11d+0x10], 0x1000
xor eax, eax
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
;mov [esp+0x2c], ax
mov [r11d+0x2c], ax
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x18], ecx
mov [r11d+0x18], ecx
;push eax
PUSH32 eax
;lea edx, [esp+0xc]
lea edx, [r11d+0xc]
;push loc_1001DC64
PUSH32 loc_1001DC64
;push edx
PUSH32 edx
mov eax, [loc_1001E890]
;mov word [esp+0x2a], 0x2
mov word [r11d+0x2a], 0x2
;mov word [esp+0x34], 0x4
mov word [r11d+0x34], 0x4
;mov word [esp+0x36], 0x10
mov word [r11d+0x36], 0x10
;push eax
PUSH32 eax
mov esi, [eax]
;call dword [esi+0xc]
mov r9d, [esi+0xc]
CALL r9
test eax, eax
jz short loc_100023C5
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_100023C5:
;push loc_1001E070
PUSH32 loc_1001E070
mov eax, [loc_1001DC64]
mov dword [loc_1001E070], 0x14
;push eax
PUSH32 eax
mov esi, [eax]
;call dword [esi+0xc]
mov r9d, [esi+0xc]
CALL r9
test eax, eax
jz short loc_100023ED
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_100023ED:
;lea eax, [esp+0x4]
lea eax, [r11d+0x4]
mov ecx, [loc_1001DC64]
;push eax
PUSH32 eax
;push 0x12
PUSH32 0x12
;push loc_1001ED50
PUSH32 loc_1001ED50
mov eax, [ecx]
;push ecx
PUSH32 ecx
;call dword [eax+0x14]
mov r9d, [eax+0x14]
CALL r9
test eax, eax
jz short loc_10002413
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_10002413:
;push loc_1001DC40
PUSH32 loc_1001DC40
mov eax, [loc_1001DC64]
;push eax
PUSH32 eax
mov esi, [eax]
;call dword [esi+0x20]
mov r9d, [esi+0x20]
CALL r9
test eax, eax
jz short loc_10002431
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_10002431:
cmp dword [loc_1001B2B4], 0x1
jge short loc_10002444
mov dword [loc_1001B2B4], 0x400
loc_10002444:
mov eax, 0x1000
xor esi, esi
cdq
idiv dword [loc_1001B2B4]
mov [loc_1001B2F4], eax
dec eax
test eax, eax
jle short loc_1000246C
loc_1000245C:
inc esi
;call loc_10002570
CALL loc_10002570
mov eax, [loc_1001B2F4]
dec eax
cmp eax, esi
jg short loc_1000245C
loc_1000246C:
;lea eax, [esp+0x34]
lea eax, [r11d+0x34]
;push 0x8
PUSH32 0x8
;push eax
PUSH32 eax
;call timeGetDevCaps
CALL timeGetDevCaps
test eax, eax
jz short loc_10002487
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_10002487:
;push 0xa
PUSH32 0xa
;call timeBeginPeriod
CALL timeBeginPeriod
test eax, eax
jz short loc_1000249D
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_1000249D:
mov eax, [loc_1001B2B0]
lea ecx, [eax+eax*4]
lea edx, [ecx+ecx*4]
mov ecx, 0x5622
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
lea eax, [edx+edx*4]
;push loc_100026B0
PUSH32 loc_100026B0
;push 0x1
PUSH32 0x1
lea eax, [eax*8+0x2b11]
cdq
idiv ecx
;push eax
PUSH32 eax
mov [loc_1001B2E8], eax
;call timeSetEvent
CALL timeSetEvent
mov [loc_1001E894], eax
test eax, eax
jnz short loc_100024E4
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x98
add r11d, 0x98
;ret
RET
loc_100024E4:
;push 0x1
PUSH32 0x1
mov eax, [loc_1001DC64]
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push eax
PUSH32 eax
mov esi, [eax]
;call dword [esi+0x30]
mov r9d, [esi+0x30]
CALL r9
;pop esi
POP32 esi
cmp eax, 0x1
sbb eax, eax
;add esp, 0x98
add r11d, 0x98
neg eax
;ret
RET
align 16
SynthesizerGetDirectSound:
loc_10002510:
mov eax, [loc_1001E890]
;ret
RET
align 16
loc_10002520:
;sub esp, 0x64
sub r11d, 0x64
mov eax, [loc_1001E894]
;push esi
;push edi
;push eax
PUSH32 esi, edi, eax
;call timeKillEvent
CALL timeKillEvent
;push 0xa
PUSH32 0xa
;call timeEndPeriod
CALL timeEndPeriod
mov edi, timeGetTime
;call edi
mov r9d, edi
CALL r9
lea esi, [eax+0x3e8]
loc_10002547:
;call edi
mov r9d, edi
CALL r9
cmp eax, esi
jb short loc_10002547
; remove useless call to sprintf
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x64
add r11d, 0x64
;ret
RET
align 16
loc_10002570:
;sub esp, 0x10
sub r11d, 0x10
;lea eax, [esp]
lea eax, [r11d]
;push ebx
PUSH32 ebx
;lea ecx, [esp+0x8]
lea ecx, [r11d+0x8]
;push esi
PUSH32 esi
;lea edx, [esp+0x10]
lea edx, [r11d+0x10]
;push edi
PUSH32 edi
;push 0x0
PUSH32 0x0
;push eax
PUSH32 eax
;lea eax, [esp+0x20]
lea eax, [r11d+0x20]
;push ecx
;push edx
PUSH32 ecx, edx
mov ecx, [loc_1001B2B4]
;push eax
PUSH32 eax
mov edx, [loc_1001B2F0]
;push ecx
PUSH32 ecx
mov eax, [loc_1001DC64]
mov ebx, [eax]
;push edx
;push eax
PUSH32 edx, eax
;call dword [ebx+0x2c]
mov r9d, [ebx+0x2c]
CALL r9
test eax, eax
jnz near loc_100026A2
mov eax, [loc_1001B2B4]
;cmp [esp+0x14], eax
cmp [r11d+0x14], eax
ja near loc_100026A2
;cmp [esp+0xc], eax
cmp [r11d+0xc], eax
ja near loc_100026A2
add [loc_1001B2F0], eax
mov eax, [loc_1001E078]
cmp [loc_1001B2F0], eax
jb short loc_100025DF
sub [loc_1001B2F0], eax
loc_100025DF:
mov esi, loc_1001DC70
;call loc_10001D80
CALL loc_10001D80
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
shr ecx, 0x1
test ecx, ecx
jz short loc_10002607
loc_100025F8:
mov dx, [esi]
add esi, 0x2
mov [eax], dx
add eax, 0x2
dec ecx
jnz short loc_100025F8
loc_10002607:
;cmp dword [esp+0x10], 0x0
cmp dword [r11d+0x10], 0x0
jz short loc_1000262C
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
shr ecx, 0x1
test ecx, ecx
jz short loc_1000262C
loc_1000261D:
mov dx, [esi]
add esi, 0x2
mov [eax], dx
add eax, 0x2
dec ecx
jnz short loc_1000261D
loc_1000262C:
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push eax
PUSH32 eax
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;push ecx
;push edx
PUSH32 ecx, edx
mov ecx, [loc_1001DC64]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [ecx]
;call dword [eax+0x4c]
mov r9d, [eax+0x4c]
CALL r9
cmp dword [loc_1001B2E0], 0x0
jz short loc_100026A2
mov ebx, 0x2d57
cmp [loc_1001B2DC], ebx
jg short loc_10002698
mov esi, 0x2d58
xor edi, edi
loc_10002669:
mov eax, [loc_1001E898]
;push eax
PUSH32 eax
;call dword [loc_1001B2E0]
mov r9d, [loc_1001B2E0]
CALL r9
;add esp, 0x4
add r11d, 0x4
test eax, eax
jle short loc_10002684
add [loc_1001B2DC], eax
jmp short loc_10002690
loc_10002684:
mov [loc_1001B2DC], esi
mov [loc_1001B2E0], edi
loc_10002690:
cmp [loc_1001B2DC], ebx
jle short loc_10002669
loc_10002698:
sub dword [loc_1001B2DC], 0x2d57
loc_100026A2:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x10
add r11d, 0x10
;ret
RET
align 16
loc_100026B0:
;sub esp, 0x8
sub r11d, 0x8
mov edx, [loc_1001DC64]
;lea eax, [esp+0x4]
lea eax, [r11d+0x4]
;lea ecx, [esp]
lea ecx, [r11d]
;push eax
;push ecx
;push edx
PUSH32 eax, ecx, edx
mov eax, [edx]
;call dword [eax+0x10]
mov r9d, [eax+0x10]
CALL r9
test eax, eax
jnz near loc_10002729
mov ecx, [loc_1001B2F0]
;sub ecx, [esp]
sub ecx, [r11d]
jns short loc_100026DF
add ecx, [loc_1001E078]
loc_100026DF:
mov eax, [loc_1001B2E8]
sub edx, edx
imul eax, ecx
mov ecx, [loc_1001B2F4]
dec ecx
imul ecx, [loc_1001B2B4]
div ecx
cmp eax, 0x1
jae short loc_10002703
mov eax, 0x1
loc_10002703:
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push loc_100026B0
PUSH32 loc_100026B0
;push 0x1
PUSH32 0x1
;push eax
PUSH32 eax
;call timeSetEvent
CALL timeSetEvent
mov [loc_1001E894], eax
test eax, eax
jz short loc_10002729
;call loc_10002570
CALL loc_10002570
inc dword [loc_1001B2EC]
loc_10002729:
;add esp, 0x8
add r11d, 0x8
;ret 0x14
RET 20
align 16
loc_10002730:
;sub esp, 0x4
sub r11d, 0x4
mov eax, [loc_1001B2B0]
;push esi
PUSH32 esi
xor si, si
test eax, eax
jle short loc_10002760
mov ecx, loc_1001DC70
loc_10002745:
mov dx, [ecx]
test dx, dx
jge short loc_10002750
neg dx
loc_10002750:
cmp si, dx
jge short loc_10002758
mov si, dx
loc_10002758:
add ecx, 0x2
dec eax
jnz short loc_10002745
jmp short loc_10002765
loc_10002760:
;mov dx, [esp+0x6]
mov dx, [r11d+0x6]
loc_10002765:
movsx ecx, dx
mov eax, [loc_1001B2B8]
sub ecx, eax
sar ecx, 0x4
add eax, ecx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
movsx eax, ax
;add esp, 0x4
add r11d, 0x4
mov [loc_1001B2B8], eax
mov [loc_1001B2BC], eax
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
SynthesizerVolume:
loc_10002790:
;push ebx
;push esi
PUSH32 ebx, esi
xor si, si
;mov bl, [esp+0xc]
mov bl, [r11d+0xc]
loc_10002799:
;push ebx
PUSH32 ebx
mov eax, [loc_1001B2A4]
;push 0x7
PUSH32 0x7
;push esi
PUSH32 esi
inc si
;push eax
PUSH32 eax
;call loc_10004EA0
CALL loc_10004EA0
;add esp, 0x10
add r11d, 0x10
cmp si, 0xf
jle short loc_10002799
;pop esi
;pop ebx
POP32 ebx, esi
;ret 0x4
RET 4
align 16
SynthesizerTrackVolume:
loc_100027C0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
PUSH32 eax
mov edx, [loc_1001B2A4]
;push 0x7
PUSH32 0x7
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10004EA0
CALL loc_10004EA0
;add esp, 0x10
add r11d, 0x10
;ret 0x8
RET 8
align 16
SynthesizerPan:
loc_100027E0:
;push ebx
;push esi
PUSH32 ebx, esi
xor si, si
;mov bl, [esp+0xc]
mov bl, [r11d+0xc]
loc_100027E9:
;push ebx
PUSH32 ebx
mov eax, [loc_1001B2A4]
;push 0xa
PUSH32 0xa
;push esi
PUSH32 esi
inc si
;push eax
PUSH32 eax
;call loc_10004EA0
CALL loc_10004EA0
;add esp, 0x10
add r11d, 0x10
cmp si, 0xf
jle short loc_100027E9
;pop esi
;pop ebx
POP32 ebx, esi
;ret 0x4
RET 4
align 16
SynthesizerTrackPan:
loc_10002810:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
PUSH32 eax
mov edx, [loc_1001B2A4]
;push 0xa
PUSH32 0xa
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10004EA0
CALL loc_10004EA0
;add esp, 0x10
add r11d, 0x10
;ret 0x8
RET 8
align 16
loc_10002830:
xor eax, eax ; remove useless calculation
;ret
RET
align 16
loc_10002900:
jmp DirectSoundCreate
align 16
loc_10002910:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;push 0x240fc
PUSH32 0x240fc
;push 0x40
PUSH32 0x40
mov edi, GlobalAlloc
;call edi
mov r9d, edi
CALL r9
mov esi, eax
;mov eax, [esp+0x38]
mov eax, [r11d+0x38]
test esi, esi
mov [eax], esi
jnz short loc_10002937
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10002937:
;mov ebx, [esp+0x10]
mov ebx, [r11d+0x10]
;mov eax, [esp+0x3c]
mov eax, [r11d+0x3c]
;push eax
PUSH32 eax
lea ecx, [esi+0x18]
;mov ax, [esp+0x30]
mov ax, [r11d+0x30]
;push ecx
PUSH32 ecx
;mov cx, [esp+0x30]
mov cx, [r11d+0x30]
;mov edx, [esp+0x38]
mov edx, [r11d+0x38]
;push edx
PUSH32 edx
mov [esi+0x14], ebx
;mov edx, [esp+0x30]
mov edx, [r11d+0x30]
;push eax
PUSH32 eax
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x30]
mov ecx, [r11d+0x30]
;push edx
PUSH32 edx
;mov edx, [esp+0x30]
mov edx, [r11d+0x30]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [ebx+0x4a2]
;mov ecx, [esp+0x34]
mov ecx, [r11d+0x34]
;push esi
PUSH32 esi
;push loc_100042D0
PUSH32 loc_100042D0
;push edx
;push eax
PUSH32 edx, eax
lea edx, [ebx+0x2]
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10015F90
CALL loc_10015F90
;add esp, 0x38
add r11d, 0x38
test eax, eax
jnz near loc_10002B01
;push esi
PUSH32 esi
;call loc_10003300
CALL loc_10003300
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_10003350
CALL loc_10003350
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_10003410
CALL loc_10003410
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_100034D0
CALL loc_100034D0
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_10003560
CALL loc_10003560
mov byte [esi+0x2407c], 0x0
mov byte [esi+0x2407d], 0x0
mov dword [esi+0x2407e], 0x5622
;add esp, 0x4
add r11d, 0x4
mov dword [esi+0x24082], 0x0
;push esi
PUSH32 esi
;call loc_100035F0
CALL loc_100035F0
;add esp, 0x4
add r11d, 0x4
;push 0x7e2
PUSH32 0x7e2
;push 0x0
PUSH32 0x0
;call edi
mov r9d, edi
CALL r9
mov [esi+0x240a6], eax
test eax, eax
jnz short loc_10002A06
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10002A06:
;push eax
;push esi
PUSH32 eax, esi
;call loc_100068D0
CALL loc_100068D0
;add esp, 0x8
add r11d, 0x8
;push 0x4670
PUSH32 0x4670
;push 0x0
PUSH32 0x0
;call edi
mov r9d, edi
CALL r9
mov [esi+0x240aa], eax
test eax, eax
jnz short loc_10002A2C
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10002A2C:
;push eax
;push esi
PUSH32 eax, esi
;call loc_100063E0
CALL loc_100063E0
mov ax, [ebx+0x49c]
;add esp, 0x8
add r11d, 0x8
mov [esi+0x240d4], ax
movsx eax, word [ebx+0x49c]
mov ecx, eax
lea edx, [eax+eax*4]
lea eax, [edx+edx*4]
lea eax, [eax+eax*8]
add eax, ecx
shl eax, 0x3
sub eax, ecx
lea eax, [eax+eax*4]
sub eax, ecx
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
;call edi
mov r9d, edi
CALL r9
mov [esi+0x240d8], eax
test eax, eax
jnz short loc_10002A7A
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10002A7A:
movsx edx, word [esi+0x240d4]
mov ecx, edx
lea ebx, [edx+edx*4]
lea edx, [ebx+ebx*4]
lea edx, [edx+edx*8]
add edx, ecx
shl edx, 0x3
sub edx, ecx
lea edx, [edx+edx*4]
sub edx, ecx
add edx, eax
;mov ax, [esp+0x34]
mov ax, [r11d+0x34]
sub edx, 0x234a
mov [esi+0x240dc], edx
movsx ecx, ax
mov [esi+0x240f0], ax
mov eax, ecx
shl ecx, 0x3
sub ecx, eax
shl ecx, 0x3
lea ecx, [eax+ecx*8]
add ecx, ecx
;push ecx
PUSH32 ecx
;push 0x0
PUSH32 0x0
;call edi
mov r9d, edi
CALL r9
mov [esi+0x240f4], eax
test eax, eax
jnz short loc_10002ADC
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10002ADC:
movsx ecx, word [esi+0x240f0]
mov edx, ecx
shl ecx, 0x3
sub ecx, edx
shl ecx, 0x3
lea edx, [edx+ecx*8]
lea ecx, [eax+edx*2]
xor eax, eax
sub ecx, 0x382
mov [esi+0x240f8], ecx
loc_10002B01:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10002B10:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
test esi, esi
jz near loc_10002B7D
;push esi
PUSH32 esi
;call loc_10002D00
CALL loc_10002D00
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x18]
;push eax
PUSH32 eax
;call loc_10016190
CALL loc_10016190
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_100036E0
CALL loc_100036E0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x240a6]
test eax, eax
jz short loc_10002B4D
;push eax
PUSH32 eax
mov edi, GlobalFree
;call edi
mov r9d, edi
CALL r9
jmp short loc_10002B53
loc_10002B4D:
mov edi, GlobalFree
loc_10002B53:
mov eax, [esi+0x240aa]
test eax, eax
jz short loc_10002B60
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
loc_10002B60:
mov eax, [esi+0x240d8]
test eax, eax
jz short loc_10002B6D
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
loc_10002B6D:
mov eax, [esi+0x240f4]
test eax, eax
jz short loc_10002B7A
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
loc_10002B7A:
;push esi
PUSH32 esi
;call edi
mov r9d, edi
CALL r9
loc_10002B7D:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_10002B80:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
;push esi
PUSH32 edi, ebp, esi
;call loc_10002FC0
CALL loc_10002FC0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x14]
mov cl, [eax+0x1]
mov [esi+0x2407c], cl
mov cl, [eax+0x498]
mov [esi+0x2407d], cl
mov dl, [eax+0x499]
dec dl
cmp dl, 0x1
sbb dl, dl
neg dl
mov [esi+0x60], dl
mov al, [eax+0x499]
mov edx, [esi+0x18]
mov word [esi+0x62], 0xffff
sub al, 0x2
cmp al, 0x1
sbb al, al
neg al
mov [esi+0x61], al
cmp cl, 0x1
sbb edi, edi
mov eax, [edx]
add di, 0x2
mov ebx, [eax+0xc]
mov [esi+0x2407e], ebx
mov ebx, GlobalAlloc
mov eax, [eax+0x10]
mov [esi+0x24082], eax
add eax, eax
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
;call ebx
mov r9d, ebx
CALL r9
mov [esi+0x24086], eax
test eax, eax
jnz short loc_10002C10
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002C10:
mov ebp, [esi+0x24082]
shl ebp, 0x2
;push ebp
PUSH32 ebp
;push 0x0
PUSH32 0x0
;call ebx
mov r9d, ebx
CALL r9
mov [esi+0x2408a], eax
test eax, eax
jnz short loc_10002C2F
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002C2F:
;push ebp
PUSH32 ebp
;push 0x0
PUSH32 0x0
;call ebx
mov r9d, ebx
CALL r9
mov [esi+0x2408e], eax
test eax, eax
jnz short loc_10002C45
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002C45:
mov eax, [esi+0x24082]
movsx edi, di
imul eax, edi
shl eax, 0x2
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
;call ebx
mov r9d, ebx
CALL r9
mov [esi+0x24092], eax
test eax, eax
jnz short loc_10002C6A
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002C6A:
mov eax, [esi+0x24082]
lea ebp, [eax*2+0x8]
;push ebp
PUSH32 ebp
;push 0x0
PUSH32 0x0
;call ebx
mov r9d, ebx
CALL r9
mov [esi+0x2409a], eax
test eax, eax
jnz short loc_10002C8D
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002C8D:
;push ebp
PUSH32 ebp
;push 0x0
PUSH32 0x0
;call ebx
mov r9d, ebx
CALL r9
mov [esi+0x2409e], eax
test eax, eax
jnz short loc_10002CA3
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002CA3:
mov eax, [esi+0x24082]
add eax, 0x4
imul eax, edi
add eax, eax
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
;call ebx
mov r9d, ebx
CALL r9
mov [esi+0x240a2], eax
test eax, eax
jnz short loc_10002CC7
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002CC7:
xor di, di
;push esi
PUSH32 esi
;call loc_100033A0
CALL loc_100033A0
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_10003460
CALL loc_10003460
;add esp, 0x4
add r11d, 0x4
loc_10002CDC:
;push 0x1
PUSH32 0x1
;push edi
PUSH32 edi
inc di
;push esi
PUSH32 esi
;call loc_10002DD0
CALL loc_10002DD0
;add esp, 0xc
add r11d, 0xc
cmp di, 0x10
jl short loc_10002CDC
mov al, 0x1
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10002D00:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push esi
PUSH32 esi
;call loc_10002FC0
CALL loc_10002FC0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x24086]
test eax, eax
jz short loc_10002D2E
;push eax
PUSH32 eax
mov edi, GlobalFree
;call edi
mov r9d, edi
CALL r9
mov dword [esi+0x24086], 0x0
jmp short loc_10002D34
loc_10002D2E:
mov edi, GlobalFree
loc_10002D34:
mov eax, [esi+0x2408a]
test eax, eax
jz short loc_10002D4B
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
mov dword [esi+0x2408a], 0x0
loc_10002D4B:
mov eax, [esi+0x2408e]
test eax, eax
jz short loc_10002D62
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
mov dword [esi+0x2408e], 0x0
loc_10002D62:
mov eax, [esi+0x24092]
test eax, eax
jz short loc_10002D79
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
mov dword [esi+0x24092], 0x0
loc_10002D79:
mov eax, [esi+0x2409a]
test eax, eax
jz short loc_10002D90
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
mov dword [esi+0x2409a], 0x0
loc_10002D90:
mov eax, [esi+0x2409e]
test eax, eax
jz short loc_10002DA7
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
mov dword [esi+0x2409e], 0x0
loc_10002DA7:
mov eax, [esi+0x240a2]
test eax, eax
jz short loc_10002DBE
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
mov dword [esi+0x240a2], 0x0
loc_10002DBE:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10002DD0:
;mov dx, [esp+0x8]
mov dx, [r11d+0x8]
;push ebx
PUSH32 ebx
movsx ebx, dx
;push esi
;push edi
;push ebp
PUSH32 esi, edi, ebp
lea eax, [ebx*8]
sub eax, ebx
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
lea ebp, [eax+eax*4]
mov ecx, [edi+0x14]
lea ebx, [edi+ebx*4+0x20]
lea esi, [ecx+ebp*2+0x22]
cmp byte [esi], 0x0
jz near loc_10002ECD
mov eax, [edi+0x18]
cmp byte [edi+0x61], 0x0
mov ebp, [eax]
jz short loc_10002E0F
and byte [esi+0x22], 0x80
loc_10002E0F:
cmp byte [edi+0x60], 0x0
jnz short loc_10002E27
cmp byte [edi+0x61], 0x0
jz short loc_10002E49
cmp dx, 0x9
jz short loc_10002E43
cmp [edi+0x62], dx
jnz short loc_10002E49
loc_10002E27:
cmp dx, 0x9
jz short loc_10002E43
cmp byte [edi+0x61], 0x0
jz short loc_10002E39
cmp [edi+0x62], dx
jz short loc_10002E43
loc_10002E39:
mov ax, [ebp+0x14]
mov [esi+0x22], ax
jmp short loc_10002E49
loc_10002E43:
mov word [esi+0x22], 0x7f
loc_10002E49:
mov ax, [esi+0x22]
;push eax
;push ebp
PUSH32 eax, ebp
;call loc_10005F90
CALL loc_10005F90
;add esp, 0x8
add r11d, 0x8
test ax, ax
jge short loc_10002E6E
cmp byte [edi+0x61], 0x0
jz short loc_10002E8B
mov ax, [ebp+0x14]
mov [esi+0x22], ax
mov ax, [ebp+0x16]
loc_10002E6E:
mov dx, [esi+0x44]
cmp ax, 0x7f
jnz short loc_10002E96
mov ax, [ebp+0x16]
test ax, ax
jge short loc_10002E84
xor ax, ax
loc_10002E84:
add dx, 0x80
jmp short loc_10002EAD
loc_10002E8B:
;pop ebp
POP32 ebp
mov dword [ebx], 0x0
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10002E96:
cmp ax, 0x7e
jnz short loc_10002EAD
mov ax, [ebp+0x16]
test ax, ax
jge short loc_10002EA8
xor ax, ax
loc_10002EA8:
add dx, 0x100
loc_10002EAD:
mov cl, [edi+0x60]
or cl, [edi+0x61]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;push ecx
;push edx
;push eax
;push ebx
PUSH32 ecx, edx, eax, ebx
mov eax, [edi+0x18]
;push eax
PUSH32 eax
;call loc_10016280
CALL loc_10016280
;add esp, 0x18
add r11d, 0x18
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10002ECD:
;pop ebp
POP32 ebp
mov dword [ebx], 0x0
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10002EE0:
;sub esp, 0x8
sub r11d, 0x8
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push edi
;push ebp
PUSH32 edi, ebp
mov eax, [esi+0x18]
mov eax, [eax+0x4]
mov ecx, [eax]
test ecx, ecx
jz short loc_10002F15
mov eax, [eax+0x4]
shl eax, 0x2
lea edx, [eax+eax*4]
lea eax, [edx+edx*4]
sub edx, edx
div ecx
cmp eax, 0x4b
jbe short loc_10002F15
;push esi
PUSH32 esi
;call loc_10002FC0
CALL loc_10002FC0
;add esp, 0x4
add r11d, 0x4
loc_10002F15:
;call timeGetTime
CALL timeGetTime
mov edi, [esi+0x14]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
mov ax, [edi+0x44]
;mov ebx, [esp+0x20]
mov ebx, [r11d+0x20]
mov cx, [edi+0x66]
add edi, 0x22
xor bp, bp
;mov [esp+0x10], ax
mov [r11d+0x10], ax
;mov [esp+0x12], cx
mov [r11d+0x12], cx
cmp [ebx], bp
jle near loc_10002F77
loc_10002F43:
movsx eax, bp
inc bp
;push 0x1
PUSH32 0x1
mov cx, [ebx+eax*4+0x2]
lea eax, [ebx+eax*4]
mov [edi+0x22], cx
;push 0x0
PUSH32 0x0
mov ax, [eax+0x4]
;push esi
PUSH32 esi
mov [edi+0x44], ax
;call loc_10002DD0
CALL loc_10002DD0
;add esp, 0xc
add r11d, 0xc
;push esi
PUSH32 esi
;call loc_10003250
CALL loc_10003250
;add esp, 0x4
add r11d, 0x4
cmp [ebx], bp
jg near loc_10002F43
loc_10002F77:
;mov ax, [esp+0x10]
mov ax, [r11d+0x10]
;push 0x1
PUSH32 0x1
;mov cx, [esp+0x16]
mov cx, [r11d+0x16]
;push 0x0
PUSH32 0x0
mov [edi+0x22], ax
;push esi
PUSH32 esi
mov [edi+0x44], cx
;call loc_10002DD0
CALL loc_10002DD0
;add esp, 0xc
add r11d, 0xc
;push esi
PUSH32 esi
;call loc_10003250
CALL loc_10003250
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;add esp, 0x4
add r11d, 0x4
mov edx, [esi+0x18]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
cmp [edx+0x30], ecx
mov cl, 0x1
adc cl, 0xff
;add esp, 0x8
add r11d, 0x8
mov al, cl
;ret
RET
align 16
loc_10002FC0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push esi
PUSH32 edi, esi
;call loc_10003700
CALL loc_10003700
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_10003100
CALL loc_10003100
xor ax, ax
;add esp, 0x4
add r11d, 0x4
xor ecx, ecx
loc_10002FDE:
movsx edx, ax
inc ax
mov [esi+edx*4+0x20], ecx
cmp ax, 0x10
jl short loc_10002FDE
mov eax, [esi+0x18]
;push eax
PUSH32 eax
;call loc_10016220
CALL loc_10016220
xor ax, ax
;add esp, 0x4
add r11d, 0x4
loc_10002FFC:
xor cx, cx
xor edi, edi
movsx edx, ax
shl edx, 0x7
loc_10003007:
movsx ebx, cx
inc cx
add ebx, edx
cmp cx, 0x80
mov [esi+ebx*4+0x22026], edi
jl short loc_10003007
inc ax
cmp ax, 0x10
jl short loc_10002FFC
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10003030:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
mov ax, [esi+0x21822]
;push esi
PUSH32 esi
mov [esi+0x21824], ax
;call loc_10003700
CALL loc_10003700
xor cx, cx
;add esp, 0x4
add r11d, 0x4
loc_10003051:
xor dx, dx
xor edi, edi
movsx eax, cx
shl eax, 0x7
loc_1000305C:
movsx ebx, dx
inc dx
add ebx, eax
cmp dx, 0x80
mov [esi+ebx*4+0x22026], edi
jl short loc_1000305C
inc cx
cmp cx, 0x10
jl short loc_10003051
mov eax, [esi+0x18]
;push eax
PUSH32 eax
;call loc_10016E50
CALL loc_10016E50
;add esp, 0x4
add r11d, 0x4
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10003090:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
;mov di, [esp+0x14]
mov di, [r11d+0x14]
;push ebp
PUSH32 ebp
mov ebx, [esi+0x240cc]
test ebx, ebx
jz short loc_100030D9
loc_100030A7:
movsx ax, byte [ebx+0x2]
cmp ax, di
jnz short loc_100030CF
mov ebp, [ebx+0x2346]
;push ebx
;push esi
PUSH32 ebx, esi
;call loc_10003A00
CALL loc_10003A00
;add esp, 0x8
add r11d, 0x8
;push ebx
;push esi
PUSH32 ebx, esi
mov ebx, ebp
;call loc_10003910
CALL loc_10003910
;add esp, 0x8
add r11d, 0x8
jmp short loc_100030D5
loc_100030CF:
mov ebx, [ebx+0x2346]
loc_100030D5:
test ebx, ebx
jnz short loc_100030A7
loc_100030D9:
xor eax, eax
xor edx, edx
movsx ecx, di
shl ecx, 0x7
loc_100030E3:
movsx edi, ax
inc ax
add edi, ecx
cmp ax, 0x80
mov [esi+edi*4+0x22026], edx
jl short loc_100030E3
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10003100:
;push esi
;push edi
PUSH32 esi, edi
xor di, di
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
loc_10003109:
;push edi
;push esi
PUSH32 edi, esi
inc di
;call loc_10003170
CALL loc_10003170
;add esp, 0x8
add r11d, 0x8
cmp di, 0x10
jl short loc_10003109
xor edx, edx
lea edi, [esi+0x21826]
mov [esi+0x21822], dx
xor eax, eax
mov [esi+0x21824], dx
mov ecx, 0x200
;rep stosd
rep a32 stosd
mov [esi+0x24066], dx
lea eax, [esi+0x2406c]
mov [esi+0x2406a], dx
mov [esi+0x24068], dl
;pop edi
POP32 edi
mov [esi+0x24069], dl
mov [eax], edx
mov [eax+0x4], edx
mov [eax+0x8], edx
mov [eax+0xc], edx
mov [esi], edx
;pop esi
POP32 esi
;ret
RET
align 16
loc_10003170:
;movsx ecx, word [esp+0x8]
movsx ecx, word [r11d+0x8]
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
xor ebx, ebx
xor edx, edx
mov [esi+ecx+0x21682], bl
lea eax, [esi+ecx]
mov [esi+ecx+0x21692], bl
loc_10003191:
movsx edi, bx
inc bx
shl edi, 0x4
add edi, ecx
cmp bx, 0x2
mov [edi+esi+0x216a2], dl
jl short loc_10003191
xor edx, edx
mov ebx, 0x7f
mov [eax+0x216c2], dl
mov [eax+0x216d2], bl
mov byte [eax+0x216e2], 0xff
mov [eax+0x216f2], bl
mov [eax+0x21702], dl
mov [eax+0x21712], dl
mov byte [eax+0x21722], 0xff
mov byte [eax+0x21732], 0xff
mov [eax+0x21742], dl
mov [eax+0x21752], dl
mov [eax+0x21762], dl
mov [eax+0x21772], dl
mov [eax+0x21782], dl
mov [eax+0x21792], bl
mov [eax+0x217a2], bl
mov [eax+0x217b2], bl
mov ebx, 0x40
;pop edi
POP32 edi
mov [eax+0x217c2], dl
mov byte [eax+0x217d2], 0x1
mov word [esi+ecx*2+0x217e2], 0xffff
mov [eax+0x21802], bl
mov [eax+0x21812], bl
mov [esi+ecx*4+0x24026], edx
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_10003250:
;ret
RET
align 16
loc_10003260:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
PUSH32 edi, ebp
xor edi, edi
;push esi
PUSH32 esi
xor ebx, ebx
;call loc_10003100
CALL loc_10003100
;add esp, 0x4
add r11d, 0x4
mov ebp, [esi+0x14]
add ebp, 0x22
loc_1000327B:
xor al, al
cmp di, 0x9
jnz short loc_1000328D
cmp [esi+0x60], bl
jnz short loc_10003298
cmp [esi+0x61], bl
jnz short loc_10003298
loc_1000328D:
cmp [esi+0x62], di
jnz short loc_100032A7
cmp [esi+0x61], bl
jz short loc_100032B4
loc_10003298:
cmp word [ebp+0x22], 0x7f
jz short loc_100032D2
mov word [ebp+0x22], 0x7f
jmp short loc_100032CC
loc_100032A7:
cmp [esi+0x61], bl
jz short loc_100032B4
test byte [ebp+0x22], 0x7f
jz short loc_100032D2
jmp short loc_100032C8
loc_100032B4:
cmp [esi+0x60], bl
jz short loc_100032C1
cmp [ebp+0x22], bx
jz short loc_100032D2
jmp short loc_100032C8
loc_100032C1:
cmp word [ebp+0x22], 0x7f
jnz short loc_100032D2
loc_100032C8:
mov [ebp+0x22], bx
loc_100032CC:
mov [ebp+0x44], bx
mov al, 0x1
loc_100032D2:
test al, al
jz short loc_100032E5
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
;push edi
;push esi
PUSH32 eax, edi, esi
;call loc_10002DD0
CALL loc_10002DD0
;add esp, 0xc
add r11d, 0xc
loc_100032E5:
inc di
add ebp, 0x46
cmp di, 0x10
jl near loc_1000327B
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10003300:
;sub esp, 0x4
sub r11d, 0x4
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
PUSH32 edi
xor di, di
loc_1000330D:
fld qword [loc_10019008]
movsx ebx, di
inc di
lea eax, [ebx-0x40]
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;fild dword [esp+0xc]
fild dword [r11d+0xc]
fmul qword [loc_10019010]
;call _CIpow_asm
CALL _CIpow_asm
fmul qword [loc_10019018]
;call _ftol_asm
CALL _ftol_asm
cmp di, 0x80
mov [esi+ebx*4+0x64], eax
jl short loc_1000330D
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10003350:
;sub esp, 0x4
sub r11d, 0x4
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
PUSH32 edi
xor di, di
loc_1000335D:
fld qword [loc_10019008]
movsx ebx, di
inc di
lea eax, [ebx-0x40]
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;fild dword [esp+0xc]
fild dword [r11d+0xc]
fmul qword [loc_10019020]
;call _CIpow_asm
CALL _CIpow_asm
fmul qword [loc_10019018]
;call _ftol_asm
CALL _ftol_asm
cmp di, 0x80
mov [esi+ebx*4+0x264], eax
jl short loc_1000335D
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_100033A0:
;sub esp, 0x8
sub r11d, 0x8
;push ebx
;push esi
PUSH32 ebx, esi
xor bx, bx
;push edi
PUSH32 edi
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
fild dword [edi+0x2407e]
;fst qword [esp+0xc]
fst qword [r11d+0xc]
fld qword [loc_10019028]
loc_100033BD:
fld qword [loc_10019008]
movsx esi, bx
inc bx
lea eax, [esi-0x3c]
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;fild dword [esp+0xc]
fild dword [r11d+0xc]
fmul qword [loc_10019010]
fadd st0, st2
;call _CIpow_asm
CALL _CIpow_asm
fdiv st0, st2
fmul qword [loc_10019030]
fmul qword [loc_10019038]
;call _ftol_asm
CALL _ftol_asm
mov [edi+esi*2+0x464], ax
cmp bx, 0x80
jl short loc_100033BD
fstp st0
fstp st0
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_10003410:
;sub esp, 0x4
sub r11d, 0x4
;push esi
;push edi
PUSH32 esi, edi
xor edi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
loc_1000341B:
fld qword [loc_10019008]
lea eax, [edi-0x8000]
inc edi
;mov [esp+0x8], eax
mov [r11d+0x8], eax
;fild dword [esp+0x8]
fild dword [r11d+0x8]
fmul qword [loc_10019040]
;call _CIpow_asm
CALL _CIpow_asm
fmul qword [loc_10019048]
;call _ftol_asm
CALL _ftol_asm
mov [esi+edi*2+0x680], ax
cmp edi, 0x10000
jl short loc_1000341B
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10003460:
;sub esp, 0x8
sub r11d, 0x8
;push ebx
;push esi
PUSH32 ebx, esi
xor si, si
;push edi
PUSH32 edi
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
fild dword [edi+0x2407e]
;fst qword [esp+0xc]
fst qword [r11d+0xc]
loc_10003477:
fld qword [loc_10019008]
movsx ebx, si
inc si
lea eax, [ebx-0x3c]
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;fild dword [esp+0xc]
fild dword [r11d+0xc]
fmul qword [loc_10019010]
;call _CIpow_asm
CALL _CIpow_asm
fmul qword [loc_10019030]
fdivr st0, st1
fmul qword [loc_10019050]
fmul qword [loc_10019038]
;call _ftol_asm
CALL _ftol_asm
mov [edi+ebx*2+0x564], ax
cmp si, 0x80
jl short loc_10003477
fstp st0
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_100034D0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov word [eax+0x664], 0x1
add eax, 0x664
mov word [eax+0x2], 0x1
add eax, 0x2
mov word [eax+0x2], 0x3
add eax, 0x2
mov word [eax+0x2], 0x1
add eax, 0x2
mov word [eax+0x2], 0x1
add eax, 0x2
mov word [eax+0x2], 0x3
add eax, 0x2
mov word [eax+0x2], 0x7
add eax, 0x2
mov word [eax+0x2], 0x0
add eax, 0x2
mov word [eax+0x2], 0x0
add eax, 0x2
mov word [eax+0x2], 0x0
add eax, 0x2
mov word [eax+0x2], 0x0
add eax, 0x2
mov word [eax+0x2], 0x0
add eax, 0x2
mov word [eax+0x2], 0x0
add eax, 0x2
mov word [eax+0x2], 0x0
add eax, 0x2
mov word [eax+0x2], 0x0
;ret
RET
align 16
loc_10003560:
;sub esp, 0xc
sub r11d, 0xc
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
xor ebx, ebx
xor di, di
;push ebp
PUSH32 ebp
;mov esi, [esp+0x20]
mov esi, [r11d+0x20]
loc_10003570:
test di, di
jle short loc_10003596
movsx eax, di
;mov [esp+0x10], eax
mov [r11d+0x10], eax
;fild dword [esp+0x10]
fild dword [r11d+0x10]
fmul qword [loc_10019058]
fld qword [loc_10019028]
fsub st0, st1
fdivrp st1, st0
;fstp qword [esp+0x10]
fstp qword [r11d+0x10]
jmp short loc_1000359E
loc_10003596:
;mov [esp+0x10], ebx
mov [r11d+0x10], ebx
;mov [esp+0x14], ebx
mov [r11d+0x14], ebx
loc_1000359E:
;fld qword [esp+0x10]
fld qword [r11d+0x10]
;call _ftol_asm
CALL _ftol_asm
movsx ecx, di
inc di
lea ebp, [esi+ecx*4]
mov [ebp+0x20682], ax
movsx eax, ax
mov ecx, eax
shl eax, 0xf
sub eax, ecx
neg eax
;mov [esp+0x18], eax
mov [r11d+0x18], eax
;fild dword [esp+0x18]
fild dword [r11d+0x18]
;fadd qword [esp+0x10]
fadd qword [r11d+0x10]
;call _ftol_asm
CALL _ftol_asm
mov [ebp+0x20684], ax
cmp di, 0x400
jl near loc_10003570
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 16
loc_100035F0:
;sub esp, 0x4
sub r11d, 0x4
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
xor ebx, ebx
lea eax, [esi+0x240ae]
mov [eax], ebx
mov [eax+0x4], ebx
;push 0x24a
PUSH32 0x24a
;push ebx
PUSH32 ebx
mov [eax+0x8], ebx
mov byte [eax+0xc], 0x39
mov byte [eax+0xd], 0x7f
mov [eax+0xe], bl
mov [eax+0xf], bl
mov word [eax+0x10], 0x7fff
;call GlobalAlloc
CALL GlobalAlloc
mov [esi+0x240c0], eax
lea esi, [eax+0x8]
;push esi
PUSH32 esi
mov dword [eax], 0x73616d70
;push loc_1001B3F4
PUSH32 loc_1001B3F4
add esi, 0x28
mov dword [eax+0x4], 0x24a
;call loc_10006C10
CALL loc_10006C10
;add esp, 0x8
add r11d, 0x8
mov [esi-0x8], ebx
mov [esi-0x4], ebx
mov byte [esi], 0x39
mov eax, 0x100
mov [esi+0x1], bl
mov word [esi+0x2], 0x2
mov [esi+0x4], bl
add esi, 0x1a
fld qword [loc_10019068]
mov [esi-0x15], bl
mov dword [esi-0x14], 0xdc00
mov [esi-0x10], ebx
mov [esi-0xc], eax
mov [esi-0x8], ebx
mov [esi-0x4], eax
loc_10003689:
;mov [esp+0x8], ebx
mov [r11d+0x8], ebx
;fild dword [esp+0x8]
fild dword [r11d+0x8]
fsub st0, st1
fmul qword [loc_10019070]
;call _ftol_asm
CALL _ftol_asm
test ax, ax
jle short loc_100036AC
lea eax, [eax*2+0x8000]
jmp short loc_100036C6
loc_100036AC:
cmp ax, 0x8000
jnz short loc_100036B8
mov ax, 0x7fff
jmp short loc_100036C6
loc_100036B8:
mov cx, 0xc000
sub cx, ax
lea eax, [ecx*2]
loc_100036C6:
mov [esi], ax
add esi, 0x2
inc ebx
cmp ebx, 0x100
jl short loc_10003689
fstp st0
;pop esi
;pop ebx
POP32 ebx, esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_100036E0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov eax, [eax+0x240c0]
test eax, eax
jz short loc_100036F5
;push eax
PUSH32 eax
;call GlobalFree
CALL GlobalFree
loc_100036F5:
;ret
RET
align 16
loc_10003700:
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push ebx
;push esi
PUSH32 ebx, esi
xor edx, edx
;push edi
PUSH32 edi
mov esi, [ecx+0x240d8]
mov [ecx+0x240d6], dx
mov eax, [ecx+0x240dc]
mov [ecx+0x240c4], esi
mov [ecx+0x240c8], eax
mov ax, [ecx+0x240d4]
mov [ecx+0x240cc], edx
test ax, ax
mov [ecx+0x240d0], edx
lea edi, [eax-0x1]
jle short loc_10003788
xor ebx, ebx
loc_10003745:
test dx, dx
jle short loc_10003758
lea eax, [esi-0x234a]
mov [esi+0x2342], eax
jmp short loc_1000375E
loc_10003758:
mov [esi+0x2342], ebx
loc_1000375E:
cmp di, dx
jg short loc_1000376B
mov [esi+0x2346], ebx
jmp short loc_10003777
loc_1000376B:
lea eax, [esi+0x234a]
mov [esi+0x2346], eax
loc_10003777:
inc dx
add esi, 0x234a
cmp [ecx+0x240d4], dx
jg short loc_10003745
loc_10003788:
mov edi, [ecx+0x240f4]
mov eax, [ecx+0x240f8]
xor ebx, ebx
mov [ecx+0x240e0], edi
xor dx, dx
mov [ecx+0x240e4], eax
mov ax, [ecx+0x240f0]
mov [ecx+0x240e8], ebx
mov [ecx+0x240f2], bx
mov [ecx+0x240ec], ebx
test ax, ax
lea esi, [eax-0x1]
jle short loc_1000380A
loc_100037C7:
test dx, dx
jle short loc_100037DA
lea eax, [edi-0x382]
mov [edi+0x37a], eax
jmp short loc_100037E0
loc_100037DA:
mov [edi+0x37a], ebx
loc_100037E0:
cmp si, dx
jg short loc_100037ED
mov [edi+0x37e], ebx
jmp short loc_100037F9
loc_100037ED:
lea eax, [edi+0x382]
mov [edi+0x37e], eax
loc_100037F9:
inc dx
add edi, 0x382
cmp [ecx+0x240f0], dx
jg short loc_100037C7
loc_1000380A:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10003810:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov eax, [esi+0x374]
test eax, eax
jz short loc_10003835
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
;push 0x0
PUSH32 0x0
;push eax
PUSH32 eax
mov eax, [edi+0x18]
;push eax
PUSH32 eax
;call loc_10006C30
CALL loc_10006C30
;add esp, 0xc
add r11d, 0xc
jmp short loc_10003839
loc_10003835:
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
loc_10003839:
;push 0x0
PUSH32 0x0
mov eax, [esi+0x37a]
;push eax
PUSH32 eax
mov ecx, [edi+0x18]
;push ecx
PUSH32 ecx
;call loc_10006C30
CALL loc_10006C30
;add esp, 0xc
add r11d, 0xc
mov ecx, [esi+0x8]
mov edx, [edi+0x18]
;push 0x0
PUSH32 0x0
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10006C90
CALL loc_10006C90
;add esp, 0xc
add r11d, 0xc
;push esi
;push edi
PUSH32 esi, edi
;call loc_10003A00
CALL loc_10003A00
;add esp, 0x8
add r11d, 0x8
;push esi
;push edi
PUSH32 esi, edi
;call loc_10003910
CALL loc_10003910
;add esp, 0x8
add r11d, 0x8
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10003880:
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
mov eax, [edx+0x240c4]
test eax, eax
jnz short loc_10003891
xor eax, eax
;ret
RET
loc_10003891:
mov ecx, [eax+0x2346]
cmp [edx+0x240c8], eax
mov [edx+0x240c4], ecx
jnz short loc_100038AF
mov dword [edx+0x240c8], 0x0
loc_100038AF:
mov ecx, [eax+0x2346]
test ecx, ecx
jz short loc_100038C3
mov dword [ecx+0x2342], 0x0
loc_100038C3:
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
mov [eax+0x8], ecx
mov dword [eax+0x2336], 0x0
mov dword [eax+0x2346], 0x0
mov ecx, [edx+0x240d0]
mov [eax+0x2342], ecx
test ecx, ecx
jz short loc_100038F6
mov [ecx+0x2346], eax
jmp short loc_100038FC
loc_100038F6:
mov [edx+0x240cc], eax
loc_100038FC:
inc word [edx+0x240d6]
mov [edx+0x240d0], eax
;ret
RET
align 16
loc_10003910:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov edi, [esi+0x2342]
lea edx, [esi+0x2346]
test edi, edi
mov eax, [edx]
jz short loc_10003934
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
mov [edi+0x2346], eax
jmp short loc_1000393E
loc_10003934:
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
mov [ecx+0x240cc], eax
loc_1000393E:
cmp [ecx+0x240d0], esi
jnz short loc_1000394C
mov [ecx+0x240d0], edi
loc_1000394C:
mov eax, [edx]
test eax, eax
jz short loc_10003958
mov [eax+0x2342], edi
loc_10003958:
mov dword [edx], 0x0
mov eax, [ecx+0x240c8]
mov [esi+0x2342], eax
test eax, eax
jz short loc_10003976
mov [eax+0x2346], esi
jmp short loc_1000397C
loc_10003976:
mov [ecx+0x240c4], esi
loc_1000397C:
dec word [ecx+0x240d6]
;pop edi
POP32 edi
mov [ecx+0x240c8], esi
;pop esi
POP32 esi
;ret
RET
align 16
loc_10003990:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
mov eax, [esi+0x8]
;push eax
;push edi
PUSH32 eax, edi
;call loc_10003A70
CALL loc_10003A70
;add esp, 0x8
add r11d, 0x8
test eax, eax
jnz short loc_100039B8
mov eax, [esi+0x8]
;push eax
;push edi
PUSH32 eax, edi
;call loc_10003AA0
CALL loc_10003AA0
;add esp, 0x8
add r11d, 0x8
loc_100039B8:
mov [esi+0x2336], eax
mov ecx, [eax+0x376]
mov [esi+0x233a], ecx
test ecx, ecx
mov dword [esi+0x233e], 0x0
jz short loc_100039E7
;pop edi
POP32 edi
mov [ecx+0x233e], esi
mov [eax+0x376], esi
;pop esi
POP32 esi
;ret
RET
loc_100039E7:
;pop edi
POP32 edi
mov [eax+0x372], esi
mov [eax+0x376], esi
;pop esi
POP32 esi
;ret
RET
align 16
loc_10003A00:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;push esi
;push edi
PUSH32 esi, edi
mov edi, [edx+0x2336]
mov esi, [edx+0x233a]
lea ecx, [edx+0x233e]
test esi, esi
mov eax, [ecx]
jz short loc_10003A26
mov [esi+0x233e], eax
jmp short loc_10003A2C
loc_10003A26:
mov [edi+0x372], eax
loc_10003A2C:
cmp [edi+0x376], edx
jnz short loc_10003A3A
mov [edi+0x376], esi
loc_10003A3A:
mov eax, [ecx]
test eax, eax
jz short loc_10003A46
mov [eax+0x233a], esi
loc_10003A46:
mov dword [edx+0x2336], 0x0
cmp dword [edi+0x372], 0x0
jnz short loc_10003A67
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;push edi
;push eax
PUSH32 edi, eax
;call loc_10003B30
CALL loc_10003B30
;add esp, 0x8
add r11d, 0x8
loc_10003A67:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10003A70:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov eax, [eax+0x240e8]
test eax, eax
jz short loc_10003A91
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
loc_10003A82:
cmp [eax+0x8], ecx
jz short loc_10003A93
mov eax, [eax+0x37e]
test eax, eax
jnz short loc_10003A82
loc_10003A91:
xor eax, eax
loc_10003A93:
;ret
RET
align 16
loc_10003AA0:
;push esi
PUSH32 esi
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
mov eax, [esi+0x240e0]
test eax, eax
jnz short loc_10003AB3
xor eax, eax
;pop esi
POP32 esi
;ret
RET
loc_10003AB3:
mov ecx, [eax+0x37e]
cmp [esi+0x240e4], eax
mov [esi+0x240e0], ecx
jnz short loc_10003AD1
mov dword [esi+0x240e4], 0x0
loc_10003AD1:
mov ecx, [eax+0x37e]
test ecx, ecx
jz short loc_10003AE5
mov dword [ecx+0x37a], 0x0
loc_10003AE5:
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
xor edx, edx
mov [eax+0x8], ecx
mov [eax+0x372], edx
mov [eax+0x376], edx
mov [eax+0x37e], edx
mov ecx, [esi+0x240ec]
mov [eax+0x37a], ecx
test ecx, ecx
jz short loc_10003B18
mov [ecx+0x37e], eax
jmp short loc_10003B1E
loc_10003B18:
mov [esi+0x240e8], eax
loc_10003B1E:
inc word [esi+0x240f2]
mov [esi+0x240ec], eax
;pop esi
POP32 esi
;ret
RET
align 16
loc_10003B30:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov ecx, [esi+0x37a]
lea edx, [esi+0x37e]
test ecx, ecx
mov eax, [edx]
jz short loc_10003B54
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
mov [ecx+0x37e], eax
jmp short loc_10003B5E
loc_10003B54:
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
mov [edi+0x240e8], eax
loc_10003B5E:
cmp [edi+0x240ec], esi
jnz short loc_10003B6C
mov [edi+0x240ec], ecx
loc_10003B6C:
mov eax, [edx]
test eax, eax
jz short loc_10003B78
mov [eax+0x37a], ecx
loc_10003B78:
mov dword [edx], 0x0
mov eax, [edi+0x240e4]
mov [esi+0x37a], eax
test eax, eax
jz short loc_10003B96
mov [eax+0x37e], esi
jmp short loc_10003B9C
loc_10003B96:
mov [edi+0x240e0], esi
loc_10003B9C:
dec word [edi+0x240f2]
mov [edi+0x240e4], esi
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10003BB0:
;sub esp, 0xbc
sub r11d, 0xbc
;mov byte [esp+0x1], 0x0
mov byte [r11d+0x1], 0x0
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;call loc_1000700D
CALL loc_1000700D
movzx cx, byte [loc_1001B2C0]
and ax, cx
;mov [esp+0x1e], ax
mov [r11d+0x1e], ax
jz short loc_10003C12
;lea eax, [esp+0x60]
lea eax, [r11d+0x60]
;push eax
PUSH32 eax
;call loc_10006FB0
CALL loc_10006FB0
;mov [esp+0x18], ax
mov [r11d+0x18], ax
;lea eax, [esp+0x3c]
lea eax, [r11d+0x3c]
;add esp, 0x4
add r11d, 0x4
xor edx, edx ; fix treating address as signed number
;mov [esp+0x34], eax
mov [r11d+0x34], eax
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
sub eax, edx
sar eax, 0x1
test eax, eax
jz short loc_10003C12
;lea ecx, [esp+0x40]
lea ecx, [r11d+0x40]
add eax, eax
sub ecx, eax
;mov [esp+0x34], ecx
mov [r11d+0x34], ecx
loc_10003C12:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
mov ecx, [eax+0x24082]
inc dword [eax]
mov al, [eax+0x2407d]
;mov [esp+0x20], ecx
mov [r11d+0x20], ecx
;mov ecx, [esp+0xd0]
mov ecx, [r11d+0xd0]
;mov [esp+0x13], al
mov [r11d+0x13], al
mov edx, [ecx+0x14]
mov al, [ecx+0x2407c]
;mov [esp+0x30], edx
mov [r11d+0x30], edx
test al, al
jz short loc_10003C5B
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
cmp byte [eax+0x4a7], 0x0
jz short loc_10003C5B
;mov byte [esp+0x12], 0x1
mov byte [r11d+0x12], 0x1
jmp short loc_10003C60
loc_10003C5B:
;mov byte [esp+0x12], 0x0
mov byte [r11d+0x12], 0x0
loc_10003C60:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
mov esi, [eax+0x240e8]
test esi, esi
jz short loc_10003C8C
loc_10003C71:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;push esi
;push eax
PUSH32 esi, eax
;call loc_100087A0
CALL loc_100087A0
;add esp, 0x8
add r11d, 0x8
mov esi, [esi+0x37e]
test esi, esi
jnz short loc_10003C71
loc_10003C8C:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;mov esi, [esp+0x60]
mov esi, [r11d+0x60]
;mov edi, [esp+0x60]
mov edi, [r11d+0x60]
mov ecx, [eax+0x240cc]
;mov [esp+0x24], ecx
mov [r11d+0x24], ecx
test ecx, ecx
jz near loc_10004054
loc_10003CAD:
;mov ebx, [esp+0x24]
mov ebx, [r11d+0x24]
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
add ebx, 0x372
cmp byte [ebx], 0x0
jz short loc_10003CE0
mov ebx, [eax+0x2346]
;push eax
PUSH32 eax
;mov ecx, [esp+0xd4]
mov ecx, [r11d+0xd4]
;push ecx
PUSH32 ecx
;call loc_10003810
CALL loc_10003810
;mov [esp+0x2c], ebx
mov [r11d+0x2c], ebx
;add esp, 0x8
add r11d, 0x8
jmp loc_10004049
loc_10003CE0:
;mov ecx, [esp+0xd0]
mov ecx, [r11d+0xd0]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10007C20
CALL loc_10007C20
;mov ecx, [esp+0x2c]
mov ecx, [r11d+0x2c]
;mov edx, [esp+0xd8]
mov edx, [r11d+0xd8]
;mov eax, [esp+0x2c]
mov eax, [r11d+0x2c]
;add esp, 0x8
add r11d, 0x8
;push ecx
;push edx
PUSH32 ecx, edx
;call dword [eax+0x382]
mov r9d, [eax+0x382]
CALL r9
;mov edx, [esp+0xd8]
mov edx, [r11d+0xd8]
;add esp, 0x8
add r11d, 0x8
mov [ebx], al
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
mov ecx, [edx+0x24086]
mov esi, [edx+0x2408a]
mov edi, [edx+0x2408e]
mov ebx, [eax+0x2409a]
mov edx, [edx+0x24092]
mov ebp, [eax+0x2409e]
;mov [esp+0x2c], ebx
mov [r11d+0x2c], ebx
;mov [esp+0x28], ebp
mov [r11d+0x28], ebp
mov ebp, [eax+0x240a2]
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
mov bx, [eax+0x304]
jz short loc_10003D7B
mov ax, [eax+0x308]
;mov [esp+0x1a], ax
mov [r11d+0x1a], ax
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
mov ax, [eax+0x30a]
;mov [esp+0x1c], ax
mov [r11d+0x1c], ax
loc_10003D7B:
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz short loc_10003DA2
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
mov ax, [eax+0x2332]
;mov [esp+0x16], ax
mov [r11d+0x16], ax
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
mov ax, [eax+0x2334]
;mov [esp+0x18], ax
mov [r11d+0x18], ax
loc_10003DA2:
;cmp byte [esp+0x11], 0x0
cmp byte [r11d+0x11], 0x0
jz near loc_10003EF4
;cmp word [esp+0x1e], 0x0
cmp word [r11d+0x1e], 0x0
jz near loc_10003E57
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz near loc_10003E1D
;mov eax, [esp+0x28]
mov eax, [r11d+0x28]
;mov edx, [esp+0x2c]
mov edx, [r11d+0x2c]
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
;push eax
;push edx
;push ebp
PUSH32 eax, edx, ebp
jz short loc_10003DFF
;mov ebp, [esp+0x40]
mov ebp, [r11d+0x40]
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;mov edx, [esp+0x22]
mov edx, [r11d+0x22]
;push ebp
PUSH32 ebp
;mov ebp, [esp+0x2c]
mov ebp, [r11d+0x2c]
;push eax
PUSH32 eax
;mov eax, [esp+0x2e]
mov eax, [r11d+0x2e]
;push edx
PUSH32 edx
;mov edx, [esp+0x38]
mov edx, [r11d+0x38]
;push ebp
;push eax
;push ebx
;push edx
;push ecx
PUSH32 ebp, eax, ebx, edx, ecx
;call simd_10007028_asm
CALL simd_10007028_asm
;add esp, 0x2c
add r11d, 0x2c
jmp loc_1000403B
loc_10003DFF:
;mov ebp, [esp+0x24]
mov ebp, [r11d+0x24]
;mov eax, [esp+0x22]
mov eax, [r11d+0x22]
;mov edx, [esp+0x2c]
mov edx, [r11d+0x2c]
;push ebp
;push eax
;push ebx
;push edx
;push ecx
PUSH32 ebp, eax, ebx, edx, ecx
;call simd_1000720B_asm
CALL simd_1000720B_asm
;add esp, 0x20
add r11d, 0x20
jmp loc_1000403B
loc_10003E1D:
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
;push ebp
PUSH32 ebp
jz short loc_10003E43
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;mov edx, [esp+0x1e]
mov edx, [r11d+0x1e]
;push eax
;push edx
;push ebx
PUSH32 eax, edx, ebx
;mov ebx, [esp+0x30]
mov ebx, [r11d+0x30]
;push ebx
;push ecx
PUSH32 ebx, ecx
;call simd_10007364_asm
CALL simd_10007364_asm
;add esp, 0x18
add r11d, 0x18
jmp loc_1000403B
loc_10003E43:
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;push ebx
;push eax
;push ecx
PUSH32 ebx, eax, ecx
;call simd_10007491_asm
CALL simd_10007491_asm
;add esp, 0x10
add r11d, 0x10
jmp loc_1000403B
loc_10003E57:
;cmp dword [esp+0x20], 0x0
cmp dword [r11d+0x20], 0x0
jle near loc_1000403B
movsx eax, bx
;mov ebx, [esp+0x20]
mov ebx, [r11d+0x20]
;mov [esp+0x28], eax
mov [r11d+0x28], eax
;mov [esp+0x2c], ebx
mov [r11d+0x2c], ebx
loc_10003E71:
movsx ebx, word [ecx]
;imul ebx, [esp+0x28]
imul ebx, [r11d+0x28]
sar ebx, 0xf
add ecx, 0x2
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz short loc_10003EB1
add esi, 0x4
add edi, 0x4
movsx eax, bx
;movsx ebp, word [esp+0x16]
movsx ebp, word [r11d+0x16]
imul ebp, eax
sar ebp, 0xf
movsx ebp, bp
add [esi-0x4], ebp
;movsx ebp, word [esp+0x18]
movsx ebp, word [r11d+0x18]
imul ebp, eax
sar ebp, 0xf
movsx eax, bp
add [edi-0x4], eax
loc_10003EB1:
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_10003EE1
movsx ebx, bx
;movsx eax, word [esp+0x1a]
movsx eax, word [r11d+0x1a]
imul eax, ebx
sar eax, 0xf
add edx, 0x4
movsx ebp, ax
;movsx eax, word [esp+0x1c]
movsx eax, word [r11d+0x1c]
imul eax, ebx
sar eax, 0xf
add [edx-0x4], ebp
movsx ebx, ax
add [edx], ebx
jmp short loc_10003EE6
loc_10003EE1:
movsx eax, bx
add [edx], eax
loc_10003EE6:
add edx, 0x4
;dec dword [esp+0x2c]
dec dword [r11d+0x2c]
jnz near loc_10003E71
jmp loc_1000403B
loc_10003EF4:
;mov byte [esp+0x11], 0x1
mov byte [r11d+0x11], 0x1
;cmp word [esp+0x1e], 0x0
cmp word [r11d+0x1e], 0x0
jz near loc_10003FA3
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz near loc_10003F69
;mov eax, [esp+0x28]
mov eax, [r11d+0x28]
;mov edx, [esp+0x2c]
mov edx, [r11d+0x2c]
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
;push eax
;push edx
;push ebp
PUSH32 eax, edx, ebp
jz short loc_10003F4B
;mov ebp, [esp+0x40]
mov ebp, [r11d+0x40]
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;mov edx, [esp+0x22]
mov edx, [r11d+0x22]
;push ebp
PUSH32 ebp
;mov ebp, [esp+0x2c]
mov ebp, [r11d+0x2c]
;push eax
PUSH32 eax
;mov eax, [esp+0x2e]
mov eax, [r11d+0x2e]
;push edx
PUSH32 edx
;mov edx, [esp+0x38]
mov edx, [r11d+0x38]
;push ebp
;push eax
;push ebx
;push edx
;push ecx
PUSH32 ebp, eax, ebx, edx, ecx
;call simd_10007104_asm
CALL simd_10007104_asm
;add esp, 0x2c
add r11d, 0x2c
jmp loc_1000403B
loc_10003F4B:
;mov ebp, [esp+0x24]
mov ebp, [r11d+0x24]
;mov eax, [esp+0x22]
mov eax, [r11d+0x22]
;mov edx, [esp+0x2c]
mov edx, [r11d+0x2c]
;push ebp
;push eax
;push ebx
;push edx
;push ecx
PUSH32 ebp, eax, ebx, edx, ecx
;call simd_100072A3_asm
CALL simd_100072A3_asm
;add esp, 0x20
add r11d, 0x20
jmp loc_1000403B
loc_10003F69:
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
;push ebp
PUSH32 ebp
jz short loc_10003F8F
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;mov edx, [esp+0x1e]
mov edx, [r11d+0x1e]
;push eax
;push edx
;push ebx
PUSH32 eax, edx, ebx
;mov ebx, [esp+0x30]
mov ebx, [r11d+0x30]
;push ebx
;push ecx
PUSH32 ebx, ecx
;call simd_100073F1_asm
CALL simd_100073F1_asm
;add esp, 0x18
add r11d, 0x18
jmp loc_1000403B
loc_10003F8F:
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;push ebx
;push eax
;push ecx
PUSH32 ebx, eax, ecx
;call simd_100074CD_asm
CALL simd_100074CD_asm
;add esp, 0x10
add r11d, 0x10
jmp loc_1000403B
loc_10003FA3:
;cmp dword [esp+0x20], 0x0
cmp dword [r11d+0x20], 0x0
jle near loc_1000403B
movsx eax, bx
;mov ebx, [esp+0x20]
mov ebx, [r11d+0x20]
;mov [esp+0x28], eax
mov [r11d+0x28], eax
;mov [esp+0x2c], ebx
mov [r11d+0x2c], ebx
loc_10003FBD:
movsx ebx, word [ecx]
;imul ebx, [esp+0x28]
imul ebx, [r11d+0x28]
sar ebx, 0xf
add ecx, 0x2
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz short loc_10003FFD
add esi, 0x4
add edi, 0x4
movsx eax, bx
;movsx ebp, word [esp+0x16]
movsx ebp, word [r11d+0x16]
imul ebp, eax
sar ebp, 0xf
movsx ebp, bp
mov [esi-0x4], ebp
;movsx ebp, word [esp+0x18]
movsx ebp, word [r11d+0x18]
imul ebp, eax
sar ebp, 0xf
movsx eax, bp
mov [edi-0x4], eax
loc_10003FFD:
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_1000402D
movsx ebx, bx
;movsx eax, word [esp+0x1a]
movsx eax, word [r11d+0x1a]
imul eax, ebx
sar eax, 0xf
add edx, 0x4
movsx ebp, ax
;movsx eax, word [esp+0x1c]
movsx eax, word [r11d+0x1c]
imul eax, ebx
sar eax, 0xf
mov [edx-0x4], ebp
movsx ebx, ax
mov [edx], ebx
jmp short loc_10004032
loc_1000402D:
movsx eax, bx
mov [edx], eax
loc_10004032:
add edx, 0x4
;dec dword [esp+0x2c]
dec dword [r11d+0x2c]
jnz near loc_10003FBD
loc_1000403B:
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
mov ecx, [eax+0x2346]
;mov [esp+0x24], ecx
mov [r11d+0x24], ecx
loc_10004049:
;cmp dword [esp+0x24], 0x0
cmp dword [r11d+0x24], 0x0
jnz near loc_10003CAD
loc_10004054:
;cmp byte [esp+0x11], 0x0
cmp byte [r11d+0x11], 0x0
jnz near loc_10004142
;cmp word [esp+0x1e], 0x0
cmp word [r11d+0x1e], 0x0
jz near loc_100040E2
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz near loc_100040B2
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
mov ecx, [eax+0x2409e]
mov edx, [eax+0x2409a]
;push ecx
;push edx
PUSH32 ecx, edx
mov ecx, [eax+0x240a2]
mov edx, [eax+0x24082]
;push ecx
;push edx
PUSH32 ecx, edx
jz short loc_100040A5
;call simd_100071D0_asm
CALL simd_100071D0_asm
;add esp, 0x10
add r11d, 0x10
jmp loc_10004142
loc_100040A5:
;call simd_1000732F_asm
CALL simd_1000732F_asm
;add esp, 0x10
add r11d, 0x10
jmp loc_10004142
loc_100040B2:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
mov ecx, [eax+0x240a2]
mov edx, [eax+0x24082]
;push ecx
;push edx
PUSH32 ecx, edx
jz short loc_100040D8
;call simd_10007472_asm
CALL simd_10007472_asm
;add esp, 0x8
add r11d, 0x8
jmp loc_10004142
loc_100040D8:
;call simd_10007506_asm
CALL simd_10007506_asm
;add esp, 0x8
add r11d, 0x8
jmp short loc_10004142
loc_100040E2:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
mov ecx, [eax+0x24092]
jz short loc_10004102
mov esi, [eax+0x2408a]
mov edi, [eax+0x2408e]
loc_10004102:
;cmp dword [esp+0x20], 0x0
cmp dword [r11d+0x20], 0x0
jle short loc_10004142
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
loc_1000410D:
mov dword [ecx], 0x0
add ecx, 0x4
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_10004126
mov dword [ecx], 0x0
add ecx, 0x4
loc_10004126:
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz short loc_1000413F
mov dword [esi], 0x0
add esi, 0x4
mov dword [edi], 0x0
add edi, 0x4
loc_1000413F:
dec eax
jnz short loc_1000410D
loc_10004142:
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jz near loc_10004233
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
mov bl, [eax+0x482]
mov al, [eax+0x48e]
;mov [esp+0x28], al
mov [r11d+0x28], al
test bl, bl
jz short loc_1000417E
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;push 0x0
PUSH32 0x0
mov ecx, [eax+0x240a6]
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_10006910
CALL loc_10006910
;add esp, 0xc
add r11d, 0xc
loc_1000417E:
;cmp byte [esp+0x28], 0x0
cmp byte [r11d+0x28], 0x0
jz short loc_1000419D
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;push ebx
PUSH32 ebx
mov ecx, [eax+0x240aa]
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_10006530
CALL loc_10006530
;add esp, 0xc
add r11d, 0xc
loc_1000419D:
test bl, bl
jnz short loc_100041AC
;cmp byte [esp+0x28], 0x0
cmp byte [r11d+0x28], 0x0
jz near loc_10004233
loc_100041AC:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;cmp word [esp+0x1e], 0x0
cmp word [r11d+0x1e], 0x0
mov edi, [eax+0x24086]
jz short loc_100041F8
mov eax, [eax+0x240a2]
;push edi
PUSH32 edi
;mov ecx, [esp+0xd4]
mov ecx, [r11d+0xd4]
;push eax
PUSH32 eax
;cmp byte [esp+0x1b], 0x0
cmp byte [r11d+0x1b], 0x0
mov eax, [loc_1001B2C4]
mov edx, [ecx+0x24082]
;push eax
;push edx
PUSH32 eax, edx
jz short loc_100041EE
;call simd_10007525_asm
CALL simd_10007525_asm
;add esp, 0x10
add r11d, 0x10
jmp short loc_10004233
loc_100041EE:
;call simd_1000758D_asm
CALL simd_1000758D_asm
;add esp, 0x10
add r11d, 0x10
jmp short loc_10004233
loc_100041F8:
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
;cmp dword [esp+0x20], 0x0
cmp dword [r11d+0x20], 0x0
mov edx, [eax+0x24092]
jle short loc_10004233
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
loc_10004210:
add edi, 0x2
mov cl, [loc_1001B2C4]
movsx esi, word [edi-0x2]
shl esi, cl
add [edx], esi
add edx, 0x4
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_10004230
add [edx], esi
add edx, 0x4
loc_10004230:
dec eax
jnz short loc_10004210
loc_10004233:
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
;mov cl, [esp+0x13]
mov cl, [r11d+0x13]
;shl dword [esp+0x20], cl
shl dword [r11d+0x20], cl
;cmp word [esp+0x1e], 0x0
cmp word [r11d+0x1e], 0x0
mov dx, [eax+0x49e]
;mov eax, [esp+0xd0]
mov eax, [r11d+0xd0]
jz near loc_1000428F
mov ecx, [eax+0x240a2]
;mov edi, [esp+0xd4]
mov edi, [r11d+0xd4]
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push ecx
;push edi
;push edx
;push eax
PUSH32 ecx, edi, edx, eax
;call simd_100075CC_asm
CALL simd_100075CC_asm
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;lea ecx, [esp+0x70]
lea ecx, [r11d+0x70]
;add esp, 0x10
add r11d, 0x10
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10006FE2
CALL loc_10006FE2
;add esp, 0x8
add r11d, 0x8
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xbc
add r11d, 0xbc
;ret
RET
loc_1000428F:
;cmp dword [esp+0x20], 0x0
cmp dword [r11d+0x20], 0x0
mov esi, [eax+0x24092]
jle short loc_100042B9
mov cl, dl
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;mov edi, [esp+0xd4]
mov edi, [r11d+0xd4]
mov edx, [cs_volume_multiplier]
cmp edx, 0x800
je short loc_100042A9
sar edx, cl
loc_100042A9_1:
mov ecx, [esi]
add esi, 0x4
imul ecx, edx
sar ecx, 11
cmp ecx, 0x7fff
jle short loc_100042A9_2
mov cx, 0x7fff
jmp short loc_100042A9_3
loc_100042A9_2:
cmp ecx, 0xffff8000
jge short loc_100042A9_3
mov cx, 0x8000
loc_100042A9_3:
mov [edi], cx
add edi, 0x2
dec eax
jnz short loc_100042A9_1
jmp short loc_100042B9 ; volume gain
loc_100042A9:
mov edx, [esi]
add esi, 0x4
sar edx, cl
mov [edi], dx
add edi, 0x2
dec eax
jnz short loc_100042A9
loc_100042B9:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xbc
add r11d, 0xbc
;ret
RET
align 16
loc_100042D0:
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push esi
PUSH32 esi
xor si, si
;mov edx, [esp+0xc]
mov edx, [r11d+0xc]
loc_100042DC:
movsx eax, si
lea eax, [ecx+eax*4+0x20]
cmp [eax], edx
jnz short loc_100042ED
mov dword [eax], 0x0
loc_100042ED:
inc si
cmp si, 0x10
jl short loc_100042DC
;pop esi
POP32 esi
;ret
RET
align 16
loc_10004300:
;mov ax, [esp+0x8]
mov ax, [r11d+0x8]
;push ebx
;push esi
PUSH32 ebx, esi
mov cl, ah
;push edi
PUSH32 edi
xor esi, esi
mov si, ax
;mov edx, [esp+0x10]
mov edx, [r11d+0x10]
movsx eax, cl
and esi, 0xff
inc cl
shl esi, 0xe
mov edi, [edx+eax*4+0x164]
movsx eax, cl
mov edx, [edx+eax*4+0x164]
;push edx
;push esi
PUSH32 edx, esi
;call loc_10006310
CALL loc_10006310
;add esp, 0x8
add r11d, 0x8
mov ebx, eax
mov eax, 0x400000
;push edi
PUSH32 edi
sub eax, esi
;push eax
PUSH32 eax
;call loc_10006310
CALL loc_10006310
;add esp, 0x8
add r11d, 0x8
add eax, ebx
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10004360:
;mov ax, [esp+0x8]
mov ax, [r11d+0x8]
;push esi
PUSH32 esi
mov cl, ah
movsx edx, cl
and ax, 0xff
inc cl
shl ax, 0x7
movsx esi, ax
movsx eax, cl
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
movsx eax, word [ecx+eax*2+0x464]
imul eax, esi
movsx ecx, word [ecx+edx*2+0x464]
sar eax, 0xf
mov edx, 0x7fff
sub edx, esi
;pop esi
POP32 esi
imul ecx, edx
sar ecx, 0xf
add ax, cx
;ret
RET
align 16
loc_100043B0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push ebx
PUSH32 ebx
mov dx, [eax+0x21822]
;push esi
PUSH32 esi
;mov si, [esp+0x14]
mov si, [r11d+0x14]
;push edi
PUSH32 edi
test si, si
jle short loc_100043E4
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
loc_100043CC:
mov bl, [ecx]
inc ecx
movsx edi, dx
inc dx
mov [edi+eax+0x21826], bl
and dx, 0x7ff
dec si
jnz short loc_100043CC
loc_100043E4:
mov [eax+0x21822], dx
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_100043F0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
mov ax, [esi+0x21824]
cmp [esi+0x21822], ax
jz near loc_1000462B
mov edi, timeGetTime
loc_10004411:
mov cx, [esi+0x21824]
movsx eax, cx
inc cx
mov bl, [eax+esi+0x21826]
mov [esi+0x21824], cx
and cx, 0x7ff
test bl, 0x80
mov [esi+0x21824], cx
jz near loc_100044D7
cmp bl, 0xf0
jb near loc_10004496
xor eax, eax
mov al, bl
cmp eax, 0xf0
jz short loc_10004463
cmp eax, 0xf7
jz short loc_1000447A
cmp eax, 0xff
jz short loc_10004488
jmp loc_10004617
loc_10004463:
mov word [esi+0x24066], 0xf0
mov word [esi+0x2406a], 0x0
jmp loc_10004617
loc_1000447A:
;push esi
PUSH32 esi
;call loc_100057C0
CALL loc_100057C0
;add esp, 0x4
add r11d, 0x4
jmp loc_10004617
loc_10004488:
;push esi
PUSH32 esi
;call loc_10002FC0
CALL loc_10002FC0
;add esp, 0x4
add r11d, 0x4
jmp loc_10004617
loc_10004496:
xor ax, ax
mov al, bl
and bl, 0xf
and ax, 0xf0
mov [esi+0x24066], ax
xor eax, eax
mov al, bl
cmp byte [eax+esi+0x21742], 0x0
jz short loc_100044B9
xor bl, bl
loc_100044B9:
mov byte [esi+0x24069], 0xff
mov [esi+0x24068], bl
;call edi
mov r9d, edi
CALL r9
movsx ecx, bl
mov [esi+ecx*4+0x24026], eax
jmp loc_10004617
loc_100044D7:
movsx ecx, word [esi+0x24066]
sub ecx, 0x80
cmp ecx, 0x70
ja near loc_10004617
xor eax, eax
mov al, [ecx+loc_10004650]
;jmp dword [eax*4+loc_10004630]
mov r9d, [eax*4+loc_10004630]
jmp r9
loc_100044FC:
mov al, [esi+0x24069]
test al, al
jge short loc_10004511
mov [esi+0x24069], bl
jmp loc_10004617
loc_10004511:
;push eax
PUSH32 eax
mov al, [esi+0x24068]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10004D60
CALL loc_10004D60
mov byte [esi+0x24069], 0xff
;add esp, 0xc
add r11d, 0xc
jmp loc_10004617
loc_1000452E:
mov al, [esi+0x24069]
test al, al
jge short loc_10004543
mov [esi+0x24069], bl
jmp loc_10004617
loc_10004543:
test bl, bl
jz short loc_1000455B
;push ebx
;push eax
PUSH32 ebx, eax
mov al, [esi+0x24068]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100046D0
CALL loc_100046D0
;add esp, 0x10
add r11d, 0x10
jmp short loc_1000456C
loc_1000455B:
;push eax
PUSH32 eax
mov al, [esi+0x24068]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10004D60
CALL loc_10004D60
;add esp, 0xc
add r11d, 0xc
loc_1000456C:
mov byte [esi+0x24069], 0xff
jmp loc_10004617
loc_10004578:
mov al, [esi+0x24069]
test al, al
jge short loc_1000458D
mov [esi+0x24069], bl
jmp loc_10004617
loc_1000458D:
;push ebx
;push eax
PUSH32 ebx, eax
mov al, [esi+0x24068]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10004EA0
CALL loc_10004EA0
mov byte [esi+0x24069], 0xff
;add esp, 0x10
add r11d, 0x10
jmp loc_10004617
loc_100045A8:
;push ebx
PUSH32 ebx
mov al, [esi+0x24068]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100053B0
CALL loc_100053B0
;add esp, 0xc
add r11d, 0xc
jmp loc_10004617
loc_100045BB:
;push ebx
PUSH32 ebx
mov al, [esi+0x24068]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10004E60
CALL loc_10004E60
;add esp, 0xc
add r11d, 0xc
jmp short loc_10004617
loc_100045CE:
cmp byte [esi+0x24069], 0x0
jge short loc_100045DF
mov [esi+0x24069], bl
jmp short loc_10004617
loc_100045DF:
;push ebx
PUSH32 ebx
mov al, [esi+0x24068]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10004E10
CALL loc_10004E10
mov byte [esi+0x24069], 0xff
;add esp, 0xc
add r11d, 0xc
jmp short loc_10004617
loc_100045F9:
mov ax, [esi+0x2406a]
cmp ax, 0x10
jge short loc_10004617
movsx eax, ax
mov [eax+esi+0x2406c], bl
inc word [esi+0x2406a]
loc_10004617:
mov ax, [esi+0x21824]
cmp [esi+0x21822], ax
jnz near loc_10004411
loc_1000462B:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 4
loc_10004630:
dd loc_100044FC
dd loc_1000452E
dd loc_10004578
dd loc_100045A8
dd loc_100045BB
dd loc_100045CE
dd loc_100045F9
dd loc_10004617
loc_10004650:
db 0
times 15 db 7
db 1
times 31 db 7
db 2
times 15 db 7
db 3
times 15 db 7
db 4
times 15 db 7
db 5
times 15 db 7
db 6
times 15 db 204
align 4
loc_100046D0:
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;push ebx
PUSH32 ebx
;mov bl, [esp+0xc]
mov bl, [r11d+0xc]
;push esi
PUSH32 esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
PUSH32 edi, ebp
;push 0x1
PUSH32 0x1
;push eax
;push ebx
;push esi
PUSH32 eax, ebx, esi
;call loc_100056C0
CALL loc_100056C0
;add esp, 0x10
add r11d, 0x10
mov eax, [esi+0xc]
cmp [esi+0x4], eax
jbe short loc_100046FE
;push esi
PUSH32 esi
;call loc_10005590
CALL loc_10005590
;add esp, 0x4
add r11d, 0x4
loc_100046FE:
movsx eax, bl
lea ebp, [esi+eax*4+0x20]
mov edi, [ebp]
test edi, edi
jz near loc_10004775
;push edi
PUSH32 edi
mov eax, [esi+0x18]
mov ecx, [eax+0x4]
;push ecx
PUSH32 ecx
;call loc_10008AB0
CALL loc_10008AB0
;add esp, 0x8
add r11d, 0x8
test al, al
jnz short loc_1000472C
mov dword [ebp], 0x0
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_1000472C:
mov eax, [edi]
cmp eax, 0x6b657962
jz short loc_10004741
cmp eax, 0x70657263
jz near loc_10004760
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10004741:
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push eax
;push ecx
;push ecx
;push ebx
;push edi
PUSH32 eax, ecx, ecx, ebx, edi
;push 0xffffffff
PUSH32 0xffffffff
;push 0x0
PUSH32 0x0
;push esi
PUSH32 esi
;call loc_10004780
CALL loc_10004780
;add esp, 0x20
add r11d, 0x20
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10004760:
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push eax
;push ecx
;push ebx
;push edi
;push esi
PUSH32 eax, ecx, ebx, edi, esi
;call loc_100048A0
CALL loc_100048A0
;add esp, 0x14
add r11d, 0x14
loc_10004775:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10004780:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;sub esp, 0xc
sub r11d, 0xc
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x18]
mov ebx, [r11d+0x18]
;push edi
;push ebp
PUSH32 edi, ebp
lea edi, [eax+0x3c]
mov ax, [edi]
add edi, 0x2
mov ecx, [ebx+0xc]
cmp [ebx+0x4], ecx
jbe short loc_100047AD
test ax, ax
jle near loc_10004878
mov ax, 0x1
loc_100047AD:
test ax, ax
jle near loc_10004878
;mov [esp+0x18], ax
mov [r11d+0x18], ax
loc_100047BB:
mov al, [edi+0x16]
lea esi, [edi+0x8]
movsx ecx, al
cmp ecx, 0x4
ja near loc_1000482B
;jmp dword [ecx*4+loc_10004880]
mov r9d, [ecx*4+loc_10004880]
jmp r9
loc_100047D0:
;mov byte [esp+0x13], 0x3c
mov byte [r11d+0x13], 0x3c
mov cl, 0x1
jmp loc_10004839
loc_100047D9:
;push eax
PUSH32 eax
;mov eax, [esp+0x34]
mov eax, [r11d+0x34]
;push eax
;push ebx
PUSH32 eax, ebx
;call loc_10005710
CALL loc_10005710
;mov [esp+0x1e], al
mov [r11d+0x1e], al
;add esp, 0xc
add r11d, 0xc
mov ebp, [esi+0xa]
test ebp, ebp
jz short loc_10004801
;push ebp
;push ebx
PUSH32 ebp, ebx
;call loc_10005500
CALL loc_10005500
;mov [esp+0x1c], eax
mov [r11d+0x1c], eax
;add esp, 0x8
add r11d, 0x8
loc_10004801:
;cmp byte [esp+0x12], 0x0
cmp byte [r11d+0x12], 0x0
jl short loc_1000482F
test ebp, ebp
jz short loc_1000482F
;cmp dword [esp+0x14], 0x0
cmp dword [r11d+0x14], 0x0
jz short loc_1000482F
;mov eax, [esp+0x3c]
mov eax, [r11d+0x3c]
;mov ecx, [esp+0x12]
mov ecx, [r11d+0x12]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push eax
;push ecx
;push edx
;push ebx
PUSH32 eax, ecx, edx, ebx
;call loc_10005530
CALL loc_10005530
;add esp, 0x10
add r11d, 0x10
loc_1000482B:
xor cl, cl
jmp short loc_10004839
loc_1000482F:
mov cl, 0x1
;mov al, [esp+0x38]
mov al, [r11d+0x38]
;mov [esp+0x13], al
mov [r11d+0x13], al
loc_10004839:
test cl, cl
jz short loc_1000486A
;mov eax, [esp+0x3c]
mov eax, [r11d+0x3c]
;mov ecx, [esp+0x13]
mov ecx, [r11d+0x13]
;mov edx, [esp+0x34]
mov edx, [r11d+0x34]
;push eax
PUSH32 eax
;mov eax, [esp+0x34]
mov eax, [r11d+0x34]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x34]
mov ecx, [r11d+0x34]
;push edx
PUSH32 edx
;mov edx, [esp+0x34]
mov edx, [r11d+0x34]
;push eax
PUSH32 eax
;mov eax, [esp+0x34]
mov eax, [r11d+0x34]
;push esi
;push ecx
;push edx
;push eax
;push ebx
PUSH32 esi, ecx, edx, eax, ebx
;call loc_10004960
CALL loc_10004960
;add esp, 0x24
add r11d, 0x24
loc_1000486A:
add edi, [edi+0x4]
;dec word [esp+0x18]
dec word [r11d+0x18]
jnz near loc_100047BB
loc_10004878:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 4
loc_10004880:
dd loc_1000482F
dd loc_100047D0
dd loc_100047D9
dd loc_100047D9
dd loc_100047D9
align 16
loc_100048A0:
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
lea ecx, [edi+0x3e]
lea eax, [edi+0x34]
mov bp, [ecx]
add ecx, 0x2
mov al, [eax]
;cmp [esp+0x20], al
cmp [r11d+0x20], al
jl near loc_10004951
movsx si, al
;movsx dx, byte [esp+0x20]
movsx dx, byte [r11d+0x20]
movsx ebx, si
movsx eax, bp
movsx ebp, dx
add ebx, eax
cmp ebx, ebp
jle near loc_10004951
sub dx, si
mov eax, [ecx+0x4]
imul ax, dx
movsx ebx, ax
mov esi, [ecx+ebx+0x10]
lea ebp, [ecx+ebx+0x8]
test esi, esi
jz near loc_10004951
movsx bx, byte [ebp+0xc]
movsx eax, bx
test eax, eax
jz short loc_10004915
cmp eax, 0x1
jz short loc_1000491B
sub bx, 0x2
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push ebx
;push edi
;push eax
PUSH32 ebx, edi, eax
;call loc_10005670
CALL loc_10005670
jmp short loc_1000492B
loc_10004915:
mov bx, 0xffff
jmp short loc_1000492E
loc_1000491B:
mov bx, 0xffff
;push esi
PUSH32 esi
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push edi
;push eax
PUSH32 edi, eax
;call loc_10005620
CALL loc_10005620
loc_1000492B:
;add esp, 0xc
add r11d, 0xc
loc_1000492E:
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
mov cl, [ebp+0xd]
;mov edx, [esp+0x20]
mov edx, [r11d+0x20]
;push eax
PUSH32 eax
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push edx
;push eax
;push esi
;push ebx
;push edi
;push ecx
PUSH32 edx, eax, esi, ebx, edi, ecx
;call loc_10004780
CALL loc_10004780
;add esp, 0x20
add r11d, 0x20
loc_10004951:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10004960:
;movsx eax, byte [esp+0x18]
movsx eax, byte [r11d+0x18]
;sub esp, 0x8
sub r11d, 0x8
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push edi
;push ebp
PUSH32 edi, ebp
add eax, esi
;mov [esp+0x10], eax
mov [r11d+0x10], eax
cmp byte [eax+0x21752], 0x0
jz short loc_1000498D
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100055E0
CALL loc_100055E0
;add esp, 0x8
add r11d, 0x8
loc_1000498D:
;mov ebx, [esp+0x2c]
mov ebx, [r11d+0x2c]
;push 0x1
PUSH32 0x1
mov ecx, [esi+0x18]
mov eax, [ebx+0xa]
;mov [esp+0x18], eax
mov [r11d+0x18], eax
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10006C90
CALL loc_10006C90
;add esp, 0xc
add r11d, 0xc
test al, al
jz near loc_10004D50
;cmp dword [esp+0x20], 0x0
cmp dword [r11d+0x20], 0x0
jz short loc_100049C9
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push 0x1
PUSH32 0x1
;push eax
PUSH32 eax
mov ecx, [esi+0x18]
;push ecx
PUSH32 ecx
;call loc_10006C30
CALL loc_10006C30
;add esp, 0xc
add r11d, 0xc
loc_100049C9:
;mov eax, [esp+0x28]
mov eax, [r11d+0x28]
;push 0x1
PUSH32 0x1
;push eax
PUSH32 eax
mov ecx, [esi+0x18]
;push ecx
PUSH32 ecx
;call loc_10006C30
CALL loc_10006C30
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;add esp, 0xc
add r11d, 0xc
;push ecx
;push esi
PUSH32 ecx, esi
;call loc_10003880
CALL loc_10003880
;add esp, 0x8
add r11d, 0x8
mov edi, eax
test edi, edi
jnz short loc_10004A09
;push esi
PUSH32 esi
;call loc_10005590
CALL loc_10005590
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;add esp, 0x4
add r11d, 0x4
;push eax
;push esi
PUSH32 eax, esi
;call loc_10003880
CALL loc_10003880
;add esp, 0x8
add r11d, 0x8
mov edi, eax
loc_10004A09:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10003990
CALL loc_10003990
;add esp, 0x8
add r11d, 0x8
mov ebp, eax
test ebp, ebp
jnz short loc_10004A2B
;push edi
;push esi
PUSH32 edi, esi
;call loc_10003910
CALL loc_10003910
;add esp, 0x8
add r11d, 0x8
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10004A2B:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
mov cl, [eax+0x21812]
;mov al, [esp+0x30]
mov al, [r11d+0x30]
add cl, [ebx+0xf]
;mov dl, [esp+0x34]
mov dl, [r11d+0x34]
;add cl, [esp+0x38]
add cl, [r11d+0x38]
mov byte [edi], 0x1
mov byte [edi+0x1], 0x0
sub cl, 0x40
mov [edi+0x2], al
movsx eax, cl
sub eax, 0x3c
mov [edi+0x3], dl
shl eax, 0x8
mov cl, [ebx+0x1]
sar eax, cl
movsx cx, byte [ebx+0x10]
add ax, cx
;mov cl, [esp+0x3c]
mov cl, [r11d+0x3c]
add ax, 0x3c00
;mov edx, [esp+0x20]
mov edx, [r11d+0x20]
mov [edi+0x6], ax
mov [edi+0x4], ah
;mov ax, [esp+0x24]
mov ax, [r11d+0x24]
mov [edi+0x5], cl
mov byte [edi+0x372], 0x0
mov byte [edi+0x373], 0x0
;mov ecx, [esp+0x28]
mov ecx, [r11d+0x28]
mov [edi+0x374], edx
mov [edi+0x378], ax
mov [edi+0x37a], ecx
;call timeGetTime
CALL timeGetTime
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov [edi+0x37e], eax
mov al, [ecx+0x21732]
test al, al
jl short loc_10004ACE
movsx ax, al
shl ax, 0x8
jmp short loc_10004AD2
loc_10004ACE:
mov ax, [ebx+0x2e]
loc_10004AD2:
mov [edi+0x2332], ax
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
mov al, [eax+0x21722]
test al, al
jl short loc_10004AF1
movsx ax, al
shl ax, 0x8
jmp short loc_10004AF5
loc_10004AF1:
mov ax, [ebx+0x3c]
loc_10004AF5:
mov [edi+0x2334], ax
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
mov dword [edi+0x382], 0x0
mov dword [edi+0x38c], 0x0
mov al, [ebx+0xe]
mov [edi+0x38a], al
mov cl, [ebx+0xf]
mov [edi+0x38b], cl
mov eax, [edx]
cmp eax, 0x636c6172
jg short loc_10004B44
jz near loc_10004BBD
cmp eax, 0x616e616c
jz near loc_10004B8D
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10004B44:
cmp eax, 0x666d2020
jg short loc_10004B64
jz near loc_10004C1D
cmp eax, 0x666c7574
jz near loc_10004BED
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10004B64:
cmp eax, 0x68616d6d
jz near loc_10004C4D
cmp eax, 0x70636d20
jz near loc_10004C7A
cmp eax, 0x77617665
jz near loc_10004CA7
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10004B8D:
mov dword [edi+0x382], loc_1000A4E0
mov dword [edi+0x386], loc_1000A460
;push loc_1000A480
PUSH32 loc_1000A480
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push edi
;push esi
PUSH32 edi, esi
;call loc_1000A320
CALL loc_1000A320
jmp loc_10004CD2
loc_10004BBD:
mov dword [edi+0x382], loc_1000A180
mov dword [edi+0x386], loc_1000A110
;push loc_1000A130
PUSH32 loc_1000A130
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push edi
;push esi
PUSH32 edi, esi
;call loc_10009FF0
CALL loc_10009FF0
jmp loc_10004CD2
loc_10004BED:
mov dword [edi+0x382], loc_10009DF0
mov dword [edi+0x386], loc_10009D50
;push loc_10009D70
PUSH32 loc_10009D70
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push edi
;push esi
PUSH32 edi, esi
;call loc_10009BE0
CALL loc_10009BE0
jmp loc_10004CD2
loc_10004C1D:
mov dword [edi+0x382], loc_100099C0
mov dword [edi+0x386], loc_10009940
;push loc_10009960
PUSH32 loc_10009960
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push edi
;push esi
PUSH32 edi, esi
;call loc_100097E0
CALL loc_100097E0
jmp loc_10004CD2
loc_10004C4D:
mov dword [edi+0x382], loc_10009580
mov dword [edi+0x386], 0x0
;push loc_10009510
PUSH32 loc_10009510
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push edi
;push esi
PUSH32 edi, esi
;call loc_10009300
CALL loc_10009300
jmp loc_10004CD2
loc_10004C7A:
mov dword [edi+0x382], loc_10008F30
mov dword [edi+0x386], loc_10008E70
;push loc_10008EF0
PUSH32 loc_10008EF0
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push edi
;push esi
PUSH32 edi, esi
;call loc_10008C60
CALL loc_10008C60
jmp short loc_10004CD2
loc_10004CA7:
mov dword [edi+0x382], loc_100092B0
mov dword [edi+0x386], 0x0
;push loc_100092A0
PUSH32 loc_100092A0
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push edi
;push esi
PUSH32 edi, esi
;call loc_10009250
CALL loc_10009250
loc_10004CD2:
;add esp, 0x8
add r11d, 0x8
cmp byte [ebx+0xe], 0x2
jge short loc_10004CE5
mov dword [edi+0x386], 0x0
loc_10004CE5:
mov eax, [ebp+0x376]
cmp [ebp+0x372], eax
jnz near loc_10004D31
;mov al, [esp+0x30]
mov al, [r11d+0x30]
;mov cl, [esp+0x34]
mov cl, [r11d+0x34]
mov byte [ebp], 0x1
mov byte [ebp+0x1], 0x0
mov [ebp+0x2], al
;push 0x0
PUSH32 0x0
;push ebx
PUSH32 ebx
mov [ebp+0x3], cl
mov al, [ebx+0xf]
;mov cl, [esp+0x44]
mov cl, [r11d+0x44]
;add al, [esp+0x40]
add al, [r11d+0x40]
;push ebp
;push esi
PUSH32 ebp, esi
mov [ebp+0x4], al
mov [ebp+0x5], cl
;call loc_10007620
CALL loc_10007620
;add esp, 0x10
add r11d, 0x10
;push ebp
;push esi
PUSH32 ebp, esi
;call loc_100078A0
CALL loc_100078A0
;add esp, 0x8
add r11d, 0x8
loc_10004D31:
;push edi
;push esi
PUSH32 edi, esi
;call loc_100078A0
CALL loc_100078A0
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;add esp, 0x8
add r11d, 0x8
cmp dword [eax], 0x70636d20
jnz short loc_10004D50
;push edi
PUSH32 edi
;call loc_10008EE0
CALL loc_10008EE0
;add esp, 0x4
add r11d, 0x4
loc_10004D50:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_10004D60:
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;sub esp, 0x4
sub r11d, 0x4
;push ebx
;push esi
PUSH32 ebx, esi
;mov bl, [esp+0x14]
mov bl, [r11d+0x14]
;push edi
PUSH32 edi
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push 0x0
PUSH32 0x0
;push eax
;push ebx
;push esi
PUSH32 eax, ebx, esi
;call loc_100056C0
CALL loc_100056C0
;add esp, 0x10
add r11d, 0x10
mov edi, [esi+0x240cc]
test edi, edi
jz near loc_10004DFD
loc_10004D89:
cmp [edi+0x2], bl
jnz near loc_10004DF3
;mov al, [esp+0x1c]
mov al, [r11d+0x1c]
cmp [edi+0x3], al
jnz near loc_10004DF3
cmp byte [edi], 0x0
jz near loc_10004DF3
;mov byte [esp+0xf], 0x0
mov byte [r11d+0xf], 0x0
cmp dword [edi+0x386], 0x0
jz short loc_10004DD8
mov al, [edi+0x38a]
;push eax
;push ebx
;push esi
PUSH32 eax, ebx, esi
;call loc_10005710
CALL loc_10005710
;add esp, 0xc
add r11d, 0xc
test al, al
jl short loc_10004DD8
cmp [edi+0x3], al
jz short loc_10004DD8
mov cl, [edi+0x5]
;push ecx
;push eax
;push edi
;push esi
PUSH32 ecx, eax, edi, esi
;call loc_10005530
CALL loc_10005530
;mov byte [esp+0x1f], 0x1
mov byte [r11d+0x1f], 0x1
;add esp, 0x10
add r11d, 0x10
loc_10004DD8:
;cmp byte [esp+0xf], 0x0
cmp byte [r11d+0xf], 0x0
jnz short loc_10004DF3
movsx eax, bl
mov byte [edi+0x5], 0x0
cmp byte [eax+esi+0x21702], 0x0
jnz short loc_10004DF3
mov byte [edi], 0x0
loc_10004DF3:
mov edi, [edi+0x2346]
test edi, edi
jnz near loc_10004D89
loc_10004DFD:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10004E10:
;mov cl, [esp+0xc]
mov cl, [r11d+0xc]
;push ebx
;push esi
PUSH32 ebx, esi
sub cl, 0x40
;mov bl, [esp+0x10]
mov bl, [r11d+0x10]
;push edi
PUSH32 edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
movsx eax, bl
mov [eax+edi+0x21682], cl
mov esi, [edi+0x240e8]
test esi, esi
jz short loc_10004E4F
loc_10004E36:
cmp [esi+0x2], bl
jnz short loc_10004E45
;push esi
;push edi
PUSH32 esi, edi
;call loc_10008690
CALL loc_10008690
;add esp, 0x8
add r11d, 0x8
loc_10004E45:
mov esi, [esi+0x37e]
test esi, esi
jnz short loc_10004E36
loc_10004E4F:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10004E60:
;mov cl, [esp+0xc]
mov cl, [r11d+0xc]
;push ebx
PUSH32 ebx
;mov bl, [esp+0xc]
mov bl, [r11d+0xc]
;push esi
PUSH32 esi
movsx eax, bl
;push edi
PUSH32 edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
mov [eax+edi+0x21692], cl
mov esi, [edi+0x240e8]
test esi, esi
jz short loc_10004E9C
loc_10004E83:
cmp [esi+0x2], bl
jnz short loc_10004E92
;push esi
;push edi
PUSH32 esi, edi
;call loc_100086C0
CALL loc_100086C0
;add esp, 0x8
add r11d, 0x8
loc_10004E92:
mov esi, [esi+0x37e]
test esi, esi
jnz short loc_10004E83
loc_10004E9C:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10004EA0:
;movsx eax, byte [esp+0xc]
movsx eax, byte [r11d+0xc]
;push ebx
PUSH32 ebx
cmp eax, 0x7f
;push esi
;push edi
PUSH32 esi, edi
ja near loc_100050F1
xor ecx, ecx
mov cl, [eax+loc_100051C4]
;jmp dword [ecx*4+loc_10005160]
mov r9d, [ecx*4+loc_10005160]
jmp r9
loc_10004EC0:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;pop edi
POP32 edi
mov [eax+esi+0x21762], bl
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
loc_10004ED8:
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov [eax+esi+0x216c2], bl
jmp loc_100050F9
loc_10004EF1:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push eax
;push esi
PUSH32 ebx, eax, esi
;call loc_10005420
CALL loc_10005420
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F9
loc_10004F0D:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push eax
;push esi
PUSH32 ebx, eax, esi
;call loc_10005250
CALL loc_10005250
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F9
loc_10004F29:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push eax
;push esi
PUSH32 ebx, eax, esi
;call loc_10005290
CALL loc_10005290
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F9
loc_10004F45:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push eax
;push esi
PUSH32 ebx, eax, esi
;call loc_100052D0
CALL loc_100052D0
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F9
loc_10004F61:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;pop edi
POP32 edi
mov [eax+esi+0x21772], bl
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
loc_10004F79:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
test bl, bl
setg al
;push eax
;push ecx
;push esi
PUSH32 eax, ecx, esi
;call loc_10005310
CALL loc_10005310
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F9
loc_10004F9A:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
test bl, bl
setg al
;push eax
;push ecx
;push esi
PUSH32 eax, ecx, esi
;call loc_10005360
CALL loc_10005360
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F9
loc_10004FBB:
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov [eax+esi+0x21722], bl
jmp loc_100050F9
loc_10004FD4:
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov [eax+esi+0x21732], bl
jmp loc_100050F9
loc_10004FED:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push 0x1
PUSH32 0x1
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100054A0
CALL loc_100054A0
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F5
loc_10005006:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push 0xffffffff
PUSH32 0xffffffff
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100054A0
CALL loc_100054A0
;add esp, 0xc
add r11d, 0xc
jmp loc_100050F5
loc_1000501F:
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;add eax, [esp+0x10]
add eax, [r11d+0x10]
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;pop edi
;pop esi
POP32 esi, edi
mov [eax+0x217a2], bl
;pop ebx
POP32 ebx
mov byte [eax+0x217c2], 0x0
;ret
RET
loc_1000503D:
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;add eax, [esp+0x10]
add eax, [r11d+0x10]
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;pop edi
;pop esi
POP32 esi, edi
mov [eax+0x21792], bl
;pop ebx
POP32 ebx
mov byte [eax+0x217c2], 0x0
;ret
RET
loc_1000505B:
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
;add eax, [esp+0x10]
add eax, [r11d+0x10]
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
;pop edi
;pop esi
POP32 esi, edi
mov [eax+0x217b2], bl
;pop ebx
POP32 ebx
mov byte [eax+0x217c2], 0x1
;ret
RET
loc_10005079:
;movsx ax, byte [esp+0x14]
movsx ax, byte [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10003090
CALL loc_10003090
;add esp, 0x8
add r11d, 0x8
jmp loc_100050F5
loc_1000508F:
;movsx ax, byte [esp+0x14]
movsx ax, byte [r11d+0x14]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10003170
CALL loc_10003170
;add esp, 0x8
add r11d, 0x8
jmp short loc_100050F5
loc_100050A5:
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
mov byte [eax+esi+0x21742], 0x0
jmp short loc_100050F5
loc_100050B8:
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
mov byte [eax+esi+0x21742], 0x1
jmp short loc_100050F5
loc_100050CB:
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
mov byte [eax+esi+0x21752], 0x1
jmp short loc_100050F5
loc_100050DE:
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
mov byte [eax+esi+0x21752], 0x0
jmp short loc_100050F5
loc_100050F1:
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
loc_100050F5:
;mov bl, [esp+0x1c]
mov bl, [r11d+0x1c]
loc_100050F9:
mov eax, [esi+0x14]
;mov cl, [esp+0x18]
mov cl, [r11d+0x18]
cmp [eax+0x49a], cl
jnz short loc_10005118
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
mov [eax+esi+0x216a2], bl
mov bl, 0x3
jmp short loc_10005132
loc_10005118:
;mov cl, [esp+0x18]
mov cl, [r11d+0x18]
cmp [eax+0x49b], cl
jnz short loc_1000515A
;movsx eax, byte [esp+0x14]
movsx eax, byte [r11d+0x14]
mov [eax+esi+0x216b2], bl
mov bl, 0x4
loc_10005132:
mov edi, [esi+0x240e8]
test edi, edi
jz short loc_1000515A
loc_1000513C:
;mov al, [esp+0x14]
mov al, [r11d+0x14]
cmp [edi+0x2], al
jnz short loc_10005150
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10008760
CALL loc_10008760
;add esp, 0xc
add r11d, 0xc
loc_10005150:
mov edi, [edi+0x37e]
test edi, edi
jnz short loc_1000513C
loc_1000515A:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
db 139
db 255
align 4
loc_10005160:
dd loc_10004EC0
dd loc_10004ED8
dd loc_10004EF1
dd loc_10004F0D
dd loc_10004F29
dd loc_10004F45
dd loc_10004F61
dd loc_10004F79
dd loc_10004F9A
dd loc_10004FBB
dd loc_10004FD4
dd loc_10004FED
dd loc_10005006
dd loc_1000501F
dd loc_1000503D
dd loc_1000505B
dd loc_1000515A
dd loc_10005079
dd loc_1000508F
dd loc_10005079
dd loc_100050A5
dd loc_100050B8
dd loc_100050CB
dd loc_100050DE
dd loc_100050F1
loc_100051C4:
db 0
times 4 db 24
db 1
db 2
db 3
db 24
db 24
db 4
db 5
times 20 db 24
db 6
times 31 db 24
db 7
db 8
times 25 db 24
db 9
db 24
db 10
db 24
db 24
db 11
db 12
db 13
db 14
db 15
db 16
times 18 db 24
db 17
db 18
db 24
db 19
db 20
db 21
db 22
db 23
times 12 db 204
align 4
loc_10005250:
;mov cl, [esp+0xc]
mov cl, [r11d+0xc]
;push ebx
PUSH32 ebx
;mov bl, [esp+0xc]
mov bl, [r11d+0xc]
;push esi
PUSH32 esi
movsx eax, bl
;push edi
PUSH32 edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
mov [eax+edi+0x216d2], cl
mov esi, [edi+0x240e8]
test esi, esi
jz short loc_1000528C
loc_10005273:
cmp [esi+0x2], bl
jnz short loc_10005282
;push esi
;push edi
PUSH32 esi, edi
;call loc_100086F0
CALL loc_100086F0
;add esp, 0x8
add r11d, 0x8
loc_10005282:
mov esi, [esi+0x37e]
test esi, esi
jnz short loc_10005273
loc_1000528C:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10005290:
;mov cl, [esp+0xc]
mov cl, [r11d+0xc]
;push ebx
PUSH32 ebx
;mov bl, [esp+0xc]
mov bl, [r11d+0xc]
;push esi
PUSH32 esi
movsx eax, bl
;push edi
PUSH32 edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
mov [eax+edi+0x216e2], cl
mov esi, [edi+0x240e8]
test esi, esi
jz short loc_100052CC
loc_100052B3:
cmp [esi+0x2], bl
jnz short loc_100052C2
;push esi
;push edi
PUSH32 esi, edi
;call loc_10008720
CALL loc_10008720
;add esp, 0x8
add r11d, 0x8
loc_100052C2:
mov esi, [esi+0x37e]
test esi, esi
jnz short loc_100052B3
loc_100052CC:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_100052D0:
;mov cl, [esp+0xc]
mov cl, [r11d+0xc]
;push ebx
PUSH32 ebx
;mov bl, [esp+0xc]
mov bl, [r11d+0xc]
;push esi
PUSH32 esi
movsx eax, bl
;push edi
PUSH32 edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
mov [eax+edi+0x216f2], cl
mov esi, [edi+0x240e8]
test esi, esi
jz short loc_1000530C
loc_100052F3:
cmp [esi+0x2], bl
jnz short loc_10005302
;push esi
;push edi
PUSH32 esi, edi
;call loc_100086F0
CALL loc_100086F0
;add esp, 0x8
add r11d, 0x8
loc_10005302:
mov esi, [esi+0x37e]
test esi, esi
jnz short loc_100052F3
loc_1000530C:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10005310:
;mov dl, [esp+0x8]
mov dl, [r11d+0x8]
;push ebx
PUSH32 ebx
;mov bl, [esp+0x10]
mov bl, [r11d+0x10]
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
movsx ecx, dl
test bl, bl
mov [ecx+eax+0x21702], bl
jnz short loc_10005351
mov eax, [eax+0x240cc]
test eax, eax
jz short loc_10005351
xor ecx, ecx
loc_10005337:
cmp [eax+0x2], dl
jnz short loc_10005347
cmp [eax], cl
jz short loc_10005347
cmp [eax+0x5], cl
jnz short loc_10005347
mov [eax], cl
loc_10005347:
mov eax, [eax+0x2346]
test eax, eax
jnz short loc_10005337
loc_10005351:
;pop ebx
POP32 ebx
;ret
RET
align 16
loc_10005360:
;mov dl, [esp+0x8]
mov dl, [r11d+0x8]
;push ebx
PUSH32 ebx
;mov bl, [esp+0x10]
mov bl, [r11d+0x10]
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
movsx ecx, dl
test bl, bl
mov [ecx+eax+0x21712], bl
jnz short loc_100053A2
mov eax, [eax+0x240cc]
test eax, eax
jz short loc_100053A2
xor ecx, ecx
loc_10005387:
cmp [eax+0x2], dl
jnz short loc_10005398
cmp [eax], cl
jz short loc_10005398
cmp [eax+0x5], cl
jnz short loc_10005398
mov [eax+0x1], cl
loc_10005398:
mov eax, [eax+0x2346]
test eax, eax
jnz short loc_10005387
loc_100053A2:
;pop ebx
POP32 ebx
;ret
RET
align 16
loc_100053B0:
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push ebx
PUSH32 ebx
;mov dl, [esp+0x10]
mov dl, [r11d+0x10]
;push esi
PUSH32 esi
;movsx si, byte [esp+0x10]
movsx si, byte [r11d+0x10]
movsx eax, si
;push edi
;push ebp
PUSH32 edi, ebp
mov [eax+ecx+0x21782], dl
lea ebx, [eax+ecx]
mov ax, si
mov ebp, [ecx+0x14]
imul ax, ax, 0x46
movsx edi, ax
lea edi, [edi+ebp+0x22]
;push 0x0
PUSH32 0x0
movsx dx, dl
movsx bp, byte [ebx+0x21762]
shl bp, 0x7
;push esi
PUSH32 esi
movsx ax, byte [ebx+0x21772]
or bp, ax
;push ecx
PUSH32 ecx
mov [edi+0x22], bp
mov [edi+0x44], dx
;call loc_10002DD0
CALL loc_10002DD0
;add esp, 0xc
add r11d, 0xc
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10005420:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;movsx edi, byte [esp+0x10]
movsx edi, byte [r11d+0x10]
lea ecx, [edi+esi]
cmp byte [ecx+0x217c2], 0x0
jz near loc_10005487
movsx eax, byte [ecx+0x217b2]
test eax, eax
jz short loc_1000544F
cmp eax, 0x1
jz short loc_1000546D
cmp eax, 0x2
jz near loc_1000547A
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_1000544F:
;mov al, [esp+0x14]
mov al, [r11d+0x14]
;push eax
PUSH32 eax
mov [ecx+0x217d2], al
;call loc_100063D0
CALL loc_100063D0
mov [esi+edi*2+0x217e2], ax
;add esp, 0x4
add r11d, 0x4
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_1000546D:
;mov al, [esp+0x14]
mov al, [r11d+0x14]
;pop edi
;pop esi
POP32 esi, edi
mov [ecx+0x21802], al
;ret
RET
loc_1000547A:
;mov al, [esp+0x14]
mov al, [r11d+0x14]
;pop edi
;pop esi
POP32 esi, edi
mov [ecx+0x21812], al
;ret
RET
loc_10005487:
movsx eax, byte [ecx+0x21792]
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_100054A0:
;mov dl, [esp+0x8]
mov dl, [r11d+0x8]
;sub esp, 0x4
sub r11d, 0x4
movsx eax, dl
;push esi
PUSH32 esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
lea ecx, [eax+esi]
movsx eax, byte [ecx+0x217b2]
test eax, eax
jz short loc_100054E3
cmp eax, 0x1
jz short loc_100054EB
cmp eax, 0x2
jz short loc_100054F3
;mov cl, [esp+0x7]
mov cl, [r11d+0x7]
loc_100054CB:
;add cl, [esp+0x14]
add cl, [r11d+0x14]
jns short loc_100054D3
xor cl, cl
loc_100054D3:
;push ecx
;push edx
;push esi
PUSH32 ecx, edx, esi
;call loc_10005420
CALL loc_10005420
;add esp, 0xc
add r11d, 0xc
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100054E3:
mov cl, [ecx+0x217d2]
jmp short loc_100054CB
loc_100054EB:
mov cl, [ecx+0x21802]
jmp short loc_100054CB
loc_100054F3:
mov cl, [ecx+0x21812]
jmp short loc_100054CB
align 16
loc_10005500:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov eax, [eax+0x240cc]
test eax, eax
jz short loc_10005521
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
loc_10005512:
cmp [eax+0x8], ecx
jz short loc_10005523
mov eax, [eax+0x2346]
test eax, eax
jnz short loc_10005512
loc_10005521:
xor eax, eax
loc_10005523:
;ret
RET
align 16
loc_10005530:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
cmp byte [esi], 0x0
jnz short loc_1000554E
;mov al, [esp+0x18]
mov al, [r11d+0x18]
;push esi
PUSH32 esi
mov byte [esi], 0x1
mov [esi+0x5], al
;call loc_10007B00
CALL loc_10007B00
;add esp, 0x4
add r11d, 0x4
loc_1000554E:
;mov al, [esp+0x14]
mov al, [r11d+0x14]
mov cl, [esi+0x38b]
add cl, al
mov [esi+0x3], al
mov eax, [esi+0x386]
mov [esi+0x4], cl
test eax, eax
jz short loc_10005577
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
;push esi
;push edi
PUSH32 esi, edi
;call eax
mov r9d, eax
CALL r9
;add esp, 0x8
add r11d, 0x8
jmp short loc_1000557B
loc_10005577:
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
loc_1000557B:
mov eax, [esi+0x36e]
test eax, eax
jz short loc_1000558C
;push esi
;push edi
PUSH32 esi, edi
;call eax
mov r9d, eax
CALL r9
;add esp, 0x8
add r11d, 0x8
loc_1000558C:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10005590:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push esi
PUSH32 esi
mov edx, [eax+0x240cc]
test edx, edx
jz short loc_100055D1
mov ecx, [edx+0x2346]
test ecx, ecx
jz short loc_100055C3
loc_100055A9:
mov esi, [edx+0x37e]
cmp [ecx+0x37e], esi
jae short loc_100055B9
mov edx, ecx
loc_100055B9:
mov ecx, [ecx+0x2346]
test ecx, ecx
jnz short loc_100055A9
loc_100055C3:
test edx, edx
jz short loc_100055D1
;push edx
;push eax
PUSH32 edx, eax
;call loc_10003810
CALL loc_10003810
;add esp, 0x8
add r11d, 0x8
loc_100055D1:
;pop esi
POP32 esi
;ret
RET
align 16
loc_100055E0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
mov edi, [esi+0x240cc]
test edi, edi
jz short loc_10005613
;mov bl, [esp+0x14]
mov bl, [r11d+0x14]
loc_100055F5:
cmp [edi+0x2], bl
jnz short loc_10005609
cmp byte [edi], 0x0
jz short loc_10005609
;push edi
;push esi
PUSH32 edi, esi
;call loc_10003810
CALL loc_10003810
;add esp, 0x8
add r11d, 0x8
loc_10005609:
mov edi, [edi+0x2346]
test edi, edi
jnz short loc_100055F5
loc_10005613:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10005620:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
PUSH32 edi, ebp
mov eax, [esi+0x240cc]
test eax, eax
jz short loc_10005668
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
;mov ebx, [esp+0x1c]
mov ebx, [r11d+0x1c]
loc_1000563A:
cmp [eax+0x374], edi
jnz short loc_1000565E
cmp [eax+0x37a], ebx
jnz short loc_1000565E
mov ebp, [eax+0x2346]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10003810
CALL loc_10003810
;add esp, 0x8
add r11d, 0x8
mov eax, ebp
jmp short loc_10005664
loc_1000565E:
mov eax, [eax+0x2346]
loc_10005664:
test eax, eax
jnz short loc_1000563A
loc_10005668:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10005670:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
PUSH32 edi, ebp
mov eax, [esi+0x240cc]
test eax, eax
jz short loc_100056BA
;mov bx, [esp+0x1c]
mov bx, [r11d+0x1c]
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
loc_1000568B:
cmp [eax+0x374], edi
jnz short loc_100056B0
cmp [eax+0x378], bx
jnz short loc_100056B0
mov ebp, [eax+0x2346]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10003810
CALL loc_10003810
;add esp, 0x8
add r11d, 0x8
mov eax, ebp
jmp short loc_100056B6
loc_100056B0:
mov eax, [eax+0x2346]
loc_100056B6:
test eax, eax
jnz short loc_1000568B
loc_100056BA:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_100056C0:
;cmp byte [esp+0x10], 0x0
cmp byte [r11d+0x10], 0x0
jz short loc_100056E8
;call timeGetTime
CALL timeGetTime
;movsx edx, byte [esp+0x8]
movsx edx, byte [r11d+0x8]
;movsx ecx, byte [esp+0xc]
movsx ecx, byte [r11d+0xc]
shl edx, 0x7
add edx, ecx
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
mov [ecx+edx*4+0x22026], eax
;ret
RET
loc_100056E8:
;movsx edx, byte [esp+0x8]
movsx edx, byte [r11d+0x8]
;movsx eax, byte [esp+0xc]
movsx eax, byte [r11d+0xc]
shl edx, 0x7
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
add edx, eax
mov dword [ecx+edx*4+0x22026], 0x0
;ret
RET
align 16
loc_10005710:
;push ebx
PUSH32 ebx
mov al, 0xff
;movsx ecx, byte [esp+0x10]
movsx ecx, byte [r11d+0x10]
;push esi
;push edi
PUSH32 esi, edi
xor edi, edi
cmp ecx, 0x2
jz short loc_1000572F
cmp ecx, 0x3
jz short loc_1000575F
cmp ecx, 0x4
jz near loc_10005790
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000572F:
xor dx, dx
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx ebx, byte [esp+0x14]
movsx ebx, byte [r11d+0x14]
shl ebx, 0x7
loc_1000573E:
movsx ecx, dx
add ecx, ebx
mov ecx, [esi+ecx*4+0x22026]
cmp edi, ecx
jae short loc_10005752
mov edi, ecx
mov al, dl
loc_10005752:
inc dx
cmp dx, 0x80
jl short loc_1000573E
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000575F:
xor edx, edx
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx ecx, byte [esp+0x14]
movsx ecx, byte [r11d+0x14]
shl ecx, 0x7
xor edi, edi
loc_1000576F:
movsx ebx, dx
add ebx, ecx
cmp [esi+ebx*4+0x22026], edi
jnz short loc_1000578A
inc dx
cmp dx, 0x80
jl short loc_1000576F
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000578A:
mov al, dl
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10005790:
mov dx, 0x7f
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;movsx ecx, byte [esp+0x14]
movsx ecx, byte [r11d+0x14]
shl ecx, 0x7
xor edi, edi
loc_100057A2:
movsx ebx, dx
add ebx, ecx
cmp [esi+ebx*4+0x22026], edi
jnz short loc_100057B8
dec dx
jns short loc_100057A2
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_100057B8:
mov al, dl
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_100057C0:
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
lea edi, [edx+0x2406c]
inc edi
mov al, [edi-0x1]
mov cl, [edi]
inc edi
movsx eax, al
cmp eax, 0x41
jz short loc_100057F2
cmp eax, 0x7e
jz near loc_100058A6
cmp eax, 0x7f
jz near loc_100058F9
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_100057F2:
cmp word [edx+0x2406a], 0x9
jnz near loc_1000590B
mov al, [edi]
inc edi
cmp al, 0x42
jnz near loc_1000590B
mov al, [edi]
inc edi
cmp al, 0x12
jnz near loc_1000590B
movsx eax, byte [edi]
movsx esi, byte [edi+0x1]
movsx ecx, byte [edi+0x2]
shl eax, 0x8
mov bl, [edi+0x3]
inc edi
or esi, eax
shl esi, 0x8
inc edi
or ecx, esi
mov eax, ecx
and eax, 0x7ff0ff
cmp eax, 0x40007f
jz short loc_10005849
cmp eax, 0x401015
jz near loc_10005888
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10005849:
movsx eax, bl
xor cl, cl
test eax, eax
jz short loc_10005859
cmp eax, 0x7f
jz short loc_10005865
jmp short loc_10005871
loc_10005859:
cmp byte [edx+0x61], 0x0
jnz short loc_10005871
mov byte [edx+0x61], 0x1
jmp short loc_1000586F
loc_10005865:
cmp byte [edx+0x61], 0x0
jz short loc_10005871
mov byte [edx+0x61], 0x0
loc_1000586F:
mov cl, 0x1
loc_10005871:
test cl, cl
jz near loc_1000590B
;push 0x0
PUSH32 0x0
;push edx
PUSH32 edx
;call loc_10003260
CALL loc_10003260
;add esp, 0x8
add r11d, 0x8
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10005888:
cmp bl, 0x1
jle short loc_1000589C
shr ecx, 0x8
;pop edi
POP32 edi
and cx, 0xf
;pop esi
POP32 esi
mov [edx+0x62], cx
;pop ebx
POP32 ebx
;ret
RET
loc_1000589C:
mov word [edx+0x62], 0xffff
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_100058A6:
cmp cl, 0x7f
jnz near loc_1000590B
cmp word [edx+0x2406a], 0x4
jnz near loc_1000590B
mov al, [edi+0x1]
cmp byte [edi], 0x9
jnz near loc_1000590B
movsx eax, al
xor cl, cl
cmp eax, 0x1
jz short loc_100058CE
cmp eax, 0x2
jz short loc_100058DA
jmp short loc_100058E6
loc_100058CE:
cmp byte [edx+0x60], 0x0
jnz short loc_100058E6
mov byte [edx+0x60], 0x1
jmp short loc_100058E4
loc_100058DA:
cmp byte [edx+0x60], 0x0
jz short loc_100058E6
mov byte [edx+0x60], 0x0
loc_100058E4:
mov cl, 0x1
loc_100058E6:
test cl, cl
jz short loc_1000590B
;push 0x0
PUSH32 0x0
;push edx
PUSH32 edx
;call loc_10003260
CALL loc_10003260
;add esp, 0x8
add r11d, 0x8
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_100058F9:
cmp cl, 0x7f
jnz short loc_1000590B
cmp word [edx+0x2406a], 0x6
jnz short loc_1000590B
mov al, [edi+0x1]
loc_1000590B:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10005910:
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
mov eax, [edx+0x4]
mov [ecx], eax
mov eax, [edx+0x8]
mov [ecx+0x4], eax
mov eax, [edx+0x18]
mov eax, [eax+0x4]
mov eax, [eax+0x4]
mov [ecx+0x8], eax
mov eax, [edx+0x18]
mov eax, [eax+0x4]
mov eax, [eax]
mov [ecx+0xc], eax
mov ax, [edx+0x240d6]
mov [ecx+0x10], ax
mov ax, [edx+0x240f2]
mov [ecx+0x12], ax
mov dx, [edx+0x10]
mov [ecx+0x14], dx
;ret
RET
align 16
loc_10005960:
;sub esp, 0x80
sub r11d, 0x80
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x90]
mov esi, [r11d+0x90]
;push edi
PUSH32 edi
mov di, 0x1
;push ebp
PUSH32 ebp
test esi, esi
jnz short loc_1000599E
;mov eax, [esp+0xa8]
mov eax, [r11d+0xa8]
;lea ecx, [esp+0x10]
lea ecx, [r11d+0x10]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10005AD0
CALL loc_10005AD0
;lea ecx, [esp+0x18]
lea ecx, [r11d+0x18]
;add esp, 0x8
add r11d, 0x8
;push ecx
PUSH32 ecx
;call loc_10005CB0
CALL loc_10005CB0
mov di, ax
;add esp, 0x4
add r11d, 0x4
loc_1000599E:
movsx eax, di
mov ecx, eax
shl eax, 0x3
sub eax, ecx
lea ecx, [eax*8+0x1a]
;push ecx
PUSH32 ecx
;push 0x40
PUSH32 0x40
;call GlobalAlloc
CALL GlobalAlloc
mov ebx, eax
;mov eax, [esp+0xa4]
mov eax, [r11d+0xa4]
test ebx, ebx
mov [eax], ebx
jnz short loc_100059D7
mov eax, 0x2
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x80
add r11d, 0x80
;ret
RET
loc_100059D7:
;mov eax, [esp+0x9c]
mov eax, [r11d+0x9c]
;mov ecx, [esp+0xa0]
mov ecx, [r11d+0xa0]
xor ebp, ebp
mov [ebx], eax
mov eax, 0xffffffff
mov [ebx+0x4], ecx
mov [ebx+0x8], esi
test esi, esi
mov dword [ebx+0xc], 0x5622
mov [ebx+0x10], ebp
mov [ebx+0x14], ax
mov [ebx+0x16], ax
mov [ebx+0x18], di
jnz near loc_10005A40
test di, di
jle near loc_10005A49
loc_10005A13:
;lea eax, [esp+0x50]
lea eax, [r11d+0x50]
;lea ecx, [esp+0x10]
lea ecx, [r11d+0x10]
;push eax
;push ebp
PUSH32 eax, ebp
;push 0x0
PUSH32 0x0
;push ecx
PUSH32 ecx
;call loc_10005D20
CALL loc_10005D20
;lea ecx, [esp+0x60]
lea ecx, [r11d+0x60]
;add esp, 0x10
add r11d, 0x10
;push ecx
;push ebp
PUSH32 ecx, ebp
inc bp
;push ebx
PUSH32 ebx
;call loc_10005DB0
CALL loc_10005DB0
;add esp, 0xc
add r11d, 0xc
cmp di, bp
jg near loc_10005A13
jmp short loc_10005A49
loc_10005A40:
;push ebx
PUSH32 ebx
;call loc_10005EB0
CALL loc_10005EB0
;add esp, 0x4
add r11d, 0x4
loc_10005A49:
;push ebx
PUSH32 ebx
;call loc_10005FF0
CALL loc_10005FF0
;add esp, 0x4
add r11d, 0x4
;push ebx
PUSH32 ebx
;call loc_100060A0
CALL loc_100060A0
;add esp, 0x4
add r11d, 0x4
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x80
add r11d, 0x80
;ret
RET
align 16
loc_10005A70:
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
test edi, edi
jz near loc_10005ACA
mov bx, [edi+0x18]
lea ebp, [edi+0x1a]
test bx, bx
jle short loc_10005AC3
mov esi, CloseHandle
loc_10005A8E:
cmp dword [edi+0x8], 0x0
jnz short loc_10005ABC
mov eax, [ebp]
;push eax
PUSH32 eax
;call esi
mov r9d, esi
CALL r9
mov dword [ebp], 0xffffffff
mov eax, [ebp+0x34]
test eax, eax
jz short loc_10005ABC
cmp dword [edi+0x8], 0x0
jnz short loc_10005ABC
;push eax
PUSH32 eax
;call GlobalFree
CALL GlobalFree
mov dword [ebp+0x34], 0x0
loc_10005ABC:
add ebp, 0x38
dec bx
jnz short loc_10005A8E
loc_10005AC3:
;push edi
PUSH32 edi
;call GlobalFree
CALL GlobalFree
loc_10005ACA:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10005AD0:
;sub esp, 0x40
sub r11d, 0x40
mov ecx, loc_1001B414
;push ebx
PUSH32 ebx
mov eax, [ecx]
mov ebx, ecx ; fix overwriting input string
;push esi
;push edi
;push ebp
PUSH32 esi, edi, ebp
;mov ebp, [esp+0x54]
mov ebp, [r11d+0x54]
;push 0x20
PUSH32 0x20
;push ebp
PUSH32 ebp
mov [ebx], eax
mov edx, [ecx+0x4]
mov edi, loc_1001B410
mov [ebx+0x4], edx
mov cl, [ecx+0x8]
mov [ebx+0x8], cl
;call GetWindowsDirectoryA
CALL GetWindowsDirectoryA
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
mov edi, ebp
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
mov edi, loc_1001B404
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
mov edi, ebp
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
mov edi, loc_1001B410
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
mov edi, ebp
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
loc_10005B91:
mov cl, [ebx]
cmp cl, 0x7c
jz short loc_10005BA1
mov [eax], cl
inc ebx
inc eax
cmp byte [ebx], 0x0
jnz short loc_10005B91
loc_10005BA1:
mov byte [eax], 0x0
mov eax, ebx
inc ebx
cmp byte [eax], 0x7c
jnz near loc_10005C65
mov edi, ebp
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov eax, ecx
shr ecx, 0x2
mov esi, edi
;lea edi, [esp+0x30]
lea edi, [r11d+0x30]
;rep movsd
rep a32 movsd
mov ecx, eax
and ecx, 0x3
;rep movsb
rep a32 movsb
;lea edi, [esp+0x10]
lea edi, [r11d+0x10]
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
;lea edi, [esp+0x30]
lea edi, [r11d+0x30]
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
;lea eax, [esp+0x30]
lea eax, [r11d+0x30]
;push eax
PUSH32 eax
;call SetCurrentDirectoryA
CALL SetCurrentDirectoryA
test eax, eax
jnz short loc_10005C25
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
loc_10005C17:
mov cl, [ebx]
inc ebx
mov [eax], cl
inc eax
cmp byte [ebx], 0x0
jnz short loc_10005C17
mov byte [eax], 0x0
loc_10005C25:
;lea edi, [esp+0x10]
lea edi, [r11d+0x10]
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
mov edi, ebp
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
;push 0x0
PUSH32 0x0
and ecx, 0x3
;push ebp
PUSH32 ebp
;rep movsb
rep a32 movsb
;call CreateDirectoryA
CALL CreateDirectoryA
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x40
add r11d, 0x40
;ret
RET
loc_10005C65:
;lea edi, [esp+0x10]
lea edi, [r11d+0x10]
mov ecx, 0xffffffff
sub eax, eax
;repne scasb
repne a32 scasb
not ecx
sub edi, ecx
mov edx, ecx
mov esi, edi
mov ecx, 0xffffffff
mov edi, ebp
sub eax, eax
;repne scasb
repne a32 scasb
dec edi
mov ecx, edx
shr ecx, 0x2
;rep movsd
rep a32 movsd
mov ecx, edx
;push 0x0
PUSH32 0x0
and ecx, 0x3
;push ebp
PUSH32 ebp
;rep movsb
rep a32 movsb
;call CreateDirectoryA
CALL CreateDirectoryA
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x40
add r11d, 0x40
;ret
RET
align 16
loc_10005CB0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;sub esp, 0x140
sub r11d, 0x140
;push ebx
;push esi
;push edi
;push eax
PUSH32 ebx, esi, edi, eax
;call SetCurrentDirectoryA
CALL SetCurrentDirectoryA
;lea ecx, [esp+0xc]
lea ecx, [r11d+0xc]
;push ecx
PUSH32 ecx
;push loc_1001B420
PUSH32 loc_1001B420
;call FindFirstFileA
CALL FindFirstFileA
cmp eax, 0xffffffff
mov ebx, eax
jnz short loc_10005CE8
xor ax, ax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x140
add r11d, 0x140
;ret
RET
loc_10005CE8:
mov di, 0x1
mov esi, FindNextFileA
loc_10005CF2:
;lea eax, [esp+0xc]
lea eax, [r11d+0xc]
;push eax
;push ebx
PUSH32 eax, ebx
;call esi
mov r9d, esi
CALL r9
test eax, eax
jz short loc_10005D04
inc di
test eax, eax
jnz short loc_10005CF2
loc_10005D04:
;push ebx
PUSH32 ebx
;call FindClose
CALL FindClose
mov ax, di
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x140
add r11d, 0x140
;ret
RET
align 16
loc_10005D20:
;sub esp, 0x140
sub r11d, 0x140
;lea eax, [esp]
lea eax, [r11d]
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov esi, [esp+0x15c]
mov esi, [r11d+0x15c]
;push ebp
;push eax
PUSH32 ebp, eax
;push loc_1001B420
PUSH32 loc_1001B420
mov byte [esi], 0x0
;call FindFirstFileA
CALL FindFirstFileA
cmp eax, 0xffffffff
mov edi, eax
jnz short loc_10005D5B
mov eax, 0x4
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x140
add r11d, 0x140
;ret
RET
loc_10005D5B:
;mov bx, [esp+0x15c]
mov bx, [r11d+0x15c]
test bx, bx
jz short loc_10005D85
mov bp, 0x1
loc_10005D6C:
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;push eax
;push edi
PUSH32 eax, edi
;call FindNextFileA
CALL FindNextFileA
cmp bp, bx
jz short loc_10005D85
inc bp
test eax, eax
jnz short loc_10005D6C
jmp short loc_10005D93
loc_10005D85:
;lea eax, [esp+0x3c]
lea eax, [r11d+0x3c]
;push esi
;push eax
PUSH32 esi, eax
;call loc_10006C10
CALL loc_10006C10
;add esp, 0x8
add r11d, 0x8
loc_10005D93:
;push edi
PUSH32 edi
;call FindClose
CALL FindClose
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x140
add r11d, 0x140
;ret
RET
align 16
loc_10005DB0:
;movsx ecx, word [esp+0x8]
movsx ecx, word [r11d+0x8]
;sub esp, 0xc
sub r11d, 0xc
mov eax, ecx
shl ecx, 0x3
;push ebx
;push esi
PUSH32 ebx, esi
sub ecx, eax
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
;push edi
;push ebp
PUSH32 edi, ebp
lea eax, [esi+ecx*8+0x1e]
lea edi, [esi+ecx*8+0x1a]
;push eax
PUSH32 eax
;mov ebx, [esp+0x2c]
mov ebx, [r11d+0x2c]
mov dword [edi], 0xffffffff
;push ebx
PUSH32 ebx
;call loc_10006C10
CALL loc_10006C10
;add esp, 0x8
add r11d, 0x8
;push 0x0
PUSH32 0x0
;push 0x80
PUSH32 0x80
;push 0x3
PUSH32 0x3
mov ebp, CreateFileA
;push 0x0
PUSH32 0x0
;push 0x1
PUSH32 0x1
;push 0x80000000
PUSH32 0x80000000
;push ebx
PUSH32 ebx
;call ebp
mov r9d, ebp
CALL r9
mov [edi], eax
cmp eax, 0xffffffff
jz near loc_10005EA1
lea ebx, [edi+0x26]
;push 0x0
PUSH32 0x0
;lea ecx, [esp+0x14]
lea ecx, [r11d+0x14]
mov ebp, ReadFile
;push ecx
PUSH32 ecx
;push 0xe
PUSH32 0xe
;push ebx
;push eax
PUSH32 ebx, eax
;call ebp
mov r9d, ebp
CALL r9
cmp eax, 0x1
sbb eax, eax
neg eax
test eax, eax
jnz near loc_10005EA1
cmp byte [ebx+0x4], 0x0
jz near loc_10005EA1
mov eax, [ebx]
cmp eax, 0x64656d6f
jz near loc_10005EA1
sub eax, 0x676d2020
cmp eax, 0x1
sbb al, al
neg al
mov [edi+0x24], al
mov ecx, [esi+0x10]
test ecx, ecx
jg short loc_10005E5D
mov eax, [ebx+0x6]
mov [esi+0xc], eax
mov ecx, [ebx+0xa]
mov [esi+0x10], ecx
jmp short loc_10005E6A
loc_10005E5D:
mov eax, [esi+0xc]
cmp [ebx+0x6], eax
jnz near loc_10005EA1
cmp [ebx+0xa], ecx
jnz near loc_10005EA1
loc_10005E6A:
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;push 0x0
PUSH32 0x0
;lea ecx, [esp+0x18]
lea ecx, [r11d+0x18]
;push eax
PUSH32 eax
;push 0x8
PUSH32 0x8
mov edx, [edi]
;push ecx
;push edx
PUSH32 ecx, edx
;call ebp
mov r9d, ebp
CALL r9
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
sub esi, 0x8
;push esi
PUSH32 esi
;push 0x0
PUSH32 0x0
;call GlobalAlloc
CALL GlobalAlloc
;push 0x0
PUSH32 0x0
mov [edi+0x34], eax
;lea eax, [esp+0x14]
lea eax, [r11d+0x14]
mov ecx, [edi+0x34]
;push eax
PUSH32 eax
mov edx, [edi]
;push esi
;push ecx
;push edx
PUSH32 esi, ecx, edx
;call ebp
mov r9d, ebp
CALL r9
loc_10005EA1:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 16
loc_10005EB0:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
lea eax, [esi+0x1e]
lea edi, [esi+0x1a]
;push eax
PUSH32 eax
;push loc_1001B428
PUSH32 loc_1001B428
mov dword [edi], 0xffffffff
;call loc_10006C10
CALL loc_10006C10
;add esp, 0x8
add r11d, 0x8
mov ecx, [esi+0x8]
cmp byte [ecx+0x4], 0x0
jz short loc_10005EEB
mov eax, [ecx+0x6]
add ecx, 0x16
mov [esi+0xc], eax
mov edx, [ecx-0xc]
mov [esi+0x10], edx
mov [edi+0x34], ecx
loc_10005EEB:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10005EF0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;sub esp, 0x4
sub r11d, 0x4
;push esi
;push edi
PUSH32 esi, edi
mov esi, [eax+0x8]
test esi, esi
jz short loc_10005F2B
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
mov edx, [edi+0x4]
mov eax, [edi]
mov ecx, eax
shl eax, 0x3
sub eax, ecx
mov ecx, edx
shr ecx, 0x2
lea edi, [esi+eax*2]
;mov esi, [esp+0x20]
mov esi, [r11d+0x20]
;rep movsd
rep a32 movsd
mov ecx, edx
and ecx, 0x3
;rep movsb
rep a32 movsb
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10005F2B:
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
;push 0x0
PUSH32 0x0
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
;push 0x0
PUSH32 0x0
mov eax, [edi]
;push eax
;push esi
PUSH32 eax, esi
;call SetFilePointer
CALL SetFilePointer
;push 0x0
PUSH32 0x0
mov ecx, [edi+0x4]
;mov edx, [esp+0x24]
mov edx, [r11d+0x24]
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;lea eax, [esp+0xc]
lea eax, [r11d+0xc]
;push eax
;push ecx
;push edx
;push esi
PUSH32 eax, ecx, edx, esi
;call ReadFile
CALL ReadFile
;pop edi
;pop esi
POP32 esi, edi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10005F70:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
cmp dword [eax], 0x67732020
movsx ax, byte [eax+0x5]
jnz short loc_10005F86
shl ax, 0x7
;ret
RET
loc_10005F86:
;ret
RET
align 16
loc_10005F90:
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;mov di, [esp+0x18]
mov di, [r11d+0x18]
cmp di, 0x7f
jz near loc_10005FE2
cmp di, 0x7e
jz near loc_10005FE2
xor bx, bx
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
cmp [esi+0x18], bx
lea ebp, [esi+0x1a]
jle short loc_10005FD1
loc_10005FB5:
lea eax, [ebp+0x26]
;push eax
PUSH32 eax
;call loc_10005F70
CALL loc_10005F70
;add esp, 0x4
add r11d, 0x4
cmp ax, di
jz short loc_10005FDA
inc bx
add ebp, 0x38
cmp [esi+0x18], bx
jg short loc_10005FB5
loc_10005FD1:
mov ax, 0xffff
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10005FDA:
mov ax, bx
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10005FE2:
mov ax, di
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10005FF0:
;sub esp, 0x3c
sub r11d, 0x3c
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x48]
mov ebx, [r11d+0x48]
;push edi
;push ebp
PUSH32 edi, ebp
loc_10005FFB:
xor eax, eax
;mov [esp+0x12], ax
mov [r11d+0x12], ax
;mov [esp+0x11], al
mov [r11d+0x11], al
movsx eax, word [ebx+0x18]
dec eax
test eax, eax
jle near loc_10006082
loc_1000600F:
;movsx eax, word [esp+0x12]
movsx eax, word [r11d+0x12]
mov ecx, eax
shl eax, 0x3
sub eax, ecx
lea ecx, [ebx+eax*8+0x40]
;push ecx
PUSH32 ecx
lea ebp, [ebx+eax*8]
;call loc_10005F70
CALL loc_10005F70
mov si, ax
;add esp, 0x4
add r11d, 0x4
lea eax, [ebp+0x78]
;push eax
PUSH32 eax
;call loc_10005F70
CALL loc_10005F70
;add esp, 0x4
add r11d, 0x4
cmp ax, si
jge short loc_1000606F
lea eax, [ebp+0x1a]
;lea edi, [esp+0x14]
lea edi, [r11d+0x14]
mov esi, eax
mov ecx, 0xe
;rep movsd
rep a32 movsd
add ebp, 0x52
mov edi, eax
mov esi, ebp
mov ecx, 0xe
;rep movsd
rep a32 movsd
;lea esi, [esp+0x14]
lea esi, [r11d+0x14]
mov edi, ebp
mov ecx, 0xe
;rep movsd
rep a32 movsd
;mov byte [esp+0x11], 0x1
mov byte [r11d+0x11], 0x1
loc_1000606F:
movsx eax, word [ebx+0x18]
;inc word [esp+0x12]
inc word [r11d+0x12]
dec eax
;movsx ecx, word [esp+0x12]
movsx ecx, word [r11d+0x12]
cmp eax, ecx
jg near loc_1000600F
loc_10006082:
;cmp byte [esp+0x11], 0x0
cmp byte [r11d+0x11], 0x0
jnz near loc_10005FFB
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x3c
add r11d, 0x3c
;ret
RET
align 16
loc_100060A0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
mov dx, [esi+0x18]
xor edi, edi
cmp dx, di
lea eax, [esi+0x1a]
jle short loc_100060E2
xor ebx, ebx
loc_100060B7:
lea ecx, [eax+0x26]
cmp dword [ecx], 0x676d2020
jnz short loc_100060C7
cmp [ecx+0x5], bl
jz short loc_100060D5
loc_100060C7:
inc di
add eax, 0x38
cmp dx, di
jg short loc_100060B7
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_100060D5:
movsx ax, byte [ecx+0x5]
mov [esi+0x14], ax
mov [esi+0x16], di
loc_100060E2:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_100060F0:
;push esi
PUSH32 esi
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
mov byte [esi], 0x1
; remove useless check
mov byte [esi+0x1], 0x1
; remove useless check
;push esi
PUSH32 esi
;call loc_100061C0
CALL loc_100061C0
;add esp, 0x4
add r11d, 0x4
lea eax, [esi+0x482]
;push eax
PUSH32 eax
;call loc_10006220
CALL loc_10006220
;add esp, 0x4
add r11d, 0x4
lea eax, [esi+0x48e]
;push eax
PUSH32 eax
;call loc_10006250
CALL loc_10006250
;add esp, 0x4
add r11d, 0x4
xor eax, eax
mov ecx, 0x1
mov [esi+0x498], al
mov [esi+0x499], cl
mov [esi+0x2], al
mov byte [esi+0x49b], 0x2
mov [esi+0x49a], cl
; remove useless check
mov word [esi+0x49c], 0x20
; remove useless check
mov dword [esi+0x4a2], 0x600000
mov byte [esi+0x4a6], 0x0
mov byte [esi+0x4a7], 0x1
mov dword [esi+0x4a8], 0x5622
mov dword [esi+0x4ac], 0x100
mov word [esi+0x49e], 0x3
mov word [esi+0x4a0], 0x23
;pop esi
POP32 esi
;ret
RET
align 16
loc_100061C0:
;push esi
;push edi
PUSH32 esi, edi
xor di, di
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
loc_100061C9:
movsx eax, di
;push edi
PUSH32 edi
mov ecx, eax
shl eax, 0x3
inc di
sub eax, ecx
lea ecx, [eax+eax*4]
lea eax, [esi+ecx*2]
add eax, 0x22
;push eax
PUSH32 eax
;call loc_10006200
CALL loc_10006200
;add esp, 0x8
add r11d, 0x8
cmp di, 0x10
jl short loc_100061C9
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10006200:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
xor ecx, ecx
mov [eax+0x22], cx
mov byte [eax], 0x1
mov [eax+0x44], cx
mov [eax+0x1], cl
mov [eax+0x2], cl
mov [eax+0x24], cl
;ret
RET
align 16
loc_10006220:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov ecx, 0x3fff
mov [eax+0x2], cx
mov byte [eax], 0x1
mov byte [eax+0x1], 0x0
mov word [eax+0x4], 0xfff
mov word [eax+0x6], 0x1fff
mov [eax+0x8], cx
mov [eax+0xa], cx
;ret
RET
align 16
loc_10006250:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov ecx, 0x1fff
mov [eax+0x2], cx
mov byte [eax], 0x1
mov byte [eax+0x1], 0x2
mov word [eax+0x6], 0x4ccc
mov word [eax+0x8], 0x3fff
mov [eax+0x4], cx
;ret
RET
align 16
loc_10006280:
;movsx eax, word [esp+0x4]
movsx eax, word [r11d+0x4]
cdq
xor eax, edx
sub eax, edx
;ret
RET
align 16
loc_10006290:
;movsx eax, word [esp+0x8]
movsx eax, word [r11d+0x8]
;movsx ecx, word [esp+0x4]
movsx ecx, word [r11d+0x4]
add eax, ecx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_100062B0:
;movsx eax, word [esp+0x4]
movsx eax, word [r11d+0x4]
;movsx ecx, word [esp+0x8]
movsx ecx, word [r11d+0x8]
sub eax, ecx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_100062D0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;sub esp, 0xc
sub r11d, 0xc
;mov dword [esp], 0x0
mov dword [r11d], 0x0
;mov edx, [esp]
mov edx, [r11d]
;push 0xa
PUSH32 0xa
;push eax
;push edx
PUSH32 eax, edx
;call LargeIntegerShiftRight_asm
CALL LargeIntegerShiftRight_asm
;lea ecx, [esp+0x8]
lea ecx, [r11d+0x8]
;mov [esp+0x4], edx
mov [r11d+0x4], edx
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push ecx
PUSH32 ecx
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
;push edx
;push ecx
;push eax
PUSH32 edx, ecx, eax
;call ExtendedLargeIntegerDivide_asm
CALL ExtendedLargeIntegerDivide_asm
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 16
loc_10006310:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;sub esp, 0x8
sub r11d, 0x8
;push eax
;push ecx
PUSH32 eax, ecx
;call EnlargedIntegerMultiply_asm
CALL EnlargedIntegerMultiply_asm
;push 0x16
PUSH32 0x16
;push edx
;push eax
PUSH32 edx, eax
;call LargeIntegerShiftRight_asm
CALL LargeIntegerShiftRight_asm
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_10006330:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;sub esp, 0x8
sub r11d, 0x8
;push eax
PUSH32 eax
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
and eax, 0xffff
;push eax
PUSH32 eax
;call EnlargedIntegerMultiply_asm
CALL EnlargedIntegerMultiply_asm
;push 0xf
PUSH32 0xf
;push edx
;push eax
PUSH32 edx, eax
;call LargeIntegerShiftRight_asm
CALL LargeIntegerShiftRight_asm
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_10006360:
;movsx edx, word [esp+0x8]
movsx edx, word [r11d+0x8]
;movsx eax, word [esp+0x4]
movsx eax, word [r11d+0x4]
imul edx, eax
mov ecx, edx
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
sar ecx, 0xf
and dx, 0x7fff
mov [eax], cx
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
mov [eax], dx
;ret
RET
align 16
loc_10006390:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
cmp eax, 0x7fff
jle short loc_100063A0
mov ax, 0x7fff
;ret
RET
loc_100063A0:
cmp eax, 0xffff8000
jge short loc_100063AB
mov ax, 0x8000
loc_100063AB:
;ret
RET
align 16
loc_100063B0:
xor ax, ax
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
test ecx, ecx
jz short loc_100063C4
loc_100063BB:
shr ecx, 0x1
inc ax
test ecx, ecx
jnz short loc_100063BB
loc_100063C4:
;ret
RET
align 16
loc_100063D0:
;movsx ax, byte [esp+0x4]
movsx ax, byte [r11d+0x4]
imul ax, ax, 0x2a
;ret
RET
align 16
loc_100063E0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push ebx
PUSH32 ebx
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
;push esi
;push edi
PUSH32 esi, edi
mov eax, [eax+0x14]
add eax, 0x48e
mov [ecx], eax
movsx edx, word [eax+0x2]
lea eax, [edx+edx*4]
lea ebx, [eax+eax*4]
xor edx, edx
lea eax, [ebx+ebx*4]
shl eax, 0x3
sar eax, 0xf
mov [ecx+0xa], ax
xor eax, eax
mov [ecx+0xc], ax
loc_10006414:
movsx esi, ax
inc ax
mov [ecx+esi*2+0xe], dx
cmp ax, 0x3e8
jl short loc_10006414
mov word [ecx+0x7de], 0x0
mov eax, [ecx]
movsx eax, byte [eax+0x1]
test eax, eax
jz short loc_10006467
cmp eax, 0x1
jz short loc_1000648D
cmp eax, 0x2
jz short loc_100064B3
mov word [ecx+0x7e0], 0x71
mov word [ecx+0x1784], 0x8b
mov word [ecx+0x2728], 0xdd
mov word [ecx+0x36cc], 0x117
jmp short loc_100064D7
loc_10006467:
mov word [ecx+0x7e0], 0x71
mov word [ecx+0x1784], 0x8b
mov word [ecx+0x2728], 0xdd
mov word [ecx+0x36cc], 0x117
jmp short loc_100064D7
loc_1000648D:
mov word [ecx+0x7e0], 0xc5
mov word [ecx+0x1784], 0xef
mov word [ecx+0x2728], 0x15b
mov word [ecx+0x36cc], 0x1df
jmp short loc_100064D7
loc_100064B3:
mov word [ecx+0x7e0], 0x19b
mov word [ecx+0x1784], 0x21b
mov word [ecx+0x2728], 0x2eb
mov word [ecx+0x36cc], 0x36f
loc_100064D7:
xor si, si
xor edi, edi
loc_100064DC:
movsx edx, si
lea eax, [edx+edx*4]
lea ebx, [eax+eax*4]
lea eax, [ebx+ebx*4]
lea ebx, [edx+eax*8]
lea eax, [edx+edx*4]
mov [ecx+ebx*4+0x7e2], di
lea eax, [eax+eax*4]
xor bx, bx
lea eax, [eax+eax*4]
lea eax, [edx+eax*8]
add eax, eax
loc_10006504:
movsx edx, bx
inc bx
add edx, eax
mov [ecx+edx*2+0x7e4], di
cmp bx, 0x7d0
jl short loc_10006504
inc si
cmp si, 0x4
jl short loc_100064DC
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10006530:
;sub esp, 0x7c
sub r11d, 0x7c
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;call loc_1000700D
CALL loc_1000700D
movzx cx, byte [loc_1001B2C0]
and ax, cx
;mov [esp+0x14], ax
mov [r11d+0x14], ax
jz near loc_100065E8
;lea edi, [esp+0x5c]
lea edi, [r11d+0x5c]
mov eax, edi
xor edx, edx ; fix treating address as signed number
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
sub eax, edx
sar eax, 0x1
test eax, eax
jz short loc_10006576
;lea edi, [esp+0x64]
lea edi, [r11d+0x64]
add eax, eax
sub edi, eax
loc_10006576:
;lea ecx, [esp+0x2c]
lea ecx, [r11d+0x2c]
mov eax, ecx
xor edx, edx ; fix treating address as signed number
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
sub eax, edx
sar eax, 0x1
test eax, eax
jz short loc_1000659B
shl eax, 0x2
;lea ecx, [esp+0x3c]
lea ecx, [r11d+0x3c]
sub ecx, eax
loc_1000659B:
;lea ebp, [esp+0x6c]
lea ebp, [r11d+0x6c]
;lea eax, [esp+0x6c]
lea eax, [r11d+0x6c]
xor edx, edx ; fix treating address as signed number
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
sub eax, edx
sar eax, 0x1
test eax, eax
jz short loc_100065C2
shl eax, 0x2
;lea ebp, [esp+0x7c]
lea ebp, [r11d+0x7c]
sub ebp, eax
loc_100065C2:
;lea ebx, [esp+0x4c]
lea ebx, [r11d+0x4c]
mov eax, ebx
xor edx, edx ; fix treating address as signed number
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
sub eax, edx
sar eax, 0x1
test eax, eax
jz short loc_100065F8
;lea ebx, [esp+0x54]
lea ebx, [r11d+0x54]
add eax, eax
sub ebx, eax
jmp short loc_100065F8
loc_100065E8:
;mov edi, [esp+0x2c]
mov edi, [r11d+0x2c]
;mov ecx, [esp+0x2c]
mov ecx, [r11d+0x2c]
;mov ebp, [esp+0x2c]
mov ebp, [r11d+0x2c]
;mov ebx, [esp+0x2c]
mov ebx, [r11d+0x2c]
loc_100065F8:
;mov esi, [esp+0x94]
mov esi, [r11d+0x94]
mov ax, [esi+0x7de]
mov edx, [esi]
;mov [esp+0x12], ax
mov [r11d+0x12], ax
mov ax, [edx+0x4]
;mov [esp+0x20], ax
mov [r11d+0x20], ax
mov ax, [edx+0x6]
;mov [esp+0x1c], ax
mov [r11d+0x1c], ax
mov ax, [edx+0x8]
movsx edx, word [edx+0x2]
;mov [esp+0x24], ax
mov [r11d+0x24], ax
lea eax, [edx+edx*4]
lea edx, [eax+eax*4]
lea eax, [edx+edx*4]
shl eax, 0x3
sar eax, 0xf
;cmp word [esp+0x14], 0x0
cmp word [r11d+0x14], 0x0
mov [esi+0xa], ax
jz near loc_1000675A
;mov ax, [esp+0x1c]
mov ax, [r11d+0x1c]
;mov dx, [esp+0x20]
mov dx, [r11d+0x20]
mov [ebx], ax
;mov ax, [esp+0x24]
mov ax, [r11d+0x24]
mov [ebx+0x2], dx
mov [ebx+0x4], ax
mov dx, [esi+0xa]
mov [edi], dx
mov ax, [esi+0x7e0]
mov [edi+0x2], ax
mov dx, [esi+0x1784]
mov [edi+0x4], dx
mov ax, [esi+0x2728]
mov [edi+0x6], ax
lea eax, [esi+0xe]
mov dx, [esi+0x36cc]
mov [edi+0x8], dx
lea edx, [esi+0x7e4]
mov [ecx], eax
lea eax, [esi+0x1788]
mov [ecx+0x4], edx
lea edx, [esi+0x272c]
mov [ecx+0x8], eax
lea eax, [esi+0x36d0]
mov [ecx+0xc], edx
lea edx, [esi+0xc]
mov [ecx+0x10], eax
lea eax, [esi+0x7e2]
mov [ebp], edx
lea edx, [esi+0x1786]
;cmp word [esp+0x14], 0x0
cmp word [r11d+0x14], 0x0
mov [ebp+0x4], eax
lea eax, [esi+0x272a]
mov [ebp+0x8], edx
lea edx, [esi+0x36ce]
mov [ebp+0xc], eax
mov [ebp+0x10], edx
jz near loc_1000675A
;mov edx, [esp+0x90]
mov edx, [r11d+0x90]
;cmp byte [esp+0x98], 0x0
cmp byte [r11d+0x98], 0x0
mov eax, [edx+0x2409e]
;push eax
PUSH32 eax
mov eax, [edx+0x24086]
;push eax
;push ebp
;push ecx
PUSH32 eax, ebp, ecx
mov edx, [edx+0x24082]
;lea ecx, [esp+0x22]
lea ecx, [r11d+0x22]
;push edi
;push ecx
;push ebx
;push edx
PUSH32 edi, ecx, ebx, edx
jz short loc_1000673E
;call simd_1000A920_asm
CALL simd_1000A920_asm
;mov cx, [esp+0x32]
mov cx, [r11d+0x32]
;add esp, 0x20
add r11d, 0x20
mov [esi+0x7de], cx
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x7c
add r11d, 0x7c
;ret
RET
loc_1000673E:
;call simd_1000AD02_asm
CALL simd_1000AD02_asm
;mov cx, [esp+0x32]
mov cx, [r11d+0x32]
;add esp, 0x20
add r11d, 0x20
mov [esi+0x7de], cx
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x7c
add r11d, 0x7c
;ret
RET
loc_1000675A:
mov ax, [esi+0x7de]
mov ecx, [esi]
;mov [esp+0x12], ax
mov [r11d+0x12], ax
mov bx, [ecx+0x4]
movsx eax, word [ecx+0x2]
mov bp, [ecx+0x6]
mov di, [ecx+0x8]
lea ecx, [eax+eax*4]
lea edx, [ecx+ecx*4]
lea eax, [edx+edx*4]
;mov edx, [esp+0x90]
mov edx, [r11d+0x90]
shl eax, 0x3
sar eax, 0xf
mov [esi+0xa], ax
mov eax, [edx+0x24086]
mov ecx, [edx+0x2408e]
;mov [esp+0x18], eax
mov [r11d+0x18], eax
;mov [esp+0x14], ecx
mov [r11d+0x14], ecx
mov ecx, [edx+0x24082]
test ecx, ecx
jle near loc_100068B1
movsx eax, bp
movsx edx, bx
movsx ebx, di
;mov [esp+0x28], eax
mov [r11d+0x28], eax
;mov [esp+0x1c], edx
mov [r11d+0x1c], edx
;mov [esp+0x20], ebx
mov [r11d+0x20], ebx
;mov [esp+0x24], ecx
mov [r11d+0x24], ecx
loc_100067CD:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;add dword [esp+0x14], 0x4
add dword [r11d+0x14], 0x4
mov ecx, [eax]
;push ecx
PUSH32 ecx
;call loc_10006390
CALL loc_10006390
movsx ecx, word [esi+0xc]
;add esp, 0x4
add r11d, 0x4
lea ecx, [esi+ecx*2+0xe]
mov dx, [ecx]
mov [ecx], ax
dec word [esi+0xc]
jns short loc_100067FF
mov ax, [esi+0xa]
dec ax
mov [esi+0xc], ax
loc_100067FF:
;mov eax, [esp+0x12]
mov eax, [r11d+0x12]
;push eax
;push edx
PUSH32 eax, edx
lea edi, [esi+0x7e0]
;call loc_100062B0
CALL loc_100062B0
mov bp, 0x4
;add esp, 0x8
add r11d, 0x8
movsx eax, ax
;imul eax, [esp+0x1c]
imul eax, [r11d+0x1c]
sar eax, 0xf
;add [esp+0x12], ax
add [r11d+0x12], ax
;mov ax, [esp+0x12]
mov ax, [r11d+0x12]
loc_1000682C:
movsx ecx, word [edi+0x2]
mov bx, [edi+ecx*2+0x4]
movsx ecx, bx
;imul ecx, [esp+0x28]
imul ecx, [r11d+0x28]
sar ecx, 0xf
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [edi+0x2]
mov [edi+ecx*2+0x4], ax
;add esp, 0x8
add r11d, 0x8
dec word [edi+0x2]
jns short loc_10006862
mov cx, [edi]
dec cx
mov [edi+0x2], cx
loc_10006862:
movsx eax, ax
;imul eax, [esp+0x28]
imul eax, [r11d+0x28]
sar eax, 0xf
add edi, 0xfa4
;push eax
;push ebx
PUSH32 eax, ebx
;call loc_10006290
CALL loc_10006290
;add esp, 0x8
add r11d, 0x8
dec bp
jnz near loc_1000682C
movsx eax, ax
;imul eax, [esp+0x20]
imul eax, [r11d+0x20]
sar eax, 0xf
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;cmp byte [esp+0x98], 0x0
cmp byte [r11d+0x98], 0x0
jz short loc_1000689F
add [ecx], ax
jmp short loc_100068A2
loc_1000689F:
mov [ecx], ax
loc_100068A2:
;add dword [esp+0x18], 0x2
add dword [r11d+0x18], 0x2
;dec dword [esp+0x24]
dec dword [r11d+0x24]
jnz near loc_100067CD
loc_100068B1:
;mov ax, [esp+0x12]
mov ax, [r11d+0x12]
;pop ebp
POP32 ebp
mov [esi+0x7de], ax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x7c
add r11d, 0x7c
;ret
RET
align 16
loc_100068D0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push esi
PUSH32 esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
xor ecx, ecx
mov eax, [eax+0x14]
add eax, 0x482
mov [esi], eax
xor eax, eax
loc_100068E7:
movsx edx, ax
inc ax
mov [esi+edx*2+0xe], cx
cmp ax, 0x3e8
jl short loc_100068E7
xor eax, eax
mov [esi+0x7de], ax
mov [esi+0xc], ax
;pop esi
POP32 esi
;ret
RET
align 16
loc_10006910:
;sub esp, 0x60
sub r11d, 0x60
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;call loc_1000700D
CALL loc_1000700D
movzx cx, byte [loc_1001B2C0]
and ax, cx
mov bp, ax
test bp, bp
jz short loc_100069A5
;lea esi, [esp+0x34]
lea esi, [r11d+0x34]
mov eax, esi
xor edx, edx ; fix treating address as signed number
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
and edx, 0x3
add eax, edx
sar eax, 0x2
test eax, eax
jz short loc_10006957
shl eax, 0x2
;lea esi, [esp+0x3c]
lea esi, [r11d+0x3c]
sub esi, eax
loc_10006957:
;lea edi, [esp+0x5c]
lea edi, [r11d+0x5c]
mov eax, edi
xor edx, edx ; fix treating address as signed number
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
sub eax, edx
sar eax, 0x1
test eax, eax
jz short loc_1000697B
;lea edi, [esp+0x64]
lea edi, [r11d+0x64]
add eax, eax
sub edi, eax
loc_1000697B:
;lea ebx, [esp+0x4c]
lea ebx, [r11d+0x4c]
mov eax, ebx
xor edx, edx ; fix treating address as signed number
xor eax, edx
sub eax, edx
and eax, 0x7
xor eax, edx
sub eax, edx
cdq
and edx, 0x3
add eax, edx
sar eax, 0x2
test eax, eax
jz short loc_100069B1
shl eax, 0x2
;lea ebx, [esp+0x54]
lea ebx, [r11d+0x54]
sub ebx, eax
jmp short loc_100069B1
loc_100069A5:
;mov esi, [esp+0x34]
mov esi, [r11d+0x34]
;mov edi, [esp+0x34]
mov edi, [r11d+0x34]
;mov ebx, [esp+0x34]
mov ebx, [r11d+0x34]
loc_100069B1:
test bp, bp
;mov eax, [esp+0x78]
mov eax, [r11d+0x78]
;mov edx, [esp+0x74]
mov edx, [r11d+0x74]
mov ecx, [eax]
jz near loc_10006A74
mov eax, [edx+0x24082]
mov [esi], eax
mov dword [esi+0x4], 0x3e8
mov dword [esi+0x8], 0xc
mov dword [esi+0xc], 0x0
mov bp, [ecx+0x6]
mov [edi], bp
mov ax, [ecx+0x8]
mov [edi+0x2], ax
movsx ebp, word [ecx+0x2]
lea eax, [ebp+ebp*4]
lea ebp, [eax+eax*4]
lea eax, [ebp+ebp*4]
shl eax, 0x3
sar eax, 0xf
mov [edi+0x4], ax
;mov eax, [esp+0x78]
mov eax, [r11d+0x78]
mov bp, [ecx+0x4]
add eax, 0x7de
mov [edi+0x6], bp
mov cx, [ecx+0xa]
mov [edi+0x8], cx
mov [ebx], eax
;mov eax, [esp+0x78]
mov eax, [r11d+0x78]
add eax, 0xc
;cmp byte [esp+0x7c], 0x0
cmp byte [r11d+0x7c], 0x0
mov [ebx+0x4], eax
mov eax, [edx+0x2409a]
;push eax
PUSH32 eax
mov ecx, [edx+0x24086]
;mov eax, [esp+0x7c]
mov eax, [r11d+0x7c]
;push ecx
;push ebx
PUSH32 ecx, ebx
jz short loc_10006A5E
add eax, 0xe
;push eax
;push edi
;push esi
PUSH32 eax, edi, esi
;call simd_1000B2EE_asm
CALL simd_1000B2EE_asm
;add esp, 0x18
add r11d, 0x18
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x60
add r11d, 0x60
;ret
RET
loc_10006A5E:
add eax, 0xe
;push eax
;push edi
;push esi
PUSH32 eax, edi, esi
;call simd_1000B7C9_asm
CALL simd_1000B7C9_asm
;add esp, 0x18
add r11d, 0x18
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x60
add r11d, 0x60
;ret
RET
loc_10006A74:
mov eax, [edx+0x2408a]
;mov ebx, [esp+0x78]
mov ebx, [r11d+0x78]
mov si, [ebx+0xc]
;mov [esp+0x20], eax
mov [r11d+0x20], eax
mov di, [ebx+0x7de]
mov eax, ebx
mov bp, [ecx+0xa]
lea ebx, [eax+0xe]
mov ax, [ecx+0x6]
;mov [esp+0x1c], bp
mov [r11d+0x1c], bp
mov bp, [ecx+0x8]
;mov [esp+0x14], bp
mov [r11d+0x14], bp
mov bp, [ecx+0x4]
movsx ecx, word [ecx+0x2]
;mov [esp+0x18], bp
mov [r11d+0x18], bp
lea ebp, [ecx+ecx*4]
lea ecx, [ebp+ebp*4]
lea ebp, [ecx+ecx*4]
lea ecx, [ebp*8]
mov ebp, [edx+0x24086]
sar ecx, 0xf
;mov [esp+0x12], cx
mov [r11d+0x12], cx
mov ecx, [edx+0x24082]
test ecx, ecx
jle near loc_10006BF3
;movsx edx, word [esp+0x14]
movsx edx, word [r11d+0x14]
sar ax, 0xc
;mov [esp+0x14], edx
mov [r11d+0x14], edx
;movsx edx, word [esp+0x18]
movsx edx, word [r11d+0x18]
;mov [esp+0x28], ax
mov [r11d+0x28], ax
;mov [esp+0x18], edx
mov [r11d+0x18], edx
;movsx eax, word [esp+0x12]
movsx eax, word [r11d+0x12]
;mov [esp+0x2c], eax
mov [r11d+0x2c], eax
;mov [esp+0x30], ecx
mov [r11d+0x30], ecx
;movsx eax, word [esp+0x1c]
movsx eax, word [r11d+0x1c]
;mov [esp+0x1c], eax
mov [r11d+0x1c], eax
loc_10006B13:
;push esi
PUSH32 esi
;call loc_10006280
CALL loc_10006280
and ax, 0xfffe
;add si, [esp+0x2c]
add si, [r11d+0x2c]
;add esp, 0x4
add r11d, 0x4
sub ax, 0x7ffe
movsx ecx, ax
;imul ecx, [esp+0x14]
imul ecx, [r11d+0x14]
sar ecx, 0x10
add cx, 0x3fff
movsx eax, cx
;imul eax, [esp+0x2c]
imul eax, [r11d+0x2c]
sar eax, 0xf
cmp ax, 0x1
jge short loc_10006B4E
mov ax, 0x1
loc_10006B4E:
add ax, di
cmp ax, 0x3e8
jl short loc_10006B5B
sub ax, 0x3e8
loc_10006B5B:
movsx edx, ax
mov dx, [ebx+edx*2]
;imul cx, [esp+0x12]
imul cx, [r11d+0x12]
and cx, 0x7fff
inc ax
cmp ax, 0x3e8
jl short loc_10006B79
sub ax, 0x3e8
loc_10006B79:
movsx eax, ax
mov ax, [ebx+eax*2]
movsx ecx, cx
sub ax, dx
movsx eax, ax
imul eax, ecx
sar eax, 0xf
add dx, ax
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
movsx ecx, dx
imul eax, ecx
sar eax, 0xf
;mov [esp+0x24], ecx
mov [r11d+0x24], ecx
movsx eax, ax
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;add dword [esp+0x20], 0x4
add dword [r11d+0x20], 0x4
add eax, [ecx]
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
movsx ecx, di
mov [ebx+ecx*2], ax
;add esp, 0x4
add r11d, 0x4
dec di
jns short loc_10006BC9
mov di, 0x3e7
loc_10006BC9:
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;imul eax, [esp+0x24]
imul eax, [r11d+0x24]
sar eax, 0xf
;cmp byte [esp+0x7c], 0x0
cmp byte [r11d+0x7c], 0x0
jz short loc_10006BE2
add [ebp], ax
jmp short loc_10006BE6
loc_10006BE2:
mov [ebp], ax
loc_10006BE6:
add ebp, 0x2
;dec dword [esp+0x30]
dec dword [r11d+0x30]
jnz near loc_10006B13
loc_10006BF3:
;mov eax, [esp+0x78]
mov eax, [r11d+0x78]
;pop ebp
POP32 ebp
mov [eax+0xc], si
mov [eax+0x7de], di
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x60
add r11d, 0x60
;ret
RET
align 16
loc_10006C10:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
loc_10006C18:
mov dl, [eax]
inc eax
mov [ecx], dl
inc ecx
cmp byte [eax], 0x0
jnz short loc_10006C18
mov byte [ecx], 0x0
;ret
RET
align 16
loc_10006C30:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
mov eax, [edi]
cmp eax, 0x6b657962
jz short loc_10006C4D
cmp eax, 0x70657263
jz short loc_10006C5F
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10006C4D:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006E00
CALL loc_10006E00
jmp short loc_10006C6F
loc_10006C5F:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006E10
CALL loc_10006E10
loc_10006C6F:
;add esp, 0xc
add r11d, 0xc
mov eax, [esi+0x10]
;push ebx
;push edi
;push eax
PUSH32 ebx, edi, eax
;call loc_1000BCB0
CALL loc_1000BCB0
;add esp, 0xc
add r11d, 0xc
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10006C90:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
mov eax, [edi]
cmp eax, 0x626f7764
jg short loc_10006CB3
jz near loc_10006D3E
cmp eax, 0x616e616c
jz near loc_10006D29
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10006CB3:
cmp eax, 0x636c6172
jg short loc_10006CD1
jz near loc_10006D65
cmp eax, 0x62726173
jz near loc_10006D53
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10006CD1:
cmp eax, 0x666c7574
jg short loc_10006CEF
jz near loc_10006D89
cmp eax, 0x65706e6f
jz near loc_10006D77
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10006CEF:
cmp eax, 0x68616d6d
jg short loc_10006D0D
jz near loc_10006DAD
cmp eax, 0x666d2020
jz near loc_10006D9B
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10006D0D:
cmp eax, 0x70636d20
jz near loc_10006DBF
cmp eax, 0x77617665
jz near loc_10006DD1
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10006D29:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006E90
CALL loc_10006E90
jmp loc_10006DE1
loc_10006D3E:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006ED0
CALL loc_10006ED0
jmp loc_10006DE1
loc_10006D53:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006EF0
CALL loc_10006EF0
jmp loc_10006DE1
loc_10006D65:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006EA0
CALL loc_10006EA0
jmp loc_10006DE1
loc_10006D77:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006F00
CALL loc_10006F00
jmp loc_10006DE1
loc_10006D89:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006EB0
CALL loc_10006EB0
jmp loc_10006DE1
loc_10006D9B:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006E80
CALL loc_10006E80
jmp loc_10006DE1
loc_10006DAD:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006EC0
CALL loc_10006EC0
jmp short loc_10006DE1
loc_10006DBF:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006E20
CALL loc_10006E20
jmp short loc_10006DE1
loc_10006DD1:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebx
;push edi
;push esi
PUSH32 ebx, edi, esi
;call loc_10006E50
CALL loc_10006E50
loc_10006DE1:
;add esp, 0xc
add r11d, 0xc
mov eax, [esi+0x14]
;push ebx
;push edi
;push eax
PUSH32 ebx, edi, eax
;call loc_1000BCB0
CALL loc_1000BCB0
;add esp, 0xc
add r11d, 0xc
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10006E00:
mov al, 0x1
;ret
RET
align 16
loc_10006E10:
mov al, 0x1
;ret
RET
align 16
loc_10006E20:
xor al, al
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
mov edx, [ecx+0x4]
mov ecx, [edx+ecx-0x10]
test ecx, ecx
jz short loc_10006E44
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;push eax
;push ecx
PUSH32 eax, ecx
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
;push ecx
PUSH32 ecx
;call loc_10006F10
CALL loc_10006F10
;add esp, 0xc
add r11d, 0xc
loc_10006E44:
;ret
RET
align 16
loc_10006E50:
xor al, al
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
mov edx, [ecx+0x4]
mov ecx, [edx+ecx-0x4]
test ecx, ecx
jz short loc_10006E74
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;push eax
;push ecx
PUSH32 eax, ecx
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
;push ecx
PUSH32 ecx
;call loc_10006F80
CALL loc_10006F80
;add esp, 0xc
add r11d, 0xc
loc_10006E74:
;ret
RET
align 16
loc_10006E80:
mov al, 0x1
;ret
RET
align 16
loc_10006E90:
mov al, 0x1
;ret
RET
align 16
loc_10006EA0:
mov al, 0x1
;ret
RET
align 16
loc_10006EB0:
mov al, 0x1
;ret
RET
align 16
loc_10006EC0:
mov al, 0x1
;ret
RET
align 16
loc_10006ED0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov eax, [eax]
sub eax, 0x626f7764
cmp eax, 0x1
sbb al, al
neg al
;ret
RET
align 16
loc_10006EF0:
mov al, 0x1
;ret
RET
align 16
loc_10006F00:
mov al, 0x1
;ret
RET
align 16
loc_10006F10:
;sub esp, 0x4
sub r11d, 0x4
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
xor bp, bp
;mov edi, [esp+0x1c]
mov edi, [r11d+0x1c]
mov cx, [edi+0x3a]
add edi, 0x3a
;mov [esp+0x12], cx
mov [r11d+0x12], cx
add edi, 0x4
cmp cx, bp
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
;mov bl, [esp+0x20]
mov bl, [r11d+0x20]
jle short loc_10006F5C
loc_10006F3A:
mov eax, [edi+0x8]
test eax, eax
jz short loc_10006F50
;push ebx
;push eax
;push esi
PUSH32 ebx, eax, esi
;call loc_10006F80
CALL loc_10006F80
;add esp, 0xc
add r11d, 0xc
test al, al
jz short loc_10006F6E
loc_10006F50:
inc bp
add edi, 0x12
;cmp [esp+0x12], bp
cmp [r11d+0x12], bp
jg short loc_10006F3A
loc_10006F5C:
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;push ebx
;push eax
PUSH32 ebx, eax
mov ecx, [esi+0x1c]
;push ecx
PUSH32 ecx
;call loc_1000BCB0
CALL loc_1000BCB0
;add esp, 0xc
add r11d, 0xc
loc_10006F6E:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10006F80:
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
cmp byte [ecx+0x35], 0x0
jz short loc_10006F93
mov eax, [eax+0x24]
jmp short loc_10006F96
loc_10006F93:
mov eax, [eax+0x20]
loc_10006F96:
;mov edx, [esp+0xc]
mov edx, [r11d+0xc]
;push edx
;push ecx
;push eax
PUSH32 edx, ecx, eax
;call loc_1000BCB0
CALL loc_1000BCB0
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 16
loc_10006FB0:
;push ebp
PUSH32 ebp
;mov ebp, esp
mov ebp, r11d
;push ebx
;push ecx
PUSH32 ebx, ecx
mov eax, 1; skip check for the task-switched (TS) flag in the CR0 register
mov ebx, [ebp+0x8]
wait
fnsave [ebx]
;pop ecx
;pop ebx
POP32 ebx, ecx
;leave
LEAVE
;ret
RET
loc_10006FE2:
;push ebp
PUSH32 ebp
;mov ebp, esp
mov ebp, r11d
;push eax
;push ebx
PUSH32 eax, ebx
mov ebx, [ebp+0x8]
frstor [ebx]
; skip restoring the task-switched (TS) flag in the CR0 register
;pop ebx
;pop eax
POP32 eax, ebx
;leave
LEAVE
;ret
RET
loc_1000700D:
; skip MMX detection
mov eax, 0x1
;ret
RET
loc_10007620:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
lea esi, [eax+0xc]
mov edx, [eax+0x8]
lea eax, [edx+0x3a]
add edx, 0x32
add eax, 0x4
mov cx, [eax-0x4]
mov [esi], cx
mov [esi+0x2], eax
lea edi, [esi+0xc]
xor cx, cx
mov ebx, [edx+0x4]
lea edx, [ebx+edx+0x8]
mov ax, [edx]
add edx, 0x2
mov [esi+0x6], ax
mov [esi+0x8], edx
cmp [esi+0x6], cx
jle near loc_1000780E
loc_10007665:
lea ebx, [edx+0xc]
lea eax, [edx+0x8]
mov [edi], edx
mov [edi+0x4], eax
mov [edi+0x8], ebx
mov byte [edi+0xd], 0x0
mov word [edi+0x10], 0x7fff
mov word [edi+0xe], 0x7fff
mov word [edi+0x12], 0x0
mov eax, [edx]
cmp eax, 0x656e7665
jz short loc_100076AD
cmp eax, 0x6c666f20
jz near loc_10007776
cmp eax, 0x72616e64
jz near loc_100077D0
jmp loc_100077FC
loc_100076AD:
mov byte [edi+0xc], 0x0
mov byte [edi+0x14], 0x1
mov byte [edi+0x15], 0x1
mov byte [edi+0x16], 0x1
mov word [edi+0x18], 0x0
mov word [edi+0x1a], 0x0
mov ax, [ebx]
mov [edi+0x1c], ax
mov bp, [ebx+0x2]
mov [edi+0x1e], bp
mov ax, [ebx+0x4]
mov [edi+0x20], ax
mov bp, [ebx+0x6]
mov [edi+0x22], bp
mov ax, [ebx+0x8]
mov [edi+0x24], ax
mov bx, [ebx+0xa]
mov [edi+0x26], bx
lea ebp, [edi+0x2e]
mov word [edi+0x28], 0x0
mov word [edi+0x2a], 0x3
lea ebx, [edi+0x2c]
mov word [ebx], 0x1
add ebx, 0x1a
add ebx, 0x1a
mov byte [ebp], 0x1
mov ax, [edi+0x1c]
add ebx, 0x2
mov [ebp+0x2], ax
add ebx, 0x8
lea eax, [edi+0x1c]
mov [ebp+0x4], eax
lea ebp, [ebx-0x22]
mov word [ebx-0x24], 0x1
mov byte [ebp], 0x1
mov ax, [edi+0x1e]
mov [ebp+0x2], ax
lea eax, [edi+0x1e]
mov [ebp+0x4], eax
lea ebp, [edi+0x20]
mov word [ebx-0xa], 0x2
mov byte [ebx-0x8], 0x1
mov ax, [edi+0x20]
mov [ebx-0x6], ax
mov [ebx-0x4], ebp
lea ebp, [edi+0x24]
mov byte [ebx], 0x1
mov ax, [edi+0x24]
mov [ebx+0x2], ax
mov [ebx+0x4], ebp
jmp loc_100077FC
loc_10007776:
mov byte [edi+0xc], 0x1
mov word [edi+0x14], 0x0
mov ax, [ebx+0x4]
lea ebp, [edi+0x2e]
mov [edi+0x16], ax
lea ebx, [edi+0x2c]
mov word [edi+0x18], 0x0
mov word [edi+0x2a], 0x2
mov word [ebx], 0x1
add ebx, 0x1a
add ebx, 0x2
mov byte [ebp], 0x0
mov ax, [edi+0x14]
mov [ebp+0x2], ax
lea eax, [edi+0x14]
mov [ebp+0x4], eax
lea ebp, [edi+0x16]
mov word [ebx-0x2], 0x1
mov byte [ebx], 0x0
mov ax, [edi+0x16]
mov [ebx+0x2], ax
mov [ebx+0x4], ebp
jmp short loc_100077FC
loc_100077D0:
lea ebx, [edi+0x2c]
lea eax, [edi+0x14]
mov byte [edi+0xc], 0x1
mov word [edi+0x16], 0x1
mov word [edi+0x2a], 0x1
mov word [ebx], 0x1
mov byte [ebx+0x2], 0x0
add ebx, 0x2
mov bp, [eax]
mov [ebx+0x2], bp
mov [ebx+0x4], eax
loc_100077FC:
add edi, 0x7a
inc cx
add edx, [edx+0x4]
cmp [esi+0x6], cx
jg near loc_10007665
loc_1000780E:
;mov edi, [esp+0x1c]
mov edi, [r11d+0x1c]
mov al, [edi+0x11]
;push eax
PUSH32 eax
;call loc_100063D0
CALL loc_100063D0
mov [esi+0x2e8], ax
;add esp, 0x4
add r11d, 0x4
mov ax, [edi+0x1e]
mov [esi+0x2ee], ax
mov cx, [edi+0x20]
mov [esi+0x2f0], cx
xor ecx, ecx
mov [esi+0x2ec], cx
mov [esi+0x2ea], cx
mov ax, [esi+0x2ee]
mov [esi+0x2f6], ax
;mov ebx, [esp+0x20]
mov ebx, [r11d+0x20]
mov [esi+0x2f8], ax
mov eax, 0x7fff
mov dx, [esi+0x2f0]
;pop ebp
POP32 ebp
mov [esi+0x2fa], dx
;pop edi
POP32 edi
mov [esi+0x2fc], ax
mov [esi+0x2fe], ax
mov [esi+0x362], ebx
mov [esi+0x300], cx
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_100078A0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;sub esp, 0x14
sub r11d, 0x14
mov cx, [eax+0x304]
add eax, 0xc
mov [eax+0x2f2], cx
;push ebx
;push esi
PUSH32 ebx, esi
lea edx, [eax+0x302]
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;push edi
;push ebp
PUSH32 edi, ebp
mov ecx, edx
xor si, si
;mov [esp+0x20], edx
mov [r11d+0x20], edx
cmp [eax+0x300], si
jle short loc_100078F4
loc_100078D8:
inc si
mov eax, [ecx+0x4]
mov ax, [eax]
add ecx, 0x8
mov [ecx-0x6], ax
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
cmp [edx+0x300], si
jg short loc_100078D8
loc_100078F4:
;mov eax, [esp+0x2c]
mov eax, [r11d+0x2c]
;push 0x1
PUSH32 0x1
;mov ecx, [esp+0x2c]
mov ecx, [r11d+0x2c]
;push 0x1
PUSH32 0x1
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10008000
CALL loc_10008000
;mov ecx, [esp+0x3c]
mov ecx, [r11d+0x3c]
;mov edx, [esp+0x38]
mov edx, [r11d+0x38]
;add esp, 0x10
add r11d, 0x10
;push 0x1
PUSH32 0x1
;push 0x0
PUSH32 0x0
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10008000
CALL loc_10008000
;mov edx, [esp+0x24]
mov edx, [r11d+0x24]
;add esp, 0x10
add r11d, 0x10
mov cx, [edx+0x6]
;mov [esp+0x12], cx
mov [r11d+0x12], cx
cmp cx, 0x6
jle short loc_1000793A
;mov word [esp+0x12], 0x6
mov word [r11d+0x12], 0x6
loc_1000793A:
;mov ebp, [esp+0x14]
mov ebp, [r11d+0x14]
add ebp, 0xc
;cmp word [esp+0x12], 0x0
cmp word [r11d+0x12], 0x0
mov esi, ebp
jle near loc_100079B8
;mov byte [esp+0x18], 0x3
mov byte [r11d+0x18], 0x3
;mov ax, [esp+0x12]
mov ax, [r11d+0x12]
;mov [esp+0x1c], ax
mov [r11d+0x1c], ax
loc_1000795A:
;mov bl, [esp+0x18]
mov bl, [r11d+0x18]
;push 0x1
PUSH32 0x1
inc bl
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;mov ecx, [esp+0x30]
mov ecx, [r11d+0x30]
;push eax
PUSH32 eax
xor di, di
;push ecx
PUSH32 ecx
;mov edx, [esp+0x34]
mov edx, [r11d+0x34]
;push edx
PUSH32 edx
;call loc_10008000
CALL loc_10008000
;add esp, 0x10
add r11d, 0x10
cmp [esi+0x2a], di
jle short loc_100079A3
loc_10007982:
inc di
mov al, bl
inc bl
;push 0x1
PUSH32 0x1
;mov ecx, [esp+0x30]
mov ecx, [r11d+0x30]
;push eax
PUSH32 eax
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_10008000
CALL loc_10008000
;add esp, 0x10
add r11d, 0x10
cmp [esi+0x2a], di
jg short loc_10007982
loc_100079A3:
;movsx eax, byte [esp+0x18]
movsx eax, byte [r11d+0x18]
add esi, 0x7a
add al, 0x4
;dec word [esp+0x1c]
dec word [r11d+0x1c]
;mov [esp+0x18], al
mov [r11d+0x18], al
jnz near loc_1000795A
loc_100079B8:
xor si, si
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
cmp [edx+0x300], si
jle short loc_100079F1
loc_100079C8:
mov ax, si
;push 0x1
PUSH32 0x1
inc si
add al, 0x1b
;mov ecx, [esp+0x30]
mov ecx, [r11d+0x30]
;push eax
PUSH32 eax
;mov edx, [esp+0x30]
mov edx, [r11d+0x30]
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10008000
CALL loc_10008000
;mov edx, [esp+0x24]
mov edx, [r11d+0x24]
;add esp, 0x10
add r11d, 0x10
cmp [edx+0x300], si
jg short loc_100079C8
loc_100079F1:
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;cmp word [esp+0x12], 0x0
cmp word [r11d+0x12], 0x0
mov ax, [edx+0x2f6]
mov [edx+0x2f2], ax
mov ax, [edx+0x2ec]
mov [edx+0x2ea], ax
jle short loc_10007A6A
;mov ax, [esp+0x12]
mov ax, [r11d+0x12]
;mov [esp+0x1c], ax
mov [r11d+0x1c], ax
loc_10007A23:
mov ax, [ebp+0x10]
lea edx, [ebp+0x2c]
xor di, di
mov [ebp+0xe], ax
cmp [ebp+0x2a], di
jle short loc_10007A60
lea esi, [edx+0x2]
loc_10007A3A:
xor ax, ax
mov ecx, esi
cmp [edx], ax
jle short loc_10007A58
loc_10007A44:
inc ax
mov ebx, [ecx+0x4]
mov bx, [ebx]
add ecx, 0x8
mov [ecx-0x6], bx
cmp [edx], ax
jg short loc_10007A44
loc_10007A58:
inc di
cmp [ebp+0x2a], di
jg short loc_10007A3A
loc_10007A60:
add ebp, 0x7a
;dec word [esp+0x1c]
dec word [r11d+0x1c]
jnz short loc_10007A23
loc_10007A6A:
xor si, si
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
cmp [edx+0x300], si
jle short loc_10007A9A
loc_10007A7E:
inc si
mov eax, [ecx+0x4]
mov ax, [eax]
add ecx, 0x8
mov [ecx-0x6], ax
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
cmp [edx+0x300], si
jg short loc_10007A7E
loc_10007A9A:
;mov eax, [esp+0x2c]
mov eax, [r11d+0x2c]
;mov ecx, [esp+0x28]
mov ecx, [r11d+0x28]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10007BD0
CALL loc_10007BD0
;mov ecx, [esp+0x34]
mov ecx, [r11d+0x34]
;mov edx, [esp+0x30]
mov edx, [r11d+0x30]
;add esp, 0x8
add r11d, 0x8
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10008000
CALL loc_10008000
;mov ecx, [esp+0x3c]
mov ecx, [r11d+0x3c]
;mov edx, [esp+0x38]
mov edx, [r11d+0x38]
;add esp, 0x10
add r11d, 0x10
;push 0x3
PUSH32 0x3
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10007FB0
CALL loc_10007FB0
;mov ecx, [esp+0x38]
mov ecx, [r11d+0x38]
;mov edx, [esp+0x34]
mov edx, [r11d+0x34]
;add esp, 0xc
add r11d, 0xc
;push 0x4
PUSH32 0x4
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10007FB0
CALL loc_10007FB0
;add esp, 0xc
add r11d, 0xc
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14
add r11d, 0x14
;ret
RET
align 16
loc_10007B00:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
xor esi, esi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
;push ebp
PUSH32 ebp
add edi, 0xc
cmp [edi+0x6], si
lea ebx, [edi+0xc]
jle short loc_10007B75
mov ecx, 0x1
xor edx, edx
loc_10007B1D:
mov eax, [ebx+0x4]
cmp [eax], dl
jnz short loc_10007B6A
mov ebp, [ebx+0x8]
mov eax, [ebx]
mov eax, [eax]
cmp eax, 0x656e7665
jz short loc_10007B3B
cmp eax, 0x6c666f20
jz short loc_10007B66
jmp short loc_10007B6A
loc_10007B3B:
mov [ebx+0x14], cl
mov [ebx+0x15], cl
mov [ebx+0x16], cl
mov [ebx+0x18], dx
mov [ebx+0x1a], dx
mov ax, [ebp+0x4]
mov [ebx+0x20], ax
mov ax, [ebp+0x8]
mov [ebx+0x24], ax
mov bp, [ebp+0xa]
mov [ebx+0x26], bp
jmp short loc_10007B6A
loc_10007B66:
mov [ebx+0x18], dx
loc_10007B6A:
inc si
add ebx, 0x7a
cmp [edi+0x6], si
jg short loc_10007B1D
loc_10007B75:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10007B80:
;push esi
;push edi
PUSH32 esi, edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
;push 0x0
PUSH32 0x0
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
;push esi
PUSH32 edi, esi
;call loc_10007FB0
CALL loc_10007FB0
;add esp, 0xc
add r11d, 0xc
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push edi
;push esi
PUSH32 edi, esi
;call loc_10008000
CALL loc_10008000
;add esp, 0x10
add r11d, 0x10
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10007BB0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push 0x0
PUSH32 0x0
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
;push 0x1
PUSH32 0x1
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10008000
CALL loc_10008000
;add esp, 0x10
add r11d, 0x10
;ret
RET
align 16
loc_10007BD0:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;push esi
PUSH32 esi
lea esi, [edx+0xc]
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
movsx eax, byte [edx+0x2]
mov al, [eax+ecx+0x216e2]
test al, al
jge short loc_10007BF4
mov ax, [esi+0x2f0]
jmp short loc_10007BFC
loc_10007BF4:
movsx ax, al
shl ax, 0x8
loc_10007BFC:
mov [esi+0x2f4], ax
;push 0x0
PUSH32 0x0
;push 0x2
PUSH32 0x2
;push edx
;push ecx
PUSH32 edx, ecx
;call loc_10008000
CALL loc_10008000
;add esp, 0x10
add r11d, 0x10
;pop esi
POP32 esi
;ret
RET
align 16
loc_10007C20:
;sub esp, 0xc
sub r11d, 0xc
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x1c]
mov esi, [r11d+0x1c]
;push edi
;push ebp
PUSH32 edi, ebp
lea ebp, [esi+0x18]
lea eax, [esi+0xc]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
cmp dword [eax+0x362], 0x1
sbb bl, bl
neg bl
xor di, di
cmp [eax+0x6], di
jle near loc_10007D26
loc_10007C4D:
mov eax, [ebp+0x4]
cmp [eax], bl
jnz near loc_10007CF1
cmp word [ebp+0x10], 0x0
jz near loc_10007CC7
mov byte [ebp+0xd], 0x1
mov eax, [ebp]
mov eax, [eax]
cmp eax, 0x656e7665
jz short loc_10007C7F
cmp eax, 0x6c666f20
jz short loc_10007C97
cmp eax, 0x72616e64
jz near loc_10007CAF
jmp loc_10007CD1
loc_10007C7F:
lea eax, [ebp+0x14]
mov ecx, [ebp+0x8]
;push eax
;push ecx
;push esi
PUSH32 eax, ecx, esi
;call loc_10007D30
CALL loc_10007D30
;mov [esp+0x1e], ax
mov [r11d+0x1e], ax
;add esp, 0xc
add r11d, 0xc
jmp loc_10007CD8
loc_10007C97:
lea eax, [ebp+0x14]
mov ecx, [ebp+0x8]
;push eax
;push ecx
;push esi
PUSH32 eax, ecx, esi
;call loc_10007E80
CALL loc_10007E80
;mov [esp+0x1e], ax
mov [r11d+0x1e], ax
;add esp, 0xc
add r11d, 0xc
jmp short loc_10007CD8
loc_10007CAF:
lea eax, [ebp+0x14]
mov ecx, [ebp+0x8]
;push eax
;push ecx
;push esi
PUSH32 eax, ecx, esi
;call loc_10007F80
CALL loc_10007F80
;mov [esp+0x1e], ax
mov [r11d+0x1e], ax
;add esp, 0xc
add r11d, 0xc
jmp short loc_10007CD8
loc_10007CC7:
cmp byte [ebp+0xd], 0x0
jz short loc_10007CF1
mov byte [ebp+0xd], 0x1
loc_10007CD1:
;mov word [esp+0x12], 0x0
mov word [r11d+0x12], 0x0
loc_10007CD8:
cmp byte [ebp+0xd], 0x0
jz short loc_10007CF1
movsx eax, word [ebp+0x10]
;movsx ecx, word [esp+0x12]
movsx ecx, word [r11d+0x12]
imul eax, ecx
sar eax, 0xf
mov [ebp+0x12], ax
loc_10007CF1:
test bl, bl
jnz short loc_10007D13
cmp byte [ebp+0xd], 0x0
jz short loc_10007D13
mov ax, di
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
mov byte [ebp+0xd], 0x0
add al, 0x5
;push eax
;push esi
;push ecx
PUSH32 eax, esi, ecx
;call loc_10007FB0
CALL loc_10007FB0
;add esp, 0xc
add r11d, 0xc
loc_10007D13:
inc di
add ebp, 0x7a
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
cmp [eax+0x6], di
jg near loc_10007C4D
loc_10007D26:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 16
loc_10007D30:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push ebx
PUSH32 ebx
;mov edx, [esp+0x10]
mov edx, [r11d+0x10]
;push esi
;push edi
PUSH32 esi, edi
cmp byte [eax], 0x0
;push ebp
PUSH32 ebp
jz near loc_10007E17
cmp byte [edx], 0x0
jz short loc_10007D6E
mov ax, [edx+0xa]
add ax, [edx+0x14]
mov [edx+0x14], ax
jns near loc_10007E6D
;pop ebp
POP32 ebp
mov byte [edx], 0x0
mov word [edx+0x14], 0x7fff
mov ax, [edx+0x14]
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10007D6E:
cmp byte [edx+0x1], 0x0
jz near loc_10007DD6
mov di, [edx+0xc]
mov ebp, 0x7fff
movsx eax, word [edx+0xe]
mov si, [edx+0x14]
sub ebp, eax
sub si, di
movsx ebx, si
mov cx, [edx+0x4]
sub ebx, eax
sar ebp, cl
mov [edx+0x14], si
cmp ebx, ebp
jge short loc_10007DB1
cmp cx, 0x3
jge short loc_10007DB1
inc cx
sar di, 0x1
mov [edx+0x4], cx
mov [edx+0xc], di
loc_10007DB1:
cmp si, [edx+0xe]
jg near loc_10007E6D
mov ax, [edx+0xe]
;pop ebp
POP32 ebp
mov [edx+0x14], ax
;pop edi
POP32 edi
mov ax, [edx+0x14]
;pop esi
POP32 esi
mov byte [edx+0x1], 0x0
mov word [edx+0x4], 0x0
;pop ebx
POP32 ebx
;ret
RET
loc_10007DD6:
mov ax, [edx+0x14]
mov cx, [edx+0x4]
sub ax, [edx+0x10]
mov si, [edx+0xe]
sar si, cl
mov [edx+0x14], ax
cmp si, ax
jle short loc_10007E03
cmp cx, 0x3
jge short loc_10007E03
inc cx
sar word [edx+0xc], 0x1
mov [edx+0x4], cx
loc_10007E03:
test ax, ax
jge near loc_10007E6D
mov word [edx+0x14], 0x0
mov ax, [edx+0x14]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10007E17:
cmp byte [edx+0x2], 0x0
jz short loc_10007E2F
mov byte [edx+0x2], 0x0
mov word [edx+0x4], 0x0
mov ax, [edx+0x14]
mov [edx+0x6], ax
loc_10007E2F:
mov si, [edx+0x12]
mov ax, [edx+0x14]
sub ax, si
mov cx, [edx+0x4]
mov di, [edx+0x6]
sar di, cl
mov [edx+0x14], ax
cmp di, ax
jle short loc_10007E62
cmp cx, 0x3
jge short loc_10007E62
inc cx
sar si, 0x1
mov [edx+0x4], cx
mov [edx+0x12], si
loc_10007E62:
test ax, ax
jge short loc_10007E6D
mov word [edx+0x14], 0x0
loc_10007E6D:
mov ax, [edx+0x14]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10007E80:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
movsx eax, byte [eax]
;push edi
PUSH32 edi
cmp eax, 0x4
ja short loc_10007E95
;jmp dword [eax*4+loc_10007F6C]
mov r9d, [eax*4+loc_10007F6C]
jmp r9
loc_10007E95:
xor ax, ax
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
mov cx, [esi+0x2]
;pop edi
POP32 edi
add [esi+0x4], cx
;pop esi
POP32 esi
;ret
RET
loc_10007EA7:
mov di, 0x7fff
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
mov ax, [esi+0x4]
;push eax
PUSH32 eax
;call loc_10006280
CALL loc_10006280
sub di, ax
;add esp, 0x4
add r11d, 0x4
movsx eax, word [esi+0x4]
movsx ecx, di
imul eax, ecx
mov cx, [esi+0x2]
;pop edi
POP32 edi
sar eax, 0xf
add [esi+0x4], cx
;pop esi
POP32 esi
;ret
RET
loc_10007ED7:
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
mov ax, [esi+0x4]
test ax, ax
jle short loc_10007EF6
mov cx, [esi+0x2]
lea eax, [eax*2-0x7ffe]
add [esi+0x4], cx
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_10007EF6:
cmp ax, 0x8000
jnz short loc_10007F0B
mov ax, 0x7fff
;pop edi
POP32 edi
mov cx, [esi+0x2]
add [esi+0x4], cx
;pop esi
POP32 esi
;ret
RET
loc_10007F0B:
mov cx, 0xc001
;pop edi
POP32 edi
sub cx, ax
lea eax, [ecx*2]
mov cx, [esi+0x2]
add [esi+0x4], cx
;pop esi
POP32 esi
;ret
RET
loc_10007F24:
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;pop edi
POP32 edi
mov ax, [esi+0x4]
mov cx, [esi+0x2]
add [esi+0x4], cx
;pop esi
POP32 esi
;ret
RET
loc_10007F37:
mov ax, 0x7fff
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
mov cx, [esi+0x2]
sub ax, [esi+0x4]
;pop edi
POP32 edi
add [esi+0x4], cx
;pop esi
POP32 esi
;ret
RET
loc_10007F4E:
mov ax, 0x7fff
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
cmp word [esi+0x4], 0x0
jge short loc_10007F61
mov ax, 0x8000
loc_10007F61:
mov cx, [esi+0x2]
;pop edi
POP32 edi
add [esi+0x4], cx
;pop esi
POP32 esi
;ret
RET
align 4
loc_10007F6C:
dd loc_10007EA7
dd loc_10007ED7
dd loc_10007F24
dd loc_10007F37
dd loc_10007F4E
align 4
loc_10007F80:
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
mov dx, [eax+0x2]
test dh, 0x80
lea ecx, [edx*2]
jz short loc_10007FA2
xor cx, 0x1d87
mov [eax+0x2], cx
mov ax, [eax+0x2]
;ret
RET
loc_10007FA2:
mov [eax+0x2], cx
mov ax, [eax+0x2]
;ret
RET
align 16
loc_10007FB0:
;push ebx
;push esi
PUSH32 ebx, esi
xor si, si
;push edi
;push ebp
PUSH32 edi, ebp
;mov ebp, [esp+0x18]
mov ebp, [r11d+0x18]
mov ebx, [ebp+0xe]
lea edi, [ebp+0xc]
cmp [edi], si
jle short loc_10007FEC
loc_10007FC6:
;mov al, [esp+0x1c]
mov al, [r11d+0x1c]
cmp [ebx], al
jnz short loc_10007FE2
;push 0x0
PUSH32 0x0
mov al, [ebx+0x1]
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;push eax
;push ebp
;push ecx
PUSH32 eax, ebp, ecx
;call loc_10008000
CALL loc_10008000
;add esp, 0x10
add r11d, 0x10
loc_10007FE2:
inc si
add ebx, 0x4
cmp [edi], si
jg short loc_10007FC6
loc_10007FEC:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10008000:
;movsx dx, byte [esp+0xc]
movsx dx, byte [r11d+0xc]
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
movsx ebp, dx
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
add edi, 0xc
test ebp, ebp
jz near loc_10008100
cmp ebp, 0x1
jz near loc_10008148
cmp ebp, 0x2
jz near loc_10008158
;cmp byte [esp+0x1c], 0x3
cmp byte [r11d+0x1c], 0x3
jl near loc_100080D1
;cmp byte [esp+0x1c], 0x1a
cmp byte [r11d+0x1c], 0x1a
jg near loc_100080D1
inc dx
lea eax, [ebp-0x3]
sar eax, 0x2
movsx ecx, ax
lea ebx, [ecx+ecx*4]
and dx, 0x3
mov eax, ecx
lea ecx, [eax+ebx*8]
lea ecx, [ecx+ecx*2]
sub ecx, eax
movsx eax, dx
lea ecx, [ecx+edi+0xc]
test eax, eax
jz short loc_1000807E
cmp eax, 0x1
jl near loc_10008166
cmp eax, 0x3
jle short loc_1000808B
jmp loc_10008166
loc_1000807E:
mov ax, [ecx+0xe]
mov [ecx+0x10], ax
jmp loc_10008166
loc_1000808B:
dec dx
cmp [ecx+0x2a], dx
jle near loc_1000826A
movsx eax, dx
mov edx, eax
lea ebx, [eax+eax*4]
lea eax, [ebx+ebx*4]
add eax, edx
lea edx, [eax+ecx+0x2e]
lea eax, [eax+ecx+0x2c]
xor cx, cx
cmp [eax], cx
jle near loc_10008166
loc_100080B8:
mov bx, [edx+0x2]
mov esi, [edx+0x4]
inc cx
add edx, 0x8
mov [esi], bx
cmp [eax], cx
jg short loc_100080B8
jmp loc_10008166
loc_100080D1:
sub dx, 0x1b
cmp [edi+0x300], dx
jle near loc_1000826A
movsx eax, dx
mov cx, [edi+eax*8+0x304]
mov edx, [edi+eax*8+0x306]
mov [edx], cx
lea eax, [edi+eax*8+0x302]
jmp short loc_10008166
loc_10008100:
;cmp byte [esp+0x20], 0x0
cmp byte [r11d+0x20], 0x0
jnz short loc_10008166
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;mov ebx, [esp+0x14]
mov ebx, [r11d+0x14]
movsx eax, byte [ecx+0x2]
mov dx, [ebx+eax*2+0x217e2]
test dx, dx
jge short loc_10008127
mov dx, [edi+0x2e8]
loc_10008127:
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
movsx ax, byte [eax+ecx+0x21682]
imul ax, dx
add ax, [edi+0x2ea]
mov [edi+0x2ec], ax
jmp short loc_10008166
loc_10008148:
mov ax, [edi+0x2f2]
mov [edi+0x2f6], ax
jmp short loc_10008166
loc_10008158:
mov ax, [edi+0x2f4]
mov [edi+0x2fa], ax
loc_10008166:
xor si, si
mov ebx, [edi+0x2]
cmp [edi], si
jle short loc_1000819C
loc_10008171:
;mov al, [esp+0x1c]
mov al, [r11d+0x1c]
cmp [ebx+0x1], al
jnz short loc_10008192
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push eax
;push ebx
;push ecx
;push edx
PUSH32 eax, ebx, ecx, edx
;call loc_10008270
CALL loc_10008270
;add esp, 0x10
add r11d, 0x10
loc_10008192:
inc si
add ebx, 0x4
cmp [edi], si
jg short loc_10008171
loc_1000819C:
test ebp, ebp
jz short loc_100081AF
cmp ebp, 0x1
jz near loc_100081DC
cmp ebp, 0x2
jz near loc_10008224
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100081AF:
mov eax, [edi+0x362]
test eax, eax
jz near loc_1000826A
;cmp byte [esp+0x20], 0x0
cmp byte [r11d+0x20], 0x0
jnz near loc_1000826A
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push ecx
;push edx
PUSH32 ecx, edx
;call eax
mov r9d, eax
CALL r9
;add esp, 0x8
add r11d, 0x8
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100081DC:
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
movsx eax, byte [ecx+0x2]
;add eax, [esp+0x14]
add eax, [r11d+0x14]
movsx cx, byte [eax+0x216f2]
movsx ax, byte [eax+0x216d2]
imul cx, ax
add cx, cx
movsx eax, cx
imul eax, eax
sar eax, 0xf
;pop ebp
POP32 ebp
movsx ecx, word [edi+0x2f6]
movsx edx, ax
imul ecx, edx
sar ecx, 0xf
mov [edi+0x2f8], cx
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10008224:
mov ax, [edi+0x2fa]
cmp ax, 0x4000
jge short loc_10008250
mov word [edi+0x2fc], 0x7fff
mov ax, [edi+0x2fa]
;pop ebp
POP32 ebp
add ax, ax
mov [edi+0x2fe], ax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10008250:
mov cx, 0xffff
sub cx, ax
add cx, cx
mov [edi+0x2fc], cx
mov word [edi+0x2fe], 0x7fff
loc_1000826A:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10008270:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;sub esp, 0xc
sub r11d, 0xc
;push ebx
PUSH32 ebx
lea ecx, [eax+0xc]
;mov byte [esp+0x7], 0x0
mov byte [r11d+0x7], 0x0
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x24]
mov esi, [r11d+0x24]
;push ebp
PUSH32 ebp
movsx di, byte [esi]
movsx edx, di
cmp edx, 0x4
ja short loc_1000829A
;jmp dword [edx*4+loc_10008644]
mov r9d, [edx*4+loc_10008644]
jmp r9
loc_1000829A:
;cmp byte [esp+0x2c], 0x0
cmp byte [r11d+0x2c], 0x0
jnz near loc_1000863C
sub di, 0x5
movsx eax, di
mov edx, eax
lea ebx, [eax+eax*4]
lea eax, [edx+ebx*8]
lea eax, [eax+eax*2]
sub eax, edx
mov dx, [eax+ecx+0x1e]
lea ebx, [eax+ecx+0xc]
mov al, [eax+ecx+0x18]
;mov [esp+0x13], al
mov [r11d+0x13], al
jmp short loc_1000833D
loc_100082CC:
;cmp byte [esp+0x2c], 0x0
cmp byte [r11d+0x2c], 0x0
jz near loc_1000863C
mov dx, [eax+0x6]
jmp short loc_10008339
loc_100082DD:
;cmp byte [esp+0x2c], 0x0
cmp byte [r11d+0x2c], 0x0
jz near loc_1000863C
movsx dx, byte [eax+0x5]
jmp short loc_10008335
loc_100082EF:
;cmp byte [esp+0x2c], 0x0
cmp byte [r11d+0x2c], 0x0
jnz near loc_1000863C
movsx edx, byte [eax+0x2]
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
movsx dx, byte [edx+eax+0x21692]
jmp short loc_10008335
loc_1000830D:
;cmp byte [esp+0x2c], 0x0
cmp byte [r11d+0x2c], 0x0
jnz near loc_1000863C
sub di, 0x3
;mov ebx, [esp+0x20]
mov ebx, [r11d+0x20]
movsx edx, byte [eax+0x2]
movsx eax, di
shl eax, 0x4
add edx, eax
movsx dx, byte [edx+ebx+0x216a2]
loc_10008335:
shl dx, 0x8
loc_10008339:
;mov ebx, [esp+0x14]
mov ebx, [r11d+0x14]
loc_1000833D:
movsx di, byte [esi+0x1]
movsx eax, di
test eax, eax
jz near loc_10008593
cmp eax, 0x1
jz near loc_100085AF
cmp eax, 0x2
jz near loc_10008628
cmp byte [esi+0x1], 0x3
jl near loc_10008500
cmp byte [esi+0x1], 0x1a
jg near loc_10008500
inc di
sub eax, 0x3
sar eax, 0x2
movsx ebx, ax
lea ebp, [ebx+ebx*4]
and di, 0x3
mov eax, ebx
lea ebx, [eax+ebp*8]
lea ebx, [ebx+ebx*2]
sub ebx, eax
movsx eax, di
lea ecx, [ebx+ecx+0xc]
test eax, eax
;mov [esp+0x14], ecx
mov [r11d+0x14], ecx
jz short loc_100083B4
cmp eax, 0x1
jl near loc_1000863C
cmp eax, 0x3
jle near loc_10008423
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_100083B4:
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_100083DE
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
movsx edi, word [esi+0x2]
movsx eax, word [ecx+0x10]
imul edi, eax
sar edi, 0x10
movsx eax, dx
movsx esi, di
imul esi, eax
sar esi, 0xf
sub si, di
jmp short loc_10008401
loc_100083DE:
mov ax, [esi+0x2]
movsx esi, dx
test ax, ax
jl short loc_100083F8
movsx ecx, ax
imul esi, ecx
sar esi, 0xf
sub si, ax
jmp short loc_10008401
loc_100083F8:
movsx eax, ax
imul esi, eax
sar esi, 0xf
loc_10008401:
add si, 0x7fff
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
movsx eax, word [ecx+0x10]
movsx edx, si
imul eax, edx
sar eax, 0xf
;pop ebp
POP32 ebp
mov [ecx+0x10], ax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_10008423:
dec di
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
cmp [ecx+0x2a], di
jle near loc_1000863C
movsx edi, di
mov eax, edi
lea ecx, [edi+edi*4]
;push edx
PUSH32 edx
lea edi, [ecx+ecx*4]
add edi, eax
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
lea eax, [edi+ecx+0x2c]
;mov [esp+0x1c], eax
mov [r11d+0x1c], eax
lea edi, [eax+0x2]
;call loc_10008660
CALL loc_10008660
xor dx, dx
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;add esp, 0x4
add r11d, 0x4
cmp [ecx], dx
jle near loc_1000863C
loc_10008468:
cmp byte [edi], 0x0
jz short loc_100084D3
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_10008497
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
movsx ebp, word [esi+0x2]
movsx ebx, word [ecx+0x10]
imul ebp, ebx
sar ebp, 0x10
movsx ecx, ax
movsx ebx, bp
imul ebx, ecx
sar ebx, 0xf
sub bx, bp
jmp short loc_100084BA
loc_10008497:
mov cx, [esi+0x2]
movsx ebx, ax
test cx, cx
jl short loc_100084B1
movsx ebp, cx
imul ebx, ebp
sar ebx, 0xf
sub bx, cx
jmp short loc_100084BA
loc_100084B1:
movsx ecx, cx
imul ebx, ecx
sar ebx, 0xf
loc_100084BA:
add bx, 0x7fff
mov ecx, [edi+0x4]
movsx ebp, word [ecx]
movsx ebx, bx
imul ebp, ebx
sar ebp, 0xf
mov [ecx], bp
jmp short loc_100084E6
loc_100084D3:
movsx ebx, word [esi+0x2]
movsx ebp, ax
imul ebx, ebp
sar ebx, 0xf
mov ecx, [edi+0x4]
add [ecx], bx
loc_100084E6:
inc dx
add edi, 0x8
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
cmp [ecx], dx
jg near loc_10008468
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_10008500:
sub di, 0x1b
movsx eax, di
lea ecx, [ecx+eax*8+0x302]
cmp byte [ecx], 0x0
jz near loc_10008578
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_10008539
movsx edi, word [esi+0x2]
movsx eax, word [ebx+0x10]
imul edi, eax
sar edi, 0x10
movsx eax, dx
movsx esi, di
imul esi, eax
sar esi, 0xf
sub si, di
jmp short loc_10008559
loc_10008539:
mov di, [esi+0x2]
movsx esi, dx
movsx eax, di
test di, di
jl short loc_10008553
imul esi, eax
sar esi, 0xf
sub si, di
jmp short loc_10008559
loc_10008553:
imul esi, eax
sar esi, 0xf
loc_10008559:
add si, 0x7fff
mov eax, [ecx+0x4]
movsx edx, word [eax]
movsx ecx, si
imul edx, ecx
sar edx, 0xf
;pop ebp
POP32 ebp
mov [eax], dx
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_10008578:
mov edi, [ecx+0x4]
;pop ebp
POP32 ebp
movsx ecx, word [esi+0x2]
movsx eax, dx
imul ecx, eax
sar ecx, 0xf
add [edi], cx
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_10008593:
movsx esi, word [esi+0x2]
movsx eax, dx
imul esi, eax
sar esi, 0xf
;pop ebp
POP32 ebp
add [ecx+0x2ec], si
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_100085AF:
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_100085E4
movsx edi, word [esi+0x2]
movsx eax, word [ebx+0x10]
imul edi, eax
sar edi, 0x10
movsx eax, dx
movsx esi, di
imul esi, eax
sar esi, 0xf
sub si, di
add si, 0x7fff
cmp si, 0xa
jg short loc_10008609
mov si, 0xa
jmp short loc_10008609
loc_100085E4:
mov di, [esi+0x2]
movsx esi, dx
movsx eax, di
test di, di
jl short loc_100085FE
imul esi, eax
sar esi, 0xf
sub si, di
jmp short loc_10008604
loc_100085FE:
imul esi, eax
sar esi, 0xf
loc_10008604:
add si, 0x7fff
loc_10008609:
movsx eax, word [ecx+0x2f6]
movsx edx, si
imul eax, edx
sar eax, 0xf
;pop ebp
POP32 ebp
mov [ecx+0x2f6], ax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_10008628:
movsx esi, word [esi+0x2]
movsx eax, dx
imul esi, eax
sar esi, 0xf
add [ecx+0x2fa], si
loc_1000863C:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 4
loc_10008644:
dd loc_100082CC
dd loc_100082DD
dd loc_100082EF
dd loc_1000830D
dd loc_1000830D
align 16
loc_10008660:
;mov ax, [esp+0x4]
mov ax, [r11d+0x4]
cmp ax, 0x6000
jl short loc_10008671
mov ax, 0x7fff
jmp short loc_10008683
loc_10008671:
cmp ax, 0x2000
jg short loc_1000867C
xor ax, ax
jmp short loc_10008683
loc_1000867C:
lea eax, [eax*2-0x4000]
loc_10008683:
cmp ax, 0x20
jge short loc_1000868D
mov ax, 0x20
loc_1000868D:
;ret
RET
align 16
loc_10008690:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
;push edi
PUSH32 esi, edi
mov edi, [eax+0x372]
test edi, edi
jz short loc_100086B8
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
loc_100086A4:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10007B80
CALL loc_10007B80
;add esp, 0x8
add r11d, 0x8
mov edi, [edi+0x233e]
test edi, edi
jnz short loc_100086A4
loc_100086B8:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_100086C0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
;push edi
PUSH32 esi, edi
mov edi, [eax+0x372]
test edi, edi
jz short loc_100086EA
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
loc_100086D4:
;push 0x2
PUSH32 0x2
;push edi
;push esi
PUSH32 edi, esi
;call loc_10007FB0
CALL loc_10007FB0
;add esp, 0xc
add r11d, 0xc
mov edi, [edi+0x233e]
test edi, edi
jnz short loc_100086D4
loc_100086EA:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_100086F0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
;push edi
PUSH32 esi, edi
mov edi, [eax+0x372]
test edi, edi
jz short loc_10008718
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
loc_10008704:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10007BB0
CALL loc_10007BB0
;add esp, 0x8
add r11d, 0x8
mov edi, [edi+0x233e]
test edi, edi
jnz short loc_10008704
loc_10008718:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10008720:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
;push esi
;push edi
PUSH32 esi, edi
;call loc_10007BD0
CALL loc_10007BD0
;add esp, 0x8
add r11d, 0x8
mov esi, [esi+0x372]
test esi, esi
jz short loc_10008752
loc_1000873E:
;push esi
;push edi
PUSH32 esi, edi
;call loc_10007BD0
CALL loc_10007BD0
;add esp, 0x8
add r11d, 0x8
mov esi, [esi+0x233e]
test esi, esi
jnz short loc_1000873E
loc_10008752:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10008760:
;push ebx
;push esi
PUSH32 ebx, esi
;mov bl, [esp+0x14]
mov bl, [r11d+0x14]
;push edi
PUSH32 edi
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push ebx
PUSH32 ebx
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
;push esi
;push edi
PUSH32 esi, edi
;call loc_10007FB0
CALL loc_10007FB0
;add esp, 0xc
add r11d, 0xc
mov esi, [esi+0x372]
test esi, esi
jz short loc_10008799
loc_10008784:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;call loc_10007FB0
CALL loc_10007FB0
;add esp, 0xc
add r11d, 0xc
mov esi, [esi+0x233e]
test esi, esi
jnz short loc_10008784
loc_10008799:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_100087A0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push ebp
;push esi
;push eax
PUSH32 ebp, esi, eax
lea edi, [esi+0xc]
;call loc_10007C20
CALL loc_10007C20
;add esp, 0x8
add r11d, 0x8
mov ebx, [esi+0x372]
test ebx, ebx
jz short loc_10008801
loc_100087C3:
lea esi, [ebx+0x18]
lea eax, [edi+0xc]
mov edx, eax
lea ecx, [ebx+0xc]
xor ax, ax
cmp [ecx+0x6], ax
jle short loc_100087F7
loc_100087D7:
cmp byte [edx+0xd], 0x0
jz short loc_100087E9
mov byte [esi+0xd], 0x1
mov bp, [edx+0x12]
mov [esi+0x12], bp
loc_100087E9:
inc ax
add edx, 0x7a
add esi, 0x7a
cmp [ecx+0x6], ax
jg short loc_100087D7
loc_100087F7:
mov ebx, [ebx+0x233e]
test ebx, ebx
jnz short loc_100087C3
loc_10008801:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10008810:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x14]
mov ebx, [r11d+0x14]
;push edi
PUSH32 edi
;push 0x24
PUSH32 0x24
mov edi, GlobalAlloc
;push 0x40
PUSH32 0x40
mov dword [ebx], 0x0
;call edi
mov r9d, edi
CALL r9
mov [ebx], eax
mov esi, eax
test esi, esi
jnz short loc_1000883A
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000883A:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;push eax
PUSH32 eax
mov [esi], eax
;push 0x0
PUSH32 0x0
;call edi
mov r9d, edi
CALL r9
mov [esi+0x8], eax
test eax, eax
jnz short loc_10008855
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10008855:
;mov bx, [esp+0x14]
mov bx, [r11d+0x14]
movsx eax, bx
shl eax, 0x4
;push eax
PUSH32 eax
;push 0x40
PUSH32 0x40
;call edi
mov r9d, edi
CALL r9
mov [esi+0x20], eax
test eax, eax
jnz short loc_10008875
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10008875:
mov [esi+0x1c], bx
;push esi
PUSH32 esi
;call loc_10008B10
CALL loc_10008B10
;add esp, 0x4
add r11d, 0x4
xor eax, eax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10008890:
;push esi
;push edi
PUSH32 esi, edi
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
test edi, edi
jz short loc_100088BF
mov eax, [edi+0x8]
test eax, eax
jz short loc_100088AC
;push eax
PUSH32 eax
mov esi, GlobalFree
;call esi
mov r9d, esi
CALL r9
jmp short loc_100088B2
loc_100088AC:
mov esi, GlobalFree
loc_100088B2:
mov eax, [edi+0x20]
test eax, eax
jz short loc_100088BC
;push eax
PUSH32 eax
;call esi
mov r9d, esi
CALL r9
loc_100088BC:
;push edi
PUSH32 edi
;call esi
mov r9d, esi
CALL r9
loc_100088BF:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_100088D0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
;push ebp
PUSH32 edi, ebp
lea edx, [esi+0x6]
test dl, 0x1
jz short loc_100088E1
inc edx
loc_100088E1:
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
mov ebx, [ecx+0x14]
test ebx, ebx
jz short loc_100088FC
loc_100088EC:
mov eax, [ebx+0x4]
sub eax, [ebx]
cmp eax, edx
jae short loc_10008903
mov ebx, [ebx+0xc]
test ebx, ebx
jnz short loc_100088EC
loc_100088FC:
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10008903:
mov ebp, [ebx]
mov eax, [ecx+0x8]
lea edi, [eax+ebp+0x6]
add ebp, edx
;push edi
PUSH32 edi
mov [ebx], ebp
;push ecx
PUSH32 ecx
add [ecx+0x4], edx
;call loc_10008AE0
CALL loc_10008AE0
;add esp, 0x8
add r11d, 0x8
mov [eax], esi
mov word [eax+0x4], 0x0
mov eax, edi
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10008930:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
;push ebp
;push edi
;push esi
PUSH32 ebp, edi, esi
;call loc_10008A20
CALL loc_10008A20
;add esp, 0x8
add r11d, 0x8
lea ebp, [eax+0x6]
test ebp, 0x1
jz short loc_10008952
inc ebp
loc_10008952:
sub edi, [esi+0x8]
;push esi
PUSH32 esi
sub edi, 0x6
;call loc_10008BA0
CALL loc_10008BA0
;add esp, 0x4
add r11d, 0x4
lea ebx, [edi+ebp]
test eax, eax
jz short loc_10008970
mov [eax], edi
mov [eax+0x4], ebx
sub [esi+0x4], ebp
loc_10008970:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10008980:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
PUSH32 edi, ebp
loc_10008988:
xor cl, cl
mov edi, [esi+0x14]
test edi, edi
jz near loc_100089E2
loc_10008991:
mov edx, [edi+0xc]
test edx, edx
jz near loc_100089DB
loc_10008998:
mov ebp, [edx]
cmp [edi+0x4], ebp
jnz short loc_100089B8
mov ebx, [edx+0xc]
mov eax, [edx+0x4]
;push edx
PUSH32 edx
mov [edi+0x4], eax
;push esi
PUSH32 esi
;call loc_10008C00
CALL loc_10008C00
;add esp, 0x8
add r11d, 0x8
mov edx, ebx
mov cl, 0x1
jmp short loc_100089D7
loc_100089B8:
mov eax, [edi]
cmp [edx+0x4], eax
jnz short loc_100089D4
mov ebx, [edx+0xc]
;push edx
;push esi
PUSH32 edx, esi
mov [edi], ebp
;call loc_10008C00
CALL loc_10008C00
;add esp, 0x8
add r11d, 0x8
mov edx, ebx
mov cl, 0x1
jmp short loc_100089D7
loc_100089D4:
mov edx, [edx+0xc]
loc_100089D7:
test edx, edx
jnz near loc_10008998
loc_100089DB:
mov edi, [edi+0xc]
test edi, edi
jnz near loc_10008991
loc_100089E2:
test cl, cl
jnz near loc_10008988
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_100089F0:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
add edx, 0x6
test dl, 0x1
jz short loc_100089FD
inc edx
loc_100089FD:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov eax, [eax+0x14]
test eax, eax
jz short loc_10008A18
loc_10008A08:
mov ecx, [eax+0x4]
sub ecx, [eax]
cmp ecx, edx
jae short loc_10008A1B
mov eax, [eax+0xc]
test eax, eax
jnz short loc_10008A08
loc_10008A18:
xor al, al
;ret
RET
loc_10008A1B:
mov al, 0x1
;ret
RET
align 16
loc_10008A20:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10008AE0
CALL loc_10008AE0
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_10008A39
mov eax, [eax]
;ret
RET
loc_10008A39:
xor eax, eax
;ret
RET
align 16
loc_10008A40:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10008AE0
CALL loc_10008AE0
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_10008A6E
mov cx, [eax+0x4]
;movzx dx, byte [esp+0xc]
movzx dx, byte [r11d+0xc]
xor dx, cx
and dx, 0x1
xor dx, cx
mov [eax+0x4], dx
loc_10008A6E:
;ret
RET
align 16
loc_10008A70:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10008AE0
CALL loc_10008AE0
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_10008AA1
mov cx, [eax+0x4]
;movzx dx, byte [esp+0xc]
movzx dx, byte [r11d+0xc]
add dx, dx
xor dx, cx
and dx, 0x2
xor dx, cx
mov [eax+0x4], dx
loc_10008AA1:
;ret
RET
align 16
loc_10008AB0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10008AE0
CALL loc_10008AE0
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_10008ACF
mov al, [eax+0x4]
and al, 0x2
shr al, 0x1
;ret
RET
loc_10008ACF:
xor al, al
;ret
RET
align 16
loc_10008AE0:
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov edx, [ecx+0x8]
cmp eax, edx
jbe short loc_10008AFF
mov ecx, [ecx]
add ecx, edx
cmp ecx, eax
jbe short loc_10008AFF
test al, 0x1
jnz short loc_10008AFF
sub eax, 0x6
;ret
RET
loc_10008AFF:
xor eax, eax
;ret
RET
align 16
loc_10008B10:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
mov ax, [esi+0x1c]
mov edx, [esi+0x20]
movsx ecx, ax
shl ecx, 0x4
mov [esi+0xc], edx
add ecx, edx
lea edi, [eax-0x1]
sub ecx, 0x10
mov [esi+0x10], ecx
xor ecx, ecx
mov [esi+0x1e], cx
mov [esi+0x14], ecx
test ax, ax
mov [esi+0x18], ecx
jle short loc_10008B75
xor ebx, ebx
loc_10008B45:
test cx, cx
mov [edx], ebx
mov [edx+0x4], ebx
jle short loc_10008B57
lea eax, [edx-0x10]
mov [edx+0x8], eax
jmp short loc_10008B5A
loc_10008B57:
mov [edx+0x8], ebx
loc_10008B5A:
cmp di, cx
jg short loc_10008B64
mov [edx+0xc], ebx
jmp short loc_10008B6A
loc_10008B64:
lea eax, [edx+0x10]
mov [edx+0xc], eax
loc_10008B6A:
inc cx
add edx, 0x10
cmp [esi+0x1c], cx
jg short loc_10008B45
loc_10008B75:
;push esi
PUSH32 esi
;call loc_10008BA0
CALL loc_10008BA0
;add esp, 0x4
add r11d, 0x4
mov dword [eax], 0x0
mov ecx, [esi]
;pop edi
POP32 edi
mov [eax+0x4], ecx
mov dword [esi+0x4], 0x0
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_10008BA0:
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
mov eax, [edx+0xc]
test eax, eax
jnz short loc_10008BAE
xor eax, eax
;ret
RET
loc_10008BAE:
mov ecx, [eax+0xc]
cmp [edx+0x10], eax
mov [edx+0xc], ecx
jnz short loc_10008BC0
mov dword [edx+0x10], 0x0
loc_10008BC0:
mov ecx, [eax+0xc]
test ecx, ecx
jz short loc_10008BCE
mov dword [ecx+0x8], 0x0
loc_10008BCE:
mov dword [eax+0xc], 0x0
mov ecx, [edx+0x18]
mov [eax+0x8], ecx
test ecx, ecx
jz short loc_10008BEA
mov [ecx+0xc], eax
inc word [edx+0x1e]
mov [edx+0x18], eax
;ret
RET
loc_10008BEA:
inc word [edx+0x1e]
mov [edx+0x14], eax
mov [edx+0x18], eax
;ret
RET
align 16
loc_10008C00:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov edx, [esi+0x8]
lea edi, [esi+0xc]
test edx, edx
mov eax, [edi]
jz short loc_10008C1B
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
mov [edx+0xc], eax
jmp short loc_10008C22
loc_10008C1B:
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
mov [ecx+0x14], eax
loc_10008C22:
cmp [ecx+0x18], esi
jnz short loc_10008C2A
mov [ecx+0x18], edx
loc_10008C2A:
mov eax, [edi]
test eax, eax
jz short loc_10008C33
mov [eax+0x8], edx
loc_10008C33:
mov dword [edi], 0x0
mov eax, [ecx+0x10]
mov [esi+0x8], eax
test eax, eax
jz short loc_10008C50
;pop edi
POP32 edi
mov [eax+0xc], esi
dec word [ecx+0x1e]
mov [ecx+0x10], esi
;pop esi
POP32 esi
;ret
RET
loc_10008C50:
dec word [ecx+0x1e]
;pop edi
POP32 edi
mov [ecx+0xc], esi
mov [ecx+0x10], esi
;pop esi
POP32 esi
;ret
RET
align 16
loc_10008C60:
;sub esp, 0xc
sub r11d, 0xc
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
xor ebx, ebx
;mov esi, [esp+0x20]
mov esi, [r11d+0x20]
;push ebp
PUSH32 ebp
add esi, 0x390
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
add eax, 0xc
;mov ecx, [esp+0x24]
mov ecx, [r11d+0x24]
;mov [esp+0x10], eax
mov [r11d+0x10], eax
mov eax, [ecx+0x8]
mov edx, [eax+0x4]
lea ebp, [edx+eax-0x18]
mov [ecx+0x38c], ebp
mov cx, 0x1
mov edi, [ebp+0x8]
mov dx, [edi+0x3a]
add edi, 0x3a
add edi, 0x4
cmp dx, cx
jle short loc_10008CC3
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
mov al, [eax+0x4]
loc_10008CAF:
cmp [edi+0xd], al
jge short loc_10008CC0
inc cx
add edi, 0x12
cmp dx, cx
jg short loc_10008CAF
jmp short loc_10008CC3
loc_10008CC0:
mov ebx, [edi+0x8]
loc_10008CC3:
test ebx, ebx
jnz short loc_10008CE2
mov ebx, [edi+0x8]
test ebx, ebx
jnz short loc_10008CE2
;mov edi, [esp+0x20]
mov edi, [r11d+0x20]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
add edi, 0x240ae
mov ebx, [ecx+0x240c0]
loc_10008CE2:
add ebx, 0x30
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
cmp word [ecx+0x10], 0x32
jl short loc_10008CF6
mov byte [esi+0x4], 0x0
jmp short loc_10008CFC
loc_10008CF6:
mov al, [ebp+0xe]
mov [esi+0x4], al
loc_10008CFC:
mov al, [ebp+0xf]
mov [esi+0x5], al
mov dword [esi+0x8], 0x0
mov ecx, [ebx+0x6]
mov [esi+0x20], ecx
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
mov dl, [edi+0xc]
mov [esi+0x24], dl
mov al, [edi+0xe]
mov [esi+0x25], al
mov eax, [esi+0x20]
mov edx, [ecx+0x2407e]
;push edx
;push eax
PUSH32 edx, eax
;call loc_100062D0
CALL loc_100062D0
;mov ecx, [esp+0x2c]
mov ecx, [r11d+0x2c]
;mov [esp+0x1c], eax
mov [r11d+0x1c], eax
mov ax, [ecx+0x6]
;mov edx, [esp+0x28]
mov edx, [r11d+0x28]
movsx cx, byte [esi+0x24]
shl cx, 0x8
;add esp, 0x8
add r11d, 0x8
sub ax, cx
;push eax
;push edx
PUSH32 eax, edx
;call loc_10004300
CALL loc_10004300
;mov ecx, [esp+0x28]
mov ecx, [r11d+0x28]
;add esp, 0x8
add r11d, 0x8
movsx edx, byte [esi+0x25]
;push eax
PUSH32 eax
mov edx, [ecx+edx*4+0x364]
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;mov [esp+0x1c], edx
mov [r11d+0x1c], edx
;push eax
PUSH32 eax
;call loc_10006310
CALL loc_10006310
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;add esp, 0x8
add r11d, 0x8
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_10006310
CALL loc_10006310
;add esp, 0x8
add r11d, 0x8
mov [esi], eax
sar eax, 0xa
mov [esi+0xc], eax
mov ecx, [ebx+0x16]
cmp [ebx+0x12], ecx
jge short loc_10008DAC
shl ecx, 0xc
lea eax, [esi+0x10]
mov [esi+0x14], ecx
mov edx, [ebx+0x12]
shl edx, 0xc
sub ecx, edx
mov [eax], ecx
jmp short loc_10008DBF
loc_10008DAC:
mov eax, [ebx+0xe]
dec eax
shl eax, 0xc
mov [esi+0x14], eax
lea eax, [esi+0x10]
mov dword [eax], 0x1000
loc_10008DBF:
cmp dword [eax], 0x4000
jae short loc_10008DCD
mov dword [eax], 0x4000
loc_10008DCD:
mov eax, [ebx+0xe]
add ebx, 0x1a
dec eax
shl eax, 0xc
lea edx, [esi+0x28]
mov [esi+0x18], eax
mov [esi+0x1c], ebx
mov cl, [ebp+0x12]
mov [esi+0x26], cl
mov al, [ebp+0x13]
mov [esi+0x27], al
xor ebx, ebx
mov cx, [ebp+0x14]
mov [edx], cx
lea ecx, [esi+0x2a]
mov ax, [ebp+0x16]
mov [ecx], ax
xor ax, ax
loc_10008E02:
movsx ebp, ax
inc ax
mov [esi+ebp*2+0x2c], bx
cmp ax, 0x4
jl short loc_10008E02
;mov ebp, [esp+0x10]
mov ebp, [r11d+0x10]
add esi, 0x6
mov word [ebp+0x300], 0x3
lea eax, [ebp+0x302]
add eax, 0x8
mov byte [eax-0x8], 0x0
mov [eax-0x4], esi
mov byte [eax], 0x0
mov [eax+0x4], edx
mov byte [eax+0x8], 0x0
mov [eax+0xc], ecx
add eax, 0x8
movsx eax, word [edi+0x10]
movsx ecx, word [ebp+0x2f8]
imul eax, ecx
sar eax, 0xf
mov [ebp+0x2f8], ax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 16
loc_10008E70:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0xc]
mov ebx, [r11d+0xc]
;push edi
PUSH32 edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
mov eax, [ebx+0x2407e]
;push eax
PUSH32 eax
mov ecx, [edi+0x3b0]
lea esi, [edi+0x390]
;push ecx
PUSH32 ecx
;call loc_100062D0
CALL loc_100062D0
movsx edx, byte [edi+0x4]
movsx ecx, byte [esi+0x24]
;add esp, 0x8
add r11d, 0x8
sub edx, ecx
movsx ecx, byte [esi+0x25]
mov edx, [ebx+edx*4+0x164]
mov edi, [ebx+ecx*4+0x364]
;push edx
;push eax
PUSH32 edx, eax
;call loc_10006310
CALL loc_10006310
;add esp, 0x8
add r11d, 0x8
;push edi
;push eax
PUSH32 edi, eax
;call loc_10006310
CALL loc_10006310
;add esp, 0x8
add r11d, 0x8
mov [esi], eax
sar eax, 0xa
;pop edi
POP32 edi
mov [esi+0xc], eax
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_10008EE0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov dword [eax+0x398], 0x0
;ret
RET
align 16
loc_10008EF0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
lea esi, [eax+0x390]
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
movsx ecx, word [eax+0x2f8]
mov cx, [edx+ecx*2+0x10682]
mov eax, [esi]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10006330
CALL loc_10006330
shr eax, 0xa
;add esp, 0x8
add r11d, 0x8
mov [esi+0xc], eax
;pop esi
POP32 esi
;ret
RET
align 16
loc_10008F30:
;sub esp, 0x18
sub r11d, 0x18
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x28]
mov esi, [r11d+0x28]
;push edi
;push ebp
PUSH32 edi, ebp
add esi, 0x390
mov cl, [esi+0x4]
mov edi, [esi+0x8]
mov eax, [esi+0xc]
;mov [esp+0x13], cl
mov [r11d+0x13], cl
;mov ecx, [esp+0x30]
mov ecx, [r11d+0x30]
;mov [esp+0x20], eax
mov [r11d+0x20], eax
cmp byte [ecx], 0x0
jnz short loc_10008F6B
cmp byte [esi+0x5], 0x0
jz short loc_10008F6B
;mov dword [esp+0x18], 0x7fffffff
mov dword [r11d+0x18], 0x7fffffff
jmp short loc_10008F72
loc_10008F6B:
mov eax, [esi+0x14]
;mov [esp+0x18], eax
mov [r11d+0x18], eax
loc_10008F72:
mov eax, [esi+0x18]
mov ecx, [esi+0x1c]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
;mov [esp+0x1c], ecx
mov [r11d+0x1c], ecx
;mov eax, [esp+0x2c]
mov eax, [r11d+0x2c]
mov ebx, [eax+0x24086]
mov eax, [eax+0x24082]
test eax, eax
jle near loc_10009220
;mov [esp+0x24], eax
mov [r11d+0x24], eax
loc_10008F9C:
;add edi, [esp+0x20]
add edi, [r11d+0x20]
;cmp edi, [esp+0x18]
cmp edi, [r11d+0x18]
jl short loc_10008FA9
sub edi, [esi+0x10]
loc_10008FA9:
;cmp edi, [esp+0x14]
cmp edi, [r11d+0x14]
jl short loc_10008FB3
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
loc_10008FB3:
mov eax, edi
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
and eax, 0xfffff7ff
sar eax, 0xb
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
mov ax, [eax+ecx]
jz short loc_10009010
mov ecx, edi
lea ebp, [edi+0x1000]
and cx, 0xfff
;cmp ebp, [esp+0x18]
cmp ebp, [r11d+0x18]
lea edx, [ecx*8]
jl short loc_10008FE9
sub ebp, [esi+0x10]
loc_10008FE9:
;cmp ebp, [esp+0x14]
cmp ebp, [r11d+0x14]
jl short loc_10008FF3
;mov ebp, [esp+0x14]
mov ebp, [r11d+0x14]
loc_10008FF3:
sar ebp, 0xc
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
mov cx, [ecx+ebp*2]
movsx edx, dx
sub cx, ax
movsx ebp, cx
imul ebp, edx
sar ebp, 0xf
add ax, bp
loc_10009010:
cmp byte [esi+0x26], 0x0
jz near loc_10009210
movsx ecx, byte [esi+0x27]
cmp ecx, 0x3
ja near loc_10009210
;jmp dword [ecx*4+loc_1000923C]
mov r9d, [ecx*4+loc_1000923C]
jmp r9
loc_1000902E:
mov cx, [esi+0x2c]
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x28]
movsx eax, ax
imul ecx, eax
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
add cx, [esi+0x2c]
mov ax, cx
mov [esi+0x2c], cx
jmp loc_10009210
loc_10009059:
mov cx, [esi+0x2c]
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x28]
movsx eax, ax
imul ecx, eax
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
add cx, [esi+0x2c]
mov [esi+0x2c], cx
mov ax, [esi+0x2e]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x28]
movsx edx, ax
imul ecx, edx
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
add cx, [esi+0x2e]
mov ax, cx
mov [esi+0x2e], ax
jmp loc_10009210
loc_100090A7:
mov cx, [esi+0x2c]
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x28]
movsx eax, ax
imul ecx, eax
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
add cx, [esi+0x2c]
mov [esi+0x2c], cx
mov ax, [esi+0x2e]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x28]
movsx edx, ax
imul ecx, edx
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
add cx, [esi+0x2e]
mov [esi+0x2e], cx
mov ax, [esi+0x30]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x28]
movsx edx, ax
imul ecx, edx
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
add cx, [esi+0x30]
mov [esi+0x30], cx
mov ax, [esi+0x32]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x28]
movsx edx, ax
imul ecx, edx
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
add cx, [esi+0x32]
mov ax, cx
jmp loc_1000920C
loc_10009137:
movsx edx, word [esi+0x2a]
movsx ecx, word [esi+0x32]
imul edx, ecx
movsx eax, ax
sar edx, 0xd
sub eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov dx, [esi+0x28]
;add esp, 0x4
add r11d, 0x4
mov cx, 0x7fff
sub cx, dx
movsx ebp, cx
movsx ecx, ax
movsx eax, dx
imul ecx, eax
movsx eax, word [esi+0x2c]
sar ecx, 0xf
imul eax, ebp
sar eax, 0xf
movsx edx, cx
movsx eax, ax
add eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov [esi+0x2c], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [esi+0x28]
movsx edx, ax
imul ecx, edx
movsx eax, word [esi+0x2e]
sar ecx, 0xf
imul eax, ebp
sar eax, 0xf
movsx edx, cx
movsx eax, ax
add eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov [esi+0x2e], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [esi+0x28]
movsx edx, ax
imul ecx, edx
movsx eax, word [esi+0x30]
sar ecx, 0xf
imul eax, ebp
sar eax, 0xf
movsx edx, cx
movsx eax, ax
add eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov [esi+0x30], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [esi+0x28]
movsx edx, ax
imul ecx, edx
sar ecx, 0xf
movsx edx, cx
movsx eax, word [esi+0x32]
imul eax, ebp
sar eax, 0xf
movsx eax, ax
add eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
;add esp, 0x4
add r11d, 0x4
loc_1000920C:
mov [esi+0x32], ax
loc_10009210:
mov [ebx], ax
add ebx, 0x2
;dec dword [esp+0x24]
dec dword [r11d+0x24]
jnz near loc_10008F9C
loc_10009220:
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
mov [esi+0x8], edi
cmp word [eax+0x302], 0x0
setle al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x18
add r11d, 0x18
;ret
RET
db 139
db 255
align 4
loc_1000923C:
dd loc_1000902E
dd loc_10009059
dd loc_100090A7
dd loc_10009137
times 4 db 204
align 4
loc_10009250:
;push esi
;push edi
PUSH32 esi, edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
mov eax, [edi+0x8]
lea esi, [edi+0x390]
lea edx, [edi+0xc]
mov ecx, [eax+0x4]
lea eax, [ecx+eax-0xc]
xor ecx, ecx
mov [edi+0x38c], eax
mov eax, [eax+0x8]
add eax, 0x30
mov [esi], ecx
mov edi, [eax+0xe]
add eax, 0x1a
mov [esi+0x4], edi
;pop edi
POP32 edi
mov [esi+0x8], eax
mov [edx+0x2ec], cx
;pop esi
POP32 esi
mov [edx+0x300], cx
;ret
RET
align 16
loc_100092A0:
;ret
RET
align 16
loc_100092B0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x10]
mov ebx, [r11d+0x10]
;push edi
;push ebp
PUSH32 edi, ebp
add ebx, 0x390
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
mov ecx, [ebx]
mov edx, [ebx+0x4]
mov edi, [ebx+0x8]
mov esi, [eax+0x24086]
mov ebp, [eax+0x24082]
test ebp, ebp
jle short loc_100092F3
loc_100092DA:
inc ecx
cmp ecx, edx
jae short loc_100092E5
mov ax, [edi+ecx*2]
jmp short loc_100092EA
loc_100092E5:
xor ax, ax
mov ecx, edx
loc_100092EA:
mov [esi], ax
add esi, 0x2
dec ebp
jnz short loc_100092DA
loc_100092F3:
;pop ebp
POP32 ebp
mov [ebx], ecx
;pop edi
POP32 edi
cmp ecx, edx
sbb al, al
;pop esi
POP32 esi
inc al
;pop ebx
POP32 ebx
;ret
RET
loc_10009300:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;sub esp, 0x14
sub r11d, 0x14
;push ebx
PUSH32 ebx
lea ecx, [edx+0x390]
;push esi
PUSH32 esi
lea ebx, [edx+0xc]
;push edi
PUSH32 edi
mov eax, [edx+0x8]
;mov [esp+0xc], ecx
mov [r11d+0xc], ecx
;push ebp
PUSH32 ebp
mov ecx, [eax+0x4]
lea esi, [ecx+eax-0x26]
;mov ecx, [esp+0x28]
mov ecx, [r11d+0x28]
mov [edx+0x38c], esi
movsx eax, byte [edx+0x4]
mov ax, [ecx+eax*2+0x564]
;mov edx, [esp+0x10]
mov edx, [r11d+0x10]
mov [edx], ax
add edx, 0x4
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
;mov [esp+0x14], edx
mov [r11d+0x14], edx
mov word [edx-0x2], 0x0
mov ax, [esi+0x2]
add ecx, 0x6
mov [edx], ax
;mov [esp+0x18], ecx
mov [r11d+0x18], ecx
mov ax, [esi+0x4]
mov [ecx], ax
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
mov dl, [esi+0x6]
add eax, 0xc
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
;mov [esp+0x1c], eax
mov [r11d+0x1c], eax
add esi, 0xa
mov [eax-0x4], dl
mov word [eax-0x2], 0x1
mov dx, [esi-0x2]
lea ebp, [ecx+0x10]
mov [eax], dx
mov edi, ebp
mov word [ecx+0xe], 0x0
mov word [ecx+0x1fa0], 0x0
;mov word [esp+0x20], 0x2
mov word [r11d+0x20], 0x2
loc_100093A5:
mov al, [esi]
lea ecx, [edi+0x2]
;push ecx
PUSH32 ecx
mov [edi], al
;call loc_1000BFF0
CALL loc_1000BFF0
mov ax, [esi+0x2]
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
mov [edi+0xfaa], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [ecx]
movsx eax, ax
imul ecx, eax
sar ecx, 0xf
mov [edi+0x4], cx
mov al, [esi+0x4]
mov [edi+0xfac], al
mov dl, [esi+0x5]
mov [edi+0xfad], dl
cmp byte [edi+0xfac], 0x0
jz short loc_100093FC
mov ax, [esi+0x6]
mov [edi+0xfae], ax
jmp short loc_10009405
loc_100093FC:
mov word [edi+0xfae], 0x7fff
loc_10009405:
mov word [edi+0xfb0], 0x0
mov ax, [esi+0x8]
mov [edi+0xfb2], ax
mov cx, [esi+0xa]
xor ax, ax
mov [edi+0xfb4], cx
xor ecx, ecx
loc_10009429:
movsx edx, ax
inc ax
mov [edi+edx*2+0xfb6], cx
cmp ax, 0x8
jl short loc_10009429
mov ax, [esi+0xc]
add esi, 0xe
mov [edi+0xfc6], ax
add edi, 0xfc8
;dec word [esp+0x20]
dec word [r11d+0x20]
jnz near loc_100093A5
mov di, 0x2
mov esi, ebp
loc_10009461:
mov ax, [esi+0xfae]
lea ecx, [esi+0x2]
;mov edx, [esp+0x28]
mov edx, [r11d+0x28]
;push eax
;push ecx
PUSH32 eax, ecx
add esi, 0xfc8
;push edx
PUSH32 edx
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
dec di
jnz short loc_10009461
add ebx, 0x302
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
add ebx, 0x8
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
mov word [ebx-0xa], 0xb
mov byte [ebx-0x8], 0x0
mov [ebx-0x4], ecx
add ebx, 0x8
mov byte [ebx-0x8], 0x1
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
mov [ebx-0x4], eax
mov byte [ebx], 0x1
mov [ebx+0x4], ecx
add ebx, 0x8
mov cx, 0x2
loc_100094BD:
lea eax, [ebp+0xfaa]
lea edx, [ebp+0xfae]
mov byte [ebx], 0x0
add ebx, 0x8
add ebx, 0x8
add ebp, 0xfc8
add ebx, 0x8
add ebx, 0x8
dec cx
mov [ebx-0x1c], eax
mov byte [ebx-0x18], 0x0
lea eax, [ebp-0x14]
mov [ebx-0x14], edx
mov byte [ebx-0x10], 0x0
lea edx, [ebp-0x2]
mov [ebx-0xc], eax
mov byte [ebx-0x8], 0x0
mov [ebx-0x4], edx
jnz short loc_100094BD
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14
add r11d, 0x14
;ret
RET
align 16
loc_10009510:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
lea esi, [eax+0x390]
movsx eax, word [eax+0x2f8]
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
add eax, eax
mov ecx, edi
sub ecx, eax
xor eax, eax
mov ax, [ecx+0x10682]
add esi, 0x10
mov bx, 0x2
xor ecx, ecx
mov cx, [esi-0x10]
imul eax, ecx
shr eax, 0xf
movsx ebp, ax
loc_1000954E:
lea edx, [esi+0x2]
add esi, 0xfc8
movsx eax, word [esi-0x1e]
imul eax, ebp
sar eax, 0xf
mov [esi-0xfc4], ax
mov cx, [esi-0x1a]
;push ecx
;push edx
;push edi
PUSH32 ecx, edx, edi
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
dec bx
jnz short loc_1000954E
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10009580:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;sub esp, 0x14
sub r11d, 0x14
;push ebx
PUSH32 ebx
mov ecx, [eax+0x38c]
;mov [esp+0xc], ecx
mov [r11d+0xc], ecx
;push esi
;push edi
PUSH32 esi, edi
lea esi, [eax+0x390]
;push ebp
PUSH32 ebp
mov edi, 0x2
lea ebp, [esi+0x10]
;mov ebx, [esp+0x28]
mov ebx, [r11d+0x28]
;mov byte [esp+0x11], 0x0
mov byte [r11d+0x11], 0x0
loc_100095AC:
cmp byte [ebp], 0x0
jz short loc_100095C7
mov ax, [ebp+0xfae]
lea ecx, [ebp+0x2]
;push eax
;push ecx
;push ebx
PUSH32 eax, ecx, ebx
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
loc_100095C7:
add ebp, 0xfc8
dec edi
jnz short loc_100095AC
mov eax, [ebx+0x24086]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
mov eax, [ebx+0x24082]
test eax, eax
jle near loc_100097B3
;mov [esp+0x20], eax
mov [r11d+0x20], eax
loc_100095EC:
mov cx, [esi+0x2]
cmp cx, 0x7fff
jge near loc_100096CE
mov ax, [esi+0x4]
add ax, cx
mov [esi+0x2], ax
jns short loc_1000960E
mov word [esi+0x2], 0x7fff
loc_1000960E:
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
movsx eax, byte [eax]
cmp eax, 0x4
ja short loc_10009621
;jmp dword [eax*4+loc_100097C0]
mov r9d, [eax*4+loc_100097C0]
jmp r9
loc_10009621:
xor dx, dx
jmp short loc_10009676
loc_10009626:
mov dx, [esi+0x2]
jmp short loc_10009676
loc_1000962C:
mov dx, 0x7fff
sub dx, [esi+0x2]
jmp short loc_10009676
loc_10009636:
mov ax, [esi+0x2]
cmp ax, 0x3fff
jge short loc_10009649
lea edx, [eax*2]
jmp short loc_10009676
loc_10009649:
mov cx, 0x3ffe
sub cx, ax
lea edx, [ecx*2]
jmp short loc_10009676
loc_10009659:
mov dx, 0x7fff
jmp short loc_10009676
loc_1000965F:
mov cx, [esi+0x2]
mov ax, 0x7fff
sub ax, cx
movsx edx, ax
movsx ecx, cx
imul edx, ecx
sar edx, 0xd
loc_10009676:
cmp word [esi+0x2], 0x7fff
jnz short loc_10009681
xor dx, dx
loc_10009681:
cmp byte [esi+0x8], 0x0
jz short loc_100096BD
mov ax, [esi+0xa]
test ah, 0x80
lea ecx, [eax*2]
jz short loc_1000969C
xor cx, 0x1d87
loc_1000969C:
mov [esi+0xa], cx
movsx eax, word [esi+0xc]
movsx ecx, word [esi+0xa]
imul eax, ecx
sar eax, 0xf
movsx ecx, dx
movsx eax, ax
imul eax, ecx
sar eax, 0xf
add dx, ax
loc_100096BD:
movsx ecx, word [esi+0x6]
movsx eax, dx
imul ecx, eax
sar ecx, 0xf
mov [esi+0xe], cx
loc_100096CE:
mov di, [esi+0xe]
lea ebx, [esi+0x10]
;mov word [esp+0x1c], 0x2
mov word [r11d+0x1c], 0x2
loc_100096DC:
cmp byte [ebx], 0x0
jz near loc_10009757
lea ebp, [ebx+0x2]
;push ebp
PUSH32 ebp
;call loc_1000C080
CALL loc_1000C080
;mov [esp+0x16], ax
mov [r11d+0x16], ax
;add esp, 0x4
add r11d, 0x4
cmp byte [ebx+0xfac], 0x0
jz short loc_1000972C
mov cx, [ebx+0xfb0]
sar ax, 0x1
mov dx, cx
sar dx, 0x1
sub ax, dx
movsx eax, ax
movsx edx, word [ebx+0xfae]
imul eax, edx
sar eax, 0xe
add ax, cx
mov [ebx+0xfb0], ax
jmp short loc_10009731
loc_1000972C:
;mov ax, [esp+0x12]
mov ax, [r11d+0x12]
loc_10009731:
movsx ecx, word [ebx+0xfc6]
movsx eax, ax
imul ecx, eax
mov ax, [esi+0xe]
sar ecx, 0xf
sub ax, cx
;push eax
;push ebp
PUSH32 eax, ebp
;call loc_1000C0D0
CALL loc_1000C0D0
;add di, [esp+0x1a]
add di, [r11d+0x1a]
;add esp, 0x8
add r11d, 0x8
loc_10009757:
add ebx, 0xfc8
;dec word [esp+0x1c]
dec word [r11d+0x1c]
jnz near loc_100096DC
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push edi
PUSH32 edi
;add dword [esp+0x18], 0x2
add dword [r11d+0x18], 0x2
mov [eax], di
;call loc_10006280
CALL loc_10006280
;add esp, 0x4
add r11d, 0x4
cmp ax, 0x80
jge short loc_100097A0
mov ax, [esi+0x1fa0]
inc ax
mov [esi+0x1fa0], ax
cmp ax, 0x100
jl short loc_100097A9
;mov byte [esp+0x11], 0x1
mov byte [r11d+0x11], 0x1
jmp short loc_100097A9
loc_100097A0:
mov word [esi+0x1fa0], 0x0
loc_100097A9:
;dec dword [esp+0x20]
dec dword [r11d+0x20]
jnz near loc_100095EC
loc_100097B3:
;mov al, [esp+0x11]
mov al, [r11d+0x11]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14
add r11d, 0x14
;ret
RET
align 4
loc_100097C0:
dd loc_10009626
dd loc_1000962C
dd loc_10009636
dd loc_10009659
dd loc_1000965F
align 16
loc_100097E0:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;sub esp, 0x8
sub r11d, 0x8
;push ebx
PUSH32 ebx
lea ecx, [edx+0x390]
;push esi
PUSH32 esi
mov eax, [edx+0x8]
;push edi
PUSH32 edi
lea esi, [edx+0xc]
;mov [esp+0xc], ecx
mov [r11d+0xc], ecx
;push ebp
PUSH32 ebp
mov ecx, [eax+0x4]
lea ebx, [ecx+eax-0x1c]
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov [edx+0x38c], ebx
add ecx, 0x6
mov ax, [ebx]
;mov [esp+0x14], ecx
mov [r11d+0x14], ecx
movsx ebp, ax
mov [ecx-0x6], ax
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov di, [eax+ebp*2+0x664]
;mov ebp, [esp+0x10]
mov ebp, [r11d+0x10]
mov [ecx-0x4], di
mov di, [ebx+0x2]
mov [ecx], di
mov cx, [ebp]
cmp cx, 0x1
jge short loc_1000984A
mov word [ebp+0x8], 0x1
jmp short loc_10009886
loc_1000984A:
cmp cx, 0x3
jge short loc_1000985C
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov word [ecx+0x8], 0x2
jmp short loc_10009886
loc_1000985C:
cmp cx, 0x8
jge short loc_1000986E
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov word [ecx+0x8], 0x3
jmp short loc_10009886
loc_1000986E:
cmp cx, 0xf
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
jge short loc_10009880
mov word [ecx+0x8], 0x4
jmp short loc_10009886
loc_10009880:
mov word [ecx+0x8], 0x0
loc_10009886:
add ebx, 0x4
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
lea edi, [ecx+0xa]
mov cx, [edx+0x6]
mov ebp, edi
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_10004360
CALL loc_10004360
mov dx, 0x4
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
mov [ecx+0x4], ax
;add esp, 0x8
add r11d, 0x8
loc_100098AC:
mov ax, [ebx+0x2]
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov [ebp], ax
add ebx, 0x6
mov word [ebp+0x2], 0x0
mov word [ebp+0x4], 0x0
movsx eax, word [ebp]
movsx ecx, word [ecx+0x4]
imul eax, ecx
sar eax, 0xb
add ebp, 0xe
dec dx
mov [ebp-0x8], ax
mov word [ebp-0x6], 0x0
mov cx, [ebx-0x2]
mov [ebp-0x4], cx
mov word [ebp-0x2], 0x0
jnz short loc_100098AC
mov ax, 0x4
add esi, 0x302
mov word [esi-0x2], 0x9
loc_10009904:
mov byte [esi], 0x0
add esi, 0x8
lea ecx, [edi+0xa]
nop
mov [esi-0x4], edi
add esi, 0x8
add edi, 0xe
mov byte [esi-0x8], 0x1
dec ax
mov [esi-0x4], ecx
jnz short loc_10009904
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
mov byte [esi], 0x0
;pop ebp
POP32 ebp
mov [esi+0x4], ecx
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_10009940:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
movsx ecx, byte [edx+0x4]
mov ax, [eax+ecx*2+0x464]
mov [edx+0x394], ax
;ret
RET
align 16
loc_10009960:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
movsx ecx, word [eax+0x2f8]
lea esi, [eax+0x39a]
;push edi
PUSH32 edi
lea edx, [eax+0x390]
xor edi, edi
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
mov di, [eax+ecx*2+0x10682]
xor eax, eax
mov ax, [edx+0x4]
imul edi, eax
xor cx, cx
shr edi, 0xf
cmp [edx+0x8], cx
jle short loc_100099B8
movsx eax, di
loc_1000999F:
inc cx
add esi, 0xe
movsx edi, word [esi-0xe]
imul edi, eax
sar edi, 0xb
mov [esi-0x8], di
cmp [edx+0x8], cx
jg short loc_1000999F
loc_100099B8:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_100099C0:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;sub esp, 0x8
sub r11d, 0x8
add edx, 0x390
;push ebx
PUSH32 ebx
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;push esi
;push edi
;push ebp
PUSH32 esi, edi, ebp
mov ecx, [eax+0x24086]
mov eax, [eax+0x24082]
test eax, eax
jle near loc_10009B72
;mov di, [esp+0x12]
mov di, [r11d+0x12]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
loc_100099F2:
movsx eax, word [edx]
cmp eax, 0x7
ja near loc_10009B00
;jmp dword [eax*4+loc_10009BB4]
mov r9d, [eax*4+loc_10009BB4]
jmp r9
loc_10009A05:
movsx eax, word [edx+0x6]
movsx esi, word [edx+0x20]
imul eax, esi
sar eax, 0xf
mov [edx+0x1c], ax
mov bx, [edx+0x24]
mov [edx+0xe], bx
jmp loc_10009AFC
loc_10009A24:
movsx eax, word [edx+0x6]
movsx esi, word [edx+0x20]
imul eax, esi
sar eax, 0xf
mov [edx+0x1c], ax
mov word [edx+0xe], 0x0
mov di, [edx+0x16]
add di, [edx+0x24]
jmp loc_10009B00
loc_10009A49:
movsx eax, word [edx+0x6]
movsx esi, word [edx+0x2e]
imul eax, esi
sar eax, 0xf
mov [edx+0x2a], ax
mov bx, [edx+0x32]
mov [edx+0x1c], bx
mov bp, [edx+0x24]
mov [edx+0xe], bp
jmp loc_10009AFC
loc_10009A70:
movsx eax, word [edx+0x6]
movsx esi, word [edx+0x2e]
imul eax, esi
sar eax, 0xf
mov [edx+0x2a], ax
mov word [edx+0x1c], 0x0
mov ax, [edx+0x24]
add ax, [edx+0x32]
jmp short loc_10009AF8
loc_10009A92:
movsx eax, word [edx+0x6]
movsx esi, word [edx+0x12]
imul eax, esi
sar eax, 0xf
mov [edx+0x2a], ax
mov bx, [edx+0x32]
mov [edx+0x1c], bx
mov bx, [edx+0x32]
mov [edx+0xe], bx
mov di, [edx+0x16]
add di, [edx+0x24]
jmp short loc_10009B00
loc_10009ABE:
movsx eax, word [edx+0x6]
movsx esi, word [edx+0x2e]
imul eax, esi
sar eax, 0xf
mov [edx+0x2a], ax
mov word [edx+0x1c], 0x0
mov word [edx+0xe], 0x0
mov di, [edx+0x16]
add di, [edx+0x32]
add di, [edx+0x24]
jmp short loc_10009B00
loc_10009AEA:
movsx eax, word [edx+0x6]
movsx esi, word [edx+0x12]
imul eax, esi
sar eax, 0xf
loc_10009AF8:
mov [edx+0xe], ax
loc_10009AFC:
mov di, [edx+0x16]
loc_10009B00:
lea eax, [edx+0xa]
mov ebx, eax
xor ax, ax
cmp [edx+0x8], ax
jle short loc_10009B62
loc_10009B0E:
mov si, [ebx+0x6]
add si, [ebx+0x2]
mov [ebx+0x2], si
mov bp, [ebx+0x4]
add bp, si
mov [ebx+0x4], bp
jns short loc_10009B2F
lea esi, [ebp+0x7fff]
jmp short loc_10009B36
loc_10009B2F:
mov si, 0x7fff
sub si, bp
loc_10009B36:
inc ax
add ebx, 0xe
movsx esi, si
movsx ebp, bp
imul esi, ebp
sar esi, 0xd
mov [ebx-0x6], si
movsx ebp, word [ebx-0x4]
movsx esi, si
imul ebp, esi
sar ebp, 0xf
mov [ebx-0x2], bp
cmp [edx+0x8], ax
jg short loc_10009B0E
loc_10009B62:
mov [ecx], di
add ecx, 0x2
;dec dword [esp+0x14]
dec dword [r11d+0x14]
jnz near loc_100099F2
loc_10009B72:
xor cx, cx
lea esi, [edx+0xa]
mov ax, [edx+0x8]
xor ebx, ebx
cmp ax, cx
jle short loc_10009B9F
xor edi, edi
loc_10009B85:
cmp [esi+0xa], di
jg short loc_10009B95
mov bp, 0x1
shl bp, cl
or bx, bp
loc_10009B95:
inc cx
add esi, 0xe
cmp cx, ax
jl short loc_10009B85
loc_10009B9F:
mov ax, [edx+0x2]
;pop ebp
POP32 ebp
and bx, ax
;pop edi
POP32 edi
cmp bx, ax
;pop esi
POP32 esi
setz al
;pop ebx
POP32 ebx
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 4
loc_10009BB4:
dd loc_10009AEA
dd loc_10009A05
dd loc_10009A24
dd loc_10009A49
dd loc_10009A70
dd loc_10009A92
dd loc_10009ABE
dd loc_10009AEA
align 16
loc_10009BE0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x10]
mov ebx, [r11d+0x10]
;push edi
;push ebp
PUSH32 edi, ebp
lea edi, [ebx+0x390]
lea esi, [ebx+0xc]
mov eax, [ebx+0x8]
mov ecx, [eax+0x4]
lea ebp, [ecx+eax-0xe]
mov [ebx+0x38c], ebp
mov ax, [ebp]
mov [edi], ax
mov word [edi+0x2], 0x1
mov cx, [ebp+0x2]
mov [edi+0x4], cx
lea ecx, [edi+0xe]
mov word [edi+0x6], 0x0
mov dx, [ebp+0x4]
;push ecx
PUSH32 ecx
mov [edi+0x8], dx
mov ax, [ebp+0x6]
mov [edi+0xc], ax
;call loc_1000BFF0
CALL loc_1000BFF0
movsx ecx, byte [ebx+0x4]
;mov ebx, [esp+0x18]
mov ebx, [r11d+0x18]
;add esp, 0x4
add r11d, 0x4
mov ax, [ebx+ecx*2+0x564]
lea ecx, [edi+0xfb6]
mov [edi+0xa], ax
;push ecx
PUSH32 ecx
mov [edi+0x10], ax
;call loc_1000BFF0
CALL loc_1000BFF0
movsx eax, word [edi+0xc]
movsx ecx, word [edi+0x10]
imul eax, ecx
sar eax, 0xd
;add esp, 0x4
add r11d, 0x4
mov [edi+0xfb8], ax
mov cx, [ebp+0x8]
mov [edi+0x1f5e], cx
mov word [edi+0x1f60], 0x0
mov dx, [ebp+0xa]
mov [edi+0x1f62], dx
lea edx, [edi+0xe]
mov ax, [ebp+0xc]
mov [edi+0x1f64], ax
mov word [edi+0x1f66], 0x0
mov cx, [edi+0x1f5e]
;push ecx
;push edx
;push ebx
PUSH32 ecx, edx, ebx
;call loc_1000C010
CALL loc_1000C010
mov cx, [edi+0x1f5e]
;add esp, 0xc
add r11d, 0xc
lea edx, [edi+0xfb6]
;push ecx
;push edx
;push ebx
PUSH32 ecx, edx, ebx
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
add esi, 0x302
lea eax, [edi+0x4]
mov word [esi-0x2], 0x7
mov byte [esi], 0x1
add esi, 0x8
add esi, 0x8
lea ecx, [edi+0x8]
mov [esi-0xc], edi
mov byte [esi-0x8], 0x0
add esi, 0x8
mov [esi-0xc], eax
mov byte [esi-0x8], 0x1
add esi, 0x8
lea eax, [edi+0xc]
mov [esi-0xc], ecx
mov byte [esi-0x8], 0x0
add esi, 0x8
lea ecx, [edi+0x1f5e]
mov [esi-0xc], eax
add esi, 0x8
lea eax, [edi+0x1f62]
add edi, 0x1f64
;pop ebp
POP32 ebp
mov byte [esi-0x10], 0x0
mov [esi-0xc], ecx
mov byte [esi-0x8], 0x0
mov [esi-0x4], eax
mov byte [esi], 0x0
mov [esi+0x4], edi
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10009D50:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
movsx ecx, byte [edx+0x4]
mov ax, [eax+ecx*2+0x564]
mov [edx+0x39a], ax
;ret
RET
align 16
loc_10009D70:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
;push edi
PUSH32 edi
lea edi, [eax+0x390]
mov ecx, esi
movsx eax, word [eax+0x2f8]
add eax, eax
sub ecx, eax
xor eax, eax
mov ax, [ecx+0x10682]
xor ecx, ecx
mov cx, [edi+0xa]
lea edx, [edi+0xe]
imul eax, ecx
shr eax, 0xf
mov [edi+0x10], ax
mov cx, [edi+0x1f5e]
;push ecx
;push edx
;push esi
PUSH32 ecx, edx, esi
;call loc_1000C010
CALL loc_1000C010
movsx ecx, word [edi+0xc]
movsx edx, word [edi+0x10]
imul ecx, edx
sar ecx, 0xd
;add esp, 0xc
add r11d, 0xc
mov [edi+0xfb8], cx
add edi, 0xfb6
mov ax, [edi+0xfa8]
;push eax
;push edi
;push esi
PUSH32 eax, edi, esi
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10009DF0:
;sub esp, 0x8
sub r11d, 0x8
;mov byte [esp+0x3], 0x0
mov byte [r11d+0x3], 0x0
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
;push edi
PUSH32 edi
mov ax, [esi+0x22ee]
;push ebp
PUSH32 ebp
lea ecx, [esi+0x39e]
add esi, 0x390
;mov ebx, [esp+0x1c]
mov ebx, [r11d+0x1c]
;push eax
;push ecx
;push ebx
PUSH32 eax, ecx, ebx
;call loc_1000C010
CALL loc_1000C010
mov cx, [esi+0x1f5e]
;add esp, 0xc
add r11d, 0xc
lea eax, [esi+0xfb6]
;push ecx
;push eax
;push ebx
PUSH32 ecx, eax, ebx
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
mov edi, [ebx+0x24086]
mov ebx, [ebx+0x24082]
test ebx, ebx
jle near loc_10009FDE
loc_10009E4E:
mov cx, [esi+0x2]
test ch, 0x80
lea eax, [ecx*2]
jz short loc_10009E62
xor ax, 0x1d87
loc_10009E62:
mov [esi+0x2], ax
mov dx, [esi+0x6]
movsx ebp, word [esi+0x4]
mov ax, [esi+0x2]
sar ax, 0x1
mov cx, dx
sar cx, 0x1
sub ax, cx
movsx ecx, ax
imul ecx, ebp
sar ecx, 0xe
add cx, dx
mov [esi+0x6], cx
movsx eax, cx
movsx ebp, word [esi+0x8]
mov dx, [esi]
imul ebp, eax
sar ebp, 0xf
movsx ecx, dx
movsx eax, bp
imul eax, ecx
sar eax, 0xf
;push eax
;push edx
PUSH32 eax, edx
;call loc_10006290
CALL loc_10006290
;mov [esp+0x1c], ax
mov [r11d+0x1c], ax
;add esp, 0x8
add r11d, 0x8
lea ecx, [esi+0xe]
;push ecx
PUSH32 ecx
;call loc_1000C080
CALL loc_1000C080
mov bp, ax
;add esp, 0x4
add r11d, 0x4
lea ecx, [esi+0xfb6]
;push ecx
PUSH32 ecx
;call loc_1000C080
CALL loc_1000C080
movsx ebp, bp
;mov [esp+0x1a], ax
mov [r11d+0x1a], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [esi+0x1f62]
imul ecx, ebp
sar ecx, 0xf
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_10006290
CALL loc_10006290
;add esp, 0x8
add r11d, 0x8
lea ecx, [esi+0xfb6]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000C0D0
CALL loc_1000C0D0
;movsx ecx, word [esp+0x1e]
movsx ecx, word [r11d+0x1e]
;add esp, 0x8
add r11d, 0x8
mov eax, ecx
imul eax, ecx
sar eax, 0xf
movsx eax, ax
imul eax, ecx
sar eax, 0xf
;mov ecx, [esp+0x16]
mov ecx, [r11d+0x16]
;push eax
;push ecx
PUSH32 eax, ecx
add edi, 0x2
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x1f64]
imul ecx, ebp
sar ecx, 0xf
;add esp, 0x8
add r11d, 0x8
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_100062B0
CALL loc_100062B0
mov cx, [esi+0x1f60]
;add esp, 0x8
add r11d, 0x8
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_100062B0
CALL loc_100062B0
movsx ecx, word [esi+0x1f5e]
movsx edx, ax
imul ecx, edx
mov ax, [esi+0x1f60]
;add esp, 0x8
add r11d, 0x8
sar ecx, 0xf
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_10006290
CALL loc_10006290
mov [esi+0x1f60], ax
;add esp, 0x8
add r11d, 0x8
lea ecx, [esi+0xe]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000C0D0
CALL loc_1000C0D0
mov cx, [esi+0x1f60]
;add esp, 0x8
add r11d, 0x8
mov [edi-0x2], cx
mov cx, [esi+0x1f60]
;push ecx
PUSH32 ecx
;call loc_10006280
CALL loc_10006280
;add esp, 0x4
add r11d, 0x4
cmp ax, 0x80
jge short loc_10009FCE
mov ax, [esi+0x1f66]
inc ax
mov [esi+0x1f66], ax
cmp ax, 0x100
jl short loc_10009FD7
;mov byte [esp+0x13], 0x1
mov byte [r11d+0x13], 0x1
jmp short loc_10009FD7
loc_10009FCE:
mov word [esi+0x1f66], 0x0
loc_10009FD7:
dec ebx
jnz near loc_10009E4E
loc_10009FDE:
;mov al, [esp+0x13]
mov al, [r11d+0x13]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_10009FF0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
;push ebp
PUSH32 edi, ebp
lea ebx, [esi+0x390]
lea edi, [esi+0xc]
mov eax, [esi+0x8]
mov ecx, [eax+0x4]
lea ebp, [ecx+eax-0xe]
mov [esi+0x38c], ebp
mov ax, [ebp]
mov [ebx], ax
mov word [ebx+0x2], 0x1
mov cx, [ebp+0x2]
mov [ebx+0x4], cx
mov word [ebx+0x6], 0x0
mov dx, [ebp+0x4]
mov [ebx+0x8], dx
lea edx, [ebx+0x10]
mov ax, [ebp+0x6]
;push edx
PUSH32 edx
mov [ebx+0xa], ax
mov cx, [ebp+0x8]
mov [ebx+0xc], cx
;call loc_1000BFF0
CALL loc_1000BFF0
movsx edx, byte [esi+0x4]
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;add esp, 0x4
add r11d, 0x4
mov ax, [ecx+edx*2+0x564]
lea esi, [ebx+0xfbc]
mov [ebx+0xe], ax
mov [ebx+0x12], ax
mov dx, [ebp+0xa]
mov [ebx+0xfb8], dx
mov word [ebx+0xfba], 0x0
mov ax, [ebp+0xc]
lea ebp, [ebx+0x10]
mov [esi], ax
mov word [ebx+0xfbe], 0x0
mov dx, [ebx+0xfb8]
add edi, 0x302
;push edx
;push ebp
;push ecx
PUSH32 edx, ebp, ecx
add edi, 0x8
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
lea eax, [ebx+0x4]
mov word [edi-0xa], 0x7
add edi, 0x8
lea ecx, [ebx+0x8]
mov byte [edi-0x10], 0x1
mov [edi-0xc], ebx
mov byte [edi-0x8], 0x0
mov [edi-0x4], eax
mov byte [edi], 0x1
mov [edi+0x4], ecx
mov byte [edi+0x8], 0x0
add edi, 0x8
lea eax, [ebx+0xa]
mov [edi+0x4], eax
add edi, 0x8
lea ecx, [ebx+0xc]
add edi, 0x8
add ebx, 0xfb8
add edi, 0x8
;pop ebp
POP32 ebp
mov byte [edi-0x10], 0x0
mov [edi-0xc], ecx
mov byte [edi-0x8], 0x0
mov [edi-0x4], ebx
mov byte [edi], 0x0
mov [edi+0x4], esi
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_1000A110:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
movsx ecx, byte [edx+0x4]
mov ax, [eax+ecx*2+0x564]
mov [edx+0x39e], ax
;ret
RET
align 16
loc_1000A130:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
lea esi, [eax+0x390]
movsx eax, word [eax+0x2f8]
mov ecx, edx
add eax, eax
sub ecx, eax
xor eax, eax
mov ax, [ecx+0x10682]
xor ecx, ecx
mov cx, [esi+0xe]
add esi, 0x10
imul eax, ecx
shr eax, 0xf
mov [esi+0x2], ax
mov cx, [esi+0xfa8]
;push ecx
;push esi
;push edx
PUSH32 ecx, esi, edx
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
;pop esi
POP32 esi
;ret
RET
align 16
loc_1000A180:
;sub esp, 0x8
sub r11d, 0x8
;mov byte [esp+0x3], 0x0
mov byte [r11d+0x3], 0x0
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
;push edi
PUSH32 edi
mov ax, [esi+0x1348]
;push ebp
PUSH32 ebp
lea ecx, [esi+0x3a0]
add esi, 0x390
;mov ebx, [esp+0x1c]
mov ebx, [r11d+0x1c]
;push eax
;push ecx
;push ebx
PUSH32 eax, ecx, ebx
;call loc_1000C010
CALL loc_1000C010
;add esp, 0xc
add r11d, 0xc
mov edi, [ebx+0x24086]
mov eax, [ebx+0x24082]
test eax, eax
jle near loc_1000A310
;mov [esp+0x14], eax
mov [r11d+0x14], eax
loc_1000A1CA:
mov ax, [esi+0x2]
test ah, 0x80
lea ecx, [eax*2]
jz short loc_1000A1DF
xor cx, 0x1d87
loc_1000A1DF:
mov [esi+0x2], cx
mov dx, [esi+0x6]
mov ax, [esi+0x2]
sar ax, 0x1
mov cx, dx
sar cx, 0x1
sub ax, cx
movsx eax, ax
movsx ecx, word [esi+0x4]
imul eax, ecx
sar eax, 0xe
add ax, dx
mov [esi+0x6], ax
movsx edx, word [esi+0x8]
movsx eax, ax
imul edx, eax
sar edx, 0xf
movsx ecx, word [esi]
movsx eax, dx
imul eax, ecx
sar eax, 0xf
movsx ebx, ax
add ebx, ecx
lea eax, [esi+0x10]
sar ebx, 0x1
;push eax
PUSH32 eax
;call loc_1000C080
CALL loc_1000C080
mov dx, [esi+0xfba]
;add esp, 0x4
add r11d, 0x4
sar ax, 0x1
mov cx, dx
sar cx, 0x1
sub ax, cx
movsx ebp, ax
movsx ecx, word [esi+0xfb8]
imul ebp, ecx
sar ebp, 0xe
add bp, dx
mov dx, 0x7fff
movsx eax, bp
mov [esi+0xfba], bp
movsx ecx, word [esi+0xfbc]
imul ecx, eax
mov ax, [esi+0xa]
sar ecx, 0xf
add cx, bx
neg cx
cmp cx, ax
jl short loc_1000A2A7
mov bp, cx
sub bp, ax
movsx eax, bp
movsx ebp, word [esi+0xc]
imul eax, ebp
sar eax, 0xd
sub dx, ax
jns short loc_1000A2A7
xor dx, dx
loc_1000A2A7:
movsx ebp, dx
movsx eax, cx
imul ebp, eax
sar ebp, 0xf
lea eax, [esi+0x10]
add bp, bx
add edi, 0x2
;push ebp
;push eax
PUSH32 ebp, eax
;call loc_1000C0D0
CALL loc_1000C0D0
mov ax, [esi+0xfba]
;add esp, 0x8
add r11d, 0x8
mov [edi-0x2], ax
;push ebp
PUSH32 ebp
;call loc_10006280
CALL loc_10006280
;add esp, 0x4
add r11d, 0x4
cmp ax, 0x80
jge short loc_1000A2FD
mov ax, [esi+0xfbe]
inc ax
mov [esi+0xfbe], ax
cmp ax, 0x100
jl short loc_1000A306
;mov byte [esp+0x13], 0x1
mov byte [r11d+0x13], 0x1
jmp short loc_1000A306
loc_1000A2FD:
mov word [esi+0xfbe], 0x0
loc_1000A306:
;dec dword [esp+0x14]
dec dword [r11d+0x14]
jnz near loc_1000A1CA
loc_1000A310:
;mov al, [esp+0x13]
mov al, [r11d+0x13]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_1000A320:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;sub esp, 0x8
sub r11d, 0x8
;push ebx
PUSH32 ebx
lea ecx, [edx+0x390]
;push esi
PUSH32 esi
lea ebx, [edx+0xc]
;push edi
PUSH32 edi
mov eax, [edx+0x8]
;mov [esp+0xc], ecx
mov [r11d+0xc], ecx
;push ebp
PUSH32 ebp
mov ecx, [eax+0x4]
lea ebp, [ecx+eax-0x20]
mov eax, ebp
;mov [esp+0x14], ebp
mov [r11d+0x14], ebp
mov [edx+0x38c], ebp
lea esi, [eax+0x2]
mov ax, [edx+0x6]
;mov ebp, [esp+0x10]
mov ebp, [r11d+0x10]
add ebp, 0x2
;push eax
PUSH32 eax
mov edi, ebp
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;push ecx
PUSH32 ecx
;call loc_10004360
CALL loc_10004360
mov dx, 0x3
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
mov [ecx], ax
;add esp, 0x8
add r11d, 0x8
loc_1000A377:
mov al, [esi]
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov [edi], al
add esi, 0x8
mov word [edi+0x4], 0x1
mov ax, [esi-0x4]
add edi, 0xe
mov [edi-0xc], ax
movsx ecx, word [ecx]
movsx eax, ax
imul ecx, eax
sar ecx, 0xd
dec dx
mov [edi-0x8], cx
mov word [edi-0x6], 0x0
mov ax, [esi-0x6]
mov [edi-0x4], ax
mov cx, [esi-0x2]
mov [edi-0x2], cx
jnz short loc_1000A377
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
mov al, [eax+0x1a]
mov [ecx+0x2c], al
mov al, [edx+0x1b]
lea edx, [ecx+0x2e]
lea esi, [ecx+0x30]
mov [ecx+0x2d], al
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
mov ax, [eax+0x1c]
mov [edx], ax
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
mov ax, [eax+0x1e]
mov [esi], ax
xor ax, ax
loc_1000A3F4:
movsx edi, ax
inc ax
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov word [ecx+edi*2+0x32], 0x0
cmp ax, 0x4
jl short loc_1000A3F4
mov cx, 0x3
add ebx, 0x302
mov word [ebx-0x2], 0xb
loc_1000A41A:
lea eax, [ebp+0x2]
lea edi, [ebp+0xa]
mov byte [ebx], 0x0
add ebx, 0x8
add ebx, 0x8
add ebp, 0xe
add ebx, 0x8
dec cx
mov [ebx-0x14], eax
mov byte [ebx-0x10], 0x0
lea eax, [ebp-0x2]
mov [ebx-0xc], edi
mov byte [ebx-0x8], 0x1
mov [ebx-0x4], eax
jnz short loc_1000A41A
mov byte [ebx], 0x0
add ebx, 0x8
;pop ebp
;pop edi
POP32 edi, ebp
mov [ebx-0x4], edx
mov byte [ebx], 0x0
mov [ebx+0x4], esi
;pop esi
;pop ebx
POP32 ebx, esi
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_1000A460:
;mov edx, [esp+0x8]
mov edx, [r11d+0x8]
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
movsx ecx, byte [edx+0x4]
mov ax, [eax+ecx*2+0x464]
mov [edx+0x390], ax
;ret
RET
align 16
loc_1000A480:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
;push edi
PUSH32 esi, edi
xor esi, esi
lea edx, [eax+0x392]
lea edi, [eax+0x390]
movsx ecx, word [eax+0x2f8]
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
mov si, [eax+ecx*2+0x10682]
xor eax, eax
mov ax, [edi]
imul esi, eax
mov ax, 0x3
shr esi, 0xf
movsx ecx, si
loc_1000A4B9:
movsx esi, word [edx+0x2]
imul esi, ecx
sar esi, 0xd
add edx, 0xe
dec ax
mov [edx-0x8], si
jnz short loc_1000A4B9
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_1000A4E0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;sub esp, 0x1c
sub r11d, 0x1c
;push ebx
PUSH32 ebx
mov ecx, [eax+0x38c]
;mov [esp+0x10], ecx
mov [r11d+0x10], ecx
;push esi
PUSH32 esi
mov cx, 0x3
;push edi
PUSH32 edi
lea edi, [eax+0x392]
;push ebp
PUSH32 ebp
lea esi, [eax+0x390]
loc_1000A505:
cmp byte [edi], 0x0
jz short loc_1000A52D
mov dx, [edi+0x8]
;mov ebp, [esp+0x1c]
mov ebp, [r11d+0x1c]
mov ax, [edi+0x6]
sub ax, dx
movsx ebx, ax
movsx eax, word [ebp]
imul ebx, eax
sar ebx, 0xf
add bx, dx
mov [edi+0x8], bx
loc_1000A52D:
add edi, 0xe
dec cx
jnz short loc_1000A505
mov ax, 0x7fff
sub ax, [esi]
movsx ecx, ax
;mov [esp+0x14], ax
mov [r11d+0x14], ax
;mov [esp+0x18], ecx
mov [r11d+0x18], ecx
mov eax, 0x1fffc000
cdq
idiv ecx
;mov [esp+0x12], ax
mov [r11d+0x12], ax
mov ecx, 0x7fff
;sub ecx, [esp+0x18]
sub ecx, [r11d+0x18]
mov eax, 0x3fff80
cdq
idiv ecx
;mov [esp+0x16], ax
mov [r11d+0x16], ax
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
mov edx, [eax+0x24086]
mov eax, [eax+0x24082]
;mov [esp+0x20], edx
mov [r11d+0x20], edx
test eax, eax
jle near loc_1000A8DB
;mov [esp+0x28], eax
mov [r11d+0x28], eax
loc_1000A58A:
xor di, di
;mov ebx, [esp+0x1c]
mov ebx, [r11d+0x1c]
add ebx, 0x2
lea ebp, [esi+0x2]
;mov word [esp+0x24], 0x3
mov word [r11d+0x24], 0x3
loc_1000A59E:
cmp byte [ebp], 0x0
jz near loc_1000A6F2
cmp byte [ebx+0x1], 0x3
jge short loc_1000A5B6
mov ax, [ebp+0x8]
add [ebp+0x4], ax
loc_1000A5B6:
movsx eax, byte [ebx+0x1]
cmp eax, 0x3
ja near loc_1000A6F2
;jmp dword [eax*4+loc_1000A8F4]
mov r9d, [eax*4+loc_1000A8F4]
jmp r9
loc_1000A5CA:
mov ax, [ebp+0x4]
test ax, ax
jle short loc_1000A5DC
lea eax, [eax*2+0x8000]
jmp short loc_1000A5F6
loc_1000A5DC:
cmp ax, 0x8000
jnz short loc_1000A5E8
mov ax, 0x7fff
jmp short loc_1000A5F6
loc_1000A5E8:
mov cx, 0xc000
sub cx, ax
lea eax, [ecx*2]
loc_1000A5F6:
movsx ecx, word [ebp+0xc]
movsx eax, ax
jmp loc_1000A6E9
loc_1000A602:
mov ax, [ebp+0x4]
;mov edx, [esp+0x18]
mov edx, [r11d+0x18]
neg edx
movsx ecx, ax
cmp edx, ecx
jle short loc_1000A627
mov edx, 0xffff8000
sub edx, ecx
;movsx eax, word [esp+0x16]
movsx eax, word [r11d+0x16]
imul eax, edx
sar eax, 0x7
jmp short loc_1000A64D
loc_1000A627:
;cmp [esp+0x14], ax
cmp [r11d+0x14], ax
jge short loc_1000A642
mov edx, 0x7fff
sub edx, ecx
;movsx eax, word [esp+0x16]
movsx eax, word [r11d+0x16]
imul eax, edx
sar eax, 0x7
jmp short loc_1000A64D
loc_1000A642:
;movsx eax, word [esp+0x12]
movsx eax, word [r11d+0x12]
imul eax, ecx
sar eax, 0xe
loc_1000A64D:
movsx ecx, word [ebp+0xc]
movsx eax, ax
jmp loc_1000A6E9
loc_1000A659:
mov ax, [ebp+0x4]
;mov edx, [esp+0x18]
mov edx, [r11d+0x18]
neg edx
movsx ecx, ax
cmp edx, ecx
jle short loc_1000A67E
mov edx, 0xffff8000
sub edx, ecx
;movsx eax, word [esp+0x16]
movsx eax, word [r11d+0x16]
imul eax, edx
sar eax, 0x7
jmp short loc_1000A6BF
loc_1000A67E:
;cmp [esp+0x14], ax
cmp [r11d+0x14], ax
jge short loc_1000A699
mov edx, 0x7fff
sub edx, ecx
;movsx eax, word [esp+0x16]
movsx eax, word [r11d+0x16]
imul eax, edx
sar eax, 0x7
jmp short loc_1000A6BF
loc_1000A699:
movsx eax, word [ebp+0xa]
sub ecx, eax
;push ecx
PUSH32 ecx
;call loc_10006390
CALL loc_10006390
;movsx ecx, word [esp+0x1a]
movsx ecx, word [r11d+0x1a]
movsx edx, ax
imul ecx, edx
sar ecx, 0x7
;add esp, 0x4
add r11d, 0x4
;push ecx
PUSH32 ecx
;call loc_10006390
CALL loc_10006390
;add esp, 0x4
add r11d, 0x4
loc_1000A6BF:
movsx ecx, word [ebp+0xc]
movsx eax, ax
jmp short loc_1000A6E9
loc_1000A6C8:
mov ax, [ebp+0x4]
test ah, 0x80
lea ecx, [eax*2]
jz short loc_1000A6DD
xor cx, 0x1d87
loc_1000A6DD:
mov [ebp+0x4], cx
movsx ecx, word [ebp+0xc]
movsx eax, word [ebp+0x4]
loc_1000A6E9:
imul ecx, eax
sar ecx, 0xf
add di, cx
loc_1000A6F2:
add ebx, 0x8
add ebp, 0xe
;dec word [esp+0x24]
dec word [r11d+0x24]
jnz near loc_1000A59E
cmp byte [esi+0x2c], 0x0
jz near loc_1000A8C5
movsx eax, byte [esi+0x2d]
cmp eax, 0x3
ja near loc_1000A8C5
;jmp dword [eax*4+loc_1000A904]
mov r9d, [eax*4+loc_1000A904]
jmp r9
loc_1000A721:
mov ax, [esi+0x32]
movsx ecx, word [esi+0x2e]
sub di, ax
movsx edi, di
imul edi, ecx
sar edi, 0xf
add di, ax
mov [esi+0x32], di
jmp loc_1000A8C5
loc_1000A741:
mov cx, [esi+0x32]
movsx eax, word [esi+0x2e]
sub di, cx
movsx edx, di
imul edx, eax
sar edx, 0xf
add dx, cx
mov [esi+0x32], dx
mov ax, [esi+0x34]
movsx ecx, word [esi+0x2e]
sub dx, ax
movsx edi, dx
imul edi, ecx
sar edi, 0xf
add di, ax
mov [esi+0x34], di
jmp loc_1000A8C5
loc_1000A77C:
mov cx, [esi+0x32]
movsx eax, word [esi+0x2e]
sub di, cx
movsx edx, di
imul edx, eax
sar edx, 0xf
add dx, cx
mov [esi+0x32], dx
mov cx, [esi+0x34]
movsx ebx, word [esi+0x2e]
sub dx, cx
movsx eax, dx
imul eax, ebx
sar eax, 0xf
add ax, cx
mov [esi+0x34], ax
mov dx, [esi+0x36]
movsx ecx, word [esi+0x2e]
sub ax, dx
movsx eax, ax
imul eax, ecx
sar eax, 0xf
add ax, dx
mov [esi+0x36], ax
mov cx, [esi+0x38]
movsx edx, word [esi+0x2e]
sub ax, cx
movsx edi, ax
imul edi, edx
sar edi, 0xf
add di, cx
jmp loc_1000A8C1
loc_1000A7E9:
movsx ecx, word [esi+0x30]
movsx eax, word [esi+0x38]
imul ecx, eax
movsx eax, di
sar ecx, 0xd
sub eax, ecx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov dx, [esi+0x2e]
;add esp, 0x4
add r11d, 0x4
mov cx, 0x7fff
movsx eax, ax
sub cx, dx
movsx edi, cx
movsx ecx, dx
imul eax, ecx
sar eax, 0xf
movsx ecx, ax
movsx eax, word [esi+0x32]
imul eax, edi
sar eax, 0xf
movsx eax, ax
add eax, ecx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov [esi+0x32], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [esi+0x2e]
movsx edx, ax
imul ecx, edx
movsx eax, word [esi+0x34]
sar ecx, 0xf
imul eax, edi
sar eax, 0xf
movsx edx, cx
movsx eax, ax
add eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov [esi+0x34], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [esi+0x2e]
movsx edx, ax
imul ecx, edx
movsx eax, word [esi+0x36]
sar ecx, 0xf
imul eax, edi
sar eax, 0xf
movsx edx, cx
movsx eax, ax
add eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov [esi+0x36], ax
;add esp, 0x4
add r11d, 0x4
movsx ecx, word [esi+0x2e]
movsx edx, ax
imul ecx, edx
sar ecx, 0xf
movsx edx, cx
movsx eax, word [esi+0x38]
imul eax, edi
sar eax, 0xf
movsx eax, ax
add eax, edx
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
mov di, ax
;add esp, 0x4
add r11d, 0x4
loc_1000A8C1:
mov [esi+0x38], di
loc_1000A8C5:
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;add dword [esp+0x20], 0x2
add dword [r11d+0x20], 0x2
mov [ecx], di
;dec dword [esp+0x28]
dec dword [r11d+0x28]
jnz near loc_1000A58A
loc_1000A8DB:
;mov eax, [esp+0x34]
mov eax, [r11d+0x34]
;pop ebp
POP32 ebp
cmp word [eax+0x304], 0x0
setle al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x1c
add r11d, 0x1c
;ret
RET
db 139
db 255
align 4
loc_1000A8F4:
dd loc_1000A5CA
dd loc_1000A602
dd loc_1000A659
dd loc_1000A6C8
align 4
loc_1000A904:
dd loc_1000A721
dd loc_1000A741
dd loc_1000A77C
dd loc_1000A7E9
align 4
loc_1000BAB0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x28]
mov ebx, [r11d+0x28]
;push edi
PUSH32 edi
;push 0x34
PUSH32 0x34
mov edi, GlobalAlloc
;push 0x40
PUSH32 0x40
mov dword [ebx], 0x0
;call edi
mov r9d, edi
CALL r9
mov [ebx], eax
mov esi, eax
test esi, esi
jnz short loc_1000BADA
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000BADA:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
;mov edx, [esp+0x18]
mov edx, [r11d+0x18]
mov [esi], eax
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov [esi+0x4], ecx
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
mov [esi+0x8], edx
;mov bx, [esp+0x28]
mov bx, [r11d+0x28]
;mov edx, [esp+0x24]
mov edx, [r11d+0x24]
mov [esi+0xc], eax
mov dword [esi+0x30], 0x0
movsx eax, bx
shl eax, 0x2
mov [esi+0x10], ecx
mov [esi+0x14], edx
lea ecx, [eax+eax*8]
;push ecx
PUSH32 ecx
;push 0x40
PUSH32 0x40
;call edi
mov r9d, edi
CALL r9
mov [esi+0x30], eax
test eax, eax
jnz short loc_1000BB2D
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000BB2D:
mov [esi+0x2c], bx
;push esi
PUSH32 esi
;call loc_1000BEC0
CALL loc_1000BEC0
;add esp, 0x4
add r11d, 0x4
xor eax, eax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000BB40:
;push esi
;push edi
PUSH32 esi, edi
;mov edi, [esp+0xc]
mov edi, [r11d+0xc]
test edi, edi
jz near loc_1000BB69
mov eax, [edi+0x30]
test eax, eax
jz short loc_1000BB60
;push eax
PUSH32 eax
mov esi, GlobalFree
;call esi
mov r9d, esi
CALL r9
;push edi
PUSH32 edi
;call esi
mov r9d, esi
CALL r9
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_1000BB60:
mov esi, GlobalFree
;push edi
PUSH32 edi
;call esi
mov r9d, esi
CALL r9
loc_1000BB69:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_1000BB70:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x14]
mov ebx, [r11d+0x14]
;push edi
PUSH32 edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebp
PUSH32 ebp
;mov ebp, [esp+0x18]
mov ebp, [r11d+0x18]
;push ebx
;push ebp
;push esi
PUSH32 ebx, ebp, esi
;call loc_1000BE20
CALL loc_1000BE20
;add esp, 0xc
add r11d, 0xc
mov edi, eax
test edi, edi
jz short loc_1000BBA6
mov eax, [edi]
mov [ebx+0x8], eax
;call timeGetTime
CALL timeGetTime
;pop ebp
POP32 ebp
mov [edi+0x16], eax
mov eax, [edi]
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_1000BBA6:
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;push eax
;push ecx
PUSH32 eax, ecx
;push 0x1
PUSH32 0x1
;push ebx
;push ebp
;push esi
PUSH32 ebx, ebp, esi
;call loc_1000BBD0
CALL loc_1000BBD0
;add esp, 0x18
add r11d, 0x18
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_1000BBD0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
;push esi
PUSH32 edi, ebp, esi
;call loc_1000BF30
CALL loc_1000BF30
;mov ebx, [esp+0x20]
mov ebx, [r11d+0x20]
;add esp, 0x4
add r11d, 0x4
mov ebp, eax
mov ecx, [esi+0x4]
mov eax, [ebx+0x4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_100088D0
CALL loc_100088D0
;add esp, 0x8
add r11d, 0x8
mov [ebp], eax
test eax, eax
jnz short loc_1000BC0F
;push ebp
;push esi
PUSH32 ebp, esi
;call loc_1000BF90
CALL loc_1000BF90
;add esp, 0x8
add r11d, 0x8
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_1000BC0F:
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
lea ecx, [ebp+0x8]
mov [ebp+0x4], edi
mov eax, [ebx]
mov [ecx], eax
mov edx, [ebx+0x4]
mov [ecx+0x4], edx
mov eax, [ebx+0x8]
mov [ecx+0x8], eax
mov word [ebp+0x14], 0x0
;call timeGetTime
CALL timeGetTime
;mov cl, [esp+0x28]
mov cl, [r11d+0x28]
mov [ebp+0x16], eax
mov byte [ebp+0x1a], 0x0
;cmp byte [esp+0x20], 0x0
cmp byte [r11d+0x20], 0x0
mov [ebp+0x1b], cl
mov edx, [ebp]
mov [ebx+0x8], edx
jz short loc_1000BC66
mov eax, [ebp]
;mov ecx, [esp+0x24]
mov ecx, [r11d+0x24]
;push eax
PUSH32 eax
mov edx, [esi]
;push ecx
;push ebx
;push edi
;push edx
PUSH32 ecx, ebx, edi, edx
;call loc_10005EF0
CALL loc_10005EF0
;add esp, 0x14
add r11d, 0x14
loc_1000BC66:
mov eax, [ebp]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_1000BC70:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
PUSH32 edi
;mov ecx, [esp+0xc]
mov ecx, [r11d+0xc]
;push esi
;push eax
;push ecx
PUSH32 esi, eax, ecx
;call loc_1000BE20
CALL loc_1000BE20
;add esp, 0xc
add r11d, 0xc
mov edi, eax
test edi, edi
jz short loc_1000BCA2
mov eax, [edi]
mov [esi+0x8], eax
;call timeGetTime
CALL timeGetTime
mov [edi+0x16], eax
mov eax, [edi]
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_1000BCA2:
xor eax, eax
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_1000BCB0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BE60
CALL loc_1000BE60
;add esp, 0x8
add r11d, 0x8
mov esi, eax
test esi, esi
jnz short loc_1000BCCD
xor al, al
;pop esi
POP32 esi
;ret
RET
loc_1000BCCD:
;cmp byte [esp+0x10], 0x0
cmp byte [r11d+0x10], 0x0
jz short loc_1000BCE9
inc word [esi+0x14]
;call timeGetTime
CALL timeGetTime
mov [esi+0x16], eax
mov al, 0x1
mov byte [esi+0x1a], 0x0
;pop esi
POP32 esi
;ret
RET
loc_1000BCE9:
mov ax, [esi+0x14]
test ax, ax
jle short loc_1000BCFC
dec ax
mov [esi+0x14], ax
mov al, 0x1
;pop esi
POP32 esi
;ret
RET
loc_1000BCFC:
xor al, al
;pop esi
POP32 esi
;ret
RET
loc_1000BD00:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push 0x0
PUSH32 0x0
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
mov eax, [esi+0x4]
;push edi
;push eax
PUSH32 edi, eax
;call loc_10008A70
CALL loc_10008A70
;add esp, 0xc
add r11d, 0xc
mov eax, [esi+0x8]
test eax, eax
jz short loc_1000BD2A
;push edi
PUSH32 edi
mov ecx, [esi+0xc]
;push ecx
PUSH32 ecx
;call eax
mov r9d, eax
CALL r9
;add esp, 0x8
add r11d, 0x8
loc_1000BD2A:
;push edi
;push esi
PUSH32 edi, esi
;call loc_1000BE60
CALL loc_1000BE60
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_1000BD4F
;push eax
;push esi
PUSH32 eax, esi
;call loc_1000BF90
CALL loc_1000BF90
;add esp, 0x8
add r11d, 0x8
mov eax, [esi+0x4]
;push edi
;push eax
PUSH32 edi, eax
;call loc_10008930
CALL loc_10008930
;add esp, 0x8
add r11d, 0x8
loc_1000BD4F:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_1000BD60:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BE60
CALL loc_1000BE60
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_1000BD7D
;mov cl, [esp+0xc]
mov cl, [r11d+0xc]
mov [eax+0x1a], cl
loc_1000BD7D:
;ret
RET
align 16
loc_1000BD80:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
loc_1000BD8A:
;push edi
;push esi
PUSH32 edi, esi
;call loc_1000BDB0
CALL loc_1000BDB0
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_1000BDA4
;push eax
;push esi
PUSH32 eax, esi
;call loc_1000BD00
CALL loc_1000BD00
;add esp, 0x8
add r11d, 0x8
jmp short loc_1000BD8A
loc_1000BDA4:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_1000BDB0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BE80
CALL loc_1000BE80
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_1000BDC9
mov eax, [eax]
;ret
RET
loc_1000BDC9:
xor eax, eax
;ret
RET
align 16
loc_1000BDD0:
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
;push esi
PUSH32 esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
mov eax, [esi]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BE80
CALL loc_1000BE80
;add esp, 0x8
add r11d, 0x8
test eax, eax
jz short loc_1000BDF2
mov eax, [eax+0x16]
cmp [esi], eax
jbe short loc_1000BDF2
mov [esi], eax
loc_1000BDF2:
;pop esi
POP32 esi
;ret
RET
align 16
loc_1000BE00:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov eax, [eax+0x24]
test eax, eax
jz short loc_1000BE18
xor ecx, ecx
loc_1000BE0D:
mov [eax+0x14], cx
mov eax, [eax+0x20]
test eax, eax
jnz short loc_1000BE0D
loc_1000BE18:
;ret
RET
align 16
loc_1000BE20:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push ebx
;push esi
PUSH32 ebx, esi
mov eax, [eax+0x24]
test eax, eax
jz short loc_1000BE4F
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
xor ebx, ebx
loc_1000BE37:
cmp [eax+0x4], ecx
jnz short loc_1000BE48
mov esi, [edx]
cmp [eax+0x8], esi
jnz short loc_1000BE48
cmp [eax+0x1a], bl
jz short loc_1000BE51
loc_1000BE48:
mov eax, [eax+0x20]
test eax, eax
jnz short loc_1000BE37
loc_1000BE4F:
xor eax, eax
loc_1000BE51:
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_1000BE60:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov eax, [eax+0x24]
test eax, eax
jz short loc_1000BE7A
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
loc_1000BE6F:
cmp [eax], ecx
jz short loc_1000BE7C
mov eax, [eax+0x20]
test eax, eax
jnz short loc_1000BE6F
loc_1000BE7A:
xor eax, eax
loc_1000BE7C:
;ret
RET
align 16
loc_1000BE80:
;push ebx
PUSH32 ebx
xor eax, eax
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
;push esi
PUSH32 esi
mov esi, [ecx+0x24]
cmp esi, eax
jz short loc_1000BEB9
;mov edx, [esp+0x10]
mov edx, [r11d+0x10]
xor ebx, ebx
loc_1000BE95:
cmp [esi+0x14], bx
jnz short loc_1000BEB2
mov ecx, [esi+0x16]
cmp ecx, edx
jae short loc_1000BEB2
cmp [esi+0x1b], bl
jnz short loc_1000BEB2
test eax, eax
jz short loc_1000BEB0
cmp [eax+0x16], ecx
jbe short loc_1000BEB2
loc_1000BEB0:
mov eax, esi
loc_1000BEB2:
mov esi, [esi+0x20]
test esi, esi
jnz short loc_1000BE95
loc_1000BEB9:
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_1000BEC0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
PUSH32 edi, ebp
mov edi, [esi+0x30]
mov bp, [esi+0x2c]
mov [esi+0x1c], edi
movsx eax, bp
shl eax, 0x2
xor ebx, ebx
mov [esi+0x2e], bx
mov [esi+0x24], ebx
xor cx, cx
lea eax, [eax+eax*8]
add eax, edi
lea edx, [ebp-0x1]
sub eax, 0x24
mov [esi+0x28], ebx
test bp, bp
mov [esi+0x20], eax
jle short loc_1000BF25
loc_1000BEFA:
test cx, cx
jle short loc_1000BF07
lea eax, [edi-0x24]
mov [edi+0x1c], eax
jmp short loc_1000BF0A
loc_1000BF07:
mov [edi+0x1c], ebx
loc_1000BF0A:
cmp dx, cx
jg short loc_1000BF14
mov [edi+0x20], ebx
jmp short loc_1000BF1A
loc_1000BF14:
lea eax, [edi+0x24]
mov [edi+0x20], eax
loc_1000BF1A:
inc cx
add edi, 0x24
cmp [esi+0x2c], cx
jg short loc_1000BEFA
loc_1000BF25:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_1000BF30:
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
mov eax, [edx+0x1c]
test eax, eax
jnz short loc_1000BF3E
xor eax, eax
;ret
RET
loc_1000BF3E:
mov ecx, [eax+0x20]
cmp [edx+0x20], eax
mov [edx+0x1c], ecx
jnz short loc_1000BF50
mov dword [edx+0x20], 0x0
loc_1000BF50:
mov ecx, [eax+0x20]
test ecx, ecx
jz short loc_1000BF5E
mov dword [ecx+0x1c], 0x0
loc_1000BF5E:
mov dword [eax+0x20], 0x0
mov ecx, [edx+0x28]
mov [eax+0x1c], ecx
test ecx, ecx
jz short loc_1000BF7A
mov [ecx+0x20], eax
inc word [edx+0x2e]
mov [edx+0x28], eax
;ret
RET
loc_1000BF7A:
inc word [edx+0x2e]
mov [edx+0x24], eax
mov [edx+0x28], eax
;ret
RET
align 16
loc_1000BF90:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
mov edi, [esi+0x1c]
lea ecx, [esi+0x20]
test edi, edi
mov eax, [ecx]
jz short loc_1000BFAB
;mov edx, [esp+0xc]
mov edx, [r11d+0xc]
mov [edi+0x20], eax
jmp short loc_1000BFB2
loc_1000BFAB:
;mov edx, [esp+0xc]
mov edx, [r11d+0xc]
mov [edx+0x24], eax
loc_1000BFB2:
cmp [edx+0x28], esi
jnz short loc_1000BFBA
mov [edx+0x28], edi
loc_1000BFBA:
mov eax, [ecx]
test eax, eax
jz short loc_1000BFC3
mov [eax+0x1c], edi
loc_1000BFC3:
mov dword [ecx], 0x0
mov eax, [edx+0x20]
mov [esi+0x1c], eax
test eax, eax
jz short loc_1000BFE0
;pop edi
POP32 edi
mov [eax+0x20], esi
dec word [edx+0x2e]
mov [edx+0x20], esi
;pop esi
POP32 esi
;ret
RET
loc_1000BFE0:
dec word [edx+0x2e]
;pop edi
POP32 edi
mov [edx+0x1c], esi
mov [edx+0x20], esi
;pop esi
POP32 esi
;ret
RET
align 16
loc_1000BFF0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push esi
PUSH32 esi
xor ecx, ecx
xor edx, edx
mov [eax], cx
loc_1000BFFC:
movsx esi, cx
inc cx
mov [eax+esi*2+0x8], dx
cmp cx, 0x7d0
jl short loc_1000BFFC
;pop esi
POP32 esi
;ret
RET
align 16
loc_1000C010:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
;push edi
PUSH32 esi, edi
lea edi, [eax+0x6]
lea esi, [eax+0x4]
;push edi
PUSH32 edi
mov ax, [eax+0x2]
;push esi
PUSH32 esi
;push 0x7d0
PUSH32 0x7d0
;push eax
PUSH32 eax
;call loc_10006360
CALL loc_10006360
;mov ax, [esp+0x24]
mov ax, [r11d+0x24]
;mov edx, [esp+0x1c]
mov edx, [r11d+0x1c]
and ax, 0xffe7
;add esp, 0x10
add r11d, 0x10
sar ax, 0x3
movsx ecx, ax
mov ax, [edi]
lea ecx, [ecx+edx+0x20682]
sub ax, [ecx+0x2]
mov [edi], ax
test ah, 0x80
jz short loc_1000C064
xor ax, 0x8000
mov [edi], ax
dec word [esi]
loc_1000C064:
mov ax, [esi]
sub ax, [ecx]
mov [esi], ax
cmp ax, 0x7d0
jl short loc_1000C078
mov word [esi], 0x7cf
loc_1000C078:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_1000C080:
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
;push esi
PUSH32 esi
mov ax, [edx+0x4]
add ax, [edx]
cmp ax, 0x7d0
jl short loc_1000C096
sub ax, 0x7d0
loc_1000C096:
movsx ecx, ax
inc ax
mov si, [edx+ecx*2+0x8]
cmp ax, 0x7d0
jl short loc_1000C0AA
sub ax, 0x7d0
loc_1000C0AA:
movsx eax, ax
mov ax, [edx+eax*2+0x8]
movsx ecx, word [edx+0x6]
sub ax, si
movsx eax, ax
imul eax, ecx
sar eax, 0xf
add ax, si
;pop esi
POP32 esi
;ret
RET
align 16
loc_1000C0D0:
;mov ax, [esp+0x8]
mov ax, [r11d+0x8]
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
movsx ecx, word [edx]
mov [edx+ecx*2+0x8], ax
mov ax, [edx]
dec ax
mov [edx], ax
jns short loc_1000C0F0
mov word [edx], 0x7cf
loc_1000C0F0:
;ret
RET
loc_10015F90:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x3c]
mov esi, [r11d+0x3c]
;push edi
PUSH32 edi
;mov di, [esp+0x3c]
mov di, [r11d+0x3c]
;push ebp
PUSH32 ebp
movsx eax, di
lea edx, [eax+eax*4]
mov ecx, eax
mov dword [esi], 0x0
lea eax, [edx+edx*8]
sub eax, ecx
add eax, 0x46
;push eax
PUSH32 eax
;push 0x40
PUSH32 0x40
;call GlobalAlloc
CALL GlobalAlloc
mov [esi], eax
mov ebx, eax
test ebx, ebx
jnz short loc_10015FCE
mov eax, 0x5
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10015FCE:
mov [ebx+0x3c], di
lea esi, [ebx+0x18]
mov dword [ebx], 0x0
mov dword [ebx+0x4], 0x0
mov dword [ebx+0x8], 0x0
mov dword [ebx+0x10], 0x0
mov dword [ebx+0x14], 0x0
;mov eax, [esp+0x48]
mov eax, [r11d+0x48]
mov dword [esi], 0x0
mov dword [ebx+0x1c], 0x0
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;push eax
PUSH32 eax
;mov edx, [esp+0x18]
mov edx, [r11d+0x18]
;push ebx
PUSH32 ebx
mov dword [ebx+0x20], 0x0
mov dword [ebx+0x24], 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_10005960
CALL loc_10005960
;add esp, 0x18
add r11d, 0x18
test eax, eax
jnz near loc_1001617C
lea eax, [ebx+0x4]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;mov ebp, [esp+0x1c]
mov ebp, [r11d+0x1c]
;push eax
;push ecx
;push ebp
PUSH32 eax, ecx, ebp
;call loc_10008810
CALL loc_10008810
;add esp, 0xc
add r11d, 0xc
test eax, eax
jnz near loc_1001617C
lea eax, [ebx+0x8]
;push eax
;push edi
PUSH32 eax, edi
;call loc_10016F70
CALL loc_10016F70
;add esp, 0x8
add r11d, 0x8
test eax, eax
jnz near loc_1001617C
lea eax, [ebx+0xc]
;push eax
PUSH32 eax
;call loc_100171A0
CALL loc_100171A0
;add esp, 0x4
add r11d, 0x4
test eax, eax
jnz near loc_1001617C
lea eax, [ebx+0x10]
;mov ecx, [esp+0x2c]
mov ecx, [r11d+0x2c]
;mov edx, [esp+0x28]
mov edx, [r11d+0x28]
;push eax
PUSH32 eax
;mov edi, [esp+0x28]
mov edi, [r11d+0x28]
;push ecx
PUSH32 ecx
;push 0x0
PUSH32 0x0
mov eax, [ebx+0x4]
;push 0x0
PUSH32 0x0
mov ecx, [ebx]
;push edx
;push edi
;push eax
;push ecx
PUSH32 edx, edi, eax, ecx
;call loc_1000BAB0
CALL loc_1000BAB0
;add esp, 0x20
add r11d, 0x20
test eax, eax
jnz near loc_1001617C
lea eax, [ebx+0x14]
;mov ecx, [esp+0x30]
mov ecx, [r11d+0x30]
;push eax
PUSH32 eax
mov edx, [ebx+0x4]
;push ecx
PUSH32 ecx
mov eax, [ebx]
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push edx
;push eax
PUSH32 edx, eax
;call loc_1000BAB0
CALL loc_1000BAB0
;add esp, 0x20
add r11d, 0x20
test eax, eax
jnz near loc_1001617C
;mov eax, [esp+0x34]
mov eax, [r11d+0x34]
;push esi
;push eax
PUSH32 esi, eax
mov ecx, [ebx+0x4]
;push 0x0
PUSH32 0x0
mov edx, [ebx]
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_1000BAB0
CALL loc_1000BAB0
;add esp, 0x20
add r11d, 0x20
test eax, eax
jnz near loc_1001617C
lea eax, [ebx+0x1c]
;mov ecx, [esp+0x38]
mov ecx, [r11d+0x38]
;push eax
PUSH32 eax
mov edx, [ebx+0x4]
;push ecx
PUSH32 ecx
mov eax, [ebx]
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push edx
;push eax
PUSH32 edx, eax
;call loc_1000BAB0
CALL loc_1000BAB0
;add esp, 0x20
add r11d, 0x20
test eax, eax
jnz near loc_1001617C
;mov si, [esp+0x3c]
mov si, [r11d+0x3c]
lea eax, [ebx+0x20]
;push eax
PUSH32 eax
mov ecx, [ebx+0x4]
;push esi
PUSH32 esi
mov eax, [ebx]
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push ecx
;push eax
PUSH32 ecx, eax
;call loc_1000BAB0
CALL loc_1000BAB0
;add esp, 0x20
add r11d, 0x20
test eax, eax
jnz near loc_1001617C
lea eax, [ebx+0x24]
mov ecx, [ebx+0x4]
;push eax
;push esi
PUSH32 eax, esi
;push 0x0
PUSH32 0x0
mov edx, [ebx]
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_1000BAB0
CALL loc_1000BAB0
;add esp, 0x20
add r11d, 0x20
test eax, eax
jnz short loc_1001617C
shr ebp, 0x1
;mov eax, [esp+0x28]
mov eax, [r11d+0x28]
;push ebx
PUSH32 ebx
mov [ebx+0x28], ebp
mov [ebx+0x34], edi
mov [ebx+0x38], eax
;call loc_10016EA0
CALL loc_10016EA0
;add esp, 0x4
add r11d, 0x4
xor eax, eax
loc_1001617C:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10016190:
;push esi
PUSH32 esi
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
test esi, esi
jz near loc_10016217
mov eax, [esi]
;push eax
PUSH32 eax
;call loc_10005A70
CALL loc_10005A70
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x4]
;push eax
PUSH32 eax
;call loc_10008890
CALL loc_10008890
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x8]
;push eax
PUSH32 eax
;call loc_10017010
CALL loc_10017010
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0xc]
;push eax
PUSH32 eax
;call loc_100171D0
CALL loc_100171D0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x10]
;push eax
PUSH32 eax
;call loc_1000BB40
CALL loc_1000BB40
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x14]
;push eax
PUSH32 eax
;call loc_1000BB40
CALL loc_1000BB40
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x18]
;push eax
PUSH32 eax
;call loc_1000BB40
CALL loc_1000BB40
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x1c]
;push eax
PUSH32 eax
;call loc_1000BB40
CALL loc_1000BB40
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x20]
;push eax
PUSH32 eax
;call loc_1000BB40
CALL loc_1000BB40
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x24]
;push eax
PUSH32 eax
;call loc_1000BB40
CALL loc_1000BB40
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call GlobalFree
CALL GlobalFree
loc_10016217:
;pop esi
POP32 esi
;ret
RET
align 16
loc_10016220:
;push esi
PUSH32 esi
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
mov eax, [esi+0x4]
;push eax
PUSH32 eax
;call loc_10008B10
CALL loc_10008B10
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x10]
;push eax
PUSH32 eax
;call loc_1000BEC0
CALL loc_1000BEC0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x14]
;push eax
PUSH32 eax
;call loc_1000BEC0
CALL loc_1000BEC0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x18]
;push eax
PUSH32 eax
;call loc_1000BEC0
CALL loc_1000BEC0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x1c]
;push eax
PUSH32 eax
;call loc_1000BEC0
CALL loc_1000BEC0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x20]
;push eax
PUSH32 eax
;call loc_1000BEC0
CALL loc_1000BEC0
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x24]
;push eax
PUSH32 eax
;call loc_1000BEC0
CALL loc_1000BEC0
;add esp, 0x4
add r11d, 0x4
;pop esi
POP32 esi
;ret
RET
align 16
loc_10016280:
;mov dx, [esp+0xc]
mov dx, [r11d+0xc]
;sub esp, 0x4
sub r11d, 0x4
test dx, dx
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
jl near loc_10016302
;mov di, [esp+0x24]
mov di, [r11d+0x24]
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;mov cl, [esp+0x2c]
mov cl, [r11d+0x2c]
mov ebp, [eax]
loc_100162A0:
cmp dx, [ebp+0x18]
jge short loc_10016302
movsx eax, dx
mov esi, eax
shl eax, 0x3
sub eax, esi
lea esi, [ebp+eax*8+0x1a]
mov eax, [ebp+eax*8+0x4e]
test eax, eax
jz near loc_10016314
test di, di
jl near loc_100163C5
cmp [eax], di
jle near loc_100163C5
movsx ebx, di
;mov [esp+0x10], ebx
mov [r11d+0x10], ebx
lea ebx, [ebx+ebx*4]
lea ebx, [ebx+ebx*8]
;sub ebx, [esp+0x10]
sub ebx, [r11d+0x10]
lea ebx, [ebx+eax+0x22]
cmp dword [ebx], 0x0
jnz near loc_10016338
cmp di, 0x80
jle short loc_100162F5
mov di, 0x80
jmp short loc_100162FD
loc_100162F5:
test cl, cl
jz short loc_10016326
mov dx, [ebp+0x16]
loc_100162FD:
test dx, dx
jge short loc_100162A0
loc_10016302:
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
mov dword [ecx], 0x0
loc_1001630C:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016314:
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
mov dword [ecx], 0x0
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016326:
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
mov dword [ecx], 0x0
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016338:
;cmp byte [esp+0x28], 0x0
cmp byte [r11d+0x28], 0x0
jz short loc_1001634E
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
mov ecx, [eax+8]
cmp dword [ecx+8], 0
jnz loc_1001634E
;push byte 0
PUSH32 0 ; skip waiting if thread procedure is quitting
;push eax
PUSH32 eax
;call loc_100163E0
CALL loc_100163E0
;add esp, 0x8
add r11d, 0x8
loc_1001634E:
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
PUSH32 eax
;call loc_10016ED0
CALL loc_10016ED0
;add esp, 0x4
add r11d, 0x4
test eax, eax
jz near loc_1001630C
mov ecx, [esi]
lea edx, [eax+0xc]
mov [eax+0x8], ecx
mov ecx, [ebx]
mov [edx], ecx
;mov cl, [esp+0x28]
mov cl, [r11d+0x28]
sub di, 0x80
mov ebp, [ebx+0x4]
cmp di, 0x1
mov [edx+0x4], ebp
mov ebx, [ebx+0x8]
mov [edx+0x8], ebx
;mov edx, [esp+0x1c]
mov edx, [r11d+0x1c]
;push eax
PUSH32 eax
mov [eax+0x1d], cl
sbb cl, cl
neg cl
;cmp byte [esp+0x2c], 0x0
cmp byte [r11d+0x2c], 0x0
mov [eax+0x1e], cl
mov [eax+0x20], edx
jz short loc_100163AD
;call loc_10016430
CALL loc_10016430
;add esp, 0x4
add r11d, 0x4
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100163AD:
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov ecx, [eax+0x8]
;push ecx
PUSH32 ecx
;call loc_10017060
CALL loc_10017060
;add esp, 0x8
add r11d, 0x8
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100163C5:
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
mov dword [ecx], 0x0
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_100163E0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov bl, [esp+0x10]
mov bl, [r11d+0x10]
;push edi
;push ebp
PUSH32 edi, ebp
mov edi, timeGetTime
test bl, bl
jz short loc_100163FD
;call edi
mov r9d, edi
CALL r9
lea esi, [eax+0xa]
loc_100163F7:
;call edi
mov r9d, edi
CALL r9
cmp eax, esi
jb short loc_100163F7
loc_100163FD:
;call edi
mov r9d, edi
CALL r9
mov ebp, eax
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
loc_10016405:
;call edi
mov r9d, edi
CALL r9
mov cx, [esi+0x40]
cmp [esi+0x3e], cx
jz short loc_1001641B
lea ecx, [ebp+0xfa0]
cmp ecx, eax
ja short loc_10016405
loc_1001641B:
test bl, bl
jz short loc_1001642A
;call edi
mov r9d, edi
CALL r9
lea esi, [eax+0xa]
loc_10016424:
;call edi
mov r9d, edi
CALL r9
cmp eax, esi
jb short loc_10016424
loc_1001642A:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10016430:
;sub esp, 0x4
sub r11d, 0x4
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
PUSH32 edi
mov edi, [esi]
test edi, edi
jz near loc_100164E0
mov eax, [edi+0x4]
;push eax
PUSH32 eax
;call loc_10008980
CALL loc_10008980
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;add esp, 0x4
add r11d, 0x4
lea ecx, [esi+0xc]
mov edx, [edi+0x10]
;push eax
;push ecx
;push edx
;push esi
PUSH32 eax, ecx, edx, esi
;call loc_10016C40
CALL loc_10016C40
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;add esp, 0x10
add r11d, 0x10
mov [esi+0x4], ecx
test ecx, ecx
jz near loc_100164BC
mov eax, [ecx]
cmp eax, 0x6b657962
jz short loc_10016483
cmp eax, 0x70657263
jz short loc_1001648F
jmp short loc_10016498
loc_10016483:
;push ecx
;push esi
PUSH32 ecx, esi
;call loc_100164F0
CALL loc_100164F0
;add esp, 0x8
add r11d, 0x8
jmp short loc_10016498
loc_1001648F:
;push esi
PUSH32 esi
;call loc_100165D0
CALL loc_100165D0
;add esp, 0x4
add r11d, 0x4
loc_10016498:
lea ebx, [esi+0x1c]
cmp byte [ebx], 0x0
jz near loc_100164D6
mov eax, [esi+0x4]
mov ecx, [esi+0x20]
;push 0x1
PUSH32 0x1
mov [ecx], eax
mov eax, [esi+0x4]
mov edx, [edi+0x4]
;push eax
;push edx
PUSH32 eax, edx
;call loc_10008A70
CALL loc_10008A70
;add esp, 0xc
add r11d, 0xc
jmp short loc_100164C2
loc_100164BC:
lea ebx, [esi+0x1c]
mov byte [ebx], 0x0
loc_100164C2:
cmp byte [ebx], 0x0
jz short loc_100164D6
cmp dword [esi+0x20], 0x0
jz short loc_100164D6
;push edi
PUSH32 edi
;call loc_10017490
CALL loc_10017490
;add esp, 0x4
add r11d, 0x4
loc_100164D6:
;push esi
;push edi
PUSH32 esi, edi
;call loc_10016F50
CALL loc_10016F50
;add esp, 0x8
add r11d, 0x8
loc_100164E0:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_100164F0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
;push ebp
PUSH32 edi, ebp
cmp dword [esi], 0x0
jz near loc_100165CA
;mov ebp, [esp+0x18]
mov ebp, [r11d+0x18]
cmp dword [ebp], 0x6b657962
jnz near loc_100165CA
mov bx, [ebp+0x3c]
add ebp, 0x3c
test bx, bx
jle near loc_100165CA
xor di, di
add ebp, 0x2
loc_10016528:
cmp dword [ebp], 0x6c617972
jnz near loc_100165CA
lea eax, [ebp+0xa]
add ebp, 0x8
cmp dword [eax], 0x0
jz short loc_10016551
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016680
CALL loc_10016680
;add esp, 0x8
add r11d, 0x8
mov [ebp+0xa], eax
test eax, eax
jz near loc_100165AB
loc_10016551:
lea eax, [ebp+0x12]
cmp dword [eax], 0x0
jz short loc_1001656A
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016920
CALL loc_10016920
;add esp, 0x8
add r11d, 0x8
mov [ebp+0x1a], eax
test eax, eax
jz near loc_100165B4
loc_1001656A:
lea eax, [ebp+0x22]
cmp dword [eax], 0x0
jz short loc_10016583
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016920
CALL loc_10016920
;add esp, 0x8
add r11d, 0x8
mov [ebp+0x2a], eax
test eax, eax
jz near loc_100165BD
loc_10016583:
lea eax, [ebp+0x30]
cmp dword [eax], 0x0
jz short loc_1001659C
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016920
CALL loc_10016920
;add esp, 0x8
add r11d, 0x8
mov [ebp+0x38], eax
test eax, eax
jz near loc_100165C6
loc_1001659C:
inc di
add ebp, 0x3e
cmp bx, di
jg near loc_10016528
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100165AB:
mov byte [esi+0x1c], 0x0
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100165B4:
mov byte [esi+0x1c], 0x0
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100165BD:
mov byte [esi+0x1c], 0x0
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100165C6:
mov byte [esi+0x1c], 0x0
loc_100165CA:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_100165D0:
;sub esp, 0xc
sub r11d, 0xc
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
;push edi
;push ebp
PUSH32 edi, ebp
mov eax, [esi]
;mov [esp+0x18], eax
mov [r11d+0x18], eax
test eax, eax
jz near loc_10016673
mov edi, [esi+0x4]
cmp dword [edi], 0x70657263
jnz near loc_10016673
mov ax, [edi+0x3e]
add edi, 0x3e
;mov [esp+0x12], ax
mov [r11d+0x12], ax
test ax, ax
jle near loc_10016673
xor bx, bx
add edi, 0x2
loc_1001660B:
cmp dword [edi], 0x736c6f74
jnz near loc_10016673
lea ebp, [edi+0x8]
cmp dword [ebp], 0x0
jz near loc_10016663
;lea eax, [esp+0x14]
lea eax, [r11d+0x14]
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
;push eax
;push ebp
PUSH32 eax, ebp
mov edx, [ecx+0x10]
;push edx
;push esi
PUSH32 edx, esi
;call loc_10016C40
CALL loc_10016C40
;mov ecx, [esp+0x24]
mov ecx, [r11d+0x24]
;add esp, 0x10
add r11d, 0x10
mov [ebp+0x8], ecx
;cmp dword [esp+0x14], 0x0
cmp dword [r11d+0x14], 0x0
jz near loc_1001666F
inc bx
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100164F0
CALL loc_100164F0
;add esp, 0x8
add r11d, 0x8
add edi, [edi+0x4]
;cmp [esp+0x12], bx
cmp [r11d+0x12], bx
jg near loc_1001660B
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_10016663:
mov byte [esi+0x1c], 0x0
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
loc_1001666F:
mov byte [esi+0x1c], 0x0
loc_10016673:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0xc
add r11d, 0xc
;ret
RET
align 16
loc_10016680:
;sub esp, 0x4
sub r11d, 0x4
;push esi
PUSH32 esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
mov ecx, [esi]
test ecx, ecx
jnz short loc_10016695
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016695:
;lea eax, [esp+0x4]
lea eax, [r11d+0x4]
;mov edx, [esp+0x10]
mov edx, [r11d+0x10]
;push eax
PUSH32 eax
mov ecx, [ecx+0x14]
;push edx
;push ecx
;push esi
PUSH32 edx, ecx, esi
;call loc_10016C40
CALL loc_10016C40
;add esp, 0x10
add r11d, 0x10
;cmp dword [esp+0x4], 0x0
cmp dword [r11d+0x4], 0x0
jnz short loc_100166BA
xor eax, eax
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100166BA:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov eax, [eax]
cmp eax, 0x626f7764
jg short loc_100166D6
jz near loc_10016762
cmp eax, 0x616e616c
jz near loc_1001674B
jmp short loc_1001673A
loc_100166D6:
cmp eax, 0x636c6172
jg short loc_100166F0
jz near loc_10016790
cmp eax, 0x62726173
jz near loc_10016779
jmp short loc_1001673A
loc_100166F0:
cmp eax, 0x666c7574
jg short loc_1001670A
jz near loc_100167BE
cmp eax, 0x65706e6f
jz near loc_100167A7
jmp short loc_1001673A
loc_1001670A:
cmp eax, 0x68616d6d
jg short loc_10016724
jz near loc_100167EC
cmp eax, 0x666d2020
jz near loc_100167D5
jmp short loc_1001673A
loc_10016724:
cmp eax, 0x70636d20
jz near loc_10016803
cmp eax, 0x77617665
jz near loc_1001681A
loc_1001673A:
;mov dword [esp+0x4], 0x0
mov dword [r11d+0x4], 0x0
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_1001674B:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100168B0
CALL loc_100168B0
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016762:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100168F0
CALL loc_100168F0
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016779:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016900
CALL loc_10016900
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016790:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100168C0
CALL loc_100168C0
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100167A7:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016910
CALL loc_10016910
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100167BE:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100168D0
CALL loc_100168D0
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100167D5:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100168A0
CALL loc_100168A0
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100167EC:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100168E0
CALL loc_100168E0
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016803:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016840
CALL loc_10016840
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_1001681A:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016870
CALL loc_10016870
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10016840:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
mov ecx, [eax+0x4]
lea esi, [ecx+eax-0x18]
cmp dword [esi], 0x0
jz short loc_10016867
mov ax, [esi+0xc]
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
;push eax
;push esi
;push ecx
PUSH32 eax, esi, ecx
;call loc_10016960
CALL loc_10016960
;add esp, 0xc
add r11d, 0xc
mov [esi+0x8], eax
loc_10016867:
;pop esi
POP32 esi
;ret
RET
align 16
loc_10016870:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push esi
PUSH32 esi
mov ecx, [eax+0x4]
lea esi, [ecx+eax-0xc]
cmp dword [esi], 0x0
jz short loc_10016894
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push 0x0
PUSH32 0x0
;push esi
;push eax
PUSH32 esi, eax
;call loc_10016A10
CALL loc_10016A10
;add esp, 0xc
add r11d, 0xc
mov [esi+0x8], eax
loc_10016894:
;pop esi
POP32 esi
;ret
RET
align 16
loc_100168A0:
;ret
RET
align 16
loc_100168B0:
;ret
RET
align 16
loc_100168C0:
;ret
RET
align 16
loc_100168D0:
;ret
RET
align 16
loc_100168E0:
;ret
RET
align 16
loc_100168F0:
;ret
RET
align 16
loc_10016900:
;ret
RET
align 16
loc_10016910:
;ret
RET
align 16
loc_10016920:
;mov edx, [esp+0x4]
mov edx, [r11d+0x4]
;sub esp, 0x4
sub r11d, 0x4
mov ecx, [edx]
test ecx, ecx
jnz short loc_10016933
xor eax, eax
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_10016933:
;lea eax, [esp]
lea eax, [r11d]
mov ecx, [ecx+0x18]
;push eax
PUSH32 eax
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;push eax
;push ecx
;push edx
PUSH32 eax, ecx, edx
;call loc_10016C40
CALL loc_10016C40
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;add esp, 0x10
add r11d, 0x10
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10016960:
;sub esp, 0x4
sub r11d, 0x4
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push edi
;push ebp
PUSH32 edi, ebp
mov ecx, [esi]
test ecx, ecx
jnz short loc_1001697B
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_1001697B:
;lea eax, [esp+0x10]
lea eax, [r11d+0x10]
;mov edx, [esp+0x1c]
mov edx, [r11d+0x1c]
;push eax
PUSH32 eax
mov ecx, [ecx+0x1c]
;push edx
;push ecx
;push esi
PUSH32 edx, ecx, esi
;call loc_10016C40
CALL loc_10016C40
;add esp, 0x10
add r11d, 0x10
;cmp dword [esp+0x10], 0x0
cmp dword [r11d+0x10], 0x0
jnz short loc_100169A3
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100169A3:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
cmp dword [eax], 0x6d73616d
jz short loc_100169B9
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100169B9:
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
mov bx, [edi+0x3a]
add edi, 0x3a
test bx, bx
jg short loc_100169D3
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100169D3:
add edi, 0x4
test bx, bx
jle short loc_100169FA
;mov bp, [esp+0x20]
mov bp, [r11d+0x20]
loc_100169E0:
cmp dword [edi], 0x0
jz short loc_100169F3
;push ebp
;push edi
;push esi
PUSH32 ebp, edi, esi
;call loc_10016A10
CALL loc_10016A10
;add esp, 0xc
add r11d, 0xc
mov [edi+0x8], eax
loc_100169F3:
add edi, 0x12
dec bx
jnz short loc_100169E0
loc_100169FA:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10016A10:
;sub esp, 0x8
sub r11d, 0x8
;mov byte [esp+0x3], 0x0
mov byte [r11d+0x3], 0x0
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push edi
;push ebp
PUSH32 edi, ebp
mov ebp, [esi]
test ebp, ebp
jnz short loc_10016A30
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10016A30:
;mov edi, [esp+0x20]
mov edi, [r11d+0x20]
mov eax, [esi+0x8]
;push edi
PUSH32 edi
mov ecx, [ebp+0x24]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BC70
CALL loc_1000BC70
;mov [esp+0x20], eax
mov [r11d+0x20], eax
;add esp, 0xc
add r11d, 0xc
test eax, eax
jz short loc_10016A6B
cmp dword [eax], 0x73616d70
jz short loc_10016A5F
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10016A5F:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10016A6B:
;lea eax, [esp+0x14]
lea eax, [r11d+0x14]
mov ecx, [ebp+0x20]
;push eax
;push edi
;push ecx
;push esi
PUSH32 eax, edi, ecx, esi
;call loc_10016C40
CALL loc_10016C40
;add esp, 0x10
add r11d, 0x10
;cmp dword [esp+0x14], 0x0
cmp dword [r11d+0x14], 0x0
jnz short loc_10016A8F
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10016A8F:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
cmp dword [eax], 0x73616d70
jz short loc_10016AA5
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10016AA5:
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
movsx eax, byte [ecx+0x34]
add ecx, 0x30
cmp eax, 0x4
ja near loc_10016BAF
;jmp dword [eax*4+loc_10016C2C]
mov r9d, [eax*4+loc_10016C2C]
jmp r9
loc_10016AC0:
cmp word [ecx+0x2], 0x1
jnz short loc_10016AF0
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
;push edi
;push esi
PUSH32 eax, edi, esi
;call loc_10017980
CALL loc_10017980
;add esp, 0xc
add r11d, 0xc
mov ebx, eax
mov ecx, [ebp+0x20]
;push 0x1
PUSH32 0x1
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BD60
CALL loc_1000BD60
;add esp, 0xc
add r11d, 0xc
jmp loc_10016BB3
loc_10016AF0:
;mov byte [esp+0x13], 0x1
mov byte [r11d+0x13], 0x1
jmp loc_10016BAF
loc_10016AFA:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
;push edi
PUSH32 eax, edi
;push 0x40000
PUSH32 0x40000
;push esi
PUSH32 esi
;call loc_10017C40
CALL loc_10017C40
;add esp, 0x10
add r11d, 0x10
mov ebx, eax
mov ecx, [ebp+0x20]
;push 0x1
PUSH32 0x1
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BD60
CALL loc_1000BD60
;add esp, 0xc
add r11d, 0xc
jmp loc_10016BB3
loc_10016B28:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
;push edi
PUSH32 eax, edi
;push 0x20000
PUSH32 0x20000
;push 0x2
PUSH32 0x2
;push esi
PUSH32 esi
;call loc_10017DA0
CALL loc_10017DA0
;add esp, 0x14
add r11d, 0x14
mov ebx, eax
mov ecx, [ebp+0x20]
;push 0x1
PUSH32 0x1
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BD60
CALL loc_1000BD60
;add esp, 0xc
add r11d, 0xc
jmp loc_10016BB3
loc_10016B55:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
;push edi
PUSH32 eax, edi
;push 0x800000
PUSH32 0x800000
;push 0x4
PUSH32 0x4
;push esi
PUSH32 esi
;call loc_10017DA0
CALL loc_10017DA0
;add esp, 0x14
add r11d, 0x14
mov ebx, eax
mov ecx, [ebp+0x20]
;push 0x1
PUSH32 0x1
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BD60
CALL loc_1000BD60
;add esp, 0xc
add r11d, 0xc
jmp loc_10016BB3
loc_10016B82:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;push eax
;push edi
PUSH32 eax, edi
;push 0x10000000
PUSH32 0x10000000
;push 0x8
PUSH32 0x8
;push esi
PUSH32 esi
;call loc_10017DA0
CALL loc_10017DA0
;add esp, 0x14
add r11d, 0x14
mov ebx, eax
mov ecx, [ebp+0x20]
;push 0x1
PUSH32 0x1
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BD60
CALL loc_1000BD60
;add esp, 0xc
add r11d, 0xc
jmp short loc_10016BB3
loc_10016BAF:
;mov ebx, [esp+0x14]
mov ebx, [r11d+0x14]
loc_10016BB3:
;mov cx, [esp+0x24]
mov cx, [r11d+0x24]
test cx, cx
jz near loc_10016C0C
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
mov eax, ebx
jz short loc_10016BCA
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
loc_10016BCA:
;push eax
;push edi
;push ecx
;push esi
PUSH32 eax, edi, ecx, esi
;call loc_10017AB0
CALL loc_10017AB0
;add esp, 0x10
add r11d, 0x10
mov esi, eax
test esi, esi
jz short loc_10016C0C
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_10016BF3
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
;mov ebx, [esp+0x14]
mov ebx, [r11d+0x14]
jz short loc_10016BF3
mov eax, [ebp+0x20]
jmp short loc_10016BF6
loc_10016BF3:
mov eax, [ebp+0x24]
loc_10016BF6:
;push 0x1
PUSH32 0x1
;push ebx
;push eax
PUSH32 ebx, eax
;call loc_1000BD60
CALL loc_1000BD60
;add esp, 0xc
add r11d, 0xc
mov eax, esi
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10016C0C:
;cmp byte [esp+0x13], 0x0
cmp byte [r11d+0x13], 0x0
jz short loc_10016C1F
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
loc_10016C1F:
mov eax, ebx
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x8
add r11d, 0x8
;ret
RET
db 141
db 73
db 0
align 4
loc_10016C2C:
dd loc_10016AC0
dd loc_10016AFA
dd loc_10016B28
dd loc_10016B55
dd loc_10016B82
align 4
loc_10016C40:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
;push ebp
PUSH32 ebp
;mov ebp, [esp+0x1c]
mov ebp, [r11d+0x1c]
mov edi, [esi]
mov dword [eax], 0x0
mov ecx, [ebp+0x4]
cmp [edi+0x28], ecx
jae short loc_10016C6A
mov eax, 0x5
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10016C6A:
mov al, [esi+0x1e]
mov cl, [esi+0x1d]
;push eax
PUSH32 eax
mov edx, [esi+0x8]
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;push ecx
;push ebp
;push edx
;push eax
PUSH32 ecx, ebp, edx, eax
;call loc_1000BB70
CALL loc_1000BB70
;add esp, 0x14
add r11d, 0x14
mov ebx, eax
test ebx, ebx
jnz near loc_10016CC1
mov eax, [esi+0x18]
mov ecx, [ebp+0x4]
;push eax
;push ecx
;push edi
PUSH32 eax, ecx, edi
;call loc_10016D00
CALL loc_10016D00
;add esp, 0xc
add r11d, 0xc
test al, al
jz near loc_10016CE0
mov al, [esi+0x1e]
mov cl, [esi+0x1d]
;push eax
PUSH32 eax
mov edx, [esi+0x8]
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;push ecx
PUSH32 ecx
;push 0x1
PUSH32 0x1
;push ebp
;push edx
;push eax
PUSH32 ebp, edx, eax
;call loc_1000BBD0
CALL loc_1000BBD0
;add esp, 0x18
add r11d, 0x18
mov ebx, eax
test ebx, ebx
jz near loc_10016CEA
loc_10016CC1:
;push 0x1
PUSH32 0x1
mov [edi+0x2c], ebx
;push ebx
PUSH32 ebx
mov eax, [edi+0x4]
;push eax
PUSH32 eax
;call loc_10008A40
CALL loc_10008A40
;mov eax, [esp+0x2c]
mov eax, [r11d+0x2c]
;add esp, 0xc
add r11d, 0xc
;pop ebp
POP32 ebp
mov [eax], ebx
xor eax, eax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10016CE0:
mov eax, 0x5
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_10016CEA:
mov eax, 0x5
;pop ebp
POP32 ebp
mov byte [esi+0x1c], 0x0
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10016D00:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
;mov ebx, [esp+0x18]
mov ebx, [r11d+0x18]
loc_10016D0F:
;push esi
PUSH32 esi
;call loc_10016D50
CALL loc_10016D50
;add esp, 0x4
add r11d, 0x4
inc eax
cmp eax, ebx
jae near loc_10016D4A
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016DD0
CALL loc_10016DD0
;add esp, 0x8
add r11d, 0x8
mov eax, [esi+0x4]
;push eax
PUSH32 eax
;call loc_10008980
CALL loc_10008980
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x4]
;push edi
;push eax
PUSH32 edi, eax
;call loc_100089F0
CALL loc_100089F0
;add esp, 0x8
add r11d, 0x8
test al, al
jz near loc_10016D0F
mov al, 0x1
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10016D4A:
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10016D50:
;sub esp, 0x4
sub r11d, 0x4
;lea eax, [esp]
lea eax, [r11d]
;push esi
PUSH32 esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push eax
PUSH32 eax
;mov dword [esp+0x8], 0xffffffff
mov dword [r11d+0x8], 0xffffffff
mov ecx, [esi+0x10]
;push ecx
PUSH32 ecx
;call loc_1000BDD0
CALL loc_1000BDD0
;lea eax, [esp+0xc]
lea eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
mov ecx, [esi+0x14]
;push eax
;push ecx
PUSH32 eax, ecx
;call loc_1000BDD0
CALL loc_1000BDD0
;lea ecx, [esp+0xc]
lea ecx, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
mov edx, [esi+0x18]
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_1000BDD0
CALL loc_1000BDD0
;lea ecx, [esp+0xc]
lea ecx, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
mov edx, [esi+0x1c]
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_1000BDD0
CALL loc_1000BDD0
;lea ecx, [esp+0xc]
lea ecx, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
mov edx, [esi+0x20]
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_1000BDD0
CALL loc_1000BDD0
;lea ecx, [esp+0xc]
lea ecx, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
mov edx, [esi+0x24]
;push ecx
;push edx
PUSH32 ecx, edx
;call loc_1000BDD0
CALL loc_1000BDD0
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;add esp, 0x8
add r11d, 0x8
;pop esi
POP32 esi
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10016DD0:
;push esi
;push edi
PUSH32 esi, edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
mov eax, [esi+0x10]
;push eax
PUSH32 eax
mov [esi+0x30], edi
;call loc_1000BD80
CALL loc_1000BD80
;add esp, 0x8
add r11d, 0x8
mov eax, [esi+0x14]
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BD80
CALL loc_1000BD80
;add esp, 0x8
add r11d, 0x8
mov eax, [esi+0x18]
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BD80
CALL loc_1000BD80
;add esp, 0x8
add r11d, 0x8
mov eax, [esi+0x1c]
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BD80
CALL loc_1000BD80
;add esp, 0x8
add r11d, 0x8
mov eax, [esi+0x20]
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BD80
CALL loc_1000BD80
;add esp, 0x8
add r11d, 0x8
mov eax, [esi+0x24]
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BD80
CALL loc_1000BD80
;add esp, 0x8
add r11d, 0x8
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10016E30:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push eax
PUSH32 eax
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov ecx, [eax+0x38]
;push ecx
PUSH32 ecx
;call dword [eax+0x34]
mov r9d, [eax+0x34]
CALL r9
;add esp, 0x8
add r11d, 0x8
;ret
RET
align 16
loc_10016E50:
;push esi
PUSH32 esi
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
mov eax, [esi+0x10]
;push eax
PUSH32 eax
;call loc_1000BE00
CALL loc_1000BE00
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x14]
;push eax
PUSH32 eax
;call loc_1000BE00
CALL loc_1000BE00
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x18]
;push eax
PUSH32 eax
;call loc_1000BE00
CALL loc_1000BE00
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x1c]
;push eax
PUSH32 eax
;call loc_1000BE00
CALL loc_1000BE00
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x20]
;push eax
PUSH32 eax
;call loc_1000BE00
CALL loc_1000BE00
;add esp, 0x4
add r11d, 0x4
mov eax, [esi+0x24]
;push eax
PUSH32 eax
;call loc_1000BE00
CALL loc_1000BE00
;add esp, 0x4
add r11d, 0x4
;pop esi
POP32 esi
;ret
RET
align 16
loc_10016EA0:
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
xor ecx, ecx
mov [eax+0x3e], cx
lea edx, [eax+0x46]
mov [eax+0x40], cx
cmp [eax+0x3c], cx
jle short loc_10016EC4
loc_10016EB7:
inc cx
mov [edx], eax
add edx, 0x2c
cmp [eax+0x3c], cx
jg short loc_10016EB7
loc_10016EC4:
;ret
RET
align 16
loc_10016ED0:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
mov dx, [edi+0x3e]
inc dword [edi+0x42]
movsx eax, dx
inc dx
mov ecx, eax
mov [edi+0x3e], dx
lea ebx, [eax+eax*4]
lea eax, [ebx+ebx*8]
sub eax, ecx
lea esi, [eax+edi+0x46]
mov ax, [edi+0x3c]
cmp ax, dx
jg short loc_10016F04
mov word [edi+0x3e], 0x0
loc_10016F04:
mov cx, [edi+0x40]
cmp ax, cx
jg short loc_10016F10
xor cx, cx
loc_10016F10:
cmp [edi+0x3e], cx
jnz short loc_10016F1C
xor eax, eax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10016F1C:
mov dword [esi+0x4], 0x0
;call timeGetTime
CALL timeGetTime
;pop edi
POP32 edi
mov [esi+0x18], eax
mov byte [esi+0x1c], 0x1
mov byte [esi+0x1e], 0x0
mov dword [esi+0x20], 0x0
mov eax, esi
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_10016F50:
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
mov ax, [ecx+0x40]
inc ax
mov [ecx+0x40], ax
cmp [ecx+0x3c], ax
jg short loc_10016F6A
mov word [ecx+0x40], 0x0
loc_10016F6A:
;ret
RET
align 16
loc_10016F70:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x10]
mov ebx, [r11d+0x10]
;push edi
PUSH32 edi
;mov di, [esp+0x10]
mov di, [r11d+0x10]
mov dword [ebx], 0x0
movsx eax, di
shl eax, 0x4
add eax, 0x18
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
;call GlobalAlloc
CALL GlobalAlloc
mov [ebx], eax
mov esi, eax
test esi, esi
jnz short loc_10016FA5
mov eax, 0x5
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10016FA5:
xor ecx, ecx
lea eax, [esi+0x18]
mov [esi+0x10], cx
mov [esi+0x12], cx
mov [esi+0x14], di
mov [esi+0x16], cx
test di, di
jle short loc_10016FCB
loc_10016FBF:
mov [eax], ebx
add eax, 0x10
dec di
mov [eax-0xc], ecx
jnz short loc_10016FBF
loc_10016FCB:
mov dword [esi+0x8], 0x0
lea eax, [esi+0x4]
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
;push esi
PUSH32 esi
;push loc_10017150
PUSH32 loc_10017150
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;call CreateThread
CALL CreateThread
;push 0xfffffffe
PUSH32 0xfffffffe
mov [esi], eax
;push eax
PUSH32 eax
;call SetThreadPriority
CALL SetThreadPriority
;push 0x0
PUSH32 0x0
;push 0x20
PUSH32 0x20
;push 0x0
PUSH32 0x0
;push 0x0
PUSH32 0x0
;call CreateSemaphoreA
CALL CreateSemaphoreA
;pop edi
POP32 edi
mov [esi+0xc], eax
xor eax, eax
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_10017010:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
test edi, edi
jz near loc_1001704E
cmp dword [edi+8], 0
jnz loc_10017036
mov dword [edi+8], 1 ; skip waiting if thread procedure is quitting
mov ebx, timeGetTime
;call ebx
mov r9d, ebx
CALL r9
lea esi, [eax+0x3e8]
loc_10017030:
;call ebx
mov r9d, ebx
CALL r9
cmp eax, esi
jb short loc_10017030
loc_10017036:
mov eax, [edi] ; skip waiting if thread procedure is quitting
mov esi, CloseHandle
;push eax
PUSH32 eax
;call esi
mov r9d, esi
CALL r9
mov ecx, [edi+0xc]
;push ecx
PUSH32 ecx
;call esi
mov r9d, esi
CALL r9
;push edi
PUSH32 edi
;call GlobalFree
CALL GlobalFree
loc_1001704E:
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10017060:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push esi
PUSH32 esi
;call loc_10017130
CALL loc_10017130
;add esp, 0x4
add r11d, 0x4
;push esi
PUSH32 esi
;call loc_100170B0
CALL loc_100170B0
mov [eax], esi
;add esp, 0x4
add r11d, 0x4
mov edi, eax
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
mov [edi+0x4], eax
;call timeGetTime
CALL timeGetTime
;push 0x0
PUSH32 0x0
mov [edi+0x8], eax
mov dword [edi+0xc], 0x0
;push 0x1
PUSH32 0x1
mov ecx, [esi+0xc]
;push ecx
PUSH32 ecx
;call ReleaseSemaphore
CALL ReleaseSemaphore
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_100170B0:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
mov ax, [esi+0x10]
movsx ecx, ax
inc ax
shl ecx, 0x4
mov [esi+0x10], ax
inc word [esi+0x16]
lea edi, [ecx+esi+0x18]
cmp [esi+0x14], ax
jg short loc_100170DA
mov word [esi+0x10], 0x0
loc_100170DA:
;push esi
PUSH32 esi
;call loc_10017130
CALL loc_10017130
mov cx, [esi+0x10]
;add esp, 0x4
add r11d, 0x4
sub cx, ax
mov eax, 0x0
cmp cx, 0x1
adc eax, 0xffffffff
and eax, edi
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_10017100:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov dword [eax+0x4], 0x0
mov dword [eax], 0x0
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
mov cx, [eax+0x12]
inc cx
mov [eax+0x12], cx
cmp [eax+0x14], cx
jg short loc_1001712B
mov word [eax+0x12], 0x0
loc_1001712B:
;ret
RET
align 16
loc_10017130:
;mov ecx, [esp+0x4]
mov ecx, [r11d+0x4]
mov ax, [ecx+0x12]
cmp [ecx+0x14], ax
jg short loc_10017141
xor ax, ax
loc_10017141:
;ret
RET
align 16
loc_10017150:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
mov esi, WaitForSingleObject
;mov edi, [esp+0x10]
mov edi, [r11d+0x10]
loc_1001715D:
;push 0xffffffff
PUSH32 0xffffffff
mov eax, [edi+0xc]
;push eax
PUSH32 eax
;call esi
mov r9d, esi
CALL r9
mov ax, [edi+0x12]
cmp [edi+0x10], ax
jz short loc_10017190
movsx eax, ax
shl eax, 0x4
mov ecx, [eax+edi+0x1c]
;push ecx
PUSH32 ecx
lea ebx, [eax+edi+0x18]
;call loc_10016430
CALL loc_10016430
;add esp, 0x4
add r11d, 0x4
;push ebx
;push edi
PUSH32 ebx, edi
;call loc_10017100
CALL loc_10017100
;add esp, 0x8
add r11d, 0x8
loc_10017190:
cmp dword [edi+0x8], 0x0
jz near loc_1001715D
xor eax, eax
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_100171A0:
;push esi
PUSH32 esi
;push 0x4a
PUSH32 0x4a
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push 0x40
PUSH32 0x40
mov dword [esi], 0x0
;call GlobalAlloc
CALL GlobalAlloc
mov [esi], eax
cmp eax, 0x1
sbb eax, eax
;pop esi
POP32 esi
and eax, 0x5
;ret
RET
align 16
loc_100171D0:
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;mov ebp, [esp+0x14]
mov ebp, [r11d+0x14]
test ebp, ebp
jz short loc_100171FD
mov bx, 0x4
lea esi, [ebp+0x2]
mov edi, GlobalFree
loc_100171E9:
mov eax, [esi+0xe]
test eax, eax
jz short loc_100171F3
;push eax
PUSH32 eax
;call edi
mov r9d, edi
CALL r9
loc_100171F3:
add esi, 0x12
dec bx
jnz short loc_100171E9
;push ebp
PUSH32 ebp
;call edi
mov r9d, edi
CALL r9
loc_100171FD:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10017210:
;push ebx
;push esi
PUSH32 ebx, esi
;mov si, [esp+0x14]
mov si, [r11d+0x14]
;push edi
PUSH32 edi
;mov edi, [esp+0x1c]
mov edi, [r11d+0x1c]
;push ebp
PUSH32 ebp
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push edi
PUSH32 edi
;mov ebp, [esp+0x18]
mov ebp, [r11d+0x18]
;push esi
;push eax
;push ebp
PUSH32 esi, eax, ebp
;call loc_10017270
CALL loc_10017270
;add esp, 0x10
add r11d, 0x10
test eax, eax
jnz near loc_10017265
;push ebp
PUSH32 ebp
;call loc_100172C0
CALL loc_100172C0
;add esp, 0x4
add r11d, 0x4
mov ebx, eax
test ebx, ebx
jnz short loc_10017253
;push ebp
PUSH32 ebp
;call loc_100172E0
CALL loc_100172E0
;add esp, 0x4
add r11d, 0x4
mov ebx, eax
test ebx, ebx
jz short loc_10017263
loc_10017253:
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push edi
;push esi
;push eax
;push ebx
PUSH32 edi, esi, eax, ebx
;call loc_10017340
CALL loc_10017340
;add esp, 0x10
add r11d, 0x10
loc_10017263:
mov eax, ebx
loc_10017265:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10017270:
;mov ax, [esp+0xc]
mov ax, [r11d+0xc]
;push esi
PUSH32 esi
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
;push edi
PUSH32 edi
xor di, di
add esi, 0x2
;mov dl, [esp+0x10]
mov dl, [r11d+0x10]
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
loc_10017289:
cmp [esi], dl
jnz short loc_10017298
cmp [esi+0x2], ax
jnz short loc_10017298
cmp [esi+0x4], ecx
jz short loc_100172A8
loc_10017298:
inc di
add esi, 0x12
cmp di, 0x4
jl short loc_10017289
xor eax, eax
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
loc_100172A8:
;call timeGetTime
CALL timeGetTime
;pop edi
POP32 edi
mov [esi+0x8], eax
mov eax, esi
;pop esi
POP32 esi
;ret
RET
align 16
loc_100172C0:
xor cx, cx
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
add eax, 0x2
loc_100172CA:
cmp byte [eax], 0x0
jz short loc_100172DC
inc cx
add eax, 0x12
cmp cx, 0x4
jl short loc_100172CA
xor eax, eax
loc_100172DC:
;ret
RET
align 16
loc_100172E0:
mov dx, 0x4
;push esi
PUSH32 esi
xor eax, eax
;mov ecx, [esp+0x8]
mov ecx, [r11d+0x8]
add ecx, 0x2
loc_100172EE:
cmp byte [ecx], 0x0
jz short loc_10017301
test eax, eax
jz short loc_100172FF
mov esi, [eax+0x8]
cmp [ecx+0x8], esi
jae short loc_10017301
loc_100172FF:
mov eax, ecx
loc_10017301:
add ecx, 0x12
dec dx
jnz short loc_100172EE
;pop esi
POP32 esi
;ret
RET
align 16
loc_10017310:
;mov ax, [esp+0x8]
mov ax, [r11d+0x8]
mov cl, 0x0
test ax, ax
jge short loc_10017328
mov dx, 0xffff
mov cl, 0x1
sub dx, ax
mov ax, dx
loc_10017328:
movsx edx, ax
;mov eax, [esp+0x4]
mov eax, [r11d+0x4]
test cl, cl
mov eax, [eax+0xe]
mov ax, [eax+edx*2]
jz short loc_1001733D
neg ax
loc_1001733D:
;ret
RET
align 16
loc_10017340:
;movsx eax, byte [esp+0x8]
movsx eax, byte [r11d+0x8]
;push esi
PUSH32 esi
cmp eax, 0x1
jz short loc_1001735F
cmp eax, 0x2
jz near loc_1001737C
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
;call timeGetTime
CALL timeGetTime
mov [esi+0x8], eax
;pop esi
POP32 esi
;ret
RET
loc_1001735F:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100173A0
CALL loc_100173A0
;add esp, 0x8
add r11d, 0x8
;call timeGetTime
CALL timeGetTime
mov [esi+0x8], eax
;pop esi
POP32 esi
;ret
RET
loc_1001737C:
;mov eax, [esp+0x14]
mov eax, [r11d+0x14]
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
;mov esi, [esp+0x8]
mov esi, [r11d+0x8]
;push eax
;push ecx
;push esi
PUSH32 eax, ecx, esi
;call loc_10017400
CALL loc_10017400
;add esp, 0xc
add r11d, 0xc
;call timeGetTime
CALL timeGetTime
mov [esi+0x8], eax
;pop esi
POP32 esi
;ret
RET
align 16
loc_100173A0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov ebx, [esp+0x10]
mov ebx, [r11d+0x10]
;push edi
;push ebp
PUSH32 edi, ebp
mov edi, 0x10000
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
xor ebp, ebp
mov [esi+0x2], bp
;push 0x100
PUSH32 0x100
;push ebp
PUSH32 ebp
mov byte [esi], 0x1
mov word [esi+0xc], 0x80
mov [esi+0x4], ebx
;call GlobalAlloc
CALL GlobalAlloc
mov [esi+0xe], eax
loc_100173D2:
mov ecx, edi
mov eax, [esi+0xe]
sar ecx, 0x10
add edi, ebx
movsx edx, bp
mov [eax+edx*2], cx
inc bp
;add ebx, [esp+0x18]
add ebx, [r11d+0x18]
cmp bp, 0x80
jl short loc_100173D2
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10017400:
;mov eax, [esp+0xc]
mov eax, [r11d+0xc]
;sub esp, 0x4
sub r11d, 0x4
;mov [esp], eax
mov [r11d], eax
;push ebx
;push esi
PUSH32 ebx, esi
mov ebx, eax
;mov ax, [esp+0x14]
mov ax, [r11d+0x14]
;push edi
PUSH32 edi
mov di, 0x1
;push ebp
PUSH32 ebp
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
mov [esi+0x2], ax
mov byte [esi], 0x2
movsx ebp, ax
mov eax, 0x10
mov [esi+0x4], ecx
cdq
idiv ebp
cmp ax, di
jle short loc_10017445
dec ax
loc_1001743E:
add di, di
dec ax
jnz short loc_1001743E
loc_10017445:
mov [esi+0xc], di
mov ebp, GlobalAlloc
movsx eax, di
add eax, eax
;push eax
PUSH32 eax
;push 0x0
PUSH32 0x0
;call ebp
mov r9d, ebp
CALL r9
mov [esi+0xe], eax
xor ax, ax
test di, di
jle short loc_10017485
loc_10017464:
;mov ecx, [esp+0x10]
mov ecx, [r11d+0x10]
mov ebp, [esi+0xe]
sar ecx, 0x10
;add [esp+0x10], ebx
add [r11d+0x10], ebx
movsx edx, ax
mov [ebp+edx*2], cx
inc ax
;add ebx, [esp+0x20]
add ebx, [r11d+0x20]
cmp di, ax
jg short loc_10017464
loc_10017485:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10017490:
;push esi
;push edi
PUSH32 esi, edi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
mov eax, [esi+0x10]
mov edi, [eax+0x24]
test edi, edi
jz short loc_100174C3
loc_100174A0:
mov eax, [edi]
;push eax
;push esi
PUSH32 eax, esi
;call loc_100174D0
CALL loc_100174D0
;add esp, 0x8
add r11d, 0x8
test al, al
jnz short loc_100174BC
mov eax, [edi]
;push eax
;push esi
PUSH32 eax, esi
;call loc_10016E30
CALL loc_10016E30
;add esp, 0x8
add r11d, 0x8
loc_100174BC:
mov edi, [edi+0x20]
test edi, edi
jnz short loc_100174A0
loc_100174C3:
;pop edi
;pop esi
POP32 esi, edi
;ret
RET
align 16
loc_100174D0:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
mov eax, [esi+0x10]
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BE60
CALL loc_1000BE60
;add esp, 0x8
add r11d, 0x8
cmp eax, 0x1
sbb al, al
inc al
jnz short loc_100174F7
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_100174F7:
mov eax, [edi]
cmp eax, 0x6b657962
jz short loc_1001750B
cmp eax, 0x70657263
jz short loc_10017514
xor bl, bl
jmp short loc_10017520
loc_1001750B:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017540
CALL loc_10017540
jmp short loc_1001751B
loc_10017514:
;push edi
;push esi
PUSH32 edi, esi
;call loc_100175A0
CALL loc_100175A0
loc_1001751B:
;add esp, 0x8
add r11d, 0x8
mov bl, al
loc_10017520:
;push ebx
PUSH32 ebx
mov eax, [esi+0x4]
;push edi
;push eax
PUSH32 edi, eax
;call loc_10008A70
CALL loc_10008A70
;add esp, 0xc
add r11d, 0xc
mov al, bl
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10017540:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
mov bl, 0x1
;push ebp
PUSH32 ebp
;mov ebp, [esp+0x18]
mov ebp, [r11d+0x18]
cmp dword [ebp], 0x6b657962
jz short loc_1001755A
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_1001755A:
mov si, [ebp+0x3c]
add ebp, 0x3c
add ebp, 0x2
test si, si
jle short loc_10017595
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
loc_1001756D:
mov eax, [ebp+0x12]
add ebp, 0x8
test eax, eax
jz short loc_10017585
;push eax
;push edi
PUSH32 eax, edi
;call loc_10017610
CALL loc_10017610
;add esp, 0x8
add r11d, 0x8
test al, al
jnz short loc_1001758E
loc_10017585:
mov dword [ebp+0xa], 0x0
xor bl, bl
loc_1001758E:
add ebp, 0x3e
dec si
jnz short loc_1001756D
loc_10017595:
mov al, bl
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_100175A0:
;sub esp, 0x4
sub r11d, 0x4
;mov byte [esp+0x3], 0x1
mov byte [r11d+0x3], 0x1
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
;mov ebp, [esp+0x1c]
mov ebp, [r11d+0x1c]
cmp dword [ebp], 0x70657263
jz short loc_100175C3
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
loc_100175C3:
mov si, [ebp+0x3e]
add ebp, 0x3e
add ebp, 0x2
test si, si
jle short loc_10017601
;mov edi, [esp+0x18]
mov edi, [r11d+0x18]
loc_100175D6:
mov eax, [ebp+0x10]
lea ebx, [ebp+0x8]
test eax, eax
jz short loc_100175EE
;push eax
;push edi
PUSH32 eax, edi
;call loc_10017540
CALL loc_10017540
;add esp, 0x8
add r11d, 0x8
test al, al
jnz short loc_100175FA
loc_100175EE:
;mov byte [esp+0x13], 0x0
mov byte [r11d+0x13], 0x0
mov dword [ebx+0x8], 0x0
loc_100175FA:
add ebp, [ebp+0x4]
dec si
jnz short loc_100175D6
loc_10017601:
;mov al, [esp+0x13]
mov al, [r11d+0x13]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x4
add r11d, 0x4
;ret
RET
align 16
loc_10017610:
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0xc]
mov esi, [r11d+0xc]
;push edi
PUSH32 edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
mov eax, [esi+0x14]
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BE60
CALL loc_1000BE60
;add esp, 0x8
add r11d, 0x8
cmp eax, 0x1
sbb al, al
inc al
jnz short loc_10017637
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10017637:
mov eax, [edi]
cmp eax, 0x626f7764
jg short loc_10017650
jz near loc_100176AD
cmp eax, 0x616e616c
jz near loc_100176A4
xor bl, bl
jmp loc_10017701
loc_10017650:
cmp eax, 0x636c6172
jg short loc_10017667
jz near loc_100176BF
cmp eax, 0x62726173
jz near loc_100176B6
xor bl, bl
jmp loc_10017701
loc_10017667:
cmp eax, 0x666c7574
jg short loc_1001767E
jz near loc_100176D1
cmp eax, 0x65706e6f
jz near loc_100176C8
xor bl, bl
jmp loc_10017701
loc_1001767E:
cmp eax, 0x68616d6d
jg short loc_10017692
jz near loc_100176E3
cmp eax, 0x666d2020
jz near loc_100176DA
xor bl, bl
jmp loc_10017701
loc_10017692:
cmp eax, 0x70636d20
jz near loc_100176EC
cmp eax, 0x77617665
jz near loc_100176F5
xor bl, bl
jmp loc_10017701
loc_100176A4:
;push edi
;push esi
PUSH32 edi, esi
;call loc_100177E0
CALL loc_100177E0
jmp loc_100176FC
loc_100176AD:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017860
CALL loc_10017860
jmp loc_100176FC
loc_100176B6:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017880
CALL loc_10017880
jmp loc_100176FC
loc_100176BF:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017800
CALL loc_10017800
jmp loc_100176FC
loc_100176C8:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017890
CALL loc_10017890
jmp loc_100176FC
loc_100176D1:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017820
CALL loc_10017820
jmp loc_100176FC
loc_100176DA:
;push edi
;push esi
PUSH32 edi, esi
;call loc_100177C0
CALL loc_100177C0
jmp short loc_100176FC
loc_100176E3:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017840
CALL loc_10017840
jmp short loc_100176FC
loc_100176EC:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017720
CALL loc_10017720
jmp short loc_100176FC
loc_100176F5:
;push edi
;push esi
PUSH32 edi, esi
;call loc_10017770
CALL loc_10017770
loc_100176FC:
;add esp, 0x8
add r11d, 0x8
mov bl, al
loc_10017701:
;push ebx
PUSH32 ebx
mov eax, [esi+0x4]
;push edi
;push eax
PUSH32 edi, eax
;call loc_10008A70
CALL loc_10008A70
;add esp, 0xc
add r11d, 0xc
mov al, bl
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10017720:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push ebx
;push esi
PUSH32 ebx, esi
mov bl, 0x1
cmp dword [eax], 0x70636d20
jz short loc_10017735
xor al, al
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
loc_10017735:
mov ecx, [eax+0x4]
lea esi, [ecx+eax-0x18]
mov eax, [ecx+eax-0x10]
test eax, eax
jz short loc_10017756
;push eax
PUSH32 eax
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;push eax
PUSH32 eax
;call loc_100178A0
CALL loc_100178A0
;add esp, 0x8
add r11d, 0x8
test al, al
jnz short loc_1001775F
loc_10017756:
mov dword [esi+0x8], 0x0
xor bl, bl
loc_1001775F:
mov al, bl
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_10017770:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push ebx
;push esi
PUSH32 ebx, esi
mov bl, 0x1
cmp dword [eax], 0x77617665
jz short loc_10017785
xor al, al
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
loc_10017785:
mov ecx, [eax+0x4]
lea esi, [ecx+eax-0xc]
mov eax, [ecx+eax-0x4]
test eax, eax
jz short loc_100177A6
;push eax
PUSH32 eax
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;push eax
PUSH32 eax
;call loc_10017930
CALL loc_10017930
;add esp, 0x8
add r11d, 0x8
test al, al
jnz short loc_100177AF
loc_100177A6:
mov dword [esi+0x8], 0x0
xor bl, bl
loc_100177AF:
mov al, bl
;pop esi
;pop ebx
POP32 ebx, esi
;ret
RET
align 16
loc_100177C0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov eax, [eax]
sub eax, 0x666d2020
cmp eax, 0x1
sbb al, al
neg al
;ret
RET
align 16
loc_100177E0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov eax, [eax]
sub eax, 0x616e616c
cmp eax, 0x1
sbb al, al
neg al
;ret
RET
align 16
loc_10017800:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov eax, [eax]
sub eax, 0x636c6172
cmp eax, 0x1
sbb al, al
neg al
;ret
RET
align 16
loc_10017820:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov eax, [eax]
sub eax, 0x666c7574
cmp eax, 0x1
sbb al, al
neg al
;ret
RET
align 16
loc_10017840:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov eax, [eax]
sub eax, 0x68616d6d
cmp eax, 0x1
sbb al, al
neg al
;ret
RET
align 16
loc_10017860:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
mov eax, [eax]
sub eax, 0x626f7764
cmp eax, 0x1
sbb al, al
neg al
;ret
RET
align 16
loc_10017880:
xor al, al
;ret
RET
align 16
loc_10017890:
xor al, al
;ret
RET
align 16
loc_100178A0:
;mov eax, [esp+0x8]
mov eax, [r11d+0x8]
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
cmp dword [eax], 0x6d73616d
jz short loc_100178B7
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100178B7:
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;mov esi, [esp+0x14]
mov esi, [r11d+0x14]
;push eax
PUSH32 eax
mov ecx, [esi+0x1c]
;push ecx
PUSH32 ecx
;call loc_1000BE60
CALL loc_1000BE60
;add esp, 0x8
add r11d, 0x8
cmp eax, 0x1
sbb bl, bl
inc bl
jnz short loc_100178DC
xor al, al
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
loc_100178DC:
;mov ebp, [esp+0x18]
mov ebp, [r11d+0x18]
mov di, [ebp+0x3a]
add ebp, 0x3a
add ebp, 0x4
test di, di
jle short loc_10017914
loc_100178EF:
mov eax, [ebp+0x8]
test eax, eax
jz short loc_10017904
;push eax
;push esi
PUSH32 eax, esi
;call loc_10017930
CALL loc_10017930
;add esp, 0x8
add r11d, 0x8
test al, al
jnz short loc_1001790D
loc_10017904:
mov dword [ebp+0x8], 0x0
xor bl, bl
loc_1001790D:
add ebp, 0x12
dec di
jnz short loc_100178EF
loc_10017914:
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
;push ebx
;push eax
PUSH32 ebx, eax
mov ecx, [esi+0x4]
;push ecx
PUSH32 ecx
;call loc_10008A70
CALL loc_10008A70
;add esp, 0xc
add r11d, 0xc
mov al, 0x1
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;ret
RET
align 16
loc_10017930:
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
;mov edi, [esp+0x14]
mov edi, [r11d+0x14]
cmp dword [edi], 0x73616d70
jz short loc_10017945
xor al, al
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
loc_10017945:
cmp byte [edi+0x35], 0x0
;mov esi, [esp+0x10]
mov esi, [r11d+0x10]
jz short loc_10017954
mov eax, [esi+0x24]
jmp short loc_10017957
loc_10017954:
mov eax, [esi+0x20]
loc_10017957:
;push edi
;push eax
PUSH32 edi, eax
;call loc_1000BE60
CALL loc_1000BE60
;add esp, 0x8
add r11d, 0x8
cmp eax, 0x1
sbb bl, bl
mov eax, [esi+0x4]
inc bl
;push ebx
;push edi
;push eax
PUSH32 ebx, edi, eax
;call loc_10008A70
CALL loc_10008A70
;add esp, 0xc
add r11d, 0xc
mov al, bl
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;ret
RET
align 16
loc_10017980:
;sub esp, 0x14
sub r11d, 0x14
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x28]
mov esi, [r11d+0x28]
;push edi
PUSH32 edi
;mov edi, [esp+0x24]
mov edi, [r11d+0x24]
;push ebp
PUSH32 ebp
lea ebp, [esi+0x30]
;mov edx, [esp+0x2c]
mov edx, [r11d+0x2c]
mov eax, [edi]
;lea ecx, [esp+0x18]
lea ecx, [r11d+0x18]
mov ebx, [edx+0x4]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
mov eax, [edx]
mov edx, [edx+0x8]
mov [ecx], eax
mov [ecx+0x4], ebx
mov [ecx+0x8], edx
;mov ecx, [esp+0x2c]
mov ecx, [r11d+0x2c]
mov ebx, [ebp+0xe]
;add [esp+0x1c], ebx
add [r11d+0x1c], ebx
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
mov [ecx+0x4], eax
mov al, [edi+0x1d]
mov dl, [edi+0x1e]
;lea ecx, [esp+0x18]
lea ecx, [r11d+0x18]
;push edx
;push eax
PUSH32 edx, eax
;push 0x0
PUSH32 0x0
mov edx, [edi+0x8]
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;push ecx
;push edx
PUSH32 ecx, edx
mov ecx, [eax+0x24]
;push ecx
PUSH32 ecx
;call loc_1000BBD0
CALL loc_1000BBD0
;mov [esp+0x28], eax
mov [r11d+0x28], eax
;add esp, 0x18
add r11d, 0x18
test eax, eax
jnz near loc_10017A3F
mov eax, [edi+0x18]
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push eax
;push ecx
;push edx
PUSH32 eax, ecx, edx
;call loc_10016D00
CALL loc_10016D00
;add esp, 0xc
add r11d, 0xc
test al, al
jz short loc_10017A2E
mov al, [edi+0x1e]
mov cl, [edi+0x1d]
;lea edx, [esp+0x18]
lea edx, [r11d+0x18]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [edi+0x8]
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push 0x0
PUSH32 0x0
;push edx
;push eax
PUSH32 edx, eax
mov edx, [ecx+0x24]
;push edx
PUSH32 edx
;call loc_1000BBD0
CALL loc_1000BBD0
;mov [esp+0x28], eax
mov [r11d+0x28], eax
;add esp, 0x18
add r11d, 0x18
loc_10017A2E:
;cmp dword [esp+0x10], 0x0
cmp dword [r11d+0x10], 0x0
jnz short loc_10017A3F
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14
add r11d, 0x14
;ret
RET
loc_10017A3F:
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
;mov ecx, [esp+0x2c]
mov ecx, [r11d+0x2c]
;mov edx, [esp+0x10]
mov edx, [r11d+0x10]
add esi, 0x8
add edx, 0x8
mov [ecx+0x8], eax
mov eax, [esi-0x8]
mov ecx, [esi-0x4]
mov edi, edx
mov [edx-0x8], eax
mov [edx-0x4], ecx
add edx, 0x28
mov ecx, 0xa
;rep movsd
rep a32 movsd
mov edi, edx
mov esi, ebp
mov ecx, 0x6
add ebp, 0x1a
;rep movsd
rep a32 movsd
;movsw
a32 movsw
mov word [edx+0x2], 0x2
mov byte [edx+0x5], 0x1
add edx, 0x1a
test ebx, ebx
jle short loc_10017AA1
loc_10017A8D:
inc ebp
add edx, 0x2
movsx ax, byte [ebp-0x1]
shl ax, 0x8
dec ebx
mov [edx-0x2], ax
jnz short loc_10017A8D
loc_10017AA1:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x14
add r11d, 0x14
;ret
RET
align 16
loc_10017AB0:
;sub esp, 0x1c
sub r11d, 0x1c
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x34]
mov esi, [r11d+0x34]
;push edi
PUSH32 edi
;mov edi, [esp+0x2c]
mov edi, [r11d+0x2c]
;push ebp
PUSH32 ebp
lea ebp, [esi+0x30]
;mov cl, [esp+0x34]
mov cl, [r11d+0x34]
mov eax, [edi]
;mov edx, [esp+0x38]
mov edx, [r11d+0x38]
;mov [esp+0x18], eax
mov [r11d+0x18], eax
mov ebx, [edx+0x4]
mov ax, 0x1
shl ax, cl
;mov [esp+0x12], ax
mov [r11d+0x12], ax
;lea ecx, [esp+0x20]
lea ecx, [r11d+0x20]
mov eax, [edx]
mov edx, [edx+0x8]
mov [ecx], eax
mov [ecx+0x4], ebx
mov [ecx+0x8], edx
;movsx ecx, word [esp+0x12]
movsx ecx, word [r11d+0x12]
movsx edx, word [ebp+0x2]
mov eax, [ebp+0xe]
;mov [esp+0x14], ecx
mov [r11d+0x14], ecx
;mov [esp+0x1c], eax
mov [r11d+0x1c], eax
lea eax, [ecx*2]
sub eax, edx
mov cl, [edi+0x1e]
;push ecx
PUSH32 ecx
mov dl, [edi+0x1d]
;push edx
PUSH32 edx
mov ecx, [edi+0x8]
;mov edx, [esp+0x20]
mov edx, [r11d+0x20]
;push 0x0
PUSH32 0x0
;imul eax, [esp+0x28]
imul eax, [r11d+0x28]
;add [esp+0x30], eax
add [r11d+0x30], eax
;lea eax, [esp+0x2c]
lea eax, [r11d+0x2c]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [edx+0x24]
;push eax
PUSH32 eax
;call loc_1000BBD0
CALL loc_1000BBD0
;add esp, 0x18
add r11d, 0x18
mov ebx, eax
test ebx, ebx
jnz near loc_10017B8C
mov eax, [edi+0x18]
;mov ecx, [esp+0x24]
mov ecx, [r11d+0x24]
;mov edx, [esp+0x18]
mov edx, [r11d+0x18]
;push eax
;push ecx
;push edx
PUSH32 eax, ecx, edx
;call loc_10016D00
CALL loc_10016D00
;add esp, 0xc
add r11d, 0xc
test al, al
jz short loc_10017B7E
mov al, [edi+0x1e]
mov cl, [edi+0x1d]
;lea edx, [esp+0x20]
lea edx, [r11d+0x20]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [edi+0x8]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;push 0x0
PUSH32 0x0
;push edx
;push eax
PUSH32 edx, eax
mov edx, [ecx+0x24]
;push edx
PUSH32 edx
;call loc_1000BBD0
CALL loc_1000BBD0
;add esp, 0x18
add r11d, 0x18
mov ebx, eax
loc_10017B7E:
test ebx, ebx
jnz short loc_10017B8C
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x1c
add r11d, 0x1c
;ret
RET
loc_10017B8C:
;mov ecx, [esp+0x28]
mov ecx, [r11d+0x28]
;mov eax, [esp+0x38]
mov eax, [r11d+0x38]
add esi, 0x8
mov [eax+0x8], ecx
mov edx, [esi-0x8]
mov ecx, [esi-0x4]
mov [ebx], edx
lea edx, [ebx+0x8]
mov edi, edx
mov [ebx+0x4], ecx
mov ecx, 0xa
add edx, 0x28
;rep movsd
rep a32 movsd
mov edi, edx
mov esi, ebp
mov ecx, 0x6
;rep movsd
rep a32 movsd
;movsw
a32 movsw
mov word [edx+0x2], 0x2
mov byte [edx+0x5], 0x1
mov eax, [edx+0x6]
;imul eax, [esp+0x14]
imul eax, [r11d+0x14]
mov [edx+0x6], eax
mov eax, [edx+0xa]
;imul eax, [esp+0x14]
imul eax, [r11d+0x14]
mov [edx+0xa], eax
mov eax, [edx+0xe]
;imul eax, [esp+0x14]
imul eax, [r11d+0x14]
mov [edx+0xe], eax
mov eax, [edx+0x12]
;imul eax, [esp+0x14]
imul eax, [r11d+0x14]
mov [edx+0x12], eax
mov eax, [edx+0x16]
;imul eax, [esp+0x14]
imul eax, [r11d+0x14]
mov [edx+0x16], eax
mov ax, [ebp+0x2]
sub ax, 0x2
cmp ax, 0x1
sbb al, al
add ebp, 0x1a
neg al
add edx, 0x1a
;mov ecx, [esp+0x12]
mov ecx, [r11d+0x12]
;push edx
;push eax
PUSH32 edx, eax
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;push ebp
;push eax
;push ecx
PUSH32 ebp, eax, ecx
;call loc_10018020
CALL loc_10018020
;add esp, 0x14
add r11d, 0x14
mov eax, ebx
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x1c
add r11d, 0x1c
;ret
RET
align 16
loc_10017C40:
;sub esp, 0x18
sub r11d, 0x18
;push ebx
;push esi
PUSH32 ebx, esi
;mov esi, [esp+0x30]
mov esi, [r11d+0x30]
;push edi
PUSH32 edi
;mov edi, [esp+0x28]
mov edi, [r11d+0x28]
;push ebp
PUSH32 ebp
lea ecx, [esi+0x30]
;mov ebp, [esp+0x34]
mov ebp, [r11d+0x34]
mov eax, [edi]
;mov [esp+0x18], ecx
mov [r11d+0x18], ecx
;lea ecx, [esp+0x1c]
lea ecx, [r11d+0x1c]
mov edx, [ebp+0x4]
mov ebx, [ebp+0x8]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
mov eax, [ebp]
mov [ecx], eax
;mov eax, [esp+0x18]
mov eax, [r11d+0x18]
mov [ecx+0x4], edx
mov [ecx+0x8], ebx
mov ebx, [eax+0xe]
;add [esp+0x20], ebx
add [r11d+0x20], ebx
;mov eax, [esp+0x20]
mov eax, [r11d+0x20]
mov [ebp+0x4], eax
;lea eax, [esp+0x1c]
lea eax, [r11d+0x1c]
mov cl, [edi+0x1e]
mov dl, [edi+0x1d]
;push ecx
;push edx
PUSH32 ecx, edx
;push 0x0
PUSH32 0x0
mov ecx, [edi+0x8]
;mov edx, [esp+0x20]
mov edx, [r11d+0x20]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [edx+0x24]
;push eax
PUSH32 eax
;call loc_1000BBD0
CALL loc_1000BBD0
;mov [esp+0x28], eax
mov [r11d+0x28], eax
;add esp, 0x18
add r11d, 0x18
test eax, eax
jnz near loc_10017D04
mov eax, [edi+0x18]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push eax
;push ecx
;push edx
PUSH32 eax, ecx, edx
;call loc_10016D00
CALL loc_10016D00
;add esp, 0xc
add r11d, 0xc
test al, al
jz short loc_10017CF3
mov al, [edi+0x1e]
mov cl, [edi+0x1d]
;lea edx, [esp+0x1c]
lea edx, [r11d+0x1c]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [edi+0x8]
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push 0x0
PUSH32 0x0
;push edx
;push eax
PUSH32 edx, eax
mov edx, [ecx+0x24]
;push edx
PUSH32 edx
;call loc_1000BBD0
CALL loc_1000BBD0
;mov [esp+0x28], eax
mov [r11d+0x28], eax
;add esp, 0x18
add r11d, 0x18
loc_10017CF3:
;cmp dword [esp+0x10], 0x0
cmp dword [r11d+0x10], 0x0
jnz short loc_10017D04
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x18
add r11d, 0x18
;ret
RET
loc_10017D04:
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
;mov edx, [esp+0x10]
mov edx, [r11d+0x10]
add esi, 0x8
mov [ebp+0x8], eax
mov ebp, [esi-0x8]
mov ecx, [esi-0x4]
mov [edx], ebp
lea ebp, [edx+0x8]
mov edi, ebp
mov [edx+0x4], ecx
mov ecx, 0xa
add ebp, 0x28
;rep movsd
rep a32 movsd
mov edi, ebp
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
mov ecx, 0x6
;rep movsd
rep a32 movsd
;movsw
a32 movsw
mov word [ebp+0x2], 0x2
;mov eax, [esp+0x30]
mov eax, [r11d+0x30]
;mov ecx, [esp+0x14]
mov ecx, [r11d+0x14]
mov byte [ebp+0x4], 0x0
mov byte [ebp+0x5], 0x1
;push eax
PUSH32 eax
mov edx, [ecx+0xc]
;push 0x0
PUSH32 0x0
;push 0x1
PUSH32 0x1
;push edx
PUSH32 edx
add ebp, 0x1a
;call loc_10017210
CALL loc_10017210
;mov edi, [esp+0x28]
mov edi, [r11d+0x28]
;add esp, 0x10
add r11d, 0x10
mov esi, eax
add edi, 0x1a
test ebx, ebx
jle short loc_10017D8D
loc_10017D72:
mov eax, edi
add ebp, 0x2
movsx ax, byte [eax]
inc edi
;push eax
;push esi
PUSH32 eax, esi
;call loc_10017310
CALL loc_10017310
mov [ebp-0x2], ax
;add esp, 0x8
add r11d, 0x8
dec ebx
jnz short loc_10017D72
loc_10017D8D:
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x18
add r11d, 0x18
;ret
RET
align 16
loc_10017DA0:
;sub esp, 0x34
sub r11d, 0x34
;push ebx
;push esi
;push edi
PUSH32 ebx, esi, edi
xor ebx, ebx
;mov esi, [esp+0x54]
mov esi, [r11d+0x54]
;push ebp
PUSH32 ebp
;mov ebp, [esp+0x48]
mov ebp, [r11d+0x48]
;mov [esp+0x11], bl
mov [r11d+0x11], bl
lea ecx, [esi+0x30]
;mov edi, [esp+0x54]
mov edi, [r11d+0x54]
mov eax, [ebp]
;mov [esp+0x2c], ebx
mov [r11d+0x2c], ebx
mov edx, [edi+0x4]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
mov eax, [edi]
;mov [esp+0x18], ecx
mov [r11d+0x18], ecx
;lea ecx, [esp+0x30]
lea ecx, [r11d+0x30]
mov [ecx], eax
mov eax, [edi+0x8]
mov [ecx+0x4], edx
mov [ecx+0x8], eax
;mov ecx, [esp+0x18]
mov ecx, [r11d+0x18]
mov ax, [ecx+0x2]
mov edx, [ecx+0xe]
test ax, ax
;mov [esp+0x20], edx
mov [r11d+0x20], edx
movsx ecx, ax
jle short loc_10017DFD
mov eax, edx
imul eax, ecx
jmp short loc_10017E07
loc_10017DFD:
mov eax, ecx
;sub eax, [esp+0x20]
sub eax, [r11d+0x20]
inc eax
cdq
idiv ecx
loc_10017E07:
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
add ecx, ecx
sub ecx, eax
;add [esp+0x34], ecx
add [r11d+0x34], ecx
;mov eax, [esp+0x34]
mov eax, [r11d+0x34]
mov [edi+0x4], eax
;lea eax, [esp+0x30]
lea eax, [r11d+0x30]
mov dl, [ebp+0x1e]
mov cl, [ebp+0x1d]
;push edx
;push ecx
PUSH32 edx, ecx
;push 0x0
PUSH32 0x0
mov edx, [ebp+0x8]
;mov ecx, [esp+0x20]
mov ecx, [r11d+0x20]
;push eax
;push edx
PUSH32 eax, edx
mov eax, [ecx+0x24]
;push eax
PUSH32 eax
;call loc_1000BBD0
CALL loc_1000BBD0
;mov [esp+0x34], eax
mov [r11d+0x34], eax
;add esp, 0x18
add r11d, 0x18
test eax, eax
jnz near loc_10017E97
mov eax, [ebp+0x18]
;mov ecx, [esp+0x34]
mov ecx, [r11d+0x34]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push eax
;push ecx
;push edx
PUSH32 eax, ecx, edx
;call loc_10016D00
CALL loc_10016D00
;add esp, 0xc
add r11d, 0xc
test al, al
jz short loc_10017E86
mov al, [ebp+0x1e]
mov cl, [ebp+0x1d]
;lea edx, [esp+0x30]
lea edx, [r11d+0x30]
;push eax
;push ecx
PUSH32 eax, ecx
mov eax, [ebp+0x8]
;mov ecx, [esp+0x1c]
mov ecx, [r11d+0x1c]
;push 0x0
PUSH32 0x0
;push edx
;push eax
PUSH32 edx, eax
mov edx, [ecx+0x24]
;push edx
PUSH32 edx
;call loc_1000BBD0
CALL loc_1000BBD0
;mov [esp+0x34], eax
mov [r11d+0x34], eax
;add esp, 0x18
add r11d, 0x18
loc_10017E86:
;cmp dword [esp+0x1c], 0x0
cmp dword [r11d+0x1c], 0x0
jnz short loc_10017E97
xor eax, eax
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x34
add r11d, 0x34
;ret
RET
loc_10017E97:
;mov eax, [esp+0x38]
mov eax, [r11d+0x38]
;mov edx, [esp+0x1c]
mov edx, [r11d+0x1c]
add esi, 0x8
mov [edi+0x8], eax
mov ebp, [esi-0x8]
mov ecx, [esi-0x4]
mov [edx], ebp
lea ebp, [edx+0x8]
mov edi, ebp
mov [edx+0x4], ecx
mov ecx, 0xa
add ebp, 0x28
;rep movsd
rep a32 movsd
mov edi, ebp
;mov esi, [esp+0x18]
mov esi, [r11d+0x18]
mov ecx, 0x6
;rep movsd
rep a32 movsd
;movsw
a32 movsw
mov word [ebp+0x2], 0x2
;mov eax, [esp+0x50]
mov eax, [r11d+0x50]
;mov ecx, [esp+0x4c]
mov ecx, [r11d+0x4c]
;mov edx, [esp+0x14]
mov edx, [r11d+0x14]
;push eax
PUSH32 eax
mov byte [ebp+0x4], 0x0
mov byte [ebp+0x5], 0x1
;push ecx
PUSH32 ecx
mov eax, [edx+0xc]
;push 0x2
PUSH32 0x2
;push eax
PUSH32 eax
add ebp, 0x1a
;call loc_10017210
CALL loc_10017210
;mov edi, [esp+0x28]
mov edi, [r11d+0x28]
;mov [esp+0x4c], eax
mov [r11d+0x4c], eax
;add esp, 0x10
add r11d, 0x10
add edi, 0x1a
;movsx eax, word [esp+0x4c]
movsx eax, word [r11d+0x4c]
;mov [esp+0x14], eax
mov [r11d+0x14], eax
mov eax, 0x10
cdq
;idiv dword [esp+0x14]
idiv dword [r11d+0x14]
mov dx, 0x1
mov cl, al
shl dx, cl
dec dx
xor esi, esi
;mov [esp+0x12], ax
mov [r11d+0x12], ax
mov ax, 0x1
;mov cl, [esp+0x12]
mov cl, [r11d+0x12]
dec cl
shl ax, cl
;mov [esp+0x24], ax
mov [r11d+0x24], ax
;cmp [esp+0x20], esi
cmp [r11d+0x20], esi
jle near loc_10018009
;mov ax, [esp+0x4c]
mov ax, [r11d+0x4c]
sar ax, 0x1
movsx ecx, ax
mov al, 0x8
;mov [esp+0x14], ecx
mov [r11d+0x14], ecx
movzx ecx, dx
;sub al, [esp+0x12]
sub al, [r11d+0x12]
;mov [esp+0x28], ecx
mov [r11d+0x28], ecx
;mov [esp+0x18], al
mov [r11d+0x18], al
;mov eax, [esp+0x24]
mov eax, [r11d+0x24]
and eax, 0xffff
;mov [esp+0x24], eax
mov [r11d+0x24], eax
loc_10017F75:
mov eax, esi
cdq
;idiv dword [esp+0x14]
idiv dword [r11d+0x14]
test edx, edx
jnz short loc_10017F87
mov al, [edi]
inc edi
;mov [esp+0x11], al
mov [r11d+0x11], al
loc_10017F87:
;mov al, [esp+0x11]
mov al, [r11d+0x11]
;mov cl, [esp+0x18]
mov cl, [r11d+0x18]
sar al, cl
movsx edx, al
;and edx, [esp+0x28]
and edx, [r11d+0x28]
;test [esp+0x24], edx
test [r11d+0x24], edx
jz short loc_10017FA6
;mov eax, [esp+0x28]
mov eax, [r11d+0x28]
not eax
or edx, eax
loc_10017FA6:
;mov cl, [esp+0x12]
mov cl, [r11d+0x12]
;push edx
PUSH32 edx
;mov eax, [esp+0x40]
mov eax, [r11d+0x40]
add ebp, 0x2
;push eax
PUSH32 eax
inc esi
;shl byte [esp+0x19], cl
shl byte [r11d+0x19], cl
;call loc_10017310
CALL loc_10017310
;mov [esp+0x48], ebx
mov [r11d+0x48], ebx
;add esp, 0x8
add r11d, 0x8
movsx eax, ax
;add eax, [esp+0x2c]
add eax, [r11d+0x2c]
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
movsx ebx, ax
;add esp, 0x4
add r11d, 0x4
lea eax, [ebx*2]
;sub eax, [esp+0x40]
sub eax, [r11d+0x40]
;push eax
PUSH32 eax
;call loc_10006390
CALL loc_10006390
movsx ecx, ax
;mov [esp+0x30], ecx
mov [r11d+0x30], ecx
;add esp, 0x4
add r11d, 0x4
;push ebx
PUSH32 ebx
;call loc_10006390
CALL loc_10006390
mov [ebp-0x2], ax
;add esp, 0x4
add r11d, 0x4
;cmp [esp+0x20], esi
cmp [r11d+0x20], esi
jg near loc_10017F75
loc_10018009:
;mov eax, [esp+0x1c]
mov eax, [r11d+0x1c]
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x34
add r11d, 0x34
;ret
RET
align 16
loc_10018020:
;sub esp, 0x11c
sub r11d, 0x11c
xor eax, eax
xor ecx, ecx
;push ebx
;push esi
;push edi
;push ebp
PUSH32 ebx, esi, edi, ebp
loc_1001802E:
movsx edx, ax
inc ax
;mov [esp+edx*2+0x1c], cx
mov [r11d+edx*2+0x1c], cx
cmp ax, 0x4
jl short loc_1001802E
xor di, di
;mov si, [esp+0x130]
mov si, [r11d+0x130]
cmp si, di
jle short loc_1001807E
loc_1001804E:
movsx eax, di
xor bx, bx
lea ebp, [eax*4]
loc_1001805B:
;push esi
;push ebx
;push edi
PUSH32 esi, ebx, edi
;call loc_100181D0
CALL loc_100181D0
movsx eax, bx
inc bx
;add esp, 0xc
add r11d, 0xc
add eax, ebp
;fstp qword [esp+eax*8+0x2c]
fstp qword [r11d+eax*8+0x2c]
cmp bx, 0x4
jl short loc_1001805B
inc di
cmp di, si
jl short loc_1001804E
loc_1001807E:
;mov dword [esp+0x10], 0x0
mov dword [r11d+0x10], 0x0
;mov eax, [esp+0x134]
mov eax, [r11d+0x134]
inc eax
;mov [esp+0x24], eax
mov [r11d+0x24], eax
test eax, eax
jle near loc_100181BC
movsx eax, si
mov edi, eax
;mov [esp+0x28], eax
mov [r11d+0x28], eax
neg edi
loc_100180A5:
xor dx, dx
loc_100180A8:
movsx eax, dx
inc dx
add eax, eax
;mov cx, [esp+eax+0x1e]
mov cx, [r11d+eax+0x1e]
;mov [esp+eax+0x1c], cx
mov [r11d+eax+0x1c], cx
cmp dx, 0x3
jl short loc_100180A8
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;cmp eax, [esp+0x134]
cmp eax, [r11d+0x134]
jge short loc_100180FB
;cmp byte [esp+0x13c], 0x0
cmp byte [r11d+0x13c], 0x0
;mov eax, [esp+0x138]
mov eax, [r11d+0x138]
jz short loc_100180EA
;add dword [esp+0x138], 0x2
add dword [r11d+0x138], 0x2
mov ax, [eax]
jmp short loc_10018100
loc_100180EA:
movsx ax, byte [eax]
shl ax, 0x8
;inc dword [esp+0x138]
inc dword [r11d+0x138]
jmp short loc_10018100
loc_100180FB:
;mov ax, [esp+0x20]
mov ax, [r11d+0x20]
loc_10018100:
;cmp dword [esp+0x10], 0x1
cmp dword [r11d+0x10], 0x1
;mov [esp+0x22], ax
mov [r11d+0x22], ax
jl near loc_100181A6
xor bp, bp
test si, si
jle near loc_100181A6
fld qword [loc_10019D38]
fld qword [loc_10019D40]
loc_10018128:
;mov dword [esp+0x14], 0x0
mov dword [r11d+0x14], 0x0
;mov dword [esp+0x18], 0x0
mov dword [r11d+0x18], 0x0
;fld qword [esp+0x14]
fld qword [r11d+0x14]
movsx ebx, bp
xor cx, cx
loc_10018142:
movsx eax, cx
inc cx
;movsx edx, word [esp+eax*2+0x1c]
movsx edx, word [r11d+eax*2+0x1c]
cmp cx, 0x4
lea eax, [eax+ebx*4]
;mov [esp+0x14], edx
mov [r11d+0x14], edx
;fild dword [esp+0x14]
fild dword [r11d+0x14]
;fmul qword [esp+eax*8+0x2c]
fmul qword [r11d+eax*8+0x2c]
faddp st1, st0
jl short loc_10018142
;fst qword [esp+0x14]
fst qword [r11d+0x14]
fcomp st0, st2
fnstsw ax
test ah, 0x1
jz short loc_10018176
mov ax, 0x8000
jmp short loc_1001818E
loc_10018176:
;fcom qword [esp+0x14]
fcom qword [r11d+0x14]
fnstsw ax
test ah, 0x41
mov ax, 0x7fff
jnz short loc_1001818E
;fld qword [esp+0x14]
fld qword [r11d+0x14]
;call _ftol_asm
CALL _ftol_asm
loc_1001818E:
inc bp
add ebx, edi
cmp bp, si
;mov ecx, [esp+0x140]
mov ecx, [r11d+0x140]
mov [ecx+ebx*2], ax
jl near loc_10018128
fstp st0
fstp st0
loc_100181A6:
;add edi, [esp+0x28]
add edi, [r11d+0x28]
;inc dword [esp+0x10]
inc dword [r11d+0x10]
;mov eax, [esp+0x10]
mov eax, [r11d+0x10]
;cmp eax, [esp+0x24]
cmp eax, [r11d+0x24]
jl near loc_100180A5
loc_100181BC:
;pop ebp
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi, ebp
;add esp, 0x11c
add r11d, 0x11c
;ret
RET
align 16
loc_100181D0:
;sub esp, 0x8
sub r11d, 0x8
;mov cx, [esp+0xc]
mov cx, [r11d+0xc]
;push ebx
PUSH32 ebx
;mov dx, [esp+0x14]
mov dx, [r11d+0x14]
;push esi
PUSH32 esi
;mov si, [esp+0x1c]
mov si, [r11d+0x1c]
;push edi
PUSH32 edi
xor edi, edi
;mov [esp+0xc], edi
mov [r11d+0xc], edi
;mov dword [esp+0x10], 0x3ff00000
mov dword [r11d+0x10], 0x3ff00000
;fld qword [esp+0xc]
fld qword [r11d+0xc]
fld qword [loc_10019D48]
loc_100181FD:
cmp di, dx
jz short loc_10018234
movsx ebx, di
movsx eax, cx
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;fild dword [esp+0xc]
fild dword [r11d+0xc]
movsx eax, si
;mov [esp+0xc], eax
mov [r11d+0xc], eax
;fidiv dword [esp+0xc]
fidiv dword [r11d+0xc]
movsx eax, dx
sub eax, ebx
;mov [esp+0xc], ebx
mov [r11d+0xc], ebx
;fisub dword [esp+0xc]
fisub dword [r11d+0xc]
;mov [esp+0xc], eax
mov [r11d+0xc], eax
fadd st0, st1
;fidiv dword [esp+0xc]
fidiv dword [r11d+0xc]
fmulp st2, st0
loc_10018234:
inc di
cmp di, 0x4
jl short loc_100181FD
fstp st0
;fst qword [esp+0xc]
fst qword [r11d+0xc]
;pop edi
;pop esi
;pop ebx
POP32 ebx, esi, edi
;add esp, 0x8
add r11d, 0x8
;ret
RET
