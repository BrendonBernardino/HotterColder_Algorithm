#include <iostream>
using namespace std;

#define FINISH_GAME 99
#define SAME        0
#define HOTTER      1
#define COLDER      -1

int jill_number; // The global variable to store Jill's number
int previous_guess; // The global variable to store Jack's previous guess
bool first_guess = true;
int previous_diff = abs(previous_guess - jill_number);

int passos = 0;

int Guess(int G) {
    int current_diff = abs(G - jill_number);

    if (first_guess) {
        first_guess = false;
        // previous_guess = G;
        previous_diff = current_diff;
        return SAME; // Same for the first guess
    }
  
    if(G == jill_number) {
        return FINISH_GAME;
    }
    else if (current_diff == previous_diff) {
        previous_diff = current_diff;
        return SAME;
    } 
    else if (current_diff < previous_diff) {
        previous_diff = current_diff;
        return HOTTER;
    } 
    else if (current_diff > previous_diff) {
        previous_diff = current_diff;
        return COLDER;
    }
}

int HC(int N) {
    int low = 1;
    int high = N;
    previous_guess = 0;
    int guess = high;
    int contador = 17;

    while (low < high) {//(contador > 0) {//(low < high)

        // cout << "Guess: " << guess << endl;

        passos++;
        // if (previous_guess != 0) {
            int response = Guess(guess);

            // if(guess == previous_guess) {

            // }

            if (response == HOTTER) {
                // cout << "HOTTER" << endl;
                if(previous_guess > guess) {
                    high = (guess + high)/2;
                }
                if(previous_guess < guess) {
                    low = (guess + low)/2;
                }
            } 
            else if (response == COLDER) {
                // cout << "COLDER" << endl;
                if(previous_guess > guess) {
                    low = (guess + low)/2;
                }
                if(previous_guess < guess) {
                    high = (guess + high)/2;
                }
            }
            else if (response == SAME) {
                // cout << "SAME" << endl;
            }
            else if(response == FINISH_GAME) {
                return guess;
            }
            previous_guess = guess;

            // cout << "[" << low << "," << high << ']' << endl;
            if(response == SAME && guess == previous_guess) {
                guess = guess + 1;
            }
            if(response != SAME) {
                guess = (low + high) / 2;
            }
            // guess = (low + high) / 2; //(middle = guess)
            // if(guess == previous_guess) {
            //     guess = high;
            // }
        // }

        // previous_guess = guess;
        contador--;
    }

    return low;
}

int main() {
    // Example usage
    // for(int i=1; i<=100; i++) {
    //     jill_number = i;//20;
    //     int result = HC(100);
    //     cout << "Jill's number is: " << result << endl;
    //     cout << passos << " Passos.\n" << endl;
    //     passos = 0;
    // }
    jill_number = 680;//20;
    int result = HC(1000);
    cout << "Jill's number is: " << result << endl;
    cout << passos << " Passos." << endl;
    return 0;
}