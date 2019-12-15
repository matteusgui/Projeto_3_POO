#include "headers/Files.h"

using namespace std;

Files::Files(GameStats* Last_Game): Last_Game(Last_Game)
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
    
}