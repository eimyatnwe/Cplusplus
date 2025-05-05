#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class SpaceObject{
    public:
        virtual void draw() const{
            cout << "Drawing a generic space object.\n";
           
        }
        virtual ~SpaceObject(){}
};

class Martian: public SpaceObject{
    public:
    void draw() const override{
        cout << "Drawing a Martian with green antennas.\n";
    }
};

class Venutian : public SpaceObject{
    public:
    void draw() const override{
        cout << "Drawing a Venutian with a shiny, silver surface\n";
    }
};

class Plutonian : public SpaceObject{
    public:
    void draw() const override{
        cout << "Drawing a Plutonian with a cold, blue glow.\n";
    }
};

class Spaceship : public SpaceObject{
    public:
    void draw() const override{
        cout << "Drawing a Spaceship wiwth sleek, aerodynamic wings\n";
    }
};

class LaserBeam : public SpaceObject{
    public:
    void draw() const override{
        cout << "Drawing a LaserBeam with a bright,red streak\n";
    }
};

class Mercurian : public SpaceObject{
    public:
    void draw() const override{
        cout << "Drawing a Mercurian with a swift, silver shadow\n";
    }
};



class ScreenManager{
    vector<std::unique_ptr<SpaceObject>> objects;
    public:
        void addObject(std::unique_ptr<SpaceObject> obj){
            objects.push_back(std::move(obj));
        }
        void refreshScreen(){
            for(const auto& obj : objects){
                obj -> draw();
            }
        }
};

int main(){
    ScreenManager manager;
    manager.addObject(std::make_unique<Martian>());
    manager.addObject(std::make_unique<Venutian>());
    manager.addObject(std::make_unique<Plutonian>());
    manager.addObject(std::make_unique<Spaceship>());
    manager.addObject(std::make_unique<LaserBeam>());
    manager.refreshScreen();
    manager.addObject(std::make_unique<Mercurian>());
     manager.refreshScreen();
   
    return 0;
}