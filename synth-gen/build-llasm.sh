#! /bin/sh
cd "`echo $0 | sed 's/\/[^\/]*$//'`"
cp llasm/*.sci ./
./SRW.exe CyberSyn.dll-original CyberSyn.llasm >a.a 2>b.a
rm *.sci
./compact_source_llasm.py
rm *.a
rm CyberSyn.resdump
