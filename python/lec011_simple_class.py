
class foo:
    """Class foo """

    def what_is_self(self):
        """ My foo function! """
        print self    

class bar:
    """Class bar """
    
    def __str__(self):

        return 'I am bar!'

    def what_is_self(self):
        """ My bar function! """
        print self

if __name__ == '__main__':

    print
    print foo
    k=foo()
    print k
    k.what_is_self()

    print
    print bar
    b=bar()
    print b
    b.what_is_self()
    
    
