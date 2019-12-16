#include "headers/Files.h"

using namespace std;

Files::Files(GameStats* Last_Game, RenderWindow* window): Last_Game(Last_Game), window(window)
{

}

void Files::GravaJogo(Player *a, Player* b, Game* game)
{
    //Verifica se a partida foi jogada contra um bot ou contra outro player
    if(a->isBot() || b->isBot())
    {
        this->Last_Game->setContra_Bot(true);
    }
    else
    {
        this->Last_Game->setContra_Bot(false);
    }
    //Coloca o vencedor nas estatisticas do último jogo
    this->Last_Game->setWinner(Game->winner());
    fstream arqOut(path, ios::binary|ios::app);
    arqOut.write(reinterpret_cast<char*>(Last_Game),sizeof(GameStats));
    arqOut.close();
}

void Files::Carrega_Jogos()
{
    ifstream arqIn(path, ios::binary)
    if (!arqIn.isOpen())
    {
        cout << "Erro na leitura do arquivo ranking.dat";
        exit(EXIT_FAILURE);
        system("pause");
    }
    GameStats R;
    arqIn.read(reinterpret_cast <char*> (&R),sizeof(GameStats));
    while (arqIn.good())
    {
        Jogos.push_back(R);
        arqIn.read(reinterpret_cast <char*> (&R),sizeof(GameStats));
    }

}

void Files::drawStats()
{
    bool contra = Last_Game->getContra_Bot;
    switch (contra)
    {
    case true:
        int vitoria = 0;
        for (int i = 0; i < Jogos.size(); i++)
        {
            if (Jogos[i].getContra_Bot())
            {
                vitoria++;
            }
            sf::Text Titulo;
            Titulo.setString(L"Jogos contra o Computador");
            Titulo.setCharacterSize(14);
            Titulo.setposition(window->getSize().x / 2 - 175, 10);
            window->draw(Titulo);
            string victory = to_string(vitoria);
            stringstream texto;
            sf::Text Texto;
            texto = "O seu número de vitórias é de:";
            Texto.setString(texto);
            Texto.setCharacterSize(10);
            Texto.setPosition(window->getSize().x, 50);
            window->draw(Texto);
            texto = victory;
            Texto.setString(texto);
            Texto.setCharacterSize(40);
            
        }
        
        break;
    
    default:
        break;
    }
}

void FIle::setFonte(Font fonte) {
        this->fonte = fonte;
}
    
Font File::getFonte() {
    return fonte;
}