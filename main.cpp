#include <iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

void addPc(int (&pc)[5][5]){
    int x, y, direction;
    
    for (int i = 0; i<3; i++){
        bool placed = false;
        
        while(!placed)
        {
            x = rand()%5;
            y = rand()%5;
            direction=rand()%2;
            
            if(direction==1 && y<=2){
                if (pc[x][y] == 0 && pc[x][y+1] == 0 && pc[x][y+2] == 0){
                    pc[x][y]=1;
                    pc[x][y+1]=1;
                    pc[x][y+2]=1;
                    placed = true;
                }
            }
            if(direction==0 && x<=2){
                if (pc[x][y] == 0 && pc[x+1][y] == 0 && pc[x+2][y] == 0){
                    pc[x][y]=1;
                    pc[x+1][y]=1;
                    pc[x+2][y]=1;
                    placed = true;
                }
            }
        }
    }
}

void addPlayer(int (&player)[5][5]){
    int x1, y1, x2, y2, x3, y3;
    
    for (int i=0; i<3; i++){
        bool placed=false;
        while(!placed){
            cout << "enter a position for your ship(x1, y1)";
            cin >> x1>> y1;
            cout << "enter a position for your ship(x2, y2)";
            cin >> x2 >> y2;
            cout << "enter a position for your ship(x3, y3)";
            cin >> x3 >> y3;
            if (x1>=0 && x1<=4  && y1>=0 && y1<=4 &&
                x2>=0 && x2<=4  && y2>=0 && y2<=4 &&
                x3>=0 && x3<=4  && y3>=0 && y3<=4 &&
                player[x1][y1] == 0 && player[x2][y2] == 0 && player[x3][y3] == 0){
                player[x1][y1]=1;
                player[x2][y2]=1;
                player[x3][y3]=1;
                placed=true;
            }else{
                cout << "You entered a wrong coordinate!" << endl;
            }
        }
    }
    
}

void guessedShip(int (&player)[5][5], int (&pc2)[5][5], int& count2, int& count3){
    int x, y;
    bool hitted = false;
    
    while(!hitted){
        x=rand()%5;
        y=rand()%5;
        
        if (pc2[x][y]==0){
            hitted = true;
            pc2[x][y] = 1;
            
            if (player[x][y]==1){
                cout << "Computer hit a part of your ship with coordinate: " << x << " and " << y << endl;
                player[x][y] = 0;
                count3++;
                if (count3==3){
                    count2--;
                    count3=0;
                    cout << "Computer destroyed your ship";
                }
            }else{
                cout << "Computer didn't hit a part of your ship" << endl;
            }
            
        }
    }
    
}

void enterShip(int (&pc)[5][5], int (&player)[5][5], int& count1, int& count4){
    int pos01, pos02;
    cout << "Enter a posibility place of enemy ship: ";
    cin >> pos01 >> pos02;
    if (pc[pos01][pos02] == 1){
        pc[pos01][pos02] = 0;
        
        cout << "You hit the part of a enemy ship" << endl;
        count4+=1;
        
        if(count4 == 3){
            count1-=1;
            count4=0;
            cout << "You destroyed your ship" << endl;
        }
    }else{
        cout << "You didn't hit the target" << endl;
    }
}

void print(int (&player)[5][5]){
    cout << "Your ships: " << endl;
    cout << "  0 1 2 3 4" << endl;
    for (int i=0; i<5; i++){
        cout << i << " ";
        for (int j=0; j<5; j++){
            cout << player[i][j] << " ";
        }
        cout << endl;
    }
}





void main_game(int (&pc)[5][5], int (&pc2)[5][5], int (&player)[5][5]){
    bool hel=true;
    int count1 = 3, count2 = 3,  count3 = 0, count4=0; //count3 і count4- рахують в середньому чи знищено корабель
    
    addPc(pc);
    addPlayer(player);
    
    while(hel){
        enterShip(pc, player, count1, count4);
        print(player);
        guessedShip(player, pc2, count2, count3);
        print(player);
        
        if(count1==0){
            cout << "\nYou won!" << endl;
            hel=false;
        }else if (count2==0){
            cout << "\nComputer won!" << endl;
            hel=false;
        }
        
    }
}



int main() {
    srand(time(0));
    int pc[5][5]={
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };
    int pc2[5][5]={
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };
    int player[5][5]={
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };
    
    main_game(pc, pc2, player);
    
    return 0;
    
}
