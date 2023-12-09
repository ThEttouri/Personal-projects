from cs50 import get_int


def main():
    # Prompt The User For The Number
    ccn = 0
    while ccn <= 0:
        ccn = get_int("Number: ")

    if checksum(ccn):
        # Printing The Brand
        print_credit_card_brand(ccn)
    else:
        print("INVALID")


# Calculate Checksum
def checksum(number):
    number_str = str(number)
    Lenght = len(number_str)
    # Check The Card Length
    if Lenght < 13 or Lenght > 16:
        return False
    else:
        sum = 0
        for i in range(len(number_str)):
            if number != 0:
                # For the even digits
                if i % 2 == 0:
                    sum += int(number % 10)
                    number = int(number / 10)
                # For the odd digits
                else:
                    digit = 2 * int(number % 10)
                    sum += int(digit / 10) + int(digit % 10)
                    number = int(number / 10)
    return int(sum % 10) == 0


# Check The Starting Digits
def print_credit_card_brand(number):
    if (number >= 34e13 and number < 35e13) or (number >= 37e13 and number < 38e13):
        print("AMEX")
    elif (number >= 51e14 and number < 56e14):
        print("MASTERCARD")
    elif (number >= 4e12 and number < 5e12) or (number >= 4e15 and number < 5e15):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()