Alphabet, alphabet = "abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# Function for encryption/decryption of a message
def encryption_method(word):
    # Encrypted word list
    encryption = [] 
    

    # for every character in the 'word'
    for letter in word:


        # Check if character is a space 
        if letter == " ":
            encryption.append(letter)


        # Check if character is LowerCase
        elif letter in alphabet:
            for i in range(len(alphabet)):
                if letter == alphabet[i]:
                    encryption.append(alphabet[-i-1])


        # Check if character is UpperCase
        elif letter in Alphabet:
            for i in range(len(Alphabet)):
                if letter == Alphabet[i]:
                    encryption.append(Alphabet[-i-1])
        

        # Check if character is not a char or space
        else:
            encryption.append(letter)


    # Return and save the encrypted word by joining the characters in list 'encryption'
    return("".join(j for j in encryption))

# Main of the application
def main():

    # Initial greetings
    print("Hello, User!\n")

    # Main loop
    while True:

        # Choices of encryption
        print("1- Cipher a message\n"+"2- End")

        # Input Choice
        while True:
            try:
                message_input = "Enter a choice( 1 or 2 ): "
                choice = int(input(message_input))
                break
            except BaseException:
                print("\n ## wrong input, please enter an integer.... ## ")

        # Encrypt/Decrypt a Cipher a message
        if choice == 1:
            while True:
                try:
                    word = input("Enter Here to encrypt: ")
                    encrypted_word = (encryption_method(word))
                    print("\nEncrypted message:")
                    print(f"\t{encrypted_word}\n")
                    break
                except BaseException:
                    pass

        # End the program
        elif choice == 2:
            break

        # For non integers
        else:
            print("\n## wrong input, no such choice.... ##")

main()