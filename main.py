import requests
import os
from bs4 import BeautifulSoup

problems = []
users = [['', '']]
exts = [['Assembly', '.asm'], ['C++', '.cpp'], ['Haskell', '.hs'], ['Java', '.java'], ['Node.js', '.js'],
        ['Pascal', '.pas'], ['Python', '.py'], ['Ruby', '.txt'], ['Rust', '.rs'], ['Scala', '.scala']]


def fetch_problem():
    r = requests.get('https://cses.fi/problemset/').text
    pos = 0
    while True:
        st = r.find('<a href="/problemset/task/', pos)
        if st == -1:
            break
        ed = r.find('</a>', st)
        id = ''
        name = ''
        j = st + len('<a href="/problemset/task/')
        # handle case that problem id is not an 4-digit number, but maybe it won't happen?
        while j < ed:
            if r[j] == '\"':
                break
            id += r[j]
            j += 1
        j += 2  # skip "\
        while j < ed:
            name += r[j]
            j += 1
        problems.append([name, id])
        pos = ed


def get_submission(user, password):
    s = requests.Session()
    login_url = 'https://cses.fi/login/'

    r = s.get(login_url)
    soup = BeautifulSoup(r.text, 'lxml')
    field = soup.find('input', {'name': 'csrf_token'})
    csrf = field['value']

    r = s.post(
        url=login_url,
        data={
            'csrf_token': csrf,
            'nick': user,
            'pass': password,
        },
    )

    if r.status_code != 200:
        print('Failed to login to', user, password)
        return

    readme_file = open(user + '/README.md', "w")

    readme_file.write('| Name                                                                     | Solution                                     |')
    readme_file.write('\n')
    readme_file.write('| ------------------------------------------------------------------------ | -------------------------------------------- |')
    readme_file.write('\n')

    for problem, id in problems:
        problem_url = 'https://cses.fi/problemset/task/' + id
        r = s.get(problem_url)
        soup = BeautifulSoup(r.text, 'lxml')
        marks = soup.find_all('span', {'class': 'task-score icon full'})
        path = ''

        for mark in marks:

            curr_element = mark.previous_element.previous_element
            curr_element = str(curr_element)

            if 'result' not in curr_element:
                continue

            pos = curr_element.find('href=')
            pos += len('href=\"')

            link_to_submission = 'https://cses.fi' + \
                curr_element[pos: curr_element.find('\">')]

            # just download first AC submission
            soup = BeautifulSoup(s.get(link_to_submission).text, 'lxml')

            last = ''

            for element in soup.find_all('td'):
                if last == 'Language:':
                    last = str(element.string)
                    break
                last = str(element.string)

            cur_ext = '.txt'

            for lang, ext in exts:
                if lang in last:
                    cur_ext = ext
                    break

            code = soup.find('pre', {'class': 'linenums'}).text

            path = user + '/' + id + cur_ext

            # fixing eol chars
            code = code.replace("\\r\\n", "\\n")
            code = code.replace("\\r", "\\n")
            code = code.replace("\r\n", "\n")
            code = code.replace("\r", "\n")

            with open(path, 'w', encoding='utf-8') as f:
                f.write(code)
                print('ok', path)

            break

        readme_file.write((('| [%s](https://cses.fi/problemset/task/%s)' % (problem, id)).ljust(75) +
                          '| [%s](%s)'.ljust(42) % (path[path.find('/') + 1:], path[path.find('/') + 1:]) + '|'))
        readme_file.write('\n')


fetch_problem()

for user, password in users:
    os.makedirs(user, exist_ok=True)
    get_submission(user, password)
