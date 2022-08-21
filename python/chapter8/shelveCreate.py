#!/bin/python3
# shelve : a small database ?
import shelve
shelveFile =  shelve.open('shData'); 
grade = { 'Calculus' : 95, 'Probability' : 93, 'English' : 89 };
shelveFile['grade'] = grade;
shelveFile.close();
