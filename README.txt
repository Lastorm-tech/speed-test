#speed-test / unmangling
- compile it using/modifying script : exec.sh
- clean all your results/cores using script : clean.sh
- all results will be drop inside results folder

/!\ important :
- always name your test-case, with 1st argument when calling exec.sh
* e.g : ./exec.sh string_assign_test
- do not touch code/perfC98.cxx, it'll be updated.
- write your tests inside : code/write_test_here.h
* both tests T1 and T2 with their shared or static argument below @GENS 
- for unmangling purpose put your mangled name as follow : ./exec.sh x MANGLEDNAME

