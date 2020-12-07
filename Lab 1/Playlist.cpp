#include "Playlist.h"

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string id, string name, string artist, int length) {
    uniqueID = id;
    songName = name;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
    this->SetNext(nodeLoc->GetNext());
    nodeLoc->SetNext(this);
}

void PlaylistNode::SetNext(PlaylistNode* nodeLoc) {
    nextNodePtr = nodeLoc;
}

string PlaylistNode::GetID() {
    return uniqueID;
}

string PlaylistNode::GetSongName() {
    return songName;
}

string PlaylistNode::GetArtistName() {
    return artistName;
}

int PlaylistNode::GetSongLength() {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist() {
    head = nullptr;
    tail = nullptr;
}

void Playlist::AddSong(string id, string name, string artist, int length) {
    PlaylistNode* n = new PlaylistNode(id, name, artist, length);
    if (head == nullptr) {
        head = tail = n;
    }
    else {
       n->InsertAfter(tail);
       tail = n;
   }
}

bool Playlist::RemoveSong(string id) {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return false;
    }
    
    PlaylistNode* curr = head;
    PlaylistNode* prev = nullptr;
    while(curr != nullptr) {
        if(curr->GetID() == id) {
            break;
        }
        prev = curr;
        curr = curr->GetNext();
    }

    if(curr == nullptr) {
        cout << "\"" << curr->GetSongName() << "\" is not found" << endl;
        return false;
    }
    else {
        if(prev != nullptr) {
            prev->SetNext(curr->GetNext());
        }
        else {
            head = curr->GetNext();
        }
        if(tail == curr) {
            tail = prev;
        }
        cout << "\"" << curr->GetSongName() << "\" removed." << endl;
        delete curr;
        return true;
    }
}

bool Playlist::ChangePosition(int oldPos, int newPos) {
    if(head == nullptr) {
        cout << "Playlist is empty" << endl;
        return false;
    }

    PlaylistNode* curr = head;
    PlaylistNode* prev = nullptr;

    int pos;
    if(head == nullptr || head == tail) {
        return false;
    }

    for(pos = 1; curr != nullptr && pos < oldPos; pos++) {
        prev = curr;
        curr = curr->GetNext();
    }

    if(curr != nullptr) {
        string currSong = curr->GetSongName();
        if(prev == nullptr) {
            head = curr->GetNext();
        }
        else {
            prev->SetNext(curr->GetNext());
        }
        if(curr == tail) {
            tail = prev;
        }
        
        PlaylistNode* newPosSong = curr;
        prev = nullptr;
        curr = head;
        
        for(pos = 1; curr != nullptr && pos < newPos; pos++) {
            prev = curr;
            curr = curr->GetNext();
        }

        if(prev == nullptr) {
            newPosSong->SetNext(head);
            head = newPosSong;
        }
        else {
            newPosSong->InsertAfter(prev);
        }
        if(curr == nullptr) {
            tail = newPosSong;
        }

        cout << "\"" << currSong << "\" moved to position " << newPos << endl;
        return true;
    }
    else {
        cout << "Song's current position is invalid" << endl;
        return false;
    }
}

void Playlist::PrintSongsByArtist(string name) {
    if(head == nullptr) {
        cout << "Playlist is empty" << endl;
    }
    else {
        PlaylistNode* curr = head;
        int i = 1;
        while(curr != nullptr) {
            if(curr->GetArtistName() == name) {
                cout << endl << i << "." << endl;
                curr->PrintPlaylistNode();
            }
            curr = curr->GetNext();
            i++;
        }
    }
}

int Playlist::TotalTime() {
    int totalTime = 0;
    PlaylistNode* curr = head;
    while(curr != nullptr) {
        totalTime += curr->GetSongLength();
        curr = curr->GetNext();
    }
    return totalTime;
}

void Playlist::PrintList() {
    if(head == nullptr) {
        cout << "Playlist is empty" << endl;
    }
    else {
        PlaylistNode* curr = head;
        int i = 1;
        while(curr != nullptr) {
            cout << i << "." << endl;
            curr->PrintPlaylistNode();
            if(curr != tail) {
                cout << endl;
            }
            curr = curr->GetNext();
            i++;
        }
    }
}