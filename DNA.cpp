
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
    const double PI = 3.1415926535897;
    string ans = "";
    bool quit = true;
    int prgCount = 0;
    do
    {
        std::string line = "";
        std::string content = "";
        int count = 0;
        double sum = 0;
        double mean = 0;
        double varriance = 0;
        double stdDev = 0;
        double probNucleo = 0;
        double progBigram = 0;

        if(prgCount == 0)
        {
            ans = argv[1];
        }
        ifstream myFile(ans);
        if(myFile.is_open())
        {
            
            cout<< "File Opened"<< endl;
            while(myFile)
            {
                content += line + "|";
                count++;
                myFile >> line;
            }
            myFile.close();
        }


    //Compute the sum of the DNA lines based on the size of the strings - the number of markers placed between them
        sum = content.length()-count;

    //compute the mean based on the sum and the number of line markers -1
        mean = sum/(count-1);

    //Compute the variance and the probabilities

        int number = 0;
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
                int temp = 0;
                temp = number - mean;
                double temp2 = pow(temp, 2);
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
        
    //print out the sum, variance, mean, standard distribution to the output file
        ofstream outFile;
        if(prgCount !=0)
        {
            outFile.open("srobbins.out", ios::app);
        }
        else{
            outFile.open("srobbins.out");
        }


        if(prgCount == 0)
        {
            outFile << "Name: Sean Robbins" << endl << "ID: 2328696" << endl << "Email: srobbins@chapman.edu" << endl;
            outFile << "CPSC350 Section 1 " << endl << endl;
        }
        


        outFile << endl << endl << endl;
        outFile << "File Name: " << ans << endl << endl;
        outFile << "The Sum: " << sum << endl;
        outFile << "The Mean: " << mean << endl;
        outFile << "The Variance: " << varriance << endl;
        outFile << "The Standard Deviation: " << stdDev << endl << endl;
        //print out the Nucleotide Probabilities
        outFile << "Nucleotide Probabilities: " << endl;
        outFile << "    A: " << aCount/sum <<endl;
        outFile << "    T: " << tCount/sum <<endl;
        outFile << "    C: " << cCount/sum <<endl;
        outFile << "    G: " << gCount/sum <<endl << endl;

        outFile << "Bigram Probabilities: " << endl;
        outFile << "    AA: " << aaCount/sum <<endl;
        outFile << "    AT: " << atCount/sum <<endl;
        outFile << "    AC: " << acCount/sum <<endl;
        outFile << "    AG: " << agCount/sum <<endl;

        outFile << "    TA: " << taCount/sum <<endl;
        outFile << "    TT: " << ttCount/sum <<endl;
        outFile << "    TC: " << tcCount/sum <<endl;
        outFile << "    TG: " << tgCount/sum <<endl;

        outFile << "    CA: " << caCount/sum <<endl;
        outFile << "    CT: " << ctCount/sum <<endl;
        outFile << "    CC: " << ccCount/sum <<endl;
        outFile << "    CG: " << cgCount/sum <<endl;

        outFile << "    GA: " << gaCount/sum <<endl;
        outFile << "    GT: " << gtCount/sum <<endl;
        outFile << "    GC: " << gcCount/sum <<endl;
        outFile << "    GG: " << ggCount/sum <<endl;

        
        for (int i=0; i<1000; ++i)
        {
            double randA = rand()/(double)RAND_MAX;
            double randB = rand()/(double)RAND_MAX;
            double C = sqrt(-2*log(randA)) * cos(2*PI*randB);
            double D = stdDev*C + mean;
            std::string strLine = "";
            for (int j = 0; j<D;++j)
            {
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
            outFile << strLine << endl;
        }
        outFile.close();

        cout << "Do you want to scan an additional file Y or N: " << endl;
        cin >> ans;
        if(ans == "Y"||ans == "y")
        {
            cout << "enter the file name: " << endl;
            cin >> ans;
            prgCount++;
            quit = false;
        }
        else
        {
            quit = true;
        }
    }while(!quit);
    
};


