#include "Playlist.h"

void PrintMenu(string title);

int main() {
    string playlistTitle;

    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    
    PrintMenu(playlistTitle);

    return 0;
}

void PrintMenu(string title) {
    Playlist list;
    string id;
    string songName;
    string artistName;
    int songLength;
    int oldPos;
    int newPos;
    char userInput;

    while(true) {
       cout << endl << title << " PLAYLIST MENU" << endl;
       cout << "a - Add song" << endl;
       cout << "d - Remove song" << endl;
       cout << "c - Change position of song" << endl;
       cout << "s - Output songs by specific artist" << endl;
       cout << "t - Output total time of playlist (in seconds)" << endl;
       cout << "o - Output full playlist" << endl;
       cout << "q - Quit" << endl << endl;

       cout << "Choose an option:" << endl;
       cin >> userInput;
       cin.ignore();

       if (userInput == 'q' || userInput == 'Q')
       {
           exit(1);
       }
       else if (userInput == 'a' || userInput == 'A')
       {
           cout << "ADD SONG" << endl;
           cout << "Enter song's unique ID:" << endl;
           cin >> id;
           cin.ignore();//ignore newline
           cout << "Enter song's name:" << endl;
           getline(cin, songName);
           cout << "Enter artist's name:" << endl;
           getline(cin, artistName);
           cout << "Enter song's length (in seconds):" << endl;
           cin >> songLength;
           list.AddSong(id, songName, artistName, songLength);
       }
       else if (userInput == 'd' || userInput == 'D')
       {
           cout << "REMOVE SONG" << endl;
           cout << "Enter song's unique ID:" << endl;
           cin >> id;
           list.RemoveSong(id);
       }
       else if (userInput == 'c' || userInput == 'C')
       {
           cout << "CHANGE POSITION OF SONG" << endl;
           cout << "Enter song's current position:" << endl;
           cin >> oldPos;
           cout << "Enter new position for song:" << endl;
           cin >> newPos;
           list.ChangePosition(oldPos, newPos);
       }
       else if (userInput == 's' || userInput == 'S')
       {
           cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
           cout << "Enter artist's name:" << endl;
           getline(cin, artistName);         
           list.PrintSongsByArtist(artistName);
       }
       else if (userInput == 't' || userInput == 'T')
       {
           cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
           cout << "Total time: " << list.TotalTime() << " seconds" << endl;
       }
       else if (userInput == 'o' || userInput == 'O')
       {
           cout << title << " - OUTPUT FULL PLAYLIST" << endl;
           list.PrintList();
       }
       else
       {
           cout << "Invalid menu choice! Please try again." << endl;
       }
    }
}