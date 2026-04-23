# HM-Software-Emulating-Mobile-Devices
Repository containing customized versions of the HM Software that emulate the video coding constraints observed in HEVC mobile codecs manufactured by Apple, Qualcomm, and MediaTek.

This research focused on characterizing the hardware-friendly video coding constraints inherently adopted in dedicated SoCs for HEVC encoding. The analysis covered chipsets from three different manufacturers:

- Apple — A16 Bionic  
- Qualcomm — Snapdragon 8 Gen 2  
- MediaTek — Helio G95  

After identifying the constraints of each platform, three separate versions of the HM Software were developed, each one reproducing the behavior of one analyzed chipset.

The implemented modifications include:

- Simplification of the block partitioning scheme  
- Reduction of the TZSearch Search Range  
- Changes to the GOP structure  
- Disabling of specific intra modes for selected Prediction Block sizes  

These emulated HM versions were later used to measure the coding efficiency losses caused by such hardware-friendly constraints and to compare the results against other state-of-the-art HEVC solutions.

The full research papers derived from this work can be found in the links below:
https://doi.org/10.5753/jbcs.2026.5354  
https://doi.org/10.1109/LASCAS60203.2024.10506151

