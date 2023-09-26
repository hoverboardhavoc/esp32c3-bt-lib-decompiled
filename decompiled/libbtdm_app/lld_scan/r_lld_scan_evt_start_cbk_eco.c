/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914));
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x24) == (uint)*(ushort *)(param_1 + 0x32)) {
      (**(code **)(_r_ip_funcs_p + 0x8d0))(*(code **)(_r_ip_funcs_p + 0x8d0));
    }
    uVar2 = *(ushort *)(iVar4 + 0x18);
    if (uVar2 != 0) {
      bVar1 = *(byte *)(param_1 + 0x38);
      if ((uVar2 & 0xc0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x3cf,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = (uint)bVar1 * 0x5a + 0x16;
      uVar3 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5) = uVar3 & 0xffc0 | uVar2 & 0xff;
    }
  }
  if ((g_scan_forever != '\0') && (param_1 != 0)) {
    if (*(char *)(param_1 + 0x3c) != '\x02') {
      bVar1 = *(byte *)(param_1 + 0x38);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      if (*(short *)(iVar4 + (uint)bVar1 * 0x5a + 0x20) != 1) {
        bVar1 = *(byte *)(param_1 + 0x38);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar4 + (uint)bVar1 * 0x5a + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
      }
    }
  }
  r_lld_scan_evt_start_cbk(param_1);
  return;
}

