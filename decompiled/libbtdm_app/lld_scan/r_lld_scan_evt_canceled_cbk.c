/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar4 = 0xaa4;
  }
  else {
    if (*(char *)(param_1 + 0x3c) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x000136a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))(*(undefined1 *)(param_1 + 0x40),"lld_scan.c",0xa9f);
      return;
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    if (*(char *)(param_1 + 0x3d) == '\x03') {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar3 + 0x18) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xa7c,*(code **)(_r_plf_funcs_p + 8));
      }
      (**(code **)(_r_ip_funcs_p + 0x448))
                (*(undefined1 *)(param_1 + 0x40),*(code **)(_r_ip_funcs_p + 0x448));
      *(undefined1 *)(param_1 + 0x3d) = 0;
    }
    bVar1 = rwip_priority;
    if ((uint)*(ushort *)(param_1 + 0x30) << 1 <= (iVar2 - *(int *)(param_1 + 0x28) & 0xfffffffU)) {
      if (0xff < (uint)*(byte *)(param_1 + 0x16) + (uint)rwip_priority) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0xa86,*(code **)(_r_plf_funcs_p + 8));
      }
      *(int *)(param_1 + 0x28) = iVar2;
      *(byte *)(param_1 + 0x16) = bVar1 + *(char *)(param_1 + 0x16);
    }
    iVar3 = _r_ip_funcs_p;
    if (*(char *)(param_1 + 0x3e) == '\x01') {
      *(undefined1 *)(param_1 + 0x3e) = 0;
                    /* WARNING: Could not recover jumptable at 0x00013674. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0x430))(*(undefined1 *)(param_1 + 0x40),iVar2,1);
      return;
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x6b0))(param_1,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar2 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar4 = 0xa92;
  }
                    /* WARNING: Could not recover jumptable at 0x00013656. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_scan.c",uVar4);
  return;
}

