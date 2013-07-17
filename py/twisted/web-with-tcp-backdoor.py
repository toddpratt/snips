
from twisted.internet import reactor
from twisted.internet.protocol import ServerFactory
from twisted.protocols.basic import LineReceiver
from twisted.web.resource import Resource
from twisted.web.server import Site



class SomeStupidServer(LineReceiver):


    def lineReceived(self, line):
        if not line: return

        args = line.split()
        method_name = "cmd_%s" % args[0]
        method = getattr(self, method_name, self.unknown_command)
        method(args)


    def unknown_command(self, args):
        self.sendLine("%s: unknown command" % args[0])


    def cmd_set(self, args):
        self.factory.resource.count = int(args[1])


    def cmd_incr(self, args):
        self.factory.resource.count += 1
        message = "count is now %s." % self.factory.resource.count
        self.sendLine(message)



class CountResource(Resource):
    count = 0


    def render_GET(self, request):
        request.setHeader('Content-Type', 'text/plain')
        return 'Count is %s.' % self.count



class CountSetFormResource(Resource):
    flash = ""


    def render_GET(self, request):
        request.setHeader('Content-Type', 'text/html')
        return """<html>
                    <head><title>Set Count</title></head>
                    <body>
                        %s
                        <form method="POST">
                            <input type="text" name="count" value="%s" />
                            <input type="submit" value="OK" />
                        </form>
                    </body>
                  </html>""" % (self.flash, self.countResource.count)


    def render_POST(self, request):
        self.countResource.count = int(request.args['count'][0])
        self.flash = "<p>Count changed to %s!</p>" % self.countResource.count
        return self.render_GET(request)


if __name__ == "__main__":
    root = Resource()
    count = CountResource()
    setter = CountSetFormResource()
    setter.countResource = count
    root.putChild('', count)
    root.putChild('set', setter)
    site = Site(root)

    f = ServerFactory()
    f.protocol = SomeStupidServer
    f.resource = count
    
    reactor.listenTCP(2323, f)
    reactor.listenTCP(8080, site)

    reactor.run()



