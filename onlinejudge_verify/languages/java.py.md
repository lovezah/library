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
  code: "import pathlib\nimport subprocess\nimport sys\nfrom logging import getLogger\n\
    from typing import *\n\nfrom onlinejudge_verify.config import get_config\nfrom\
    \ onlinejudge_verify.languages.models import LanguageEnvironment\nfrom onlinejudge_verify.languages.user_defined\
    \ import UserDefinedLanguage\n\nlogger = getLogger(__name__)\n\n\nclass JavaLanguageEnvironment(LanguageEnvironment):\n\
    \    def compile(self, path: pathlib.Path, *, basedir: pathlib.Path, tempdir:\
    \ pathlib.Path) -> None:\n        command = ['javac', str(basedir / path)]\n \
    \       logger.info('$ %s', command)\n        subprocess.check_call(command, stdout=sys.stdout,\
    \ stderr=sys.stderr)\n\n    def get_execute_command(self, path: pathlib.Path,\
    \ *, basedir: pathlib.Path, tempdir: pathlib.Path) -> List[str]:\n        relative_path\
    \ = (basedir / path).relative_to(basedir)\n        class_path = '.'.join([*relative_path.parent.parts,\
    \ relative_path.stem])\n        return ['java', class_path]\n\n\n# TODO: stop\
    \ using UserDefinedLanguage\nclass JavaLanguage(UserDefinedLanguage):\n    config:\
    \ Dict[str, Any]\n\n    def __init__(self, *, config: Optional[Dict[str, Any]]\
    \ = None):\n        if config is None:\n            config = get_config().get('languages',\
    \ {}).get('java', {})\n        if 'compile' in config:\n            raise RuntimeError('You\
    \ cannot overwrite \"compile\" for Java language')\n        if 'execute' in config:\n\
    \            raise RuntimeError('You cannot overwrite \"execute\" for Java language')\n\
    \        super().__init__(extension='java', config=config)\n\n    def list_environments(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> Sequence[LanguageEnvironment]:\n\
    \        return [JavaLanguageEnvironment()]\n\n    def is_verification_file(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> bool:\n        return path.name.endswith(\"\
    _test.java\")\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/languages/java.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/languages/java.py
layout: document
redirect_from:
- /library/onlinejudge_verify/languages/java.py
- /library/onlinejudge_verify/languages/java.py.html
title: onlinejudge_verify/languages/java.py
---
