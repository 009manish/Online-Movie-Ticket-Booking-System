#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cinema {
private:
    string name;
    // COMPOSITION: Cinema owns its Screen objects.
    vector<Screen> screens;
public:
    explicit Cinema(const string& name)
        : name(name) {}

    string getName() const {
        return name;
    }
    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }
    vector<Screen>& getScreens() {
        return screens;
    }
    const vector<Screen>& getScreens() const {
        return screens;
    }
    void listMovies(const vector<Movie>& movies) const {
        cout << "\n===== CURRENTLY PLAYING MOVIES =====\n";
        if (movies.empty()) {
            cout << "No movies available.\n";
            return;
        }
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". "<< movies[i].getTitle()<< " | " << movies[i].getLanguage()<< " | " << movies[i].getDuration()<< " min\n";
        }
    }
};