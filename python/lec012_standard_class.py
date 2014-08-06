
class foo:
    """Class foo """

    _cvar = 1

class bar:

    _cvar = 1

    def __init__(self):

        self._cvar = 2

if __name__ == '__main__':

    print
    print 'foo._cbar',foo._cvar
    f=foo()
    print 'foo instance _cvar',f._cvar
    f._cvar = 3
    print 'foo instance _cvar after re-asignment to 3:',f._cvar
    print 'foo class current _cvar:',foo._cvar

    print
    print 'bar._cbar',bar._cvar
    b=bar()
    print 'bar instance _cvar',b._cvar
    b._cvar = 3
    print 'bar instance _cvar after re-asignment to 3'
    print 'bar class current _cvar:',bar._cvar    

    print
