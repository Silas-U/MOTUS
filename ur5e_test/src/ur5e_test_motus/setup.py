from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'ur5e_test_motus'


def _data_files():
    files = [
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ]
    # Recursive-ish glob: one entry per subdirectory that actually has files,
    # so adding a new mesh file later never needs a setup.py edit (unlike
    # robokpy_controller's current per-robot explicit mesh globs).
    for root, dirs, filenames in os.walk('.'):
        rel = os.path.relpath(root, '.')
        if rel == '.' or rel.startswith('.') or rel.startswith('build') \
                or rel.startswith('install') or rel.startswith(package_name):
            continue
        if not filenames:
            continue
        dest = os.path.join('share', package_name, rel)
        files.append((dest, [os.path.join(root, f) for f in filenames]))
    return files


setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=_data_files(),
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='you',
    maintainer_email='you@example.com',
    description='Generated Motus robot project for ur5e_test.',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)
