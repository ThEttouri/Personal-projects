import sys
import random
from pyfiglet import FigletFont, Figlet

fig = FigletFont.getFonts()
figlet = Figlet()

if len(sys.argv) != 3 and len(sys.argv) != 1:
    print("Invalid usage")
    sys.exit(1)
if len(sys.argv) == 3:
    if sys.argv[1] != "-f" and sys.argv[1] != "--font":
        print("Invalid usage")
        sys.exit(1)
    if sys.argv[2] not in fig:
        print("Invalid usage")
        sys.exit(1)
if len(sys.argv) == 3:
    figlet.setFont(font=sys.argv[2])
else:
    Font = random.choice(fig)
    figlet.setFont(font=Font)
i = input("Input:  ")
print("Output: ")
print(figlet.renderText(i))