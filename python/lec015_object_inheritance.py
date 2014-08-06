
class foo(object):

    def __init__(self):

        print 'foo ctor!'

class bar(foo):

    def __init__(self):

        print 'bar ctor!'
        super(bar,self).__init__()

class suckit:

    def __init__(self):

        print 'suckit ctor'

class kazu(suckit):

    def __init__(self):
        
        print 'kazu ctor'
    
if __name__ == '__main__':

    print 
    b = bar()
    print isinstance(b,foo)
    print isinstance(b,bar)
    print
    k = kazu()
    print
