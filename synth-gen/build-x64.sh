#! /bin/sh
cd "`echo $0 | sed 's/\/[^\/]*$//'`"
cp x64/*.sci ./
./SRW.exe CyberSyn.dll-original CyberSyn.asm >a.a 2>b.a
rm *.sci
./compact_source.py
nasm CyberSyn.asm -felf64 -Ox -w+orphan-labels -w-number-overflow -i../synth/x64 -o CyberSyn.o 2>a.a
./repair_short_jumps.py
nasm CyberSyn.asm -felf64 -Ox -w+orphan-labels -w-number-overflow -i../synth/x64 -o CyberSyn.o 2>a.a
./repair_short_jumps.py
rm *.a
rm CyberSyn.def
rm CyberSyn.resdump
