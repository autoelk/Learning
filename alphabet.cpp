#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
int timesRight[26];

bool quizNum()
{
    int randInt = rand() % 26;
    if (timesRight[randInt] > 1)
        randInt = rand() % 26;
    if (randInt == 0)
        std::cout << "What is the " << randInt + 1 << "st letter of the alphabet?" << std::endl;
    else if (randInt == 1)
        std::cout << "What is the " << randInt + 1 << "nd letter of the alphabet?" << std::endl;
    else if (randInt == 2)
        std::cout << "What is the " << randInt + 1 << "rd letter of the alphabet?" << std::endl;
    else
        std::cout << "What is the " << randInt + 1 << "th letter of the alphabet?" << std::endl;

    char answer;
    std::cin >> answer;
    if (tolower(answer) == alphabet[randInt])
    {
        timesRight[randInt]++;
        std::cout << "Correct!" << std::endl;
        return true;
    }
    std::cout << "Incorrect, the correct answer was " << alphabet[randInt] << "." << std::endl;
    return false;
}

bool comesFirst()
{
    int intOne = rand() % 26, intTwo = rand() % 26;
    if (timesRight[intOne] > 2 || timesRight[intOne] == timesRight[intTwo])
        intOne = rand() % 26;
    else if (timesRight[intTwo] > 2)
        intTwo = rand() % 26;
    char answer, correctAnswer = std::min(alphabet[intOne], alphabet[intTwo]);
    std::cout << "Which comes first? " << alphabet[intOne] << ", or " << alphabet[intTwo] << "?" << std::endl;
    std::cin >> answer;
    if (answer == correctAnswer)
    {
        timesRight[intOne]++;
        timesRight[intTwo]++;
        std::cout << "Correct!" << std::endl;
        return true;
    }
    std::cout << "Incorrect!" << std::endl;
    return false;
}

bool isDone()
{
    int amt_done = 0;
    for (int i = 0; i < 26; i++)
    {
        if (timesRight[i] > 2)
        {
            amt_done++;
        }
    }
    if (amt_done == 26)
    {
        return true;
    }
    return false;
}

int main()
{
    std::srand(time(NULL)); // generate a seed
    while (!isDone())
    {
        quizNum();
        comesFirst();
    }
    return 0;
}