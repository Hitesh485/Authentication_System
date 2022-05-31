#include<iostream>
#include<cmath>
#include<cstring>

using namespace std; 

string encryption(string str)
{
    int len = str.length();
    string encrypted;
    
    // square root of string - 
    int b = ceil(sqrt(len));
    int a = floor(sqrt(len));

    if (b * a < len)
    {
        if (min(b, a) == b)
            b += 1;
        else
            a += 1;
    }
    // Matrix to generate the encrypted string
    char arr[a][b];
    memset(arr, ' ', sizeof(arr));
    int k = 0;

    // Fill matrix row wise
    for (int j= 0; j < a; j++)
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
        for (int  i = 0; i < a; i++)
        {
            encrypted = encrypted + arr[i][j];
        }
    }
    return encrypted;
}

string decryption (string str)
{
    int len = str.length();
    int b = ceil(sqrt(len));
    int a = floor(sqrt(len));

    string decrypted;

    char arr[a][b];
    memset(arr, ' ', sizeof(arr));
    int k = 0;

    for (int j = 0; j < b; j++)
    {
        for (int i = 0; i < a; i++)
        {
            if (k < len)
            {
                arr[j][i] = str[k];
            }
            k++;
        }
    }

    for (int j = 0; j < a; j++)
    {
        for (int i = 0; i < b; i++)
        {
            decrypted = decrypted + arr[i][j];
        }
    }
    return decrypted;
}

int main(){

    // string str = "Geeks For Geeks";
    string str = "hitesh@123";

    string encrypted, decrypted;

    encrypted = encryption(str);
    cout<<encrypted<<endl;

    decrypted = decryption(encrypted);
    cout<<decrypted<<endl;
    
    return 0;
}