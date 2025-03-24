#include <SFML/Graphics.hpp>
#include "List/List.h"

int main()
{
    List<int> list;

    //list isert in beginnning
    for(int i = 10; i > 0; i--)
        list.push_front(i);
    //print list
    list.printList();

    //insert end of list
    list.push_back(100);
    list.printList();




}
/*
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
*/
