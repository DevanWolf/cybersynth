loc_10001D43,26,; remove useless call to sprintf
loc_1000254D,24,; remove useless call to sprintf
loc_10002830,206,;xor eax, eax|mov eax, 0 ; remove useless calculation
loc_100060F8,10,; remove useless check
loc_10006106,6,; remove useless check
loc_10006156,10,; remove useless check
loc_10006169,11,; remove useless check
loc_10006FB5,35,;mov eax, 1|mov eax, 1; skip check for the task-switched (TS) flag in the CR0 register
loc_10006FEC,29,; skip restoring the task-switched (TS) flag in the CR0 register

loc_100010F1,2,;mov eax, 1|mov eax, 1 ; allow output type 2
loc_10001139,2,;jmp short loc_1000112E|tcall loc_1000112E|endp|proc loc_1000113B ; allow output type 2

loc_10003BEC,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number
loc_10006558,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number
loc_1000657C,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number
loc_100065A3,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number
loc_100065C8,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number
loc_10006935,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number
loc_1000695D,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number
loc_10006981,1,;xor edx, edx|mov edx, 0 ; fix treating address as signed number

loc_10005ADB,4,;mov ebx, ecx|mov ebx, ecx ; fix overwriting input string

loc_10016343,2,;mov ecx, [eax+8]|add tmpadr, eax, 8|load tmp1, tmpadr, 1|;cmp dword [ecx+8], 0|add tmpadr, tmp1, 8|load tmp1, tmpadr, 1|;jnz loc_1001634E|ctcallnz tmp1, loc_1001634E|tcall loc_10016343_2|endp|proc loc_10016343_2|;push byte 0|PUSH 0 ; skip waiting if thread procedure is quitting
loc_1001701B,7,;cmp dword [edi+8], 0|add tmpadr, edi, 8|load tmp1, tmpadr, 1|;jnz loc_10017036|ctcallnz tmp1, loc_10017036|tcall loc_1001701B_2|endp|proc loc_1001701B_2|;mov dword [edi+8], 1|add tmpadr, edi, 8|mov tmp1, 1|store tmp1, tmpadr, 1 ; skip waiting if thread procedure is quitting
loc_10017036,2,;loc_10017036:|;mov eax, [edi]|load eax, edi, 1 ; skip waiting if thread procedure is quitting

loc_100042A2,7,;mov edi, [esp+0xd4]|add tmpadr, esp, 212|load edi, tmpadr, 4|load edx, cs_volume_multiplier, 4|sub tmpcnd, edx, 0x800|ctcallz tmpcnd, loc_100042A9|tcall loc_100042A9_0|endp|proc loc_100042A9_0|and tmp2, ecx, 0x1f|ashr edx, edx, tmp2|tcall loc_100042A9_1|endp|proc loc_100042A9_1|load ecx, esi, 1|add esi, esi, 4|mul ecx, ecx, edx|ashr ecx, ecx, 11|cmovsgt ecx, 0x7fff, ecx, 0x7fff, ecx|cmovslt ecx, -0x8000, ecx, -0x8000, ecx|store16 ecx, edi, 1|add edi, edi, 2|sub eax, eax, 1|mov tmpcnd, eax|ctcallnz tmpcnd, loc_100042A9_1|tcall loc_100042A9|endp ; volume gain

loc_1000700D,21,; skip MMX detection
