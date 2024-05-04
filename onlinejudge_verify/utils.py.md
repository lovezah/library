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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# Python Version: 3.x\nimport glob\nimport os\nimport pathlib\nfrom typing\
    \ import *\n\nimport onlinejudge_verify.languages.list\n\n\ndef is_local_execution()\
    \ -> bool:\n    return 'GITHUB_ACTION' not in os.environ\n\n\ndef is_verification_file(path:\
    \ pathlib.Path, *, basedir: Optional[pathlib.Path] = None) -> bool:\n    \"\"\"\
    `is_verification_file` is a thin wrapper for `Languge.is_verification_file`. \
    \ This function automatically get the language.\n    \"\"\"\n\n    basedir = basedir\
    \ or pathlib.Path.cwd()  # TODO: remove this. make basedir argument always required\n\
    \    language = onlinejudge_verify.languages.list.get(path)\n    return language\
    \ is not None and language.is_verification_file(path, basedir=basedir)\n\n\ndef\
    \ glob_with_predicate(pred: Callable[[pathlib.Path], bool]) -> Iterator[pathlib.Path]:\n\
    \    \"\"\"glob_with_basename iterates files whose basenames satisfy the predicate.\n\
    \n    This function ignores hidden directories and hidden files, whose names start\
    \ with dot `.` letter.\n    \"\"\"\n    return filter(pred, map(pathlib.Path,\
    \ glob.glob('**', recursive=True)))\n\n\ndef iterate_verification_files() -> Iterator[pathlib.Path]:\n\
    \    return glob_with_predicate(is_verification_file)\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/utils.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/utils.py
layout: document
redirect_from:
- /library/onlinejudge_verify/utils.py
- /library/onlinejudge_verify/utils.py.html
title: onlinejudge_verify/utils.py
---
