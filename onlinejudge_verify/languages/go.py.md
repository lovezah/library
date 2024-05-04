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
  code: "from typing import *\n\nfrom onlinejudge_verify.config import get_config\n\
    from onlinejudge_verify.languages.user_defined import UserDefinedLanguage\n\n\n\
    # TODO: stop using UserDefinedLanguage\nclass GoLanguage(UserDefinedLanguage):\n\
    \    config: Dict[str, Any]\n\n    def __init__(self, *, config: Optional[Dict[str,\
    \ Any]] = None):\n        if config is None:\n            config = get_config().get('languages',\
    \ {}).get('go', {})\n        config.setdefault('compile', 'echo')\n        config.setdefault('execute',\
    \ 'go run {basedir}/{path}')\n        super().__init__(extension='go', config=config)\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/languages/go.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/languages/go.py
layout: document
redirect_from:
- /library/onlinejudge_verify/languages/go.py
- /library/onlinejudge_verify/languages/go.py.html
title: onlinejudge_verify/languages/go.py
---
