#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

int
du(const char *filename, int first)
{
    DIR *directory;
    char *next_filename;
    size_t f_size;
    blkcnt_t count;
    struct dirent *d;
    struct stat s;

    if (stat(filename, &s) != 0)
    {
        perror("stat");
        return -1;
    }

    if (S_ISDIR(s.st_mode))
    {
        count = s.st_blocks;
        f_size = strlen(filename);
        
        directory = opendir(filename);
        if (directory == NULL)
        {
            perror("opendir");
            return 0;
        }

        while (1)
        {
            errno = 0;
            d = readdir(directory);

            if (d == NULL)
            {
                if (errno != 0)
                {
                    perror("readdir");
                    return -1;
                }
                else
                    break;
            }

            if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0)
                continue;

            next_filename = malloc((f_size
                        + strlen(d->d_name) + 2) * sizeof(char));
            if (next_filename == NULL)
            {
                perror("allocation");
                return -1;
            }

            strcat(next_filename, filename);
            next_filename[f_size] = '/';
            next_filename[f_size + 1] = '\0';
            strcat(next_filename, d->d_name);
           
            count += du(next_filename, 0);
        }
            
        printf("%7lu %s\n", count, filename);
        return count;
    }
    else
    {
        if (first)
        {
            printf("%7lu %s\n", s.st_blocks, filename);
            return 1;
        }
        return s.st_blocks;
    }
        
}

int main(int argc, const char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "%s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    du(argv[1], 1);

    return EXIT_SUCCESS;
}
