---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/kmyk/online-judge-verify-helper/issues/116",
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import pathlib\nfrom logging import getLogger\nfrom typing import *\n\nfrom\
    \ onlinejudge_verify.config import get_config\nfrom onlinejudge_verify.languages.cplusplus\
    \ import CPlusPlusLanguage\nfrom onlinejudge_verify.languages.csharpscript import\
    \ CSharpScriptLanguage\nfrom onlinejudge_verify.languages.go import GoLanguage\n\
    from onlinejudge_verify.languages.haskell import HaskellLanguage\nfrom onlinejudge_verify.languages.java\
    \ import JavaLanguage\nfrom onlinejudge_verify.languages.models import Language\n\
    from onlinejudge_verify.languages.nim import NimLanguage\nfrom onlinejudge_verify.languages.python\
    \ import PythonLanguage\nfrom onlinejudge_verify.languages.ruby import RubyLanguage\n\
    from onlinejudge_verify.languages.rust import RustLanguage\nfrom onlinejudge_verify.languages.user_defined\
    \ import UserDefinedLanguage\n\nlogger = getLogger(__name__)\n\n_dict: Optional[Dict[str,\
    \ Language]] = None\n\n\ndef _get_dict() -> Dict[str, Language]:\n    global _dict\
    \  # pylint: disable=invalid-name\n    if _dict is None:\n        _dict = {}\n\
    \        _dict['.cpp'] = CPlusPlusLanguage()\n        _dict['.hpp'] = _dict['.cpp']\n\
    \        _dict['.cc'] = _dict['.cpp']\n        _dict['.h'] = _dict['.cpp']\n \
    \       _dict['.csx'] = CSharpScriptLanguage()\n        _dict['.nim'] = NimLanguage()\n\
    \        _dict['.py'] = PythonLanguage()\n        _dict['.hs'] = HaskellLanguage()\n\
    \        _dict['.ruby'] = RubyLanguage()\n        _dict['.go'] = GoLanguage()\n\
    \        _dict['.java'] = JavaLanguage()\n        _dict['.rs'] = RustLanguage()\n\
    \n        for ext, config in get_config().get('languages', {}).items():\n    \
    \        if '.' + ext in _dict:\n                if not isinstance(_dict['.' +\
    \ ext], UserDefinedLanguage):\n                    for key in ('compile', 'execute',\
    \ 'bundle', 'list_attributes', 'list_dependencies'):\n                       \
    \ if key in config:\n                            raise RuntimeError(\"You cannot\
    \ overwrite existing language: .{}\".format(ext))\n            else:\n       \
    \         logger.warning(\"config.toml: languages.%s: Adding new languages using\
    \ `config.toml` is supported but not recommended. Please consider making pull\
    \ requests for your languages, see https://github.com/kmyk/online-judge-verify-helper/issues/116\"\
    , ext)\n                _dict['.' + ext] = UserDefinedLanguage(extension=ext,\
    \ config=config)\n    return _dict\n\n\ndef get(path: pathlib.Path) -> Optional[Language]:\n\
    \    return _get_dict().get(path.suffix)\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/languages/list.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/languages/list.py
layout: document
redirect_from:
- /library/onlinejudge_verify/languages/list.py
- /library/onlinejudge_verify/languages/list.py.html
title: onlinejudge_verify/languages/list.py
---
