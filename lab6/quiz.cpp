#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string questionText;
    vector<string> options;
    char correctAnswer; 
};

class QuizQuestion {
public:
    int score;
    int currentIndex;
    char userAnswer;
    QuizQuestion() : score(0), currentIndex(0) {}

    void displayQuestion(const vector<Question>& questions) {
        while (currentIndex < questions.size()) {
            const Question& currentQuestion = questions[currentIndex];
            cout << "Question: " << currentIndex + 1 << " " << currentQuestion.questionText << "\n";

            for (int j = 0; j < currentQuestion.options.size(); j++) {
                cout << currentQuestion.options[j] << endl;
            }
            cout << "Enter answer (a, b, c): ";
            cin >> userAnswer;
            checkAnswer(questions[currentIndex]); 
            currentIndex++;
        }
    }

    void checkAnswer(const Question& currentQuestion) {
        switch (userAnswer) {
            case 'a':
            case 'b':
            case 'c':
                if (userAnswer == currentQuestion.correctAnswer) {
                    score++;
                    cout << "Correct!\n";
                } else {
                    cout << "Incorrect Answer! The correct Answer is: " << currentQuestion.correctAnswer << endl;
                }
                break;
            default:
                cout << "Invalid answer. Please enter a valid option.\n";
        }
    }
};

int main() {
    vector<Question> questions = {
        {"What is the capital of France?",{"a) Berlin","b) Paris","c) London"},'b'},
        {"Which planet is known as the Red Planet?",{"a) Mars","b) Jupiter","c) Saturn"},'a'},
        {"What is the largest mammal?",{"a) Elephant","b) Blue Whale","c) Giraffe"},'b'},
        {"Who wrote Hamlet?",{"a) Mark Twain","b) Charles Dickens","c) William Shakespeare"},'c'},
        {"What is the chemical symbol for water?",{"a) H2O","b) CO2","c) O2"},'a'}
    };

    QuizQuestion quiz;
    quiz.displayQuestion(questions);

    cout << "Quiz completed! Your total score is: " << quiz.score << endl;

    return 0;
}
