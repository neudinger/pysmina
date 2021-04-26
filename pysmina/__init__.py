# -*- coding: utf-8 -*-
"""

## sminalib

This module is python boost c++ library with smina source code

Example:

example.py
```python
from pysmina import sminalib
import os

if __name__ == '__main__':
    base_dir : str = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'data')
    # autobox_add: float = 4.0  # Default
    params: dict = dict(center_x=-14,
                        center_y=18,
                        center_z=-15,
                        size_x=14,
                        size_y=18,
                        size_z=15.0,
                        receptor=f'{base_dir}/receptor.pdbqt',
                        ligand=f'{base_dir}/ligand.pdbqt')
    sdfs: str = sminalib.run(params)
    print(sdfs)
```
```python
ligand=f'{base_dir}/ligand.pdbqt'
# OR
ligand=[f'{base_dir}/ligand.pdbqt', f'{base_dir}/ligand2.pdbqt']
```
Todo:
    * Add Rdkit module
    * Add pandas module

"""