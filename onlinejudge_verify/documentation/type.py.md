---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: onlinejudge_verify/documentation/main.py
    title: onlinejudge_verify/documentation/main.py
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import datetime\nimport enum\nimport pathlib\nfrom typing import *\n\n\n\
    class VerificationStatus(enum.Enum):\n    LIBRARY_ALL_AC = 'LIBRARY_ALL_AC'\n\
    \    LIBRARY_PARTIAL_AC = 'LIBRARY_PARTIAL_AC'\n    LIBRARY_SOME_WA = 'LIBRARY_SOME_WA'\n\
    \    LIBRARY_ALL_WA = 'LIBRARY_ALL_WA'\n    LIBRARY_NO_TESTS = 'LIBRARY_NO_TESTS'\n\
    \    TEST_ACCEPTED = 'TEST_ACCEPTED'\n    TEST_WRONG_ANSWER = 'TEST_WRONG_ANSWER'\n\
    \    TEST_WAITING_JUDGE = 'TEST_WAITING_JUDGE'\n\n\nclass SourceCodeStat(NamedTuple):\n\
    \    \"\"\"A tuple represents a code file.\n    \"\"\"\n    path: pathlib.Path\
    \  # a relative path from basedir\n    is_verification_file: bool\n    verification_status:\
    \ VerificationStatus\n    timestamp: datetime.datetime  # the same format to timestamps.*.json\n\
    \    depends_on: List[pathlib.Path]  # relative paths from basedir\n    required_by:\
    \ List[pathlib.Path]  # relative paths from basedir\n    verified_with: List[pathlib.Path]\
    \  # relative paths from basedir\n    attributes: Dict[str, Any]\n\n\nclass FrontMatterItem(enum.Enum):\n\
    \    # pylint: disable=invalid-name\n    title = 'title'\n    layout = 'layout'\n\
    \    documentation_of = 'documentation_of'\n    data = 'data'\n    redirect_from\
    \ = 'redirect_from'  # for jekyll-redirect-from plugin\n\n\nclass PageRenderJob(NamedTuple):\n\
    \    path: pathlib.Path  # a relative path from basedir\n    front_matter: Dict[str,\
    \ Any]\n    content: bytes\n\n\nclass SiteRenderConfig(NamedTuple):\n    basedir:\
    \ pathlib.Path  # an absolute path\n    config_yml: Dict[str, Any]\n    static_dir:\
    \ pathlib.Path  # an absolute path\n    index_md: pathlib.Path  # an absolute\
    \ path\n    destination_dir: pathlib.Path  # an absolute path\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/documentation/type.py
  requiredBy:
  - onlinejudge_verify/documentation/main.py
  timestamp: '2024-05-05 04:59:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/documentation/type.py
layout: document
redirect_from:
- /library/onlinejudge_verify/documentation/type.py
- /library/onlinejudge_verify/documentation/type.py.html
title: onlinejudge_verify/documentation/type.py
---
