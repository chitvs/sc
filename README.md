# Assembly/C programming exercises

This repository contains a collection of Assembly IA-32 programming exercises taken from my university exams. Each exercise is neatly organized within its dedicated folder, encompassing both the source code and pertinent documentation.
The exercises are provided in chronological order based on their exam date, providing a structured approach for study and review sessions.

This compilation serves as a valuable resource for students aiming to strengthen their understanding of Assembly programming concepts and prepare for examinations effectively.

## How to compile and run

Clone the repository:
```sh
git clone https://github.com/chitvs/sc.git
cd sc
```

### Exams

Navigate to the `exams` directory and use `gcc` to compile the ASM/C file. For example:

#### E1 - Assembly

```sh
cd src/exams/<year>/<month>/<session>/e1/
gcc -g -m32 -o e1 e1.s e1_main.c
./e1
```

#### E2 - C

```sh
cd src/exams/<year>/<month>/<session>/e2/
gcc -g -o e2 e2.s e2_main.c
./e2
```
> [!NOTE]  
> If your folder structure does not include multiple sessions, you can skip the `<session>` placeholder.

### Exercises

Navigate to the `exercises` directory and use `gcc` to compile the ASM/C file, following the same process as described for the exams.