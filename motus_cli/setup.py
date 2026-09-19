from setuptools import setup, find_packages

setup(
    name='motus_cli',
    version='0.1.0',
    packages=find_packages(),
    entry_points={'console_scripts': ['motus = motus_cli.cli:main']},
    install_requires=['setuptools'],
)
