from setuptools import find_packages
from setuptools import setup

setup(
    name='mycobot_pro450_interfaces',
    version='1.0.0',
    packages=find_packages(
        include=('mycobot_pro450_interfaces', 'mycobot_pro450_interfaces.*')),
)
