// Not yet finished
#include <deque>
#include <queue>
#include <vector>
using std::deque;
using std::queue;
using std::vector;

class Director {
   public:
    bool isAvailable() { return availability; }

    Director() : availability(true){};

   protected:
    bool availability;
};

class Manager {
   public:
    bool isAvailable() { return availability; }

    Manager() : availability(true){};

   protected:
    bool availability;
};

class Respondent {
   public:
    bool isAvailable() { return availability; }

    Respondent() : availability(true){};

   protected:
    bool availability;
};

class CallCenter {
   public:
    CallCenter() {
        deque<Respondent> r(100, Respondent());
        queue<Respondent> resqueue(r);
        respondent = std::move(resqueue);

        deque<Manager> m(10, Manager());
        queue<Manager> managerqueue(m);
        manager = std::move(managerqueue);

        director.push(Director());
    }

    size_t getNRespondent() { return respondent.size(); }
    size_t getNManager() { return manager.size(); }
    size_t getNDirector() { return director.size(); }

   private:
    queue<Respondent> respondent;
    queue<Manager> manager;
    queue<Director> director;
};

int main(int argc, const char *argv[]) {
    CallCenter callcenter;
    return 0;
}
