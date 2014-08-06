
class foo:

    def __init__(self):
        
        print self.__class__,'constructor'

    def __del__(self):

        print 'Destructing instance:',self

class bar:
    
    def __init__(self):

        self.item = foo()

    def __del__(self):

        print 'Destructing instance:',self

if __name__ == '__main__':

    print
    print 'Executing a program in',__name__
    print 'Creating bar instance!'

    b = bar()

print 'Exiting the program now...'
print
