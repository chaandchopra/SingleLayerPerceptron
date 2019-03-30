#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define CharCount 4
float * getDataVal(FILE *fp);
float * initWeight();
float dotProduct(float *, float *);
int activationFunction(float, float);
int errorCheck(int, int);
float updateWeight(float, float, float, int);
int main()
{
    float threshold = 1; 
    float learningParameter = 0;
    bool incorrectClass = false;
    float * weights = initWeight();
    for(int i = 0; i < CharCount; i++)
    {
        printf("weights %d : %f    \n", i, weights[i]);
    }
    
    FILE * fp = fopen("testdata", "r");
    float * val = getDataVal(fp);
    for(int i = 0; i < 5; i++)
    {
        printf("values : %f\n", *(val+ i));
    }
    float dotprod = dotProduct(val, weights);
    int Tvalue = activationFunction(dotprod, threshold);
    int error = errorCheck(Tvalue, (int)*(val + 4));
    float newWeight = updateWeight(*(weights+1), 0.5, *(val+1), error);
    printf("\n dotproduct = %f", dotprod);
    printf("\n activation = %d", Tvalue);
    printf("\n error chack = %d", error);
    printf("\n new Weights for =  %f", newWeight );
    /*while(incorrectClass == true)
    {
        incorrectClass = false;
        while(1)
        {
            
        }
    }*/
}
int errorCheck(int Tvalue, int Avalue)
{
    return (Tvalue-Avalue);    
}
float updateWeight(float w, float lp, float i, int delta)
{
    return (w + (lp * i * delta));
}
int activationFunction(float dotProd, float threshold)
{
    if(dotProd >= threshold)
        return 1; // Class 1
    else
        return 2; //CLass 2
}
float dotProduct(float * weights, float * value)
{
    float f = 0;
    for(int i = 0; i < CharCount; i++)
    {
        /* code */
        f = f + (*(weights+i)) * (*(value+i));
    }
    return f;
}
float * initWeight()
{
    float * num = (float *)malloc(4*sizeof(float));
    for(size_t i = 0; i < 4; i++)
    {
        /* code */
        num[i] = (float)rand() / (float)RAND_MAX;
    }
    
    return num;
}

float * getDataVal(FILE *fp)
{
    static float values[5];
    if(fp == NULL)
    {
        printf("File Not Found");
        exit(0);
    }
    if(fp != NULL)
    {
        char line [128];
        while(fgets(line,sizeof(line) , fp) != NULL)
        {
            char * tok = strtok(line, ",");
            float f;
            int i = 0;
            while(tok != NULL)
            {
                sscanf(tok, "%f", &f);
                values[i++] = f;
                tok = strtok(NULL, ",");
            }
        }
        fclose(fp);        
        return values;
    }

}