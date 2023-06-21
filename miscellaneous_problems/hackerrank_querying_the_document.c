// problem link : https://www.hackerrank.com/challenges/querying-the-document/problem?isFullScreen=true

/*
Idea:
convert string as an array of character to multi-level pointers (document - paragraph - sentences - words - letters)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m-1][k-1];
}


char*** kth_paragraph(char**** document, int k) {
    
    return document[k-1];
}

char**** get_document(char* text) {
    int IDletter = 0, IDword = 0, IDsentence = 0, IDparagraph = 0;

    char ****document = (char****) calloc(1, sizeof(char***)); // pointer to array of paragraphs pointers
    document[0] = (char***) calloc(1, sizeof(char**));        // pointers to arrays of sentences pointers
    document[0][0] = (char**) calloc (1, sizeof(char*));     // pointers to arrays of words pointers
    document[0][0][0] = (char*) calloc (1, sizeof(char));    // pointer to arrays of chars

    int i = 0;
    while(text[i] != '\0')
    {
        if( (text[i] != ' ') && (text[i] != '.') && (text[i] != '\n') )
        {
            document[IDparagraph][IDsentence][IDword][IDletter] = text[i];
            IDletter++;
            document[IDparagraph][IDsentence][IDword] = (char*)realloc(document[IDparagraph][IDsentence][IDword], (IDletter +  1) * sizeof(char));
        }
        else if(text[i] == ' ')
        {
            IDletter = 0;
            IDword++;
            document[IDparagraph][IDsentence] = (char**) realloc(document[IDparagraph][IDsentence], (IDword +  1) * sizeof(char*));
            document[IDparagraph][IDsentence][IDword] = (char*) calloc(1,  sizeof(char*));

            
        }
        else if(text[i] == '.')
        {
            IDletter = 0;
            IDword = 0;
            IDsentence++;
            document[IDparagraph] = (char***) realloc(document[IDparagraph], (IDsentence +  1) * sizeof(char*));
            document[IDparagraph][IDsentence] = (char**) calloc(1, sizeof(char*));
            document[IDparagraph][IDsentence][IDword] = (char*) calloc(1, sizeof(char*));
        }
        else if(text[i] == '\n')
        {
            IDletter = 0;
            IDword = 0;
            IDsentence = 0;
            IDparagraph++;
            document = (char****) realloc(document, (IDparagraph +  1) * sizeof(char*));
            document[IDparagraph] = (char***) calloc((IDparagraph +  1), sizeof(char*));
            document[IDparagraph][IDsentence] = (char**) calloc(1, sizeof(char*));
            document[IDparagraph][IDsentence][IDword] = (char*) calloc(1, sizeof(char*));
        }
        i++;
    }
    return document;
}

int main()
{
    char *text = "Learning C is fun.\nLearning pointers is more fun.It is good to have pointers.";
    
    char ****doc = get_document(text);
    
    printf("%s", doc[1][1][2]);
    
    return 0;
}