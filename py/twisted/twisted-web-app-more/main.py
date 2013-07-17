


import json



from twisted.web import resource
from twisted.web import static



class RootResource(resource.Resource):


    def __init__(self):
        resource.Resource.__init__(self)
        self.putChild('', static.File('html'))
        self.putChild('resources', IndexResource())



class IndexResource(resource.Resource):


    def __init__(self):
        resource.Resource.__init__(self)
        self.jobs = {}
        self.new_id = 1
        self.putChild('list', ListResource(self.jobs))


    def render_GET(self, request):
        return ('<html><head><title>Add Job</title></head>'
                '<body><form method="POST"><input type="text"name="name" />'
                '<input type="submit" value="OK" /></form></body></html>')


    def render_POST(self, request):
        job_id = self.new_id
        self.new_id += 1
        self.jobs[job_id] = request.args['name'][0]
        return str(job_id)



class ListResource(resource.Resource):


    def __init__(self, jobs):
        resource.Resource.__init__(self)
        self.jobs = jobs


    def render_GET(self, request):
        request.setHeader('Content-Type', 'application/json')
        return json.dumps(self.jobs)

