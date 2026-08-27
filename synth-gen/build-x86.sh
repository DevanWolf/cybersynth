#! /bin/sh
cd "`echo $0 | sed 's/\/[^\/]*$//'`"
cp x86/*.sci ./
./SRW.exe CyberSyn.dll-original CyberSyn.asm >a.a 2>b.a
rm *.sci
./compact_source.py
rm *.a
rm CyberSyn.def
rm CyberSyn.resdump
