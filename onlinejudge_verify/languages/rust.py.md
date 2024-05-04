---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: onlinejudge_verify/config.py
    title: onlinejudge_verify/config.py
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
    links:
    - https://doc.rust-lang.org/cargo/commands/cargo-metadata.html#output-format>
    - https://docs.rs/cargo/0.49.0/cargo/ops/enum.CompileFilter.html#method.need_dev_deps
    - https://docs.rs/cargo/0.49.0/src/cargo/util/important_paths.rs.html#6-20
    - https://docs.rs/cargo_metadata>
    - https://github.com/est31/cargo-udeps/pull/35
    - https://github.com/rust-lang/cargo/blob/rust-1.49.0/src/cargo/core/compiler/fingerprint.rs#L1824-L1830
    - https://github.com/rust-lang/cargo/blob/rust-1.49.0/src/cargo/core/compiler/fingerprint.rs#L1979-L1997
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import abc\nimport enum\nimport functools\nimport itertools\nimport json\n\
    import pathlib\nimport shutil\nimport subprocess\nfrom collections import defaultdict\n\
    from enum import Enum\nfrom logging import getLogger\nfrom subprocess import PIPE\n\
    from typing import *\n\nfrom onlinejudge_verify.config import get_config\nfrom\
    \ onlinejudge_verify.languages import special_comments\nfrom onlinejudge_verify.languages.models\
    \ import Language, LanguageEnvironment\n\nlogger = getLogger(__name__)\n_metadata_by_manifest_path:\
    \ Dict[pathlib.Path, Dict[str, Any]] = {}\n_cargo_checked_workspaces: Set[pathlib.Path]\
    \ = set()\n_related_source_files_by_workspace: Dict[pathlib.Path, Dict[pathlib.Path,\
    \ FrozenSet[pathlib.Path]]] = {}\n\n\nclass _ListDependenciesBackend:\n    @abc.abstractmethod\n\
    \    def list_dependencies(self, path: pathlib.Path, *, basedir: pathlib.Path)\
    \ -> List[pathlib.Path]:\n        raise NotImplementedError\n\n\nclass _NoBackend(_ListDependenciesBackend):\n\
    \    def list_dependencies(self, path: pathlib.Path, *, basedir: pathlib.Path)\
    \ -> List[pathlib.Path]:\n        return _list_dependencies_by_crate(path, basedir=basedir,\
    \ cargo_udeps_toolchain=None)\n\n\nclass _CargoUdeps(_ListDependenciesBackend):\n\
    \    toolchain: str = 'nightly'\n\n    def __init__(self, *, toolchain: Optional[str]):\n\
    \        if toolchain is not None:\n            self.toolchain = toolchain\n\n\
    \    def list_dependencies(self, path: pathlib.Path, *, basedir: pathlib.Path)\
    \ -> List[pathlib.Path]:\n        return _list_dependencies_by_crate(path, basedir=basedir,\
    \ cargo_udeps_toolchain=self.toolchain)\n\n\n@functools.lru_cache(maxsize=None)\n\
    def _list_dependencies_by_crate(path: pathlib.Path, *, basedir: pathlib.Path,\
    \ cargo_udeps_toolchain: Optional[str]) -> List[pathlib.Path]:\n    \"\"\"The\
    \ `list_dependencies` implementation for `_NoBackend` and `CargoUdeps`.\n\n  \
    \  :param path: A parameter in `Language.list_dependencies`.\n    :param basedir:\
    \ A parameter in `Language.list_dependencies`.\n    :param cargo_udeps_toolchain:\
    \ A Rust toolchain name for cargo-udeps. If it is `None`, we don't run cargo-udeps.\n\
    \    :returns: Paths to the `.rs` files for `Language.list_dependencies`.\n  \
    \  \"\"\"\n    path = basedir / path\n\n    # We regard that a generated file\
    \ does not depend on any files.\n    for parent in path.parents:\n        if (parent.parent\
    \ / 'Cargo.toml').exists() and parent.parts[-1] == 'target':\n            logger.warning('This\
    \ is a generated file!: %s', path)\n            return [path]\n\n    metadata\
    \ = _cargo_metadata(cwd=path.parent)\n\n    # First, collects source files in\
    \ the same crate.\n    common_result = set(_source_files_in_same_targets(path,\
    \ _related_source_files(basedir, metadata)))\n\n    main_package_and_target =\
    \ _find_target(metadata, path)\n    if not main_package_and_target:\n        return\
    \ sorted(common_result)\n    main_package, main_target = main_package_and_target\n\
    \n    packages_by_id = {p['id']: p for p in metadata['packages']}\n\n    class\
    \ DependencyNamespace(Enum):\n        NORMAL_DEVELOPMENT = enum.auto()\n     \
    \   BUILD = enum.auto()\n\n        @classmethod\n        def from_dep_kind(cls,\
    \ kind: str):\n            if kind == 'build':\n                return cls.BUILD\n\
    \            return cls.NORMAL_DEVELOPMENT\n\n    # Collect the `(|dev-|build-)dependencies`\
    \ into a <is a `build-dependency`> \u2192 (<\"extern crate name\"> \u2192 <package>)\
    \ dictionary.\n    dependencies: DefaultDict[DependencyNamespace, Dict[str, Dict[str,\
    \ Any]]] = defaultdict(dict)\n    for dep in next(n['deps'] for n in metadata['resolve']['nodes']\
    \ if n['id'] == main_package['id']):\n        if _need_dev_deps(main_target) or\
    \ any(k['kind'] is None for k in dep['dep_kinds']):\n            dependencies[DependencyNamespace.NORMAL_DEVELOPMENT][dep['name']]\
    \ = packages_by_id[dep['pkg']]\n        if any(k['kind'] == 'build' for k in dep['dep_kinds']):\n\
    \            dependencies[DependencyNamespace.BUILD][dep['name']] = packages_by_id[dep['pkg']]\n\
    \n    # If `cargo_udeps_toolchain` is present, collects packages that are \"unused\"\
    \ by `target`.\n    unused_packages = defaultdict(set)\n    if cargo_udeps_toolchain\
    \ is not None:\n        explicit_names_in_toml = {(DependencyNamespace.from_dep_kind(d['kind']),\
    \ d['rename']) for d in main_package['dependencies'] if d['rename']}\n       \
    \ if not shutil.which('cargo-udeps'):\n            raise RuntimeError('`cargo-udeps`\
    \ not in $PATH')\n        unused_deps = json.loads(subprocess.run(\n         \
    \   ['rustup', 'run', cargo_udeps_toolchain, 'cargo', 'udeps', '--output', 'json',\
    \ '--manifest-path', main_package['manifest_path'], *_target_option(main_target)],\n\
    \            cwd=metadata['workspace_root'],\n            check=False,\n     \
    \       stdout=PIPE,\n        ).stdout.decode())['unused_deps'].values()\n   \
    \     unused_dep = next((u for u in unused_deps if u['manifest_path'] == main_package['manifest_path']),\
    \ None)\n        if unused_dep:\n            names_in_toml = [(DependencyNamespace.NORMAL_DEVELOPMENT,\
    \ name_in_toml) for name_in_toml in [*unused_dep['normal'], *unused_dep['development']]]\n\
    \            names_in_toml.extend((DependencyNamespace.BUILD, name_in_toml) for\
    \ name_in_toml in unused_dep['build'])\n            for dependency_namespace,\
    \ name_in_toml in names_in_toml:\n                if (dependency_namespace, name_in_toml)\
    \ in explicit_names_in_toml:\n                    # If the `name_in_toml` is explicitly\
    \ renamed one, it equals to the `extern_crate_name`.\n                    unused_package\
    \ = dependencies[dependency_namespace][name_in_toml]['id']\n                else:\n\
    \                    # Otherwise, it equals to the `package.name`.\n         \
    \           unused_package = next(p['id'] for p in dependencies[dependency_namespace].values()\
    \ if p['name'] == name_in_toml)\n                unused_packages[dependency_namespace].add(unused_package)\n\
    \n    # Finally, adds source files related to the depended crates except:\n  \
    \  #\n    # - those detected by cargo-udeps\n    # - those come from Crates.io\
    \ or Git repositories (e.g. `proconio`, other people's libraries including `ac-library-rs`)\n\
    \n    # `main_package` should always be included.\n    # Note that cargo-udeps\
    \ does not detect it if it is unused.\n    # https://github.com/est31/cargo-udeps/pull/35\n\
    \    depended_packages = [main_package]\n    for dependency_namespace, values\
    \ in dependencies.items():\n        for depended_package in values.values():\n\
    \            if depended_package['id'] not in unused_packages[dependency_namespace]\
    \ and not depended_package['source']:\n                depended_packages.append(depended_package)\n\
    \n    ret = common_result\n\n    for depended_package in depended_packages:\n\
    \        depended_targets = [t for t in depended_package['targets'] if t != main_target\
    \ and (_is_build(t) or _is_lib_or_proc_macro(t))]\n        assert len(depended_targets)\
    \ <= 2\n        for depended_target in depended_targets:\n            related_source_files\
    \ = _related_source_files(basedir, _cargo_metadata_by_manifest_path(pathlib.Path(depended_package[\"\
    manifest_path\"])))\n            ret |= _source_files_in_same_targets(pathlib.Path(depended_target['src_path']).resolve(strict=True),\
    \ related_source_files)\n    return sorted(ret)\n\n\ndef _related_source_files(basedir:\
    \ pathlib.Path, metadata: Dict[str, Any]) -> Dict[pathlib.Path, FrozenSet[pathlib.Path]]:\n\
    \    \"\"\"Collects all of the `.rs` files recognized by a workspace.\n\n    :param\
    \ basedir: A parameter from `Language.list_dependencies`.\n    :param metadata:\
    \ Output of `cargo metadata`\n    :returns: A (main source file) \u2192 (other\
    \ related files) map\n    \"\"\"\n    if pathlib.Path(metadata['workspace_root'])\
    \ in _related_source_files_by_workspace:\n        return _related_source_files_by_workspace[pathlib.Path(metadata['workspace_root'])]\n\
    \n    # Runs `cargo check` to generate `$target_directory/debug/deps/*.d`.\n \
    \   if pathlib.Path(metadata['workspace_root']) not in _cargo_checked_workspaces:\n\
    \        subprocess.run(\n            ['cargo', 'check', '--manifest-path', str(pathlib.Path(metadata['workspace_root'],\
    \ 'Cargo.toml')), '--workspace', '--all-targets'],\n            cwd=metadata['workspace_root'],\n\
    \            check=True,\n        )\n        _cargo_checked_workspaces.add(pathlib.Path(metadata['workspace_root']))\n\
    \n    ret: Dict[pathlib.Path, FrozenSet[pathlib.Path]] = dict()\n\n    targets_in_workspace\
    \ = itertools.chain.from_iterable(p['targets'] for p in metadata['packages'] if\
    \ p['id'] in metadata['workspace_members'])\n    for target in targets_in_workspace:\n\
    \        # Finds the **latest** \"dep-info\" file that contains a line in the\
    \ following format, and parses the line.\n        #\n        # ```\n        #\
    \ <relative/absolute path to the `.d` file itself>: <relative/absolute path to\
    \ the root source file> <relative/aboslute paths to the other related files>...\n\
    \        # ```\n        #\n        # - https://github.com/rust-lang/cargo/blob/rust-1.49.0/src/cargo/core/compiler/fingerprint.rs#L1979-L1997\n\
    \        # - https://github.com/rust-lang/cargo/blob/rust-1.49.0/src/cargo/core/compiler/fingerprint.rs#L1824-L1830\n\
    \        if _is_build(target):\n            dep_info_paths = pathlib.Path(metadata['target_directory'],\
    \ 'debug', 'build').rglob(f'{_crate_name(target)}-*.d')\n        elif _is_example(target):\n\
    \            dep_info_paths = pathlib.Path(metadata['target_directory'], 'debug',\
    \ 'examples').glob(f'{_crate_name(target)}-*.d')\n        else:\n            dep_info_paths\
    \ = pathlib.Path(metadata['target_directory'], 'debug', 'deps').glob(f'{_crate_name(target)}-*.d')\n\
    \        for dep_info_path in sorted(dep_info_paths, key=lambda p: p.stat().st_mtime_ns,\
    \ reverse=True):\n            with open(dep_info_path) as file:\n            \
    \    dep_info = file.read()\n            for line in dep_info.splitlines():\n\
    \                ss = line.split(': ')\n                if len(ss) == 2 and pathlib.Path(metadata['workspace_root'],\
    \ ss[0]) == dep_info_path:\n                    paths = []\n                 \
    \   it = iter(ss[1].split())\n                    for s in it:\n             \
    \           while s.endswith('\\\\'):\n                            s = s.rstrip('\\\
    \\')\n                            s += ' '\n                            s += next(it)\n\
    \                        path = pathlib.Path(metadata['workspace_root'], s).resolve(strict=True)\n\
    \                        # Ignores paths that don't start with the `basedir`.\
    \ (e.g. `/dev/null`, `/usr/local/share/foo/bar`)\n                        try:\n\
    \                            # `PurePath.is_relative_to` is since Python 3.9.\n\
    \                            _ = path.relative_to(basedir)\n                 \
    \           paths.append(path)\n                        except ValueError:\n \
    \                           pass\n                    if paths[:1] == [pathlib.Path(target['src_path']).resolve(strict=True)]:\n\
    \                        ret[paths[0]] = frozenset(paths[1:])\n              \
    \          break\n            else:\n                continue\n            break\n\
    \        else:\n            logger.error('no `.d` file for `%s`', target[\"name\"\
    ])\n\n    _related_source_files_by_workspace[pathlib.Path(metadata['workspace_root'])]\
    \ = ret\n    return ret\n\n\ndef _source_files_in_same_targets(path: pathlib.Path,\
    \ related_source_files: Dict[pathlib.Path, FrozenSet[pathlib.Path]]) -> FrozenSet[pathlib.Path]:\n\
    \    \"\"\"Returns `.rs` file paths relating to `path`.\n\n    :param path: Path\
    \ to a `.rs` file\n    :param related_source_files: Output of `_related_source_files`\n\
    \    :returns: Relating `.rs` file paths\n    \"\"\"\n    # If `p` is `src_path`\
    \ of a target, it does not belong to any other target unless it's weirdly symlinked,\n\
    \    if path in related_source_files:\n        return frozenset({path, *related_source_files[path]})\n\
    \n    # Otherwise, it may be used by multiple targets with `#[path = \"..\"] mod\
    \ foo;` or something.\n    return frozenset(itertools.chain.from_iterable({k,\
    \ *v} for (k, v) in related_source_files.items() if path in v)) or frozenset({path})\n\
    \n\nclass RustLanguageEnvironment(LanguageEnvironment):\n    def compile(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path, tempdir: pathlib.Path) -> None:\n\
    \        path = basedir / path\n        metadata = _cargo_metadata(cwd=path.parent)\n\
    \        target = _ensure_target(metadata, path)\n        subprocess.run(\n  \
    \          ['cargo', 'build', '--release', *_target_option(target)],\n       \
    \     cwd=path.parent,\n            check=True,\n        )\n\n    def get_execute_command(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path, tempdir: pathlib.Path) -> List[str]:\n\
    \        path = basedir / path\n        metadata = _cargo_metadata(cwd=path.parent)\n\
    \        target = _ensure_target(metadata, path)\n        return [str(pathlib.Path(metadata['target_directory'],\
    \ 'release', *([] if _is_bin(target) else ['examples']), target['name']))]\n\n\
    \nclass RustLanguage(Language):\n    _list_dependencies_backend: _ListDependenciesBackend\n\
    \n    def __init__(self, *, config: Optional[Dict[str, Any]] = None):\n      \
    \  if config is None:\n            config = get_config().get('languages', {}).get('rust',\
    \ {})\n\n        # Parses `languages.rust.list_dependencies_backend`.\n      \
    \  if 'list_dependencies_backend' in config:\n            list_dependencies_backend\
    \ = config['list_dependencies_backend']\n\n            if not isinstance(list_dependencies_backend,\
    \ dict):\n                raise RuntimeError('`languages.rust.list_dependencies_backend`\
    \ must be `dict`')\n            if 'kind' not in list_dependencies_backend:\n\
    \                raise RuntimeError('missing `languages.rust.list_dependencies_backend.kind`')\n\
    \n            list_dependencies_backend_kind = list_dependencies_backend['kind']\n\
    \n            if not isinstance(list_dependencies_backend_kind, str):\n      \
    \          raise RuntimeError('`languages.rust.list_dependencies_backend.kind`\
    \ must be `str`')\n\n            if list_dependencies_backend_kind == 'none':\n\
    \                self._list_dependencies_backend = _NoBackend()\n            elif\
    \ list_dependencies_backend_kind == 'cargo-udeps':\n                if 'toolchain'\
    \ not in list_dependencies_backend:\n                    toolchain = None\n  \
    \              elif isinstance(list_dependencies_backend['toolchain'], str):\n\
    \                    toolchain = list_dependencies_backend['toolchain']\n    \
    \            else:\n                    raise RuntimeError('`languages.rust.list_dependencies_backend.toolchain`\
    \ must be `str`')\n                self._list_dependencies_backend = _CargoUdeps(toolchain=toolchain)\n\
    \            else:\n                raise RuntimeError(\"expected 'none' or 'cargo-udeps'\
    \ for `languages.rust.list_dependencies_backend.kind`\")\n        else:\n    \
    \        self._list_dependencies_backend = _NoBackend()\n\n    def list_dependencies(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> List[pathlib.Path]:\n     \
    \   return self._list_dependencies_backend.list_dependencies(path, basedir=basedir)\n\
    \n    def bundle(self, path: pathlib.Path, *, basedir: pathlib.Path, options:\
    \ Dict[str, Any]) -> bytes:\n        raise NotImplementedError\n\n    def is_verification_file(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> bool:\n        path = basedir\
    \ / path\n        metadata = _cargo_metadata(cwd=path.parent)\n        package_and_target\
    \ = _find_target(metadata, path)\n        if not package_and_target:\n       \
    \     return False\n        _, target = package_and_target\n        return _is_bin_or_example_bin(target)\
    \ and 'PROBLEM' in special_comments.list_special_comments(path)\n\n    def list_environments(self,\
    \ path: pathlib.Path, *, basedir: pathlib.Path) -> Sequence[RustLanguageEnvironment]:\n\
    \        return [RustLanguageEnvironment()]\n\n\ndef _cargo_metadata(cwd: pathlib.Path)\
    \ -> Dict[str, Any]:\n    \"\"\"Returns \"metadata\" for a Cargo.toml file in\
    \ `cwd` or its parent directories.\n\n    :raises ValueError: if `cwd` is not\
    \ absolute or contains `..`\n    :returns: Output of `cargo metadata` command\n\
    \    \"\"\"\n    if not cwd.is_absolute() or '..' in cwd.parts:\n        raise\
    \ ValueError(f'the `cwd` parameter must be absolute and must not contain `..`:\
    \ {cwd}')\n\n    # https://docs.rs/cargo/0.49.0/src/cargo/util/important_paths.rs.html#6-20\n\
    \    for directory in [cwd, *cwd.parents]:\n        manifest_path = directory\
    \ / 'Cargo.toml'\n        if manifest_path.exists():\n            return _cargo_metadata_by_manifest_path(manifest_path)\n\
    \    raise RuntimeError(f'could not find `Cargo.toml` in `{cwd}` or any parent\
    \ directory')\n\n\ndef _cargo_metadata_by_manifest_path(manifest_path: pathlib.Path)\
    \ -> Dict[str, Any]:\n    \"\"\"Returns \"metadata\" for a certain `Cargo.toml`.\n\
    \n    :returns: Output of `cargo metadata` command\n    \"\"\"\n    if manifest_path\
    \ in _metadata_by_manifest_path:\n        return _metadata_by_manifest_path[manifest_path]\n\
    \n    metadata = _run_cargo_metadata(manifest_path)\n    root_manifest_path =\
    \ pathlib.Path(metadata['workspace_root'], 'Cargo.toml')\n    if root_manifest_path\
    \ != manifest_path:\n        metadata = _run_cargo_metadata(root_manifest_path)\n\
    \n    for key in [root_manifest_path, *(pathlib.Path(p['manifest_path']) for p\
    \ in metadata['packages'] if p['id'] in metadata['workspace_members'])]:\n   \
    \     _metadata_by_manifest_path[key] = metadata\n\n    return metadata\n\n\n\
    def _run_cargo_metadata(manifest_path: pathlib.Path) -> Dict[str, Any]:\n    \"\
    \"\"Runs `cargo metadata` for a certain `Cargo.toml`.\n\n    This function is\
    \ considered to be executed just once for every Cargo.toml in the repository.\n\
    \    For detailed information about `cargo metadata`, see:\n\n    - <https://doc.rust-lang.org/cargo/commands/cargo-metadata.html#output-format>\n\
    \    - <https://docs.rs/cargo_metadata>\n\n    :param manifest_path: Path to a\
    \ `Cargo.toml`\n    :returns: Output of `cargo metadata` command\n    \"\"\"\n\
    \    return json.loads(subprocess.run(\n        ['cargo', 'metadata', '--format-version',\
    \ '1', '--manifest-path', str(manifest_path)],\n        stdout=PIPE,\n       \
    \ cwd=manifest_path.parent,\n        check=True,\n    ).stdout.decode())\n\n\n\
    def _find_target(\n    metadata: Dict[str, Any],\n    src_path: pathlib.Path,\n\
    ) -> Optional[Tuple[Dict[str, Any], Dict[str, Any]]]:\n    for package in metadata['packages']:\n\
    \        for target in package['targets']:\n            # A `src_path` may contain\
    \ `..`\n            # The path may not actually exist by being excluded from the\
    \ package.\n            if pathlib.Path(target['src_path']).resolve() == src_path:\n\
    \                return package, target\n    return None\n\n\ndef _ensure_target(metadata:\
    \ Dict[str, Any], src_path: pathlib.Path) -> Dict[str, Any]:\n    package_and_target\
    \ = _find_target(metadata, src_path)\n    if not package_and_target:\n       \
    \ raise RuntimeError(f'{src_path} is not a main source file of any target')\n\
    \    _, target = package_and_target\n    return target\n\n\ndef _crate_name(target:\
    \ Dict[str, Any]) -> bool:\n    return target['name'].replace('-', '_')\n\n\n\
    def _is_build(target: Dict[str, Any]) -> bool:\n    return target['kind'] == ['custom-build']\n\
    \n\ndef _is_lib_or_proc_macro(target: Dict[str, Any]) -> bool:\n    return target['kind']\
    \ in [['lib'], ['proc-macro']]\n\n\ndef _is_bin(target: Dict[str, Any]) -> bool:\n\
    \    return target['kind'] == ['bin']\n\n\ndef _is_example(target: Dict[str, Any])\
    \ -> bool:\n    return target['kind'] == ['example']\n\n\ndef _is_bin_or_example_bin(target:\
    \ Dict[str, Any]) -> bool:\n    return _is_bin(target) or _is_example(target)\
    \ and target['crate_types'] == ['bin']\n\n\ndef _need_dev_deps(target: Dict[str,\
    \ Any]) -> bool:\n    # Comes from https://docs.rs/cargo/0.49.0/cargo/ops/enum.CompileFilter.html#method.need_dev_deps\n\
    \    return not (_is_lib_or_proc_macro(target) or _is_bin(target))\n\n\ndef _target_option(target:\
    \ Dict[str, Any]) -> List[str]:\n    if target['kind'] == ['bin']:\n        return\
    \ ['--bin', target['name']]\n    if target['kind'] == ['example']:\n        return\
    \ ['--example', target['name']]\n    if target['kind'] == ['test']:\n        return\
    \ ['--test', target['name']]\n    if target['kind'] == ['bench']:\n        return\
    \ ['--bench', target['name']]\n    return ['--lib']\n"
  dependsOn:
  - onlinejudge_verify/config.py
  - onlinejudge_verify/languages/models.py
  - onlinejudge_verify/languages/special_comments.py
  isVerificationFile: false
  path: onlinejudge_verify/languages/rust.py
  requiredBy: []
  timestamp: '2024-05-05 04:59:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/languages/rust.py
layout: document
redirect_from:
- /library/onlinejudge_verify/languages/rust.py
- /library/onlinejudge_verify/languages/rust.py.html
title: onlinejudge_verify/languages/rust.py
---
