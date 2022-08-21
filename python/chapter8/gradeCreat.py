#!/bin/python3
import pprint
grade = { 'Calculus' : 95, 'Probability' : 93, 'English' : 89 };
pprint.pformat(grade);
file = open('grade.py', 'w')
file.write('grades = ' + pprint.pformat(grade) + '\n');
file.close();
