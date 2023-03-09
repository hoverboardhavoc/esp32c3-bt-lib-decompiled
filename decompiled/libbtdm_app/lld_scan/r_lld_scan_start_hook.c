/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_start_hook(int param_1,char *param_2)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  
  piVar6 = _lld_scan_env;
  if ((param_1 == 0) && (*param_2 == '\0')) {
    if (_lld_scan_env != (int *)0x0) {
      piVar11 = _lld_scan_env + 2;
      iVar7 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
      do {
        if (*piVar6 != 0) {
          sVar2 = *(short *)(iVar7 + 0x14);
          uVar10 = (uint)*(byte *)(*piVar6 + 0x38);
          if ((sVar2 != 0) && (*(short *)(iVar7 + 0x16) != 0)) {
            iVar5 = uVar10 * 0x5a;
            iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar9 = _r_plf_funcs_p;
            *(short *)(iVar8 + iVar5 + 0xc) = sVar2;
            uVar3 = *(undefined2 *)(iVar7 + 0x16);
            iVar9 = (**(code **)(iVar9 + 0xbc))(0x400,*(code **)(iVar9 + 0xbc));
            *(undefined2 *)(iVar5 + 0xe + iVar9) = uVar3;
          }
          uVar4 = *(ushort *)(iVar7 + 0x18);
          if (0x24 < uVar4) {
            bVar1 = *(byte *)(iVar7 + 0x1a);
            if ((uVar4 & 0xc0) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x395,*(code **)(_r_plf_funcs_p + 8))
              ;
            }
            iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            *(ushort *)(uVar10 * 0x5a + 0x16 + iVar9) = uVar4 & 0xff | (ushort)bVar1 << 0xf;
          }
        }
        piVar6 = piVar6 + 1;
      } while (piVar6 != piVar11);
    }
    return 0;
  }
  return 0;
}

