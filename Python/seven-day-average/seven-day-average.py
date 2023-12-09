import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    # Getting the states from the user
    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# Creating a dictionary to store the days of new cases by state
def calculate(reader):
    dictionary = {}
    previous_cases = {}
    for line in reader:
        state = line["state"]
        cases = int(line["cases"])
        if state not in dictionary:
            dictionary[state] = []
        if state not in previous_cases:
            previous_cases[state] = cases
        if len(dictionary[state]) == 0:
            dictionary[state].append(cases)
        else:
            _cases = cases - previous_cases[state]
            dictionary[state].append(_cases)
            previous_cases[state] = cases
    return dictionary


# Calculating and printing out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        case_list = new_cases[state]
        current_week_cases = case_list[-7:]
        previous_week_cases = case_list[-14:-7]
        try:
            # Calculating the week averages
            current_week_average = sum(current_week_cases) / 7
            previous_week_average = sum(previous_week_cases) / 7
            # Calculating the percent change
            percent_change = ((current_week_average - previous_week_average) / previous_week_average) * 100
        except ZeroDivisionError:
            print("Zero division error")
            exit(1)
        # Printing the outputs
        if percent_change > 0:
            print(f"{state} had a 7-day average of {current_week_average:.0f} and an increase of {percent_change:.0f}%.")
        elif percent_change < 0:
            print(f"{state} had a 7-day average of {current_week_average:.0f} and a decrease of {percent_change:.0f}%.")
        else:
            print(f"{state} had a 7-day average of {current_week_average:.0f} and percent change is 0%.")


main()