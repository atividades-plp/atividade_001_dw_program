import random

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "
text ="METHINKS IT IS LIKE A WEASEL"

alphabet.split(" ")
text.split(" ")


def Sort_Char(alphabet):
    random_number = random.randint(0,len(alphabet)-1)
    return alphabet[random_number]


def Sort_Initial_String(targPharse,  alphabet):
    sortedString = []
    for i in targPharse:
        sortedString.append(Sort_Char(alphabet))
    return sortedString


def Has_2_Be_Sorted():
    number = random.randint(1,100)
    return number <= 5

def Resort_String(targPharse, alphabet, textCopy):
    newTextCopy = []
    for j in range(len(targPharse)):
        if textCopy[j] == targPharse[j] or not Has_2_Be_Sorted():
            newTextCopy.append(textCopy[j])
        else:
            newTextCopy.append(Sort_Char(alphabet))
    return newTextCopy


def Copy_Of(text_copy, numb_copies):
    list_copies = []
    for k in range(numb_copies):
        list_copies.append(text_copy)
    return list_copies


def getScore(text_Copy, targPharse):
    score_text = 0
    for w in range(len(targPharse)):
        if text_Copy[w] == targPharse[w]:
            score_text += 1
    return score_text


def printGeneration(text_Copy, generation):
    print("GENERATION {} (SCORE {}): ".format(generation,
                                 getScore(text_Copy, text)), end="")
    for writing in text_Copy:
        print(writing, end="")
    print()


def Main():
    current_Copy = Sort_Initial_String(text, alphabet)
    generation = 0
    num_generations = 100
    copies = []
    while(getScore(current_Copy, text) < len(text)):
        copies = Copy_Of(current_Copy, num_generations)

        for copy in copies:
            resort_Copy = Resort_String(text, alphabet, copy)
            if(getScore(resort_Copy, text) > getScore(current_Copy,
                                                             text)):
                current_Copy = resort_Copy
                

        printGeneration(current_Copy, generation)
        generation += 1


Main()
