#!/bin/python3

import re

phoneNumRegex = re.compile(r'\d{3}-\d{3}-\d{4}');

mo = phoneNumRegex.search('My phone num is 333-333-3333 or 555-555-5555');

subReg = re.compile(r'(\d{3})-(\d{3})-(\d{4})');

submo = subReg.search('My phone num is 333-333-3333 or 555-555-5555');

print(mo.group());
print(submo.group());
print(submo.group(1) + '.' + submo.group(2) + '.' + submo.group(3));

# with prefix
string = 'premise, prefer, precise';
strReg = re.compile(r'pre([a-z]{1}mise|[a-z]{1}ise)');
strmo = strReg.search(string);
print(strmo.group());
print(strmo.group(1));

# ? selectable sub match
strReg2 = re.compile(r'pre([a-z]{1})?ise');
strmo2 = strReg2.search(string);
print(strmo2.group());
print(strmo2.group(1));

# * 0 or more times match
strReg3 = re.compile(r'pre([a-z]{1})*ise');
strmo3 = strReg3.search(string);
print(strmo3.group());

# + 1 or more times matchs
strReg4 = re.compile(r'pre([a-z]{1})+ise');
strmo4 = strReg4.search(string);
print(strmo4.group());

# match policy
string = "HaHaHaHaHa";
strReg5 = re.compile(r'(Ha){3,5}');
strmo5 = strReg5.search(string);
print(strmo5.group());
strReg6 = re.compile(r'(Ha){3,5}?');
strmo6 = strReg6.search(string);
print(strmo6.group());

# find all
strReg7 = re.compile(r'Ha');
strmo7 = strReg7.findall(string);

print(strmo7);

poetry = '''

From fairest creatures we desire increase,

That thereby beauty's rose might never die,

But as the riper should by time decease,

His tender heir might bear his memory;

But thou contracted to thine own bright eyes,

Feed'st thy light's flame with self-substantial fuel,

Making a famine where abundance lies,

Thyself thy foe, to thy sweet self too cruel.

Thou that art now the world's fresh ornament,

And only herald to the gaudy spring,

Within thine own bud buriest thy content,

And, tender churl, mak'st waste in niggarding.

Pity the world, or else this glutton be,

To eat the world's due, by the grave and thee.

''';

poeReg = re.compile(r'(.*)\n');
poeMo = poeReg.findall(poetry);

while '' in poeMo:
    del poeMo[poeMo.index('')];

poetry = '';
for i in poeMo: 
    poetry += i + '\n';

poetry.rstrip('\n');
print(poetry);

#aeiouReg = re.compile(r'[aeiouAEIOU]{1}');
aeiouReg = re.compile(r'[aeiou]+?', re.I);
aeiouMo = aeiouReg.findall(poetry);

count = {};

for i in aeiouMo: 
    i = i.lower();
    count.setdefault(i, 0);
    count[i] += 1;

import pprint
pprint.pprint(count)

# only match this line
lineReg = re.compile(r'.*');
lineMo = lineReg.search(poetry);
print(lineMo.group());

# match all lines with DOTALL
lineRegAll = re.compile(r'.*', re.DOTALL);
lineMo = lineRegAll.search(poetry);
print(lineMo.group());

# sub 
subReg = re.compile(r'(\W)(to)(\W)', re.I);
subMo = subReg.findall(poetry);
# how to sub to to 2 ? 
# A smart way by me haha 
# think twice before fury next time
print(subReg.sub(r"\1 \b2\3", poetry));
