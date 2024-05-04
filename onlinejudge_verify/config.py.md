---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: onlinejudge_verify/languages/cplusplus.py
    title: onlinejudge_verify/languages/cplusplus.py
  - icon: ':warning:'
    path: onlinejudge_verify/languages/nim.py
    title: onlinejudge_verify/languages/nim.py
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
  code: "# Python Version: 3.x\nimport pathlib\nfrom logging import getLogger\nfrom\
    \ typing import *\n\nimport toml\n\nlogger = getLogger(__name__)\n\ndefault_config_path\
    \ = pathlib.Path('.verify-helper/config.toml')\n\n_loaded_config: Optional[Dict[str,\
    \ Any]] = None\n\n\ndef set_config_path(config_path: pathlib.Path) -> None:\n\
    \    global _loaded_config  # pylint: disable=invalid-name\n    assert _loaded_config\
    \ is None\n    if not config_path.exists():\n        _loaded_config = {}\n   \
    \     logger.info('no config file')\n    else:\n        _loaded_config = dict(toml.load(str(config_path)))\n\
    \        logger.info('config file loaded: %s: %s', str(config_path), _loaded_config)\n\
    \n\ndef get_config() -> Dict[str, Any]:\n    if _loaded_config is None:\n    \
    \    set_config_path(default_config_path)\n    assert _loaded_config is not None\n\
    \    return _loaded_config\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/config.py
  requiredBy:
  - onlinejudge_verify/languages/cplusplus.py
  - onlinejudge_verify/languages/nim.py
  - onlinejudge_verify/languages/rust.py
  timestamp: '2024-05-05 05:09:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/config.py
layout: document
redirect_from:
- /library/onlinejudge_verify/config.py
- /library/onlinejudge_verify/config.py.html
title: onlinejudge_verify/config.py
---
