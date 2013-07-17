#! /usr/bin/env python

from twisted.internet import reactor
from twisted.web import resource, server



class Page(resource.Resource):


    def render(self, request):
        request.setHeader('content-type', 'text/plain')
        return "<html><body>Test Page</body></html>"



root = resource.Resource()
root.putChild("", Page())

site = server.Site(root)
reactor.listenTCP(8000, site)
reactor.run()

