#include <stdio.h>
#include <iostream>
using namespace std;
int pc_grid[10][10];
int player_grid[10][10];
int coor[1];

int grid(){
    int i,j;
    cout<<"    ";
    for (int k=0; k<10; ++k){
        cout<<k;
        cout<< " ";
    }
    cout<<"|Y|";
    cout<<"\n";
    for (i=0; i<10; ++i){
        cout <<i;
        cout <<" | ";
        for(j=0; j<10; ++j)
        {
            player_grid[i][j]=0;
            cout<<player_grid[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }
    cout<<"X | ";
    return player_grid[i][j];
}
int battlegrid(){
    int i,j;
    cout<<"    ";
    for (int k=0; k<10; ++k){
        cout<<k;
        cout<< " ";
    }
    cout <<"\n";
    for (i=0; i<10; ++i){
        cout <<i;
        cout <<" | ";
        for(j=0; j<10; ++j)
        {
            cout<<player_grid[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }
    return player_grid[i][j];
}
int ShipA(int a, int b){
    for(int i=0; i<3; i++){
        if(player_grid[a+i][b]!=0){
            return 0;
        }
    }
    for(int i=0; i<3; i++){
        player_grid[a+i][b]=1;
    }
    return 1;
}
int ShipB(int a, int b){
    for(int i=0; i<3; i++){
        if(player_grid[a][b+i]!=0){
            return 0;
        }
    }
    for(int i=0; i<3; i++){
        player_grid[a][b+i]=2;
    }
    return 1;
}
int ShipC(int a, int b){
    for(int i=0; i<5; i++){
        if(player_grid[a][b+i]!=0){
            return 0;
        }
    }
    for(int i=0; i<5; i++){
        player_grid[a][b+i]=3;
    }
    return 1;
}

int ShipD(int a, int b){
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            if(player_grid[a+i][b+j]!=0){
                return 0;
        }}
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            player_grid[a+i][b+j]=4;
        }}
    return 1;
}
int ShipE(int a, int b){
    for(int i=0; i<3; i++){
        if(player_grid[a+i][b]!=0){
            return 0;
        }
    }
    for(int i=1; i<3; i++){
        if(player_grid[a+2][b+i]!=0){
            return 0;
        }
    }
    for(int i=0; i<3; i++){
        player_grid[a+i][b]=5;
    }
    for(int i=1; i<3; i++){
        player_grid[a+2][b+i]=5;
    }
    return 1;
}
int main()
{
    char run = 'Y',diff;
    int ship_remain,x,y,z;;
    //loop if the commander wants to play again
    while(run == 'Y'){
        cout<<"Battleship ";
        cout<<"  CE-205\n";;
        while(true){
            cout<<" -------- -------- \n";
            cout<<"|[E] Easy|[H] Hard|\n";
            cout<<" -------- -------- \n";
            cout<<"What would you like to do Commander? ";
            cin>>diff;
            if(diff == 'E' or diff =='e'){
                ship_remain =5;
                break;}
            else if(diff == 'H' or diff =='h'){
                ship_remain = 22;
                break;
            }
            else
                cout<<"Wrong Input\n";
        }
        //making a grid for player
        grid();
        int k;
        cout<<"\n";
        string shiparr[5] = {"Ship size 3x1","Ship size 1x3","Ship size 1x5","Ship size 2x3","Ship L ship"};
        for(k=0; k <5; k++){
            //if the user inputted wrong coordinates it loop again
            while(true){
                string ships;
                //enter coordinates for x and y
                cout<<"Enter Coordinate for "<<shiparr[k]<<": ";
                cin>>z;
                for (int i = 1; i >= 0; i--) {
                    coor[i] = z % 10;
                    z /= 10;
                    }
                x= coor[0]; y = coor[1];
                if(k==0){
                    //calling shipA function
                    //this function is putting a ship in the coordinates inputted; ship size 3x1 
                    if(ShipA(x,y)==1)
                        break;
                    else
                        cout<<"Coordinate already has a ship\n";
                }else if(k==1){
                    //calling ShipB function
                    //this function is putting a ship in the coordinates inputted; ship size 1x3
                    if(ShipB(x,y)==1)
                        break;
                    else
                        cout<<"Coordinate already has a ship\n";
                }else if(k==2){
                    //calling shipC function
                    //this function is putting a ship in the coordinates inputted; ship size 1x5
                    if(ShipC(x,y)==1)
                        break;
                    else
                        cout<<"Coordinate already has a ship\n";
                }else if(k==3){
                    //calling shipD function
                    //this function is putting a ship in the coordinates inputted; ship size 2x3
                    if(ShipD(x,y)==1)
                        break;
                    else
                        cout<<"Coordinate already has a ship\n";
                }else if(k==4){
                    //calling shipE function
                    //this function is putting a ship in the coordinates inputted; ship L
                    if(ShipE(x,y)==1)
                        break;
                    else
                        cout<<"Coordinate already has a ship\n";
                }else{
                    cout<<"";
                }
            }
            //showing the updated grid
            battlegrid();
        }
        //PC Generates Battleship
        for (int i=0; i<10; ++i){
            for(int j=0; j<10; ++j)
            {
                pc_grid[i][j]=0;
            }
        }
        int a,b,valid=1;
        //First Ship 3x1
        //checking if coordinates are 0
        while(valid){
            valid=0;
            a = rand() % 7; b = rand() % 9;
            for(int i=0; i<3; i++){
                if(pc_grid[a+i][b]!=0){
                    //if coordinates not zero, valid == 1 to reset the pc to choose again
                    valid=1;
                }
            }
        }
        //if coordinates is zero then it will generate a ship
        for(int i=0; i<3; i++){
            pc_grid[a+i][b]=1;
        }
        //make valid value one again to run the loop
        valid = 1;
        //Second Ship 1x5
        while(valid){
            valid = 0;
            a = rand() % 9; b = rand() % 7;
            for(int i=0; i<3; i++){
                if(pc_grid[a][b+i]!=0){
                    valid=1;
                }
            }
            }
        for(int i=0; i<3; i++){
            pc_grid[a][b+i]=2;
        }
        valid =1;
        //Third Ship 1x5
        while(valid){
            valid=0;
            a = rand() % 9; b = rand() % 5;
            for(int i=0; i<5; i++){
                if(pc_grid[a][b+i]!=0){
                    valid==1;
                }
            }
        }
        for(int i=0; i<5; i++){
            pc_grid[a][b+i]=3;
        }
        //Fourth Ship 2x3
        valid =1;
        while(valid){
            valid =0;
            a = rand() % 8; b = rand() % 7;
            for(int i=0; i<2; i++){
                for(int j=0; j<3; j++){
                    if(pc_grid[a+i][b+j]!=0){
                    valid=1;
                }}
            }
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                pc_grid[a+i][b+j]=4;
            }}
        //Fifth Ship L shape
        valid =1;
        while(valid){
            valid =0;
            a = rand() % 7; b = rand() % 7;
            for(int i=0; i<3; i++){
                if(pc_grid[a+i][b]!=0){
                    valid=1;
                }
            }
            for(int i=1; i<3; i++){
                if(pc_grid[a+2][b+i]!=0){
                    valid=1;
                }
            }}
        for(int i=0; i<3; i++){
            pc_grid[a+i][b]=5;
        }
        for(int i=1; i<3; i++){
            pc_grid[a+2][b+i]=5;
        }
        //This portion you can delete This
        //It just showing the pc battle grid
        cout<<"PC Battle Grid"
        cout<<"    ";
        for (int k=0; k<10; ++k){
            cout<<k;
            cout<< " ";
        }
        cout <<"\n";
        for (int i=0; i<10; ++i){
            cout <<i;
            cout <<" | ";
            for(int j=0; j<10; ++j)
            {
                cout<<pc_grid[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        //end of pc battle grid
        
        //Start Battle
        cout<<"\n*****Start Battle*****\n";
        int hit;
        while(ship_remain !=0){ 
            if(diff == 'e' or diff=='E')
                cout<<"\nRemaining Ship: "<<ship_remain;
            cout<<"\nEnter Coordinate to attack: ";
            cin>>z;
            for (int i = 1; i >= 0; i--) {
                coor[i] = z % 10;
                z /= 10;
            }   
            x = coor[0]; y = coor[1];
            //if coordinate are correct one of the ships are down
            if(pc_grid[x][y]==1){
                ship_remain-=1;
                cout<<"You Hit";
                //let make 9 as coordinate that is already hit
                //if difficulty is hard, the coordinate will change 9
                if(diff == 'h' or diff=='H'){
                    pc_grid[x][y]=9;
                }
                else{
                //if difficulty is easy, the ship are down
                for(int i=0; i<3; i++){
                    pc_grid[x+i][y]=9;
                }}
            }
            else if(pc_grid[x][y]==2){
                ship_remain-=1;
                cout<<"You Hit";
                if(diff == 'h' or diff=='H'){
                    pc_grid[x][y]=9;
                }
                else{
                for(int i=0; i<3; i++){
                    pc_grid[x][y+i]=9;
                }
                }
            }
            else if(pc_grid[x][y]==3){
                ship_remain-=1;
                cout<<"You Hit";
                if(diff == 'h' or diff=='H'){
                    pc_grid[x][y]=9;
                }
                else{
                for(int i=0; i<5; i++){
                    pc_grid[x+i][y]=9;
                }}
            }
            else if(pc_grid[x][y]==4){
                ship_remain-=1;
                cout<<"You Hit";
                if(diff == 'h' or diff=='H'){
                    pc_grid[x][y]=9;
                }
                else{
                for(int i=0; i<2; i++){
                    for(int j=0; j<3; j++){
                        pc_grid[x+i][y+j]=9;
                    }}
                }
            }
            else if(pc_grid[x][y]==5){
                ship_remain-=1;
                cout<<"You Hit";
                if(diff == 'h' or diff=='H'){
                    pc_grid[x][y]=9;
                }
                else{
                    for(int i=0; i<3; i++){
                        pc_grid[x+i][y]=9;
                    }
                    for(int i=1; i<3; i++){
                        pc_grid[x+2][y+i]=9;
                    }
                }
            }
            else if(pc_grid[x][y]==9){
                cout<<"You already Hit it";
            }
            else{
                ship_remain-=0;
                cout<<"You Miss";
            }
            cout<<"\n";
            //Pc turns
            if(player_grid[x][y]==1){
                cout<<"PC Hit";
                for(int i=0; i<3; i++){
                    player_grid[x+i][y]=9;
                }
            }
            else if(player_grid[x][y]==2){
                cout<<"PC Hit";
                for(int i=0; i<3; i++){
                    player_grid[x][y+i]=9;
                }
            }
            else if(player_grid[x][y]==3){
                cout<<"PC Hit";
                for(int i=0; i<5; i++){
                    player_grid[x+i][y]=9;
                }
            }
            else if(player_grid[x][y]==4){
                cout<<"PC Hit";
                for(int i=0; i<2; i++){
                    for(int j=0; j<3; j++){
                        player_grid[x+i][y+j]=9;
                    }}
            }
            else if(player_grid[x][y]==5){
                cout<<"PC Hit";
                for(int i=0; i<3; i++){
                    player_grid[x+i][y]=9;
                }
                for(int i=1; i<3; i++){
                    player_grid[x+2][y+i]=9;
                }
            }
            else{
                cout<<"PC Miss";
            }
        }
        cout<<"\nCongratulations Commander!\n";
        cout<<"Do you want to play another game, Commander?[Y|N] ";
        cin>>run;
        run = toupper(run);
    }
    return 0;
}







