#include <string>
using namespace std;

class Movie {
private:
    string title;
    string language;
    int duration;

public:
    // COMPILE-TIME POLYMORPHISM: overloaded constructors.
    Movie() : title(""), language(""), duration(0) {}

    Movie(const string& title, const string& language, int duration)
        : title(title), language(language), duration(duration) {}

    string getTitle() const {
        return title;
    }

    string getLanguage() const {
        return language;
    }

    int getDuration() const {
        return duration;
    }
};