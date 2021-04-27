#include "main.h"
#include "genius_info.h"
#include <stdio.h>
#include "genius_ntfs.h"
#include <string.h>
#include <malloc.h>
#include "genius_commander.h"

int shell(char *filename){
    struct ntfs_sb_info *fs  = ntfs_init(filename);
    if (fs == NULL) return -1;
    printf("NTFS filesystem detected.\n");
    int exitFlag = 0;
    char *inputString = malloc(1024);
    while (!exitFlag) {
        char *pwd_path = pwd(fs);
        printf("%s$ ", pwd_path);
        free(pwd_path);
        fgets(inputString, 1024, stdin);
        char *command = strtok(inputString, " \n");
        if (command == NULL) {
            continue;
        }
        char *path = strtok(NULL, " \n");
        char *out_path = strtok(NULL, " \n");
        if (strcmp(command, "exit") == 0) {
            exitFlag = 1;
        } else if (strcmp(command, "help") == 0) {
            printf("cd [directory] - change working directory\n");
            printf("pwd - print full path to working directory \n");
            printf("cp [directory/file] [target directory] - copy dir or file from mounted device\n");
            printf("ls/ll - show working directory elements\n");
            printf("exit - terminate program\n");
            printf("help - print help\n");
        } else if (strcmp(command, "ls") == 0 || strcmp(command, "ll") == 0 ) {
            char *output = ls(fs, path);
            if (output == NULL) {
                printf("No such file or directory\n");
                continue;
            }
            printf("%s", output);
            free(output);
        } else if (strcmp(command, "pwd") == 0) {
            char *output = pwd(fs);
            printf("%s\n", output);
            free(output);
        } else if (strcmp(command, "cd") == 0) {
            if (path == NULL){
                printf("cd command requires path argument\n");
                continue;
            }
            char *output = cd(fs, path);
            printf("%s", output);
            free(output);
        } else if (strcmp(command, "cp") == 0) {
            if (path == NULL) {
                printf("cp command requires path argument\n");
                continue;
            }
            if (out_path == NULL) {
                printf("cp command requires out_path argument\n");
                continue;
            }
            char *output = cp(fs, path, out_path);
            printf("%s", output);
            free(output);
        } else {
            printf("Wrong command. Enter 'help' to get help.\n");
        }
    }
    free_fs(fs);
    return 0;
}

void print_help(){
    printf("To run program in list mode use `list` key. \n"
           "To run it in shell mode use `commander` key and specify drive or deviceDescriptor.\n");
}

int main(int argc, char *argv[]) {

    if (argc >= 2 && strcmp(argv[1], "help") == 0) {
        print_help();
        return 0;
    }
    if (argc >= 2 && strcmp(argv[1], "list") == 0) {
        print_info();
        return 0;
    }
    if (argc >= 3 && strcmp(argv[1], "commander") == 0) {
        shell(argv[2]);
        return 0;
    }
    printf("Incorrect command line arguments.\n\n");
    print_help();
    return 0;
}



