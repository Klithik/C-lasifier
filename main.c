#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
    printf("Welcome to C-lasifier, what directory would you like to get in order:\n");
    char *input;
    scanf("%s", input);
    struct dirent *target;

    // Verify valid directory
    DIR *dir = opendir(input);
    if(dir == NULL){return 1;}

    while((target = readdir(dir)) != NULL){
        if(target->d_name[0] == '.'){continue;}
    }
    return 0;
}
