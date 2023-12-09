greeting = input("Greeting: ").strip().lower()

words = greeting.split()
if words[0] == "hello" or words[0] == "hello,":
    print("$0")
    exit(0)
for letter in words:
    if letter[0] == "h":
        print("$20")
        exit(0)
    else:
        print("$100")
        exit(0)