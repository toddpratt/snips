from twisted.enterprise import adbapi
from twisted.internet import reactor

pool = adbapi.ConnectionPool("sqlite3",
        database="/home/tpratt/twf/data.db")

def printResults(results):
    for row in results:
        print row
    reactor.stop()

d = pool.runQuery("select * from joke")
d.addCallback(printResults)

reactor.run()

