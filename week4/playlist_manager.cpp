#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

struct Artist{
    string name;
    string hometown;
};

struct Song{
    string title;
    Artist artist;
    string genre;
    int durationSeconds;
};


void inputSongs(Song songs[], int numSongs){
    for (int i = 0; i < numSongs; i++){
        cout << "Enter information for song " << i + 1 << ": " << endl;
        
        cout << "   Title: ";
        getline(cin, songs[i].title);

        cout << "   Artist name: ";
        getline(cin, songs[i].artist.name);
        
        cout << "   Artist hometown: ";
        getline(cin, songs[i].artist.hometown);

        cout << "   Genre: ";
        getline(cin, songs[i].genre);

        cout << "   Duration in seconds: ";
        cin >> songs[i].durationSeconds;
        cin.ignore(1000, '\n');
        
        cout << endl;
    }
}

void displayPlaylist(Song songs[], int numSongs){
    for (int i = 0; i < numSongs; i++){
        cout << "   " << i + 1 << ". " << songs[i].title << endl;

        cout << "   Artist: " << songs[i].artist.name << " (" << songs[i].artist.hometown << ")" << endl;

        cout << "   Genre: " << songs[i].genre << endl;

        int minutes = songs[i].durationSeconds / 60;
        int seconds = songs[i].durationSeconds % 60;
        cout << "   Duration: " << minutes << ":" << setw(2) << setfill('0') << seconds << setfill(' ') << endl;

        cout << endl;

    }
}

void displayStats(Song songs[], int numSongs){
    int totalSeconds = 0;
    string longestSong = "";
    int longestDuration = 0;

    for (int i = 0; i < numSongs; i++){
        totalSeconds += songs[i].durationSeconds;

        if (songs[i].durationSeconds > longestDuration){
            longestDuration = songs[i].durationSeconds;
            longestSong = songs[i].title;
        }
    }
    int totalMinutes = totalSeconds / 60;
    int totalRemainingSeconds = totalSeconds % 60;

    int longestMinutes = longestDuration / 60;
    int longestSeconds = longestDuration % 60;

    cout << "   Total runtime: " << totalMinutes << ":" << setw(2) << setfill('0') << totalRemainingSeconds << setfill(' ') << endl;
    cout << "   Longest song: " << longestSong << " (" << longestMinutes << ":" << setw(2) << setfill('0') << longestSeconds << setfill(' ') << ")" << endl;
    cout << endl;
}

string toLowerCase(string text){
    for (int i = 0; i < text.length(); i++){
        text[i] = tolower(text[i]);
    }
    return text;
}

void searchByArtist(Song songs[], int numSongs){
    string searchArtist;
    bool found = false;

    cout << "Search by artist: ";
    getline(cin, searchArtist);

    cout << "Songs by artist: " << searchArtist << endl;

    string lowerSearchArtist = toLowerCase(searchArtist);

    for (int i = 0; i < numSongs; i++){
        if (toLowerCase(songs[i].artist.name) == lowerSearchArtist){
            found = true;

            int minutes = songs[i].durationSeconds / 60;
            int seconds = songs[i].durationSeconds % 60;

            cout << "   - " << songs[i].title << " (" << minutes << ":" << setw(2) << setfill('0') << seconds << setfill(' ') << ")" << endl;
        }

    }
    if (!found){
        cout << "No songs found by " << searchArtist << "." << endl;
    }
    cout << endl;
}

void searchByGenre(Song songs[], int numSongs){
    string searchGenre;
    bool found = false;

    cout << "Search by genre: ";
    getline(cin, searchGenre);

    cout << "Songs in genre: " << searchGenre << endl;

    string lowerSearchGenre = toLowerCase(searchGenre);

    for (int i = 0; i < numSongs; i++){
        if (toLowerCase(songs[i].genre) == lowerSearchGenre){
            found = true;

            int minutes = songs[i].durationSeconds / 60;
            int seconds = songs[i].durationSeconds % 60;

            cout << "   - " << songs[i].title << " (" << minutes << ":" << setw(2) << setfill('0') << seconds << setfill(' ') << ")" << endl;
        }
    }
    if (!found){
        cout << "  No songs found in that genre." << endl;
    }
    cout << endl;
}

int main(){

    const int numSongs = 5;
    Song songs[numSongs];

    cout << "PERSONAL PLAYLIST MANAGER" << endl;
    cout << "-------------------------" << endl;

    inputSongs(songs, numSongs);

    cout << "YOUR PLAYLIST:" << endl;
    cout << "--------------" << endl;
    displayPlaylist(songs, numSongs);

    cout << "Playlist Stats:" << endl;
    displayStats(songs, numSongs);

    searchByArtist(songs, numSongs);

    searchByGenre(songs, numSongs);
}

