from cs50 import get_string


def main():
    # Get the Text from the user
    text = get_string("Text: ")
    while not check_correctness(text):
        text = get_string("Text: ")

    # Store the variables
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Compute the index and printing it
    Coleman_Liau_index(letters, words, sentences)


# Checking the Correctness
def check_correctness(text):
    for i in range(len(text) - 1):
        # Elimination of consecutive spaces
        if (text[i] == ' ') and (text[i + 1] == ' '):
            print("It looks like you used consecutive spaces in your text.")
            return False
        # Elimination of wrong Punctuation
        elif (text[i] == '!' and (i == 0 or i == 1)) or (text[i] == '?' and (i == 0 or i == 1)) or (text[i] == '.' and (i == 0 or i == 1)) or (text[i] == ',' and (i == 0 or i == 1)):
            print("It looks like you used Punctuation in the beginning of your text.")
            return False
    return True


# Calculating the number of Letters
def count_letters(text):
    sum = 0
    for i in range(len(text)):
        if (text[i] >= 'A' and text[i] <= 'Z') or (text[i] >= 'a' and text[i] <= 'z'):
            sum += 1
    return sum


# Calculating the number of Words
def count_words(text):
    sum = 0
    for i in range(len(text)):
        if text[i] == ' ':
            sum += 1
    return sum + 1


# Calculating the number of Sentences
def count_sentences(text):
    sum = 0
    n = len(text)
    if text[n - 1] == '!' or text[n - 1] == '?' or text[n - 1] == '.':
        sum += 1
    for i in range(len(text)):
        # Exceptional cases filtering
        if text[i] == '.' and text[i - 3] != ' ' and text[i - 4] != ' ' and i != n - 1 and i != 2 and i != 3:
            sum += 1
        elif (text[i] == '.' and text[i - 3] == ' ' and text[i - 2].isupper() == False and i != n - 1 and i != 2 and i != 3) or (text[i] == '.' and text[i - 4] == ' ' and text[i - 3].isupper() == False and i != n - 1 and i != 2 and i != 3):
            sum += 1
        elif i <= n - 3:
            if text[i] == '!' and text[i + 2].isupper() == True:
                sum += 1
            elif text[i] == '?' and text[i + 2].isupper() == True:
                sum += 1
    return sum


# Computing the index and printing it
def Coleman_Liau_index(letters, words, sentences):
    # Parameters calculation
    l = (float(letters) / float(words)) * 100
    s = (float(sentences) / float(words)) * 100
    # Index calculation
    g = round(0.0588 * l - 0.296 * s - 15.8)
    # Index Printing
    if g < 1:
        print("Before Grade 1")
    elif g >= 1 and g <= 15:
        print(f"Grade {g}")
    elif g >= 16:
        print("Grade 16+")


if __name__ == "__main__":
    main()