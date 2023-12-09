import pyttsx3

engine = pyttsx3.init()
n = input("What's your name? ")
engine.say(f"Hello, {n}")
engine.runAndWait()