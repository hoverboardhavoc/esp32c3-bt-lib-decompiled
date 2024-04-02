/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
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
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char acStack_41 [13];
  
  acStack_41[0] = '\f';
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x7f4))
                    (1,acStack_41,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x7f4));
  if (iVar3 == 0) {
    iVar3 = r_lld_scan_start(param_1,param_2);
    acStack_41[0] = (char)iVar3;
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
      if ((acStack_41[0] == '\0') && (_lld_scan_env != 0)) {
        iVar3 = 0;
        while( true ) {
          iVar6 = *(int *)(_lld_scan_env + iVar3 * 4);
          if (iVar6 != 0) {
            iVar2 = (uint)*(byte *)(iVar6 + 0x38) * 0x5a;
            iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar1 = *(ushort *)(iVar4 + iVar2);
            iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar5 = *(undefined4 *)(iVar6 + 4);
            *(ushort *)(iVar4 + iVar2) = uVar1 & 0xffdf;
            (&_LANCHOR0)[iVar3] = uVar5;
          }
          if (iVar3 == 1) break;
          iVar3 = 1;
        }
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x7f4))
              (0,acStack_41,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x7f4));
  }
  return acStack_41[0];
}

