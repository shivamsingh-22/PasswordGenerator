#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;
class PasswordGenerator {
public:
    PasswordGenerator(int length, bool useUpper, bool useLower, bool useDigits, bool useSpecial)
        : length(length), useUpper(useUpper), useLower(useLower), useDigits(useDigits), useSpecial(useSpecial) {
        // Initialize the character set based on user preferences
        if (useUpper) {
            characterSet += upperCase;
        }
        if (useLower) {
            characterSet += lowerCase;
        }
        if (useDigits) {
            characterSet += digits;
        }
        if (useSpecial) {
            characterSet += specialChars;
        }
        if (characterSet.empty()) {
            throw invalid_argument("At least one character set must be selected.");
        }
        srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    }

   string generate() {
        string password;
        for (int i = 0; i < length; ++i) {
            int index = rand() % characterSet.size();
            password += characterSet[index];
        }
        return password;
    }

private:
    int length;
    bool useUpper;
    bool useLower;
    bool useDigits;
    bool useSpecial;
    string characterSet;

    const string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";
};
int main() {
    int length;
    char includeUpper, includeLower, includeDigits, includeSpecial;

    cout << "Password Generator\n";
    cout << "Enter the desired length of the password: ";
    cin >> length;
    if (length <= 0) {
        cerr << "Error: Password length must be a positive integer." << endl;
        return -1;
    }
    else{
    cout << "Include uppercase letters? (y/n): ";
    cin >> includeUpper;
    cout << "Include lowercase letters? (y/n): ";
    cin >> includeLower;

    cout << "Include digits? (y/n): ";
    cin >> includeDigits;

    cout << "Include special characters? (y/n): ";
    cin >> includeSpecial;
    }
    try {
        PasswordGenerator generator(length,
                                    includeUpper == 'y' || includeUpper == 'Y',
                                    includeLower == 'y' || includeLower == 'Y',
                                    includeDigits == 'y' || includeDigits == 'Y',
                                    includeSpecial == 'y' || includeSpecial == 'Y');

        string password = generator.generate();
        cout << "Generated Password: " << password << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}