#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_folders>\n", argv[0]);
        return 1;
    }

    int count = atoi(argv[1]);

    if (count <= 0) {
        fprintf(stderr, "Please provide a positive number.\n");
        return 1;
    }

    char folder_name[256];

    for (int i = 1; i <= count; i++) {
        snprintf(folder_name, sizeof(folder_name), "folder%d", i);

        if (mkdir(folder_name, 0755) != 0) {
            if (errno == EEXIST) {
                printf("Skipping existing folder: %s\n", folder_name);
            } else {
                perror("mkdir failed");
                return 1;
            }
        }
    }

    printf("Created %d folders.\n", count);

    return 0;
}
