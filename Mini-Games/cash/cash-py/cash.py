from cs50 import get_float

while True:
    # Prompting the user for the owed Change
    change = get_float("Change owed: ")
    if change > 0:
        break
coins = 0
change = change * 100
# Calculating the coins
while change > 0:
    if change - (0.250 * 100) >= 0:
        change = (change - (0.250 * 100))
        coins += 1
    elif change - (0.100 * 100) >= 0:
        change = (change - (0.100 * 100))
        coins += 1
    elif change - (0.050 * 100) >= 0:
        change = (change - (0.050 * 100))
        coins += 1
    else:
        change = (change - (0.010 * 100))
        coins += 1
# Printing the coins
print(coins)