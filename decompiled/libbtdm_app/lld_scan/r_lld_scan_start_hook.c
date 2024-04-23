/*
 * Last changed at upstream commit 9780fd66d97866977d972fb63319830f47f12785
 * https://github.com/espressif/esp32c3-bt-lib/commit/9780fd66d97866977d972fb63319830f47f12785
 * Upstream date: 2024-04-23 11:19:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a771b7c)
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
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  
  piVar11 = _lld_scan_env;
  if (param_1 != 0) {
    return 0;
  }
  if ((*param_2 == '\0') && (_lld_scan_env != (int *)0x0)) {
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
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x3cf,*(code **)(_r_plf_funcs_p + 8));
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
  lld_rpa_renew_start(*(undefined1 *)(param_3 + 0x12));
  return 0;
}

