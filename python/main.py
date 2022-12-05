import random


symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "
targPharse ="METHINKS IT IS LIKE A WEASEL"

symbols.split(" ")
targPharse.split(" ")


def Sort_Char(alphabet):
    randNum = random.randint(0,len(alphabet)-1)
    return alphabet[randNum]


def Sort_Initial_String(targPharse,  alphabet):
    sortedString = []
    for i in targPharse:
        sortedString.append(Sort_Char(alphabet))
    return sortedString


def Resort_String(targPharse, alphabet, textCopy):
    newTextCopy = []
    for j in range(len(targPharse)):
        if textCopy[j] == targPharse[j]:
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
    for writing in text_Copy:
        print(writing, end="")
    print(" In Generation {} and Score of {}\n".format(generation,
                                 getScore(text_Copy, targPharse)))


def Main():
    current_Copy = Sort_Initial_String(targPharse, symbols)
    generation = 0
    num_generations = 100
    copies = []
    while(getScore(current_Copy, targPharse) < len(targPharse)):
        copies = Copy_Of(current_Copy, num_generations)

        for copy in copies:
            resort_Copy = Resort_String(targPharse, symbols, copy)
            if(getScore(resort_Copy, targPharse) > getScore(current_Copy,
                                                             targPharse)):
                current_Copy = resort_Copy
                

        printGeneration(current_Copy, generation)
        generation += 1


Main()
