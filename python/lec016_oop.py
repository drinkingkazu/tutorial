
class partBase:

    def give_me_part(self):
        pass

class partA(partBase):

    def give_me_part(self):
        return 'A'

class partB(partBase):

    def give_me_part(self):
        return 'B'

class partC(partBase):

    def give_me_part(self):
        return 'C'

class productX:

    def __init__(self):

        self._A = partA()
        self._B = partB()
        self._C = partC()
        
        self.A = self._A.give_me_part
        self.B = self._B.give_me_part
        self.C = self._C.give_me_part

if __name__ == '__main__':

    print
    print 'Construct productX'
    k = productX()

    print 'A():', k.A()
    print 'B():', k.B()
    print 'C():', k.C()
    print
