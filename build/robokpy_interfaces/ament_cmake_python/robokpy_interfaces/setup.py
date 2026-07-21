from setuptools import find_packages
from setuptools import setup

setup(
    name='robokpy_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('robokpy_interfaces', 'robokpy_interfaces.*')),
)
