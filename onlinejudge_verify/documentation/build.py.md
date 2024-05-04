---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: onlinejudge_verify/documentation/main.py
    title: onlinejudge_verify/documentation/main.py
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
  code: "\"\"\"This module generate actual pages for given metadata. This module doesn't\
    \ collect metadata to generate pages.\n\"\"\"\n\nimport copy\nimport pathlib\n\
    import traceback\nfrom logging import getLogger\nfrom typing import *\n\nimport\
    \ pkg_resources\nimport yaml\n\nimport onlinejudge_verify.documentation.front_matter\n\
    import onlinejudge_verify.languages.list\nimport onlinejudge_verify.utils as utils\n\
    from onlinejudge_verify.documentation.type import *\n\nlogger = getLogger(__name__)\n\
    \n_RESOURCE_PACKAGE = 'onlinejudge_verify_resources'\n_COPIED_STATIC_FILE_PATHS:\
    \ List[str] = [\n    '_layouts/page.html',\n    '_layouts/document.html',\n  \
    \  '_layouts/toppage.html',\n    '_includes/mathjax.html',\n    '_includes/theme_fix.html',\n\
    \    '_includes/highlight.html',\n    '_includes/document_header.html',\n    '_includes/document_body.html',\n\
    \    '_includes/document_footer.html',\n    '_includes/toppage_header.html',\n\
    \    '_includes/toppage_body.html',\n    'assets/css/copy-button.css',\n    'assets/js/copy-button.js',\n\
    \    'Gemfile',\n]\n\n\ndef _build_page_title_dict(*, page_render_jobs: List[PageRenderJob])\
    \ -> Dict[pathlib.Path, str]:\n    page_title_dict: Dict[pathlib.Path, str] =\
    \ {}\n    for job in page_render_jobs:\n        assert job.path.suffix == '.md'\n\
    \        title = job.front_matter.get(FrontMatterItem.title.value)\n        if\
    \ title is None:\n            title = str(job.path.parent / job.path.stem)\n \
    \       page_title_dict[job.path] = title\n        page_title_dict[job.path.parent\
    \ / job.path.stem] = title\n    return page_title_dict\n\n\ndef _get_verification_status_icon(verification_status:\
    \ VerificationStatus) -> str:\n    table = {\n        VerificationStatus.LIBRARY_ALL_AC:\
    \ ':heavy_check_mark:',\n        VerificationStatus.LIBRARY_PARTIAL_AC: ':question:',\n\
    \        VerificationStatus.LIBRARY_SOME_WA: ':question:',\n        VerificationStatus.LIBRARY_ALL_WA:\
    \ ':x:',\n        VerificationStatus.LIBRARY_NO_TESTS: ':warning:',\n        VerificationStatus.TEST_ACCEPTED:\
    \ ':heavy_check_mark:',\n        VerificationStatus.TEST_WRONG_ANSWER: ':x:',\n\
    \        VerificationStatus.TEST_WAITING_JUDGE: ':warning:',\n    }\n    return\
    \ table[verification_status]\n\n\ndef _render_source_code_stat(stat: SourceCodeStat,\
    \ *, basedir: pathlib.Path) -> Dict[str, Any]:\n    with open(basedir / stat.path,\
    \ 'rb') as fh:\n        code = fh.read().decode()\n    try:\n        language\
    \ = onlinejudge_verify.languages.list.get(stat.path)\n        assert language\
    \ is not None\n        bundled_code = language.bundle(stat.path, basedir=basedir,\
    \ options={'include_paths': [basedir]}).decode()\n    except Exception:\n    \
    \    logger.warning(\"failed to bundle: %s\", str(stat.path))\n        bundled_code\
    \ = traceback.format_exc()\n    return {\n        'path': str(stat.path),\n  \
    \      'code': code,\n        'bundledCode': bundled_code,\n        'isVerificationFile':\
    \ stat.is_verification_file,\n        'verificationStatus': stat.verification_status.value,\n\
    \        'timestamp': str(stat.timestamp),\n        'dependsOn': [str(path) for\
    \ path in stat.depends_on],\n        'requiredBy': [str(path) for path in stat.required_by],\n\
    \        'verifiedWith': [str(path) for path in stat.verified_with],\n       \
    \ 'attributes': stat.attributes,\n    }\n\n\ndef _render_source_code_stat_for_page(\n\
    \    path: pathlib.Path,\n    *,\n    source_code_stats_dict: Dict[pathlib.Path,\
    \ SourceCodeStat],\n    page_title_dict: Dict[pathlib.Path, str],\n    basedir:\
    \ pathlib.Path,\n) -> Dict[str, Any]:\n    relative_path = (basedir / path).resolve().relative_to(basedir)\n\
    \    stat = source_code_stats_dict[relative_path]\n    data = _render_source_code_stat(stat,\
    \ basedir=basedir)\n    data['_pathExtension'] = path.suffix.lstrip('.')\n   \
    \ data['_verificationStatusIcon'] = _get_verification_status_icon(stat.verification_status)\n\
    \    data['_isVerificationFailed'] = stat.verification_status in (VerificationStatus.LIBRARY_SOME_WA,\
    \ VerificationStatus.LIBRARY_ALL_WA, VerificationStatus.TEST_WRONG_ANSWER)\n\n\
    \    def ext(relative_path: pathlib.Path) -> Dict[str, Any]:\n        stat = source_code_stats_dict[relative_path]\n\
    \        return {\n            'path': str(relative_path),\n            'title':\
    \ page_title_dict[relative_path],\n            'icon': _get_verification_status_icon(stat.verification_status),\n\
    \        }\n\n    data['_extendedDependsOn'] = [ext(path) for path in sorted(stat.depends_on,\
    \ key=str)]\n    data['_extendedRequiredBy'] = [ext(path) for path in sorted(stat.required_by,\
    \ key=str)]\n    data['_extendedVerifiedWith'] = [ext(path) for path in sorted(stat.verified_with,\
    \ key=str)]\n\n    return data\n\n\ndef _render_source_code_stats_for_top_page(\n\
    \    *,\n    source_code_stats: List[SourceCodeStat],\n    page_title_dict: Dict[pathlib.Path,\
    \ str],\n    basedir: pathlib.Path,\n) -> Dict[str, Any]:\n    library_categories:\
    \ Dict[str, List[Dict[str, str]]] = {}\n    verification_categories: Dict[str,\
    \ List[Dict[str, str]]] = {}\n    for stat in source_code_stats:\n        if utils.is_verification_file(stat.path,\
    \ basedir=basedir):\n            categories = verification_categories\n      \
    \  else:\n            categories = library_categories\n        category = str(stat.path.parent)\n\
    \        if category not in categories:\n            categories[category] = []\n\
    \        categories[category].append({\n            'path': str(stat.path),\n\
    \            'title': page_title_dict[stat.path],\n            'icon': _get_verification_status_icon(stat.verification_status),\n\
    \        })\n\n    data: Dict[str, Any] = {}\n    data['libraryCategories'] =\
    \ []\n    for category, pages in library_categories.items():\n        data['libraryCategories'].append({\n\
    \            'name': category,\n            'pages': pages,\n        })\n    data['verificationCategories']\
    \ = []\n    for category, pages in verification_categories.items():\n        data['verificationCategories'].append({\n\
    \            'name': category,\n            'pages': pages,\n        })\n    return\
    \ data\n\n\ndef render_pages(*, page_render_jobs: List[PageRenderJob], source_code_stats:\
    \ List[SourceCodeStat], site_render_config: SiteRenderConfig) -> Dict[pathlib.Path,\
    \ bytes]:\n    \"\"\"\n    :returns: mapping from absolute paths to file contents\n\
    \    \"\"\"\n\n    page_title_dict = _build_page_title_dict(page_render_jobs=page_render_jobs)\n\
    \    source_code_stats_dict = {stat.path: stat for stat in source_code_stats}\n\
    \n    rendered_pages: Dict[pathlib.Path, bytes] = {}\n    for job in page_render_jobs:\n\
    \        documentation_of = job.front_matter.get(FrontMatterItem.documentation_of.value)\n\
    \n        front_matter = copy.deepcopy(job.front_matter)\n        if front_matter.get(FrontMatterItem.layout.value)\
    \ == 'toppage':\n            data = _render_source_code_stats_for_top_page(source_code_stats=source_code_stats,\
    \ page_title_dict=page_title_dict, basedir=site_render_config.basedir)\n     \
    \       front_matter[FrontMatterItem.data.value] = data\n\n        elif documentation_of\
    \ is not None:\n            front_matter.setdefault(FrontMatterItem.layout.value,\
    \ 'document')\n            data = _render_source_code_stat_for_page(pathlib.Path(documentation_of),\
    \ source_code_stats_dict=source_code_stats_dict, page_title_dict=page_title_dict,\
    \ basedir=site_render_config.basedir)\n            front_matter.setdefault(FrontMatterItem.data.value,\
    \ data)\n\n        path = site_render_config.destination_dir / job.path\n    \
    \    content = onlinejudge_verify.documentation.front_matter.merge_front_matter(front_matter,\
    \ job.content)\n        rendered_pages[path] = content\n\n    return rendered_pages\n\
    \n\ndef render_source_code_stats(*, source_code_stats: List[SourceCodeStat], basedir:\
    \ pathlib.Path) -> List[Dict[str, Any]]:\n    data: List[Dict[str, Any]] = []\n\
    \    for stat in source_code_stats:\n        data.append(_render_source_code_stat(stat,\
    \ basedir=basedir))\n    return data\n\n\ndef load_static_files(*, site_render_config:\
    \ SiteRenderConfig) -> Dict[pathlib.Path, bytes]:\n    files: Dict[pathlib.Path,\
    \ bytes] = {}\n\n    # write merged config.yml\n    files[site_render_config.destination_dir\
    \ / '_config.yml'] = yaml.safe_dump(site_render_config.config_yml).encode()\n\n\
    \    # load files in onlinejudge_verify_resources/\n    for path in _COPIED_STATIC_FILE_PATHS:\n\
    \        files[site_render_config.destination_dir / pathlib.Path(path)] = pkg_resources.resource_string(_RESOURCE_PACKAGE,\
    \ path)\n\n    # overwrite with docs/static\n    for src in site_render_config.static_dir.glob('**/*'):\n\
    \        if src.is_file():\n            dst = site_render_config.destination_dir\
    \ / src.relative_to(site_render_config.static_dir)\n            with open(src,\
    \ 'rb') as fh:\n                files[dst] = fh.read()\n    return files\n"
  dependsOn: []
  isVerificationFile: false
  path: onlinejudge_verify/documentation/build.py
  requiredBy:
  - onlinejudge_verify/documentation/main.py
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: onlinejudge_verify/documentation/build.py
layout: document
redirect_from:
- /library/onlinejudge_verify/documentation/build.py
- /library/onlinejudge_verify/documentation/build.py.html
title: onlinejudge_verify/documentation/build.py
---
