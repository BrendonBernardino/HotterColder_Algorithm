#include <iostream>
using namespace std;

#define JILL_NUMBER 453
#define SIZE_LIST   1000

#define FINISH_GAME 99
#define SAME        0
#define HOTTER      1
#define COLDER      -1

int previous_guess;
int previous_diff = abs(previous_guess - JILL_NUMBER);
int step_counter = 0;
bool first_guess = true;

int Guess(int G) {
    int current_diff = abs(G - JILL_NUMBER);
    
    if (first_guess) { // Primeiro palpite sempre retorna SAME
        first_guess = false;
        previous_diff = current_diff;
        return SAME;
    }
    if(G == JILL_NUMBER) // Palpite certo, acaba o game
        return FINISH_GAME;
    else if (current_diff == previous_diff) { // Nem mais longe nem mais perto
        previous_diff = current_diff;
        return SAME;
    } 
    else if (current_diff < previous_diff) { // Mais próximo do que antes
        previous_diff = current_diff;
        return HOTTER;
    } 
    else if (current_diff > previous_diff) { // Mais longe do que antes
        previous_diff = current_diff;
        return COLDER;
    }
    return FINISH_GAME;
}

int HC(int N) {
    int low = 1;
    int high = N;
    int guess = high; // Primeiro palpite é N
    previous_guess = 0;

    while (low < high) {
        cout << "Guess: " << guess << endl;
        step_counter++;

        int response = Guess(guess);
        if (response == HOTTER) {
            cout << "HOTTER" << endl;
            if(previous_guess > guess) 
                high = (guess + high)/2;

            if(previous_guess < guess)
                low = (guess + low)/2;
        } 
        else if (response == COLDER) {
            cout << "COLDER" << endl;
            if(previous_guess > guess)
                low = (guess + low)/2;

            if(previous_guess < guess)
                high = (guess + high)/2;
        }
        else if (response == SAME)
            cout << "SAME" << endl;

        else if(response == FINISH_GAME)
            return guess;

        previous_guess = guess;
        cout << "[" << low << "," << high << ']' << endl;
        if(response == SAME && guess == previous_guess) //Casos especiais
            guess = guess + 1;

        if(response != SAME) //Padrão
            guess = (low + high) / 2;
    }
    return low;
}

int main() {
    int result = HC(SIZE_LIST);
    cout << "O Numero de Jill eh: " << result << endl;
    cout << step_counter << " passos." << endl;
    return 0;
}