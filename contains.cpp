#include <iostream>
#include <fstream>

std::ifstream fin("contains.txt");

struct term
{
    std::string phrase;
    bool used = false;
};

term terms[1000];

int main()
{
    std::string temp, name;
    fin >> name;
    int amt_terms = 0;
    while (fin >> temp)
    {
        if (amt_terms >= 1000)
        {
            std::cout << "Sorry, but you have reached the max limit for amount of terms" << std::endl;
        }
        terms[amt_terms].phrase = temp;
        amt_terms++;
    }

    std::cout << name << ": " << std::endl;

    for (int i = 0; i < amt_terms; i++)
    {
        std::string ans;
        std::cin >> ans;

        bool contains = false;
        int position;
        for (int j = 0; j < amt_terms && !contains; j++)
        {
            if (terms[j].phrase == ans)
            {
                position = j;
                contains = true;
            }
        }

        if (contains && !terms[position].used)
        {
            std::cout << "Good Job!" << std::endl;
            terms[position].used = true;
        }
        else if (contains && terms[position].used)
        {
            std::cout << "You have already used that phrase" << std::endl;
        }
        else
        {
            std::cout << "Sorry, but the phrase \"" << terms[position].phrase << "\" is not part of the set" << std::endl;
            i++;
        }
    }

    return 0;
}