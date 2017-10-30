#!/bin/sh

#arg is test name

##-std=c++98

g++ -D 'T1' -Wno-deprecated -fno-strict-aliasing -Wno-write-strings -I./include -I/include -fPIC -g  -D__64BITS__ -fPIC -O3 -Wall -Wno-unused -pipe -D__WORKAROUND_GLIBC_BUG__ code/perfC98.cxx -o results/perfC98_$1; ./results/perfC98_$1 > results/T1/chrono/chrono_$1.res;
g++ -D 'T2' -Wno-deprecated -fno-strict-aliasing -Wno-write-strings -I./include -I/include -fPIC -g  -D__64BITS__ -fPIC -O3 -Wall -Wno-unused -pipe -D__WORKAROUND_GLIBC_BUG__ code/perfC98.cxx -o results/perfC98_$1; ./results/perfC98_$1 > results/T2/chrono/chrono_$1.res;

g++ -D 'T1' -O2 -S code/perfC98.cxx -o results/T1/asm/asm_$1.s;
g++ -D 'T2' -O2 -S code/perfC98.cxx -o results/T2/asm/asm_$1.s;

echo '----------------------------' > results/result_$1.res;
echo '############ speed part   : ' >> results/result_$1.res;
diff -c results/T1/chrono/chrono_$1.res results/T2/chrono/chrono_$1.res >> results/result_$1.res;
echo '----------------------------' >> results/result_$1.res;
echo '############ asm part     : ' >> results/result_$1.res;
diff -c results/T1/asm/asm_$1.s results/T2/asm/asm_$1.s >> results/result_$1.res;
echo '----------------------------' >> results/result_$1.res;
echo '############ class hierarchy : ' >> results/result_$1.res;
g++ -fdump-class-hierarchy code/perfC98.cxx >> results/result_$1.res;

#delete useless files
rm a.out perfC98.cxx.002t.class results/perfC98_$1;