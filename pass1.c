/*

Pass one of two pass assembler

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f1, *f2, *f3, *f4;
char str1[20], str2[20], str3[20], opcode[20], value[20];
int flag=0, start, n;

int main(){
    
    f1 = fopen("assembly.txt", "r");
    f2 = fopen("symtab.txt", "w");
    f3 = fopen("intermediate.txt", "w");

    fscanf(f1, "%s%s%s", str1, str2, str3);
    if(strcmp(str2, "START") == 0){
        start = atoi(str3);
        n = start;
        fprintf(f3, "%s\t%s\t%s\n", str1, str2, str3);
    }
    while(strcmp(str2, "END") != 0){
        flag = 0;
        fscanf(f1, "%s%s%s", str1, str2, str3);
        f4 = fopen("optab.txt", "r");
        while(fscanf(f4, "%s%s", opcode, value) != EOF){
            if(strcmp(opcode, str2) == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("ERROR: opcode not found\n");
        }
        fclose(f4);
        fprintf(f3, "%d\t%s\t%s\t%s\n", start, str1, str2, str3);

        if(strcmp("**", str1) != 0){
            fprintf(f2, "%s\t%d\n", str1, start);
        }
        if(strcmp("RESW", str2) == 0){
            start += (3 * atoi(str3));
        }
        else if(strcmp("RESB", str2) == 0){
            start += atoi(str3);
        }
        else{
            start += 3;
        }
    }
    printf("\nLength of program = %d", start - n - 3);
    fclose(f1);
    fclose(f2);
    fclose(f3);


    return 0;

}
