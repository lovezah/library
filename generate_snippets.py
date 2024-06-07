# Generates cpp.json with snippets for VSCode

import os
import json
import sys

snippets = {}

for subdir in os.walk('.'):
  if subdir[0] == '.' or subdir[0][2] == '.':
    continue
  for filename in subdir[2]:
    if filename == "Makefile":
      continue
    name, extension = filename.split('.')
    if extension != 'hpp':
      continue
    if name in snippets:
      print(f'error: duplicate snippet {name}', file=sys.stderr)
      exit(0)

    path = subdir[0] + '/' + filename
    with open(path, 'r') as f:
      snippet = {
        "prefix": name,
        "body": [line.rstrip() for line in f.readlines()],
        "description": name
      }
      snippets[name] = snippet

    print(f'generated snippet {name}', file=sys.stderr)

with open('C:\\Users\\zah\\AppData\\Roaming\\Code\\User\\snippets\\cpp.json', 'w') as f:
  f.write(json.dumps(snippets, indent=2))

print('done', file=sys.stderr)