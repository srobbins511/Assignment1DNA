

#include <iostream>
#include <fstream>

class DNA
{
    public:
        DNA(const std::string& fname);
        int Sum();
        double Mean();
        double Varriance();
        double StdDev();
        double ProbNucleo();
        double ProbBigram();
    private:
        std::string content;
        std::string line;
        int sum;
        double mean;
        double varriance;
        double stdDev;
        double probNucleo;
        double progBigram;
};