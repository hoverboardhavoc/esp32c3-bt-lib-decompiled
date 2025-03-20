/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_evt_canceled_cbk(int param_1)

{
  int iVar1;
  byte bVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = 0x5c8;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    if (*(char *)(param_1 + 0x31) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00011b18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))(*(undefined1 *)(param_1 + 0x51),"lld_init.c",0x5c3);
      return;
    }
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    bVar2 = rwip_priority;
    if ((uint)*(ushort *)(param_1 + 0x2c) << 1 <= (iVar3 - *(int *)(param_1 + 0x28) & 0xfffffffU)) {
      if (0xff < (uint)*(byte *)(param_1 + 0x16) + (uint)rwip_priority) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x5aa,*(code **)(_r_plf_funcs_p + 8));
      }
      *(int *)(param_1 + 0x28) = iVar3;
      *(byte *)(param_1 + 0x16) = bVar2 + *(char *)(param_1 + 0x16);
    }
    iVar1 = _r_ip_funcs_p;
    if (*(char *)(param_1 + 0x3d) == '\x01') {
      *(undefined1 *)(param_1 + 0x3d) = 0;
                    /* WARNING: Could not recover jumptable at 0x00011aee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + 0x48c))(*(undefined1 *)(param_1 + 0x51),iVar3,1);
      return;
    }
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(param_1,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar3 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
    uVar4 = 0x5b6;
  }
                    /* WARNING: Could not recover jumptable at 0x00011ad0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_init.c",uVar4);
  return;
}

