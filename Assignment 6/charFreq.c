/*  Assignment 6
 *  Name: Evan Laia
 *  Partner's name: Cordan W.
 *  CS 1713 Summer 2015
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * struct for storing a char and the number of times it appears in a provided text
 */
struct charfreq
{
    int count;
    char next;
};

typedef struct charfreq charfreq;

/*
 * Returns the index of charfreq struct which has the char c stored in its member variable next.
 * If none of the charfreq structs contains c then it returns -1.
 */
int charInCFStruct(charfreq **cfarray, int size, char c){

    int i;
    
    if (size != 0) { /*the first value needs to be populated first before searching*/
        for (i=0; i<size; i++) {
            
            if (cfarray[i]->next == c)
            return i;
        }
    }

    return -1;
}

/*
 * Prints the contents of all of the charfreq structs.
 */
void printCFStruct(charfreq **cfarray, int size){

    int i;
    
    for (i=0; i<size-1; i++) {
           printf("%c: %d\n", cfarray[i]->next, cfarray[i]->count);
    }
}

/*
 * Frees all of the charfreq structs and then frees the pointer to the structs.
 */
void freeCFStruct(charfreq **cfarray, int size){

    int i = 0;

    while (i<size) {
        free(cfarray[i]);
        i++;
    
    }
    
    free(cfarray);
    
}

int main(void)
{
    charfreq **cfarray;
    charfreq **cfrealloc;
    FILE *inputfile;
    char next;
    int size = 10; /* used initial value of 10 but any positive number should work */
    int biggerSize = size; /* increment value if array is filled */
    int i = 0;
    int pos;

    /* open file to read from */
    inputfile = fopen("chars.txt", "r");

    if(inputfile == NULL) {
        printf("Oops! It looks like the chars.txt file is not included in you directory!\n");
        exit(1);
    }

    /* allocate space for pointers to char frequency structs */
    cfarray = malloc(size*sizeof(charfreq*));
    
    /* read in chars until the end of file is reached */
    while(fscanf(inputfile, "%c", &next) != EOF){

        /* allocate more pointers if we've reached our initial size value */
        if (i == size) {
            
            size = size+biggerSize;
            cfarray = realloc(cfarray,size*sizeof(charfreq*));
        
        }
        
        /* fill in code to fill structs with data being read in */
        pos = charInCFStruct(cfarray, i, next);
        
        if (pos == -1) { //if the char is unique with no repeated values
            cfarray[i] = malloc(sizeof(charfreq));
            cfarray[i]->next = next;
            cfarray[i]->count = 1;
            i++;
        } else { //increase the count at returned position
          
            cfarray[pos]->count++;
        
        }
    }


    /* print out char frequency structs */
    printCFStruct(cfarray,i);

    /* free all char frequency structs */
    freeCFStruct(cfarray,i);

    /* close the file we opened earlier */
    fclose(inputfile);

    return 0;
}
