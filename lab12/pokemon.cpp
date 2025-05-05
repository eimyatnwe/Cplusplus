#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
using namespace std;

class Pokemon{
    public:
        string name,sound,type;
        int power,speed;
        Pokemon(string names,string sounds,string types,int pow,int speeds){
            name = names;
            sound = sounds;
            type = types;
            power = pow;
            speed = speeds;
        }
        string getName() const{
            return name;
        }
        string getSound() const{
            return sound;
        }
        string getType() const{
            return type;
        }
        int getPower() const{
            return power;
        }
        int getSpeed() const{
            return speed;
        }
};

class WildPokemon : public Pokemon{
    public:
        int catchRate;
        WildPokemon(string names,string sounds,string types,int pow,int speeds,int catchRate) 
        : Pokemon(names,sounds,types,pow,speeds){
            catchRate = 2 * (speeds + pow);
        };

        int getCatchRate() const{
            return catchRate;
        }

        bool attemptEscape() {
            int randomNum = rand() % 100 + 1;
            return randomNum > catchRate;
    }
};

class PalPokemon : public Pokemon{
    public:
        PalPokemon(string names,string sounds,string types,int pow,int speeds):Pokemon(names,sounds,types,pow,speeds){};

};

class Pokeball{
    private:
        string name;
        int efficiency;
    public:
        
        Pokeball(string nam,int effic){
            name = nam;
            efficiency = effic;
        };

        string getName() const{
            return name;
        }

        int getEfficiency() const{
            return efficiency;
        }

        void increaseEfficiency(int amount) {
            efficiency += amount;
        }

        bool catchPokemon(const WildPokemon& wildPokemon) const {
            int catchChance = efficiency - wildPokemon.getCatchRate();
            int randomChance = rand() % 100 + 1; // Generate a random number between 1 and 100

            if (randomChance <= catchChance) {
        // Pokemon is caught
                return true;
            } else {
        // Pokemon broke free
                return false;
            }
    }
};

class Berry {
private:
    std::string name;
    int effectiveness;

public:
    Berry(std::string name, int effectiveness) : name(name), effectiveness(effectiveness) {}

    void applyEffect(Pokeball& pokeball) {
        pokeball.increaseEfficiency(effectiveness);
        std::cout << "Berry " << name << " applied. Pokeball efficiency increased by " << effectiveness << std::endl;
    }
};

class Player {
private:
    std::vector<Pokeball> pokeballsCollection;
    std::vector<WildPokemon> caughtPokemons; // Vector to store caught Pokémons
    Berry* berry;

public:
    Player() {
        berry = nullptr;
    }

    void addBerry(Berry* newBerry) {
        berry = newBerry;
    }

    void addPokeBall(const Pokeball& pokeball) {
        pokeballsCollection.push_back(pokeball);
    }

    bool catchPokemon(const WildPokemon& wild) {
        if (pokeballsCollection.empty()) {
            std::cout << "There are no Pokéballs left." << std::endl;
            return false;
        }

        for (size_t i = 0; i < pokeballsCollection.size(); ++i) {
            if (pokeballsCollection[i].catchPokemon(wild)) {
                std::cout << "You caught wild " << wild.getName() << "!" << std::endl;
                // Remove the Pokeball from the collection
                pokeballsCollection.erase(pokeballsCollection.begin() + i);
                // Add the caught Pokemon to the caughtPokemons vector
                caughtPokemons.push_back(wild);
                return true;
            }
        }

        std::cout << "The wild " << wild.getName() << " escaped!" << std::endl;
        return false;
    }

    void listPokeballs() const {
        std::cout << "List of Pokéballs:" << std::endl;
        for (const Pokeball& pokeball : pokeballsCollection) {
            std::cout << "Name: " << pokeball.getName() << ", Efficiency: " << pokeball.getEfficiency() << std::endl;
        }
    }

    void listCaughtPokemons() const {
        std::cout << "List of caught Pokémons:" << std::endl;
        for (const WildPokemon& pokemon : caughtPokemons) {
            std::cout << "Name: " << pokemon.getName() << ", Type: " << pokemon.getType() << std::endl;
        }
    }
};


class World {
private:
    std::vector<WildPokemon> wilds;

public:
    World() {}

    void addWild(const WildPokemon& wildPoke) {
        wilds.push_back(wildPoke);
    }

    WildPokemon generateRandomEncounter() const {
        if (wilds.empty()) {
            throw std::runtime_error("No wild Pokémon in the world.");
        }

        int randomIndex = rand() % wilds.size();
        return wilds[randomIndex];
    }

    void simulateUser(Player& player) {
        std::cout << "Player exploration starts....." << std::endl;
        if (rand() % 5 == 0) { // % probability of encountering wild Pokémon
            WildPokemon randomWild = generateRandomEncounter();
            std::cout << "Encountered a wild " << randomWild.getName() << "!" << std::endl;
            player.catchPokemon(randomWild);
        }
    }
};


class GameTester {
public:
    static void testCatchPokemon(Player& player, const WildPokemon& wildPokemon) {
        std::cout << "Testing catchPokemon method..." << std::endl;
        player.catchPokemon(wildPokemon);
    }

    static void testPokeball(Pokeball& pokeball, const WildPokemon& wildPokemon) {
        std::cout << "Testing Pokeball functionality..." << std::endl;
        bool result = pokeball.catchPokemon(wildPokemon);
        if (result) {
            std::cout << "Pokemon was caught!" << std::endl;
        } else {
            std::cout << "Pokemon escaped!" << std::endl;
        }
    }

    static void testBerry(Berry* berry, Pokeball& pokeball) {
        std::cout << "Testing Berry functionality..." << std::endl;
        berry->applyEffect(pokeball);
        int enhancedEfficiency = pokeball.getEfficiency(); 
        std::cout << "Enhanced efficiency: " << enhancedEfficiency << std::endl;
    }


    static void testPlayerWorldInteraction(Player& player, World& world) {
        std::cout << "Simulating player-world interaction..." << std::endl;
        world.simulateUser(player);
    }

};


int main() {
    
    srand(static_cast<unsigned>(time(0)));
    Player player;

    // Add berries to player's inventory
    Berry berry("Power Berry", 10);
    player.addBerry(&berry);

    // Add pokeballs to player's inventory
   

    

    // Create virtual world
    World world; 
    int choice;
    while(true){
        cout << "Choose an action:\n 1. Add Pokeballs to stock\n 2. Walk\n 3.List Pokeballs\n 4.List caught Pokemon\n 5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1){
            world.addWild(WildPokemon("Pikachu", "Pika pika!", "Electric", 70, 100, 70));
            world.addWild(WildPokemon("Bulbasaur", "Bulba bulba!", "Grass", 65, 80, 60));
            world.addWild(WildPokemon("Charmander", "Char char!", "Fire", 70, 90, 75));
            world.addWild(WildPokemon("Squirtle", "Squirt squirt!", "Water", 68, 85, 65));
            world.addWild(WildPokemon("Jigglypuff", "Jiggly jiggly!", "Normal", 60, 75, 55));

            Pokeball normalPokeball1("Normal", 80);
            Pokeball normalPokeball2("Normal", 80);
            Pokeball normalPokeball3("Normal", 80);
            Pokeball strongPokeball("Strong", 90);
            Pokeball ultraPokeball("Ultra", 95);
            player.addPokeBall(normalPokeball1);
            player.addPokeBall(normalPokeball2);
            player.addPokeBall(normalPokeball3);
            player.addPokeBall(strongPokeball);
            player.addPokeBall(ultraPokeball);

        }else if(choice == 2){
           world.simulateUser(player);
        }else if(choice == 3){
             player.listPokeballs();
        }else if(choice == 4){
            player.listCaughtPokemons();
        }
        else if(choice == 5){
            break;
        }
    } 

    return 0;
}