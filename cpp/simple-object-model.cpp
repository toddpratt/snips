
#include<iostream>

class Joke
{
    protected:
        std::string mText;
        
    public:
        Joke(std::string text);
        std::string getText(void);
};

Joke::Joke(std::string text)
{
    mText = text;
}

std::string Joke::getText(void)
{
    return mText;
}

class KnockKnock : public Joke
{
    public:
        KnockKnock(std::string text) : Joke(text) {};
};

class Comedian
{
    public:
        void tell(Joke j);
};

void Comedian::tell(Joke j)
{
    std::cout << "Joke: " << j.getText() << std::endl;
}

int main(void)
{
    std::string t("Knock knock...");
    KnockKnock j(t);
    Comedian rock;
    rock.tell(j);
}

