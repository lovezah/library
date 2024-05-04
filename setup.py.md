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
    - https://github.com/kmyk/online-judge-verify-helper
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\nfrom setuptools import find_packages, setup\n\nsetup(\n\
    \    name='online-judge-verify-helper',\n    version='5.6.0',\n    author='Kimiyuki\
    \ Onaka',\n    author_email='kimiyuki95@gmail.com',\n    url='https://github.com/kmyk/online-judge-verify-helper',\n\
    \    license='MIT License',\n    description='',\n    python_requires='>=3.8',\n\
    \    install_requires=[\n        'colorlog',\n        'pyyaml',\n        'online-judge-tools\
    \ >= 11.3.0',\n        'setuptools',\n        'toml',\n        'importlab',\n\
    \    ],\n    packages=find_packages(exclude=('tests', 'docs')),\n    package_data={\n\
    \        'onlinejudge_verify_resources': ['*', '_layouts/*', '_includes/*', 'assets/*',\
    \ 'assets/css/*', 'assets/js/*'],\n    },\n    entry_points={\n        'console_scripts':\
    \ [\n            'oj-verify = onlinejudge_verify.main:main',\n            'oj-bundle\
    \ = onlinejudge_bundle.main:main',\n        ],\n    },\n)\n"
  dependsOn: []
  isVerificationFile: false
  path: setup.py
  requiredBy: []
  timestamp: '2024-05-05 04:59:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setup.py
layout: document
redirect_from:
- /library/setup.py
- /library/setup.py.html
title: setup.py
---
