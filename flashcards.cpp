#include <iostream>
#include <fstream>
#include <string>

std::ifstream fin("flashcards.txt");

struct Card
{
    std::string front, back;
    double wrong;
};

Card cards[1000];

void QuizFront(int index)
{
    std::string input;
    std::cout << cards[index].back << " ";
    std::cin >> input;
    if (input == cards[index].front)
    {
        std::cout << "Correct" << std::endl;
        cards[index].wrong -= 0.5;
    }
    else if (input != cards[index].front)
    {
        std::cout << "Incorrect, the correct answer was " << cards[index].front << std::endl;
        cards[index].wrong++;
    }
}

void QuizBack(int index)
{
    std::string input;
    std::cout << cards[index].front << " ";
    std::cin >> input;
    if (input == cards[index].back)
    {
        std::cout << "Correct" << std::endl;
        cards[index].wrong -= 0.5;
    }
    else if (input != cards[index].back)
    {
        std::cout << "Incorrect, the correct answer was " << cards[index].back << std::endl;
        cards[index].wrong++;
    }
}

int main()
{
    std::string front, back;
    int amt_cards = 0;
    while (fin >> front >> back)
    {
        if (amt_cards >= 1000)
        {
            std::cout << "Sorry, but you have reached the max limit for amount of flashcards" << std::endl;
        }
        cards[amt_cards] = {front, back, 0};
        amt_cards++;
    }

    //Quiz back
    for (int i = 0; i < amt_cards; i++)
    {
        QuizBack(i);
    }

    for (int i = 0; i < amt_cards; i++)
    {
        for (int k = 0; k < amt_cards; k++)
        {
            if (cards[k].wrong > i)
            {
                QuizFront(k);
            }
        }
    }

    for (int i = 0; i < amt_cards; i++)
    {
        for (int k = 0; k < amt_cards; k++)
        {
            if (cards[k].wrong > i)
            {
                QuizBack(k);
            }
        }
    }

    return 0;
}