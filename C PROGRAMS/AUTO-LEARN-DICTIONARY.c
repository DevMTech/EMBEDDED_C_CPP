

//WIPRO QUESTION

//WRITE AUTO BUILD DICTIONARY CODE THAT BUILDS UNIQUE WORD LIST AS NEW STRINGS OF WORDS ARE PROVIDED TO THE CODE

// INPUT : able point clue dig grip able atom clue trigger tin dig 

// OUTPUT : able point clue dig grip atom trigger tin

//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/* only used in string related operations */
typedef struct String string;
struct String
{
    char *str;
};

char *input(FILE *fp, int size, int has_space)
{
    int actual_size = 0;
    char str = (char *)malloc(sizeof(char)(size+actual_size));
    char ch;
    if(has_space == 1)
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    else
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n' && ch != ' ')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    actual_size++;
    str = realloc(str,sizeof(char)*actual_size);
    str[actual_size-1] = '\0';
    return str;
}
/* only used in string related operations */


typedef struct array_single_string array_single_string;
struct array_single_string
{
	string *data;
	int size;
};


/*
 * 
 */
array_single_string  dictWords(string textInput)
{
    array_single_string  answer;
    // Write your code here


    return answer;
}

int main()
{
    string textInput;
	
    
	//input for textInput
	textInput.str = input(stdin, 6000, 1);
	
	
    
	array_single_string result = dictWords(textInput);
	for(int idx = 0; idx < result.size - 1; idx++)
	{
		printf("%s ", result.data[idx].str);
	}
	printf("%s", result.data[result.size - 1].str);
	
    return 0;
}