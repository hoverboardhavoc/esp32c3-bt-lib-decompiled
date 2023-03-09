/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_lld_scan_start_eco(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char acStack_31 [9];
  
  acStack_31[0] = '\f';
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x7f4))
                    (1,acStack_31,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x7f4));
  if (iVar3 == 0) {
    iVar3 = r_lld_scan_start(param_1,param_2);
    acStack_31[0] = (char)iVar3;
    if (iVar3 == 0) {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
      if (*(char *)(iVar3 + 1) == '\0') {
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if (*(short *)(iVar3 + 0x14) != 0) {
          _DAT_60031124 = 0x10001;
          iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
          uVar1 = *(ushort *)(iVar3 + 0x14);
          if ((uVar1 & 0xfe00) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ed,*(code **)(_r_plf_funcs_p + 8));
          }
          _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | (uint)uVar1;
        }
      }
      else {
        _DAT_60031124 = 0x10001;
        _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | 1;
      }
      if ((acStack_31[0] == '\0') && (_lld_scan_env != (int *)0x0)) {
        piVar5 = _lld_scan_env + 2;
        piVar2 = _lld_scan_env;
        do {
          if (*piVar2 != 0) {
            iVar4 = (uint)*(byte *)(*piVar2 + 0x38) * 0x5a;
            iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar1 = *(ushort *)(iVar3 + iVar4);
            iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            *(ushort *)(iVar3 + iVar4) = uVar1 & 0xffdf;
          }
          piVar2 = piVar2 + 1;
        } while (piVar2 != piVar5);
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x7f4))
              (0,acStack_31,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x7f4));
  }
  return acStack_31[0];
}

