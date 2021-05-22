#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

enum GENRE {
    DRAMA,
    COMEDY,
    MUSICAL,
    ROMANCE,
    DETECTIVE,
    THRILLER,
    HORROR,
    CARTOON,
    FANTASY,
    DOCUMENTARY,
};

string  getGenre (GENRE genre) {
    switch (genre) {
        case GENRE::DRAMA:
            return "DRAMA";
        case GENRE::COMEDY:
            return "COMEDY";
        case GENRE::MUSICAL:
            return "MUSICAL";
        case GENRE::ROMANCE:
            return "ROMANCE";
        case GENRE::DETECTIVE:
            return "DETECTIVE";
        case GENRE::THRILLER:
            return "THRILLER";
        case GENRE::HORROR:
            return "HORROR";
        case GENRE::CARTOON:
            return "CARTOON";
        case GENRE::FANTASY:
            return "FANTASY";
        case GENRE::DOCUMENTARY:
            return "DOCUMENTARY";
    }
}

class Movie {
    string name;
    string studio;
    unsigned int rating;
    unsigned int year;
    GENRE genre;
public:
    Movie(const string &name, const string &studio, unsigned int rating, unsigned int year, GENRE genre) :
        name(name),
        studio(studio),
        rating(rating),
        year(year),
        genre(genre) {
    }

    const string &getName() const {
        return name;
    }

    const string &getStudio() const {
        return studio;
    }

    unsigned int getRating() const {
        return rating;
    }

    unsigned int getYear() const {
        return year;
    }


    GENRE getGenre() const {
        return genre;
    }

    string getDescription() {
        return name + " " + studio + " " + ::getGenre(genre) + " " + to_string(year) + ", " + to_string(rating);
    }

    static Movie *createBubbleStudioMovie() {
        return new Movie("Major Grom", "Bubble", 75, 2021, DETECTIVE);
    }

    static Movie *createMarvelMovie() {
        return new Movie("Capitan Marvel", "Marvel", 65, 2019, FANTASY);
    }

    static  Movie *createColumbiaPicturesMovie(GENRE genre = GENRE::FANTASY) {
        return new Movie("Ghostbusters", "ColumbiaPictures", 80, 1984, COMEDY);
    }

};

int main() {

    vector<Movie *> Movies1, Movies2;

    Movies1.push_back(Movie::createBubbleStudioMovie());

    for (int i = 0; i < 5; i++) {
        Movies1.push_back(Movie::createColumbiaPicturesMovie(GENRE::FANTASY));
    }

    cout << "Order 1: " << endl;
    for (int i = 0, len = Movies1.size(); i < len; i++) {
        std::cout << Movies1[i]->getDescription() << endl;
    }

    for (int i = 0; i < 5; i++) {
        Movies2.push_back(Movie::createMarvelMovie());
    }

    cout << "Order 2: " << endl;
    for (int i = 0, len = Movies2.size(); i < len; i++) {
        std::cout << Movies2[i]->getDescription() << endl;
    }

    return 0;
}
