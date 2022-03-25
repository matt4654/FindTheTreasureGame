#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>
#include <ctime> 

int main()
{
    system("cls");
    char restartOrexit;

    do
    { 
        //Two random numbers between -30 and 30

        srand(time(NULL));
        int iPN = 2 * (rand()%2 - 0.5);
        int jPN = 2 * (rand()%2 - 0.5);
        int i = iPN * rand()%30;
        int j = jPN * rand()%30;

        //Player and treasure locations

        int playerLoc[2] = {0, 0};
        int treasureLoc[2] = {i, j};

        //Player stamina levels (difficulty)

        int playerStam = 1;
        bool safe = false;
        int brutal = abs(i) + abs(j) + 1;
        int easy = 3.5 * brutal;
        int normal = 3 * brutal;
        int hard = 1.5 * brutal;

        //Difficulty Selection

        char diff;  
        do
        {
            std::cout << "Select Difficulty" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "1. Safe" << std::endl;
            std::cout << "2. Easy" << std::endl;
            std::cout << "3. Normal" << std::endl;
            std::cout << "4. Hard" << std::endl;
            std::cout << "5. Brutal" << std::endl;
            std::cout << " " << std::endl;
            std::cin >> diff;
        
            switch(diff)
            {
                case '1':
                {
                    safe = true;
                }
                break;
                case '2':
                {             
                    playerStam = easy;
                }
                break;
                case '3':
                {
                    playerStam = normal;
                }
                break;
                case '4':
                {
                    playerStam = hard;
                }
                break;
                case '5':
                {
                    playerStam = brutal;
                }
                break;
                default:
                {
                    system("cls");
                    std::cout << "Invalid Entry: Use 1,2,3,4,5 to Select a Difficulty" << std::endl;
                    std::cout << " " << std::endl;
                }

            }
        }
        while(diff != '1' && diff != '2' && diff != '3' && diff != '4' && diff != '5');
        system("cls");

        //Gameplay (Infinite and Finite)

        char input;
        if(safe)
        {
            do
            {
                int a = abs(playerLoc[0] - treasureLoc[0]);
                int b = abs(playerLoc[1] - treasureLoc[1]);
                double treasureDist = std::round(sqrt(pow(a,2) + pow(b,2)));

                std::string stamina = "00";

                std::cout << "Player Coordinates" << "  |  " << "Treasure Distance" << "  |  " << "Stamina" << std::endl;
                std::cout << " " << std::endl;
                std::cout << "      " << playerLoc[0]  << " , " << playerLoc[1] << "                 " << treasureDist << " m"
                << "                " << stamina << std::endl;
                std::cout << " " << std::endl;

                input = getch();
                switch(input)
                {
                    case 'w':
                    {
                        playerLoc[1]++;
                        system("cls");
                    }
                    break;
                    case 'a':
                    {   
                        playerLoc[0]--;
                        system("cls");
                    }
                    break;
                    case 's':
                    {
                        playerLoc[1]--;
                        system("cls");
                    }
                    break;
                    case 'd':
                    {
                        playerLoc[0]++;
                        system("cls");
                    }
                    break;
                    default:
                    {
                        system("cls");
                        std::cout << "Invalid Entry: Use W,A,S,D to Navigate" << std::endl;
                        std::cout << " " << std::endl;
                    }
                }
            }
            while((playerLoc[0] != treasureLoc[0] || playerLoc[1] != treasureLoc[1]));
        }
        else
        {
            do
            {
                int a = abs(playerLoc[0] - treasureLoc[0]);
                int b = abs(playerLoc[1] - treasureLoc[1]);
                double treasureDist = std::round(sqrt(pow(a,2) + pow(b,2)));

                std::string stamina;
                for(int k = 0; k<playerStam; k++)
                {
                    stamina += "X";
                }   

                std::cout << "Player Coordinates" << "  |  " << "Treasure Distance" << "  |  " << "Stamina" << std::endl;
                std::cout << " " << std::endl;
                std::cout << "      " << playerLoc[0]  << " , " << playerLoc[1] << "                 " << treasureDist << " m"
                << "                " << stamina << std::endl;
                std::cout << " " << std::endl;

                input = getch();
                switch(input)
                {
                    case 'w':
                    {
                        playerLoc[1]++;
                        playerStam--;
                        system("cls");
                    }
                    break;
                    case 'a':
                    {   
                        playerLoc[0]--;
                        playerStam--;
                        system("cls");
                    }
                    break;
                    case 's':
                    {
                        playerLoc[1]--;
                        playerStam--;
                        system("cls");
                    }
                    break;
                    case 'd':
                    {
                        playerLoc[0]++;
                        playerStam--;
                        system("cls");
                    }
                    break;
                    default:
                    {
                        system("cls");
                        std::cout << "Invalid Entry: Use W,A,S,D to Navigate" << std::endl;
                        std::cout << " " << std::endl;
                    }
                }
            }
            while((playerLoc[0] != treasureLoc[0] || playerLoc[1] != treasureLoc[1]) && playerStam != 0);
        }

        //Win and fail states
        
        if(playerStam != 0)
        {
            std::cout << "YOU HAVE FOUND THE TREASURE!!!" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "It was at " << treasureLoc[0] << " , " << treasureLoc[1] << std::endl; 
            std::cout << " " << std::endl;
        }
        else
        {
            std::cout << "GAME OVER" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "You ran out of stamina" << std::endl; 
            std::cout << " " << std::endl;
        }

        //Restart or Exit

        char restartOrexitchocie;
        do
        {
            std::cout << "1. Restart" << std::endl;
            std::cout << "2. Exit" << std::endl;
            std::cin >> restartOrexitchocie;
            switch(restartOrexitchocie)
            {
                case '1':
                {
                    restartOrexit = 'r';
                }
                break;
                case '2':
                {
                    restartOrexit = 'e';
                }
                break;
                default:
                {
                    restartOrexit = 'NA';
                    system("cls");
                    std::cout << "Invalid Entry: Use 1,2 to Select" << std::endl;
                    std::cout << " " << std::endl;
                }
            }
        }
        while(restartOrexit !='r' && restartOrexit !='e');
        system("cls");
    }
    while(restartOrexit !='e');

    return 0;
}