#include "Game.h"

int main()
{
    Player *a = new Player("Vitor", 'X');
    Player *b = new Player("Outro", 'O');
    
    Game g(a, b);
    int play[2];

    while(!g.isFull() && !g.winner())
    {
        do{
            cout << g.getActive()->getSymbol() << " turn... ";
            cin >> play[0] >> play[1];
        }while(!g.play(play[0], play[1]));
        g.print();
    }
    if(g.winner()) cout << g.winner()->getSymbol() << " WINS" << endl;
    return EXIT_SUCCESS;
}