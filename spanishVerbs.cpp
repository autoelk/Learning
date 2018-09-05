#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

std::ifstream fin("verbs.txt");

struct verb
{
    std::string name;
    std::string yo, tu, el, nos, ellos;
};

int amt_verbs;
verb verbs[1000];
bool quizAgain[1000];

int Quiz(int index)
{
    int amt_wrong = 0;
    std::string answer;
    std::cout << verbs[index].name << std::endl;

    std::cout << "Yo: " << std::endl;
    std::cin >> answer;
    if (answer != verbs[index].yo)
    {
        amt_wrong++;
        std::cout << "Incorrect, the correct answer was: " << verbs[index].yo << std::endl;
    }
    std::cout << "Tu: " << std::endl;
    std::cin >> answer;
    if (answer != verbs[index].tu)
    {
        amt_wrong++;
        std::cout << "Incorrect, the correct answer was: " << verbs[index].tu << std::endl;
    }
    std::cout << "El: " << std::endl;
    std::cin >> answer;
    if (answer != verbs[index].el)
    {
        amt_wrong++;
        std::cout << "Incorrect, the correct answer was: " << verbs[index].el << std::endl;
    }
    std::cout << "Nosotros: " << std::endl;
    std::cin >> answer;
    if (answer != verbs[index].nos)
    {
        amt_wrong++;
        std::cout << "Incorrect, the correct answer was: " << verbs[index].nos << std::endl;
    }
    std::cout << "Ellos: " << std::endl;
    std::cin >> answer;
    if (answer != verbs[index].ellos)
    {
        amt_wrong++;
        std::cout << "Incorrect, the correct answer was: " << verbs[index].ellos << std::endl;
    }
    return amt_wrong;
}

bool hasWrong()
{
    for (int i = 0; i < amt_verbs; i++)
    {
        if (quizAgain[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //take input
    fin >> amt_verbs;

    for (int i = 0; i < amt_verbs; i++)
    {
        fin >> verbs[i].name;
        fin >> verbs[i].yo >> verbs[i].nos >> verbs[i].tu >> verbs[i].el >> verbs[i].ellos;
        std::cout << verbs[i].name << std::endl
                  << verbs[i].yo << verbs[i].nos << std::endl
                  << verbs[i].tu << std::endl
                  << verbs[i].el << verbs[i].ellos << std::endl;
    }

    for (int i = 0; i < amt_verbs; i++)
    {
        if (Quiz(i) > 0)
        {
            quizAgain[i] = true;
        }
    }

    while (hasWrong())
    {
        for (int i = 0; i < amt_verbs; i++)
        {
            if (quizAgain[i])
            {
                if (Quiz(i) > 0)
                {
                    quizAgain[i] = true;
                }
                else
                {
                    quizAgain[i] = false;
                }
            }
        }
    }

    return 0;
}