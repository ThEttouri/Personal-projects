from cs50 import get_int

while True:
    # Prompting the user for the Height
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
for i in range(height):
    # Printing the blocks
    print(" " * (height - (i + 1)), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1))