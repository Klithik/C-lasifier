#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int verifyDir(char target[]){
    struct stat s;
    int err = stat(target,&s);
    if(err == -1){
        return 1;
    }
    if(!S_ISDIR(s.st_mode)){
        return 1;
    }
    return 0;
}

int main(){
    printf("Welcome to C-lasifier, what directory would you like to get in order:\n");
    char *input;
    scanf("%s", input);
    if(verifyDir(input)!=0){return 1;}

    struct dirent *target;
    DIR *dir = opendir(input);
    if(dir == NULL){return 1;}

    while((target = readdir(dir)) != NULL){
        if(target->d_name[0] == '.'){continue;}
    }
    return 0;
}
