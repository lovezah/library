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
  code: "from typing import *\n\nimport yaml\n\n_separator: bytes = b'---'\n\n\ndef\
    \ _split_front_matter_without_parsing_yaml(content: bytes) -> Tuple[bytes, bytes]:\n\
    \    lines = content.splitlines(keepends=True)\n    if len(lines) == 0 or lines[0].rstrip()\
    \ != _separator:\n        return (b'', content)\n    for i, line in enumerate(lines):\n\
    \        if i == 0:\n            continue\n        if line.rstrip() == _separator:\n\
    \            break\n    else:\n        return b'', content\n\n    front_matter\
    \ = b''.join(lines[1:i])\n    content = b''.join(lines[i + 1:])\n    return front_matter,\
    \ content\n\n\ndef split_front_matter(content: bytes) -> Tuple[Dict[str, Any],\
    \ bytes]:\n    front_matter, content = _split_front_matter_without_parsing_yaml(content)\n\
    \    return yaml.safe_load(front_matter) or {}, content\n\n\ndef merge_front_matter(front_matter:\
    \ Dict[str, Any], content: bytes) -> bytes:\n    if not front_matter:\n      \
    \  return content\n    return b'\\n'.join([\n        _separator,\n        yaml.safe_dump(front_matter).rstrip().encode(),\n\
    \        _separator,\n        content,\n    ])\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/documentation/front_matter.py
  requiredBy: []
  timestamp: '2024-05-05 05:09:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/documentation/front_matter.py
layout: document
redirect_from:
- /library/onlinejudge_verify/documentation/front_matter.py
- /library/onlinejudge_verify/documentation/front_matter.py.html
title: onlinejudge_verify/documentation/front_matter.py
---
