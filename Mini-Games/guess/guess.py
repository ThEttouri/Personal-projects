import random

def start_game():
    print("Welcome to the number guessing game!")
    print("I'm thinking of a number between 1 and 100.")

def user_guess():
    print("What do you think the number is?")
    return int(input("Please enter your guess: "))

def check_guess(user_number, secret_number):
    if user_number == secret_number:
        print("Congratulations! You guessed the number.")
        return True
    elif user_number > secret_number:
        print("Your guess is too high.")
        return False
    else:
        print("Your guess is too low.")
        return False

def play_again():
    print("Do you want to play again? (yes or no)")
    return input().lower().startswith('y')

while True:
    start_game()
    secret_number = random.randint(1, 100)

    while True:
        user_number = user_guess()
        if check_guess(user_number, secret_number):
            break

    if not play_again():
        break