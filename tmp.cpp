#include <bits/stdc++.h>
#include <unistd.h>
#include <termios.h>
#include <cstdlib>

using namespace std;

char getch(void){
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

void clear(){
    system("clear");
}

class logo{
    public:

    vector <vector <string>> vc;
    int cur;

    logo(){
        cur = 0;
        vc.resize(3);

        vector <string> w1 = {" .----------------.  .----------------.  .----------------.  .----------------. \n",
                              "| .--------------. || .--------------. || .--------------. || .--------------. |\n",
                              "| |  _________   | || |   ______     | || |     ____     | || |    _______   | |\n",
                              "| | |  _   _  |  | || |  |_   _ \\    | || |   .'    `.   | || |   /  ___  |  | |\n",
                              "| | |_/ | | \\_|  | || |    | |_) |   | || |  /  .--.  \\  | || |  |  (__ \\_|  | |\n",
                              "| |     | |      | || |    |  __'.   | || |  | |    | |  | || |   '.___`-.   | |\n",
                              "| |    _| |_     | || |   _| |__) |  | || |  \\  `--'  /  | || |  |\\____)  |  | |\n",
                              "| |   |_____|    | || |  |_______/   | || |   `.____.'   | || |  |_______.'  | |\n",
                              "| |              | || |              | || |              | || |              | |\n",
                              "| '--------------' || '--------------' || '--------------' || '--------------' |\n",
                              "'----------------'  '----------------'  '----------------'  '----------------' \n"};

        vector <string> w2 = {"__/\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\_________/\\\\__________/\\\\\\\\\\\\___      \n",
                            "__\\///////\\\\/////__\\/\\\\/////////\\\\_____/\\\\///\\\\______/\\\\/////////\\\\_        \n",
                            "_________\\/\\\\_______\\/\\\\_______\\/\\\\___/\\\\/__\\///\\\\___\\//\\\\______\\///__        \n", 
                            "__________\\/\\\\_______\\/\\\\\\\\\\\\\\___/\\\\______\\//\\\\___\\////\\\\_________        \n",
                            "    _______\\/\\\\_______\\/\\\\/////////\\\\_\\/\\\\_______\\/\\\\______\\////\\\\______    \n",
                            "    ________\\/\\\\_______\\/\\\\_______\\/\\\\_\\//\\\\______/\\\\__________\\////\\\\___   \n",
                            "    _________\\/\\\\_______\\/\\\\_______\\/\\\\__\\///\\\\__/\\\\_____/\\\\______\\//\\\\__  \n",
                            "    __________\\/\\\\_______\\/\\\\\\\\\\\\\\/_____\\///\\\\\\/_____\\///\\\\\\\\\\\\/___ \n",
                            "        _______\\///_______\\/////////////_________\\/////_________\\///////////___\n",
                            "\n", "\n"};

         vector <string> w3 =  {"\n\n\t\t    ███     ▀█████████▄   ▄██████▄     ▄████████ \n",
                                "\t\t▀█████████▄   ███    ███ ███    ███   ███    ███ \n",
                                "\t\t   ▀███▀▀██   ███    ███ ███    ███   ███    █▀  \n",
                                "\t\t    ███   ▀  ▄███▄▄▄██▀  ███    ███   ███        \n",
                                "\t\t    ███     ▀▀███▀▀▀██▄  ███    ███ ▀███████████ \n",
                                "\t\t    ███       ███    ██▄ ███    ███          ███ \n",
                                "\t\t    ███       ███    ███ ███    ███    ▄█    ███ \n",
                                "\t\t   ▄████▀   ▄█████████▀   ▀██████▀   ▄████████▀  \n", "\n"};
                                                 

        vc[0] = w1;
        vc[1] = w2;
        vc[2] = w3;
    }

    void tbos(){
        for(int i = 0; i < vc[cur].size(); ++i){
            for(int j = 0; j < vc[cur][i].size(); ++j){
                cout << vc[cur][i][j];
            }
        }

        cout << "\t\t\tText Based Operating System\n";

        cout << "--------------------------------------------------------------------------------\n";
    }

    void jiit(){
        cout << " .----------------.  .----------------.  .----------------.  .----------------. \n";
        cout << "| .--------------. || .--------------. || .--------------. || .--------------. |\n";
        cout << "| |     _____    | || |     _____    | || |     _____    | || |  _________   | |\n";
        cout << "| |    |_   _|   | || |    |_   _|   | || |    |_   _|   | || | |  _   _  |  | |\n";
        cout << "| |      | |     | || |      | |     | || |      | |     | || | |_/ | | \\_|  | |\n";
        cout << "| |   _  | |     | || |      | |     | || |      | |     | || |     | |      | |\n";
        cout << "| |  | |_' |     | || |     _| |_    | || |     _| |_    | || |    _| |_     | |\n";
        cout << "| |  `.___.'     | || |    |_____|   | || |    |_____|   | || |   |_____|    | |\n";
        cout << "| |              | || |              | || |              | || |              | |\n";
        cout << "| '--------------' || '--------------' || '--------------' || '--------------' |\n";
        cout << "'----------------'  '----------------'  '----------------'  '----------------'\n";
    }
};

logo lg;

class Calendar {
private:
    int year;
    int month;

public:
    Calendar() {
        time_t now = time(nullptr);
        tm* currentTime = localtime(&now);
        year = currentTime->tm_year + 1900;
        month = currentTime->tm_mon + 1;
    }

    void run() {
        clear();

        char choice;
        do {

            clear();

            lg.tbos();
            cout << "\n\t\t\t\t*** Calendar ***\n";
            
            displayCalendar();

            cout << "\n\t\tN - Next month\t P - Previous Month\t Q - Quit\n";
            
            choice = getch();

            switch (toupper(choice)) {
                case 'N':
                    nextMonth();
                    break;
                case 'P':
                    prevMonth();
                    break;
                case 'Q':
                    cout << "Exiting the calendar. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (toupper(choice) != 'Q');
    }

private:
    void displayCalendar() {
        clear();

        lg.tbos();
        cout << "\n\t\t\t\t*** Calendar ***\n";

        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\t       " << getMonthName() << " " << year << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\t Sun Mon Tue Wed Thu Fri Sat" << endl;

        int startDay = getStartDay();
        int daysInMonth = getDaysInMonth();
        int day = 1;

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if(j == 0){
                    cout << "\t\t\t";
                }
                if (i == 0 && j < startDay) {
                    cout << "    ";
                } else if (day <= daysInMonth) {
                    cout << " " << setw(2) << day << " ";
                    day++;
                }
            }

            cout << endl;

            if (day > daysInMonth)
                break;
        }

        cout << "\t\t\t---------------------------" << endl;
    }

    void nextMonth() {
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    void prevMonth() {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
    }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getDaysInMonth() {
        if (month == 2) {
            return isLeapYear() ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    int getStartDay() {
        tm timeStruct = { 0 };
        timeStruct.tm_year = year - 1900;
        timeStruct.tm_mon = month - 1;
        timeStruct.tm_mday = 1;
        mktime(&timeStruct);
        return timeStruct.tm_wday;
    }

    string getMonthName() {
        switch (month) {
            case 1:
                return "January";
            case 2:
                return "February";
            case 3:
                return "March";
            case 4:
                return "April";
            case 5:
                return "May";
            case 6:
                return "June";
            case 7:
                return "July";
            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12:
                return "December";
            default:
                return "";
        }
    }
};

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    bool gameEnded;

public:
    TicTacToe() {
        currentPlayer = 'X';
        gameEnded = false;

        // Initialize the board with empty spaces
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void playGame() {
        char choice;
        int row, col;

        do {

            
            clear();
            lg.tbos();
            cout << "\n\t\t\t*** Tic-Tac-Toe ***\n\n";

            printBoard();
            
            if (currentPlayer == 'X') {
                cout << "\t\tPlayer " << currentPlayer << ", enter your move (row column): ";
                cin >> row >> col;

                if (isValidMove(row, col)) {
                    board[row][col] = currentPlayer;

                    if (checkWin()) {
                        clear();
                        lg.tbos();
                        cout << "\n\t\t\t*** Tic-Tac-Toe\n\n";
                        printBoard();

                        cout << "\t\t\t\tPlayer " << currentPlayer << " wins!" << endl;
                        gameEnded = true;
                    } else if (isBoardFull()) {
                        clear();
                        printBoard();
                        cout << "\t\t\t\tIt's a tie!" << endl;
                        gameEnded = true;
                    } else {
                        switchPlayer();
                    }
                } else {
                    cout << "\t\t\tInvalid move. Try again." << endl;
                }
            } else {
                makeComputerMove();
                if (checkWin()) {
                    clear();
                    lg.tbos();
                    cout << "\n\t\t\t*** Tic-Tac-Toe\n\n";
                    printBoard();

                    cout << "\t\t\tComputer wins!" << endl;
                    gameEnded = true;
                } else if (isBoardFull()) {
                    clear();
                    lg.tbos();
                    cout << "\n\t\t\t*** Tic-Tac-Toe\n\n";
                    printBoard();

                    cout << "\t\t\tIt's a tie!" << endl;
                    gameEnded = true;
                } else {
                    switchPlayer();
                }
            }
        } while (!gameEnded);

        cout << "\t\t\t\t   Game Over" << endl;

        char ch = getch();
    }

private:

    void printBoard() {
            cout << "\t\t\t\t-------------" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if(j == 0){
                        cout << "\t\t\t\t";
                    }

                    cout << "| " << board[i][j] << " ";
                }
                cout << "|" << endl;
                cout << "\t\t\t\t-------------\n" << endl;
            }
    }

    bool isValidMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
            return true;
        return false;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
                return true;
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
            return true;

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void makeComputerMove() {
        // Simple random move for the computer player
        srand(time(nullptr));

        int row, col;
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (!isValidMove(row, col));

        board[row][col] = currentPlayer;
        cout << "\t\tComputer placed " << currentPlayer << " at position " << row << ", " << col << endl;
    }
};

class AddressBook {
private:
    struct Address {
        string name;
        string street;
        string city;
        string state;
        string zipCode;
    };

public:
    void run() {

        char choice;
        do {
            clear();
            lg.tbos();
            cout << "\n\n";
            
            cout << "\t\t\t*** Address Book ***" << "\n\n";

            cout << "\t\t\tMenu:\n\n";
            cout << "\t\t\t1. Add a new address\n\n";
            cout << "\t\t\t2. View saved addresses\n\n";
            cout << "\t\t\t3. Quit\n\n";
            cout << "\t\t\tEnter your choice (1-3): ";
            
            choice = getch();

            switch (choice) {
                case '1':
                    createAddress();
                    break;
                case '2':
                    viewAddresses();
                    break;
                case '3':
                    cout << "\t\t\tExiting the program. Goodbye!" << endl;
                    break;
                default:
                    cout << "\t\t\tInvalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != '3');
    }

private:
    void createAddress() {
        clear();
        lg.tbos();
        cout << "\n\n";
        
        cout << "\t\t\t*** Address Book ***" << "\n\n";

        Address address;

        cout << "\n\t\t\tEnter the name: ";
        getline(cin >> ws, address.name);

        cout << "\n\t\t\tEnter the street: ";
        getline(cin, address.street);

        cout << "\n\t\t\tEnter the city: ";
        getline(cin, address.city);

        cout << "\n\t\t\tEnter the state: ";
        getline(cin, address.state);

        cout << "\n\t\t\tEnter the zip code: ";
        getline(cin, address.zipCode);

        saveAddress(address);
    }

    void viewAddresses() {
        ifstream file("addresses.txt");
        if (file.is_open()) {

            clear();
            lg.tbos();
            cout << "\n\n";
            
            cout << "\t\t\t*** Address Book ***" << "\n\n";

            cout << "\t\t\tSaved Addresses" << endl;

            string line;
            while (getline(file, line)) {
                int pos1 = line.find(',');
                int pos2 = line.find(',', pos1 + 1);
                int pos3 = line.find(',', pos2 + 1);
                int pos4 = line.find(',', pos3 + 1);

                if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos && pos4 != string::npos) {
                    string name = line.substr(0, pos1);
                    string street = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    string city = line.substr(pos2 + 1, pos3 - pos2 - 1);
                    string state = line.substr(pos3 + 1, pos4 - pos3 - 1);
                    string zipCode = line.substr(pos4 + 1);

                    cout << "Name: " << name << "\n\n";
                    cout << "Street: " << street << "\n\n";
                    cout << "City: " << city << "\n\n";
                    cout << "State: " << state << "\n\n";
                    cout << "Zip Code: " << zipCode << "\n\n";
                    cout << "------------------------" << endl;
                }
            }

            file.close();
        } else {
            cout << "Error: Unable to open the addresses file." << endl;
        }

        char ch = getch();
    }

    void saveAddress(const Address& address) {
        ofstream file("addresses.txt", ios::app);
        if (file.is_open()) {
            file << address.name << "," << address.street << "," << address.city << "," << address.state << ","
                 << address.zipCode << endl;
            file.close();
            cout << "Address saved successfully." << endl;
        } else {
            cout << "Error: Unable to open the addresses file." << endl;
        }
    }
};

class Memo {
public:
    void show() {
        clear();

        lg.tbos();
        cout << "\n\t\t\t\t*** Memo ***" << endl;

        char choice;
        do {

            clear();

            lg.tbos();
            cout << "\n\t\t\t\t*** Memo ***" << endl;

            cout << "\n\t\t\t\t   Menu:\n\n";
            cout << "\t\t\t\t1. Write a new memo\n\n";
            cout << "\t\t\t\t2. View saved memos\n\n";
            cout << "\t\t\t\t3. Quit\n";
            
            choice = getch();

            switch (choice) {
                case '1':
                    writeMemo();
                    break;
                case '2':
                    viewMemos();
                    break;
                case '3':
                    cout << "Exiting the program. Goodbye!" << "\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != '3');
    }

private:
    void writeMemo() {

        clear();

        lg.tbos();
        cout << "\n\t\t\t\t*** Memo ***" << endl;

        cout << "\tEnter your memo. Press Enter on an empty line to save and exit." << endl;

        string memo;
        while (true) {
            string line;
            getline(cin, line);

            if (line.empty()) {
                saveMemo(memo);
                break;
            }

            memo += line + "\n";
        }
    }

    void saveMemo(const string& memo) {
        ofstream file("memo.txt");
        if (file.is_open()) {
            file << memo;
            file.close();
            cout << "Memo saved successfully." << endl;
        } else {
            cout << "Error: Unable to open the memo file." << endl;
        }
    }

    void viewMemos() {
        ifstream file("memo.txt");
        if (file.is_open()) {
            clear();

            lg.tbos();
            cout << "\n\t\t\t\t*** Memo ***" << endl;

            cout << "\n\t\t\t   Saved Memos     " << endl << endl;

            string line;
            while (getline(file, line)) {
                cout << "\t\t\t" << line << endl << endl;
            }

            file.close();
        } else {
            cout << "Error: Unable to open the memo file." << endl;
        }

        char ch = getch();
    }
};

class Wallpaper{
    public:
    void change(){
        lg.cur++;
        lg.cur %= 3;
    }
};

struct Contact {
    string name;
    string phoneNumber;
};

class Phonebook {  

public:
    void show() {
        

        char choice;
        do {
            clear();

            lg.tbos();
            cout << "\n\t\t\t\t*** PHONEBOOK ***" << endl;

            cout << "\n\t\t\t\tMenu:\n\n";
            cout << "\t\t\t1. Create a new contact\n\n";
            cout << "\t\t\t2. View saved contacts\n\n";
            cout << "\t\t\t3. Quit\n\n";
            cout << "\t\t\tEnter your choice (1-3): ";
            
            choice = getch();

            switch (choice) {
                case '1':
                    createContact();
                    break;
                case '2':
                    viewContacts();
                    break;
                case '3':
                    break;
                default:
                    break;
            }
        } while (choice != '3');
    }

private:
    void createContact() {

        clear();
        lg.tbos();

        cout << "\n\t\t\t\t*** PHONEBOOK ***" << endl;
        cout << "\t\t\t\t New Contact\n\n";

        Contact contact;



        cout << "\tEnter the contact name: ";
        getline(cin >> ws, contact.name);

        cout << "\tEnter the phone number: ";
        getline(cin, contact.phoneNumber);

        saveContact(contact);
    }

    void viewContacts() {
        ifstream file("contacts.txt");
        if (file.is_open()) {
            clear();
            lg.tbos();
            cout << "\n\t\t\t\t*** PHONEBOOK ***" << endl;

            cout << "\n\t\t\t*** Saved Contacts ***" << "\n\n";

            string line;
            while (getline(file, line)) {
                int pos = line.find(',');
                if (pos != string::npos) {
                    string name = line.substr(0, pos);
                    string phoneNumber = line.substr(pos + 1);
                    cout << "\t\tName: " << name << ", Phone Number: " << phoneNumber << "\n\n";
                }
            }

            file.close();
        } else {
            cout << "Error: Unable to open the contacts file." << endl;
        }

        char ch = getch();
    }

    void saveContact(const Contact& contact) {
        ofstream file("contacts.txt", ios::app);
        if (file.is_open()) {
            clear();
            lg.tbos();
            cout << "\n\t\t\t\t*** PHONEBOOK ***" << "\n\n";

            file << contact.name << "," << contact.phoneNumber << endl;
            file.close();
            cout << "Contact saved successfully." << endl;
        } else {
            cout << "Error: Unable to open the contacts file." << endl;
        }
    }
};

class Calculator {
public:
    void show() {
        clear();

        lg.tbos();
        cout << "\n\t\t\t\t*** CALCULATOR ***\n\n\n";

        double num1, num2;
        char operation;
        
        cout << "\t\tEnter the first number: ";
        cin >> num1;

        cout << "\t\tEnter an operator (+, -, *, /): ";
        cin >> operation;

        cout << "\t\tEnter the second number: ";
        cin >> num2;

        double result = 0.0;

        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    return;
                }
                break;
            default:
                cout << "Error: Invalid operator." << endl;
                return;
        }

        cout << "\n\t\t\t\tResult: " << result << endl;
        cout << "--------------------------------------------------------------------------------\n";
        cout << "\t\tPress X to perform another calculation\n\n";

        char ch;
        ch = getch();

        if(tolower(ch) == 'x'){
            show();
        }
        else return;
    }
};

class Sudoku {
public:
    Sudoku() {
        board_ = generateRandomBoard();
        deleteElements(30);
    }

    void play() {
        while (true) {
            displayBoard();

            int row, col, num;
            cout << "\t\tEnter row (1-9), column (1-9), and number" << "\n\t\t\t" << "(1-9) to fill (or 0 to quit): ";
            cin >> row;

            if (row == 0) {
                break;
            }

            cin >> col >> num;

            if (isValidInput(row, col, num)) {
                board_[row - 1][col - 1] = num;
            }
            else {
                cout << "\t\t\tInvalid input! Try again.\n";
            }
        }
    }

private:
    vector<vector<int>> board_;

    void clear() {
        system("clear");
    }

    void displayBoard() {
        clear();

        lg.tbos();
        cout << "\n\n";
        cout << "\t\t\t\tSudoku\n\n";

        for (int i = 0; i < 9; ++i) {

            for (int j = 0; j < 9; ++j) {
                if(j == 0){
                    cout << "\t\t\t";
                }
                if (j % 3 == 0 && j != 0) {
                    cout << "| ";
                }

                if (board_[i][j] != 0) {
                    cout << board_[i][j] << " ";
                }
                else {
                    cout << ". ";
                }
            }

            cout << "\n";

        }

        cout << "\n";

    }

    vector<vector<int>> generateRandomBoard() {
        vector<vector<int>> board(9, vector<int>(9, 0));

        random_device rd;
        mt19937 g(rd());

        for (int i = 0; i < 9; ++i) {
            vector<int> row = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            shuffle(row.begin(), row.end(), g);

            for (int j = 0; j < 9; ++j) {
                board[i][j] = row[j];
            }
        }

        return board;
    }

    void deleteElements(int numElements) {
        random_device rd;
        mt19937 g(rd());

        for (int i = 0; i < numElements; ++i) {
            int row = uniform_int_distribution<int>(0, 8)(g);
            int col = uniform_int_distribution<int>(0, 8)(g);

            if (board_[row][col] != 0) {
                board_[row][col] = 0;
            }
            else {
                --i;
            }
        }
    }

    bool isValidInput(int row, int col, int num) {
        return (row >= 1 && row <= 9) && (col >= 1 && col <= 9) && (num >= 1 && num <= 9);
    }
};

class MainMenu{

public:
    int n = 30;
    int m = 49;

    int curAt;
    int opnCnt;
    char sym[8];
    string options[8];

    MainMenu(){
        curAt = 0;
        opnCnt = 8;

        for(int i = 0; i < opnCnt; ++i){
            sym[i] = ' ';
        }
        sym[0] = '*';

        options[0] = "Calculator";
        options[1] = "PhoneBook";
        options[2] = "MemoPad";
        options[3] = "Address";
        options[4] = "Sudoku";
        options[5] = "Calender";
        options[6] = "Wallpaper";
        options[7] = "Tic-Tac-Toe";
    }

    void show()
    {
        clear();
        lg.tbos();
        cout << "\n\n";
        cout << "\t\t" << sym[0] << " " << options[0] << " " << sym[0] << "\t\t\t" << sym[1] << " " << options[1] << " " << sym[1] << "\n\n\n";
        cout << "\t\t" << sym[2] << " " << options[2] << " " << sym[2] << "\t\t\t" << sym[3] << " " << options[3] << " " << sym[3] << "\n\n\n";
        cout << "\t\t" << sym[4] << " " << options[4] << " " << sym[4] << "\t\t\t" << sym[5] << " " << options[5] << " " << sym[5] << "\n\n\n";
        cout << "\t\t" << sym[6] << " " << options[6] << " " << sym[6] << "\t\t\t" << sym[7] << " " << options[7] << " " << sym[7] << "\n";

        char choice = getch();

        if (tolower(choice) == 'd')
        {
            ++curAt;
            curAt %= 8;
        }
        else if (tolower(choice) == 'a')
        {
            --curAt;
            curAt += 8;
            curAt %= 8;
        }
        else if(tolower(choice) == 's'){
            curAt += 2;
            curAt %= 8;
        }
        else if(tolower(choice) == 'w'){
            curAt -= 2;
            curAt += 8;
            curAt %= 8;
        }
        else if(tolower(choice) == 'b'){
            return;
        }
        else if (tolower(choice == 'x')){
            // Lock
            if(curAt == 0){
                Calculator c;
                c.show();
            }
            else if(curAt == 1){
                Phonebook p;
                p.show();
            }
            else if(curAt == 2){
                Memo m;
                m.show();
            }
            else if(curAt == 3){
                AddressBook a;
                a.run();
            }
            else if(curAt == 4){
                Sudoku s;
                s.play();
            }
            else if(curAt == 5){
                Calendar c;
                c.run();
            }
            else if(curAt == 6){
                Wallpaper w;
                w.change();   
            }
            else if(curAt == 7){
                TicTacToe ttt;
                ttt.playGame();
            }
        }
        else if(tolower(choice) == 'b'){
            return;
        }

        for (int i = 0; i < opnCnt; ++i)
        {
            if (i == curAt){
                sym[i] = '*';
            }
            else{
                sym[i] = ' ';
            }
        }

        show();
    }

};

class Desktop
{

public:
    int n = 30;
    int m = 49;

    int curAt;
    int opnCnt;
    char sym[2];
    string options[2];

    Desktop()
    {
        curAt = 0;
        opnCnt = 2;

        sym[0] = '*';
        sym[1] = ' ';

        options[0] = "Menu";
        options[1] = "Exit";
    }

    void show()
    {
        clear();
        lg.jiit();
        lg.tbos();
        cout << "\n\t\t" << sym[0] << " " << options[0] << " " << sym[0] << "\t\t\t" << sym[1] << " " << options[1] << " " << sym[1] << "\t\n";

        char choice = getch();

        if (tolower(choice) == 'd'){
            ++curAt;
            curAt %= 2;
        }
        else if (tolower(choice) == 'a'){
            --curAt;
            curAt += 2;
            curAt %= 2;
        }
        else if (tolower(choice == 'x')){
            // Lock
            if(curAt == 0){
                MainMenu m;
                m.show();
            }
            else{
                // Exit
                return;
            }
        }

        for (int i = 0; i < opnCnt; ++i){
            if (i == curAt){
                sym[i] = '*';
            }
            else{
                sym[i] = ' ';
            }
        }

        show();
    }
};

int main()
{

    // fast();
    Desktop s;
    s.show();

    return 0;
}