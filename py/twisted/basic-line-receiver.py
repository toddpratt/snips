
from twisted.internet import stdio
from twisted.protocols import basic
from twisted.internet import reactor

class SimpleProtocol(basic.LineReceiver):

    def connectionMade(self):
        delimiter = '\n'
        self.sendLine("HELLO")

    def lineReceived(self, line):
        self.sendLine('line: %s' % line)

    def connectionLost(self, reason):
        self.sendLine('BYE')


if __name__ == "__main__":
    f = stdio.StandardIO(SimpleProtocol())
    reactor.run() 

