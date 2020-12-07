#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <string>
using namespace std;

class PlaylistNode {
    public:
        PlaylistNode();
        PlaylistNode(string id, string name, string artist, int length);
        void InsertAfter(PlaylistNode* nodeLoc);
        void SetNext(PlaylistNode* nodeLoc);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};

class Playlist {
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
    public:
        Playlist();
        void AddSong(string id, string name, string artist, int length);
        bool RemoveSong(string id);
        bool ChangePosition(int oldPos, int newPos);
        void PrintSongsByArtist(string name);
        int TotalTime();
        void PrintList();
};
#endif
