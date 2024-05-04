---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: onlinejudge_verify/languages/models.py
    title: onlinejudge_verify/languages/models.py
  - icon: ':warning:'
    path: onlinejudge_verify/languages/special_comments.py
    title: onlinejudge_verify/languages/special_comments.py
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
  code: "# Python Version: 3.x\nimport functools\nimport os\nimport pathlib\nimport\
    \ re\nimport subprocess\nimport uuid\nfrom logging import getLogger\nfrom typing\
    \ import *\n\nimport onlinejudge_verify.languages.special_comments as special_comments\n\
    from onlinejudge_verify.languages.models import Language, LanguageEnvironment\n\
    \nlogger = getLogger(__name__)\n\ndotnet_dll_caches_dir = pathlib.Path('.verify-helper/cache')\
    \ / 'dotnet-script'\n\npragma_line_caches: Dict[pathlib.Path, Set[int]] = {}\n\
    \n\n@functools.lru_cache(maxsize=None)\ndef _publish_csx(path: pathlib.Path) ->\
    \ pathlib.Path:\n    path = path.resolve()\n    if path not in pragma_line_caches:\n\
    \        pragma_line_caches[path] = set()\n    filename = str(uuid.uuid4())\n\
    \    command = [\n        'dotnet-script',\n        'publish',\n        str(path),\n\
    \        '--dll',\n        '-n',\n        filename,\n        '-o',\n        str(dotnet_dll_caches_dir),\n\
    \        '-c',\n        'Release',\n    ]\n    logger.info('$ %s', ' '.join(command))\n\
    \    res = subprocess.check_output(command).decode().strip().splitlines()\n  \
    \  for warning in res[:-1]:\n        matchobj = re.match(r'^(?P<file>.*)\\((?P<line>\\\
    d+),\\d+\\): warning CS1633:', warning)\n        if matchobj is None:\n      \
    \      continue\n        file = pathlib.Path(matchobj.group('file'))\n       \
    \ line = int(matchobj.group('line'))\n        if file not in pragma_line_caches:\n\
    \            pragma_line_caches[file] = set()\n        pragma_line_caches[file].add(line)\n\
    \    return dotnet_dll_caches_dir / f'{filename}.dll'\n\n\n@functools.lru_cache(maxsize=None)\n\
    def _get_csx_dependencies(path: pathlib.Path) -> Set[pathlib.Path]:\n    def _resolve_dependencies(path:\
    \ pathlib.Path, deps: Set[pathlib.Path]) -> None:\n        path = path.resolve()\n\
    \        if path in deps:\n            return\n        deps.add(path)\n      \
    \  content = path.read_text()\n        matchobj = re.search(r'^\\s*#load\\s*\"\
    \\s*(.+)\\s*\"', content, flags=re.MULTILINE)\n        if matchobj is None:\n\
    \            return\n        for match in matchobj.groups():\n            if match.startswith(\"\
    nuget:\"):\n                continue\n            if os.path.isabs(match):\n \
    \               _resolve_dependencies(pathlib.Path(match), deps)\n           \
    \ else:\n                _resolve_dependencies(path.parent / match, deps)\\\n\n\
    \    res: Set[pathlib.Path] = set()\n    _resolve_dependencies(path.resolve(),\
    \ res)\n    return res\n\n\n@functools.lru_cache(maxsize=None)\ndef _get_csx_pragmas(path:\
    \ pathlib.Path) -> Dict[str, str]:\n    path = path.resolve()\n    if path not\
    \ in pragma_line_caches:\n        _publish_csx(path)\n    lines = path.read_text().splitlines()\n\
    \    res: Dict[str, str] = {}\n    for line in pragma_line_caches[path]:\n   \
    \     matchobj = re.search(r'^\\s*#pragma\\s+(?P<key>[^\\s]+)\\s*(?P<value>.*)\\\
    s*', lines[line - 1])\n        if matchobj is None:\n            continue\n  \
    \      key = matchobj.group('key')\n        value = matchobj.group('value')\n\
    \        res[key] = value\n    return res\n\n\nclass CSharpScriptLanguageEnvironment(LanguageEnvironment):\n\
    \    def compile(self, path: pathlib.Path, *, basedir: pathlib.Path, tempdir:\
    \ pathlib.Path) -> None:\n        _publish_csx(path)\n\n    def get_execute_command(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path, tempdir: pathlib.Path) -> List[str]:\n\
    \        return ['dotnet-script', 'exec', str(_publish_csx(path))]\n\n\nclass\
    \ CSharpScriptLanguage(Language):\n    def list_attributes(self, path: pathlib.Path,\
    \ *, basedir: pathlib.Path) -> Dict[str, Any]:\n        attributes: Dict[str,\
    \ Any] = special_comments.list_special_comments(path.resolve()) or _get_csx_pragmas(path.resolve())\n\
    \        attributes.setdefault('links', [])\n        attributes['links'].extend(special_comments.list_embedded_urls(path))\n\
    \        return attributes\n\n    def list_dependencies(self, path: pathlib.Path,\
    \ *, basedir: pathlib.Path) -> List[pathlib.Path]:\n        return list(_get_csx_dependencies(path.resolve()))\n\
    \n    def bundle(self, path: pathlib.Path, *, basedir: pathlib.Path, options:\
    \ Dict[str, Any]) -> bytes:\n        raise NotImplementedError\n\n    def list_environments(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> Sequence[CSharpScriptLanguageEnvironment]:\n\
    \        return [CSharpScriptLanguageEnvironment()]\n"
  dependsOn:
  - onlinejudge_verify/languages/special_comments.py
  - onlinejudge_verify/languages/models.py
  isVerificationFile: false
  path: onlinejudge_verify/languages/csharpscript.py
  requiredBy: []
  timestamp: '2024-05-05 05:59:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/languages/csharpscript.py
layout: document
redirect_from:
- /library/onlinejudge_verify/languages/csharpscript.py
- /library/onlinejudge_verify/languages/csharpscript.py.html
title: onlinejudge_verify/languages/csharpscript.py
---
