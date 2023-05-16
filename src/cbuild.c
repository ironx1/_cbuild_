//
// Created by akaan on 10.05.2023.
//

#include <cbuild.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define isNullM if(argv == NULL)
static void cbuild_runExecutable(){
    FILE *run;
    if (!fopen_s(&run, "BUILD\\run.bat","w")){
        fprintf_s(run, "%s\n", "@echo off");
        fprintf_s(run, "%s", "..\\BIN\\main.exe");
    }else perror("Error");
}

void cbuild_buildObjects(char *argv[], int argc){
    isNullM return;
    FILE *objects;
    int tmp;
    if(!fopen_s(&objects, "BUILD\\compile.bat", "w")){
        fprintf_s(objects, "%s\n", "@echo off");
        fprintf_s(objects, "%s\n", "mkdir OBJ");
        int j = 0;
        for (int i = 1; i < argc; ++i) {
            if((argv[i])[0] == '-') continue;
            if(!strcmp(argv[i], "-lstatic") || !strcmp(argv[i], "-lshared")) {
                i++;
                continue;
            }
            fprintf_s(objects, "%s ", "gcc -c");
            fprintf_s(objects, "..\\%s ", argv[i]);
            fprintf_s(objects, "%s ", "-o");
            fprintf_s(objects,"OBJ\\%s.o\n",vector->array[j++]);
        }
        fclose(objects);

    }else perror("Error"), fclose(objects);
}

void cbuild_buildExecutable(char *argv[], int argc){
    isNullM return;
    FILE *executable;
    int j = 0;
    if(!fopen_s(&executable, "BUILD\\build-e.bat", "w")){
        fprintf_s(executable, "%s\n", "@echo off");
        fprintf_s(executable, "%s\n", "call compile.bat");
        fprintf_s(executable, "%s\n", "mkdir ..\\BIN");
        fprintf_s(executable, "%s ","gcc -o ..\\BIN\\main.exe");
        for (int i = 1; i < argc; ++i) {
            if((argv[i])[0] == '-') continue;
            if(!strcmp(argv[i], "-lstatic") || !strcmp(argv[i], "-lshared")) {
                i++;
                continue;
            }
            fprintf_s(executable, "OBJ\\%s.o ", vector->array[j++]);
        }
        fprintf_s(executable, "\n%s", "call run.bat");
        cbuild_runExecutable();
    }else perror("Error");
}

