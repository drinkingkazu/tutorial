
class foo:

    _cvar = 1

    def __init__(self):

        self._cvar = 2

    @classmethod
    def test_classmethod(cls):
        print 'caller:',cls
        print cls._cvar

    def test_selfmethod(self):
        print 'caller:',self
        print self._cvar

    @staticmethod
    def test_staticmethod():
        print 'static method!'
        print 3

if __name__ == '__main__':

    print

    f=foo()

    print 'Calling class method...'
    f.test_classmethod()

    print
    print 'Calling self method...'
    f.test_selfmethod()

    print
    print 'Calling a static method...'
    f.test_staticmethod()

    print
