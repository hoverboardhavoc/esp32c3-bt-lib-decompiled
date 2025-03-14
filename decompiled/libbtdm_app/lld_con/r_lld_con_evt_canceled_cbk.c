/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_canceled_cbk(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
    if (*(char *)(param_1 + 0x8f) != '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0xb91,*(code **)(_r_plf_funcs_p + 8));
    }
    *(uint *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + *(int *)(param_1 + 100) & 0xfffffff;
    cVar1 = rwip_priority;
    *(short *)(param_1 + 0x7e) = *(short *)(param_1 + 0x7e) + 1;
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar1;
                    /* WARNING: Could not recover jumptable at 0x00012e7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3a8))(*(undefined1 *)(param_1 + 0x8e),uVar2,0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00012e9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))("lld_con.c",0xb9f);
  return;
}

