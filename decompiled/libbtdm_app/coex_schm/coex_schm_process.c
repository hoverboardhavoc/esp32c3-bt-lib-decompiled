/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void coex_schm_process(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (**(code **)(_r_osi_funcs_p + 0xec))(*(code **)(_r_osi_funcs_p + 0xec));
  if (iVar5 != 0) {
    coex_schm_btdm_env = 1;
                    /* WARNING: Could not recover jumptable at 0x0001015a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0xf0))(*(code **)(_r_osi_funcs_p + 0xf0));
    return;
  }
  DAT_000101f7 = 0;
  pbVar2 = (byte *)(**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
  if (pbVar2 != (byte *)0x0) {
    iVar5 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    bVar1 = *pbVar2;
    iVar3 = (**(code **)(_r_osi_funcs_p + 0xc4))(*(code **)(_r_osi_funcs_p + 0xc4));
    iVar4 = (**(code **)(_r_osi_funcs_p + 0xc0))(*(code **)(_r_osi_funcs_p + 0xc0));
    DAT_000101f8 = (((uint)bVar1 * iVar4 * iVar3) / 0x271) * 2 + iVar5 & 0xfffffff;
    if (3 < _g_bt_plf_log_level) {
      ets_printf("SCHM PROC %02x %02x, %p\n",pbVar2[3],pbVar2[2],pbVar2);
    }
    if (((pbVar2[2] & 0x20) != 0) &&
       (iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
       *(char *)(iVar5 + 0x23) != '\0')) {
      coex_schm_ble_scan_stop();
      return;
    }
  }
  return;
}

