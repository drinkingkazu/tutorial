
class foo:

    _fvar = 1

class bar(foo):

    _bvar = 2
    
if __name__ == '__main__':

    print 
    f = bar()
    print f._fvar
    print f._bvar
    print
