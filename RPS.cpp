#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void play(){

    string player, computer = "", plays[] = {"Rock", "Paper", "Scissor"};
    int score[3] = {0, 0, 0};

    ifstream file("score.txt");

    if(file){

        for(int i=0;i<3;i++){

            file >> score[i];

        }

    }

    file.close();

    computer = plays[rand() % 3];

    cout << "---------------------------------" << endl;

    cout << "Rock, Paper or Scissor?" << endl;
    cout << "Enter your choice: ";
    cin >> player;

    cout << "---------------------------------" << endl;

    if(computer == player){

        cout << "Its a tie!\n";
        cout << "player: " << player << endl << "Computer: " << computer << endl;
        score[2]++;
        system("pause");

    }else if((computer == "Rock" && player == "Paper") ||
             (computer == "Paper" && player == "Scissor")||
             (computer == "Scissor" && player == "Rock")){

        cout << "Player Won!\n";
        cout << "player: " << player << endl << "Computer: " << computer << endl;
        score[0]++;
        system("pause");
    

    }else if((computer == "Rock" && player == "Scissor")||
             (computer == "Paper" && player == "Rock")||
             (computer == "Scissor" && player == "Paper")){

        cout << "Computer Won!\n";
        cout << "player: " << player << endl << "Computer: " << computer << endl;
        score[1]++;
        system("pause");

    }else{

        cout << "Invalid Entry, Make sure its one of the options or the first letter is capital.\n";
        return;

    }

    ofstream saveFile("score.txt");

    for(int i=0;i<3;i++){

        saveFile << score[i] << endl;

    }
    saveFile.close();

}

void score(){

    int score[3];

    ifstream file("score.txt");

    if(file){

        for(int i=0;i<3;i++){

            file>>score[i];

        }

    }

    file.close();

    cout << "---------------------------------" << endl;

    cout << "Win: " << score[0] << endl << "Loss: " << score[1] << endl << "Ties: " << score[2] << endl;
    system("pause");

}

void reset(){

    ofstream file("score.txt", ios::binary);

    file << 0 << endl << 0 << endl << 0;

    file.close();

    cout << "Successfully Reset!\n";
    system("pause");

}

int main(){

    srand(time(0));

    int choice;

    while (true) {  // Loop until user chooses to exit
        cout << "---------------------------------" << endl;
        cout << "Welcome TO RPS Game!\n" << endl;
        cout << "1: Play\n2: Score\n3: Exit\n4: Reset\n" << endl;
        cout << "What to do?: ";
        cin >> choice;

        switch (choice) {
            case 1:
    
                play();
                break;

            case 2:

                score();
                break;

            case 3:

                cout << "Exiting game...\n";
                system("pause");
                return 0;

            case 4:

                reset();
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

}