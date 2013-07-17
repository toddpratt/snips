

from twisted.python import reflect


class B1(object):
    joke = ["hi 1"]


class B2(object):
    joke = ["hi 2"]


class B3(object):
    joke = ["hi 3"]


class D(B1, B2, B3):
    joke = ["hi 4"]

l = []

reflect.accumulateClassList(D, 'joke', l)
print l

