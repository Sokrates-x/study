#!/bin/python3

import shelve
capitalData = shelve.open('AmericaStatesCapitalsData');

import pprint

capitalsDict = capitalData['Capitals'];
pprint.pprint(capitalsDict);

import random
states = list(capitalsDict.keys());
capitals = list(capitalsDict.values());

random.shuffle(states);

answerFlag = [ 'A', 'B', 'C', 'D' ];
answerList = ['', '', '', ''];
grade = 0;

for s in states:
    answerList[0] = capitalsDict[s];
    random.shuffle(capitals);
    j = 0;
    for i in range(1, 4, 1):
        if capitals[j] == answerList[0] :
            j += 1;
        answerList[i] = capitals[j];
        j += 1;
    random.shuffle(answerList);
    print('The capital of ' + s + ' is: ');
    for i in range(4) :
        print(answerFlag[i] + '. ' + answerList[i]);
    ans = input();
    if capitalsDict[s] == answerList[answerFlag.index(ans)] :
        grade += 2;

print("Your Grade is " + str(grade));
