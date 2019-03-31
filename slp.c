#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define CharCount 4
#define CharOutCount 5
#define TrainingSet 40
#define threshold 6.0f
float * getDataVal(FILE *fp);
float * initWeight();
float dotProduct(float *, float *);
int activationFunction(float, float);
int errorCheck(int, int);
float updateWeight(float, float, float, int);
void printValues(float *);
void printWeights(float *);
void TestSLP(float *);
void printIris(int);
int main()
{
    //float threshold = 6; 
    float learningParameter = 0.5;
    bool incorrectClassue, errue, err = false;
    float * weights = initWeight();
    printWeights(weights);
    FILE * fp = fopen("testdata", "r");
    bool CorrectClass = false;
    float * val;
    float dp;
    int Tvalue, error;
    while(CorrectClass == false)
    {
        CorrectClass = true;
        int i = 0;
        while(i < TrainingSet)
        {
            //if(i == 2) break;
            printf("Inputing values..\n");
            val = getDataVal(fp);
            printValues(val);
            printf("\nWeights Values:\n");
            printWeights(weights);
            dp = dotProduct(val, weights);
            printf("\nDot Product with weigths: %f", dp);
            Tvalue = activationFunction(dp, threshold);
            printf("\nT Value: %d", Tvalue);
            error = errorCheck(Tvalue, *(val + (CharOutCount-1)));
            printf("\nError Values: %d\n", error);
            if(error == 0 ) printf("\nCorrect Output.");
            if(error != 0)
            {
                CorrectClass = false;
                printf("Incorrect Output. Need weights updates..");
                printf("***********************************************");
                for(int i = 0; i < CharCount; i++)
                {
                   
                    *(weights + i) = updateWeight(*(weights + i), learningParameter, *(val + i), error);
                }
                printWeights(weights);
            }
        i++;
        }

        rewind(fp);
    }
    fclose(fp);
    TestSLP(weights);
}
void TestSLP(float *w)
{
    float input[CharCount], f;
    for(int i = 0; i < CharCount; i++)
    {
        printf("\nEnter Input Values %d:", i+1);
        scanf("%f", &f);
        input[i] = f;
    }
    float dp = dotProduct(w, input);
    int T = activationFunction(dp,threshold);
    printIris(T);
}
void printIris(int T)
{
    if(T == 1)
        printf("\nIris-setosa\n");
    if(T == 2)
        printf("\nIris-Versicolor\n");
}
void printWeights(float * weights)
{
    for(int i = 0; i < CharCount; i++)
    {
        printf("%f\t", *(weights+i));
    }
}
void printValues(float * val)
{
    for(int i = 0; i < CharOutCount; i++)
    {
        /* code */
        printf("%f \t", *(val + i));
    }
    
}

int errorCheck(int Tvalue, int Avalue)
{
    return (Tvalue-Avalue);    
}
float updateWeight(float w, float lp, float i, int delta)
{
    return (w + (lp * i * delta));
}
int activationFunction(float dotProd, float thres)
{
    if(dotProd >= thres)
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
    for(size_t i = 0; i < CharCount; i++)
    {
        /* code */
        num[i] = (float)rand() / (float)RAND_MAX;
    }
    
    return num;
}

float * getDataVal(FILE *fp)
{
    static float values[CharOutCount];
    if(fp == NULL)
    {
        printf("File Not Found");
        exit(0);
    }
    if(fp != NULL)
    {
        char line [128];
        fgets(line,sizeof(line) , fp);
        char * tok = strtok(line, ",");
        float f;
        int i = 0;
        while(tok != NULL)
        {
            sscanf(tok, "%f", &f);
            values[i++] = f;
            tok = strtok(NULL, ",");
        }      
        return values;
    }

}