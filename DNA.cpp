
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
    //initialize and declare variables that will be used throughout the program
    const double PI = 3.1415926535897;
    string ans = "";
    bool quit = true;
    int prgCount = 0;

    //the whole program lies in a do while loop so that adding additional files is simple
    do
    {
        //initialize the variables that will be used for each file to store and manipulate the data
        std::string line = "";
        std::string content = "";
        int count = 0;
        double sum = 0;
        double mean = 0;
        double varriance = 0;
        double stdDev = 0;
        double probNucleo = 0;
        double progBigram = 0;

        //check to see what iteration of the loop the program is on
        //this is to insure the file being read from is the correct file
        //whether it is the one from the command line or one entered by the user later
        if(prgCount == 0)
        {
            ans = argv[1];
        }
        ifstream myFile(ans);

        //check to see if the file has been opened successfully
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
        else
        {
            //if File could not be opened inform the user through the console
            cout << "File Not Found" << endl;
        }

    //Compute the sum of the DNA lines based on the size of the strings - the number of markers placed between them
        sum = content.length()-count;

    //compute the mean based on the sum and the number of line markers -1
        mean = sum/(count-1);

    //Compute the variance and the probabilities
        //initialize additional variables for use in finding the variance and probabilities
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

        //loop through the contents of the file looking at each character
        //As this is done check to see where the ends of lines are and the size of said lines to calculate the variance
        //after one iteration store the characeter checked in the iteration for use in the next iteration to find the probability of bigrams
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
        //compute the variance based on data gathered and stored in the above loop
        varriance = sum2/counter;

    //compute the standard Deviation based on the variance
        stdDev = sqrt(sum2/counter);
        
    //print out the sum, variance, mean, standard distribution to the output file
    //Also check the program file to see if the program should overwrite the output file or just append it
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
            //check the program counter to see if basic identification 
            //should be put at the top of the output file or if iit is not needed
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

        //compute the gaussian distribution
        //then print out the DNA lines based on the gausian distribution
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

        //check to see if the user wants to scan an additional file
        cout << "Do you want to scan an additional file Y or N: " << endl;
        cin >> ans;
        if(ans == "Y"||ans == "y")
        {
            //if yes prompt the user to enter that file name
            //then increment the program counter and set the quit variable to false to keep from exiting the loop
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


