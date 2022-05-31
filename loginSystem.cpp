#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <algorithm>

/*
    1. Take 1 or 2 numbers ➡️ if 1 is ✔️, then Register user
                                                  ↪️ Password will store in encrypted format.
                                            ➡️ if 2 is ✔️, then Login user
                                                   ↪️ a. Take input as password,
                                                        b. get encrypted pass from file and decrypte it.
                                                        c. remove unwanted space with the help of resize().
                                                        d. Compare both strings and if match return true.

*/

using namespace std;

class encrypt
{
private:
    string username;
    string password;

public:
    void credentials(void);
    string encryption(string);
    string decryption(string);
    bool isLoggedIn();
};

void encrypt ::credentials(void)
{
    cout << "Enter Username: ";
    cin>>username;
    cout << "Enter Password: ";
    cin >> password;

    // Encrypted password
    password = encryption(password);

    ofstream out("auth.txt");
    out << username << endl
        << password;

    out.close();
}

string encrypt ::encryption(string str)
{
    int len = str.length();
    string encrypted;

    // square root of string -
    int b = ceil(sqrt(len));
    int a = floor(sqrt(len));

    if (a * b < len)
    {
        if (min(b, a) == b)
            b += 1;
        else
            a += 1;
    }
    // Matrix to generate the encrypted string
    char arr[a][b];
    int k = 0;

    // Fill matrix row wise
    for (int j = 0; j < a; j++)
    {
        for (int i = 0; i < b; i++)
        {
            if (k < len)
            {
                arr[j][i] = str[k];
            }
            k++;
        }
    }

    // Loop to generate encrypted string
    for (int j = 0; j < b; j++)
    {
        for (int i = 0; i < a; i++)
        {
            encrypted = encrypted + arr[i][j];
        }
    }
    return encrypted;
}

string encrypt ::decryption(string str)
{
    int len = str.length();
    int b = ceil(sqrt(len));
    int a = floor(sqrt(len));
    string decrypted;

    char arr[a][b];
    int k = 0;

    // Fill matrix column wise
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (k < len)
                arr[i][j] = str[k];
            k++;
        }
    }

    // Loop to generate encrypted string
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            decrypted = decrypted + arr[j][i];
        }
    }
    return decrypted;
}

bool encrypt ::isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    int len_pass = password.length();

    // To get username and password from auth file
    ifstream in("auth.txt");
    getline(in, un);
    getline(in, pw);

    pw = decryption(pw);
    // There is some spaces in pw after decrypt the password so, we need to remove extra spaces.
    // Here, we use resize method to remove unwanted spaces from decrypt string.
    pw.resize(len_pass);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    bool exit = false;
    char yesNo;
    while (!exit)
    {

        cout << "1: Register\n2: Login\nYour Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            encrypt en;
            en.credentials();

            // main(); // register another user.
        }
        else if (choice == 2)
        {
            encrypt en;
            bool status = en.isLoggedIn();

            if (!status)
            {
                cout << "username or password is incorrect !" << endl;
            }
            else
            {
                cout << "Succesfully logged in!" << endl;
            }
        }
        else
            cout << "Kindly select 1 or 2" << endl;

        cout << "Do you want to continue? (Y or N)" << endl;
        cin >> yesNo;
        if (yesNo == 'N' || yesNo == 'n')
            exit = true;
    }

    system("PAUSE");
    return 0;
}