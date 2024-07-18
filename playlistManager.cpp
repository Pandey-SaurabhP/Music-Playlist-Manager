#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <termios.h>
#include <map>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define clear		system("clear")

// Start
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

// Decorations
class logo{
    public:
    vector <vector <string>> vc;
    int cur;

    logo(){
        cur = 0;
        vc.resize(3);

        vector <string> w1 = 
			{
			" .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n",
			"| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n",
			"| | ____    ____ | || | _____  _____ | || |    _______   | || |     _____    | || |     ______   | |\n",
			"| ||_   \\  /   _|| || ||_   _||_   _|| || |   /  ___  |  | || |    |_   _|   | || |   .' ___  |  | |\n",
			"| |  |   \\/   |  | || |  | |    | |  | || |  |  (__ \\_|  | || |      | |     | || |  / .'   \\_|  | |\n",
			"| |  | |\\  /| |  | || |  | '    ' |  | || |   '.___`-.   | || |      | |     | || |  | |         | |\n",
			"| | _| |_\\/_| |_ | || |   \\ `--' /   | || |  |`\\____) |  | || |     _| |_    | || |  \\ `.___.'\\  | |\n",
			"| ||_____||_____|| || |    `.__.'    | || |  |_______.'  | || |    |_____|   | || |   `._____.'  | |\n",
			"| |              | || |              | || |              | || |              | || |              | |\n",
			"| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n",
			" '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n"
			};

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

    void mpm(){
        for(int i = 0; i < vc[cur].size(); ++i){
            for(int j = 0; j < vc[cur][i].size(); ++j){
                cout << vc[cur][i][j];
            }
        }

        cout << "\t\t\t\t\tMusic Playlist Manager\n";

        cout << "-----------------------------------------------------------------------------------------------------\n";
    }

    void line(){
        cout << "-----------------------------------------------------------------------------------------------------\n";
    }

    void jiit(){
        cout << " 	 .----------------.  .----------------.  .----------------.  .----------------. \n";
        cout << " 	| .--------------. || .--------------. || .--------------. || .--------------. |\n";
        cout << " 	| |     _____    | || |     _____    | || |     _____    | || |  _________   | |\n";
        cout << " 	| |    |_   _|   | || |    |_   _|   | || |    |_   _|   | || | |  _   _  |  | |\n";
        cout << " 	| |      | |     | || |      | |     | || |      | |     | || | |_/ | | \\_|  | |\n";
        cout << " 	| |   _  | |     | || |      | |     | || |      | |     | || |     | |      | |\n";
        cout << " 	| |  | |_' |     | || |     _| |_    | || |     _| |_    | || |    _| |_     | |\n";
        cout << " 	| |  `.___.'     | || |    |_____|   | || |    |_____|   | || |   |_____|    | |\n";
        cout << " 	| |              | || |              | || |              | || |              | |\n";
        cout << " 	| '--------------' || '--------------' || '--------------' || '--------------' |\n";
        cout << " 	'----------------'  '----------------'  '----------------'  '----------------'\n";
    }
};

logo lg;

// DS Definitions
template <typename T>
class BSTSet {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool count(Node* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }

        if (value < node->data) {
            return count(node->left, value);
        } else if (value > node->data) {
            return count(node->right, value);
        } else {
            return true; // Element found
        }
    }

    void inorderTraversal(Node* node, vector<T>& result) const {
        if (node != nullptr) {
            inorderTraversal(node->left, result);
            result.push_back(node->data);
            inorderTraversal(node->right, result);
        }
    }

    int size(Node* node) const {
        return (node == nullptr) ? 0 : 1 + size(node->left) + size(node->right);
    }

public:
    BSTSet() : root(nullptr) {}

    void insert(const T& value) {
        root = insert(root, value);
    }

    bool count(const T& value) const {
        return count(root, value);
    }

    int getSize() const {
        return size(root);
    }

    vector<T> getAllElements() const {
        vector<T> result;
        inorderTraversal(root, result);
        return result;
    }
};

// Struct Definitions
class Song{
public:
    string name;
    string genre;
    string artist;
};


// Global dataset


map <string, vector <int>> playlists;
map <int, Song> songList;

// Global Display Functions
void displayPlaylist(){
	cout << "\tPlaylists Data :\n";

	for (const auto& playlist : playlists) {
	    cout << playlist.first << " : ";

	    for (const auto& songId : playlist.second) {
	        const Song& song = songList[songId];
	        cout << "\t" << song.name << " " << song.genre << " " << song.artist << "\n";
	    }

	    cout << "\n";
	}

	cout << "\n\n";
}

void displayPlaylist(string playlistName){

	cout << "\tPlaylists Data : " << playlistName << "\n";

	for(auto jt : playlists[playlistName]){
		cout << "\t" << jt << ". " << songList[jt].name << "\n";
	}
	cout << "\n\n";
	
}

void displaySongList(){

	cout << "\n\tSong Lists :\n";
    for(auto it : songList){
		cout << "\t" << it.ff << " " << it.ss.name << "\n";
	}
}

// Load Data Functions
void loadPlaylist() {
    const char delimiter = ' ';

    map<string, vector<int>> dataMap;

    ifstream inputFile("playlists.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file playlist!" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string key;
        int value;

        if (iss >> key >> value) {
            dataMap[key].push_back(value);
        }
    }

    inputFile.close();
    playlists = dataMap;

// Debug Statement
    // displayPlaylist();
}

void loadSongList() {
    map<int, Song> songMap;

    ifstream inputFile("songList.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file song!" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int key;
        Song song;

        if (iss >> key >> song.name >> song.genre >> song.artist) {
            songMap[key] = song;
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    inputFile.close();
    songList = songMap;

    // Debug Statement
    // displaySongList();
}


// Writing Data Functions
void writeData() {

	const string filename = "playlists.txt";
    char delimiter = ' ';

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Error opening the file for writing: " << filename << endl;
        return;
    }

    for (const auto& pair : playlists) {
        for (const auto& value : pair.second) {
            outputFile << pair.first << delimiter << value << endl;
        }
    }

    outputFile.close();

// Debug Statement
    // displayPlaylist();
}

void addToPlaylist(string playlistName, int songId){

	cout << "Adding...\n";
	playlists[playlistName].pb(songId);
	writeData();
}


// Main Functions
void createPlaylist(){

	clear;
	lg.mpm();


	string playlistName;

	cout << "\t\t\t\t\tCREATE PLAYLIST\n";

	cout << "\n\tEnter playlist Name : ";
	cin >> playlistName;

	if(playlists.count(playlistName)){
		cout << "\n\t:( Playlist already exists. Enter another ...\n";
		getch();
		createPlaylist();
		return;
	}

	displaySongList();

	cout << "\n";
	lg.line();

	BSTSet <int> songSet;
	cout << "\tEnter space seperated song number, end with -1 : ";

	int inp;
	cin >> inp;

	while(inp != -1){
		songSet.insert(inp);
		cin >> inp;
	}

	vector <int> elems = songSet.getAllElements();

	for(auto it : elems){
		for(auto jt : songList){
			if(it == jt.first){
				addToPlaylist(playlistName, it);
				break;
			}
		}
	}

	cout << "\n\tSuccessfully Added...Press any key to continue\n";
	getch();
}

// Opening File
void openFile(const string fileName){

	#ifdef _WIN32
	    string command = "start ";
	#else
	    string command = "xdg-open ";
	#endif

    command += fileName;

    int result = system(command.c_str());

    if (result == 0) {
        cout << "\tFile opened successfully." << endl;
    } else {
        cerr << "\tError opening the file." << endl;
    }
}

// Open Playlist
int openCurAt = 0;
int psz;
vector<char> openOptions(psz);

void openPlaylist(){
	clear;
	lg.mpm();

	cout << "\t\t\t\t\tOPEN A PLAYLIST\n\n";

// Init
	openOptions.assign(' ', openOptions.size());
	openOptions[openCurAt] = '*';

	int x = 0;
	for(auto it : playlists){
		cout << "\t\t\t\t\t" << openOptions[x] << " " << it.first << " " << openOptions[x] << "\n";
		++x;
	}

	cout << "\n";
	lg.line();

	cout << "\t\t\t\tPRESS S, or W to navigate, and X to SELECT\n";

	char ch = getch();

	ch = tolower(ch);

	if(ch == 'w'){
		--openCurAt;
		if(openCurAt < 0) openCurAt += psz;
		openCurAt %= psz;
	}
	else if(ch == 's'){
		++openCurAt;
		openCurAt %= psz;
	}
	else if(ch == 'x'){
		int x = 0;
		for(auto it : playlists){
			if(x == openCurAt){
				int inp = openCurAt;

				displayPlaylist(it.first);

				lg.line();
				cout << "\tPress any key to confirm, 0 to cancel\n";
				char ch = getch();

				if(ch == '0'){
					cout << "\tConfirmation failed...\n";
					openPlaylist();
					return;
				}

				lg.line();
				cout << "\tDo you want to shuffle, 0 for NO, Any Other for YES\n";
				lg.line();

				ch = getch();

				BSTSet <int> opened;

				if(ch != '0'){
					int sz = playlists[it.first].size();

					while (opened.getSize() != sz) {
					    int r = rand() % sz;

					    if (!opened.count(r)) {
					        opened.insert(r);
					        openFile(songList[playlists[it.first][r]].name);
					    }
					}
				}
				else{
					for(auto jt : playlists[it.first]){
						openFile(songList[jt].name);
					}
				}

				return;
			}
			
			++x;
		}
	}

	openPlaylist();
}

// Edit Playlist
void addSong(string playlistName){
	displayPlaylist(playlistName);
	lg.line();
	displaySongList();

	BSTSet <int> songSet;
	cout << "\tEnter song number, end with -1 : ";

	int inp;
	cin >> inp;
	cout << "\n";

	while(inp != -1){
		songSet.insert(inp);
		cin >> inp;
	}

	vector <int> elem = songSet.getAllElements();

	for(auto it : elem){
		for(auto jt : songList){
			if(it == jt.first){
				addToPlaylist(playlistName, it);
				break;
			}
		}
	}
}

void removeSong(string playlistName){
	displayPlaylist(playlistName);

	BSTSet <int> songSet;
	cout << "\tEnter song number, end with -1 : ";

	int inp;
	cin >> inp;

	while(inp != -1){
		songSet.insert(inp);
		cin >> inp;
	}

	vector <int> tmp;

	for(auto it : playlists[playlistName]){
		if(!songSet.count(it)){
			tmp.pb(it);
		}
	}

	playlists[playlistName] = tmp;
	writeData();
}


void editPlaylist(){
	// Add or remove Songs
	clear;
	lg.mpm();

	map <int, string> playlistMap;
	int sno = 1;

	for(auto it : playlists){
		cout << "\t" << sno << ". " << it.first << "\n";
		playlistMap[sno++] = it.first;
	}

	cout << "\tEnter the playlist Code to Edit :";
	int inp; cin >> inp;

	cout << "\n";
	lg.line();



	if(playlistMap.count(inp)){
		cout << "\t1. Add song[s]\n";
		cout << "\t2. Remove song[s]\n";
		cout << "\t3. Go Back [Any other key]\n";


		cout << "\tEnter option from [1-3] :";
		int inp2;
		cin >> inp2;


		cout << "\n";
		lg.line();

		string playlistName = playlistMap[inp];

// Add Song Done
		if(inp2 == 1){
			addSong(playlistName);
		}
// Remove song Done
		else if(inp2 == 2){
			removeSong(playlistName);
		}
// Quit
		else{
			return;
		}
	}
	else{
		cout << "\tEnter valid playlist please...\n";
		editPlaylist();
	}
}

// Trie Implementation


class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    vector<string> search(const string& prefix) {
        vector<string> results;
        TrieNode* node = searchNode(prefix);
        if (node != nullptr) {
            collectStrings(node, prefix, results);
        }
        return results;
    }

    bool startsWith(const string& prefix) {
        return (searchNode(prefix) != nullptr);
    }

private:
    TrieNode* root;

    TrieNode* searchNode(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return nullptr; // Prefix not found
            }
            current = current->children[ch];
        }
        return current;
    }

    void collectStrings(TrieNode* node, const string& currentPrefix, vector<string>& results) {
        if (node->isEndOfWord) {
            results.push_back(currentPrefix);
        }

        for (const auto& child : node->children) {
            collectStrings(child.second, currentPrefix + child.first, results);
        }
    }
};

Trie tr;
string pref;

void search(){

	clear;

	lg.mpm();
	cout << "\t\t\t\t\t\tSEARCH\n\n";
	cout << "\t\t\t\tEnter Song Name : " << pref << "\n";

	lg.line();
	cout << "\n";

	vector <string> tmp = tr.search(pref);

	if(tmp.size() == 0){

		cout << "\t\tSong Not Available...\n";
		lg.line();

		cout << "\tEnter song name to Search for it...";
		cout << "\n";
	}
	else{
		int x = 1;

		for(auto it : tmp){
			cout << "\t" << x << ". " << it << "\n";
			++x;
		}
		cout << "\n";

		lg.line();
		cout << "\tEnter song name to Search for it...Use a-z to ENTER, [ as BACKSPACE, ] as CANCEL/BACK\n";
		cout << "\n";
	}

	char ch = getch();

	if(ch == '['){

		if (pref.size() > 0) {
		    pref = pref.substr(0, pref.size() - 1);
		}

		search();

	}
	else if(ch == ']'){

		pref = "";
		return;
	}
	else if(ch == '-'){
		for(auto it : tmp){
			openFile(it);
		}

		cout << "\tDone\n";
	}
	else{
		pref += ch;
		search();
	}


}

void searchInit(){

	for(auto it : songList){
		tr.insert(it.second.name);
	}
}


int initCurAt = 0;
vector <char> initOptions(5);

void initPage(){
// Done
	clear;
	lg.mpm();

	initOptions.assign(' ', 5);
	initOptions[initCurAt] = '*';

	cout << "\n\t\t\t\t\t" << initOptions[0] << " Search for a SONG " << initOptions[0] << "\n\n"; 
	cout << "\t\t\t\t\t" << initOptions[1] << " Create a playlist " << initOptions[1] << "\n\n";
	cout << "\t\t\t\t\t" << initOptions[2] << " Open a playlist " << initOptions[2] << "\n\n";
	cout << "\t\t\t\t\t" << initOptions[3] << " Edit a playlist " << initOptions[3] << "\n\n";
	cout << "\t\t\t\t\t" << initOptions[4] << " Exit " << initOptions[4] << "\n\n";

	lg.line();

	cout << "\t\t\t\tPRESS S, or W to navigate, and X to SELECT\n";

	char ch = getch();
	ch = tolower(ch);

	if(ch == 'w'){
		initCurAt = (initCurAt - 1 + 5) % 5;
	}
	else if(ch == 's'){
		initCurAt = (initCurAt + 1) % 5;
	}
	else if(ch == 'x'){
		if(initCurAt == 1){
			createPlaylist();
		}
		else if(initCurAt == 2){
			openPlaylist();
		}
		else if(initCurAt == 3){
			editPlaylist();
		}
		else if(initCurAt == 0){
			search();
		}
		else{
			return;
		}
	}

	initPage();
}

void splashScreen(){
	clear;

	lg.jiit();
	lg.mpm();

	cout << "\t\t\t\tPress Any key to continue, Ctrl + C to exit\n";

	getch();

	initPage();
}


int main(){
	srand(time(NULL));

	loadSongList();
	loadPlaylist();
	searchInit();

	psz = playlists.size();

	splashScreen();
	// initPage();

    return 0;
}