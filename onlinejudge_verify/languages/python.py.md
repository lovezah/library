---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: onlinejudge_verify/languages/models.py
    title: onlinejudge_verify/languages/models.py
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
  code: "# Python Version: 3.x\nimport concurrent.futures\nimport functools\nimport\
    \ pathlib\nimport platform\nimport sys\nimport textwrap\nfrom logging import getLogger\n\
    from typing import Any, Dict, List, Sequence, Tuple\n\nimport importlab.environment\n\
    import importlab.fs\nimport importlab.graph\n\nfrom onlinejudge_verify.languages.models\
    \ import Language, LanguageEnvironment\n\nlogger = getLogger(__name__)\n\n\nclass\
    \ PythonLanguageEnvironment(LanguageEnvironment):\n    def compile(self, path:\
    \ pathlib.Path, *, basedir: pathlib.Path, tempdir: pathlib.Path) -> None:\n  \
    \      code = textwrap.dedent(f\"\"\"\\\n            #!{sys.executable}\n    \
    \        \\\"\\\"\\\"This is a helper script to run the target Python code.\n\n\
    \            We need this script to set PYTHONPATH portably. The env command,\
    \ quoting something, etc. are not portable or difficult to implement.\n      \
    \      \\\"\\\"\\\"\n\n            import os\n            import sys\n\n     \
    \       # arguments\n            path = {repr(str(path.resolve()))}\n        \
    \    basedir = {repr(str(basedir.resolve()))}\n\n            # run {str(path)}\n\
    \            env = dict(os.environ)\n            if \"PYTHONPATH\" in env:\n \
    \               env[\"PYTHONPATH\"] = basedir + os.pathsep + env[\"PYTHONPATH\"\
    ] \n            else:\n                env[\"PYTHONPATH\"] = basedir  # set `PYTHONPATH`\
    \ to import files relative to the root directory\n            os.execve(sys.executable,\
    \ [sys.executable, path], env=env)  # use `os.execve` to avoid making an unnecessary\
    \ parent process\n        \"\"\")\n        with open(tempdir / 'compiled.py',\
    \ 'wb') as fh:\n            fh.write(code.encode())\n\n    def get_execute_command(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path, tempdir: pathlib.Path) -> List[str]:\n\
    \        return [sys.executable, str(tempdir / 'compiled.py')]\n\n\n@functools.lru_cache(maxsize=None)\n\
    def _python_list_depending_files(path: pathlib.Path, basedir: pathlib.Path) ->\
    \ List[pathlib.Path]:\n    # compute the dependency graph of the `path`\n    env\
    \ = importlab.environment.Environment(\n        importlab.fs.Path([importlab.fs.OSFileSystem(str(basedir.resolve()))]),\n\
    \        (sys.version_info.major, sys.version_info.minor),\n    )\n    try:\n\
    \        executor = concurrent.futures.ThreadPoolExecutor()\n        future =\
    \ executor.submit(importlab.graph.ImportGraph.create, env, [str(path)], trim=True)\n\
    \        if platform.uname().system == 'Windows':\n            timeout = 5.0 \
    \ # 1.0 sec causes timeout on CI using Windows\n        else:\n            timeout\
    \ = 1.0\n        res_graph = future.result(timeout=timeout)\n    except concurrent.futures.TimeoutError\
    \ as e:\n        raise RuntimeError(f\"Failed to analyze the dependency graph\
    \ (timeout): {path}\") from e\n    try:\n        node_deps_pairs = res_graph.deps_list()\
    \  # type: List[Tuple[str, List[str]]]\n    except Exception as e:\n        raise\
    \ RuntimeError(f\"Failed to analyze the dependency graph (circular imports?):\
    \ {path}\") from e\n    logger.debug('the dependency graph of %s: %s', str(path),\
    \ node_deps_pairs)\n\n    # collect Python files which are depended by the `path`\
    \ and under `basedir`\n    res_deps = []  # type: List[pathlib.Path]\n    res_deps.append(path.resolve())\n\
    \    for node_, deps_ in node_deps_pairs:\n        node = pathlib.Path(node_)\n\
    \        deps = list(map(pathlib.Path, deps_))\n        if node.resolve() == path.resolve():\n\
    \            for dep in deps:\n                if basedir.resolve() in dep.resolve().parents:\n\
    \                    res_deps.append(dep.resolve())\n            break\n    return\
    \ list(set(res_deps))\n\n\nclass PythonLanguage(Language):\n    def list_dependencies(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> List[pathlib.Path]:\n     \
    \   return _python_list_depending_files(path.resolve(), basedir)\n\n    def bundle(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path, options: Dict[str, Any]) -> bytes:\n\
    \        \"\"\"\n        :throws NotImplementedError:\n        \"\"\"\n      \
    \  raise NotImplementedError\n\n    def is_verification_file(self, path: pathlib.Path,\
    \ *, basedir: pathlib.Path) -> bool:\n        return '.test.py' in path.name\n\
    \n    def list_environments(self, path: pathlib.Path, *, basedir: pathlib.Path)\
    \ -> Sequence[PythonLanguageEnvironment]:\n        # TODO add another environment\
    \ (e.g. pypy)\n        return [PythonLanguageEnvironment()]\n"
  dependsOn:
  - onlinejudge_verify/languages/models.py
  isVerificationFile: false
  path: onlinejudge_verify/languages/python.py
  requiredBy: []
  timestamp: '2024-05-05 05:09:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/languages/python.py
layout: document
redirect_from:
- /library/onlinejudge_verify/languages/python.py
- /library/onlinejudge_verify/languages/python.py.html
title: onlinejudge_verify/languages/python.py
---
