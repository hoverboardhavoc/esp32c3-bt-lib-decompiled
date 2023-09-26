/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_start_hook(int param_1,char *param_2)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  
  piVar11 = _lld_scan_env;
  if ((param_1 == 0) && (*param_2 == '\0')) {
    if (_lld_scan_env != (int *)0x0) {
      piVar10 = _lld_scan_env + 2;
      iVar7 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
      do {
        if (*piVar11 != 0) {
          sVar1 = *(short *)(iVar7 + 0x14);
          uVar6 = (uint)*(byte *)(*piVar11 + 0x38);
          if ((sVar1 != 0) && (*(short *)(iVar7 + 0x16) != 0)) {
            iVar5 = uVar6 * 0x5a;
            iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar9 = _r_plf_funcs_p;
            *(short *)(iVar8 + iVar5 + 0xc) = sVar1;
            uVar2 = *(undefined2 *)(iVar7 + 0x16);
            iVar9 = (**(code **)(iVar9 + 0xbc))(0x400,*(code **)(iVar9 + 0xbc));
            *(undefined2 *)(iVar5 + 0xe + iVar9) = uVar2;
          }
          uVar3 = *(ushort *)(iVar7 + 0x18);
          if (uVar3 != 0) {
            if ((uVar3 & 0xc0) != 0) {
              (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x3cf,*(code **)(_r_plf_funcs_p + 8))
              ;
            }
            iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            iVar9 = uVar6 * 0x5a + 0x16;
            uVar4 = *(ushort *)(iVar5 + iVar9);
            iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            *(ushort *)(iVar9 + iVar5) = uVar4 & 0xffc0 | uVar3 & 0xff;
          }
        }
        piVar11 = piVar11 + 1;
      } while (piVar11 != piVar10);
    }
    return 0;
  }
  return 0;
}

