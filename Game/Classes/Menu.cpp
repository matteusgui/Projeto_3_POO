#include "headers/Menu.h"

Menu::Menu(sf::RenderWindow &window,sf::Image background_Recieved, sf::Font fonte)
{
    sf::Texture texture;
    texture.loadFromImage(background_Recieved);

    this->background.setTexture(texture);
    this->fonte = fonte;
    this->window = window;

    Selecionar.setFont(this->fonte);

    Selecionar.setString("Modo de Jogo");

    Selecionar.setCharacterSize(15);

    Selecionar.setFillColor(Color::Black);
}

void Menu::drawMenu()
{
    sf::Vector2f meio(window.getSize().x,window.getSize().y);
    //Coloca o background na posição correta na tela
    background.setPosition(0,0);
    window.draw(background);

    //Cria o retangulo
    sf::RectangleShape rectangle(190, 35);
    rectangle.setColor(Color::Black);
    rectangle.setPosition((meio.x / 2) - 85, meio.y - 45);
    window.draw(rectangle);
    //Desenha o texto dentro do retangulo desenhado
    Selecionar.setPosition((meio.x/2)-80, meio.y - 40);
    window.draw(Selecionar);
}

bool Menu::cliqueIniciar()
{
    return (mouseButton.position.x > window.getSize().x - 130) && (mouseButton.position.x < window.getSize().x - 30) && (mouseButton.position.y > 80) && (mouseButton.position.y < 110);
}