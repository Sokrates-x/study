#!/bin/python3

grade = { 'Calculus' : 97, 'English' : 91, 'Linear Algbra' : 94, 
    'Info Theory': 89 };

print(grade['Calculus']);

for i in grade.keys():
    print(i, end = ': ');
    print(grade[i]);

print(grade.keys());
print(grade.values());
print(grade.items());

course = list(grade.keys());
print(course);

# a more simple way
for k, v in grade.items():
    print(k + ': ' + str(v));

print('Calculus' in grade.keys());

# get
print('Grade of History: ' + str(grade.get('Histroy', 0)));

# setdefault
# if key exists do nothing
grade.setdefault('Calculus', 100);
# if key NOT exists insert one
grade.setdefault('Probability', 93);

for k, v in grade.items():
    print(k + ': ' + str(v));

string = 'It was a bright cold day in April, and the clocks were striking ';
string += 'thriteen.';
print(string);

count = {};
for i in string:
    count.setdefault(i, 0); 
    count[i] += 1;

print(count);

# pprint
import pprint
pprint.pprint(count);
# same as
print(pprint.pformat(count));

# '#' chess
def printChess(chess):
    chess.setdefault('topLeft', ' ');
    print(chess['topLeft'], end = '|');
    chess.setdefault('topMid', ' ');
    print(chess['topMid'], end = '|');
    chess.setdefault('topRight', ' ');
    print(chess['topRight']);
    print('-+-+-');    
    chess.setdefault('midLeft', ' ');
    print(chess['midLeft'], end = '|');
    chess.setdefault('midMid', ' ');
    print(chess['midMid'], end = '|');
    chess.setdefault('midRight', ' ');
    print(chess['midRight']);
    print('-+-+-');    
    chess.setdefault('btmLeft', ' ');
    print(chess['btmLeft'], end = '|');
    chess.setdefault('btmMid', ' ');
    print(chess['btmMid'], end = '|');
    chess.setdefault('btmRight', ' ');
    print(chess['btmRight']);

chess = {};
chess['midMid'] = 'O';
chess['topLeft'] = 'X';
chess['btmLeft'] = 'O';
chess['topRight'] = 'X';
chess['topMid'] = 'O';
chess['btmMid'] = 'X';
chess['midRight'] = 'O';
chess['midLeft'] = 'X';
chess['btmRight'] = 'O';
printChess(chess); 
print("Draw");

guests = {'Alice' : { 'Apple' : 3, 'Banana' : 5, 'Orange' : 5 },
          'Bob' : { 'Apple' : 2, 'Cola' : 8, 'Hamberg': 10, 'Orange' : 3 },
          'James' : { 'Banana' : 3, 'Cola' : 5, 'Cookie' : 3 } };
food = {}
for p in guests.values():
    for k, v in p.items():
        food.setdefault(k, 0); 
        food[k] += v;
for k, v in food.items():
    print(k + ': ' + str(v));

# fun games
has = {'gold coin' : 33, 'rope' : 1, 'ruby' : 1, 'dagger' : 1};
dragenLoss = ['gold coin', 'rope', 'sword', 'ruby', 'gold coin',
    'gold coin', 'ruby', 'gold coin', 'gold coin'];

def add2has(has, loss) :
    for i in loss:
        has.setdefault(i, 0);
        has[i] += 1;

add2has(has, dragenLoss);

for k, v in has.items() :
    print(k + ': ' + str(v));
