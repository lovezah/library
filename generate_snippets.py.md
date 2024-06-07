---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# Generates cpp.json with snippets for VSCode\n\nimport os\nimport json\n\
    import sys\n\nsnippets = {}\n\nfor subdir in os.walk('.'):\n  if subdir[0] ==\
    \ '.' or subdir[0][2] == '.':\n    continue\n  for filename in subdir[2]:\n  \
    \  if filename == \"Makefile\":\n      continue\n    name, extension = filename.split('.')\n\
    \    if extension != 'hpp':\n      continue\n    if name in snippets:\n      print(f'error:\
    \ duplicate snippet {name}', file=sys.stderr)\n      exit(0)\n\n    path = subdir[0]\
    \ + '/' + filename\n    with open(path, 'r') as f:\n      snippet = {\n      \
    \  \"prefix\": name,\n        \"body\": [line.rstrip() for line in f.readlines()],\n\
    \        \"description\": name\n      }\n      snippets[name] = snippet\n\n  \
    \  print(f'generated snippet {name}', file=sys.stderr)\n\nwith open('C:\\\\Users\\\
    \\zah\\\\AppData\\\\Roaming\\\\Code\\\\User\\\\snippets\\\\cpp.json', 'w') as\
    \ f:\n  f.write(json.dumps(snippets, indent=2))\n\nprint('done', file=sys.stderr)"
  dependsOn: []
  isVerificationFile: false
  path: generate_snippets.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: generate_snippets.py
layout: document
redirect_from:
- /library/generate_snippets.py
- /library/generate_snippets.py.html
title: generate_snippets.py
---
