/*

To implement Pass Two of Two Pass Assembler

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FILE *f1, *f2, *f3, *f4, *f5;
char str1[20], str2[20], str3[20], ch[20], opcode[20], value[20], symb[20], symbvalue[20];
int flag=0;
int main(){
    f1 = fopen("assembly.txt", "r");
    f2 = fopen("object_code.txt", "w");
    f3 = fopen("intermediate.txt", "r");

    fscanf(f3, "%s%s%s", str1, str2, str3);
    printf("%s%s%s", str1, str2, str3);
    fprintf(f2, "%s\t%s\t%s\n", str1, str2, str3);
    while(strcmp("END", str2) != 0){
        flag = 0;
        fscanf(f3, "%s%s%s%s", ch, str1, str2, str3);
        f4 = fopen("optab.txt", "r");
        while(fscanf(f4, "%s%s", opcode, value) != EOF){
            if(strcmp(str2, opcode) == 0){
                f5 = fopen("symtab.txt", "r");
                while(fscanf(f5, "%s%s", symb, symbvalue) != EOF){
                    if(strcmp(symb, str3) == 0){
                        fprintf(f2, "%s %s %s %s %s%s\n", ch, str1, str2, str3, value, symbvalue);
                        flag=1;
                    }
                }
                fclose(f5);
            }
        }
        fclose(f4);
        if(flag == 0){
            fprintf(f2, "%s %s %s %s\n", ch, str1, str2, str3);
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
