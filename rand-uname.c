#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NOUN_FILE "/etc/rand_name/username_nouns.txt"
#define VERB_FILE "/etc/rand_name/username_verbs.txt"
#define LINE_BUFFER_SIZE 256

static long number_of_lines(FILE *file)
{

    long lines = 0;
    int c;
    int last_char = '\n';

    rewind(file);

    while ((c = fgetc(file)) != EOF)
    {
          if (c == '\n')
          {
            lines++;
          }
          last_char = c;
    }

    if (last_char !='\n')
    {
        lines++;
    }

    rewind(file);
    return lines;
}

static char *get_line(FILE *file,long targetLine)
{
    char buff[LINE_BUFFER_SIZE];
    long current_line = 0;

    rewind(file);

    while (fgets(buff, sizeof(buff), file) != NULL)
    {

        if(current_line == targetLine)
        {
            size_t len = strlen(buff);
            if (len > 0 && buff[len -1] == '\n')
            {
                buff[len -1] = '\0';
            }
            return strdup(buff);
        }
        current_line++;
    }

    return NULL;
}

int main(int argc, char **argv)
{
    srand((unsigned int)time(NULL));

    const char *noun_path = NOUN_FILE;
    const char *verb_path = VERB_FILE;

    if (argc >= 2)
    {
        noun_path = argv[1];
    }
    if (argc >= 3)
    {
        verb_path = argv[2];
    }

    FILE *noun_file = fopen(noun_path,"r");
    if(!noun_file)
    {
        fprintf(stderr, "Error opening file '%s': %s\n", noun_path, strerror(errno));
        return 1;
    }

    FILE *verb_file = fopen(verb_path, "r");
    if(!verb_file)
    {
        fprintf(stderr, "Error opening file '%s': %s\n", verb_path, strerror(errno));
        fclose(noun_file);
        return 1;
    }

    long noun_count = number_of_lines(noun_file);
    long verb_count = number_of_lines(verb_file);

    if (noun_count <= 0 && verb_count <= 0)
    {
        fprintf(stderr, "One of the word list files is empty.\n");
        fclose(noun_file);
        fclose(verb_file);
        return 1;
    }

    long random_noun = rand() % noun_count;
    long random_verb = rand() % verb_count;
    unsigned int random_num = rand() % 100;

    char *verb_word = get_line(verb_file, random_verb);
    char *noun_word = get_line(noun_file, random_noun);

    if (!verb_word || !noun_word)
    {
        fprintf(stderr, "Error reading word list.\n");
    }
    else
    {
        printf("%s%s%u\n", verb_word, noun_word, random_num);
    }

    free(verb_word);
    free(noun_word);
    fclose(noun_file);
    fclose(verb_file);

    return 0;
}