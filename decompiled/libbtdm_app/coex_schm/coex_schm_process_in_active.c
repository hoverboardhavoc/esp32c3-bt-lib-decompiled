/*
 * Last changed at upstream commit 0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * https://github.com/espressif/esp32c3-bt-lib/commit/0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * Upstream date: 2024-03-26 14:09:42 +0800
 * Upstream subject: feat(ble/controller): Add coexist schm (bb95ac61)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_process_in_active
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void coex_schm_process_in_active(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  DAT_000101c7 = 0;
  iVar2 = (**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
  if (iVar2 != 0) {
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    pbVar4 = (byte *)(**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
    bVar1 = *pbVar4;
    iVar5 = (**(code **)(_r_osi_funcs_p + 0xc4))(*(code **)(_r_osi_funcs_p + 0xc4));
    iVar6 = (**(code **)(_r_osi_funcs_p + 0xc0))(*(code **)(_r_osi_funcs_p + 0xc0));
    DAT_000101c8 = ((iVar5 * iVar6 * (uint)bVar1) / 0x271) * 2 + iVar3 & 0xfffffff;
    if (3 < _g_bt_plf_log_level) {
      ets_printf("SCHM PROC %02x %02x, %p\n",*(undefined1 *)(iVar2 + 3),*(undefined1 *)(iVar2 + 2),
                 iVar2);
    }
    if ((*(byte *)(iVar2 + 2) & 0x20) != 0) {
      coex_schm_ble_scan_stop();
      return;
    }
  }
  return;
}

