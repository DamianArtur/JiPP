#include <iostream>
#include <string>

using namespace std;

class Note {

protected:
    string title;

public:

    string getTitle() const {
        return title;
    }

    void setTitle(const string new_title) {
        title = new_title;
    }

    virtual string getContent() const;

    virtual void setContent(const string);
};

class TextNote : public Note {

private:
    string content;

public:

    string getContent() const {
        return content;
    }

    void setContent(const string new_content) {
        content = new_content;
    }

};

int main() {
    return 0;
}