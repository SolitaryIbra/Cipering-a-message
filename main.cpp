// Name: Ibrahim Mohamed
// Student ID: 20211002
// Course Name/ID: Structured Programming / CS-112
// Program: A simple program to cipher and decipher using 'Affine' method
// Assignment due: 27/3/2022
#include <iostream>


using namespace std;
// Function To Cipher Using affine method, Parameters slope A, interception B.
string encrypt_message(string plane_text, int A, int B)
{
//    Define Ciphered String.
    string ciphered_message = " ";
//     Loop to pass by every letter.
    int i = 0;
    for (; i<plane_text.length(); i++){
//         Check if letter is not blank or space, adds the ciphered letter by the parameters.
        if (plane_text[i] != ' ')
            ciphered_message += char ((((A * (plane_text[i]-'A') ) + B) % 26) + 'A');
//        Prints the letters if it is not in english alphabet.
        else ciphered_message += plane_text[i];
    }
//    Returned The message after ciphering it.
    return  ciphered_message;
}
// Function To DeCipher Using affine method, Parameters slope A, inverted A, Inverse Slop B.
string decrypt_message(string plane_text, int A, int inv_A, int C)
{
//    Define DeCiphered message.
    string deciphered_message = " ";
//    Loop for every letter in the alphabet.
    for (int i = 0; i < 26; i++){
        C = (A * i) % 26;
//        Check if C is minimum of alphabet index.
        if (C == 1)
            inv_A = i;
    }
//    Loop to pass through every letter in ciphered text.
    int i = 0;
    for (; i < plane_text.length(); i++){
//         Check if letter is not blank or space, adds the DeCiphered letter by the parameters.
        if(plane_text[i]!=' ')
            deciphered_message += (char) (((inv_A * ((plane_text[i]+'A' - C)) % 26)) + 'A');
//        Prints the letters if it is not in english alphabet.
        else
            deciphered_message += plane_text[i];
    }
//    Prints the message in after deciphering it.
    return deciphered_message;
}

int main()
{
//    Loop to Continue choosing what command a user will do.
    while (true)
    {
//        Define The Plane Text The User Choice, and all the integer parameters.
        string plane_text, choice;
        int A,B,C,inv_A;
//        Input the Choice Of The User.
        cout<<"a. Cipher a message using 'Affine' method"<<endl;
        cout<<"b. DeCipher a message using 'Affine' method"<<endl;
        cout<<"c. Exit The Program"<<endl;
        cout<< "Choice an option(a or b or c): ";
        getline(cin>> ws, choice);

//        If Choice is to cipher.
        if (choice == "a"){
//            Input the plane text.
            cout<< "Enter Text To Cipher: ";
            getline(cin>> ws, plane_text);

//          Input the slope.
            cout<< "Enter Slope/A: ";
            cin>> A;

//            Inputs The Interception.
            cout<< "Enter Interception/B: ";
            cin >> B;

//            Prints the ciphered Message.
            cout<< "The cipher of '"<<plane_text<<"' is: "<<encrypt_message(plane_text, A, B)<<endl;
        }

//        If Choice is to Decipher.
        else if (choice =="b"){
//            Inputs the ciphered message.
            cout<< "Enter Text To DeCipher: ";
            getline(cin>> ws, plane_text);

//            Inputs the slope A.
            cout<< "Enter Slope/A: ";
            cin>> A;

//            Inputs The interception C.
            cout<< "Enter Interception/C: ";
            cin >> C;

//            Enter The inverse of Slope inv_A.
            cout<< "Enter Inverse Of slope: ";
            cin >> inv_A;

//            Prints The Deciphered Message.
            cout<< "The decipher of '"<<plane_text<<"' is: "<<decrypt_message(plane_text, A, inv_A ,C)<<endl;
        }

//      If Choice is to exit.
        else if (choice == "c"){
            cout<< "Thanks For Using Our Program";
            break;
        }

//        If choice is invalid.
        else
            cout<<"##Invalid Choice##"<<endl;
    }
//    Prints a break line between round.
    cout<<"--------------------------------"<<endl;
}
