from PIL import Image
import sys

def display_help() -> None:
    with open("bonus/help.txt") as file:
        print(file.read())

def main(path: str) -> None:
    try:
        image = Image.open(path)
    except FileNotFoundError:
        print(f"No such file or directory: '{path}'.")
        exit()
    new_image = image.resize((1728, 972))
    new_image.save(path)
try:
    if (sys.argv[1] == "-h"):
        display_help()
        exit()
except IndexError:
    print(f"Must give a file path as an argument.")
main(sys.argv[1])
