/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_start_hook(int param_1,char *param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  piVar6 = _lld_scan_env;
  if (param_1 != 0) {
    return 0;
  }
  if ((*param_2 == '\0') && (_lld_scan_env != (int *)0x0)) {
    piVar10 = _lld_scan_env + 2;
    iVar7 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
    do {
      if (*piVar6 != 0) {
        sVar1 = *(short *)(iVar7 + 0x14);
        uVar5 = (uint)*(byte *)(*piVar6 + 0x38);
        if ((sVar1 != 0) && (*(short *)(iVar7 + 0x16) != 0)) {
          iVar9 = uVar5 * 0x5a;
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(short *)(iVar9 + 0xc + iVar8) = sVar1;
          uVar2 = *(undefined2 *)(iVar7 + 0x16);
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)(iVar9 + 0xe + iVar8) = uVar2;
        }
        uVar3 = *(ushort *)(iVar7 + 0x18);
        if (uVar3 != 0) {
          if ((uVar3 & 0xc0) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x3cf,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar8 = uVar5 * 0x5a + 0x16;
          uVar4 = *(ushort *)(iVar9 + iVar8);
          iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar8 + iVar9) = uVar3 & 0xff | uVar4 & 0xffc0;
        }
      }
      piVar6 = piVar6 + 1;
    } while (piVar6 != piVar10);
  }
  lld_rpa_renew_start(*(undefined1 *)(param_3 + 0x12));
  return 0;
}

