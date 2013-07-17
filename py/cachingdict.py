
import datetime



class cachingdict(object):


    def __init__(self, fetcher, max_age):
        """
        fetcher is a function that returns
                the value for the specified key
                fetcher is expected to take
                the key as its only argument

        max_age is a datetime.datetime.timedelta
                that is the max data age
        """
        self.max_age = max_age
        self._dict = dict()
        self._age = dict()
        self._fetcher = fetcher


    def __getitem__(self, name):
        now = datetime.datetime.now()
        if now - self._age[name] > self.max_age:
            self[name] = self._fetcher(name)
        return self._dict[name]


    def __setitem__(self, name, value):
        self._dict[name] = value
        self._age[name] = datetime.datetime.now()


