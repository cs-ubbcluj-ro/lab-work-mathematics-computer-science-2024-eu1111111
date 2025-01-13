if __name__ == '__main__':
    finalStates = []
    states = []
    transitions = []
    alphabet = []
    f = open("exemplu.txt", "r")

    # HERE WE GET THE SET OF STATES
    for line in f:
        lis = line.split("->")
        statement = lis[0]
        state = lis[1]
        t = str(statement[2] + statement[3])
        if t not in states:
            states.append(t)
        t = str(state[1] + state[2])
        if t not in states:
            states.append(t)
    print("Set of states: " + str(states) + "\n")
    f.close()

    #HERE WE GET THE SET OF FINAL STATES

    f = open("exemplu.txt", "r")
    for line in f:
        lis = line.split("->")
        statement = lis[0]
        state = lis[1]
        t = str(statement[2] + statement[3])
        if statement[1] == "[":
            if t not in finalStates:
                finalStates.append(t)
        t = str(state[1] + state[2])
        if state[0] == "[":
            if t not in finalStates:
                finalStates.append(t)
    print("Set of final states: " + str(finalStates) + "\n")
    f.close()

    #HERE WE GET THE SET OF TRANSITIONS

    f = open("exemplu.txt", "r")
    for line in f:
        t = str(line[2] + line[3] + " -> " + line[11] + line[12])
        transitions.append(t)
    print("The transitions: " + str(transitions) + "\n")
    f.close()

    #HERE WE GET THE ALPHABET

    f = open("exemplu.txt", "r")
    for line in f:
        t = str(line[6])
        if t not in alphabet:
            alphabet.append(t)
    print("The alphabet: " + str(alphabet) + "\n")
    f.close()