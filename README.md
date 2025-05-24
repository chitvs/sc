# Assembly/C programming exercises

This repository contains a collection of Assembly IA-32 programming exercises taken from my university exams. Each exercise is neatly organized within its dedicated folder, encompassing both the source code and pertinent documentation.
The exercises are provided in chronological order based on their exam date, providing a structured approach for study and review sessions.

This compilation serves as a valuable resource for students aiming to strengthen their understanding of Assembly programming concepts and prepare for examinations effectively.

## How to compile and run

Navigate to the exercise directory and use `gcc` to compile the ASM file. For example:

```sh
cd src/"year"/"month"/"version X"/"exercise X"/
gcc -g -m32 -o eX eX.s eX_main.c
./eX
```