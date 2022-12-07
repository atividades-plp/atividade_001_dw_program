import random

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "
targ_text ="METHINKS IT IS LIKE A WEASEL"

alphabet.split(" ")
targ_text.split(" ")


def sort_char(alphabet):
    random_number = random.randint(0,len(alphabet)-1)
    return alphabet[random_number]


def sort_initial_string(targPharse,  alphabet):
    sortedString = []

    for i in targPharse:
        sortedString.append(sort_char(alphabet))

    return sortedString

# Defining if there is a mutation in the character
def has_2_be_sorted():
    mutantion_number = 5
    number = random.randint(1,100)
    return number <= mutantion_number

def resort_string(targPharse, alphabet, textCopy):
    newTextCopy = []
    length_targPharse = len(targPharse)

    for j in range(length_targPharse):
        if textCopy[j] == targPharse[j] or not has_2_be_sorted():
            newTextCopy.append(textCopy[j])
        else:
            newTextCopy.append(sort_char(alphabet))

    return newTextCopy

# Returns a list of copies of the chosen phrase
def copy_of(text_copy, numb_copies):
    list_copies = []

    for k in range(numb_copies):
        list_copies.append(text_copy)

    return list_copies


def get_score(text_Copy, targPharse):
    score_text = 0
    length_targPharse = len(targPharse)

    for w in range(length_targPharse):
        if text_Copy[w] == targPharse[w]:
            score_text += 1

    return score_text


def printGeneration(text_Copy, generation):
    print("GENERATION {} (SCORE {}): ".format(generation,
          get_score(text_Copy, targ_text)), end="")

    for writing in text_Copy:
        print(writing, end="")

    print()


def Main():
    current_Copy = sort_initial_string(targ_text, alphabet)
    generation = 0
    num_generations = 100
    copies = []

    while(get_score(current_Copy, targ_text) < len(targ_text)):
        copies = copy_of(current_Copy, num_generations)

        for copy in copies:
            resort_Copy = resort_string(targ_text, alphabet, copy)
            if get_score(resort_Copy, targ_text) > get_score(current_Copy,
                targ_text):
                current_Copy = resort_Copy
                
        printGeneration(current_Copy, generation)
        generation += 1


Main()
