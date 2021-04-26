from pysmina import sminalib
import os

if __name__ == "__main__":
    base_dir : str = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'data')
    params: dict = dict(center_x=-14,
                        center_y=18,
                        center_z=-15,
                        size_x=14,
                        size_y=18,
                        size_z=15.0,
                        receptor=f"{base_dir}/receptor.pdbqt",
                        ligand=f"{base_dir}/ligand.pdbqt")
    # autobox_add: float = 4.0  # Default
    sdfs: str = sminalib.run(params)
    print(sdfs)
