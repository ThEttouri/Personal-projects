import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for line in reader:
            database.append(line)

    # Read DNA sequence file into a variable
    DNA = ""
    with open(sys.argv[2]) as f:
        DNA = f.read()

    # Find longest match of each STR in DNA sequence
    if sys.argv[1] == 'databases/small.csv':
        AGATC = longest_match(DNA, "AGATC")
        AATG = longest_match(DNA, "AATG")
        TATC = longest_match(DNA, "TATC")
    elif sys.argv[1] == 'databases/large.csv':
        AGATC = longest_match(DNA, "AGATC")
        TTTTTTCT = longest_match(DNA, "TTTTTTCT")
        AATG = longest_match(DNA, "AATG")
        TCTAG = longest_match(DNA, "TCTAG")
        GATA = longest_match(DNA, "GATA")
        TATC = longest_match(DNA, "TATC")
        GAAA = longest_match(DNA, "GAAA")
        TCTG = longest_match(DNA, "TCTG")

    # Check database for matching profiles
    if sys.argv[1] == 'databases/small.csv':
        for person in database:
            if int(person["AGATC"]) == AGATC and int(person["AATG"]) == AATG and int(person["TATC"]) == TATC:
                print(f"{person['name']}")
                sys.exit(0)
        print("No match")
    elif sys.argv[1] == 'databases/large.csv':
        for person in database:
            if int(person["AGATC"]) == AGATC and int(person["TTTTTTCT"]) == TTTTTTCT and int(person["AATG"]) == AATG and int(person["TCTAG"]) == TCTAG and int(person["GATA"]) == GATA and int(person["TATC"]) == TATC and int(person["GAAA"]) == GAAA and int(person["TCTG"]) == TCTG:
                print(f"{person['name']}")
                sys.exit(0)
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()