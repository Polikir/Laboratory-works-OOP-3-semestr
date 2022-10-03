#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <unistd.h>
#include "Board.h"
#include "MMA.h"



sf::Vector2i Block_Until_Mouse_Click(RenderWindow* window2){

    static bool pressed=false;
    sf::Vector2i position;
    while (true){

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!pressed){
                position = sf::Mouse::getPosition(*window2);
                pressed=true;
                break;
            }
        }
        else{
            pressed = false;
        }
    }

    return position;
}




int what_area(int x, int y)
{   int i,j;
    i = 10;
    j = 10;
    if ((150<x) && (x<396))
    {
        i = 0;
    }
    else if ((426<x) && (x<672))
    {
        i = 1;
    }
    else if ((702<x) && (x<948))
    {
        i = 2;
    }

    if ((220<y) && (y<486))
    {
        j = 0;
    }
    else if ((516<y) && (y<782))
    {
        j = 1;
    }
    else if ((812<y) && (y<1078))
    {
        j = 2;
    }

    if (i==10 || j==10)
    {
        return 10;
    }
    else
    {
        return (i+j*3);
    }

}

void printImage(RenderWindow* window,std::string file, int area)
{
    Texture text;
    text.loadFromFile(file);
    Sprite spr;

    spr.setTexture(text);
    spr.setPosition(120+30+(246+30)*(area%3),220+30+(266+30)*(area/3));
    window->draw(spr);
}



void printBoard(RenderWindow* window, std::vector<sf::Sprite>& sprites)
{

    Font font;


    font.loadFromFile("Marker Felt.ttf");


    Text text("Tic Tac Toe",font);


    text.setCharacterSize(100);
    text.setPosition(330,40);


    text.setFillColor(Color::Black);
    window->draw(text);

    RectangleShape line(sf::Vector2f(1100-240, 30));
    RectangleShape line_v(sf::Vector2f(30, 1318-400));
    line.setFillColor(Color(130, 130, 130));
    line_v.setFillColor(Color(130, 130, 130));

    line.setPosition(120.f, 220.f);
    line_v.setPosition(120.f, 220.f);
    window->draw(line);
    window->draw(line_v);
    line_v.setPosition(120+30+246.f, 220.f);
    window->draw(line_v);
    line_v.setPosition(120+30+246+30+246.f, 220.f);
    window->draw(line_v);
    line_v.setPosition(120+30+246+30+246+278.f, 220.f);
    window->draw(line_v);

    line.setPosition(120.f, 220+30+266.f);
    window->draw(line);
    line.setPosition(120.f, 220+30+266+30+266.f);
    window->draw(line);
    line.setPosition(120.f, 220+30+266+30+266+30+266.f);
    window->draw(line);
    for(auto &i: sprites){
        window->draw(i);
    }
}

#include <SFML/Graphics.hpp>

using namespace sf;

void gui()
{   int set;
    int end = 0;
    int index2;
    int player;
    int motion=0;
    Board* board;
    board = new Board();
    RenderWindow window(VideoMode(1100, 1318), "Laba 2!");
    Texture texture;
    texture.loadFromFile("Images/Wallpaper-Kemra-SoftWhiteBricks-1.jpg");
    Sprite sprite;
    sprite.setTexture(texture);
    bool is_empty[9] = {true,true,true,true,true,true,true,true,true};
    Sprite sprite1,sprite2,sprite3,sprite4,sprite5,sprite6,sprite7,sprite8,sprite0;
    std::vector<Sprite>sprites = {sprite1,sprite2,sprite3,sprite4,sprite5,sprite6,sprite7,sprite8,sprite0};
    std::string pict1,pict2;

    Font font;
    font.loadFromFile("Marker Felt.ttf");


    Texture texture0,texture1,texture2,texture3,texture4,texture5,texture6,texture7,texture8;
    std::vector<Texture> textures = {texture0,texture1,texture2,texture3,texture4,texture5,texture6,texture7,texture8};

    bool isMenu1=1,isMenu2 = 1,isMenu3 = 1;
    int menuNum1 = 0,menuNum2 = 0,menuNum3 = 0;


    sf::RectangleShape rectangle1(sf::Vector2f(300, 100));
    rectangle1.setPosition(sf::Vector2f(100, 350));
    rectangle1.setFillColor(Color::Black);


    sf::RectangleShape rectangle2(sf::Vector2f(300, 100));
    rectangle2.setPosition(sf::Vector2f(700, 600));
    rectangle2.setFillColor(Color::Black);

    sf::RectangleShape rectangle3(sf::Vector2f(300, 100));
    rectangle3.setPosition(sf::Vector2f(100, 850));
    rectangle3.setFillColor(Color::Black);

    sf::RectangleShape rectangle4(sf::Vector2f(350, 150));
    rectangle4.setPosition(sf::Vector2f(100, 450));
    rectangle4.setFillColor(Color::Black);

    sf::RectangleShape rectangle5(sf::Vector2f(350, 150));
    rectangle5.setPosition(sf::Vector2f(100+350+150, 450));
    rectangle5.setFillColor(Color::Black);

    sf::RectangleShape rectangle6(sf::Vector2f(500, 150));
    rectangle6.setPosition(sf::Vector2f(300, 50));
    rectangle6.setFillColor(Color::Black);



    while (window.isOpen())
    {
        Event event,event_g;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
        }

        window.draw(sprite);


        while (isMenu1)
        {   Text text1("Tic Tac Toe",font);
            text1.setCharacterSize(100);
            text1.setPosition(330,40);
            text1.setFillColor(Color::Black);

            Text text2("Classic set",font);
            text2.setCharacterSize(50);
            text2.setPosition(100,350);
            text2.setFillColor(Color::White);

            Text text3("Football set",font);
            text3.setCharacterSize(50);
            text3.setPosition(700,600);
            text3.setFillColor(Color::White);

            Text text4("Christmas"
                       " set",font);
            text4.setCharacterSize(50);
            text4.setPosition(100,850);
            text4.setFillColor(Color::White);



            if (IntRect(100, 350, 300, 100).contains(Mouse::getPosition(window))) {  menuNum1 = 1; }
            if (IntRect(700, 600, 300, 100).contains(Mouse::getPosition(window))) {  menuNum1 = 2; }
            if (IntRect(100, 850, 300, 100).contains(Mouse::getPosition(window))) {  menuNum1 = 3; }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum1 == 1 || menuNum1 == 2 || menuNum1 == 3)
                {isMenu1 = false;set = menuNum1;};


                window.draw(sprite);

                window.draw(text1);

                window.draw(rectangle1);
                window.draw(text2);

                window.draw(rectangle2);
                window.draw(text3);

                window.draw(rectangle3);
                window.draw(text4);
                window.display();

            }
            window.clear();

        };

        while (isMenu2)
        {   Text text1("Tic Tac Toe",font);
            text1.setCharacterSize(100);
            text1.setPosition(330,40);
            text1.setFillColor(Color::Black);

            Text text5("P1",font);
            text5.setCharacterSize(150);
            text5.setPosition(100,450);
            text5.setFillColor(Color::White);

            Text text6("P2",font);
            text6.setCharacterSize(150);
            text6.setPosition(100+350+150,450);
            text6.setFillColor(Color::White);

            if (IntRect(100, 450, 350, 150).contains(Mouse::getPosition(window))) {  menuNum2 = 1; }
            if (IntRect(100+350+150, 250+200, 350, 150).contains(Mouse::getPosition(window))) {  menuNum2 = 2; }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum2 == 1 || menuNum2 == 2)
                {isMenu2 = false;
                    player = menuNum2;
                    motion = player-1;
                }


                window.draw(sprite);
                window.draw(text1);

                window.draw(rectangle4);
                window.draw(text5);

                window.draw(rectangle5);
                window.draw(text6);

                window.display();
            }
            window.clear();

        };


        while (isMenu3)
        {   Text text1("Play",font);
            text1.setCharacterSize(150);
            text1.setPosition(420,50);
            text1.setFillColor(Color::White);



            if (IntRect(300, 50, 500, 150).contains(Mouse::getPosition(window))) {  menuNum3 = 1; }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum3 == 1 )
                {isMenu3 = false;
                }


                window.draw(sprite);
                window.draw(rectangle6);
                window.draw(text1);



                window.display();
            }
            window.clear();

        };
        window.draw(sprite);

        printBoard(&window, sprites);

        if (set==1)
        {
            pict1 = "Images/nol.png";
            pict2 = "Images/krest.png";
        }

        else if (set==2)
        {
            pict1 = "Images/m10.jpg";
            pict2 = "Images/r7.jpg";
        }

        else if (set==3)
        {
            pict1 = "Images/ctree.png";
            pict2 = "Images/deer.png";
        }

        int area,x,y;



        if(Mouse::isButtonPressed(Mouse::Left))
        {
            auto position = Block_Until_Mouse_Click(&window);
            area = what_area(position.x,position.y);
        }
        if ((area != 10) && is_empty[area] && end ==0 && motion % 2 == 0)
        {
            is_empty[area] = false;

            textures[area].loadFromFile(pict1);
            sprites[area].setTexture(textures[area]);
            sprites[area].setPosition(120+30+(246+30)*(area%3),220+30+(266+30)*(area/3));
            window.draw(sprites[area]);

            board->setValue(area,'O');
            if (board->user_won() == 1)
            {
                end = 1;
            }
            else if (board->isFull() == 1)
            {
                end = 1;
            }
            motion+=1;

        }
        if (motion % 2 == 1 && end == 0)
        {
            index2 = comove(board);
            end = (index2 / 10);
            index2 %= 10;
            is_empty[index2] = false;
            board->setValue(index2,'X');


            textures[index2].loadFromFile(pict2);
            sprites[index2].setTexture(textures[index2]);
            sprites[index2].setPosition(120+30+(246+30)*(index2%3),220+30+(266+30)*(index2/3));
            window.draw(sprites[index2]);
            motion+=1;


        }
        window.display();
    }

}
