// String Related Programs 
//  (a) Write a program to concatenate one string to another string. 
//  (b) Write a program to reverse a string. 
//  (c) Write a program to delete all the vowels from the string. 
//  (d) Write a program to sort the strings in alphabetical order. 
//  (e) Write a program to convert a character from uppercase to lowercase. 

#include <iostream>
using namespace std;

void concatenate(char s1[], char s2[]) {
    int i = 0, j = 0;
    while (s1[i] != '\0') i++;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';
    cout << "Concatenated: " << s1 << endl;
}

void reverseString(char s[]) {
    int len = 0;
    while (s[len] != '\0') len++;
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    cout << "Reversed: " << s << endl;
}

void removeVowels(char s[]) {
    char result[100];
    int i = 0, j = 0;
    while (s[i] != '\0') {
        char c = s[i];
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result[j] = c;
            j++;
        }
        i++;
    }
    result[j] = '\0';
    cout << "Without vowels: " << result << endl;
}

void sortStrings(char arr[][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;
            while (arr[i][k] == arr[j][k] && arr[i][k] != '\0') k++;
            if (arr[i][k] > arr[j][k]) {
                char temp[20];
                int m = 0;
                while (arr[i][m] != '\0') { temp[m] = arr[i][m]; m++; }
                temp[m] = '\0';

                m = 0;
                while (arr[j][m] != '\0') { arr[i][m] = arr[j][m]; m++; }
                arr[i][m] = '\0';

                m = 0;
                while (temp[m] != '\0') { arr[j][m] = temp[m]; m++; }
                arr[j][m] = '\0';
            }
        }
    }

    cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void toLower(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32; // convert to lowercase
        }
        i++;
    }
    cout << "Lowercase string: " << s << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Concatenate strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels from a string\n";
        cout << "4. Sort strings alphabetically\n";
        cout << "5. Convert whole string to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore(); // clear buffer

        if (choice == 1) {
            char s1[100], s2[100];
            cout << "Enter first string: ";
            cin.getline(s1, 100);
            cout << "Enter second string: ";
            cin.getline(s2, 100);
            concatenate(s1, s2);
        }
        else if (choice == 2) {
            char s[100];
            cout << "Enter a string: ";
            cin.getline(s, 100);
            reverseString(s);
        }
        else if (choice == 3) {
            char s[100];
            cout << "Enter a string: ";
            cin.getline(s, 100);
            removeVowels(s);
        }
        else if (choice == 4) {
            int n;
            cout << "How many strings? ";
            cin >> n;
            cin.ignore();
            char arr[10][20];
            for (int i = 0; i < n; i++) {
                cout << "Enter string " << i + 1 << ": ";
                cin.getline(arr[i], 20);
            }
            sortStrings(arr, n);
        }
        else if (choice == 5) {
            char s[100];
            cout << "Enter a string: ";
            cin.getline(s, 100);
            toLower(s);
        }
        else if (choice == 6) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

