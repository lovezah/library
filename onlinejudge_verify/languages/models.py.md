---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: onlinejudge_verify/languages/special_comments.py
    title: onlinejudge_verify/languages/special_comments.py
  _extendedRequiredBy:
  - icon: ':warning:'
    path: onlinejudge_verify/languages/cplusplus.py
    title: onlinejudge_verify/languages/cplusplus.py
  - icon: ':warning:'
    path: onlinejudge_verify/languages/csharpscript.py
    title: onlinejudge_verify/languages/csharpscript.py
  - icon: ':warning:'
    path: onlinejudge_verify/languages/nim.py
    title: onlinejudge_verify/languages/nim.py
  - icon: ':warning:'
    path: onlinejudge_verify/languages/python.py
    title: onlinejudge_verify/languages/python.py
  - icon: ':warning:'
    path: onlinejudge_verify/languages/rust.py
    title: onlinejudge_verify/languages/rust.py
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
  code: "# Python Version: 3.x\nimport abc\nimport pathlib\nfrom typing import *\n\
    \nimport onlinejudge_verify.languages.special_comments as special_comments\n\n\
    \nclass LanguageEnvironment:\n    @abc.abstractmethod\n    def compile(self, path:\
    \ pathlib.Path, *, basedir: pathlib.Path, tempdir: pathlib.Path) -> None:\n  \
    \      \"\"\"\n        :throws Exception:\n        \"\"\"\n\n        raise NotImplementedError\n\
    \n    @abc.abstractmethod\n    def get_execute_command(self, path: pathlib.Path,\
    \ *, basedir: pathlib.Path, tempdir: pathlib.Path) -> List[str]:\n        raise\
    \ NotImplementedError\n\n\nclass Language:\n    def list_attributes(self, path:\
    \ pathlib.Path, *, basedir: pathlib.Path) -> Dict[str, Any]:\n        \"\"\"\n\
    \        :throws Exception:\n        \"\"\"\n\n        attributes: Dict[str, Any]\
    \ = special_comments.list_special_comments(path)\n        attributes.setdefault('links',\
    \ [])\n        attributes['links'].extend(special_comments.list_embedded_urls(path))\n\
    \        return attributes\n\n    @abc.abstractmethod\n    def list_dependencies(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> List[pathlib.Path]:\n     \
    \   \"\"\"\n        :throws Exception:\n        \"\"\"\n\n        raise NotImplementedError\n\
    \n    @abc.abstractmethod\n    def bundle(self, path: pathlib.Path, *, basedir:\
    \ pathlib.Path, options: Dict[str, Any]) -> bytes:\n        \"\"\"\n        :throws\
    \ Exception:\n        :throws NotImplementedError:\n        \"\"\"\n\n       \
    \ raise NotImplementedError\n\n    def is_verification_file(self, path: pathlib.Path,\
    \ *, basedir: pathlib.Path) -> bool:\n        return '.test.' in path.name\n\n\
    \    @abc.abstractmethod\n    def list_environments(self, path: pathlib.Path,\
    \ *, basedir: pathlib.Path) -> Sequence[LanguageEnvironment]:\n        raise NotImplementedError\n"
  dependsOn:
  - onlinejudge_verify/languages/special_comments.py
  isVerificationFile: false
  path: onlinejudge_verify/languages/models.py
  requiredBy:
  - onlinejudge_verify/languages/cplusplus.py
  - onlinejudge_verify/languages/nim.py
  - onlinejudge_verify/languages/csharpscript.py
  - onlinejudge_verify/languages/rust.py
  - onlinejudge_verify/languages/python.py
  timestamp: '2024-05-05 05:59:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/languages/models.py
layout: document
redirect_from:
- /library/onlinejudge_verify/languages/models.py
- /library/onlinejudge_verify/languages/models.py.html
title: onlinejudge_verify/languages/models.py
---
