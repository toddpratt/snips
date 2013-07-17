#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::string> phonebook;
    std::map<std::string, std::string>::iterator i;

    phonebook["todd"] = "978-212-9334";
    phonebook["thuy"] = "978-677-8178";

    std::cout << "entries: " << phonebook.size() << std::endl << std::endl;

    for(i=phonebook.begin(); i != phonebook.end(); ++i)
    {
        std::cout << (*i).first << ": " << (*i).second << std::endl;
    }

    return 0;
}

