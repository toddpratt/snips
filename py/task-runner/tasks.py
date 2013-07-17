
tasks = []


def runTasks():
    incompletes = True
    while incompletes:
        incompletes = [t for t in tasks if not t.isCompleted()]
        readies = [t for t in incompletes if t.isReady()]
        for task in readies:
            task.run()



class Task:


    def __init__(self, name):
        self.name = name
        self.completed = False
        self.dependencies = []
        tasks.append(self)


    def addDependency(self, dependsOn):
        self.dependencies.append(dependsOn)


    def run(self):
        print "running %s" % self
        self.completed = True


    def isReady(self):
        for task in self.dependencies:
            if not task.isCompleted():
                return False
        return True

    def isCompleted(self):
        return self.completed


    def __repr__(self):
        return "<Task %s>" % self.name



t2b = Task("2b")
t2a = Task("2a")
t2c = Task("2c")
t4 = Task("4")
t3 = Task("3")
t1 = Task("1")

t4.addDependency(t3)

t3.addDependency(t2a)
t3.addDependency(t2b)

t2a.addDependency(t1)
t2b.addDependency(t2a)
t2c.addDependency(t2b)

t3.addDependency(t2c)

runTasks()


