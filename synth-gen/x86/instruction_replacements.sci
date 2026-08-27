loc_10001D43,26,; remove useless call to sprintf
loc_1000254D,24,; remove useless call to sprintf
loc_10002830,206,xor eax, eax ; remove useless calculation
loc_100060F8,10,; remove useless check
loc_10006106,6,; remove useless check
loc_10006156,10,; remove useless check
loc_10006169,11,; remove useless check
loc_10006FB5,35,mov eax, 1; skip check for the task-switched (TS) flag in the CR0 register
loc_10006FEC,29,; skip restoring the task-switched (TS) flag in the CR0 register

loc_100010F1,2,mov eax, 1 ; allow output type 2
loc_10001139,2,jmp short loc_1000112E ; allow output type 2

loc_10003BEC,1,xor edx, edx ; fix treating address as signed number
loc_10006558,1,xor edx, edx ; fix treating address as signed number
loc_1000657C,1,xor edx, edx ; fix treating address as signed number
loc_100065A3,1,xor edx, edx ; fix treating address as signed number
loc_100065C8,1,xor edx, edx ; fix treating address as signed number
loc_10006935,1,xor edx, edx ; fix treating address as signed number
loc_1000695D,1,xor edx, edx ; fix treating address as signed number
loc_10006981,1,xor edx, edx ; fix treating address as signed number

loc_10005ADB,4,mov ebx, ecx ; fix overwriting input string

loc_10016343,2,mov ecx, [eax+8]|cmp dword [ecx+8], 0|jnz loc_1001634E|push byte 0 ; skip waiting if thread procedure is quitting
loc_1001701B,7,cmp dword [edi+8], 0|jnz loc_10017036|mov dword [edi+8], 1 ; skip waiting if thread procedure is quitting
loc_10017036,2,loc_10017036:|mov eax, [edi] ; skip waiting if thread procedure is quitting

loc_100042A2,7,mov edi, [esp+0xd4]|mov edx, [cs_volume_multiplier]|cmp edx, 0x800|je short loc_100042A9|sar edx, cl|loc_100042A9_1:|mov ecx, [esi]|add esi, 0x4|imul ecx, edx|sar ecx, 11|cmp ecx, 0x7fff|jle short loc_100042A9_2|mov cx, 0x7fff|jmp short loc_100042A9_3|loc_100042A9_2:|cmp ecx, 0xffff8000|jge short loc_100042A9_3|mov cx, 0x8000|loc_100042A9_3:|mov [edi], cx|add edi, 0x2|dec eax|jnz short loc_100042A9_1|jmp short loc_100042B9 ; volume gain

loc_100075E0,5,and eax, 0xffff|mov edx, [cs_volume_multiplier]|cmp edx, 0x800|je short loc_100075E0_2|dec eax|xchg eax, ecx|sar edx, cl|movd mm7, edx|punpcklwd mm7, mm7|punpckldq mm7, mm7|loc_100075E0_1:|movq mm0, [esi]|movq mm1, mm0|pmullw mm0, mm7|pmulhw mm1, mm7|movq mm2, mm0|punpcklwd mm0, mm1|punpckhwd mm2, mm1|psrad mm0, 11|psrad mm2, 11|packssdw mm0, mm2|movq [edi], mm0|add edi, 0x8|add esi, 0x8|sub eax, 0x4|jg short loc_100075E0_1|jmp short loc_10007609|loc_100075E0_2: ; volume gain
loc_10007609,2,loc_10007609:|emms ; volume gain
