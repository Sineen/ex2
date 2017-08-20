//
// Created by sin_een on 8/20/17.
//

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LineSeparator.h"
#define BAD -1
#define GOOD 0
#define GOODOUT 1
#define BUFF 10000
#define STOP  "\n / ,"
#define EXACT 0.00001
#define MAX_DIM  400

typedef struct vector
{
    double point[MAX_DIM]; // should be more than one maybe array ?? or for in a stuct chekc that out
    int label; // can be only -1 if bad 1 if good 0 if we didnt label it yet
} vector;


/**
 * @param dim dimintion of the fieled
 * @param w  vector
 * @param v  vector
 * @return  nothing adds the value of v to w ( changes teh w value )
 */



void getVector(FILE* input , int dim , vector* v , int x)
{
    char in[BUFF] = "";
    fgets(in, BUFF, input);
    char* token = strtok(in, STOP);
    int i;

    for ( i=0; i < dim; i++){
        v->point[i]= strtod(token, NULL);
        token = strtok(NULL, STOP);
    }
    if (x < 0 ) {
        v->label = (int) strtod(token, NULL);
    }

}


int braket(int dim, vector* v, vector* w)
{
    int i;
    double mul = 0 ;
    for (i = 0 ; i < dim ; i++)
    {
        mul = mul + (v->point[i] * w->point[i]);
    }
    if ( mul > GOOD )
    {
        return GOODOUT;
    } else
    {
        return BAD;
    }
}


void algo(int dim, vector* wVector ,vector* v)
{
    int mul= braket(dim, wVector, v);
    if ( mul != v->label ){
        addVectors(dim, wVector, multiplyVecScal(dim, v->label , *v));
    }
}
/**
 * @param dim dimintion of the fieled
 * @param w  vector
 * @param v  vector
 * @return  nothing adds the value of v to w ( changes teh w value )
 */
void addVectors(int dim, vector* w , vector v)
{

    int i;
    for (i=0; i < dim; ++i)
    {
        w->point[i] = w->point[i] + v.point[i];
    }
}

vector multiplyVecScal(int dim, int scalar, vector v)
{
    vector w = {{0}, 0};
    int i;
    for (i=0; i < dim; ++i)
    {
        w.point[i] = scalar * v.point[i];
    }
    return w;
}

int getNumber(char *token)
{
    if ( strtok(NULL, STOP) != NULL)
    {
        fprintf(stderr," wrong input");
    }
    int d = (int)(strtod(token,NULL ));
    return d;
}

void labelAndPrint(int dim, vector* v, vector w)
{
    int mul = braket(dim, &w , v);
    if ( mul > EXACT ){
        printf("%d  \n", GOODOUT);
    } else
    {
        printf("%d  \n", BAD);

    }
}

void run(FILE* input)
{
    char in[BUFF] = "";
    char * token;
    int exampleNumber = 0 ;
    int dim = 0 ;
    vector vector1 = {{0} , 0};
    vector w = {{0}, 0};


    // read first  lines,
    fgets(in, BUFF, input);
    token = strtok(in, STOP);
    dim = getNumber(token);
    assert(dim > 0);
    // reads second line
    fgets(in, BUFF, input);
    token = strtok(in, STOP);
    exampleNumber = getNumber(token);
    assert(exampleNumber > 0);


// learns the learnign input running the algo
    int j;
    for ( j =0; j < exampleNumber; ++j){
        getVector(input, dim, &vector1, BAD);
        algo(dim, &w, &vector1);
    }
    // labels the vectors

    while ( !feof(input)) {
        getVector(input, dim ,&vector1, GOOD);
        labelAndPrint(dim, &vector1, w);
    }
}

int main(int argc, char** argv)
{
    if (argc  != 2 )
    {
        fprintf(stderr,"error bad arguments");
        return (BAD);
    }
    //name of teh file in argv[1];
    FILE* inFile = fopen(argv[1], "r");
    if (inFile == NULL)
    {
        fprintf(stderr, "Error in input file");
        return(BAD);
    }
    else
    {
        run(inFile);
    }
    return GOOD;

}