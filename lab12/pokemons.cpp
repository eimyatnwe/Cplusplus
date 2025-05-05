#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // for rand()

class Pokemon {
protected:
    std::string name;
    std::string sound;
    std::string type;
    int power;
    int speed;

public:
    Pokemon(std::string name, std::string sound, std::string type, int power, int speed)
        : name(name), sound(sound), type(type), power(power), speed(speed) {}

    std::string getName() const { return name; }
    std::string getSound() const { return sound; }
    std::string getType() const { return type; }
    int getPower() const { return power; }
    int getSpeed() const { return speed; }
};

class WildPokemon : public Pokemon {
private:
    int catchRate;

public:
    WildPokemon(std::string name, std::string sound, std::string type, int power, int speed, int catchRate)
        : Pokemon(name, sound, type, power, speed), catchRate(catchRate) {}

    int getCatchRate() const { return catchRate; }

    bool attemptEscape() const {
        // Simulate escape behavior based on speed and random chance
        int escapeChance = speed * 10; // Higher speed increases the chance of escape
        return rand() % 100 < escapeChance;
    }
};

class PalPokemon : public Pokemon {
public:
    PalPokemon(std::string name, std::string sound, std::string type, int power, int speed)
        : Pokemon(name, sound, type, power, speed) {}
};

class Pokeball {
private:
    std::string name;
    int efficiency;

public:
    Pokeball(std::string name, int efficiency) : name(name), efficiency(efficiency) {}

    int getEfficiency() const { return efficiency; }
    std::string getName() const {return name; }

    bool catchPokemon(const WildPokemon& wildPokemon) const {
        int catchChance = efficiency * wildPokemon.getCatchRate();
        return rand() % 100 < catchChance;
    }
};

class Berry {
private:
    std::string name;
    int effectiveness;

public:
    Berry(std::string name, int effectiveness) : name(name), effectiveness(effectiveness) {}

    int applyEffect(int initialEfficiency) const {
        return initialEfficiency + effectiveness;
    }
};

class Player {
private:
    std::vector<Pokeball> pokeballCollection;
    std::vector<WildPokemon> capturedPokemon;
    bool hasStockpiledPokeballs;

public:
    Player() : hasStockpiledPokeballs(false) {}

    void addPokeball(const Pokeball& newBall) {
        pokeballCollection.push_back(newBall);
    }

    void addCapturedPokemon(const WildPokemon& pokemon) {
        capturedPokemon.push_back(pokemon);
    }

    void stockpilePokeballs() {
        if (!hasStockpiledPokeballs) {
            for (int i = 0; i < 5; ++i) {
                // Add five Pokéballs of random types to the inventory
                int efficiency = rand() % 50 + 50; // Random efficiency between 50 and 100
                std::string ballType;
                switch(rand() % 3) {
                    case 0:
                        ballType = "Normal";
                        break;
                    case 1:
                        ballType = "Strong";
                        break;
                    case 2:
                        ballType = "Ultra";
                        break;
                }
                addPokeball(Pokeball(ballType, efficiency));
            }
            hasStockpiledPokeballs = true;
        }
    }

    bool catchPokemon(const WildPokemon& wildPokemon) {
        if (pokeballCollection.empty()) {
            std::cout << "Out of Pokeballs!" << std::endl;
            return false;
        }

        for (Pokeball& ball : pokeballCollection) {
            if (ball.catchPokemon(wildPokemon)) {
                addCapturedPokemon(wildPokemon);
                std::cout << "You caught the wild " << wildPokemon.getName() << "!" << std::endl;
                return true;
            }
        }

        std::cout << "The wild " << wildPokemon.getName() << " escaped!" << std::endl;
        return false;
    }

    void displayPokeballs() const {
        std::cout << "Current Pokeball Inventory:" << std::endl;
        for (const Pokeball& ball : pokeballCollection) {
            std::cout << ball.getName() << " (Efficiency: " << ball.getEfficiency() << ")" << std::endl;
        }
    }

    void displayCapturedPokemon() const {
        std::cout << "Captured Pokemon:" << std::endl;
        for (const WildPokemon& pokemon : capturedPokemon) {
            std::cout << pokemon.getName() << std::endl;
        }
    }
};

class World {
private:
    std::vector<WildPokemon> wildPokemonCollection;

public:
    World() {}

    void addWildPokemon(const WildPokemon& newPokemon) {
        wildPokemonCollection.push_back(newPokemon);
    }

    void simulateExploration(Player& player) {
        for (int i = 0; i < 5; ++i) {
            if (rand() % 100 < 25) { // 25% probability of encountering wild Pokemon
                int randomIndex = rand() % wildPokemonCollection.size();
                WildPokemon wildPokemon = wildPokemonCollection[randomIndex];
                std::cout << "Encountered a wild " << wildPokemon.getName() << "!" << std::endl;

                std::cout << "Attempt to catch? (Y/N): ";
                char choice;
                std::cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    player.catchPokemon(wildPokemon);
                }
            }
        }
    }
};

class GameTester {
public:
    static void runTests() {
        Player player;
        World world;

        // Populate world with diverse set of wild Pokemon
        world.addWildPokemon(WildPokemon("Pikachu", "Pika Pika!", "Electric", 50, 60, 70));
        world.addWildPokemon(WildPokemon("Charmander", "Char Char!", "Fire", 60, 50, 80));
        world.addWildPokemon(WildPokemon("Squirtle", "Squirtle Squirt!", "Water", 55, 55, 75));
        world.addWildPokemon(WildPokemon("Bulbasaur", "Bulba Bulba!", "Grass", 65, 45, 85));
        world.addWildPokemon(WildPokemon("Jigglypuff", "Jiggly Jiggly!", "Fairy", 45, 65, 65));

        // Player's actions
        player.stockpilePokeballs();
        player.displayPokeballs();
        world.simulateExploration(player);
        player.displayCapturedPokemon();
    }
};

int main() {
    GameTester::runTests();

    return 0;
}
