
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
    double PI = 3.1415926535897;
    std::string line = "";
    std::string content = "";
    int count = 0;
    double sum = 0;
    double mean = 0;
    double varriance = 0;
    double stdDev = 0;
    double probNucleo = 0;
    double progBigram = 0;


    ifstream myFile(argv[1]);
    if(myFile.is_open())
    {
        
        cout<< "file opened"<< endl;
        while(myFile)
        {
            content += line + "|";
            count++;
            myFile >> line;
        }
        cout<< content << endl;
        myFile.close();
    }


//Compute the sum of the DNA lines based on the size of the strings - the number of markers placed between them
    sum = content.length()-count;

//compute the mean based on the sum and the number of line markers -1
    mean = sum/(count-1);

//Compute the variance and the probabilities

    int number;
    double counter = 0;
    double aCount = 0;
    double tCount = 0;
    double gCount = 0;
    double cCount = 0;

    //bigram counter variables for bigrams starting with a
    double aaCount = 0;
    double atCount = 0;
    double agCount = 0;
    double acCount = 0;

    //bigram counter variables for bigrams starting with c
    double caCount = 0;
    double ctCount = 0;
    double cgCount = 0;
    double ccCount = 0;

    //bigram counter variables for bigrams starting with t
    double taCount = 0;
    double ttCount = 0;
    double tgCount = 0;
    double tcCount = 0;

    //bigram counter variables for bigrams starting with g
    double gaCount = 0;
    double gtCount = 0;
    double ggCount = 0;
    double gcCount = 0;

    double sum2 = 0;
    char tempChar = '0';
    string buffer = "";
    for(char w: content)
    {
        if( w == '|' && number !=0)
        {
            int temp = number - mean;
            double temp2 = pow(2, temp);
            sum2 +=temp2;
            counter++;
            number = 0;
        }
        else 
        {
            if(w == 'A' || w == 'a')
            {
                if(tempChar == 'A' || tempChar == 'a')
                {
                    aaCount++;
                } else if(tempChar == 'C' || tempChar == 'c')
                {
                    caCount++;
                } else if(tempChar == 'T' || tempChar == 't')
                {
                    taCount++;
                } else if(tempChar == 'G' || tempChar == 'g')
                {
                    gaCount++;
                }
                aCount++;
            } 
            else if(w == 'C' || w == 'c') 
            {
                if(tempChar == 'A' || tempChar == 'a')
                {
                    acCount++;
                } else if(tempChar == 'C' || tempChar == 'c')
                {
                    ccCount++;
                } else if(tempChar == 'T' || tempChar == 't')
                {
                    tcCount++;
                } else if(tempChar == 'G' || tempChar == 'g')
                {
                    gcCount++;
                }
                cCount++;
            } 
            else if(w == 'T' || w == 't')
            {
                if(tempChar == 'A' || tempChar == 'a')
                {
                    atCount++;
                } else if(tempChar == 'C' || tempChar == 'c')
                {
                    ctCount++;
                } else if(tempChar == 'T' || tempChar == 't')
                {
                    ttCount++;
                } else if(tempChar == 'G' || tempChar == 'g')
                {
                    gtCount++;
                }
                tCount++;
            } 
            else if(w == 'G' || w == 'g') 
            {
                if(tempChar == 'A' || tempChar == 'a')
                {
                    agCount++;
                } else if(tempChar == 'C' || tempChar == 'c')
                {
                    cgCount++;
                } else if(tempChar == 'T' || tempChar == 't')
                {
                    tgCount++;
                } else if(tempChar == 'G' || tempChar == 'g')
                {
                    ggCount++;
                }
                gCount++;
            }
            tempChar = w;
            number++;
        }
    }
    varriance = sum2/counter;

//compute the standard Deviation
    stdDev = sqrt(sum2/counter);

//compute the gaussian distribution
    ofstream outFile("srobbins.out");
    for (int i=0; i<1000; ++i)
    {
        double randA = rand()/(double)RAND_MAX;
        double randB = rand()/(double)RAND_MAX;
        double C = sqrt(-2*log(randA)) * cos(2*PI*randB);
        double D = stdDev*C + mean;
        for (int j = 0; j<D;++j)
        {
            std::string strLine = "";
            int randGen = rand()/(double)RAND_MAX*4;
            if(randGen == 0)
            {
                strLine +="A";
            }
            else if(randGen == 1)
            {
                strLine +="T";
            }
            else if(randGen == 2)
            {
                strLine +="C";
            }
            else if(randGen == 3)
            {
                strLine +="G";
            }
        }
    }
    


//print out the sum, variance, mean, standard distribution
    cout << "The Sum: " << sum << endl;
    cout << "The Mean: " << mean << endl;
    cout << "The Variance: " << varriance << endl;
    cout << "The Standard Deviation: " << stdDev << endl;

    //print out the Nucleotide Probabilities
    cout << "Nucleotide Probabilities: " << endl;
    cout << "    A: " << aCount/sum <<endl;
    cout << "    T: " << tCount/sum <<endl;
    cout << "    C: " << cCount/sum <<endl;
    cout << "    G: " << gCount/sum <<endl;

    cout << "Bigram Probabilities: " << endl;
    cout << "    AA: " << aaCount/sum <<endl;
    cout << "    AT: " << atCount/sum <<endl;
    cout << "    AC: " << acCount/sum <<endl;
    cout << "    AG: " << agCount/sum <<endl;

    cout << "    TA: " << taCount/sum <<endl;
    cout << "    TT: " << ttCount/sum <<endl;
    cout << "    TC: " << tcCount/sum <<endl;
    cout << "    TG: " << tgCount/sum <<endl;

    cout << "    CA: " << caCount/sum <<endl;
    cout << "    CT: " << ctCount/sum <<endl;
    cout << "    CC: " << ccCount/sum <<endl;
    cout << "    CG: " << cgCount/sum <<endl;

    cout << "    GA: " << gaCount/sum <<endl;
    cout << "    GT: " << gtCount/sum <<endl;
    cout << "    GC: " << gcCount/sum <<endl;
    cout << "    GG: " << ggCount/sum <<endl;
};


