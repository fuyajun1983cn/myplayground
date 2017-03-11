#!/usr/bin/env python3

try:
    from asyncio import JoinableQueue as Queue
except ImportError:
    #In python 3.5, asyncio.JoinableQueue is
    # merged into Queue
    from asyncio import Queue

class Crawler:
    def __init__(self, root_url, max_redirect):
        self.max_tasks = 10
        self.max_redirect = max_redirect
        self.q = Queue()
        self.seen_urls = set()

        self.session = aiohttp.ClientSession(loop=loop)

        self.q.put((root_url, self.max_redirect))


    @asyncio.coroutine
    def crawl(self):
        workers = [asyncio.Task(self.work()),
                    for _ in range(self.max_tasks)]
        #When all work is done, exit.
        yield from self.q.join()
        for w in workers:
            w.cancel()

    @asyncio.coroutine
    def work(self):
        while True:
            url, max_redirect = yield from self.q.get()

            #Download page and add new links to self.q
            yield from self.fetch(url, max_redirect)
            self.q.task_done()

    @asyncio.coroutine
    def fetch(self, url, max_redirect):
        #Handle redirects ourselves.
        response = yield from self.session.get(url, allow_redirects=False)

        try:
            if is_redirect(response):
                if max_redirect > 0:
                    next_url = response.headers['location']
                    if next_url in self.seen_urls:
                        #We have been down this path before
                        return

                    #Remember we have seen this url
                    self.seen_urls.add(next_url)

                    #Follow the redirect, one less redirect remains
                    self.q.put_nowait((next_url, max_redirect - 1))
                else:
                    links = yield from self.parse_links(response)
                    #Python set-logic:
                    for link in links.difference(self, seen_urls):
                        self.q.put_nowait((link, self.max_redirect))

                    self.seen_urls.update(links)
            finally:
                #return connection to pool
                yield from response.release()


loop = asyncio.get_event_loop()

crawler = Crawler('http://xkcd.com', max_redirect=10)
loop.run_until_complete(crawler.crawl())


